
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Request)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Http, Request, yuga, http_request, yuga_http_request_method_entry, 0);

	zend_declare_property_null(yuga_http_request_ce, SL("data"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("headers"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("host"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("uri"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("method"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("input"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("app"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("rewriteRoute"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("rewriteUrl"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("loadedRoute"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("formFields"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_request_ce, SL("model"), ZEND_ACC_PROTECTED);
	yuga_http_request_ce->create_object = zephir_init_properties_Yuga_Http_Request;

	return SUCCESS;
}

PHP_METHOD(Yuga_Http_Request, __construct)
{
	zval _11;
	zval _0, _1, _3, _4, _5, _6, _7, _8, _9, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "http-host");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheader", &_2, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("host"), &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request-uri");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getheader", &_2, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uri"), &_3);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, yuga_http_input_input_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 52, this_ptr);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("input"), &_1);
	ZEPHIR_INIT_VAR(&_4);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("input"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "request-method");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getheader", &_2, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "_method");
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "post");
	ZEPHIR_CALL_METHOD(&_6, &_5, "get", NULL, 0, &_8, &_7, &_9);
	zephir_check_call_status();
	zephir_fast_strtolower(&_4, &_6);
	zephir_update_property_zval(this_ptr, ZEND_STRL("method"), &_4);
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 1, 0);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "_token");
	zephir_array_fast_append(&_11, &_8);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "except", NULL, 0, &_11);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_10);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Http_Request, parseHeaders)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, name, value, _0, *_1, _2, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &_0);
	zephir_is_iterable(&_SERVER, 0, "yuga/Http/Request.zep", 49);
	if (Z_TYPE_P(&_SERVER) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SERVER), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_fast_strtolower(&_5$$3, &name);
			zephir_update_property_array(this_ptr, SL("headers"), &_5$$3, &value);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "_");
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "-");
			zephir_fast_str_replace(&_7$$3, &_8$$3, &_9$$3, &name);
			zephir_fast_strtolower(&_6$$3, &_7$$3);
			zephir_update_property_array(this_ptr, SL("headers"), &_6$$3, &value);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_SERVER, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_SERVER, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &_SERVER, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_SERVER, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_fast_strtolower(&_10$$4, &name);
				zephir_update_property_array(this_ptr, SL("headers"), &_10$$4, &value);
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZEPHIR_INIT_NVAR(&_13$$4);
				ZVAL_STRING(&_13$$4, "_");
				ZEPHIR_INIT_NVAR(&_14$$4);
				ZVAL_STRING(&_14$$4, "-");
				zephir_fast_str_replace(&_12$$4, &_13$$4, &_14$$4, &name);
				zephir_fast_strtolower(&_11$$4, &_12$$4);
				zephir_update_property_array(this_ptr, SL("headers"), &_11$$4, &value);
			ZEPHIR_CALL_METHOD(NULL, &_SERVER, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();
}

/**
 * Get all headers
 * @return array
 */
PHP_METHOD(Yuga_Http_Request, getHeaders)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "headers");
}

/**
 * Get header value by name
 *
 * @param string name
 * @param string|null defaultValue
 *
 * @return string|null
 */
PHP_METHOD(Yuga_Http_Request, getHeader)
{
	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaultValue_param = NULL, _SERVER, headerName, headerValue, _0, _1, *_5, _6, _2$$3, _3$$3, _4$$3;
	zval name, defaultValue;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&headerName);
	ZVAL_UNDEF(&headerValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue_param);
	zephir_get_strval(&name, name_param);
	if (!defaultValue_param) {
		ZEPHIR_INIT_VAR(&defaultValue);
	} else {
		zephir_get_strval(&defaultValue, defaultValue_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &name);
	if (zephir_array_isset(&_0, &_1)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fast_strtolower(&_4$$3, &name);
		zephir_array_fetch(&_3$$3, &_2$$3, &_4$$3, PH_NOISY | PH_READONLY, "yuga/Http/Request.zep", 72);
		RETURN_CTOR(&_3$$3);
	}
	zephir_is_iterable(&_SERVER, 0, "yuga/Http/Request.zep", 81);
	if (Z_TYPE_P(&_SERVER) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SERVER), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&headerName);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&headerName, _8);
			} else {
				ZVAL_LONG(&headerName, _7);
			}
			ZEPHIR_INIT_NVAR(&headerValue);
			ZVAL_COPY(&headerValue, _5);
			if (ZEPHIR_IS_IDENTICAL(&headerName, &name)) {
				RETURN_CCTOR(&headerValue);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_SERVER, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &_SERVER, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&headerName, &_SERVER, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&headerValue, &_SERVER, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&headerName, &name)) {
					RETURN_CCTOR(&headerValue);
				}
			ZEPHIR_CALL_METHOD(NULL, &_SERVER, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&headerValue);
	ZEPHIR_INIT_NVAR(&headerName);
	RETURN_CTOR(&defaultValue);
}

