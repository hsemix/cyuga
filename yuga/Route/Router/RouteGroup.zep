namespace Yuga\Route\Router;

use Yuga\Http\Request;
use Yuga\Route\Support\IGroupRoute;
use Yuga\Handlers\IExceptionHandler;

class RouteGroup extends Route implements IGroupRoute
{
    protected prefix;
    protected name;
    protected domains = [];
    protected exceptionHandlers = [];

    /**
     * Method called to check if a domain matches
     *
     * @param Request request
     * @return bool
     */
    public function matchDomain(<Request> request)
    {
        var domain;
        if (this->domains === null || count(this->domains) === 0) {
            return true;
        }

        for domain in this->domains {

            var parameters = this->parseParameters(domain, request->getHost(), ".*");

            if (parameters !== null && count(parameters) > 0) {

                let this->parameters = parameters;

                return true;
            }
        }

        return false;
    }

    /**
     * Method called to check if route matches
     *
     * @param string url
     * @param Request request
     * @return bool
     */
    public function matchRoute(url, <Request> request)
    {
        if (this->getGroup() !== null && this->getGroup()->matchRoute(url, request) === false) {
            return false;
        }
        /* Skip if prefix doesn"t match */
        if (this->prefix !== null && stripos(url, this->prefix) === false) {
            return false;
        }

        return this->matchDomain(request);
    }

    /**
     * Add exception handler
     *
     * @param IExceptionHandler|string handler
     * @return static this
     */
    public function addExceptionHandler(handler)
    {
        let this->exceptionHandlers[] = handler;

        return this;
    }

    /**
     * Set exception-handlers for group
     *
     * @param array handlers
     * @return static this
     */
    public function setExceptionHandlers(array handlers)
    {
        let this->exceptionHandlers = handlers;

        return this;
    }

    /**
     * Get exception-handlers for group
     *
     * @return array
     */
    public function getExceptionHandlers()
    {
        return this->exceptionHandlers;
    }

    /**
     * Get allowed domains for domain.
     *
     * @return array
     */
    public function getDomains()
    {
        return this->domains;
    }

    /**
     * Set allowed domains for group.
     *
     * @param array domains
     * @return this
     */
    public function setDomains(array domains)
    {
        let this->domains = domains;

        return this;
    }

    /**
     * @param string prefix
     * @return static
     */
    public function setPrefix(prefix)
    {
        let this->prefix = "/" . trim(prefix, "/");

        return this;
    }

    /**
     * Set prefix that child-routes will inherit.
     *
     * @return string
     */
    public function getPrefix()
    {
        return this->prefix;
    }

    /**
     * Merge with information from another route.
     *
     * @param array values
     * @param bool merge
     * @return static
     */
    public function setSettings(array values, merge = false)
    {

        if (isset(values["prefix"])) {
            this->setPrefix(values["prefix"] . this->prefix);
        }

        if (isset(values["exceptionHandler"])) {
            this->setExceptionHandlers((array)values["exceptionHandler"]);
        }

        if (isset(values["domain"])) {
            this->setDomains((array)values["domain"]);
        }

        if (isset(values["as"])) {
            if (this->name !== null && merge !== false) {
                let this->name = values["as"] . "." . this->name;
            } else {
                let this->name = values["as"];
            }
        }

        parent::setSettings(values, merge);

        return this;
    }

    /**
     * Export route settings to array so they can be merged with another route.
     *
     * @return array
     */
    public function toArray()
    {
        var values = [];

        if (this->prefix !== null) {
            let values["prefix"] = this->getPrefix();
        }

        if (this->name !== null) {
            let values["as"] = this->name;
        }

        if (count(this->parameters) > 0) {
            let values["parameters"] = this->parameters;
        }

        return array_merge(values, parent::toArray());
    }

}