
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Yuga_Support_Helpers)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Support, Helpers, yuga, support_helpers, yuga_support_helpers_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Yuga_Support_Helpers, view)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *template = NULL, template_sub, *data = NULL, data_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(template)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &template, &data);
	if (!template) {
		template = &template_sub;
		template = &__$null;
	}
	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	}


}

PHP_METHOD(Yuga_Support_Helpers, path)
{
	zval *file = NULL, file_sub, _ENV, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&_ENV);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(file)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_get_global(&_ENV, SL("_ENV"));
	zephir_fetch_params_without_memory_grow(0, 1, &file);
	if (!file) {
		file = &file_sub;
		file = &__$null;
	}


	zephir_array_fetch_string(&_0, &_ENV, SL("base_path"), PH_NOISY | PH_READONLY, "yuga/Support/Helpers.zep", 12);
	ZEPHIR_CONCAT_VSV(return_value, &_0, "/", file);
	return;
}

PHP_METHOD(Yuga_Support_Helpers, storage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, path_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path);
	if (!path) {
		path = &path_sub;
		path = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SSV(&_0, "storage", "/", path);
	ZEPHIR_RETURN_CALL_SELF("path", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Support_Helpers, env)
{
	zend_bool _1$$3;
	zval *key, key_sub, *defaultValue = NULL, defaultValue_sub, _ENV, __$null, _0$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_ENV);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_get_global(&_ENV, SL("_ENV"));
	zephir_fetch_params_without_memory_grow(1, 1, &key, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	if (zephir_array_isset(&_ENV, key)) {
		zephir_array_fetch(&_0$$3, &_ENV, key, PH_NOISY | PH_READONLY, "yuga/Support/Helpers.zep", 24);
		_1$$3 = ZEPHIR_IS_STRING(&_0$$3, "");
		if (!(_1$$3)) {
			zephir_array_fetch(&_2$$3, &_ENV, key, PH_NOISY | PH_READONLY, "yuga/Support/Helpers.zep", 24);
			_1$$3 = Z_TYPE_P(&_2$$3) == IS_NULL;
		}
		if (_1$$3) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			return;
		}
		zephir_array_fetch(&_3$$3, &_ENV, key, PH_NOISY | PH_READONLY, "yuga/Support/Helpers.zep", 28);
		RETURN_CTORW(&_3$$3);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;
}

PHP_METHOD(Yuga_Support_Helpers, app)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *param = NULL, param_sub, __$null, _0$$4, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(param)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &param);
	if (!param) {
		param = &param_sub;
		param = &__$null;
	}


	if (zephir_is_true(param)) {
		if (zephir_class_exists(param, 1)) {
			ZEPHIR_CALL_CE_STATIC(&_0$$4, yuga_application_application_ce, "getinstance", &_1, 0);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_METHOD(&_0$$4, "resolve", NULL, 0, param);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_CE_STATIC(&_2$$3, yuga_application_application_ce, "getinstance", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_2$$3, "make", NULL, 0, param);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_CE_STATIC(yuga_application_application_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Support_Helpers, event)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName = NULL, eventName_sub, *params = NULL, params_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_sub);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(eventName)
		Z_PARAM_ZVAL(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &eventName, &params);
	if (!eventName) {
		eventName = &eventName_sub;
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_STRING(eventName, "yuga.auto.events");
	}
	if (!params) {
		params = &params_sub;
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}


	ZEPHIR_CALL_SELF(&_0, "app", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "events");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "trigger", NULL, 0, eventName, params);
	zephir_check_call_status();
	RETURN_MM();
}

