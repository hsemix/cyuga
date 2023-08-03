
extern zend_class_entry *yuga_application_application_ce;

ZEPHIR_INIT_CLASS(Yuga_Application_Application);

PHP_METHOD(Yuga_Application_Application, __construct);
PHP_METHOD(Yuga_Application_Application, basePath);
PHP_METHOD(Yuga_Application_Application, bootPath);
PHP_METHOD(Yuga_Application_Application, configPath);
PHP_METHOD(Yuga_Application_Application, getCachedConfigPath);
PHP_METHOD(Yuga_Application_Application, getCachedServicesPath);
PHP_METHOD(Yuga_Application_Application, getCachedPackagesPath);
PHP_METHOD(Yuga_Application_Application, normalizeCachePath);
PHP_METHOD(Yuga_Application_Application, setVendorDir);
PHP_METHOD(Yuga_Application_Application, getVendorDir);
PHP_METHOD(Yuga_Application_Application, runningInConsole);
PHP_METHOD(Yuga_Application_Application, getInstance);
PHP_METHOD(Yuga_Application_Application, registerBaseBindings);
PHP_METHOD(Yuga_Application_Application, registerConfig);
PHP_METHOD(Yuga_Application_Application, run);
PHP_METHOD(Yuga_Application_Application, getDebugEnabled);
PHP_METHOD(Yuga_Application_Application, setEncryptionMethod);
PHP_METHOD(Yuga_Application_Application, getEncryptionMethod);
PHP_METHOD(Yuga_Application_Application, registerConfigProviders);
PHP_METHOD(Yuga_Application_Application, registerDefaultProviders);
PHP_METHOD(Yuga_Application_Application, setRequestForYugaConsole);
PHP_METHOD(Yuga_Application_Application, refreshRequest);
PHP_METHOD(Yuga_Application_Application, onRequest);
PHP_METHOD(Yuga_Application_Application, registerProvider);
PHP_METHOD(Yuga_Application_Application, getProviders);
PHP_METHOD(Yuga_Application_Application, bootProvider);
PHP_METHOD(Yuga_Application_Application, providerLoaded);
zend_object *zephir_init_properties_Yuga_Application_Application(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, root)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_basepath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_bootpath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_configpath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_getcachedconfigpath, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_getcachedservicespath, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_getcachedpackagespath, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_normalizecachepath, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_setvendordir, 0, 0, 1)
	ZEND_ARG_INFO(0, vendorDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_getvendordir, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_runninginconsole, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_getinstance, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_registerbasebindings, 0, 0, 1)
	ZEND_ARG_INFO(0, container)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_registerconfig, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_run, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_getdebugenabled, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_setencryptionmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_getencryptionmethod, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_registerconfigproviders, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_registerdefaultproviders, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_setrequestforyugaconsole, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_refreshrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_onrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_registerprovider, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, Yuga\\Interfaces\\Providers\\ServiceProviderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_getproviders, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_bootprovider, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, Yuga\\Interfaces\\Providers\\ServiceProviderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_providerloaded, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, Yuga\\Interfaces\\Providers\\ServiceProviderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_zephir_init_properties_yuga_application_application, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_application_application_method_entry) {
	PHP_ME(Yuga_Application_Application, __construct, arginfo_yuga_application_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yuga_Application_Application, basePath, arginfo_yuga_application_application_basepath, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Application_Application, bootPath, arginfo_yuga_application_application_bootpath, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Application_Application, configPath, arginfo_yuga_application_application_configpath, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, getCachedConfigPath, arginfo_yuga_application_application_getcachedconfigpath, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Application_Application, getCachedConfigPath, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, getCachedServicesPath, arginfo_yuga_application_application_getcachedservicespath, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Application_Application, getCachedServicesPath, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, getCachedPackagesPath, arginfo_yuga_application_application_getcachedpackagespath, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Application_Application, getCachedPackagesPath, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Application_Application, normalizeCachePath, arginfo_yuga_application_application_normalizecachepath, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Application_Application, setVendorDir, arginfo_yuga_application_application_setvendordir, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, getVendorDir, arginfo_yuga_application_application_getvendordir, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Application_Application, getVendorDir, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, runningInConsole, arginfo_yuga_application_application_runninginconsole, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Application_Application, runningInConsole, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, getInstance, arginfo_yuga_application_application_getinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_Application_Application, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(Yuga_Application_Application, registerBaseBindings, arginfo_yuga_application_application_registerbasebindings, ZEND_ACC_PROTECTED)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, registerConfig, arginfo_yuga_application_application_registerconfig, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Yuga_Application_Application, registerConfig, NULL, ZEND_ACC_PROTECTED)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, run, arginfo_yuga_application_application_run, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Application_Application, run, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, getDebugEnabled, arginfo_yuga_application_application_getdebugenabled, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Application_Application, getDebugEnabled, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Application_Application, setEncryptionMethod, arginfo_yuga_application_application_setencryptionmethod, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, getEncryptionMethod, arginfo_yuga_application_application_getencryptionmethod, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Application_Application, getEncryptionMethod, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, registerConfigProviders, arginfo_yuga_application_application_registerconfigproviders, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Yuga_Application_Application, registerConfigProviders, NULL, ZEND_ACC_PROTECTED)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, registerDefaultProviders, arginfo_yuga_application_application_registerdefaultproviders, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Yuga_Application_Application, registerDefaultProviders, NULL, ZEND_ACC_PROTECTED)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, setRequestForYugaConsole, arginfo_yuga_application_application_setrequestforyugaconsole, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Application_Application, setRequestForYugaConsole, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Application_Application, refreshRequest, arginfo_yuga_application_application_refreshrequest, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Application_Application, onRequest, arginfo_yuga_application_application_onrequest, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Application_Application, registerProvider, arginfo_yuga_application_application_registerprovider, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Application_Application, getProviders, arginfo_yuga_application_application_getproviders, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Application_Application, getProviders, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Application_Application, bootProvider, arginfo_yuga_application_application_bootprovider, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Application_Application, providerLoaded, arginfo_yuga_application_application_providerloaded, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
