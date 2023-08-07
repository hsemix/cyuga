
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "Zend/zend_closures.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Yuga_Container_Container)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Container, Container, yuga, container_container, yuga_container_container_method_entry, 0);

	zend_declare_property_null(yuga_container_container_ce, SL("bindings"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_container_container_ce, SL("instances"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_container_container_ce, SL("thisInstances"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);
	/**
	 * An array of the types that have been resolved.
	 *
	 * @var array
	 */
	zend_declare_property_null(yuga_container_container_ce, SL("resolved"), ZEND_ACC_PROTECTED);
	yuga_container_container_ce->create_object = zephir_init_properties_Yuga_Container_Container;

	zend_class_implements(yuga_container_container_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;
}

PHP_METHOD(Yuga_Container_Container, offsetGet)
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "make", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Container_Container, offsetSet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Container_Container, offsetExists)
{
	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &key);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, key));
}

PHP_METHOD(Yuga_Container_Container, offsetUnset)
{
	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &key);


	zephir_unset_property_array(this_ptr, ZEND_STRL("bindings"), key);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, key, PH_SEPARATE);
}

PHP_METHOD(Yuga_Container_Container, bind)
{
	zval _3$$4, _5$$3, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *value, value_sub, *singleton = NULL, singleton_sub, __$false, _0, _1, _2$$4, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&singleton_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(singleton)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &value, &singleton);
	ZEPHIR_SEPARATE_PARAM(key);
	if (!singleton) {
		singleton = &singleton_sub;
		singleton = &__$false;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\");
	zephir_fast_trim(&_0, key, &_1, ZEPHIR_TRIM_LEFT);
	ZEPHIR_CPY_WRT(key, &_0);
	if (zephir_is_instance_of(value, SL("Closure"))) {
		if (zephir_is_true(singleton)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0);
			zephir_array_fast_append(&_3$$4, this_ptr);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_2$$4, value, &_3$$4);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("instances"), key, &_2$$4);
		}
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 1, 0);
		zephir_array_fast_append(&_5$$3, this_ptr);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_4$$3, value, &_5$$3);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("bindings"), key, &_4$$3);
	} else {
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_create_array(&_6$$5, 2, 0);
		zephir_array_update_string(&_6$$5, SL("value"), value, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_6$$5, SL("singleton"), singleton, PH_COPY | PH_SEPARATE);
		zephir_update_property_array(this_ptr, SL("bindings"), key, &_6$$5);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Determine if the given abstractValue type has been bound.
 *
 * @param  string  abstractValue
 * @return bool
 */
PHP_METHOD(Yuga_Container_Container, bound)
{
	zend_bool _1;
	zval *abstractValue, abstractValue_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&abstractValue_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(abstractValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &abstractValue);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, abstractValue);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		_1 = zephir_array_isset(&_2, abstractValue);
	}
	RETURN_BOOL(_1);
}

/**
 * Determine if the given abstractValue type has been resolved.
 *
 * @param  string  abstractValue
 * @return bool
 */
PHP_METHOD(Yuga_Container_Container, resolved)
{
	zend_bool _1;
	zval *abstractValue, abstractValue_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&abstractValue_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(abstractValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &abstractValue);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("resolved"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, abstractValue);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		_1 = zephir_array_isset(&_2, abstractValue);
	}
	RETURN_BOOL(_1);
}

PHP_METHOD(Yuga_Container_Container, has)
{
	zend_bool _1;
	zval *key, key_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &key);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_key_exists(&_0, key);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		_1 = zephir_array_key_exists(&_2, key);
	}
	if (_1) {
		RETURN_BOOL(1);
	}
	RETURN_BOOL(0);
}

