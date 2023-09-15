namespace Yuga\Route\Router;

use ReflectionClass;
// use Yuga\Views\View;
use Yuga\Http\Request;
use ReflectionFunction;
use Yuga\Http\Redirect;
use Yuga\View\ViewModel;
use Yuga\Support\Helpers;
// use Yuga\Pipeline\Pipeline;
use Yuga\Container\Container;
use Yuga\Route\Support\IRoute;
use Yuga\Application\Application;
use Yuga\Route\Support\IGroupRoute;

// use Yuga\Http\Middleware\IMiddleware;
use Yuga\Route\Exceptions\HttpException;
use Yuga\Route\Exceptions\NotFoundHttpException;
use Yuga\Route\Exceptions\NotFoundHttpMethodException;
// use Yuga\Http\Middleware\MiddleWare as RouteMiddleware;
use Yuga\Route\Exceptions\NotFoundHttpControllerException;
// use Yuga\Database\Elegant\Exceptions\ModelNotFoundException;

abstract class Route implements IRoute
{
    const PARAMETERS_REGEX_FORMAT = "%s([\w]+)(\%s?)%s";
    const PARAMETERS_DEFAULT_REGEX = "[\w]+";

    const REQUEST_TYPE_GET = "get";
    const REQUEST_TYPE_POST = "post";
    const REQUEST_TYPE_PUT = "put";
    const REQUEST_TYPE_PATCH = "patch";
    const REQUEST_TYPE_OPTIONS = "options";
    const REQUEST_TYPE_DELETE = "delete";

    public static requestTypes = [
        self::REQUEST_TYPE_GET,
        self::REQUEST_TYPE_POST,
        self::REQUEST_TYPE_PUT,
        self::REQUEST_TYPE_PATCH,
        self::REQUEST_TYPE_OPTIONS,
        self::REQUEST_TYPE_DELETE
    ];

    /**
     * If enabled parameters containing null-value
     * will not be passed along to the callback.
     *
     * @var bool
     */
    protected filterEmptyParams = false;
    protected defaultParameterRegex = null;
    // protected paramModifiers = "{}";
    protected paramModifiers = ["{", "}"];
    protected paramOptionalSymbol = "?";
    protected group;
    protected parent;
    protected callback;
    protected defaultNamespace;

    /* Default options */
    protected namespaceValue;
    protected requestMethods = [];
    protected where = [];
    protected parameters = [];
    protected originalParameters = [];
    protected middlewares = [];

    protected function loadClass(name)
    {
        // exception = NotFoundHttpException::class;
        // if (env('DEBUG_MODE_SETTINGS', '{"controller_missing": true, "method_missing": true}') !== null) {
        //     debugSettings = json_decode(env('DEBUG_MODE_SETTINGS', '{"controller_missing": true, "method_missing": true}'), true);
        //     if (isset(debugSettings['controller_missing'])) {
        //         if (debugSettings['controller_missing'] == true) {
        //             exception = NotFoundHttpControllerException::class;
        //         }  
        //     }
        // }
        // if (class_exists(name) == false) {
        //     throw new exception(sprintf('Class "%s" does not exist', name), 404);
        // }
        return Application::getInstance()->resolve(name);
    }

    protected function instantiated(callback, request = null)
    {
        var reflection, classes = [], app = Application::getInstance(), param;
        let reflection = new ReflectionFunction(callback);
        
        for param in reflection->getParameters() {

            if (param->getType() !== null) {
                var classValue = param->getType()->getName();
                
                if (this->isSingleton(app, classValue)) {
                    var binding = this->isSingleton(app, classValue);
                    let classes[param->name] = binding;
                } else {
                    let classes[param->name] = app->resolve(classValue);
                }
                
            } else {
                if (array_key_exists(param->name, this->getParameters())) {
                    let classes[param->name] = this->getParameters()[param->name];
                } 
            }
            
        }
        return classes;
    }

    protected function isSingleton(<Application> app, className)
    {
        var instance;
        for instance in array_values(app->getSingletons()){
            if get_class(instance) == className {
                return instance;
            }
        }
        return false;
    }

