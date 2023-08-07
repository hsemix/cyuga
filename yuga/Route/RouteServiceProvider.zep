namespace Yuga\Route;

// use Yuga\Route\Route;
use Yuga\Providers\ServiceProvider;
use Yuga\Interfaces\Application\Application;

class RouteServiceProvider extends ServiceProvider
{
    public function load(<Application> app)
    {
        if (!app->runningInConsole()) {
            app->singleton("router", "\\Yuga\\Route\\Route");
            app->resolve("router")->start();
        }
    }  
}