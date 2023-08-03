
extern zend_class_entry *yuga_route_exceptions_notfoundhttpexceptionhandler_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Exceptions_NotFoundHttpExceptionHandler);

PHP_METHOD(Yuga_Route_Exceptions_NotFoundHttpExceptionHandler, handleError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_exceptions_notfoundhttpexceptionhandler_handleerror, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, error, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_exceptions_notfoundhttpexceptionhandler_method_entry) {
	PHP_ME(Yuga_Route_Exceptions_NotFoundHttpExceptionHandler, handleError, arginfo_yuga_route_exceptions_notfoundhttpexceptionhandler_handleerror, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