PHP_METHOD(Yuga_Container_Container, singleton)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *value, value_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);


	ZVAL_BOOL(&_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "bind", NULL, 0, key, value, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Container_Container, getBinding)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, _0, _1, _2, _3, _6, _4$$4, _5$$4, _7$$5, _8$$5, _11$$5, _12$$5, _16$$5, _17$$5, _9$$6, _10$$6, _13$$7, _14$$7, _15$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);
	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\");
	zephir_fast_trim(&_0, key, &_1, ZEPHIR_TRIM_LEFT);
	ZEPHIR_CPY_WRT(key, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(&_2)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_3, key)) {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_5$$4, &_4$$4, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 109);
		RETURN_CTOR(&_5$$4);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_6, key)) {
		zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_8$$5);
		zephir_array_fetch(&_8$$5, &_7$$5, key, PH_NOISY, "yuga/Container/Container.zep", 114);
		if (zephir_is_instance_of(&_8$$5, SL("Closure"))) {
			zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_10$$6, &_9$$6, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 115);
			RETURN_CTOR(&_10$$6);
		}
		zephir_read_property(&_11$$5, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_12$$5, &_11$$5, key, PH_READONLY, "yuga/Container/Container.zep", 118);
		if (zephir_array_isset_string(&_12$$5, SL("value"))) {
			zephir_read_property(&_13$$7, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_14$$7, &_13$$7, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 119);
			zephir_array_fetch_string(&_15$$7, &_14$$7, SL("value"), PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 119);
			RETURN_CTOR(&_15$$7);
		}
		zephir_read_property(&_16$$5, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_17$$5, &_16$$5, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 121);
		RETURN_CTOR(&_17$$5);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Container_Container, getBindings)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(return_value, &_0);
	return;
}

PHP_METHOD(Yuga_Container_Container, make)
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbinding", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Container_Container, get)
{
	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0, _1, _2, _3, _4, _6, _7, _8, _9, _10, _11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_array_fetch(&_2, &_1, key, PH_NOISY, "yuga/Container/Container.zep", 141);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 143);
	_5 = Z_TYPE_P(&_4) == IS_STRING;
	if (_5) {
		zephir_read_property(&_6, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_7, &_6, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 143);
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_STRING(&_8, "/");
		ZEPHIR_INIT_VAR(&_9);
		zephir_fast_strpos(&_9, &_7, &_8, 0 );
		_5 = !ZEPHIR_IS_FALSE(&_9);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_11, &_10, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 145);
	if (zephir_array_key_exists(&_0, key)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbinding", NULL, 0, key);
		zephir_check_call_status();
		RETURN_MM();
	} else if (zephir_is_instance_of(&_2, SL("Closure"))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbinding", NULL, 0, key);
		zephir_check_call_status();
		RETURN_MM();
	} else if (_5) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbinding", NULL, 0, key);
		zephir_check_call_status();
		RETURN_MM();
	} else if (Z_TYPE_P(&_11) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "make", NULL, 0, key);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolve", NULL, 0, key);
		zephir_check_call_status();
		RETURN_MM();
	}
}

PHP_METHOD(Yuga_Container_Container, getSingletons)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "instances");
}

PHP_METHOD(Yuga_Container_Container, isSingleton)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, binding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&binding);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	ZEPHIR_CALL_METHOD(&binding, this_ptr, "getbinding", NULL, 0, key);
	zephir_check_call_status();
	if (Z_TYPE_P(&binding) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

PHP_METHOD(Yuga_Container_Container, singletonResolved)
{
	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &key);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, key));
}

PHP_METHOD(Yuga_Container_Container, getSingletonInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "singletonresolved", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, key, PH_NOISY, "yuga/Container/Container.zep", 175);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Yuga_Container_Container, prepareObject)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *objectValue, objectValue_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&objectValue_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(objectValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &objectValue);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "issingleton", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_update_property_array(this_ptr, SL("instances"), key, objectValue);
	}
	RETVAL_ZVAL(objectValue, 1, 0);
	RETURN_MM();
}

