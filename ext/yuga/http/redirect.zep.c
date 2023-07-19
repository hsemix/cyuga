
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exit.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Redirect)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Http, Redirect, yuga, http_redirect, yuga_http_redirect_method_entry, 0);

	zend_declare_property_null(yuga_http_redirect_ce, SL("request"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_redirect_ce, SL("path"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Yuga_Http_Redirect, __construct)
{
	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &request);


	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
}

PHP_METHOD(Yuga_Http_Redirect, setPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);
	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
	} else {
		zephir_get_strval(&path, path_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path);
	RETURN_THIS();
}

PHP_METHOD(Yuga_Http_Redirect, getPath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "path");
}

/**
 * Set the http status code
 *
 * @param int code
 * @return static
 */
PHP_METHOD(Yuga_Http_Redirect, httpCode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(code)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);


	ZEPHIR_CALL_FUNCTION(NULL, "http_response_code", NULL, 24, code);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Redirect the response
 *
 * @param string url
 * @param int httpCode
 */
PHP_METHOD(Yuga_Http_Redirect, to)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, *httpCode = NULL, httpCode_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&httpCode_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(url)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(httpCode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url, &httpCode);
	if (!httpCode) {
		httpCode = &httpCode_sub;
		httpCode = &__$null;
	}


	if (Z_TYPE_P(httpCode) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "httpcode", NULL, 0, httpCode);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isvaliduri", NULL, 0, url);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "httpurl", NULL, 0, url);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpath", NULL, 0, url);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(Yuga_Http_Redirect, header)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);


	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 25, value);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(Yuga_Http_Redirect, refresh)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Refresh:0");
	ZEPHIR_RETURN_CALL_FUNCTION("header", NULL, 25, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Redirect, back)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP/1.1 301 Moved Permanently");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getreferer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "to", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Http_Redirect, route)
{
	zval *name = NULL, name_sub, *parameters = NULL, parameters_sub, *getParams = NULL, getParams_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&getParams_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(parameters)
		Z_PARAM_ZVAL_OR_NULL(getParams)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 3, &name, &parameters, &getParams);
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!getParams) {
		getParams = &getParams_sub;
		getParams = &__$null;
	}


	zephir_exit_empty();
}

PHP_METHOD(Yuga_Http_Redirect, isValidUri)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *uri, uri_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(uri)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, uri, 0 , 4 , 0);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_2, "http"));
}

PHP_METHOD(Yuga_Http_Redirect, cleanUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri, uri_sub, url, http, firstSection, secondSection, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&http);
	ZVAL_UNDEF(&firstSection);
	ZVAL_UNDEF(&secondSection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(uri)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);


	ZEPHIR_INIT_VAR(&firstSection);
	zephir_fast_explode_str(&firstSection, SL("://"), uri, LONG_MAX);
	ZEPHIR_OBS_VAR(&http);
	zephir_array_fetch_long(&http, &firstSection, 0, PH_NOISY, "yuga/Http/Redirect.zep", 102);
	zephir_array_fetch_long(&_0, &firstSection, 1, PH_NOISY | PH_READONLY, "yuga/Http/Redirect.zep", 103);
	ZEPHIR_INIT_VAR(&secondSection);
	zephir_fast_explode_str(&secondSection, SL("/"), &_0, LONG_MAX);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, yuga_1__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&url, "array_map", NULL, 26, &_1, &secondSection);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_join_str(&_2, SL("/"), &url);
	ZEPHIR_CONCAT_VSV(return_value, &http, "://", &_2);
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Redirect, httpUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *url_param = NULL, cleanUrl, _0, _2;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&cleanUrl);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(url)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);
	zephir_get_strval(&url, url_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP/1.1 301 Moved Permanently");
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 25, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&cleanUrl, this_ptr, "cleanurl", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "Location: ", &cleanUrl);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 25, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Http_Redirect, with)
{
	zval *key = NULL, key_sub, *value = NULL, value_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(key)
		Z_PARAM_ZVAL_OR_NULL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 2, &key, &value);
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	RETURN_THISW();
}

PHP_METHOD(Yuga_Http_Redirect, __call)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, *parameters, parameters_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method, &parameters);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	zephir_array_fast_append(&_0, method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

