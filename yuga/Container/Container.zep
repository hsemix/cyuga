namespace Yuga\Container;

use Closure;
use Exception;
use ArrayAccess;
use ReflectionClass;
use ReflectionMethod;
use ReflectionFunction;
use ReflectionNamedType;
use ReflectionParameter;
use InvalidArgumentException;
use Yuga\Container\Support\ClassNotInstantiableException;

class Container implements ArrayAccess
{
    protected bindings = [];

    protected instances = [];

    private static thisInstances = [];
    /**
     * An array of the types that have been resolved.
     *
     * @var array
     */
    protected resolved = [];


    public function offsetGet(key)
    {
        return this->make(key);
    }

    public function offsetSet(key, value)
    {
        this->bind(key, value);
    }

    public function offsetExists(key)
    {
        return array_key_exists(key, this->bindings);
    }

    public function offsetUnset(key)
    {
        unset(this->bindings[key]);
    }

    public function bind(key, value, singleton = false)
    {
        let key = ltrim(key, "\\");

        if value instanceof Closure {
            if (singleton) {
                let this->instances[key] = value(this);
            }
            let this->bindings[key] = value(this);
        } else {
            let this->bindings[key] = compact("value", "singleton");
        }
        
    }

    /**
     * Determine if the given abstractValue type has been bound.
     *
     * @param  string  abstractValue
     * @return bool
     */
    public function bound(abstractValue)
    {
        return isset(this->bindings[abstractValue]) || isset(this->instances[abstractValue]);
    }

    /**
     * Determine if the given abstractValue type has been resolved.
     *
     * @param  string  abstractValue
     * @return bool
     */
    public function resolved(abstractValue)
    {
        return isset(this->resolved[abstractValue]) || isset(this->instances[abstractValue]);
    }

    public function has(key)
    {
        if (array_key_exists(key, this->instances) || array_key_exists(key, this->bindings)) {
            return true;
        }
        return false;
    }

    public function singleton(key, value)
    {
        return this->bind(key, value, true);
    }

    public function getBinding(var key)
    {
        let key = ltrim(key, "\\");
        if !array_key_exists(key, this->bindings) {
            return null;
        } elseif array_key_exists(key, this->instances) {
            return this->instances[key];
        } elseif(this->bindings[key] instanceof Closure) {
            return this->bindings[key];
        } else {
            return this->bindings[key]["value"];
        }
    }

    public function getBindings()
    {
        return array_keys(this->bindings);
    }

    public function make(key)
    {
        return this->getBinding(key);
    }

    public function get(key)
    {
        if array_key_exists(key, this->instances) {
            return this->getBinding(key);
        } elseif this->bindings[key] instanceof Closure {        
            return this->getBinding(key);
        } elseif is_string(this->bindings[key]) && strpos(this->bindings[key], '/') != false {
            return this->getBinding(key);
        } elseif is_object(this->bindings[key]) {
            return this->make(key);
        } else {
            return this->resolve(key);
        }
        
    }

    public function getSingletons()
    {
        return this->instances;
    }

    protected function isSingleton(key)
    {
        var binding = this->getBinding(key);
        if (binding == null) {
            return false;
        }

        return true;
    }

    protected function singletonResolved(key)
    {
        return array_key_exists(key, this->instances);
    }

    protected function getSingletonInstance(key)
    {
        return this->singletonResolved(key) ? this->instances[key] : null;
    }

    protected function prepareObject(key, objectValue)
    {
        if (this->isSingleton(key)) {
            let this->instances[key] = objectValue;
        }

        return objectValue;
    }

    public function resolve(key, array arguments = [])
    {
        
        var classVar = this->getBinding(key);
        if (classVar == null) {
            let classVar = key;
        }

        if (this->isSingleton(key) && this->singletonResolved(key)) {
            return this->getSingletonInstance(key);
        }
        
        var objectVar = this->buildObject(classVar, arguments);
        return this->prepareObject(key, objectVar);
    }


    public function inSingletons(classValue)
    {
        var instanceObject;
        for instanceObject in array_values(this->getSingletons()) {
            if get_class(instanceObject) == classValue {
                return instanceObject;
            }
        }
        return false;
    }

    protected function buildDependencies(arguments, dependencies, className)
    {
        var dependency;
        for dependency in dependencies {

            var name = dependency->getName();
            
            var type = dependency->getType();

            if (dependency->isOptional()) {
                continue; 
            }    
            
            if (dependency->getType() == null) {
                continue;
            }

            if (type->isBuiltIn()) {
                continue;
            }

            if !type {
                continue;
            }

            if type instanceof ReflectionUnionType {
                throw new Exception("Failed to resolve class '" . dependency . "' because of a union type");
            }

            if type && type instanceof ReflectionNamedType {

                if get_class(this) === type->getName() {
                    let arguments[] = this;
                    continue;
                }
                // make instance of this class :
                var paramInstance = this->resolve(type->getName());

                // push to dependencies array
                let arguments[]  = paramInstance;

            } else {

                let name = dependency->getName(); // get the name of param

                // check this param value exist in parameters
                if (array_key_exists(name, arguments)) { // if exist

                    // push  value to dependencies sequencially
                    let dependencies[] = arguments[name];

                } else { // if not exist

                    if (!dependency->isOptional()) { // check if not optional
                        throw new Exception("Class " . name . " cannot be Instantiated");
                    }

                }

            }

        }

        return arguments;
    }

