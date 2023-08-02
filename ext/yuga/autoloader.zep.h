
extern zend_class_entry *yuga_autoloader_ce;

ZEPHIR_INIT_CLASS(Yuga_AutoLoader);

PHP_METHOD(Yuga_AutoLoader, __construct);
PHP_METHOD(Yuga_AutoLoader, getInstance);
PHP_METHOD(Yuga_AutoLoader, addPsr4);
PHP_METHOD(Yuga_AutoLoader, load);
PHP_METHOD(Yuga_AutoLoader, includeFile);
PHP_METHOD(Yuga_AutoLoader, loadPsr4);
zend_object *zephir_init_properties_Yuga_AutoLoader(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_autoloader___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_autoloader_getinstance, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_autoloader_addpsr4, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, classes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_autoloader_load, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_autoloader_includefile, 0, 0, 1)
	ZEND_ARG_INFO(0, classValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_autoloader_loadpsr4, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, namespaces, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_autoloader_zephir_init_properties_yuga_autoloader, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_autoloader_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_AutoLoader, __construct, arginfo_yuga_autoloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Yuga_AutoLoader, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_AutoLoader, getInstance, arginfo_yuga_autoloader_getinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_AutoLoader, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(Yuga_AutoLoader, addPsr4, arginfo_yuga_autoloader_addpsr4, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_AutoLoader, load, arginfo_yuga_autoloader_load, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_AutoLoader, load, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_AutoLoader, includeFile, arginfo_yuga_autoloader_includefile, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_AutoLoader, loadPsr4, arginfo_yuga_autoloader_loadpsr4, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
