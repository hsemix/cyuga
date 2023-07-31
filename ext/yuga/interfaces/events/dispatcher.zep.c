
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Interfaces_Events_Dispatcher)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Interfaces\\Events, Dispatcher, yuga, interfaces_events_dispatcher, yuga_interfaces_events_dispatcher_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Yuga_Interfaces_Events_Dispatcher, dispatch);
