
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yuga_Support_Str)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Support, Str, yuga, support_str, yuga_support_str_method_entry, 0);

	return SUCCESS;
}

/**
 * Determine if a given string contains a given substring.
 *
 * @param  string  haystack
 * @param  string|array  needles
 * @return bool
 */
PHP_METHOD(Yuga_Support_Str, contains)
{
	zend_bool _3$$3, _6$$5;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *haystack, haystack_sub, *needles, needles_sub, needle, *_1, _2, _4$$3, _7$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&haystack_sub);
	ZVAL_UNDEF(&needles_sub);
	ZVAL_UNDEF(&needle);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(haystack)
		Z_PARAM_ZVAL(needles)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &haystack, &needles);


	zephir_get_arrval(&_0, needles);
	zephir_is_iterable(&_0, 0, "yuga/Support/Str.zep", 23);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&needle);
			ZVAL_COPY(&needle, _1);
			_3$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&needle, "");
			if (_3$$3) {
				ZEPHIR_CALL_FUNCTION(&_4$$3, "mb_strpos", &_5, 57, haystack, &needle);
				zephir_check_call_status();
				_3$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(&_4$$3);
			}
			if (_3$$3) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&needle, &_0, "current", NULL, 0);
			zephir_check_call_status();
				_6$$5 = !ZEPHIR_IS_STRING_IDENTICAL(&needle, "");
				if (_6$$5) {
					ZEPHIR_CALL_FUNCTION(&_7$$5, "mb_strpos", &_5, 57, haystack, &needle);
					zephir_check_call_status();
					_6$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(&_7$$5);
				}
				if (_6$$5) {
					RETURN_MM_BOOL(1);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&needle);
	RETURN_MM_BOOL(0);
}

/**
 * Determine if a given string starts with a given substring.
 *
 * @param  string  haystack
 * @param  string|array  needles
 * @return bool
 */
PHP_METHOD(Yuga_Support_Str, startsWith)
{
	zval _7$$3, _12$$5;
	zend_bool _3$$3, _8$$5;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *haystack, haystack_sub, *needles, needles_sub, needle, *_1, _2, _4$$3, _5$$3, _6$$3, _9$$5, _10$$5, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&haystack_sub);
	ZVAL_UNDEF(&needles_sub);
	ZVAL_UNDEF(&needle);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_12$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(haystack)
		Z_PARAM_ZVAL(needles)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &haystack, &needles);


	zephir_get_arrval(&_0, needles);
	zephir_is_iterable(&_0, 0, "yuga/Support/Str.zep", 43);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&needle);
			ZVAL_COPY(&needle, _1);
			_3$$3 = !ZEPHIR_IS_STRING(&needle, "");
			if (_3$$3) {
				ZVAL_LONG(&_4$$3, 0);
				ZVAL_LONG(&_5$$3, zephir_fast_strlen_ev(&needle));
				ZEPHIR_INIT_NVAR(&_6$$3);
				zephir_substr(&_6$$3, haystack, 0 , zephir_get_intval(&_5$$3), 0);
				zephir_cast_to_string(&_7$$3, &needle);
				_3$$3 = ZEPHIR_IS_EQUAL(&_6$$3, &_7$$3);
			}
			if (_3$$3) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&needle, &_0, "current", NULL, 0);
			zephir_check_call_status();
				_8$$5 = !ZEPHIR_IS_STRING(&needle, "");
				if (_8$$5) {
					ZVAL_LONG(&_9$$5, 0);
					ZVAL_LONG(&_10$$5, zephir_fast_strlen_ev(&needle));
					ZEPHIR_INIT_NVAR(&_11$$5);
					zephir_substr(&_11$$5, haystack, 0 , zephir_get_intval(&_10$$5), 0);
					zephir_cast_to_string(&_12$$5, &needle);
					_8$$5 = ZEPHIR_IS_EQUAL(&_11$$5, &_12$$5);
				}
				if (_8$$5) {
					RETURN_MM_BOOL(1);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&needle);
	RETURN_MM_BOOL(0);
}

/**
 * Ends the haystack string with the suffix needle?
 */
PHP_METHOD(Yuga_Support_Str, endsWith)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *haystack_param = NULL, *needle_param = NULL, _1, _2;
	zval haystack, needle;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&haystack);
	ZVAL_UNDEF(&needle);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(haystack)
		Z_PARAM_STR(needle)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &haystack_param, &needle_param);
	zephir_get_strval(&haystack, haystack_param);
	zephir_get_strval(&needle, needle_param);


	_0 = zephir_fast_strlen_ev(&needle) == 0;
	if (!(_0)) {
		ZVAL_LONG(&_1, -zephir_fast_strlen_ev(&needle));
		ZEPHIR_INIT_VAR(&_2);
		zephir_substr(&_2, &haystack, zephir_get_intval(&_1), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		_0 = ZEPHIR_IS_EQUAL(&_2, &needle);
	}
	RETURN_MM_BOOL(_0);
}

