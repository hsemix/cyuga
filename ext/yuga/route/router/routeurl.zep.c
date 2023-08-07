
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Router_RouteUrl)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Route\\Router, RouteUrl, yuga, route_router_routeurl, yuga_route_router_loadableroute_ce, yuga_route_router_routeurl_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Yuga_Route_Router_RouteUrl, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url, &callback);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seturl", NULL, 0, url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcallback", NULL, 0, callback);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Route_Router_RouteUrl, matchRoute)
{
	zval _6;
	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url = NULL, url_sub, *request, request_sub, _0, _1, _2, _3, _4, regexMatch, parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&regexMatch);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(url)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url, &request);
	ZEPHIR_SEPARATE_PARAM(url);


	ZEPHIR_CALL_FUNCTION(&_0, "urldecode", NULL, 90, url);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 5);
	ZEPHIR_CALL_FUNCTION(url, "parse_url", NULL, 70, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/");
	zephir_fast_trim(&_2, url, &_3, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_2, "/");
	ZEPHIR_CPY_WRT(url, &_4);
	ZEPHIR_CALL_METHOD(&regexMatch, this_ptr, "matchregex", NULL, 0, request, url);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&regexMatch)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&parameters, this_ptr, "parseparameters", NULL, 0, &_1, url);
	zephir_check_call_status();
	_5 = Z_TYPE_P(&regexMatch) == IS_NULL;
	if (_5) {
		_5 = Z_TYPE_P(&parameters) == IS_NULL;
	}
	if (_5) {
		RETURN_MM_BOOL(0);
	}
	zephir_get_arrval(&_6, &parameters);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparameters", NULL, 0, &_6);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);
}

PHP_METHOD(Yuga_Route_Router_RouteUrl, getParams)
{
	zval *key = NULL, key_sub, __$null, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &key);
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	if (Z_TYPE_P(key) != IS_NULL) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_1$$3, &_0$$3, key, PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteUrl.zep", 42);
		RETURN_CTORW(&_1$$3);
	}
	RETURN_MEMBER(getThis(), "parameters");
}

