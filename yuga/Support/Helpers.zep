namespace Yuga\Support;

class Helpers
{
    public static function view(template = null, data = [])
    {

    }

    public static function path(file = null)
    {
        return _ENV["base_path"] . DIRECTORY_SEPARATOR . file;
    }

    public static function storage(path = null) 
    {
        return self::path("storage" . DIRECTORY_SEPARATOR . path);
    }

    public static function env(key, defaultValue = null)
    {
        if isset(_ENV[key]) {
                        
            if _ENV[key] == "" || is_null(_ENV[key]) {
                return defaultValue;
            } 
            
            return _ENV[key];
        }

        return defaultValue;
    }

    public static function app(param = null)
    {
        if param {
            if class_exists(param) {
                return \Yuga\Application\Application::getInstance()->resolve(param);
            }

            return \Yuga\Application\Application::getInstance()->make(param);       
        }  

        return \Yuga\Application\Application::getInstance();
    }

    public static function event(eventName = "yuga.auto.events", params = [])
	{
		return self::app()->get("events")->trigger(eventName, params);
	}
}