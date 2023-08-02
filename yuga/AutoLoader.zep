namespace Yuga;

class AutoLoader
{
    protected namespaces = [];
    protected static instance;

    public function __construct()
    {
        if !self::instance {
            let self::instance = this;
        }
    }

    /**
     * Return a static instance of the ClassLoad object through out the request
     * 
     * @return object instance
     */
    public static function getInstance()
    {
        if is_null(self::instance) {
            let self::instance = new self();
        }

        return self::instance;
    }

    /**
     * Load classes using psr-4 autoload
     * 
     * @param array
     */
    public function addPsr4(array classes)
    {
        var namespaceValue, root;
        for namespaceValue, root in classes {
            let this->namespaces[namespaceValue] = root;
        }
            
        return this;
    }

    /**
     * Include the file and load the class
     * 
     * @param null
     * 
     * @return resource
     */
    public function load()
    {
        return spl_autoload_register([this, "includeFile"]);        
    }

    /**
     * Check the file to find out whether it exists
     * 
     * @param string classValue
     * 
     * @return null
     */
    public function includeFile(classValue)
    {
        var parts = explode("\\", classValue), namespaceKey, src;
        var filtered = [], file;
        var namespaces = this->namespaces;
        for namespaceKey, src in namespaces {
            if parts[0] == rtrim(namespaceKey, "\\") {
                let parts[0] = rtrim(src, "/");
                let filtered = parts;
            }
        }
        
        if (count(filtered) > 0) {
            let file = str_replace("\\", "/", implode("/", parts)).".php";
            if file_exists(file) {
                require file;
            }    
        }
    }

    /**
     * Add a namespace to the psr-4 autoloaded namespaces array
     * 
     * @param array|string namespaces
     * 
     * @param string|null root
     * 
     * @return static
     */
    public static function loadPsr4(array namespaces)
    {
        static::getInstance()->addPsr4(namespaces);
        return static::getInstance();
    }
}