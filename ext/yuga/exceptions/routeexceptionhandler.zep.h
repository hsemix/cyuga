
extern zend_class_entry *yuga_exceptions_routeexceptionhandler_ce;

ZEPHIR_INIT_CLASS(Yuga_Exceptions_RouteExceptionHandler);

PHP_METHOD(Yuga_Exceptions_RouteExceptionHandler, handleError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_exceptions_routeexceptionhandler_handleerror, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, error, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_exceptions_routeexceptionhandler_method_entry) {
	PHP_ME(Yuga_Exceptions_RouteExceptionHandler, handleError, arginfo_yuga_exceptions_routeexceptionhandler_handleerror, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
