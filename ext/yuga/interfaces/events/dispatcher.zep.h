
extern zend_class_entry *yuga_interfaces_events_dispatcher_ce;

ZEPHIR_INIT_CLASS(Yuga_Interfaces_Events_Dispatcher);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_events_dispatcher_dispatch, 0, 0, 0)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_interfaces_events_dispatcher_method_entry) {
	PHP_ABSTRACT_ME(Yuga_Interfaces_Events_Dispatcher, dispatch, arginfo_yuga_interfaces_events_dispatcher_dispatch)
	PHP_FE_END
};
