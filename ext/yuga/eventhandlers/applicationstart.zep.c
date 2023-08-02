
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Yuga_EventHandlers_ApplicationStart)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\EventHandlers, ApplicationStart, yuga, eventhandlers_applicationstart, yuga_eventhandlers_applicationstart_method_entry, 0);

	zend_class_implements(yuga_eventhandlers_applicationstart_ce, 1, yuga_eventhandlers_handlerinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_EventHandlers_ApplicationStart, handle)
{
	zval *event, event_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(event)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &event);


}