    protected function buildObject(classValue, array arguments = [])
    {
        var objectValue, className, reflector, newObject;
        if is_array(classValue) {
            let className = classValue["value"];
        } else {
            let className = classValue;
        }
        
        let reflector = new ReflectionClass(className);
        
        if !reflector->isInstantiable() {
            throw new ClassNotInstantiableException("Class " . className . " cannot be Instantiated");
        }
        
        if !is_null(reflector->getConstructor()) {
            var constructor = reflector->getConstructor();
            var dependencies = constructor->getParameters();

            let arguments = this->buildDependencies(arguments, dependencies, classValue); 
            let objectValue = reflector->newInstanceArgs(arguments);    
            
        } else {
            let newObject = new reflector;
            let objectValue = newObject->name;
        }
        
        return objectValue;
    }

    /**
     * Call the given Closure / class@method and inject its dependencies.
     *
     * @param  callable|string  callback
     * @param  array  parameters
     * @param  string|null  defaultMethod
     * @return mixed
     */
    public function call(callback, array parameters = [], defaultMethod = null)
    {
        var dependencies;
        if (this->isCallableWithAtSign(callback) || defaultMethod) {
            return this->callClass(callback, parameters, defaultMethod);
        }

        let dependencies = this->getMethodDependencies(callback, parameters);

        return call_user_func_array(callback, dependencies);
    }

    /**
     * Call a string reference to a class using Class@method syntax.
     *
     * @param  string  target
     * @param  array  parameters
     * @param  string|null  defaultMethod
     * @return mixed
     */
    protected function callClass(target, array parameters = [], defaultMethod = null)
    {
        var method, segments;
        let segments = explode('@', target);

        // If the listener has an @ sign, we will assume it is being used to delimit
        // the class name from the handle method name. This allows for handlers
        // to run multiple handler methods in a single class for convenience.
        
        let method = defaultMethod;
        if count(segments) == 2 {
            let method = segments[1];
        }

        if (is_null(method)) {
            throw new InvalidArgumentException("Method not provided.");
        }

        return this->call([this->buildObject(segments[0]), method], parameters);
    }

    /**
     * Determine if the given string is in Class@method syntax.
     *
     * @param  mixed  callback
     * @return bool
     */
    protected function isCallableWithAtSign(callback)
    {
        if !is_string(callback) {
            return false;
        }

        return strpos(callback, '@') != false;
    }

     /**
     * Get all dependencies for a given method.
     *
     * @param  callable|string  callback
     * @param  array  parameters
     * @return array
     */
    protected function getMethodDependencies(callback, array parameters = [])
    {
        var dependencies = [], key, parameter;

        //  
        
        var reflector = this->getCallReflector(callback);

        for key, parameter in reflector->getParameters() {
            this->addDependencyForCallParameter(parameter, parameters, dependencies);
        }

        return array_merge(dependencies, parameters);
    }

    /**
     * Get the proper reflection instance for the given callback.
     *
     * @param  callable|string  callback
     * @return \ReflectionFunctionAbstract
     */
    protected function getCallReflector(var callback)
    {
        if (is_string(callback) && strpos(callback, "::") != false) {
            let callback = explode("::", callback);
        }

        if (is_array(callback)) {
            return new ReflectionMethod(callback[0], callback[1]);
        }

        return new ReflectionFunction(callback);
    }

    /**
     * Get the dependency for the given call parameter.
     *
     * @param  \ReflectionParameter  $parameter
     * @param  array  parameters
     * @param  array  dependencies
     * @return mixed
     */
    protected function addDependencyForCallParameter(<ReflectionParameter> parameter, array parameters, dependencies)
    {
        if array_key_exists($parameter->name, parameters) {
            let dependencies[] = parameters[$parameter->name];

            unset(parameters[parameter->name]);
        } elseif parameter->getType() {
            var classValue = $parameter->getType() ? $parameter->getType()->getName() : null;

            if !parameter->isOptional() {
                if !\is_null(classValue) {
                    let dependencies[] = this->buildObject(classValue);
                } 
            }
        } elseif parameter->isDefaultValueAvailable() {
            let dependencies[] = $parameter->getDefaultValue();
        }

        return dependencies;
    }
}