PHP_METHOD(Yuga_Container_Container, resolve)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zval *key, key_sub, *arguments_param = NULL, classValue, _0, _2, objectValue;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&classValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&objectValue);
	ZVAL_UNDEF(&arguments);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &arguments_param);
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}


	ZEPHIR_CALL_METHOD(&classValue, this_ptr, "getbinding", NULL, 0, key);
	zephir_check_call_status();
	if (Z_TYPE_P(&classValue) == IS_NULL) {
		ZEPHIR_CPY_WRT(&classValue, key);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "issingleton", NULL, 0, key);
	zephir_check_call_status();
	_1 = zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "singletonresolved", NULL, 0, key);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsingletoninstance", NULL, 0, key);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&objectValue, this_ptr, "buildobject", NULL, 0, &classValue, &arguments);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "prepareobject", NULL, 0, key, &objectValue);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Container_Container, inSingletons)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classValue, classValue_sub, instanceObject, _0, _1, *_2, _3, _4$$3, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classValue_sub);
	ZVAL_UNDEF(&instanceObject);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(classValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classValue);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsingletons", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 3, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "yuga/Container/Container.zep", 215);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&instanceObject);
			ZVAL_COPY(&instanceObject, _2);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_get_class(&_4$$3, &instanceObject, 0);
			if (ZEPHIR_IS_EQUAL(&_4$$3, classValue)) {
				RETURN_CCTOR(&instanceObject);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&instanceObject, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				zephir_get_class(&_5$$5, &instanceObject, 0);
				if (ZEPHIR_IS_EQUAL(&_5$$5, classValue)) {
					RETURN_CCTOR(&instanceObject);
				}
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&instanceObject);
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Yuga_Container_Container, buildDependencies)
{
	zend_bool _9$$3, _29$$16;
	zval newDependencies;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_12 = NULL, *_14 = NULL, *_16 = NULL, *_17 = NULL, *_26 = NULL, *_32 = NULL, *_34 = NULL, *_36 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments, arguments_sub, *dependencies, dependencies_sub, *className, className_sub, dependency, name, *_0, _1, type$$3, _2$$3, _3$$3, _4$$3, _6$$8, _7$$8, _10$$9, _11$$9, _13$$9, paramInstance$$11, _15$$11, _18$$11, _19$$13, _20$$14, _21$$15, _22$$15, type$$16, _23$$16, _24$$16, _25$$16, _27$$21, _28$$21, _30$$22, _31$$22, _33$$22, paramInstance$$24, _35$$24, _37$$24, _38$$26, _39$$27, _40$$28, _41$$28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&dependencies_sub);
	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&dependency);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&type$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&paramInstance$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&type$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&paramInstance$$24);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_37$$24);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_39$$27);
	ZVAL_UNDEF(&_40$$28);
	ZVAL_UNDEF(&_41$$28);
	ZVAL_UNDEF(&newDependencies);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(arguments)
		Z_PARAM_ZVAL(dependencies)
		Z_PARAM_ZVAL(className)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &arguments, &dependencies, &className);
	ZEPHIR_SEPARATE_PARAM(arguments);


	ZEPHIR_INIT_VAR(&newDependencies);
	array_init(&newDependencies);
	zephir_is_iterable(dependencies, 0, "yuga/Container/Container.zep", 290);
	if (Z_TYPE_P(dependencies) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(dependencies), _0)
		{
			ZEPHIR_INIT_NVAR(&dependency);
			ZVAL_COPY(&dependency, _0);
			ZEPHIR_CALL_METHOD(&name, &dependency, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&type$$3, &dependency, "gettype", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_2$$3, &dependency, "isoptional", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_2$$3)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_3$$3, &dependency, "gettype", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&_3$$3) == IS_NULL) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_4$$3, &type$$3, "isbuiltin", &_5, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_4$$3)) {
				continue;
			}
			if (!(zephir_is_true(&type$$3))) {
				continue;
			}
			if (zephir_is_instance_of(&type$$3, SL("ReflectionUnionType"))) {
				ZEPHIR_INIT_NVAR(&_6$$8);
				object_init_ex(&_6$$8, zend_ce_exception);
				ZEPHIR_INIT_NVAR(&_7$$8);
				ZEPHIR_CONCAT_SVS(&_7$$8, "Failed to resolve class '", &dependency, "' because of a union type");
				ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", &_8, 5, &_7$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$8, "yuga/Container/Container.zep", 247);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_9$$3 = zephir_is_true(&type$$3);
			if (_9$$3) {
				_9$$3 = zephir_is_instance_of(&type$$3, SL("ReflectionNamedType"));
			}
			if (_9$$3) {
				ZEPHIR_INIT_NVAR(&_10$$9);
				zephir_get_class(&_10$$9, this_ptr, 0);
				ZEPHIR_CALL_METHOD(&_11$$9, &type$$3, "getname", &_12, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&_10$$9, &_11$$9)) {
					zephir_array_append(arguments, this_ptr, PH_SEPARATE, "yuga/Container/Container.zep", 254);
					continue;
				}
				ZEPHIR_CALL_METHOD(&_13$$9, &type$$3, "getname", &_14, 0);
				zephir_check_call_status();
				if (zephir_class_exists(&_13$$9, 1)) {
					ZEPHIR_CALL_METHOD(&_15$$11, &type$$3, "getname", &_16, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&paramInstance$$11, this_ptr, "resolve", &_17, 0, &_15$$11);
					zephir_check_call_status();
					zephir_array_update_zval(arguments, &name, &paramInstance$$11, PH_COPY | PH_SEPARATE);
					zephir_array_fetch(&_18$$11, arguments, &name, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 265);
					zephir_array_update_zval(&newDependencies, &name, &_18$$11, PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_CALL_METHOD(&name, &dependency, "getname", NULL, 0);
				zephir_check_call_status();
				if (zephir_array_key_exists(arguments, &name)) {
					zephir_array_fetch(&_19$$13, arguments, &name, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 276);
					zephir_array_update_zval(&newDependencies, &name, &_19$$13, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_CALL_METHOD(&_20$$14, &dependency, "isoptional", NULL, 0);
					zephir_check_call_status();
					if (!zephir_is_true(&_20$$14)) {
						ZEPHIR_INIT_NVAR(&_21$$15);
						object_init_ex(&_21$$15, zend_ce_exception);
						ZEPHIR_INIT_NVAR(&_22$$15);
						ZEPHIR_CONCAT_SVS(&_22$$15, "Class ", &name, " cannot be Instantiated");
						ZEPHIR_CALL_METHOD(NULL, &_21$$15, "__construct", &_8, 5, &_22$$15);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_21$$15, "yuga/Container/Container.zep", 281);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, dependencies, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, dependencies, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&dependency, dependencies, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&name, &dependency, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&type$$16, &dependency, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_23$$16, &dependency, "isoptional", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_23$$16)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_24$$16, &dependency, "gettype", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&_24$$16) == IS_NULL) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_25$$16, &type$$16, "isbuiltin", &_26, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_25$$16)) {
					continue;
				}
				if (!(zephir_is_true(&type$$16))) {
					continue;
				}
				if (zephir_is_instance_of(&type$$16, SL("ReflectionUnionType"))) {
					ZEPHIR_INIT_NVAR(&_27$$21);
					object_init_ex(&_27$$21, zend_ce_exception);
					ZEPHIR_INIT_NVAR(&_28$$21);
					ZEPHIR_CONCAT_SVS(&_28$$21, "Failed to resolve class '", &dependency, "' because of a union type");
					ZEPHIR_CALL_METHOD(NULL, &_27$$21, "__construct", &_8, 5, &_28$$21);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_27$$21, "yuga/Container/Container.zep", 247);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_29$$16 = zephir_is_true(&type$$16);
				if (_29$$16) {
					_29$$16 = zephir_is_instance_of(&type$$16, SL("ReflectionNamedType"));
				}
				if (_29$$16) {
					ZEPHIR_INIT_NVAR(&_30$$22);
					zephir_get_class(&_30$$22, this_ptr, 0);
					ZEPHIR_CALL_METHOD(&_31$$22, &type$$16, "getname", &_32, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_EQUAL(&_30$$22, &_31$$22)) {
						zephir_array_append(arguments, this_ptr, PH_SEPARATE, "yuga/Container/Container.zep", 254);
						continue;
					}
					ZEPHIR_CALL_METHOD(&_33$$22, &type$$16, "getname", &_34, 0);
					zephir_check_call_status();
					if (zephir_class_exists(&_33$$22, 1)) {
						ZEPHIR_CALL_METHOD(&_35$$24, &type$$16, "getname", &_36, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&paramInstance$$24, this_ptr, "resolve", &_17, 0, &_35$$24);
						zephir_check_call_status();
						zephir_array_update_zval(arguments, &name, &paramInstance$$24, PH_COPY | PH_SEPARATE);
						zephir_array_fetch(&_37$$24, arguments, &name, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 265);
						zephir_array_update_zval(&newDependencies, &name, &_37$$24, PH_COPY | PH_SEPARATE);
					}
				} else {
					ZEPHIR_CALL_METHOD(&name, &dependency, "getname", NULL, 0);
					zephir_check_call_status();
					if (zephir_array_key_exists(arguments, &name)) {
						zephir_array_fetch(&_38$$26, arguments, &name, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 276);
						zephir_array_update_zval(&newDependencies, &name, &_38$$26, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_CALL_METHOD(&_39$$27, &dependency, "isoptional", NULL, 0);
						zephir_check_call_status();
						if (!zephir_is_true(&_39$$27)) {
							ZEPHIR_INIT_NVAR(&_40$$28);
							object_init_ex(&_40$$28, zend_ce_exception);
							ZEPHIR_INIT_NVAR(&_41$$28);
							ZEPHIR_CONCAT_SVS(&_41$$28, "Class ", &name, " cannot be Instantiated");
							ZEPHIR_CALL_METHOD(NULL, &_40$$28, "__construct", &_8, 5, &_41$$28);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_40$$28, "yuga/Container/Container.zep", 281);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			ZEPHIR_CALL_METHOD(NULL, dependencies, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&dependency);
	RETVAL_ZVAL(arguments, 1, 0);
	RETURN_MM();
}

PHP_METHOD(Yuga_Container_Container, buildObject)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zval *classValue, classValue_sub, *arguments_param = NULL, objectValue, className, reflector, _0, _3, _1$$5, _2$$5, constructor$$6, dependencies$$6, _4$$6, _5$$6, _6$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classValue_sub);
	ZVAL_UNDEF(&objectValue);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&reflector);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&constructor$$6);
	ZVAL_UNDEF(&dependencies$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&arguments);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(classValue)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classValue, &arguments_param);
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}


	if (Z_TYPE_P(classValue) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&className);
		zephir_array_fetch_string(&className, classValue, SL("value"), PH_NOISY, "yuga/Container/Container.zep", 298);
	} else {
		ZEPHIR_CPY_WRT(&className, classValue);
	}
	ZEPHIR_INIT_VAR(&reflector);
	object_init_ex(&reflector, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflector, "__construct", NULL, 8, &className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &reflector, "isinstantiable", NULL, 16);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, yuga_container_support_classnotinstantiableexception_ce);
		ZEPHIR_INIT_VAR(&_2$$5);
		ZEPHIR_CONCAT_SVS(&_2$$5, "Class ", &className, " cannot be Instantiated");
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 5, &_2$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "yuga/Container/Container.zep", 306);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_3, &reflector, "getconstructor", NULL, 17);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&_3) == IS_NULL)) {
		ZEPHIR_CALL_METHOD(&constructor$$6, &reflector, "getconstructor", NULL, 17);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&dependencies$$6, &constructor$$6, "getparameters", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "builddependencies", NULL, 0, &arguments, &dependencies$$6, classValue);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&arguments, &_4$$6);
		zephir_read_property(&_5$$6, &reflector, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&objectValue);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&objectValue, &_5$$6, &arguments);
		zephir_check_call_status();
		RETURN_CCTOR(&objectValue);
	} else {
		zephir_read_property(&_6$$7, &reflector, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&objectValue);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&objectValue, &_6$$7);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&objectValue);
}

