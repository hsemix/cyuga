
extern zend_class_entry *yuga_eventhandlers_applicationstop_ce;

ZEPHIR_INIT_CLASS(Yuga_EventHandlers_ApplicationStop);

PHP_METHOD(Yuga_EventHandlers_ApplicationStop, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_eventhandlers_applicationstop_handle, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_eventhandlers_applicationstop_method_entry) {
	PHP_ME(Yuga_EventHandlers_ApplicationStop, handle, arginfo_yuga_eventhandlers_applicationstop_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
