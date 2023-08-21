
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(yuga_3__closure)
{
	ZEPHIR_REGISTER_CLASS(yuga, 3__closure, yuga, 3__closure, yuga_3__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(yuga_3__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *matches, matches_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matches_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(matches)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches);


	zephir_array_fetch_long(&_0, matches, 0, PH_NOISY | PH_READONLY, "yuga/Http/Uri.zep", 412);
	ZEPHIR_RETURN_CALL_FUNCTION("urlencode", NULL, 96, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

