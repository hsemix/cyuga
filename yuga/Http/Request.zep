namespace Yuga\Http;

use Exception;
use Yuga\Http\Input\Input;

class Request
{   

    protected data = [];
    protected headers;
    protected host;
    protected uri;
    protected method;
    protected input;
    protected app;
    
    protected rewriteRoute;
    protected rewriteUrl;

    protected loadedRoute;

    protected formFields = [];

    protected model;

    public function __construct()
    {
        this->parseHeaders();
        let this->host = this->getHeader("http-host");
        let this->uri = this->getHeader("request-uri");
        let this->input = new Input(this);
        let this->method = strtolower(this->input->get("_method", this->getHeader("request-method"), "post"));
        let this->data = this->except(["_token"]);
    }

    

    protected function parseHeaders()
    {
        var name, value;

        let this->headers = [];

        for name, value in _SERVER {
            let this->headers[strtolower(name)] = value;
            let this->headers[strtolower(str_replace("_", "-", name))] = value;
        }

    }

    /**
     * Get all headers
     * @return array
     */
    public function getHeaders()
    {
        return this->headers;
    }

    /**
     * Get header value by name
     *
     * @param string name
     * @param string|null defaultValue
     *
     * @return string|null
     */
    public function getHeader(string name, string defaultValue = null)
    {
        var headerName, headerValue;
        if (isset(this->headers[strtolower(name)])) {
            return this->headers[strtolower(name)];
        }

        for headerName, headerValue in _SERVER {
            if headerName === name {
                return headerValue;
            }
        }

        return defaultValue;
    }

    public function getBearerToken()
    {
        var authorize, matches;

        let authorize = this->getHeader("http-authorization");

        let matches = [];
        
        if !preg_match("#Bearer\s(\S+)#", authorize, matches) {
            throw new Exception("Access Token Not Found", 401);
            
        }
        return matches[1];
        
    }

    public function getInput()
    {
        return this->input;
    }

    /**
     * Is format accepted
     *
     * @param string format
     *
     * @return bool
     */
    public function isFormatAccepted(format)
    {
        return (this->getHeader("http-accept") !== null && stripos(this->getHeader("http-accept"), format) > -1);
    }

    /**
     * Get accept formats
     * @return array
     */
    public function getAcceptFormats()
    {
        return explode(',', this->getHeader("http-accept"));
    }

    /**
     * @param string uri
     */
    public function setUri(string uri)
    {
        let this->uri = uri;
        return this;
    }

    /**
     * @param string host
     */
    public function setHost(string host)
    {
        let this->host = host;
        return this;
    }

    /**
     * @param string method
     */
    public function setMethod(string method)
    {
        let this->method = method;
        return this;
    }

    /**
     * Get rewrite route
     *
     * @return ILoadableRoute|null
     */
    public function getRewriteRoute()
    {
        return this->rewriteRoute;
    }

    /**
     * Set rewrite url
     *
     * @param string rewriteUrl
     * @return static
     */
    public function setRewriteUrl(rewriteUrl)
    {
        let this->rewriteUrl = rewriteUrl;

        return this;
    }

    /**
     * Get loaded route
     * @return ILoadableRoute|null
     */
    public function getLoadedRoute()
    {
        return this->loadedRoute;
    }

    /**
     * Set loaded route
     *
     * @param ILoadableRoute route
     * @return static
     */
    public function setLoadedRoute(route)
    {
        let this->loadedRoute = route;

        return this;
    }

    public function __isset(name)
    {
        return array_key_exists(name, this->data);
    }

    public function __set(name, value = null)
    {
        let this->data[name] = value;
    }

    public function __get(name)
    {
        return isset(this->data[name]) ? this->data[name] : null;
    }

    public function isAjax()
    {
        if ((this->getHeader("http-x-requested-with") !== null && strtolower(this->getHeader("http-x-requested-with")) === "xmlhttprequest") || (this->getHeader("http-user-agent") !== null && preg_match("/^(curl|wget)/i", this->getHeader("http-user-agent")))) {
            return true;
        }
        return false;
    }

