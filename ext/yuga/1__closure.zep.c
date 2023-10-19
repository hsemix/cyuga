
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(yuga_1__closure)
{
	ZEPHIR_REGISTER_CLASS(yuga, 1__closure, yuga, 1__closure, yuga_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(yuga_1__closure_ce, SL("carbon"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(yuga_1__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval carbon;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&carbon);


	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&carbon, yuga_1__closure_ce, SL("carbon"), PH_NOISY_CC);

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 107, &carbon);
	zephir_check_call_status();
	RETURN_MM();
}

