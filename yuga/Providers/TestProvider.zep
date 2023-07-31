namespace Yuga\Providers;

use Yuga\Interfaces\Application\Application;

class TestProvider extends ServiceProvider
{
    public function getName()
    {
        return "Hello world!";
    }

    public function load(<Application> app)
    {

    }
}