namespace Yuga\Interfaces\Providers;

use Yuga\Interfaces\Application\Application;

interface ServiceProviderInterface
{
    public function register(<Application> $app);
}