PHP_METHOD(Yuga_Http_Request, getBearerToken)
{
	zval authorize, matches, _0, _1, _2, _6, _3$$3, _4$$3, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&authorize);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "http-authorization");
	ZEPHIR_CALL_METHOD(&authorize, this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "#Bearer\\s(\\S+)#");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "#Bearer\\s(\\S+)#");
	zephir_preg_match(&_1, &_2, &authorize, &matches, 0, 0 , 0 );
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, zend_ce_exception);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Access Token Not Found");
		ZVAL_LONG(&_5$$3, 401);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 2, &_4$$3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "yuga/Http/Request.zep", 93);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_long(&_6, &matches, 1, PH_NOISY | PH_READONLY, "yuga/Http/Request.zep", 96);
	RETURN_CTOR(&_6);
}

PHP_METHOD(Yuga_Http_Request, getInput)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "input");
}

/**
 * Is format accepted
 *
 * @param string format
 *
 * @return bool
 */
PHP_METHOD(Yuga_Http_Request, isFormatAccepted)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *format, format_sub, _0, _1, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(format)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &format);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "http-accept");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheader", &_2, 0, &_1);
	zephir_check_call_status();
	_3 = Z_TYPE_P(&_0) != IS_NULL;
	if (_3) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "http-accept");
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "getheader", &_2, 0, &_1);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_5, "stripos", NULL, 53, &_4, format);
		zephir_check_call_status();
		_3 = ZEPHIR_GT_LONG(&_5, -1);
	}
	RETURN_MM_BOOL(_3);
}

/**
 * Get accept formats
 * @return array
 */
PHP_METHOD(Yuga_Http_Request, getAcceptFormats)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "http-accept");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheader", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ",");
	zephir_fast_explode(return_value, &_1, &_0, LONG_MAX);
	RETURN_MM();
}

/**
 * @param string uri
 */
PHP_METHOD(Yuga_Http_Request, setUri)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *uri_param = NULL;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);
	zephir_get_strval(&uri, uri_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("uri"), &uri);
	RETURN_THIS();
}

/**
 * @param string host
 */
PHP_METHOD(Yuga_Http_Request, setHost)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *host_param = NULL;
	zval host;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(host)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host_param);
	zephir_get_strval(&host, host_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("host"), &host);
	RETURN_THIS();
}

/**
 * @param string method
 */
PHP_METHOD(Yuga_Http_Request, setMethod)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *method_param = NULL;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);
	zephir_get_strval(&method, method_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("method"), &method);
	RETURN_THIS();
}

/**
 * Get rewrite route
 *
 * @return ILoadableRoute|null
 */
PHP_METHOD(Yuga_Http_Request, getRewriteRoute)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "rewriteRoute");
}

/**
 * Set rewrite url
 *
 * @param string rewriteUrl
 * @return static
 */
PHP_METHOD(Yuga_Http_Request, setRewriteUrl)
{
	zval *rewriteUrl, rewriteUrl_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rewriteUrl_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(rewriteUrl)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &rewriteUrl);


	zephir_update_property_zval(this_ptr, ZEND_STRL("rewriteUrl"), rewriteUrl);
	RETURN_THISW();
}

/**
 * Get loaded route
 * @return ILoadableRoute|null
 */
PHP_METHOD(Yuga_Http_Request, getLoadedRoute)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "loadedRoute");
}

/**
 * Set loaded route
 *
 * @param ILoadableRoute route
 * @return static
 */
