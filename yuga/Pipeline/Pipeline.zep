namespace Yuga\Pipeline;

use Closure;
use Yuga\Support\Helpers;
use InvalidArgumentException;

class Pipeline
{
    protected passable;
    protected pipes;
    protected method = "run";

    public static function send(passable)
    {
        var pipeline;
        let pipeline = new self;

        let pipeline->passable = passable;

        return pipeline;
    }

    public function through(array pipes)
    {
        let this->pipes = pipes;


        // print_r(this->pipes);
        // die();
        return this;
    }

    public function then(<Closure> destination)
    {
        var pipeline;
        
        let pipeline = array_reduce(
            this->pipes,
            // array_reverse(this->pipes),
            this->carry()
            // function (passable) use (destination) {
            //     return {destination}(passable);
            //     // return call_user_func(destination, passable);
            // }
        );


        // print_r(this->carry());

        // exit();

        return {pipeline}(this->passable);

        // return call_user_func(pipeline, this->passable);
    }

    public function thenReturn()
    {
        return this->then(function (passable) {
            return passable;
        });
    }

    protected function carry()
    {
        var currentObject = this;
        
        return function (pipeStack, pipe) use (currentObject) {
            
            return currentObject->passable(pipeStack, pipe);
        };
    }

    protected function passable(pipeStack, pipe)
    {
        return function (passable) use (pipeStack, pipe) {
            // if (is_callable(pipe)) {
            //     return call_user_func_array(pipe, [passable, pipeStack]);
            // } 
            // else
            // if (is_object(pipe)) {
            //     return call_user_func_array([pipe, "run"], [passable, pipeStack]);
            // } else
            if (is_string(pipe) && class_exists(pipe)) {

                return call_user_func_array([Helpers::app(pipe), "run"], [passable, pipeStack]);
            } else {
                throw new InvalidArgumentException("Invalid pipe type.");
            }
        };
    }
}