/**
 * Call the given Closure / class@method and inject its dependencies.
 *
 * @param  callable|string  callback
 * @param  array  parameters
 * @param  string|null  defaultMethod
 * @return mixed
 */
PHP_METHOD(Yuga_Container_Container, call)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *callback, callback_sub, *parameters_param = NULL, *defaultMethod = NULL, defaultMethod_sub, __$null, dependencies, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&defaultMethod_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(parameters)
		Z_PARAM_ZVAL_OR_NULL(defaultMethod)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &callback, &parameters_param, &defaultMethod);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}
	if (!defaultMethod) {
		defaultMethod = &defaultMethod_sub;
		defaultMethod = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "iscallablewithatsign", NULL, 0, callback);
	zephir_check_call_status();
	_1 = zephir_is_true(&_0);
	if (!(_1)) {
		_1 = zephir_is_true(defaultMethod);
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callclass", NULL, 0, callback, &parameters, defaultMethod);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&dependencies, this_ptr, "getmethoddependencies", NULL, 0, callback, &parameters);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, callback, &dependencies);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Call a string reference to a class using Class@method syntax.
 *
 * @param  string  target
 * @param  array  parameters
 * @param  string|null  defaultMethod
 * @return mixed
 */
PHP_METHOD(Yuga_Container_Container, callClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters, _1;
	zval *target, target_sub, *parameters_param = NULL, *defaultMethod = NULL, defaultMethod_sub, __$null, method, segments, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&target_sub);
	ZVAL_UNDEF(&defaultMethod_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(target)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(parameters)
		Z_PARAM_ZVAL_OR_NULL(defaultMethod)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &target, &parameters_param, &defaultMethod);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}
	if (!defaultMethod) {
		defaultMethod = &defaultMethod_sub;
		defaultMethod = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "@");
	ZEPHIR_INIT_VAR(&segments);
	zephir_fast_explode(&segments, &_0, target, LONG_MAX);
	ZEPHIR_CPY_WRT(&method, defaultMethod);
	if (zephir_fast_count_int(&segments) == 2) {
		ZEPHIR_OBS_NVAR(&method);
		zephir_array_fetch_long(&method, &segments, 1, PH_NOISY, "yuga/Container/Container.zep", 369);
	}
	if (Z_TYPE_P(&method) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Method not provided.", "yuga/Container/Container.zep", 373);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_fetch_long(&_3, &segments, 0, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 376);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "buildobject", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_fast_append(&_1, &_2);
	zephir_array_fast_append(&_1, &method);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "call", NULL, 0, &_1, &parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Determine if the given string is in Class@method syntax.
 *
 * @param  mixed  callback
 * @return bool
 */
PHP_METHOD(Yuga_Container_Container, isCallableWithAtSign)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *callback, callback_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);


	if (!(Z_TYPE_P(callback) == IS_STRING)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "@");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, callback, &_0, 0 );
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE(&_1));
}

