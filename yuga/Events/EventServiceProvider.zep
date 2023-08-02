namespace Yuga\Events;

use Yuga\Console\Events\YugaStart;
use Yuga\Providers\ServiceProvider;
use Yuga\Interfaces\Application\Application;
use Yuga\Interfaces\Events\DispatcherInterface;

class EventServiceProvider extends ServiceProvider
{
    protected app;
    /**
     * All Yuga default events registered here!
     * 
     * @var array events
     */
    protected events = [
        "on:app-start"      : "\\Yuga\\EventHandlers\\ApplicationStart",
        "on:app-stop"       : "\\Yuga\\EventHandlers\\ApplicationStop"
        // "on:authenticate"   : "\Yuga\EventHandlers\Auth\UserLoggedIn",
        // "on:signup"         : "\Yuga\EventHandlers\Auth\UserRegistered",
        // "on:signout"        : "\Yuga\EventHandlers\Auth\UserLoggedOut",
        // "on:hax-render"     : "\Yuga\EventHandlers\Hax\Rendered",
        // "on:hax-instance"   : "\Yuga\EventHandlers\Hax\HaxInstance",
        // "on:hax-extension"  : "\Yuga\EventHandlers\Hax\HaxExtension"
    ];

    /**
     * Boot the event service provider with app 
     * 
     * @param \Yuga\Interfaces\Application\Application app
     * 
     * @return void
     */
    public function __construct(<Application> app)
    {
        let this->app = app;
    }

    /**
     * Load a service provider
     * 
     * @param \Yuga\Interfaces\Application\Application app
     * 
     * @return mixed
     */
    public function load(<Application> app)
    {
        app->singleton("events", this->loadEvents(new Event(app)));

        // if (app->runningInConsole()) {
        //     app->singleton('console.events', function () use (app) {
        //         return new YugaStart(app);
        //     });
        // }
    }
    
    /**
     * Load all event handlers that have been registered by the developer
     * 
     * @param \Yuga\Events\DispatcherInterface dispatcher
     * 
     * @return \Yuga\Events\Event dispatcher
     */
    protected function loadEvents(<DispatcherInterface> dispatcher)
    {
        var otherApplicationEvents = [], handlers, event, handles;

        // if (\file_exists(path('config/AppEvents.php'))) {
        //     let otherApplicationEvents = require path('config/AppEvents.php');
        // }
        let handlers = array_merge(this->events,  otherApplicationEvents);

        for event, handles in handlers {
            if (is_array(handles)) {
                var handle;
                for handle in handles {
                    if (is_array(handle)) {
                        dispatcher->attach(event, [this->app->resolve(handle[0]), handle[1]]);
                    } else {
                        dispatcher->attach(event, this->app->resolve(handle));
                    }
                }
            } else {
                dispatcher->attach(event, this->app->resolve(handles));
            }
        }
        return dispatcher;
    }
}