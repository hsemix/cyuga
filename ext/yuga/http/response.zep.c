
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exit.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Response)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Http, Response, yuga, http_response, yuga_http_response_method_entry, 0);

	zend_declare_property_null(yuga_http_response_ce, SL("request"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_response_ce, SL("redirect"), ZEND_ACC_PUBLIC);
	return SUCCESS;
}

PHP_METHOD(Yuga_Http_Response, __construct)
{
	zval *request, request_sub, *redirect, redirect_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&redirect_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
		Z_PARAM_OBJECT_OF_CLASS(redirect, zephir_get_internal_ce(SL("yuga\\http\\redirect")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &request, &redirect);


	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	zephir_update_property_zval(this_ptr, ZEND_STRL("redirect"), redirect);
}

/**
 * Set the http status code
 *
 * @param int code
 * @return static
 */
PHP_METHOD(Yuga_Http_Response, httpCode)
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


	ZEPHIR_CALL_FUNCTION(NULL, "http_response_code", NULL, 31, code);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Redirect the response
 *
 * @param string url
 * @param int httpCode
 */
PHP_METHOD(Yuga_Http_Response, redirect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url = NULL, url_sub, *httpCode = NULL, httpCode_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&httpCode_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(url)
		Z_PARAM_ZVAL_OR_NULL(httpCode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &url, &httpCode);
	if (!url) {
		url = &url_sub;
		url = &__$null;
	}
	if (!httpCode) {
		httpCode = &httpCode_sub;
		httpCode = &__$null;
	}


	if (Z_TYPE_P(httpCode) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "httpcode", NULL, 0, httpCode);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("redirect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "to", NULL, 0, url);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Response, redirectResponse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, *httpCode = NULL, httpCode_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&httpCode_sub);
	ZVAL_NULL(&__$null);
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "redirect", NULL, 0, url, httpCode);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Response, viewResponse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL, args_sub, *data = NULL, data_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&args_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(args)
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &args, &data);
	if (!args) {
		args = &args_sub;
		args = &__$null;
	}
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	ZEPHIR_RETURN_CALL_FUNCTION("view", NULL, 0, args, data);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Response, jsonResponse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *options = NULL, options_sub, *code = NULL, code_sub, *dept = NULL, dept_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&dept_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(options)
		Z_PARAM_ZVAL(code)
		Z_PARAM_ZVAL(dept)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &value, &options, &code, &dept);
	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		ZVAL_LONG(options, 0);
	}
	if (!code) {
		code = &code_sub;
		ZEPHIR_INIT_VAR(code);
		ZVAL_LONG(code, 200);
	}
	if (!dept) {
		dept = &dept_sub;
		ZEPHIR_INIT_VAR(dept);
		ZVAL_LONG(dept, 512);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "json", NULL, 0, value, options, code, dept);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Response, refresh)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "redirectresponse", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Add http authorisation
 * @param string name
 * @return static
 */
PHP_METHOD(Yuga_Http_Response, auth)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);
	if (!name) {
		name = &name_sub;
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "WWW-Authenticate: Basic realm=\"", name, "\"");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "HTTP/1.0 401 Unauthorized");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "headers", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(Yuga_Http_Response, cache)
{
	zend_bool _6, _7, _8;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eTag, eTag_sub, *lastModified = NULL, lastModified_sub, httpModified, httpIfNoneMatch, _1, _2, _3, _4, _5, _9, _10$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eTag_sub);
	ZVAL_UNDEF(&lastModified_sub);
	ZVAL_UNDEF(&httpModified);
	ZVAL_UNDEF(&httpIfNoneMatch);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(eTag)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(lastModified)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &eTag, &lastModified);
	if (!lastModified) {
		lastModified = &lastModified_sub;
		ZEPHIR_INIT_VAR(lastModified);
		ZVAL_LONG(lastModified, 2592000);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Cache-Control: public");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "D, d M Y H:i:s");
	ZEPHIR_CALL_FUNCTION(&_2, "gmdate", NULL, 36, &_1, lastModified);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVS(&_3, "Last-Modified: ", &_2, " GMT");
	zephir_array_fast_append(&_0, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "Etag: ", eTag);
	zephir_array_fast_append(&_0, &_3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "headers", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "http-if-modified-since");
	ZEPHIR_CALL_METHOD(&httpModified, &_4, "getheader", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "http-if-none-match");
	ZEPHIR_CALL_METHOD(&httpIfNoneMatch, &_5, "getheader", NULL, 0, &_1);
	zephir_check_call_status();
	_6 = Z_TYPE_P(&httpIfNoneMatch) != IS_NULL;
	if (_6) {
		_6 = ZEPHIR_IS_IDENTICAL(&httpIfNoneMatch, eTag);
	}
	_7 = _6;
	if (!(_7)) {
		_8 = Z_TYPE_P(&httpModified) != IS_NULL;
		if (_8) {
			ZEPHIR_CALL_FUNCTION(&_9, "strtotime", NULL, 37, &httpModified);
			zephir_check_call_status();
			_8 = ZEPHIR_IS_IDENTICAL(&_9, lastModified);
		}
		_7 = _8;
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "HTTP/1.1 304 Not Modified");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", NULL, 0, &_10$$3);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	RETURN_THIS();
}

/**
 * Json encode array
 * @param array value
 */
PHP_METHOD(Yuga_Http_Response, json)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *options = NULL, options_sub, *code = NULL, code_sub, *dept = NULL, dept_sub, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&dept_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(options)
		Z_PARAM_ZVAL(code)
		Z_PARAM_ZVAL(dept)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &value, &options, &code, &dept);
	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		ZVAL_LONG(options, 0);
	}
	if (!code) {
		code = &code_sub;
		ZEPHIR_INIT_VAR(code);
		ZVAL_LONG(code, 200);
	}
	if (!dept) {
		dept = &dept_sub;
		ZEPHIR_INIT_VAR(dept);
		ZVAL_LONG(dept, 512);
	}


	_0 = (zephir_is_instance_of(value, SL("JsonSerializable"))) == 0;
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "\is_array", NULL, 38, value);
		zephir_check_call_status();
		_0 = ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid type for parameter \"value\". Must be of type array or object implementing the \\JsonSerializable interface.", "yuga/Http/Response.zep", 107);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "httpcode", NULL, 0, code);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Content-Type: application/json; charset=utf-8");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	zephir_json_encode(&_2, value, zephir_get_intval(options) );
	zend_print_zval(&_2, 0);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_MM_RESTORE();
	zephir_exit(&_3);
	ZEPHIR_MM_RESTORE();
}

/**
 * Add header to response
 * @param string value
 * @return static
 */
PHP_METHOD(Yuga_Http_Response, header)
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


	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 32, value);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Add multiple headers to response
 * @param array headers
 * @return static
 */
PHP_METHOD(Yuga_Http_Response, headers)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, header, *_0, _1;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(headers)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);
	zephir_get_arrval(&headers, headers_param);


	zephir_is_iterable(&headers, 0, "yuga/Http/Response.zep", 139);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&headers), _0)
		{
			ZEPHIR_INIT_NVAR(&header);
			ZVAL_COPY(&header, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", &_2, 0, &header);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&header, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", &_2, 0, &header);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&header);
	RETURN_THIS();
}

PHP_METHOD(Yuga_Http_Response, getOrSetVars)
{
	zval *this_ptr = getThis();



}