/**
 * Get all dependencies for a given method.
 *
 * @param  callable|string  callback
 * @param  array  parameters
 * @return array
 */
PHP_METHOD(Yuga_Container_Container, getMethodDependencies)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *callback, callback_sub, *parameters_param = NULL, dependencies, key, parameter, reflector, _0, *_1, _2, _5$$3, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&reflector);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&parameters);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &parameters_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&dependencies);
	array_init(&dependencies);
	ZEPHIR_CALL_METHOD(&reflector, this_ptr, "getcallreflector", NULL, 0, callback);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &reflector, "getparameters", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "yuga/Container/Container.zep", 413);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&parameter);
			ZVAL_COPY(&parameter, _1);
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "adddependencyforcallparameter", &_6, 0, &parameter, &parameters, &dependencies);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&dependencies, &_5$$3);
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
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameter, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "adddependencyforcallparameter", &_6, 0, &parameter, &parameters, &dependencies);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&dependencies, &_7$$4);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&parameter);
	ZEPHIR_INIT_NVAR(&key);
	zephir_fast_array_merge(return_value, &dependencies, &parameters);
	RETURN_MM();
}

/**
 * Get the proper reflection instance for the given callback.
 *
 * @param  callable|string  callback
 * @return \ReflectionFunctionAbstract
 */
