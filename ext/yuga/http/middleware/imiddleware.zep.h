
extern zend_class_entry *yuga_http_middleware_imiddleware_ce;

ZEPHIR_INIT_CLASS(Yuga_Http_Middleware_IMiddleware);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_middleware_imiddleware_run, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, next, Closure, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_http_middleware_imiddleware_method_entry) {
	PHP_ABSTRACT_ME(Yuga_Http_Middleware_IMiddleware, run, arginfo_yuga_http_middleware_imiddleware_run)
	PHP_FE_END
};
