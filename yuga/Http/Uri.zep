namespace Yuga\Http;

use Yuga\Http\Exceptions\BadFormedUrlException;

class Uri
{
    private originalUrl;
    private scheme;
    private host;
    private port;
    private username;
    private password;
    private path;
    private params;
    private fragment;

    /**
     * Url constructor.
     *
     * @param string url
     * @throws BadFormedUrlException
     */
    public function __construct(url)
    {
        let this->originalUrl = url;

        if (url !== null && url !== "/") {
            var data = this->parseUrl(url);

            let this->scheme = null;
            let this->host = null;
            let this->port = null;
            let this->username = null;
            let this->password = null;
            let this->fragment = null;
            
            if isset(data["scheme"]) {
                let this->scheme = data["scheme"];
            }
            
            if isset(data["host"]) {
                let this->host = data["host"];
            }
            
            if isset(data["port"]) {
                let this->port = data["port"];
            }
            
            if isset(data["user"]) {
                let this->username = data["user"];
            }
            
            if isset(data["pass"]) {
                let this->password = data["pass"];
            }

            if (isset(data["path"]) === true) {
                this->setPath(data["path"]);
            }

            if isset(data["fragment"]) {
                let this->fragment = data["fragment"];
            } 

            if (isset(data["query"]) === true) {
                var params = [];
                parse_str(data["query"], params);
                this->setParams(params);
            }
        }
    }

    /**
     * Check if url is using a secure protocol like https
     *
     * @return bool
     */
    public function isSecure()
    {
        return (strtolower(this->getScheme()) === "https");
    }

    /**
     * Checks if url is relative
     *
     * @return bool
     */
    public function isRelative()
    {
        return (this->getHost() === null);
    }

    /**
     * Get url scheme
     *
     * @return string|null
     */
    public function getScheme()
    {
        return this->scheme;
    }

    /**
     * Set the scheme of the url
     *
     * @param string scheme
     * @return static
     */
    public function setScheme(scheme)
    {
        let this->scheme = scheme;

        return this;
    }

    /**
     * Get url host
     *
     * @return string|null
     */
    public function getHost()
    {
        return this->host;
    }

    /**
     * Set the host of the url
     *
     * @param string host
     * @return static
     */
    public function setHost(host)
    {
        let this->host = host;

        return this;
    }

    /**
     * Get url port
     *
     * @return int|null
     */
    public function getPort()
    {
        if (this->port !== null) {
            return (int)this->port;
        } 
        return null;
    }

    /**
     * Set the port of the url
     *
     * @param int port
     * @return static
     */
    public function setPort(port)
    {
        let this->port = port;

        return this;
    }

    /**
     * Parse username from url
     *
     * @return string|null
     */
    public function getUsername()
    {
        return this->username;
    }

    /**
     * Set the username of the url
     *
     * @param string username
     * @return static
     */
    public function setUsername(username)
    {
        let this->username = username;

        return this;
    }

    /**
     * Parse password from url
     * @return string|null
     */
    public function getPassword()
    {
        return this->password;
    }

    /**
     * Set the url password
     *
     * @param string password
     * @return static
     */
    public function setPassword(password)
    {
        let this->password = password;

        return this;
    }

    /**
     * Get path from url
     * @return string
     */
    public function getPath()
    {
        if isset(this->path) {
            return this->path;
        } 
        
        return "/";
    }

    /**
     * Set the url path
     *
     * @param string path
     * @return static
     */
    public function setPath(path)
    {
        let this->path = rtrim(path, "/") . "/";

        return this;
    }

    /**
     * Get query-string from url
     *
     * @return array
     */
    public function getParams()
    {
        return this->params;
    }

    /**
     * Merge parameters array
     *
     * @param array params
     * @return static
     */
    public function mergeParams(array params)
    {
        return this->setParams(array_merge(this->getParams(), params));
    }

    /**
     * Set the url params
     *
     * @param array params
     * @return static
     */
    public function setParams(array params)
    {
        let this->params = params;

        return this;
    }

    /**
     * Get query-string params as string
     *
     * @return string
     */
    public function getQueryString()
    {
        return static::arrayToParams(this->getParams());
    }

