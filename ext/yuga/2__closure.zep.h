
extern zend_class_entry *yuga_2__closure_ce;

ZEPHIR_INIT_CLASS(yuga_2__closure);

PHP_METHOD(yuga_2__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_2__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_2__closure_method_entry) {
	PHP_ME(yuga_2__closure, __invoke, arginfo_yuga_2__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
