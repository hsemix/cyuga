
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Router_TestRoute)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Route\\Router, TestRoute, yuga, route_router_testroute, NULL, 0);

	return SUCCESS;
}

