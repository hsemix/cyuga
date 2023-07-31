
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Events_Exceptions_EventException)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Events\\Exceptions, EventException, yuga, events_exceptions_eventexception, zend_ce_exception, NULL, 0);

	return SUCCESS;
}

