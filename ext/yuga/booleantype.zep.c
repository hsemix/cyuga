
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Yuga_BooleanType)
{
	ZEPHIR_REGISTER_CLASS(Yuga, BooleanType, yuga, booleantype, yuga_booleantype_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Yuga_BooleanType, parse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str, str_sub, *defaultValue = NULL, defaultValue_sub, __$false, boolValue, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&boolValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(str)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$false;
	}


	ZVAL_LONG(&_0, 258);
	ZVAL_LONG(&_1, 134217728);
	ZEPHIR_CALL_FUNCTION(&boolValue, "filter_var", NULL, 25, str, &_0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&boolValue) != IS_NULL) {
		RETURN_CCTOR(&boolValue);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

