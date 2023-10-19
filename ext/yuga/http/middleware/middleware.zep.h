
extern zend_class_entry *yuga_http_middleware_middleware_ce;

ZEPHIR_INIT_CLASS(Yuga_Http_Middleware_MiddleWare);

PHP_METHOD(Yuga_Http_Middleware_MiddleWare, except);
zend_object *zephir_init_properties_Yuga_Http_Middleware_MiddleWare(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_middleware_middleware_except, 0, 0, 0)
	ZEND_ARG_INFO(0, except)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_middleware_middleware_zephir_init_properties_yuga_http_middleware_middleware, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_http_middleware_middleware_method_entry) {
	PHP_ME(Yuga_Http_Middleware_MiddleWare, except, arginfo_yuga_http_middleware_middleware_except, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
