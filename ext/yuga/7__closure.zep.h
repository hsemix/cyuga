
extern zend_class_entry *yuga_7__closure_ce;

ZEPHIR_INIT_CLASS(yuga_7__closure);

PHP_METHOD(yuga_7__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_7__closure___invoke, 0, 0, 2)
	ZEND_ARG_INFO(0, pipeStack)
	ZEND_ARG_INFO(0, pipe)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_7__closure_method_entry) {
	PHP_ME(yuga_7__closure, __invoke, arginfo_yuga_7__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};