    protected function runMiddleware(<Request> request, middleware)
    { 
        // if (is_object(middleware) == false) {
        //     routeMiddleware = this->loadClass(RouteMiddleware);
        //     wares = array_merge(routeMiddleware->routerMiddleWare, require path('config/AppMiddleWare.php'));
        //     routeMiddlewares = [];
        //     middlewares = middleware;
        //     if (is_string(middleware) == true) {
        //         middlewares = [middleware];
        //     }
        //     foreach (middlewares as ware) {
        //        if (isset(wares[ware])) {
        //             routeMiddlewares[] = this->loadClass(wares[ware]);
        //         } else {
        //             throw new NotFoundHttpException(sprintf('Middleware "%s" does not exist', ware), 404);
        //         } 
        //     }  
        // }
        
        // result = Pipeline::send(request)->through(routeMiddlewares)->thenReturn();

        // if (result instanceof ViewModel || is_string(result) || result instanceof View ) {
        //     echo result;
        // } elseif (result instanceof Redirect) {
        //     if (result->getPath() !== null) {
        //         result->header('Location: ' . result->getPath());
        //         exit();
        //     } else {
        //         throw new NotFoundHttpException("You have not provided a Redirect URL");
        //     }
        // } elseif (is_scalar(result)) {
        //     echo result;
        // } 
    }

    public function renderRoute(<Request> request)
    {
        
        var callback = this->getCallback(), classValue, result, controller, method, className;

        if (callback === null) {
            return;
        }

        if (is_array(callback) === true) {
            if (isset(callback["middleware"])) {
                var middleware = callback["middleware"];
                let callback = callback[0];
                this->runMiddleware(request, middleware);
            }

            let controller = callback[0];
            let classValue = this->loadClass(controller);
            let method = callback[1];
        }

        // if (is_string(callback) === true) {

        //     echo callback;
        //     exit();
        // }

        /* Render callback function */
        if (is_callable(callback) == true) {

            /* When the callback is a function */
            // let result = call_user_func_array(callback, this->instantiated(callback, request));
            // echo "hrere!!!!!";
            return call_user_func_array(callback, this->instantiated(callback, request));
            // if (result instanceof ViewModel || is_string(result) || is_scalar(result) || result instanceof View) {
                // echo result;
            // } elseif (result instanceof Redirect) {
            //     if (result->getPath() !== null) {
            //         result->header('Location: ' . result->getPath());
            //         exit();
            //     } else {
            //         throw new NotFoundHttpException("You have not provided a Redirect URL");
            //     }
            // }
            return;

        }

        // echo "hereeeee";

        // exit();
        if (is_object(callback) === true) {
            // if (callback instanceof ViewModel) {
            //     echo callback;
            //     return;
            // }
        }

        if is_string(callback) === true {
            /* When the callback is a class + method */
            var controller = explode('@', callback);

            var namespaceValue = this->getNamespace();

            if (count(controller) === 1) {
                var viewModel = this->loadClass(controller[0]);
                if (viewModel instanceof ViewModel) {
                    echo viewModel;
                    return;
                } else {
                    let className = controller[0];
                    if (namespaceValue !== null && controller[0][0] !== "\\") {
                        let className = namespaceValue . "\\" . controller[0];
                    }
                    throw new NotFoundHttpException(sprintf("Method not provided for controller class '%s'", className), 404);
                }
            }
            
            let className = controller[0];
            
            if (namespaceValue !== null && controller[0][0] !== "\\") {
                let className = namespaceValue . "\\" . controller[0];
            }

            let classValue = this->loadClass(className);
            let method = controller[1];
        }
        
        
        if (method_exists(classValue, method) === false) {
            var exceptionClass = "Yuga\\Route\\Exceptions\\NotFoundHttpException";
            // if (env('DEBUG_MODE_SETTINGS', '{"controller_missing": true, "method_missing": true}') !== null) {
            //     debugSettings = json_decode(env('DEBUG_MODE_SETTINGS', '{"controller_missing": true, "method_missing": true}'), true);
                
            //     if (isset(debugSettings['method_missing'])) {
            //         if (debugSettings['method_missing'] == true) {
            //             exception = NotFoundHttpMethodException::class;
            //         } 
            //     }
            // }
            throw new {exceptionClass}(sprintf("Method '%s' does not exist in class '%s'", method, className), 404);
        }

        var parameters = this->getParameters();

        
        /* Filter parameters with null-value */

        if (this->filterEmptyParams === true) {
            let parameters = array_filter(parameters, function (variable) {
                return (variable !== null);
            });
        }


        let result = call_user_func_array([classValue, method], this->methodInjection(classValue, method, parameters, request));
        
        // if (result instanceof ViewModel || is_string(result) || is_scalar(result) || result instanceof View ) {
            echo result;
        // } elseif (result instanceof Redirect) {
        //     if (result->getPath() !== null) {
        //         result->header('Location: ' . result->getPath());
        //         exit();
        //     } else {
        //         throw new NotFoundHttpException("You have not provided a Redirect URL");
        //     }
        // }
        
    }

