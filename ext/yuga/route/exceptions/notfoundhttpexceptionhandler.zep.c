
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


ZEPHIR_INIT_CLASS(Yuga_Route_Exceptions_NotFoundHttpExceptionHandler)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Route\\Exceptions, NotFoundHttpExceptionHandler, yuga, route_exceptions_notfoundhttpexceptionhandler, yuga_exceptions_routeexceptionhandler_ce, NULL, 0);

	return SUCCESS;
}

