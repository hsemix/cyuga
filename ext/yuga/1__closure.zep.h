
extern zend_class_entry *yuga_1__closure_ce;

ZEPHIR_INIT_CLASS(yuga_1__closure);

PHP_METHOD(yuga_1__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_1__closure___invoke, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_1__closure_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(yuga_1__closure, __invoke, arginfo_yuga_1__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#else
	PHP_ME(yuga_1__closure, __invoke, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#endif
	PHP_FE_END
};
