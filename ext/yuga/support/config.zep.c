
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
#include "ext/json/php_json.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_array.h"


/**
 * @author Mahad Tech Solutions
 */
ZEPHIR_INIT_CLASS(Yuga_Support_Config)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Support, Config, yuga, support_config, yuga_support_config_method_entry, 0);

	zend_declare_property_null(yuga_support_config_ce, SL("data"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_support_config_ce, SL("defaultValue"), ZEND_ACC_PROTECTED);
	zend_class_implements(yuga_support_config_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(yuga_support_config_ce, 1, zend_ce_countable);
	zend_class_implements(yuga_support_config_ce, 1, zend_ce_aggregate);
	zend_class_implements(yuga_support_config_ce, 1, php_json_serializable_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Support_Config, load)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file = NULL, file_sub, *key = NULL, key_sub, __$null, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file, &key);
	ZEPHIR_SEPARATE_PARAM(file);
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ".");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_str_replace(&_0, &_1, &_2, file);
	ZEPHIR_CPY_WRT(file, &_0);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, file, ".php");
	ZEPHIR_CALL_FUNCTION(&_4, "path", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_5);
	if (zephir_require_zval_ret(&_5, &_4) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(file, &_5);
	if (zephir_is_true(key)) {
		zephir_update_property_array(this_ptr, SL("data"), key, file);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), file);
	}
	RETURN_THIS();
}

PHP_METHOD(Yuga_Support_Config, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *defaultValue = NULL, defaultValue_sub, __$null, segments, segment, _0, data, _1, *_2, _3, _4$$5, _5$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	if (ZEPHIR_IS_EMPTY(key)) {
		RETURN_THIS();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultValue"), defaultValue);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, ".");
	ZEPHIR_INIT_VAR(&segments);
	zephir_fast_explode(&segments, &_0, key, LONG_MAX);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_1);
	zephir_is_iterable(&segments, 0, "yuga/Support/Config.zep", 52);
	if (Z_TYPE_P(&segments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&segments), _2)
		{
			ZEPHIR_INIT_NVAR(&segment);
			ZVAL_COPY(&segment, _2);
			if (zephir_array_isset(&data, &segment)) {
				zephir_array_fetch(&_4$$5, &data, &segment, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 45);
				ZEPHIR_CPY_WRT(&data, &_4$$5);
			} else {
				ZEPHIR_OBS_NVAR(&data);
				zephir_read_property(&data, this_ptr, ZEND_STRL("defaultValue"), PH_NOISY_CC);
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &segments, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &segments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&segment, &segments, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset(&data, &segment)) {
					zephir_array_fetch(&_5$$8, &data, &segment, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 45);
					ZEPHIR_CPY_WRT(&data, &_5$$8);
				} else {
					ZEPHIR_OBS_NVAR(&data);
					zephir_read_property(&data, this_ptr, ZEND_STRL("defaultValue"), PH_NOISY_CC);
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &segments, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&segment);
	RETURN_CCTOR(&data);
}

PHP_METHOD(Yuga_Support_Config, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("defaultValue"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(!ZEPHIR_IS_EQUAL(&_0, &_1));
}

PHP_METHOD(Yuga_Support_Config, getAll)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "data");
}

/**
 * Return the value of a given key or all the values as JSON
 */
PHP_METHOD(Yuga_Support_Config, toJson)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long options = 0, ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, options_sub, __$null, _2, _3, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(key)
		Z_PARAM_ZVAL(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key, &options);
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		ZVAL_LONG(options, 0);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (Z_TYPE_P(key) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "get", NULL, 0, key);
		zephir_check_call_status();
		ZVAL_LONG(&_1$$3, options);
		zephir_json_encode(return_value, &_0$$3, zephir_get_intval(&_1$$3) );
		RETURN_MM();
	}
	if (Z_TYPE_P(key) == IS_NULL) {
		options = 0;
	} else {
		options = zephir_get_numberval(key);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, options);
	zephir_json_encode(return_value, &_2, zephir_get_intval(&_3) );
	RETURN_MM();
}

/**
 * Check if a given key exists
 *
 * @param  int|string  key
 * @return bool
 */
PHP_METHOD(Yuga_Support_Config, offsetExists)
{
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &key);


}

/**
 * Return the value of a given key
 *
 * @param  int|string  key
 * @return mixed
 */
PHP_METHOD(Yuga_Support_Config, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set a given value to the given key
 *
 * @param int|string|null  key
 * @param mixed  value
 */
PHP_METHOD(Yuga_Support_Config, offsetSet)
{
	zval *key, key_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &key, &value);


	if (Z_TYPE_P(key) == IS_NULL) {
		zephir_update_property_array_append(this_ptr, SL("data"), value);
		RETURN_NULL();
	}
}

/**
 * Delete the given key
 *
 * @param  int|string  key
 * @return void
 */
PHP_METHOD(Yuga_Support_Config, offsetUnset)
{
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &key);


}

/**
 * Return the number of items in a given key
 *
 * @param  int|string|null  key
 * @return int
 */
PHP_METHOD(Yuga_Support_Config, count)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(&_0));
}

/**
 * Get an iterator for the stored items
 *
 * @return \ArrayIterator<TKey, TValue>
 */
PHP_METHOD(Yuga_Support_Config, getIterator)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, spl_ce_ArrayIterator);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 31, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return items for JSON serialization
 *
 * @return array<TKey, TValue>
 */
PHP_METHOD(Yuga_Support_Config, jsonSerialize)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "data");
}

