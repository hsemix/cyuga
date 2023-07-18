
extern zend_class_entry *yuga_http_redirect_ce;

ZEPHIR_INIT_CLASS(Yuga_Http_Redirect);

PHP_METHOD(Yuga_Http_Redirect, __construct);
PHP_METHOD(Yuga_Http_Redirect, setPath);
PHP_METHOD(Yuga_Http_Redirect, getPath);
PHP_METHOD(Yuga_Http_Redirect, httpCode);
PHP_METHOD(Yuga_Http_Redirect, to);
PHP_METHOD(Yuga_Http_Redirect, header);
PHP_METHOD(Yuga_Http_Redirect, refresh);
PHP_METHOD(Yuga_Http_Redirect, back);
PHP_METHOD(Yuga_Http_Redirect, route);
PHP_METHOD(Yuga_Http_Redirect, isValidUri);
PHP_METHOD(Yuga_Http_Redirect, cleanUrl);
PHP_METHOD(Yuga_Http_Redirect, httpUrl);
PHP_METHOD(Yuga_Http_Redirect, with);
PHP_METHOD(Yuga_Http_Redirect, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_setpath, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_getpath, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_httpcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_to, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, httpCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_header, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_refresh, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_back, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_route, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, getParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_isvaliduri, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_cleanurl, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_httpurl, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect_with, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_redirect___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_http_redirect_method_entry) {
	PHP_ME(Yuga_Http_Redirect, __construct, arginfo_yuga_http_redirect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yuga_Http_Redirect, setPath, arginfo_yuga_http_redirect_setpath, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Redirect, getPath, arginfo_yuga_http_redirect_getpath, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Redirect, getPath, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Redirect, httpCode, arginfo_yuga_http_redirect_httpcode, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Redirect, to, arginfo_yuga_http_redirect_to, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Redirect, header, arginfo_yuga_http_redirect_header, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Redirect, refresh, arginfo_yuga_http_redirect_refresh, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Redirect, refresh, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Redirect, back, arginfo_yuga_http_redirect_back, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Redirect, back, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Redirect, route, arginfo_yuga_http_redirect_route, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Redirect, isValidUri, arginfo_yuga_http_redirect_isvaliduri, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Http_Redirect, cleanUrl, arginfo_yuga_http_redirect_cleanurl, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Http_Redirect, httpUrl, arginfo_yuga_http_redirect_httpurl, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Redirect, with, arginfo_yuga_http_redirect_with, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Redirect, __call, arginfo_yuga_http_redirect___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
