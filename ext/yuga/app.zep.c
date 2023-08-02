
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Yuga_App)
{
	ZEPHIR_REGISTER_CLASS(Yuga, App, yuga, app, yuga_app_method_entry, 0);

	return SUCCESS;
}

/**
 * Call all non static methods in \Yuga\Application\Application statically as if they were defined as static
 */
PHP_METHOD(Yuga_App, __callStatic)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, *args, args_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&args_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(args)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method, &args);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_CALL_CE_STATIC(&_1, yuga_application_application_ce, "getinstance", &_2, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, args);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Interface all methods of \Yuga\Application\Application to be called by this class
 */
PHP_METHOD(Yuga_App, __call)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, *args, args_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&args_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(args)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method, &args);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_CALL_CE_STATIC(&_1, yuga_application_application_ce, "getinstance", &_2, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, args);
	zephir_check_call_status();
	RETURN_MM();
}