PHP_METHOD(Yuga_Container_Container, getCallReflector)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback = NULL, callback_sub, _1, _2, _3$$3, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);
	ZEPHIR_SEPARATE_PARAM(callback);


	_0 = Z_TYPE_P(callback) == IS_STRING;
	if (_0) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_STRING(&_1, "::");
		ZEPHIR_INIT_VAR(&_2);
		zephir_fast_strpos(&_2, callback, &_1, 0 );
		_0 = !ZEPHIR_IS_FALSE(&_2);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_fast_explode_str(&_3$$3, SL("::"), callback, LONG_MAX);
		ZEPHIR_CPY_WRT(callback, &_3$$3);
	}
	if (Z_TYPE_P(callback) == IS_ARRAY) {
		object_init_ex(return_value, zephir_get_internal_ce(SL("reflectionmethod")));
		zephir_array_fetch_long(&_4$$4, callback, 0, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 429);
		zephir_array_fetch_long(&_5$$4, callback, 1, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 429);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 18, &_4$$4, &_5$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, zephir_get_internal_ce(SL("reflectionfunction")));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, callback);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the dependency for the given call parameter.
 *
 * @param  \ReflectionParameter  $parameter
 * @param  array  parameters
 * @param  array  dependencies
 * @return mixed
 */
