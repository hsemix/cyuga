
extern zend_class_entry *yuga_3__closure_ce;

ZEPHIR_INIT_CLASS(yuga_3__closure);

PHP_METHOD(yuga_3__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_3__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_3__closure_method_entry) {
	PHP_ME(yuga_3__closure, __invoke, arginfo_yuga_3__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
