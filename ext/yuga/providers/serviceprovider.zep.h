
extern zend_class_entry *yuga_providers_serviceprovider_ce;

ZEPHIR_INIT_CLASS(Yuga_Providers_ServiceProvider);

PHP_METHOD(Yuga_Providers_ServiceProvider, register);
PHP_METHOD(Yuga_Providers_ServiceProvider, load);
PHP_METHOD(Yuga_Providers_ServiceProvider, commands);
PHP_METHOD(Yuga_Providers_ServiceProvider, provides);
void zephir_init_static_properties_Yuga_Providers_ServiceProvider();

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_providers_serviceprovider_register, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Yuga\\Interfaces\\Application\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_providers_serviceprovider_load, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Yuga\\Interfaces\\Application\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_providers_serviceprovider_commands, 0, 0, 1)
	ZEND_ARG_INFO(0, commands)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_providers_serviceprovider_provides, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_providers_serviceprovider_zephir_init_static_properties_yuga_providers_serviceprovider, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_providers_serviceprovider_method_entry) {
	PHP_ME(Yuga_Providers_ServiceProvider, register, arginfo_yuga_providers_serviceprovider_register, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Providers_ServiceProvider, load, arginfo_yuga_providers_serviceprovider_load, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Providers_ServiceProvider, commands, arginfo_yuga_providers_serviceprovider_commands, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Providers_ServiceProvider, provides, arginfo_yuga_providers_serviceprovider_provides, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Providers_ServiceProvider, provides, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
