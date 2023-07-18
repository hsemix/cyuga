namespace Yuga\Application;

use Yuga\Container\Container;
use Yuga\Interfaces\Application\Application as IApplication;

class Application extends Container implements IApplication
{
    const VERSION = "6.0.0";
    const CHARSET_UTF8 = "UTF-8";

    /**
     * Store the configuration instance in this variable so we can use it as
     * <code>$this->app->config->get('db.default.settings')</code> from a controller
     *
     * @var \Yuga\Support\Config
     */
    public config;

    /**
     * The base file path of the application so we can install the framework 
     * in a different directory and access it entiry
     *
     * @var string
     */
    protected basePath;

    /**
     * The application instance is to be stored in this variable
     *
     * @var \Yuga\Application\Application
     */
    protected static app;

    /**
     * The Default Application language we shall use
     * can be changed
     *
     * @var string
     */
    protected locale = "en";

    /**
     * The Application debug mode default is false 
     * can be changed in the .env file
     *
     * @var boolean
     */
    protected debugEnabled = false;
    
    /**
     * The names of the loaded service providers.
     *
     * @var array
     */
    protected loadedProviders = [];

    /**
     * The encryption method we shall use throught the entire application
     * can be changed later
     *
     * @var string
     */
    protected encryptionMethod = "AES-256-CBC";

    protected debuggerStarted = false;

    protected booted = false;

    protected charset;

    /**
     * composer vendor directory
     */
     protected vendorDir;

     /**
      * The prefixes of absolute cache paths for use during normalization.
      *
      * @var string[]
      */
     protected absoluteCachePathPrefixes = ["/", "\\"];
    
    public function __construct(root = null)
    {
        let this->basePath = root;
        let this->charset = self::CHARSET_UTF8;
    }
}