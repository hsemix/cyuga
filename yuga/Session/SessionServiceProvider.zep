namespace Yuga\Session;

use Yuga\Providers\ServiceProvider;
use Yuga\Interfaces\Application\Application;

class SessionServiceProvider extends ServiceProvider
{
    public function load(<Application> app)
    {
        if (!app->runningInConsole()) {
            app->singleton("session", "Yuga\\Session\\Session");
            app->resolve("session");
        }
    }
}