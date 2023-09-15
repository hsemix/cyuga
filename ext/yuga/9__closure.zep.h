
extern zend_class_entry *yuga_9__closure_ce;

ZEPHIR_INIT_CLASS(yuga_9__closure);

PHP_METHOD(yuga_9__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_9__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_9__closure_method_entry) {
	PHP_ME(yuga_9__closure, __invoke, arginfo_yuga_9__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
