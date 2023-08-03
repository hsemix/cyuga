
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Support_IRoute)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Route\\Support, IRoute, yuga, route_support_iroute, yuga_route_support_iroute_method_entry);

	return SUCCESS;
}

/**
 * Method called to check if a domain matches
 *
 * @param string route
 * @param Request request
 * @return bool
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, matchRoute);
/**
 * Called when route is matched.
 * Returns class to be rendered.
 *
 * @param Request request
 * @throws \Pecee\SimpleRouter\Exceptions\NotFoundHttpException
 * @return void
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, renderRoute);
/**
 * Returns callback name/identifier for the current route based on the callback.
 * Useful if you need to get a unique identifier for the loaded route, for instance
 * when using translations etc.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getIdentifier);
/**
 * Set allowed request methods
 *
 * @param array methods
 * @return static this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setRequestMethods);
/**
 * Get allowed request methods
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getRequestMethods);
/**
 * @return IRoute|null
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getParent);
/**
 * Get the group for the route.
 *
 * @return IGroupRoute|null
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getGroup);
/**
 * Set group
 *
 * @param IGroupRoute group
 * @return static this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setGroup);
/**
 * Set parent route
 *
 * @param IRoute parent
 * @return static this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setParent);
/**
 * Set callback
 *
 * @param string callback
 * @return static
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setCallback);
/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getCallback);
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getMethod);
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getClass);
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setMethod);
/**
 * @param string namespaceValue
 * @return static this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setNamespace);
/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getNamespace);
/**
 * @param string namespaceValue
 * @return static this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setDefaultNamespace);
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getDefaultNamespace);
/**
 * Get parameter names.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getWhere);
/**
 * Set parameter names.
 *
 * @param array options
 * @return static
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setWhere);
/**
 * Get parameters
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getParameters);
/**
 * Get parameters
 *
 * @param array parameters
 * @return static this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setParameters);
/**
 * Merge with information from another route.
 *
 * @param array settings
 * @param bool merge
 * @return static this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setSettings);
/**
 * Export route settings to array so they can be merged with another route.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, toArray);
/**
 * Get middlewares array
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, getMiddlewares);
/**
 * Set middleware class-name
 *
 * @param string middleware
 * @return static
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, addMiddleware);
/**
 * Set middlewares array
 *
 * @param array middlewares
 * @return this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRoute, setMiddlewares);
