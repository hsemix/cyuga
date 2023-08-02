namespace Yuga\Cookie;

class Cookie
{
    public static function exists(name)
    {            
        if isset(_COOKIE[name]) {
            return true;
        }
        return false;
    }

    public static function get(name)
    {
        return _COOKIE[name];
    }

    public static function put(name, value, expiry = null, domain = null, secure = true, path = "/")
    {
        return self::create(name, value, expiry, domain, secure, path);
    }

    public static function create(name, value, expiry = null, domain = null, secure = true, path = "/")
    {
        if !empty(name) && !is_null(name) {
            // if (domain === null) {
            //     var sub = explode('.', request()->getHost());
            //     let domain = (count(sub) > 2) ? request()->getHost() :  request()->getHost();
            // }
            if expiry === null {
                let expiry = time() + 60 * 60 * 24 * 6004;
            } else {
                let expiry = time() + expiry;
            }

            var expiryValue = null;

            if expiry > 0 {
                let expiryValue = expiry;
            }

            return setcookie(name, value, expiryValue, path, domain, secure);
        }
    }
    
    public static function delete(name)
    {
        return self::put(name, "", - 1);
    }
}