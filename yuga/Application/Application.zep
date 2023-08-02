namespace Yuga\Application;

use Yuga\Support\Str;
use Yuga\Http\Request;
use Yuga\Support\Helpers;
use Yuga\Container\Container;
use Yuga\Events\EventServiceProvider;
use Yuga\Interfaces\Providers\ServiceProviderInterface;
use Yuga\Interfaces\Application\Application as IApplication;
use Yuga\Providers\TestProvider;


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

        this->registerConfig();
    }

    /**
     * Get the base path of the Laravel installation.
     *
     * @param  string  path
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
     * @param  string  path
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
        var env = Helpers::env(key);
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
     * Register the Service providers
     *
     * @return void
     */
    protected function registerConfig()
    {
        
        if (!self::app) {
            let self::app = this;
        }
        // providers = this->config->load('config.ServiceProviders');
        this->registerConfigProviders();
        
        // foreach (this->config->getAll() as name => provider) {
        //     if (class_exists(provider)) {
        //         this->singleton(name, provider);
        //         provider = this->resolve(name);
        //         this->registerProvider(provider);
        //     }
        // }
        
        
        // if (env('ROUTER_BOOTED', false)) {
        //     if (env('ENABLE_MVP_ROUTES', false)) {
                
        //         Route::group(['middleware' => 'web', 'namespace' => 'App\Controllers', 'exceptionHandler' => NotFoundHttpExceptionHandler::class], function () {
        //             routePrefix = '/' . trim(env('PREFIX_MVP_ROUTE', '/'), '/') . '/';
        //             routePrefix = (routePrefix == '//') ? '/' : routePrefix;
        //             controller = env('MVP_CONTROLLER', 'Controller');
        //             if (env('MATCH_ROUTES_TO_CONTROLLERS', false)) {
        //                 trigger_error("MVP ROUTING and IMPLICIT ROUTING can not co-exist", E_USER_WARNING);
        //             }

        //             Route::csrfVerifier(new WebMiddleware);
        //             Route::all(routePrefix . '{slug?}', controller . '@show')->where(['slug' => '(.*)']);
        //         });
                
        //     }
        // }
        
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
        this->registerBaseBindings(this);
        this->registerDefaultProviders();
        this["events"]->dispatch("on:app-start");
        
        // if (!this->runningInConsole()) {
        //     this->make('session')->delete('errors');
        // }

        return this;
    }

    /**
     * Get the debug mode if set
     * 
     * @param null
     * 
     * @return bool
     */
    public function getDebugEnabled()
    {
        return this->debugEnabled;
    }

    /**
     * Set the default application's encryption methode
     * 
     * @param string method
     * 
     * @return \Yuga\Application\Application this
     */
    public function setEncryptionMethod(method)
    {
        let this->encryptionMethod = method;

        return this;
    }

    /**
     * Get the Encryption method
     * 
     * @param null
     * 
     * @return string
     */
    public function getEncryptionMethod()
    {
        return this->encryptionMethod;
    }

    /**
     * Register those providers that need to be loaded before any other providers
     * 
     * @return void
     */
    protected function registerConfigProviders()
    {
        this->registerProvider(new EventServiceProvider(this));
    }

    /**
     * Register all of the base service providers.
     *
     * @return void
     */
    protected function registerDefaultProviders()
    {
        this->registerProvider(new TestProvider(this));
        // this->registerProvider(new ElegantServiceProvider(this));

        // this->registerProvider(new LogServiceProvider(this));

        // this->registerProvider(new RouteServiceProvider(this));
        
        // if (this->runningInConsole()) {
        //     this->registerProvider(new YugaServiceProvider(this));
        // }
        
    }

    /**
     * Set the application request for the console environment.
     *
     * @return void
     */
    public function setRequestForYugaConsole()
    {
        // var url = this["config"]->get("app.url", "http://localhost");

        // var parameters = [url, "GET", [], [], [], _SERVER];

        // this->refreshRequest(self::onRequest("create", parameters));
    }

    // /**
    //  * Refresh the bound request instance in the container.
    //  *
    //  * @param  \Yuga\Http\Request  request
    //  * @return void
    //  */
    // protected function refreshRequest(<Request> request)
    // {
    //     return this->singleton("request", request);
    // }

    /**
     * Call a method on the default request class.
     *
     * @param  string  method
     * @param  array  parameters
     * @return mixed
     */
    public static function onRequest(method, parameters = [])
    {
        return forward_static_call_array([new Request, method], parameters);
    }

    /**
     * @param \Yuga\Interfaces\Providers\IServiceProvider provider
     * 
     * @return \Yuga\Application\Application this
     */
    public function registerProvider(<ServiceProviderInterface> provider)
    {
        
        if (!this->providerLoaded(provider)) {
            if (method_exists(provider, "register")) {
                provider->register(this);
                this->bootProvider(provider);
            }
            let this->loadedProviders[] = get_class(provider);
            return this;
        }
        
    }

    public function getProviders()
    {
        return this->loadedProviders;
    }

    /**
     * @param \Yuga\Interfaces\Providers\ServiceProviderInterface provider
     * 
     * @return mixed
     */
    protected function bootProvider(<ServiceProviderInterface> provider)
    {
        if (method_exists(provider, "boot")) {
            return this->call([provider, "boot"]);
        }
    }

    /**
     * Determine whether a service provider has been loaded or not
     * 
     * @param ServiceProviderInterface provider
     * 
     * @return bool
     */
    protected function providerLoaded(<ServiceProviderInterface> provider)
    {
        return array_key_exists(get_class(provider), this->loadedProviders);
    }
}