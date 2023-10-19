
extern zend_class_entry *yuga_http_middleware_basecsrfverifier_ce;

ZEPHIR_INIT_CLASS(Yuga_Http_Middleware_BaseCsrfVerifier);

PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, __construct);
PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, skip);
PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, run);
PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, generateToken);
PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, hasToken);
PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, getToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_middleware_basecsrfverifier___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_middleware_basecsrfverifier_skip, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_middleware_basecsrfverifier_run, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, next, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_middleware_basecsrfverifier_generatetoken, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_middleware_basecsrfverifier_hastoken, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_middleware_basecsrfverifier_gettoken, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_http_middleware_basecsrfverifier_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Middleware_BaseCsrfVerifier, __construct, arginfo_yuga_http_middleware_basecsrfverifier___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Yuga_Http_Middleware_BaseCsrfVerifier, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
	PHP_ME(Yuga_Http_Middleware_BaseCsrfVerifier, skip, arginfo_yuga_http_middleware_basecsrfverifier_skip, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Http_Middleware_BaseCsrfVerifier, run, arginfo_yuga_http_middleware_basecsrfverifier_run, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Middleware_BaseCsrfVerifier, generateToken, arginfo_yuga_http_middleware_basecsrfverifier_generatetoken, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Middleware_BaseCsrfVerifier, generateToken, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Middleware_BaseCsrfVerifier, hasToken, arginfo_yuga_http_middleware_basecsrfverifier_hastoken, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Middleware_BaseCsrfVerifier, hasToken, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Middleware_BaseCsrfVerifier, getToken, arginfo_yuga_http_middleware_basecsrfverifier_gettoken, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Middleware_BaseCsrfVerifier, getToken, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
