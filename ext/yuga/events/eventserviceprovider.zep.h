
extern zend_class_entry *yuga_events_eventserviceprovider_ce;

ZEPHIR_INIT_CLASS(Yuga_Events_EventServiceProvider);

PHP_METHOD(Yuga_Events_EventServiceProvider, __construct);
PHP_METHOD(Yuga_Events_EventServiceProvider, load);
PHP_METHOD(Yuga_Events_EventServiceProvider, loadEvents);
zend_object *zephir_init_properties_Yuga_Events_EventServiceProvider(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_eventserviceprovider___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Yuga\\Interfaces\\Application\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_eventserviceprovider_load, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Yuga\\Interfaces\\Application\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_eventserviceprovider_loadevents, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Yuga\\Interfaces\\Events\\DispatcherInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_eventserviceprovider_zephir_init_properties_yuga_events_eventserviceprovider, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_events_eventserviceprovider_method_entry) {
	PHP_ME(Yuga_Events_EventServiceProvider, __construct, arginfo_yuga_events_eventserviceprovider___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yuga_Events_EventServiceProvider, load, arginfo_yuga_events_eventserviceprovider_load, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_EventServiceProvider, loadEvents, arginfo_yuga_events_eventserviceprovider_loadevents, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