PHP_METHOD(Yuga_Http_Request, setLoadedRoute)
{
	zval *route, route_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(route)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &route);


	zephir_update_property_zval(this_ptr, ZEND_STRL("loadedRoute"), route);
	RETURN_THISW();
}

PHP_METHOD(Yuga_Http_Request, __isset)
{
	zval *name, name_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &name);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, name));
}

PHP_METHOD(Yuga_Http_Request, __set)
{
	zval *name, name_sub, *value = NULL, value_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 1, &name, &value);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	zephir_update_property_array(this_ptr, SL("data"), name, value);
}

PHP_METHOD(Yuga_Http_Request, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name, name_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, name)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, name, PH_NOISY, "yuga/Http/Request.zep", 210);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Yuga_Http_Request, isAjax)
{
	zend_bool _3, _6, _8;
	zval _0, _1, _4, _5, _7, _9, _10, _11, _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "http-x-requested-with");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheader", &_2, 0, &_1);
	zephir_check_call_status();
	_3 = Z_TYPE_P(&_0) != IS_NULL;
	if (_3) {
		ZEPHIR_INIT_NVAR(&_1);
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "http-x-requested-with");
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "getheader", &_2, 0, &_5);
		zephir_check_call_status();
		zephir_fast_strtolower(&_1, &_4);
		_3 = ZEPHIR_IS_STRING_IDENTICAL(&_1, "xmlhttprequest");
	}
	_6 = _3;
	if (!(_6)) {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_STRING(&_5, "http-user-agent");
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "getheader", &_2, 0, &_5);
		zephir_check_call_status();
		_8 = Z_TYPE_P(&_7) != IS_NULL;
		if (_8) {
			ZEPHIR_INIT_VAR(&_9);
			ZEPHIR_INIT_NVAR(&_5);
			ZVAL_STRING(&_5, "http-user-agent");
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "getheader", &_2, 0, &_5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_5);
			ZVAL_STRING(&_5, "/^(curl|wget)/i");
			ZEPHIR_INIT_VAR(&_11);
			ZEPHIR_INIT_VAR(&_12);
			ZVAL_STRING(&_12, "/^(curl|wget)/i");
			zephir_preg_match(&_11, &_12, &_10, &_9, 0, 0 , 0 );
			_8 = zephir_is_true(&_11);
		}
		_6 = _8;
	}
	if (_6) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Yuga_Http_Request, model)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "model");
}

PHP_METHOD(Yuga_Http_Request, setModel)
{
	zval *model, model_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(model)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &model);


	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), model);
	RETURN_THISW();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Http_Request, getMethod)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "method");
}

PHP_METHOD(Yuga_Http_Request, create)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	object_init_ex(return_value, yuga_http_request_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 10);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Request, isSecure)
{
	zend_bool _3, _5;
	zval _0, _1, _4, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "http-x-forwarded-proto");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheader", &_2, 0, &_1);
	zephir_check_call_status();
	_3 = ZEPHIR_IS_STRING_IDENTICAL(&_0, "https");
	if (!(_3)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "https");
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "getheader", &_2, 0, &_1);
		zephir_check_call_status();
		_3 = Z_TYPE_P(&_4) != IS_NULL;
	}
	_5 = _3;
	if (!(_5)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "server-port");
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "getheader", &_2, 0, &_1);
		zephir_check_call_status();
		_5 = ZEPHIR_IS_LONG_IDENTICAL(&_6, 443);
	}
	RETURN_MM_BOOL(_5);
}

PHP_METHOD(Yuga_Http_Request, getPort)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "server-port");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Http_Request, getUri)
{
	zval *trim = NULL, trim_sub, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&trim_sub);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(trim)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &trim);
	if (!trim) {
		trim = &trim_sub;
		trim = &__$false;
	}


	if (zephir_is_true(trim)) {
		RETURN_MEMBER(getThis(), "uri");
	}
}

PHP_METHOD(Yuga_Http_Request, formatUrl)
{
	zval *url, url_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(url)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &url);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
	zend_print_zval(&_0, 0);
	zephir_exit_empty();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Http_Request, getHost)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "host");
}

PHP_METHOD(Yuga_Http_Request, getServer)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "server-name");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get http basic auth user
 * @return string|null
 */
