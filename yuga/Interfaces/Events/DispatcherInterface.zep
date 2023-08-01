namespace Yuga\Interfaces\Events;

interface DispatcherInterface
{
    public function dispatch(event = null, parameters = null, callback = null);
}