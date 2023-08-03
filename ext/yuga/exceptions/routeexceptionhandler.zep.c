
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Exceptions_RouteExceptionHandler)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Exceptions, RouteExceptionHandler, yuga, exceptions_routeexceptionhandler, yuga_exceptions_routeexceptionhandler_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(yuga_exceptions_routeexceptionhandler_ce, 1, yuga_exceptions_iexception_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Exceptions_RouteExceptionHandler, handleError)
{
}

