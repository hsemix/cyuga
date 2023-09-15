
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
#include "ext/date/php_date.h"
#include "ext/json/php_json.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yuga_Carbon_Carbon)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Carbon, Carbon, yuga, carbon_carbon, php_date_get_date_ce(), yuga_carbon_carbon_method_entry, 0);

	zend_declare_property_string(yuga_carbon_carbon_ce, SL("toStringFormat"), "Y-m-d H:i:s", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	zephir_declare_class_constant_string(yuga_carbon_carbon_ce, SL("DEFAULT_TO_STRING_FORMAT"), "Y-m-d H:i:s");

	zend_class_implements(yuga_carbon_carbon_ce, 1, php_json_serializable_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Carbon_Carbon, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *time = NULL, time_sub, *tz = NULL, tz_sub, __$null, timezone, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&time_sub);
	ZVAL_UNDEF(&tz_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&timezone);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(time)
		Z_PARAM_ZVAL_OR_NULL(tz)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &time, &tz);
	if (!time) {
		time = &time_sub;
		time = &__$null;
	}
	if (!tz) {
		tz = &tz_sub;
		tz = &__$null;
	}


	ZEPHIR_CALL_STATIC(&timezone, "safecreatedatetimezone", NULL, 0, tz);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(time) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "now");
	} else {
		ZEPHIR_CPY_WRT(&_0, time);
	}
	ZEPHIR_CALL_PARENT(NULL, yuga_carbon_carbon_ce, getThis(), "__construct", NULL, 0, &_0, &timezone);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Carbon_Carbon, __toString)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, yuga_carbon_carbon_ce, SL("toStringFormat"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "format", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Carbon_Carbon, jsonSerialize)
{
	zval carbon, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&carbon);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CPY_WRT(&carbon, this_ptr);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, yuga_1__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(yuga_1__closure_ce, ZEND_STRL("carbon"), &carbon);
	ZEPHIR_CALL_USER_FUNC(return_value, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Format the instance as date
 *
 * @return string
 */
PHP_METHOD(Yuga_Carbon_Carbon, toDateString)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "format", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Format the instance as a readable date
 *
 * @return string
 */
PHP_METHOD(Yuga_Carbon_Carbon, toFormattedDateString)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "M j, Y");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "format", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Format the instance as time
 *
 * @return string
 */
PHP_METHOD(Yuga_Carbon_Carbon, toTimeString)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "H:i:s");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "format", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Format the instance as date and time
 *
 * @return string
 */
PHP_METHOD(Yuga_Carbon_Carbon, toDateTimeString)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "format", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Format the instance with day, date and time
 *
 * @return string
 */
PHP_METHOD(Yuga_Carbon_Carbon, toDayDateTimeString)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "D, M j, Y g:i A");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "format", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Carbon_Carbon, safeCreateDateTimeZone)
{
	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *objectVal = NULL, objectVal_sub, __$null, __$true, _0$$3, tzName$$5, _1$$5, _2$$6, _3$$6, tz, _5$$7, _6$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objectVal_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&tzName$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&tz);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(objectVal)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &objectVal);
	ZEPHIR_SEPARATE_PARAM(objectVal);


	if (Z_TYPE_P(objectVal) == IS_NULL) {
		object_init_ex(return_value, php_date_get_timezone_ce());
		ZEPHIR_CALL_FUNCTION(&_0$$3, "date_default_timezone_get", NULL, 31);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_is_instance_of(objectVal, SL("DateTimeZone"))) {
		RETVAL_ZVAL(objectVal, 1, 0);
		RETURN_MM();
	}
	if (zephir_is_numeric(objectVal)) {
		ZVAL_LONG(&_1$$5, (zephir_get_numberval(objectVal) * 3600));
		ZEPHIR_CALL_FUNCTION(&tzName$$5, "timezone_name_from_abbr", NULL, 32, &__$null, &_1$$5, &__$true);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&tzName$$5)) {
			ZEPHIR_INIT_VAR(&_2$$6);
			object_init_ex(&_2$$6, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_3$$6);
			ZEPHIR_CONCAT_SVS(&_3$$6, "Unknown or bad timezone (", objectVal, ")");
			ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 33, &_3$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$6, "yuga/Carbon/Carbon.zep", 102);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(objectVal, &tzName$$5);
	}
	zephir_cast_to_string(&_4, objectVal);
	ZEPHIR_CALL_FUNCTION(&tz, "timezone_open", NULL, 34, &_4);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&tz)) {
		ZEPHIR_INIT_VAR(&_5$$7);
		object_init_ex(&_5$$7, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_6$$7);
		ZEPHIR_CONCAT_SVS(&_6$$7, "Unknown or bad timezone (", objectVal, ")");
		ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 33, &_6$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$7, "yuga/Carbon/Carbon.zep", 111);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&tz);
}

/**
 * Get a Carbon instance for the current date and time.
 *
 * @param \DateTimeZone|string|null tz
 *
 * @return static
 */
PHP_METHOD(Yuga_Carbon_Carbon, now)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tz = NULL, tz_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tz_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(tz)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &tz);
	if (!tz) {
		tz = &tz_sub;
		tz = &__$null;
	}


	object_init_ex(return_value, yuga_carbon_carbon_ce);
	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 35, &_0, tz);
	zephir_check_call_status();
	RETURN_MM();
}

