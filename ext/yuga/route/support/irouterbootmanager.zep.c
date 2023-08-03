
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Support_IRouterBootManager)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Route\\Support, IRouterBootManager, yuga, route_support_irouterbootmanager, yuga_route_support_irouterbootmanager_method_entry);

	return SUCCESS;
}

/**
 * Called when router loads it's routes
 *
 * @param Route router
 * @param Request request
 */
ZEPHIR_DOC_METHOD(Yuga_Route_Support_IRouterBootManager, boot);