    protected function processBindings(request = null)
    {
        var modelBindingSettings = [];
        if (\file_exists(Helpers::path("config/AppRouteModelBinding.php"))) {
            let modelBindingSettings = require Helpers::path("config/AppRouteModelBinding.php");
        }
        
        if (count(modelBindingSettings) > 0) {
            var routeBindings = [], routeBinding, fields;
            for routeBinding, fields in modelBindingSettings {
                
                if count(explode("/", trim(routeBinding, "/"))) == count(explode("/", trim(request->getUri(), "/"))) {
                    var regex = sprintf(self::PARAMETERS_REGEX_FORMAT, this->paramModifiers[0], this->paramOptionalSymbol, this->paramModifiers[1]), parameters;
                    
                    if (preg_match_all("/" . regex . "/", routeBinding, parameters)) {
                        var index, field;
                        for index, field in explode(",", fields) {
                            let routeBindings[parameters[1][index]] = field;
                        }
                    }
                }
            }
            return routeBindings;
        }
        return [];
    }

    protected function methodInjection(className, method, params, request = null)
    {
        var parameters = null, reflection, dependecies = [];
        var app = Application::getInstance();
        let reflection = new ReflectionClass(className);
        if (reflection->hasMethod(method)) {
            var reflectionMethod = reflection->getMethod(method);
            var reflectionParameters = reflectionMethod->getParameters();
            var parameter;

            
            for (parameter in reflectionParameters) {
                if (!is_null(parameter->getType())) {
                    var dependency = parameter->getType()->getName();

                    // print_r(parameter->name);
                    // die();
                    var type = parameter->getType();
                    if (array_key_exists(parameter->name, params) && !type->isBuiltIn()) {
                        var dependencyObject;
                        let dependencyObject = new {dependency};
                        var modelBindingSettings = this->processBindings(request);
                        var field = dependencyObject->getPrimaryKey();

                        if (dependencyObject->getRouteKeyName() !== null && dependencyObject->getRouteKeyName() !== "") {
                            let field = dependencyObject->getRouteKeyName();
                        }

                        if (in_array(parameter->name, array_keys(modelBindingSettings))) {
                            let field = modelBindingSettings[parameter->name];
                        }

                        var value = params[parameter->name];
                        var modelBound = dependencyObject->where(field, value)->first();

                        if (modelBound) {
                            let dependecies[parameter->name] = modelBound;
                            if (Helpers::env("MODEL_BIND_VAR", false)) {
                                let dependecies[parameter->name . "_var"] = params[parameter->name];
                            }
                                
                        } else {
                            throw new ModelNotFoundException("Model dependency with field = 'value' not found");
                        } 

                    } else {
                        if (!type->isBuiltIn()) {
                            if (this->isSingleton(app, dependency)) {
                                let dependecies[parameter->name] = this->isSingleton(app, dependency);
                            } else {
                                let dependecies[parameter->name] = app->resolve(dependency);
                            }
                        } else {
                            let dependecies[parameter->name] = params[parameter->name];
                        }
                    }
                } else {
                    if (array_key_exists(parameter->name, params)) {
                        let dependecies[parameter->name] = params[parameter->name];
                    }
                } 
            }
            
            // dependecies[] = app;
            
        }
        //parameters = array_merge(dependecies, params);

        return dependecies;
    }

