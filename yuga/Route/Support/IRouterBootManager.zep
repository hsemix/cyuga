namespace Yuga\Route\Support;

use Yuga\Http\Request;

interface IRouterBootManager
{
    /**
     * Called when router loads it's routes
     *
     * @param Route router
     * @param Request request
     */
    public function boot(<Request> request);
}