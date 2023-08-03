
extern zend_class_entry *yuga_exceptions_iexception_ce;

ZEPHIR_INIT_CLASS(Yuga_Exceptions_IException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_exceptions_iexception_handleerror, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, error, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_exceptions_iexception_method_entry) {
	PHP_ABSTRACT_ME(Yuga_Exceptions_IException, handleError, arginfo_yuga_exceptions_iexception_handleerror)
	PHP_FE_END
};