    protected function parseParameters(route, url, parameterRegex = null)
    {
        var regex = sprintf(self::PARAMETERS_REGEX_FORMAT, this->paramModifiers[0], this->paramOptionalSymbol, this->paramModifiers[1]);

        var parameters = [], matches;

        var urlRegex = preg_quote(route, "/");
        if (preg_match_all("/" . regex . "/", route, parameters)) {

            var urlParts = preg_split("/((\-?\/?)\{[^}]+\})/", rtrim(route, "/")), t, key;

            // foreach (urlParts as key => t) {
            for key, t in urlParts {

                var regex = "";

                if (key < count(parameters[1])) {

                    var name = parameters[1][key];

                    /* If custom regex is defined, use that */
                    if (isset(this->where[name]) === true) {
                        let regex = this->where[name];
                    } else {

                        /* If method specific regex is defined use that, otherwise use the default parameter regex */
                        if (parameterRegex !== null) {
                            let regex = parameterRegex;
                        } else {
                            let regex = (this->defaultParameterRegex === null) ? self::PARAMETERS_DEFAULT_REGEX : this->defaultParameterRegex;
                        }
                    }

                    let regex = sprintf("\-?\/?(?P<%s>%s)", name, regex) . parameters[2][key];

                }

                let urlParts[key] = preg_quote(t, "/") . regex;
            }

            let urlRegex = join("", urlParts);

        }

        if (preg_match("/^" . urlRegex . "(\/?)/", url, matches) > 0) {

            var values = [];

            if (isset(parameters[1]) === true) {
                var name;
                /* Only take matched parameters with name */
                for (name in parameters[1]) {

                    let values[name] = null;

                    if (isset(matches[name]) && matches[name] !== "") {
                        let values[name] = matches[name];
                    }
                }
            }

            return values;
        }

        return null;
    }

    /**
     * Returns callback name/identifier for the current route based on the callback.
     * Useful if you need to get a unique identifier for the loaded route, for instance
     * when using translations etc.
     *
     * @return string
     */
    public function getIdentifier()
    {
        if is_string(this->callback) === true && strpos(this->callback, "@") !== false {
            return this->callback;
        }

        return "function_" . md5(this->callback);
    }

    /**
     * Set allowed request methods
     *
     * @param array methods
     * @return static this
     */
    public function setRequestMethods(array methods)
    {
        let this->requestMethods = methods;

        return this;
    }

    /**
     * Get allowed request methods
     *
     * @return array
     */
    public function getRequestMethods()
    {
        return this->requestMethods;
    }

    /**
     * @return IRoute|null
     */
    public function getParent()
    {
        return this->parent;
    }

    /**
     * Get the group for the route.
     *
     * @return IGroupRoute|null
     */
    public function getGroup()
    {
        return this->group;
    }

    /**
     * Set group
     *
     * @param IGroupRoute group
     * @return static this
     */
    public function setGroup(<IGroupRoute> group)
    {
        let this->group = group;

        return this;
    }

    /**
     * Set parent route
     *
     * @param IRoute parent
     * @return static this
     */
    public function setParent(<IRoute> parent)
    {
        let this->parent = parent;

        return this;
    }

    /**
     * Set callback
     *
     * @param string callback
     * @return static
     */
    public function setCallback(callback)
    {
        let this->callback = callback;

        return this;
    }

    /**
     * @return string
     */
    public function getCallback()
    {
        return this->callback;
    }

    public function getMethod()
    {
        if (is_string(this->callback) === true && strpos(this->callback, '@') !== false) {
            var tmp = explode('@', this->callback);

            return tmp[1];
        }

        return null;
    }

    public function getClass()
    {
        if is_string(this->callback) === true && strpos(this->callback, '@') !== false {
            var tmp = explode('@', this->callback);

            return tmp[0];
        }

        return null;
    }

    public function setMethod(method)
    {
        let this->callback = sprintf("%s@%s", this->getClass(), method);

        return this;
    }

    public function setClass(className)
    {
        let this->callback = sprintf("%s@%s", className, this->getMethod());

        return this;
    }

    /**
     * @param string namespace
     * @return static this
     */
    public function setNamespace(namespaceValue)
    {
        let this->namespaceValue = namespaceValue;

        return this;
    }

    /**
     * @param string namespace
     * @return static this
     */
    public function setDefaultNamespace(namespaceValue)
    {
        let this->defaultNamespace = namespaceValue;

        return this;
    }

    public function getDefaultNamespace()
    {
        return this->defaultNamespace;
    }

    /**
     * @return string
     */
    public function getNamespace()
    {
        if (this->namespaceValue === null) {
            return this->defaultNamespace;
        }
        
        return this->namespaceValue;
    }

