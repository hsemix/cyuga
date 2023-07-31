
extern zend_class_entry *yuga_events_dispatcher_dispatcher_ce;

ZEPHIR_INIT_CLASS(Yuga_Events_Dispatcher_Dispatcher);

PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, __construct);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, getName);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, setParams);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, getParams);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, getParam);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, setName);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, setParam);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, __get);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, __set);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, setAttribute);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, getAttribute);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, setAttributes);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, getInstance);
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, __call);
zend_object *zephir_init_properties_Yuga_Events_Dispatcher_Dispatcher(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_getparams, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_setattributes, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_getinstance, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_dispatcher_dispatcher_zephir_init_properties_yuga_events_dispatcher_dispatcher, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_events_dispatcher_dispatcher_method_entry) {
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, __construct, arginfo_yuga_events_dispatcher_dispatcher___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, getName, arginfo_yuga_events_dispatcher_dispatcher_getname, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, getName, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, setParams, arginfo_yuga_events_dispatcher_dispatcher_setparams, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, getParams, arginfo_yuga_events_dispatcher_dispatcher_getparams, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, getParams, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, getParam, arginfo_yuga_events_dispatcher_dispatcher_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, setName, arginfo_yuga_events_dispatcher_dispatcher_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, setParam, arginfo_yuga_events_dispatcher_dispatcher_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, __get, arginfo_yuga_events_dispatcher_dispatcher___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, __set, arginfo_yuga_events_dispatcher_dispatcher___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, setAttribute, arginfo_yuga_events_dispatcher_dispatcher_setattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, getAttribute, arginfo_yuga_events_dispatcher_dispatcher_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, setAttributes, arginfo_yuga_events_dispatcher_dispatcher_setattributes, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, getInstance, arginfo_yuga_events_dispatcher_dispatcher_getinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(Yuga_Events_Dispatcher_Dispatcher, __call, arginfo_yuga_events_dispatcher_dispatcher___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
