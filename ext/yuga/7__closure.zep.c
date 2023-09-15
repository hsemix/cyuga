
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
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(yuga_7__closure)
{
	ZEPHIR_REGISTER_CLASS(yuga, 7__closure, yuga, 7__closure, yuga_7__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(yuga_7__closure_ce, SL("currentObject"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(yuga_7__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval currentObject, *pipeStack, pipeStack_sub, *pipe, pipe_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&currentObject);
	ZVAL_UNDEF(&pipeStack_sub);
	ZVAL_UNDEF(&pipe_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(pipeStack)
		Z_PARAM_ZVAL(pipe)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&currentObject, yuga_7__closure_ce, SL("currentObject"), PH_NOISY_CC);
	zephir_fetch_params(1, 2, 0, &pipeStack, &pipe);


	ZEPHIR_RETURN_CALL_METHOD(&currentObject, "passable", NULL, 0, pipeStack, pipe);
	zephir_check_call_status();
	RETURN_MM();
}

