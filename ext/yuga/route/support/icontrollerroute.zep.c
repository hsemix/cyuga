
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Support_IControllerRoute)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Route\\Support, IControllerRoute, yuga, route_support_icontrollerroute, yuga_route_support_icontrollerroute_method_entry);

	zend_class_implements(yuga_route_support_icontrollerroute_ce, 1, yuga_route_support_iroute_ce);
	return SUCCESS;
}

/**
 * Get controller class-name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IControllerRoute, getController);
/**
 * Set controller class-name
 *
 * @param string controller
 * @return static
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IControllerRoute, setController);
/**
 * Return active method
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IControllerRoute, getMethod);
/**
 * Set active method
 *
 * @param string method
 * @return static
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IControllerRoute, setMethod);
