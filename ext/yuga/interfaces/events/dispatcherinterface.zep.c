
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Interfaces_Events_DispatcherInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Interfaces\\Events, DispatcherInterface, yuga, interfaces_events_dispatcherinterface, yuga_interfaces_events_dispatcherinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Yuga_Interfaces_Events_DispatcherInterface, dispatch);
