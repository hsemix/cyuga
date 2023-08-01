
extern zend_class_entry *yuga_events_event_ce;

ZEPHIR_INIT_CLASS(Yuga_Events_Event);

PHP_METHOD(Yuga_Events_Event, __get);
PHP_METHOD(Yuga_Events_Event, __set);
PHP_METHOD(Yuga_Events_Event, setAttribute);
PHP_METHOD(Yuga_Events_Event, getAttribute);
PHP_METHOD(Yuga_Events_Event, attach);
PHP_METHOD(Yuga_Events_Event, on);
PHP_METHOD(Yuga_Events_Event, triggerObjectHandlers);
PHP_METHOD(Yuga_Events_Event, dispatch);
PHP_METHOD(Yuga_Events_Event, trigger);
PHP_METHOD(Yuga_Events_Event, getParameters);
PHP_METHOD(Yuga_Events_Event, fire);
zend_object *zephir_init_properties_Yuga_Events_Event(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event_attach, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event_on, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event_triggerobjecthandlers, 0, 0, 1)
	ZEND_ARG_INFO(0, handlers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event_dispatch, 0, 0, 0)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event_trigger, 0, 0, 0)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event_getparameters, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, listeners)
	ZEND_ARG_INFO(0, event)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, params, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, params, 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_events_event_zephir_init_properties_yuga_events_event, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_events_event_method_entry) {
	PHP_ME(Yuga_Events_Event, __get, arginfo_yuga_events_event___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Event, __set, arginfo_yuga_events_event___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Event, setAttribute, arginfo_yuga_events_event_setattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Event, getAttribute, arginfo_yuga_events_event_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Event, attach, arginfo_yuga_events_event_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Event, on, arginfo_yuga_events_event_on, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Event, triggerObjectHandlers, arginfo_yuga_events_event_triggerobjecthandlers, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Events_Event, dispatch, arginfo_yuga_events_event_dispatch, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Event, trigger, arginfo_yuga_events_event_trigger, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Events_Event, getParameters, arginfo_yuga_events_event_getparameters, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Events_Event, fire, arginfo_yuga_events_event_fire, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
