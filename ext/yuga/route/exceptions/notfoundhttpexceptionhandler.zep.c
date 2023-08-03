
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Exceptions_NotFoundHttpExceptionHandler)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Route\\Exceptions, NotFoundHttpExceptionHandler, yuga, route_exceptions_notfoundhttpexceptionhandler, yuga_exceptions_routeexceptionhandler_ce, yuga_route_exceptions_notfoundhttpexceptionhandler_method_entry, 0);

	return SUCCESS;
}

/**
 * @param Request request
 * @param \Exception error
 * @throws \Exception
 */
PHP_METHOD(Yuga_Route_Exceptions_NotFoundHttpExceptionHandler, handleError)
{
	zval *request, request_sub, *error, error_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&error_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
		Z_PARAM_OBJECT_OF_CLASS(error, zend_ce_exception)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &request, &error);


	zephir_throw_exception_debug(error, "yuga/Route/Exceptions/NotFoundHttpExceptionHandler.zep", 27);
	return;
}

