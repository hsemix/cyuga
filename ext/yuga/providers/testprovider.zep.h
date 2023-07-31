
extern zend_class_entry *yuga_providers_testprovider_ce;

ZEPHIR_INIT_CLASS(Yuga_Providers_TestProvider);

PHP_METHOD(Yuga_Providers_TestProvider, getName);
PHP_METHOD(Yuga_Providers_TestProvider, load);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_providers_testprovider_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_providers_testprovider_load, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Yuga\\Interfaces\\Application\\Application, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_providers_testprovider_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Providers_TestProvider, getName, arginfo_yuga_providers_testprovider_getname, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Providers_TestProvider, getName, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Providers_TestProvider, load, arginfo_yuga_providers_testprovider_load, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
