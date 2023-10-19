
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/require.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_array.h"


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
	zephir_fcall_cache_entry *_4 = NULL;
	zval *file = NULL, file_sub, *key = NULL, key_sub, __$null, _0, _1, _2, _3, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
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
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VS(&_5, file, ".php");
	ZEPHIR_CALL_CE_STATIC(&_3, yuga_support_helpers_ce, "path", &_4, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_6);
	if (zephir_require_zval_ret(&_6, &_3) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(file, &_6);
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
	zephir_is_iterable(&segments, 0, "yuga/Support/Config.zep", 48);
	if (Z_TYPE_P(&segments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&segments), _2)
		{
			ZEPHIR_INIT_NVAR(&segment);
			ZVAL_COPY(&segment, _2);
			if (zephir_array_isset(&data, &segment)) {
				zephir_array_fetch(&_4$$5, &data, &segment, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 41);
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
					zephir_array_fetch(&_5$$8, &data, &segment, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 41);
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
	RETURN_MM_BOOL(!ZEPHIR_IS_IDENTICAL(&_0, &_1));
}

PHP_METHOD(Yuga_Support_Config, getAll)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "data");
}

PHP_METHOD(Yuga_Support_Config, set)
{
	zend_bool _10$$6, _14$$8;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *value = NULL, value_sub, __$null, data, segment, keyItem, valueItem, _5, _6, _7, *_8, _9, *_0$$3, _1$$3, _11$$6, _13$$6, _12$$7, _15$$8, _17$$8, _16$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&keyItem);
	ZVAL_UNDEF(&valueItem);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_16$$9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &value);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	if (Z_TYPE_P(key) == IS_ARRAY) {
		zephir_is_iterable(key, 0, "yuga/Support/Config.zep", 70);
		if (Z_TYPE_P(key) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(key), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&keyItem);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&keyItem, _3$$3);
				} else {
					ZVAL_LONG(&keyItem, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&valueItem);
				ZVAL_COPY(&valueItem, _0$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 103, &keyItem, &valueItem);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, key, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, key, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&keyItem, key, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&valueItem, key, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 103, &keyItem, &valueItem);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, key, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&valueItem);
		ZEPHIR_INIT_NVAR(&keyItem);
		RETURN_THIS();
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_5);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, ".");
	zephir_fast_explode(&_6, &_7, key, LONG_MAX);
	zephir_is_iterable(&_6, 0, "yuga/Support/Config.zep", 84);
	if (Z_TYPE_P(&_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_6), _8)
		{
			ZEPHIR_INIT_NVAR(&segment);
			ZVAL_COPY(&segment, _8);
			_10$$6 = !(zephir_array_isset(&data, &segment));
			if (!(_10$$6)) {
				zephir_array_fetch(&_11$$6, &data, &segment, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 77);
				_10$$6 = !(Z_TYPE_P(&_11$$6) == IS_ARRAY);
			}
			if (_10$$6) {
				ZEPHIR_INIT_NVAR(&_12$$7);
				array_init(&_12$$7);
				zephir_array_update_zval(&data, &segment, &_12$$7, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_13$$6, &data, &segment, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 81);
			ZEPHIR_CPY_WRT(&data, &_13$$6);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_6, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_9, &_6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&segment, &_6, "current", NULL, 0);
			zephir_check_call_status();
				_14$$8 = !(zephir_array_isset(&data, &segment));
				if (!(_14$$8)) {
					zephir_array_fetch(&_15$$8, &data, &segment, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 77);
					_14$$8 = !(Z_TYPE_P(&_15$$8) == IS_ARRAY);
				}
				if (_14$$8) {
					ZEPHIR_INIT_NVAR(&_16$$9);
					array_init(&_16$$9);
					zephir_array_update_zval(&data, &segment, &_16$$9, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_17$$8, &data, &segment, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 81);
				ZEPHIR_CPY_WRT(&data, &_17$$8);
			ZEPHIR_CALL_METHOD(NULL, &_6, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&segment);
	ZEPHIR_CPY_WRT(&data, value);
	RETURN_THIS();
}

/**
 * Delete the given key or keys
 * @param array<TKey>|array<TKey, TValue>|int|string keys
 * @return Config
 */
PHP_METHOD(Yuga_Support_Config, delete)
{
	zend_bool _10$$5, _13$$7, _21$$11, _24$$13;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL, keys_sub, key, *_1, _2, _3$$3, items$$3, segment$$3, segments$$3, lastSegment$$3, _6$$3, *_8$$3, _9$$3, _5$$4, _11$$5, _12$$5, _14$$7, _15$$7, _16$$9, items$$9, segment$$9, segments$$9, lastSegment$$9, _18$$9, *_19$$9, _20$$9, _17$$10, _22$$11, _23$$11, _25$$13, _26$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&items$$3);
	ZVAL_UNDEF(&segment$$3);
	ZVAL_UNDEF(&segments$$3);
	ZVAL_UNDEF(&lastSegment$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&items$$9);
	ZVAL_UNDEF(&segment$$9);
	ZVAL_UNDEF(&segments$$9);
	ZVAL_UNDEF(&lastSegment$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(keys)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys);
	ZEPHIR_SEPARATE_PARAM(keys);


	zephir_get_arrval(&_0, keys);
	ZEPHIR_CPY_WRT(keys, &_0);
	zephir_is_iterable(keys, 0, "yuga/Support/Config.zep", 121);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(keys), _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _1);
			ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "exists", &_4, 0, &key);
			zephir_check_call_status();
			if (zephir_is_true(&_3$$3)) {
				zephir_unset_property_array(this_ptr, ZEND_STRL("data"), &key);
				zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_5$$4, &key, PH_SEPARATE);
				continue;
			}
			ZEPHIR_OBS_NVAR(&items$$3);
			zephir_read_property(&items$$3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZVAL_STRING(&_6$$3, ".");
			ZEPHIR_INIT_NVAR(&segments$$3);
			zephir_fast_explode(&segments$$3, &_6$$3, &key, LONG_MAX);
			ZEPHIR_MAKE_REF(&segments$$3);
			ZEPHIR_CALL_FUNCTION(&lastSegment$$3, "array_pop", &_7, 104, &segments$$3);
			ZEPHIR_UNREF(&segments$$3);
			zephir_check_call_status();
			zephir_is_iterable(&segment$$3, 0, "yuga/Support/Config.zep", 118);
			if (Z_TYPE_P(&segment$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&segment$$3), _8$$3)
				{
					ZEPHIR_INIT_NVAR(&segment$$3);
					ZVAL_COPY(&segment$$3, _8$$3);
					_10$$5 = !(zephir_array_isset(&items$$3, &segment$$3));
					if (!(_10$$5)) {
						zephir_array_fetch(&_11$$5, &items$$3, &segment$$3, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 111);
						_10$$5 = !(Z_TYPE_P(&_11$$5) == IS_ARRAY);
					}
					if (_10$$5) {
						continue;
					}
					zephir_array_fetch(&_12$$5, &items$$3, &segment$$3, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 115);
					ZEPHIR_CPY_WRT(&items$$3, &_12$$5);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &segment$$3, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_9$$3, &segment$$3, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_9$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&segment$$3, &segment$$3, "current", NULL, 0);
					zephir_check_call_status();
						_13$$7 = !(zephir_array_isset(&items$$3, &segment$$3));
						if (!(_13$$7)) {
							zephir_array_fetch(&_14$$7, &items$$3, &segment$$3, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 111);
							_13$$7 = !(Z_TYPE_P(&_14$$7) == IS_ARRAY);
						}
						if (_13$$7) {
							continue;
						}
						zephir_array_fetch(&_15$$7, &items$$3, &segment$$3, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 115);
						ZEPHIR_CPY_WRT(&items$$3, &_15$$7);
					ZEPHIR_CALL_METHOD(NULL, &segment$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&segment$$3);
			zephir_array_unset(&items$$3, &lastSegment$$3, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, keys, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_16$$9, this_ptr, "exists", &_4, 0, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_16$$9)) {
					zephir_unset_property_array(this_ptr, ZEND_STRL("data"), &key);
					zephir_read_property(&_17$$10, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_17$$10, &key, PH_SEPARATE);
					continue;
				}
				ZEPHIR_OBS_NVAR(&items$$9);
				zephir_read_property(&items$$9, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(&_18$$9);
				ZVAL_STRING(&_18$$9, ".");
				ZEPHIR_INIT_NVAR(&segments$$9);
				zephir_fast_explode(&segments$$9, &_18$$9, &key, LONG_MAX);
				ZEPHIR_MAKE_REF(&segments$$9);
				ZEPHIR_CALL_FUNCTION(&lastSegment$$9, "array_pop", &_7, 104, &segments$$9);
				ZEPHIR_UNREF(&segments$$9);
				zephir_check_call_status();
				zephir_is_iterable(&segment$$9, 0, "yuga/Support/Config.zep", 118);
				if (Z_TYPE_P(&segment$$9) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&segment$$9), _19$$9)
					{
						ZEPHIR_INIT_NVAR(&segment$$9);
						ZVAL_COPY(&segment$$9, _19$$9);
						_21$$11 = !(zephir_array_isset(&items$$9, &segment$$9));
						if (!(_21$$11)) {
							zephir_array_fetch(&_22$$11, &items$$9, &segment$$9, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 111);
							_21$$11 = !(Z_TYPE_P(&_22$$11) == IS_ARRAY);
						}
						if (_21$$11) {
							continue;
						}
						zephir_array_fetch(&_23$$11, &items$$9, &segment$$9, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 115);
						ZEPHIR_CPY_WRT(&items$$9, &_23$$11);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &segment$$9, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_20$$9, &segment$$9, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_20$$9)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&segment$$9, &segment$$9, "current", NULL, 0);
						zephir_check_call_status();
							_24$$13 = !(zephir_array_isset(&items$$9, &segment$$9));
							if (!(_24$$13)) {
								zephir_array_fetch(&_25$$13, &items$$9, &segment$$9, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 111);
								_24$$13 = !(Z_TYPE_P(&_25$$13) == IS_ARRAY);
							}
							if (_24$$13) {
								continue;
							}
							zephir_array_fetch(&_26$$13, &items$$9, &segment$$9, PH_NOISY | PH_READONLY, "yuga/Support/Config.zep", 115);
							ZEPHIR_CPY_WRT(&items$$9, &_26$$13);
						ZEPHIR_CALL_METHOD(NULL, &segment$$9, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&segment$$9);
				zephir_array_unset(&items$$9, &lastSegment$$9, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();
}

/**
 * Return the value of a given key or all the values as JSON
 *
 * @param  mixed  key
 * @param  int  options
 * @return string|false
 */
PHP_METHOD(Yuga_Support_Config, toJson)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *options = NULL, options_sub, __$null, _0$$3, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
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
		zephir_json_encode(return_value, &_0$$3, zephir_get_intval(options) );
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(options, key);
	if (Z_TYPE_P(key) == IS_NULL) {
		ZEPHIR_INIT_NVAR(options);
		ZVAL_LONG(options, 0);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_json_encode(return_value, &_1, zephir_get_intval(options) );
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "exists", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 105, &_0);
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

