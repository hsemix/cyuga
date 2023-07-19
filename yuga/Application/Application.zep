namespace Yuga\Application;

use Yuga\Support\Str;
use Yuga\Container\Container;
use Yuga\Interfaces\Application\Application as IApplication;

class Application extends Container implements IApplication
{
    const VERSION = "6.0.0";
    const CHARSET_UTF8 = "UTF-8";

    /**
     * Store the configuration instance in this variable so we can use it as
     * <code>this->app->config->get("db.default.settings")</code> from a controller
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

    /**
     * Get the base path of the Laravel installation.
     *
     * @param  string  $path
     * @return string
     */
    public function basePath(path = "")
    {
        
        if path != "" {
            let path = DIRECTORY_SEPARATOR.path;
        }

        return this->basePath. path;
    }

    /**
     * Get the path to the boot directory.
     *
     * @param  string  $path
     * @return string
     */
    public function bootPath(path = "")
    {
        if path != "" {
            let path = DIRECTORY_SEPARATOR.path;
        }

        return this->basePath.DIRECTORY_SEPARATOR."boot".path;
    }

    /**
     * Get the path to the application configuration files.
     *
     * @param  string  path
     * @return string
     */
    public function configPath(path = "")
    {
        if path != "" {
            let path = DIRECTORY_SEPARATOR.path;
        }
        return this->basePath.DIRECTORY_SEPARATOR."config".path;
    }

    /**
     * Get the path to the configuration cache file.
     *
     * @return string
     */
    public function getCachedConfigPath()
    {
        return this->normalizeCachePath("APP_CONFIG_CACHE", "cache/config.php");
    }

    /**
     * Get the path to the cached services.php file.
     *
     * @return string
     */
    public function getCachedServicesPath()
    {
        return this->normalizeCachePath("APP_SERVICES_CACHE", "cache/services.php");
    }

    /**
     * Get the path to the cached packages.php file.
     *
     * @return string
     */
    public function getCachedPackagesPath()
    {
        return this->normalizeCachePath("APP_PACKAGES_CACHE", "cache/packages.php");
    }

    /**
     * Normalize a relative or absolute path to a cache file.
     *
     * @param  string  key
     * @param  string  default
     * @return string
     */
    protected function normalizeCachePath(key, defaultValue)
    {
        var env = env(key);
        if is_null(env) {
            return this->bootPath(defaultValue);
        }

        if Str::startsWith(env, this->absoluteCachePathPrefixes) {
            return env;
        }
        return this->basePath(env);
    }

    public function setVendorDir(vendorDir)
    {
        let this->vendorDir = vendorDir;
        return this;
    }

    public function getVendorDir()
    {
        return this->vendorDir;
    }

    /**
     * Determine if we are running in the console.
     *
     * @return bool
     */
    public function runningInConsole()
    {
        return php_sapi_name() == "cli";
    }

    /**
     * Return a static instance of the Application instance through out the entire application
     * 
     * @param null
     * 
     * @return \Yuga\Application\Application
     */
    public static function getInstance()
    {
        return self::app;
    }

    /**
     * Register the basic bindings into the container.
     *
     * @return void
     */
    protected function registerBaseBindings(container)
    {
        this->singleton("app", this);
        this->singleton("Yuga\\Container\\Container", this);
        this->bind("base_path", this->basePath);
        this->bind("Yuga\\Interfaces\\Application\\Application", "Yuga\\Application\\Application");
        this->bind("vendor_path", this->vendorDir);
        // this->singleton(PackageManager::class, function () {
        //     return new PackageManager(
        //         this->basePath, 
        //         env("COMPOSER_VENDOR_DIR", this->vendorDir),
        //         path("config".DIRECTORY_SEPARATOR."ServiceProviders.php")
        //     );
        // });
    }

    /**
     * Run the Yuga application
     */
    public function run()
    {
        this->singleton("config", "Yuga\\Support\\Config");
        // this->config = this->get('config');
        // load default class alias here
        // this->setVendorDir(this->basePath.DIRECTORY_SEPARATOR.'vendor');
        // if (!this->runningInConsole()) {
        //     this->setDebugEnabled(env('DEBUG_MODE', false)); 
        //     this->initTracy();  
        // }
        // this->registerConfig();
        if (this->debuggerStarted) {
            // this['events']->dispatch('on:yuga-tracy');
        }
        this->registerBaseBindings($this);
        // this->registerDefaultProviders();
        // this['events']->dispatch('on:app-start');
        
        // if (!$this->runningInConsole()) {
        //     $this->make('session')->delete('errors');
        // }

        return this;
    }
}