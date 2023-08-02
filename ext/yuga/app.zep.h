
extern zend_class_entry *yuga_app_ce;

ZEPHIR_INIT_CLASS(Yuga_App);

PHP_METHOD(Yuga_App, __callStatic);
PHP_METHOD(Yuga_App, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_app___callstatic, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_app___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_app_method_entry) {
	PHP_ME(Yuga_App, __callStatic, arginfo_yuga_app___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_App, __call, arginfo_yuga_app___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