    /**
     * Export route settings to array so they can be merged with another route.
     *
     * @return array
     */
    public function toArray()
    {
        var values = [];

        if (this->namespaceValue !== null) {
            let values["namespace"] = this->namespaceValue;
        }

        if (count(this->requestMethods) > 0) {
            let values["method"] = this->requestMethods;
        }

        if (count(this->where) > 0) {
            let values["where"] = this->where;
        }

        if (count(this->middlewares) > 0) {
            let values["middleware"] = this->middlewares;
        }

        if (this->defaultParameterRegex !== null) {
            let values["defaultParameterRegex"] = this->defaultParameterRegex;
        }

        return values;
    }

    /**
     * Merge with information from another route.
     *
     * @param array values
     * @param bool merge
     * @return static this
     */
    public function setSettings(array values, merge = false)
    {
        if (this->namespaceValue === null && isset(values["namespace"])) {
            this->setNamespace(values["namespace"]);
        }

        if (isset(values["method"])) {
            this->setRequestMethods(array_merge(this->requestMethods, (array)values["method"]));
        }

        if (isset(values["where"])) {
            this->setWhere(array_merge(this->where, (array)values["where"]));
        }

        if (isset(values["parameters"])) {
            this->setParameters(array_merge(this->parameters, (array)values["parameters"]));
        }

        // Push middleware if multiple
        if (isset(values["middleware"])) {
            this->setMiddlewares(array_merge((array)values["middleware"], this->middlewares));
        }

        if (isset(values["defaultParameterRegex"])) {
            this->setDefaultParameterRegex(values["defaultParameterRegex"]);
        }

        return this;
    }

    /**
     * Get parameter names.
     *
     * @return array
     */
    public function getWhere()
    {
        return this->where;
    }

    /**
     * Set parameter names.
     *
     * @param array options
     * @return static
     */
    public function setWhere(array options)
    {
        let this->where = options;

        return this;
    }

    /**
     * Add regular expression parameter match.
     * Alias for LoadableRoute::where()
     *
     * @see LoadableRoute::where()
     * @param array options
     * @return static
     */
    public function where(array options)
    {
        return this->setWhere(options);
    }

    /**
     * Get parameters
     *
     * @return array
     */
    public function getParameters()
    {
        /* Sort the parameters after the user-defined param order, if any */
        var parameters = [];

        if (count(this->originalParameters) > 0) {
            let parameters = this->originalParameters;
        }

        return array_merge(parameters, this->parameters);
    }

    /**
     * Get parameters
     *
     * @param array parameters
     * @return static this
     */
    public function setParameters(array parameters)
    {
        /*
         * If this is the first time setting parameters we store them so we
         * later can organize the array, in case somebody tried to sort the array.
         */
        if (count(parameters) > 0 && count(this->originalParameters) === 0) {
            let this->originalParameters = parameters;
        }

        let this->parameters = array_merge(this->parameters, parameters);

        return this;
    }

    /**
     * Add middleware class-name
     *
     * @deprecated This method is deprecated and will be removed in the near future.
     * @param IMiddleware|string middleware
     * @return static
     */
    public function setMiddleware(middleware)
    {
        let this->middlewares[] = middleware;

        return this;
    }

    /**
     * Add middleware class-name
     *
     * @param IMiddleware|string middleware
     * @return static
     */
    public function addMiddleware(middleware)
    {
        let this->middlewares[] = middleware;

        return this;
    }

    /**
     * Set middlewares array
     *
     * @param array middlewares
     * @return this
     */
    public function setMiddlewares(array middlewares)
    {
        let this->middlewares = middlewares;

        return this;
    }

    /**
     * @return string|array
     */
    public function getMiddlewares()
    {
        return this->middlewares;
    }

    /**
     * Set default regular expression used when matching parameters.
     * This is used when no custom parameter regex is found.
     *
     * @param string regex
     * @return static this
     */
    public function setDefaultParameterRegex(regex)
    {
        let this->defaultParameterRegex = regex;

        return this;
    }

    /**
     * Get default regular expression used when matching parameters.
     *
     * @return string
     */
    public function getDefaultParameterRegex()
    {
        return this->defaultParameterRegex;
    }
}