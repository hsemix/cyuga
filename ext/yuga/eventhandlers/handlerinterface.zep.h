
extern zend_class_entry *yuga_eventhandlers_handlerinterface_ce;

ZEPHIR_INIT_CLASS(Yuga_EventHandlers_HandlerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_eventhandlers_handlerinterface_handle, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_eventhandlers_handlerinterface_method_entry) {
	PHP_ABSTRACT_ME(Yuga_EventHandlers_HandlerInterface, handle, arginfo_yuga_eventhandlers_handlerinterface_handle)
	PHP_FE_END
};
