
extern zend_class_entry *yuga_support_config_ce;

ZEPHIR_INIT_CLASS(Yuga_Support_Config);

PHP_METHOD(Yuga_Support_Config, load);
PHP_METHOD(Yuga_Support_Config, get);
PHP_METHOD(Yuga_Support_Config, exists);
PHP_METHOD(Yuga_Support_Config, getAll);
PHP_METHOD(Yuga_Support_Config, toJson);
PHP_METHOD(Yuga_Support_Config, offsetExists);
PHP_METHOD(Yuga_Support_Config, offsetGet);
PHP_METHOD(Yuga_Support_Config, offsetSet);
PHP_METHOD(Yuga_Support_Config, offsetUnset);
PHP_METHOD(Yuga_Support_Config, count);
PHP_METHOD(Yuga_Support_Config, getIterator);
PHP_METHOD(Yuga_Support_Config, jsonSerialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_load, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_getall, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_tojson, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_count, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_getiterator, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_config_jsonserialize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_support_config_method_entry) {
	PHP_ME(Yuga_Support_Config, load, arginfo_yuga_support_config_load, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Support_Config, get, arginfo_yuga_support_config_get, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Support_Config, exists, arginfo_yuga_support_config_exists, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Support_Config, getAll, arginfo_yuga_support_config_getall, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Support_Config, getAll, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Support_Config, toJson, arginfo_yuga_support_config_tojson, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Support_Config, offsetExists, arginfo_yuga_support_config_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Support_Config, offsetGet, arginfo_yuga_support_config_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Support_Config, offsetSet, arginfo_yuga_support_config_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Support_Config, offsetUnset, arginfo_yuga_support_config_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Support_Config, count, arginfo_yuga_support_config_count, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Support_Config, getIterator, arginfo_yuga_support_config_getiterator, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Support_Config, getIterator, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Support_Config, jsonSerialize, arginfo_yuga_support_config_jsonserialize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Support_Config, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
