
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Support_IGroupRoute)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Route\\Support, IGroupRoute, yuga, route_support_igrouproute, yuga_route_support_igrouproute_method_entry);

	zend_class_implements(yuga_route_support_igrouproute_ce, 1, yuga_route_support_iroute_ce);
	return SUCCESS;
}

/**
 * Method called to check if a domain matches
 *
 * @param Request request
 * @return bool
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IGroupRoute, matchDomain);
/**
 * Add exception handler
 *
 * @param IExceptionHandler|string handler
 * @return static this;
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IGroupRoute, addExceptionHandler);
/**
 * Set exception-handlers for group
 *
 * @param array handlers
 * @return static this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IGroupRoute, setExceptionHandlers);
/**
 * Get exception-handlers for group
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IGroupRoute, getExceptionHandlers);
/**
 * Get domains for domain.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IGroupRoute, getDomains);
/**
 * Set allowed domains for group.
 *
 * @param array domains
 * @return this
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IGroupRoute, setDomains);
/**
 * Set prefix that child-routes will inherit.
 *
 * @param string prefix
 * @return string
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IGroupRoute, setPrefix);
/**
 * Get prefix.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IGroupRoute, getPrefix);