PHP_METHOD(Yuga_Http_Request, getUser)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php-auth-user");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get http basic auth password
 * @return string|null
 */
PHP_METHOD(Yuga_Http_Request, getPassword)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php-auth-pw");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get id address
 * @return string
 */
PHP_METHOD(Yuga_Http_Request, getIp)
{
	zval _0, _1, _4, _3$$3, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "http-cf-connecting-ip");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheader", &_2, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "http-cf-connecting-ip");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", &_2, 0, &_3$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "http-x-forwarded-for");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getheader", &_2, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&_4) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "http-x-forwarded-for");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", &_2, 0, &_5$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "remote-addr");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", &_2, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get remote address/ip
 *
 * @alias static::getIp
 * @return string
 */
PHP_METHOD(Yuga_Http_Request, getRemoteAddr)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getip", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get referer
 * @return string
 */
PHP_METHOD(Yuga_Http_Request, getReferer)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "http-referer");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get user agent
 * @return string
 */
PHP_METHOD(Yuga_Http_Request, getUserAgent)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "http-user-agent");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Request, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, _0;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value_param, &defaultValue);
	zephir_get_strval(&value, value_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinput", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &value, defaultValue);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Request, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, index_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &index);
	if (!index) {
		index = &index_sub;
		index = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinput", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "exists", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Request, files)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *defaultValue = NULL, defaultValue_sub, __$null, files, _0, _1, _2, _3, _4$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(key)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key, &defaultValue);
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinput", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&files, &_0, "findfile", NULL, 0, key, defaultValue);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getinput", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "findfile", NULL, 0, key, defaultValue);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &_2, "haserror", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "getinput", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_4$$3, "findfile", NULL, 0, key, defaultValue);
		zephir_check_call_status();
		RETURN_MM();
	} else if (!(zephir_is_true(&_3))) {
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getinput", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_5$$4, "findfile", NULL, 0, key, defaultValue);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Yuga_Http_Request, hasFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinput", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "hasfile", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Request, all)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter_param = NULL, _0;
	zval filter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(filter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filter_param);
	if (!filter_param) {
		ZEPHIR_INIT_VAR(&filter);
	} else {
		zephir_get_arrval(&filter, filter_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinput", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "all", NULL, 0, &filter);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Request, only)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *onlyFields_param = NULL, only, field, value, _0, *_1, _2;
	zval onlyFields;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&onlyFields);
	ZVAL_UNDEF(&only);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(onlyFields)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &onlyFields_param);
	if (!onlyFields_param) {
		ZEPHIR_INIT_VAR(&onlyFields);
		array_init(&onlyFields);
	} else {
		zephir_get_arrval(&onlyFields, onlyFields_param);
	}


	ZEPHIR_INIT_VAR(&only);
	array_init(&only);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "yuga/Http/Request.zep", 415);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&field, _4);
			} else {
				ZVAL_LONG(&field, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (zephir_fast_in_array(&field, &onlyFields)) {
				zephir_array_update_zval(&only, &field, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_fast_in_array(&field, &onlyFields)) {
					zephir_array_update_zval(&only, &field, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&field);
	RETURN_CCTOR(&only);
}

PHP_METHOD(Yuga_Http_Request, except)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exceptFields_param = NULL, only, field, value, _0, *_1, _2;
	zval exceptFields;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exceptFields);
	ZVAL_UNDEF(&only);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(exceptFields)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &exceptFields_param);
	if (!exceptFields_param) {
		ZEPHIR_INIT_VAR(&exceptFields);
		array_init(&exceptFields);
	} else {
		zephir_get_arrval(&exceptFields, exceptFields_param);
	}


	ZEPHIR_INIT_VAR(&only);
	array_init(&only);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "yuga/Http/Request.zep", 429);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&field, _4);
			} else {
				ZVAL_LONG(&field, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (!(zephir_fast_in_array(&field, &exceptFields))) {
				zephir_array_update_zval(&only, &field, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_fast_in_array(&field, &exceptFields))) {
					zephir_array_update_zval(&only, &field, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&field);
	RETURN_CCTOR(&only);
}

zend_object *zephir_init_properties_Yuga_Http_Request(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("formFields"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("formFields"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

