
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Support_ILoadableRoute)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Route\\Support, ILoadableRoute, yuga, route_support_iloadableroute, yuga_route_support_iloadableroute_method_entry);

	zend_class_implements(yuga_route_support_iloadableroute_ce, 1, yuga_route_support_iroute_ce);
	return SUCCESS;
}

/**
 * Find url that matches method, parameters or name.
 * Used when calling the url() helper.
 *
 * @param string|null method
 * @param array|null parameters
 * @param string|null name
 * @return string
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_ILoadableRoute, findUrl);
/**
 * Loads and renders middlewares-classes
 *
 * @param Request request
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_ILoadableRoute, loadMiddleware);
ZEPHIR_DOC_METHOD(Yuga_Route_Support_ILoadableRoute, getUrl);
ZEPHIR_DOC_METHOD(Yuga_Route_Support_ILoadableRoute, setUrl);
/**
 * Returns the provided name for the router.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_ILoadableRoute, getName);
/**
 * Check if route has given name.
 *
 * @param string name
 * @return bool
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_ILoadableRoute, hasName);
/**
 * Sets the router name, which makes it easier to obtain the url or router at a later point.
 *
 * @param string name
 * @return static this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_ILoadableRoute, setName);
/**
 * Get regular expression match used for matching route (if defined).
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_ILoadableRoute, getMatch);
/**
 * Add regular expression match for the entire route.
 *
 * @param string regex
 * @return static
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_ILoadableRoute, setMatch);
