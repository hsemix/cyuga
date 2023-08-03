namespace Yuga\Support;

class Helpers
{
    public static function view(template = null, data = [])
    {

    }

    public static function path(file = null)
    {
        return self::app()->basePath(DIRECTORY_SEPARATOR . file);
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
		return self::app()->make("events")->trigger(eventName, params);
	}

    public static function cookie()
    {
        return self::app()->make("cookie");
    }

    // public static function class_base(var classValue)
    // {
    //     var classValue = classValue;

    //     if is_object(classValue) {
    //         let classValue = get_class(classValue);
    //     }
        
    //     return basename(str_replace("\\", "/", classValue));
    // }

    // public static function response()
    // {
    //     // return Route::response();
    // }

    // public static function request()
    // {
    //     // return Route::request();
    // }

    // public static function input()
    // {
    //     // return request()->getInput();
    // }

    // public static function redirect(url = null, code = null)
    // {
    //     // if (code !== null) {
    //     //     response()->httpCode(code);
    //     // }
        
    //     // return response()->redirect(url);
    // }

    // public static function fullHost(value ="")
    // {
    //     // return self::host(value);
    // }

    public static function scheme(value = null)
    {
        var scheme = "http";
        
        if isset(_SERVER["REQUEST_SCHEME"]) {
            let scheme = _SERVER["REQUEST_SCHEME"];
        }
        return scheme ."://".value;
    }
}