    /**
     * Get fragment from url (everything after #)
     *
     * @return string|null
     */
    public function getFragment()
    {
        return this->fragment;
    }

    /**
     * Set url fragment
     *
     * @param string fragment
     * @return static
     */
    public function setFragment(fragment)
    {
        let this->fragment = fragment;

        return this;
    }

    /**
     * @return string
     */
    public function getOriginalUrl()
    {
        return this->originalUrl;
    }

    /**
     * Get position of value.
     * Returns -1 on failure.
     *
     * @param string value
     * @return int
     */
    public function indexOf(value)
    {
        var index;
        let index = stripos(this->getOriginalUrl(), value);


        if (index === false) {
            return -1;
        } 
        
        return index;
    }

    /**
     * Check if url contains value.
     *
     * @param string value
     * @return bool
     */
    public function contains(value)
    {
        return (stripos(this->getOriginalUrl(), value) !== false);
    }

    /**
     * Check if url contains parameter/query string.
     *
     * @param string name
     * @return bool
     */
    public function hasParam(name)
    {
        return \in_array(name, this->getParams(), true);
    }

    /**
     * Removes parameter from query-string
     *
     * @param string name
     */
    public function removeParam(name)
    {
        if (this->hasParam(name) === true) {
            var params = this->getParams(), key;
            let key = \array_search(name, params, true);

            if (key === true) {
                unset(params[key]);
                this->setParams(params);
            }
        }
    }

    /**
     * Get parameter by name.
     * Returns parameter value or default value.
     *
     * @param string name
     * @param string|null defaultValue
     * @return string|null
     */
    public function getParam(name, defaultValue = null)
    {
        var output = null;

        if (this->hasParam(name) === true) {
            var params = this->getParams(), key;
            let key = \array_search(name, params, true);

            if (key === true) {
                let output = params[key];
            }
        }

        if output {
            return output;
        }
        return defaultValue;
    }

    /**
     * UTF-8 aware parse_url() replacement.
     * @param string url
     * @param int component
     * @return array
     * @throws BadFormedUrlException
     */
    public function parseUrl(url, component = -1)
    {
        var encodedUrl;
        var parts;
        let encodedUrl = preg_replace_callback(
            "/[^:\/@?&=#]+/u",
            function (matches) {
                return urlencode(matches[0]);
            },
            url
        );

        let parts = parse_url(encodedUrl, component);

        if (parts === false) {
            throw new BadFormedUrlException(sprintf("Failed to parse url: \"%s\"", url));
        }

        return array_map("urldecode", parts);
    }

    /**
     * Convert array to query-string params
     *
     * @param array getParams
     * @param bool includeEmpty
     * @return string
     */
    public static function arrayToParams(array getParams = null, includeEmpty = true)
    {
        if (getParams != null) {

            if (includeEmpty === false) {
                let getParams = array_filter(getParams, function (item) {
                    return (trim(item) !== "");
                });
            }

            return http_build_query(getParams);
        }

        return "";
    }

    /**
     * Returns the relative url
     *
     * @return string
     */
    public function getRelativeUrl()
    {
        var params = this->getQueryString();

        var path = "", query = "", fragment = "";

        if isset(this->path) {
            let path = this->path;
        }

        if params !== "" {
            let query = "?" . params;
        }

        if this->fragment !== null {
            let fragment = "#" . this->fragment;
        }

        return path . query . fragment;
    }

    /**
     * Returns the absolute url
     *
     * @return string
     */
    public function getAbsoluteUrl()
    {
        var scheme = "", host = "", port = "", user = "", pass = "";

        if this->scheme !== null {
            let scheme = this->scheme . "://";
        }

        if isset(this->host) {
            let host = this->host;
        } 
        
        if this->port !== null {
            let port = ":" . this->port;
        } 
        
        if isset(this->username) {
            let user = this->username;
        } 
        
        if this->password !== null {
            let pass = ":" . this->password;
        } 
        
        if (user || pass) {
            let pass = pass . "@";
        } 

        return scheme . user . pass . host . port . this->getRelativeUrl();
    }

    public function __toString()
    {
        return this->getRelativeUrl();
    }

}