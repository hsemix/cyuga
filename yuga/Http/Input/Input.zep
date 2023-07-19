namespace Yuga\Http\Input;

use Closure;
use Yuga\Http\Request;

class Input 
{
    /**
     * @var array
     */
    public get = [];

    /**
     * @var array
     */
    public post = [];

    /**
     * @var array
     */
    public file = [];

    /**
     * @var Request
     */
    protected request;

    public function __construct(<Request> request)
    {
        let this->request = request;

        this->parseInputs();
    }

    public function parseInputs()
    {
        var postValues;
        /* Parse get requests */
        if (count(_GET) > 0) {
            let this->get = this->handleGetPost(filter_var_array(_GET, FILTER_SANITIZE_FULL_SPECIAL_CHARS));
        }

        /* Parse post requests */
        let postValues = filter_var_array(_POST, FILTER_SANITIZE_FULL_SPECIAL_CHARS);

        if in_array(this->request->getMethod(), ["put", "patch", "delete"], false) === true {
            parse_str(file_get_contents("php://input"), postValues);
        }

        if (count(postValues) > 0) {
            let this->post = this->handleGetPost(postValues);
        }

        /* Parse get requests */
        if (count(_FILES) > 0) {
            let this->file = this->parseFiles();
        }
    }

    public function parseFiles()
    {
        var list, key, value, keys, files, values;
        let list = [];

        for key, value in _FILES {
            // Handle array input
            if is_array(value["name"]) === false {
                let values["index"] = key;
                let list[key] = InputFile::createFromArray(array_merge(value, values));
                continue;
            }

            let keys = [];

            let files = this->rearrangeFiles(value["name"], keys, value);

            if (isset(list[key])) {
                let list[key][] = files;
            } else {
                let list[key] = files;
            }
        }

        return list;
    }

    protected function generateFiles(array values, <Closure> getItem)
    {
        var value, key, output;

        for key, value in values {
            var index = [], files, file;

            var possibleFiles = call_user_func_array(getItem, [key]);
            if (is_array(possibleFiles) === false) {
                let file = this->getFile(key, getItem);
                
                if (isset(output[key])) {
                    let output[key][] = file;
                } else {
                    let output[key] = file;
                }
                continue;
            }
            
            let index[] = key;

            let files = this->rearrangeFiles(value, index, index);
            if (isset(output[key])) {
                let output[key][] = files;
            } else {
                let output[key] = files;
            }
        }

        return output;
    }

    protected function getFile(key, <Closure> getItem)
    {
        return InputFile::createFromArray([
            "index"     : key,
            "name"      : call_user_func_array(getItem, [key]),
            "error"     : call_user_func_array(getItem, [key, "error"]),
            "tmp_name"  : call_user_func_array(getItem, [key, "tmp_name"]),
            "type"      : call_user_func_array(getItem, [key, "type"]),
            "size"      : call_user_func_array(getItem, [key, "size"])
        ]);
    }

    protected function handleGetPost(array arrayList)
    {
        var list, key, value;
        let list = [];

        for key, value in arrayList {
            var output;
            // Handle array input
            if (is_array(value) == false) {
                let list[key] = new InputItem(key, value);
                continue;
            }

            let output = this->handleGetPost(value);

            let list[key] = output;
        }

        return list;
    }

    protected function rearrangeFiles(array values, index, original)
    {
        var output, getItem;
        let output = [];
        let getItem = function (key, property = "name") use (original, index) {
            var path, fileValues, value;
            let path = original[property];
            
            let fileValues = array_values(index);

            for value in fileValues {
                let path = path[value];
            }

            return path[key];
        };

        
        let output = this->generateFiles(values, getItem);
        return output;
    }

    /**
     * Find post-value by index or return default value.
     *
     * @param string index
     * @param string|null defaultValue
     * @return InputItem|string
     */
    public function findPost(index, defaultValue = null)
    {
        var input, stringVar;
        let input = this->post;
        let stringVar = file_get_contents("php://input");
        if !is_null(stringVar) {
            let input = array_merge(this->post, filter_var_array((array)json_decode(stringVar, true), FILTER_SANITIZE_FULL_SPECIAL_CHARS));
        }
        return isset(input[index]) ? input[index] : defaultValue;
    }

    /**
     * Find file by index or return default value.
     *
     * @param string index
     * @param string|null defaultValue
     * @return InputFile|string
     */
    public function findFile(index, defaultValue = null)
    {
        return isset(this->file[index]) ? this->file[index] : defaultValue;
    }

    /**
     * Find parameter/query-string by index or return default value.
     *
     * @param string index
     * @param string|null defaultValue
     * @return InputItem|string
     */
    public function findGet(index, defaultValue = null)
    {
        return isset(this->get[index]) ? this->get[index] : defaultValue;
    }

    /**
     * Get input object
     *
     * @param string index
     * @param string|null defaultValue
     * @param array|string|null methods
     * @return IInputItem|string
     */
    public function getObject(string index, defaultValue = null, methods = null)
    {
        if (methods != null && is_string(methods) == true) {
            let methods = [methods];
        }

        var element = null;

        if (methods == null || in_array("get", methods)) {
            let element = this->findGet(index);
        }

        if ((element == null && methods == null) || (methods != null && in_array("post", methods))) {
            let element = this->findPost(index);
        }

        if ((element == null && methods == null) || (methods != null && in_array("file", methods))) {
            let element = this->findFile(index);
        }

        return (element != null) ? element : defaultValue;
    }

    /**
     * Get input element value matching index
     *
     * @param string index
     * @param string|null defaultValue
     * @param array|string|null methods
     * @return InputItem|string
     */
    public function get(string index, defaultValue = null, methods = null)
    {
        var inputObject = this->getObject(index, defaultValue, methods);

        if (inputObject instanceof InputItem) {
            return (trim(inputObject->getValue()) == "") ? defaultValue : inputObject->getValue();
        }

        return inputObject;
    }

    /**
     * Check if a input-item exist
     *
     * @param string index
     * @return bool
     */
    public function exists(index)
    {
        return (this->getObject(index) != null);
    }

    /**
     * Get all get/post items
     * @param array|null filter Only take items in filter
     * @return array
     */
    public function all(array filter = null)
    {
        var output, contents;

        // let output = _POST;
        let output = this->post;

        if (this->request->getMethod() == "post" || this->request->getMethod() == "patch" || this->request->getMethod() == "put") {

            let contents = file_get_contents("php://input");

            if (strpos(trim(contents), '{') === 0) {
                let output = json_decode(contents, true);
                if (output === false) {
                    let output = [];
                }
            }
        }

        return (filter != null) ? array_intersect_key(output, array_flip(filter)) : array_merge(this->get, output);
        // return (filter != null) ? array_intersect_key(output, array_flip(filter)) : array_merge(_GET, output);
    }

    public static function file(key = null, defaultValue = null)
	{
		return array_get(_FILES, key, defaultValue);
    }
    
    /**
     * Determine if the input contains a file
     */
    public static function hasFile(key)
	{
        var file;

        let file = static::file(key . ".tmp_name");

        if (is_array(file)) {
            if (file[0] === "") {
                return false;
            } 
            return true;
        }

        if (file === "" || file === null) {
            return false;
        }
        return true;
	}

}