    public function model()
    {
        return this->model;
    }

    public function setModel(model)
    {
        let this->model = model;
        return this;
    }

    /**
     * @return string
     */
    public function getMethod()
    {
        return this->method;
    }

    public function create()
    {
        return new self();
    }

    public function isSecure()
    {
        return this->getHeader("http-x-forwarded-proto") === "https" || this->getHeader("https") !== null || this->getHeader("server-port") === 443;
    }

    public function getPort()
    {
        return this->getHeader("server-port");
    }

    /**
     * @return string
     */
    public function getUri(trim = false)
    {
        if (trim) {
            return this->uri;
        }
        // return "/" . ltrim(str_replace(this->processHost(), "", this->uri), "/");
    }


    // public function processHost()
    // {
    //     var scriptName, segs, last;

    //     let scriptName = this->getHeader("php-self");
        
    //     let segs = explode('/', trim(scriptName, '/'));
    //     let segs = array_reverse(segs);
    //     let index = 0;
    //     let last = count(segs);
    //     var baseUrl = "";

    //     do {
    //         let seg = segs[index];
    //         let baseUrl = "/" . seg . rtrim(baseUrl, "/") ;
    //         let index++;
    //     } while (last > index && (false !== pos = strpos(scriptName, baseUrl)) && 0 != pos);

    //     return baseUrl . "/";
    // }

    public function formatUrl(url)
    {
        echo this->uri;
        exit();
    }

    /**
     * @return string
     */
    public function getHost()
    {
        return this->host;
    }

    public function getServer()
    {
        return this->getHeader("server-name");
    }

    /**
     * Get http basic auth user
     * @return string|null
     */
    public function getUser()
    {
        return this->getHeader("php-auth-user");
    }

    /**
     * Get http basic auth password
     * @return string|null
     */
    public function getPassword()
    {
        return this->getHeader("php-auth-pw");
    }

    /**
     * Get id address
     * @return string
     */
    public function getIp()
    {
        if (this->getHeader("http-cf-connecting-ip") !== null) {
            return this->getHeader("http-cf-connecting-ip");
        }

        if (this->getHeader("http-x-forwarded-for") !== null) {
            return this->getHeader("http-x-forwarded-for");
        }

        return this->getHeader("remote-addr");
    }

    /**
     * Get remote address/ip
     *
     * @alias static::getIp
     * @return string
     */
    public function getRemoteAddr()
    {
        return this->getIp();
    }

    /**
     * Get referer
     * @return string
     */
    public function getReferer()
    {
        return this->getHeader("http-referer");
    }

    /**
     * Get user agent
     * @return string
     */
    public function getUserAgent()
    {
        return this->getHeader("http-user-agent");
    }

    public function get(string value, defaultValue = null)
    {
        return this->getInput()->get(value, defaultValue);
    }

    public function exists(index = null)
    {
		return this->getInput()->exists(index);
    }

    public function files(key = null, defaultValue = null)
    {
        var files;
        let files = this->getInput()->findFile(key, defaultValue);
		if is_array(files) {
            return this->getInput()->findFile(key, defaultValue);
        } elseif !this->getInput()->findFile(key, defaultValue)->hasError() {
            return this->getInput()->findFile(key, defaultValue);
        }
			
        return false;
    }

    public function hasFile(key)
    {
        return this->getInput()->hasFile(key);
    }

    public function all(array filter = null)
    {
        return this->getInput()->all(filter);
    }

    public function only(array onlyFields = [])
    {
        var only, field, value;
        let only = [];

        for field, value in this->all() {
            if in_array(field, onlyFields) {
                let only[field] = value;
            }   
        }
        
       return only;
    }

    public function except(array exceptFields = [])
    {
        var only, field, value;
        let only = [];

        for field, value in this->all() {
            if !in_array(field, exceptFields) {
                let only[field] = value;
            }   
        }

       return only;
    }

}