
extern zend_class_entry *yuga_http_response_ce;

ZEPHIR_INIT_CLASS(Yuga_Http_Response);

PHP_METHOD(Yuga_Http_Response, __construct);
PHP_METHOD(Yuga_Http_Response, httpCode);
PHP_METHOD(Yuga_Http_Response, redirect);
PHP_METHOD(Yuga_Http_Response, redirectResponse);
PHP_METHOD(Yuga_Http_Response, viewResponse);
PHP_METHOD(Yuga_Http_Response, jsonResponse);
PHP_METHOD(Yuga_Http_Response, refresh);
PHP_METHOD(Yuga_Http_Response, auth);
PHP_METHOD(Yuga_Http_Response, cache);
PHP_METHOD(Yuga_Http_Response, json);
PHP_METHOD(Yuga_Http_Response, header);
PHP_METHOD(Yuga_Http_Response, headers);
PHP_METHOD(Yuga_Http_Response, getOrSetVars);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, redirect, Yuga\\Http\\Redirect, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_httpcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_redirect, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, httpCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_redirectresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, httpCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_viewresponse, 0, 0, 0)
	ZEND_ARG_INFO(0, args)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_jsonresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, options)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, dept)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_refresh, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_auth, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, eTag)
	ZEND_ARG_INFO(0, lastModified)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_json, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, options)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, dept)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_header, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_headers, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_response_getorsetvars, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_http_response_method_entry) {
	PHP_ME(Yuga_Http_Response, __construct, arginfo_yuga_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yuga_Http_Response, httpCode, arginfo_yuga_http_response_httpcode, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Response, redirect, arginfo_yuga_http_response_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Response, redirectResponse, arginfo_yuga_http_response_redirectresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Response, viewResponse, arginfo_yuga_http_response_viewresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Response, jsonResponse, arginfo_yuga_http_response_jsonresponse, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Response, refresh, arginfo_yuga_http_response_refresh, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Response, refresh, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Response, auth, arginfo_yuga_http_response_auth, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Response, cache, arginfo_yuga_http_response_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Response, json, arginfo_yuga_http_response_json, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Response, header, arginfo_yuga_http_response_header, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Response, headers, arginfo_yuga_http_response_headers, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Response, getOrSetVars, arginfo_yuga_http_response_getorsetvars, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Response, getOrSetVars, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
