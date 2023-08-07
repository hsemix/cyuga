
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(yuga_1__closure)
{
	ZEPHIR_REGISTER_CLASS(yuga, 1__closure, yuga, 1__closure, yuga_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(yuga_1__closure_ce, SL("original"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	zend_declare_property_null(yuga_1__closure_ce, SL("index"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(yuga_1__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval original, index, *key, key_sub, *property = NULL, property_sub, path, fileValues, value, *_0, _1, _4, _2$$3, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&original);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&property_sub);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&fileValues);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(property)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&index, yuga_1__closure_ce, SL("index"), PH_NOISY_CC);
	zephir_read_static_property_ce(&original, yuga_1__closure_ce, SL("original"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 1, &key, &property);
	if (!property) {
		property = &property_sub;
		ZEPHIR_INIT_VAR(property);
		ZVAL_STRING(property, "name");
	}


	ZEPHIR_OBS_VAR(&path);
	zephir_array_fetch(&path, &original, property, PH_NOISY, "yuga/Http/Input/Input.zep", 158);
	ZEPHIR_CALL_FUNCTION(&fileValues, "array_values", NULL, 3, &index);
	zephir_check_call_status();
	zephir_is_iterable(&fileValues, 0, "yuga/Http/Input/Input.zep", 166);
	if (Z_TYPE_P(&fileValues) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fileValues), _0)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			zephir_array_fetch(&_2$$3, &path, &value, PH_NOISY | PH_READONLY, "yuga/Http/Input/Input.zep", 163);
			ZEPHIR_CPY_WRT(&path, &_2$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fileValues, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &fileValues, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &fileValues, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch(&_3$$4, &path, &value, PH_NOISY | PH_READONLY, "yuga/Http/Input/Input.zep", 163);
				ZEPHIR_CPY_WRT(&path, &_3$$4);
			ZEPHIR_CALL_METHOD(NULL, &fileValues, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_fetch(&_4, &path, key, PH_NOISY | PH_READONLY, "yuga/Http/Input/Input.zep", 166);
	RETURN_CTOR(&_4);
}

