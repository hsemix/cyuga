namespace Yuga\Events;

use Closure;
use Yuga\Events\Dispatcher\Dispatcher;
use Yuga\EventHandlers\HandlerInterface;
use Yuga\Events\Exceptions\EventException;
use Yuga\Interfaces\Events\DispatcherInterface;

class Event implements DispatcherInterface
{
    /**
     * @var array list of attributes
    */
    private attributes = [];

    /**
     * @var array list of listeners
     */
    protected listeners = [];

    /**
     * @var string name of the default events
     */
    protected name = "yuga.auto.events";

    public function __get(key)
    {
        return this->getAttribute(key);
    }
	/**
	* Set a variable and make an object point to it
	*/
    public function __set(key, value)
    {
        this->setAttribute(key, value);
    }

    public function setAttribute(key, value)
    {
        let this->attributes[key] = value;
        
        return this;
    }

    /**
     * Get an attribute from the event.
     *
     * @param  string  key
     * @return mixed
     */
    public function getAttribute(name)
    {
        return this->attributes[name];
    }

    /**
     * Attach callback to event
     *
     * @param  string   eventName
     * @param  callable callback|null
     * @param  int  priority
     *
     * @return void
     */
    public function attach(eventName, callback = null, priority = 1)
    {
        var args = func_get_args();
        if (eventName instanceof Dispatcher) {
            let eventName = eventName->getName();
        }

        if (count(args) == 1) {
            this->triggerObjectHandlers(eventName);
        } else {
            if (!isset(this->listeners[eventName])) {
                let this->listeners[eventName] = [];
            }
            if (!isset(this->listeners[eventName][priority])) {
                let this->listeners[eventName][priority] = [];
            }
            let this->listeners[eventName][priority][] = callback;
        }
        return this;
    }

    /**
     * Allias to the attach method
     *
     * @param  string   eventName
     * @param  callable callback|null
     * @param  int  priority
     *
     * @return void
     */
    public function on(eventName, callback = null, priority = 1)
    {
        return this->attach(eventName, callback, priority);
    }

    /**
     * Some times the name provided in the attach method might be an instance of the HandlerInterface
     * When that happens, Make sure the event has the handle method
     * 
     * @param array|string handlers
     * 
     * @return void
     */
    protected function triggerObjectHandlers(handlers)
    {
        var handler;
        if is_array(handlers) {
            for handler in handlers {
            
                if !method_exists(handler, "handle") {
                    throw new EventException(get_class(handler)." must implement the `handle` method");
                }
                let this->listeners[this->name][1][] = [handler, "handle"];
            }
            return;
        }
        if (!method_exists(handlers, "handle")) {
            throw new EventException(get_class(handlers)." must implement the `handle` method");
        }

        let this->listeners[this->name][1][] = [handlers, "handle"];
    }

    /**
     * Dispatch event
     *
     * @param  string|Event  event
     * @param  array  parameters
     *
     * @return Event event
     */
    public function dispatch(var event = null, parameters = null, callback = null)
    {
        var params;
        if (count(func_get_args()) == 2) {
            var items = this->getParameters(parameters);

            let params = items["params"];
            let callback = items["callback"];
        } else {
            let params = parameters;
        }

        if (!event) {
            let event = this->name;
        }
            
        if is_string(event) {
            let event = new Dispatcher(event, params);
        }

        event->setAttributes(this->attributes);
        event->setAttribute("dispatcher", this);
        
        var paramValue = [];

        if params {
            let paramValue = params;
        }

        let params = array_merge([event], paramValue);
        if (false != strpos(event->getName(), ":")) {
            var eventNamespace = substr(event->getName(), 0, strpos(event->getName(), ":"));
            if (isset(this->listeners[eventNamespace])) {
                this->fire(this->listeners[eventNamespace], event, params, callback);
            }
        }

        if (isset(this->listeners[event->getName()])) {
            
            this->fire(this->listeners[event->getName()], event, params, callback);
        }
        return event;
    }

    /**
     * Alias for dispatch
     * 
     * @param  string|Event  event
     * @param  array  parameters
     *
     * @return Event event
     */
    public function trigger(event = null, parameters = null, callback = null)
    {
        if (count(func_get_args()) == 2) {
            return this->dispatch(event, parameters);
        }
        return this->dispatch(event, parameters, callback);
    }

    /**
     * Organise parameters to suit both two and three arguments as a user dispatches or triggers the event
     * 
     * @param parameters
     * 
     * @return array items
     */
    protected function getParameters(parameters = null)
    {
        var items = [];
        if (parameters instanceof Closure) {
            let items["params"] = [];
            let items["callback"] = parameters;
        } else {
            let items["params"] = parameters;
            let items["callback"] = null;
        }

        return items;
    }

    /**
     * Fire an Event
     *
     * @param  array listeners
     * @param  Dispatcher event
     * @param array params
     * @param callable|null callback
     *
     * @return void
     */
    protected function fire(listeners, event, array params = [], callback = null)
    {    
        var list, listener;    
        ksort(listeners);

        for list in listeners {
            for listener in list {
                var eventParams, eventListener;
                let eventParams = params;
                if (is_array(listener)) {
                    let eventListener = listener;
                } elseif (listener instanceof Closure) {
                   let  eventListener = listener;
                } else {
                    let eventListener = [listener, "handle"];
                    if (listener instanceof HandlerInterface) {
                        if (array_values(params) !== params) {
                            event->setAttributes(params);
                            let eventParams = [event];
                        } 
                    }
                }

                call_user_func_array(eventListener, array_values(eventParams));
                if (callback instanceof Closure) {
                    // callback(event);
                    return call_user_func(callback, event);
                }
                    
            }
        }
    }
}