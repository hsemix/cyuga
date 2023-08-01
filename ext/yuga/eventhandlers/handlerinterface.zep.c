
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_EventHandlers_HandlerInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\EventHandlers, HandlerInterface, yuga, eventhandlers_handlerinterface, yuga_eventhandlers_handlerinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Yuga_EventHandlers_HandlerInterface, handle);