PHP_METHOD(Yuga_Container_Container, addDependencyForCallParameter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *parameter, parameter_sub, *parameters_param = NULL, *dependencies, dependencies_sub, _0, _1, _2, _3$$3, _4$$3, _5$$3, classValue$$4, _6$$4, _7$$4, _8$$4, _9$$6, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameter_sub);
	ZVAL_UNDEF(&dependencies_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&classValue$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&parameters);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(parameter, zephir_get_internal_ce(SL("reflectionparameter")))
		Z_PARAM_ARRAY(parameters)
		Z_PARAM_ZVAL(dependencies)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &parameter, &parameters_param, &dependencies);
	zephir_get_arrval(&parameters, parameters_param);
	ZEPHIR_SEPARATE_PARAM(dependencies);


	zephir_read_property(&_0, parameter, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, parameter, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, parameter, "isdefaultvalueavailable", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_key_exists(&parameters, &_0)) {
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_read_property(&_4$$3, parameter, ZEND_STRL("name"), PH_NOISY_CC);
		zephir_array_fetch(&_3$$3, &parameters, &_4$$3, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 446);
		zephir_array_append(dependencies, &_3$$3, PH_SEPARATE, "yuga/Container/Container.zep", 446);
		zephir_read_property(&_5$$3, parameter, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&parameters, &_5$$3, PH_SEPARATE);
	} else if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD(&_6$$4, parameter, "gettype", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_6$$4)) {
			ZEPHIR_CALL_METHOD(&_7$$4, parameter, "gettype", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&classValue$$4, &_7$$4, "getname", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&classValue$$4);
			ZVAL_NULL(&classValue$$4);
		}
		ZEPHIR_CALL_METHOD(&_8$$4, parameter, "isoptional", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_8$$4))) {
			if (!(Z_TYPE_P(&classValue$$4) == IS_NULL)) {
				ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "buildobject", NULL, 0, &classValue$$4);
				zephir_check_call_status();
				zephir_array_append(dependencies, &_9$$6, PH_SEPARATE, "yuga/Container/Container.zep", 454);
			}
		}
	} else if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_10$$7, parameter, "getdefaultvalue", NULL, 0);
		zephir_check_call_status();
		zephir_array_append(dependencies, &_10$$7, PH_SEPARATE, "yuga/Container/Container.zep", 458);
	}
	RETVAL_ZVAL(dependencies, 1, 0);
	RETURN_MM();
}

zend_object *zephir_init_properties_Yuga_Container_Container(zend_class_entry *class_type)
{
		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("resolved"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("resolved"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("instances"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindings"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

void zephir_init_static_properties_Yuga_Container_Container()
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(yuga_container_container_ce, ZEND_STRL("thisInstances"), &_0);
	ZEPHIR_MM_RESTORE();
}

