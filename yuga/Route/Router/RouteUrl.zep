namespace Yuga\Route\Router;

use Yuga\Http\Request;

class RouteUrl extends LoadableRoute
{
    public function __construct(url, callback)
    {
        this->setUrl(url);
        this->setCallback(callback);
    }

    public function matchRoute(url, <Request> request)
    {

        let url = parse_url(urldecode(url), PHP_URL_PATH);
        let url = rtrim(url, "/") . "/";
        /* Match global regular-expression for route */
        var regexMatch = this->matchRegex(request, url);

        if (regexMatch === false) {
            return false;
        }

        /* Parse parameters from current route */
        var parameters = this->parseParameters(this->url, url);

        /* If no custom regular expression or parameters was found on this route, we stop */
        if (regexMatch === null && parameters === null) {
            return false;
        }

        /* Set the parameters */
        this->setParameters((array)parameters);

        return true;
    }

    public function getParams(key = null)
    {
        if key != null {
            return this->parameters[key];
        }

        return this->parameters;
    }
}