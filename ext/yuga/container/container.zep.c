
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
	zval _3$$4, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *value, value_sub, *singleton = NULL, singleton_sub, __$false, _0, _1, _2$$4, _4$$3, _6$$5, _7$$5, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&singleton_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$3);
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
		ZVAL_STRING(&_6$$5, "value");
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "singleton");
		ZEPHIR_CALL_FUNCTION(&_8$$5, "compact", NULL, 1, &_6$$5, &_7$$5);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("bindings"), key, &_8$$5);
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
	zval *key = NULL, key_sub, _0, _1, _2, _3, _4, _5, _6$$4, _7$$4, _8$$5, _9$$5, _10$$6, _11$$6, _12$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
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
	zephir_read_property(&_2, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_5);
	zephir_array_fetch(&_5, &_4, key, PH_NOISY, "yuga/Container/Container.zep", 106);
	if (!(zephir_array_key_exists(&_2, key))) {
		RETURN_MM_NULL();
	} else if (zephir_array_key_exists(&_3, key)) {
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_7$$4, &_6$$4, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 105);
		RETURN_CTOR(&_7$$4);
	} else if (zephir_is_instance_of(&_5, SL("Closure"))) {
		zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_9$$5, &_8$$5, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 107);
		RETURN_CTOR(&_9$$5);
	} else {
		zephir_read_property(&_10$$6, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_11$$6, &_10$$6, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 109);
		zephir_array_fetch_string(&_12$$6, &_11$$6, SL("value"), PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 109);
		RETURN_CTOR(&_12$$6);
	}
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
	zephir_array_fetch(&_2, &_1, key, PH_NOISY, "yuga/Container/Container.zep", 127);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 129);
	_5 = Z_TYPE_P(&_4) == IS_STRING;
	if (_5) {
		zephir_read_property(&_6, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_7, &_6, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 129);
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_STRING(&_8, "/");
		ZEPHIR_INIT_VAR(&_9);
		zephir_fast_strpos(&_9, &_7, &_8, 0 );
		_5 = !ZEPHIR_IS_FALSE(&_9);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_11, &_10, key, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 131);
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
		zephir_array_fetch(&_0, &_2, key, PH_NOISY, "yuga/Container/Container.zep", 161);
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
	zval *key, key_sub, *arguments_param = NULL, classVar, _0, _2, objectVar;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&classVar);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&objectVar);
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


	ZEPHIR_CALL_METHOD(&classVar, this_ptr, "getbinding", NULL, 0, key);
	zephir_check_call_status();
	if (Z_TYPE_P(&classVar) == IS_NULL) {
		ZEPHIR_CPY_WRT(&classVar, key);
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
	ZEPHIR_CALL_METHOD(&objectVar, this_ptr, "buildobject", NULL, 0, &classVar, &arguments);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "prepareobject", NULL, 0, key, &objectVar);
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
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 2, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "yuga/Container/Container.zep", 198);
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
	zend_bool _9$$3, _26$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_12 = NULL, *_14 = NULL, *_15 = NULL, *_23 = NULL, *_29 = NULL, *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments, arguments_sub, *dependencies, dependencies_sub, *className, className_sub, dependency, *_0, _1, name$$3, type$$3, _2$$3, _3$$3, _4$$3, _6$$8, _7$$8, _10$$9, _11$$9, paramInstance$$9, _13$$9, _16$$12, _17$$13, _18$$14, _19$$14, name$$15, type$$15, _20$$15, _21$$15, _22$$15, _24$$20, _25$$20, _27$$21, _28$$21, paramInstance$$21, _30$$21, _32$$24, _33$$25, _34$$26, _35$$26;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&dependencies_sub);
	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&dependency);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name$$3);
	ZVAL_UNDEF(&type$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&paramInstance$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&name$$15);
	ZVAL_UNDEF(&type$$15);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&paramInstance$$21);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_32$$24);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_34$$26);
	ZVAL_UNDEF(&_35$$26);
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
	ZEPHIR_SEPARATE_PARAM(dependencies);


	zephir_is_iterable(dependencies, 1, "yuga/Container/Container.zep", 264);
	if (Z_TYPE_P(dependencies) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(dependencies), _0)
		{
			ZEPHIR_INIT_NVAR(&dependency);
			ZVAL_COPY(&dependency, _0);
			ZEPHIR_CALL_METHOD(&name$$3, &dependency, "getname", NULL, 0);
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
			if (zephir_is_instance_of(&type$$3, SL("Yuga\\Container\\ReflectionUnionType"))) {
				ZEPHIR_INIT_NVAR(&_6$$8);
				object_init_ex(&_6$$8, zend_ce_exception);
				ZEPHIR_INIT_NVAR(&_7$$8);
				ZEPHIR_CONCAT_SVS(&_7$$8, "Failed to resolve class '", &dependency, "' because of a union type");
				ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", &_8, 3, &_7$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$8, "yuga/Container/Container.zep", 227);
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
				if (ZEPHIR_IS_IDENTICAL(&_10$$9, &_11$$9)) {
					zephir_array_append(arguments, this_ptr, PH_SEPARATE, "yuga/Container/Container.zep", 233);
					continue;
				}
				ZEPHIR_CALL_METHOD(&_13$$9, &type$$3, "getname", &_14, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&paramInstance$$9, this_ptr, "resolve", &_15, 0, &_13$$9);
				zephir_check_call_status();
				zephir_array_append(arguments, &paramInstance$$9, PH_SEPARATE, "yuga/Container/Container.zep", 240);
			} else {
				ZEPHIR_CALL_METHOD(&name$$3, &dependency, "getname", NULL, 0);
				zephir_check_call_status();
				if (zephir_array_key_exists(arguments, &name$$3)) {
					zephir_array_fetch(&_16$$12, arguments, &name$$3, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 250);
					zephir_array_append(dependencies, &_16$$12, PH_SEPARATE, "yuga/Container/Container.zep", 250);
				} else {
					ZEPHIR_CALL_METHOD(&_17$$13, &dependency, "isoptional", NULL, 0);
					zephir_check_call_status();
					if (!zephir_is_true(&_17$$13)) {
						ZEPHIR_INIT_NVAR(&_18$$14);
						object_init_ex(&_18$$14, zend_ce_exception);
						ZEPHIR_INIT_NVAR(&_19$$14);
						ZEPHIR_CONCAT_SVS(&_19$$14, "Class ", &name$$3, " cannot be Instantiated");
						ZEPHIR_CALL_METHOD(NULL, &_18$$14, "__construct", &_8, 3, &_19$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_18$$14, "yuga/Container/Container.zep", 255);
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
				ZEPHIR_CALL_METHOD(&name$$15, &dependency, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&type$$15, &dependency, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_20$$15, &dependency, "isoptional", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_20$$15)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_21$$15, &dependency, "gettype", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&_21$$15) == IS_NULL) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_22$$15, &type$$15, "isbuiltin", &_23, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_22$$15)) {
					continue;
				}
				if (!(zephir_is_true(&type$$15))) {
					continue;
				}
				if (zephir_is_instance_of(&type$$15, SL("Yuga\\Container\\ReflectionUnionType"))) {
					ZEPHIR_INIT_NVAR(&_24$$20);
					object_init_ex(&_24$$20, zend_ce_exception);
					ZEPHIR_INIT_NVAR(&_25$$20);
					ZEPHIR_CONCAT_SVS(&_25$$20, "Failed to resolve class '", &dependency, "' because of a union type");
					ZEPHIR_CALL_METHOD(NULL, &_24$$20, "__construct", &_8, 3, &_25$$20);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_24$$20, "yuga/Container/Container.zep", 227);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_26$$15 = zephir_is_true(&type$$15);
				if (_26$$15) {
					_26$$15 = zephir_is_instance_of(&type$$15, SL("ReflectionNamedType"));
				}
				if (_26$$15) {
					ZEPHIR_INIT_NVAR(&_27$$21);
					zephir_get_class(&_27$$21, this_ptr, 0);
					ZEPHIR_CALL_METHOD(&_28$$21, &type$$15, "getname", &_29, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_IDENTICAL(&_27$$21, &_28$$21)) {
						zephir_array_append(arguments, this_ptr, PH_SEPARATE, "yuga/Container/Container.zep", 233);
						continue;
					}
					ZEPHIR_CALL_METHOD(&_30$$21, &type$$15, "getname", &_31, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&paramInstance$$21, this_ptr, "resolve", &_15, 0, &_30$$21);
					zephir_check_call_status();
					zephir_array_append(arguments, &paramInstance$$21, PH_SEPARATE, "yuga/Container/Container.zep", 240);
				} else {
					ZEPHIR_CALL_METHOD(&name$$15, &dependency, "getname", NULL, 0);
					zephir_check_call_status();
					if (zephir_array_key_exists(arguments, &name$$15)) {
						zephir_array_fetch(&_32$$24, arguments, &name$$15, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 250);
						zephir_array_append(dependencies, &_32$$24, PH_SEPARATE, "yuga/Container/Container.zep", 250);
					} else {
						ZEPHIR_CALL_METHOD(&_33$$25, &dependency, "isoptional", NULL, 0);
						zephir_check_call_status();
						if (!zephir_is_true(&_33$$25)) {
							ZEPHIR_INIT_NVAR(&_34$$26);
							object_init_ex(&_34$$26, zend_ce_exception);
							ZEPHIR_INIT_NVAR(&_35$$26);
							ZEPHIR_CONCAT_SVS(&_35$$26, "Class ", &name$$15, " cannot be Instantiated");
							ZEPHIR_CALL_METHOD(NULL, &_34$$26, "__construct", &_8, 3, &_35$$26);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_34$$26, "yuga/Container/Container.zep", 255);
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
	zend_class_entry *_5$$7 = NULL;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zval *classValue, classValue_sub, *arguments_param = NULL, objectValue, className, reflector, newObject, _0, _3, _1$$5, _2$$5, constructor$$6, dependencies$$6, _4$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classValue_sub);
	ZVAL_UNDEF(&objectValue);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&reflector);
	ZVAL_UNDEF(&newObject);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&constructor$$6);
	ZVAL_UNDEF(&dependencies$$6);
	ZVAL_UNDEF(&_4$$6);
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
		zephir_array_fetch_string(&className, classValue, SL("value"), PH_NOISY, "yuga/Container/Container.zep", 271);
	} else {
		ZEPHIR_CPY_WRT(&className, classValue);
	}
	ZEPHIR_INIT_VAR(&reflector);
	object_init_ex(&reflector, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflector, "__construct", NULL, 4, &className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &reflector, "isinstantiable", NULL, 5);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, yuga_container_support_classnotinstantiableexception_ce);
		ZEPHIR_INIT_VAR(&_2$$5);
		ZEPHIR_CONCAT_SVS(&_2$$5, "Class ", &className, " cannot be Instantiated");
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 3, &_2$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "yuga/Container/Container.zep", 279);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_3, &reflector, "getconstructor", NULL, 6);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&_3) == IS_NULL)) {
		ZEPHIR_CALL_METHOD(&constructor$$6, &reflector, "getconstructor", NULL, 6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&dependencies$$6, &constructor$$6, "getparameters", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "builddependencies", NULL, 0, &arguments, &dependencies$$6, classValue);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&arguments, &_4$$6);
		ZEPHIR_CALL_METHOD(&objectValue, &reflector, "newinstanceargs", NULL, 7, &arguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&newObject);
		if (!_5$$7) {
		_5$$7 = zephir_fetch_class_str_ex(SL("Yuga\\Container\\reflector"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&newObject, _5$$7);
		if (zephir_has_constructor(&newObject)) {
			ZEPHIR_CALL_METHOD(NULL, &newObject, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_OBS_NVAR(&objectValue);
		zephir_read_property(&objectValue, &newObject, ZEND_STRL("name"), PH_NOISY_CC);
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
		zephir_array_fetch_long(&method, &segments, 1, PH_NOISY, "yuga/Container/Container.zep", 336);
	}
	if (Z_TYPE_P(&method) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Method not provided.", "yuga/Container/Container.zep", 340);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_fetch_long(&_3, &segments, 0, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 343);
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
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *callback, callback_sub, *parameters_param = NULL, dependencies, key, parameter, reflector, _0, *_1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&reflector);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
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
	zephir_is_iterable(&_0, 0, "yuga/Container/Container.zep", 380);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddependencyforcallparameter", &_5, 0, &parameter, &parameters, &dependencies);
			zephir_check_call_status();
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
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "adddependencyforcallparameter", &_5, 0, &parameter, &parameters, &dependencies);
				zephir_check_call_status();
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
		zephir_array_fetch_long(&_4$$4, callback, 0, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 396);
		zephir_array_fetch_long(&_5$$4, callback, 1, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 396);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 8, &_4$$4, &_5$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, zephir_get_internal_ce(SL("reflectionfunction")));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, callback);
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
	zval *parameter, parameter_sub, *parameters_param = NULL, *dependencies, dependencies_sub, _0, _1, _2, _3$$3, _4$$3, _5$$3, classValue$$4, _6$$4, _7$$4, _8$$4, _9$$5, _10$$6, _11$$7;
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
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
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
		zephir_array_fetch(&_3$$3, &parameters, &_4$$3, PH_NOISY | PH_READONLY, "yuga/Container/Container.zep", 413);
		zephir_array_append(dependencies, &_3$$3, PH_SEPARATE, "yuga/Container/Container.zep", 413);
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
			ZEPHIR_CALL_FUNCTION(&_9$$5, "\is_null", NULL, 10, &classValue$$4);
			zephir_check_call_status();
			if (!(zephir_is_true(&_9$$5))) {
				ZEPHIR_CALL_METHOD(&_10$$6, this_ptr, "buildobject", NULL, 0, &classValue$$4);
				zephir_check_call_status();
				zephir_array_append(dependencies, &_10$$6, PH_SEPARATE, "yuga/Container/Container.zep", 421);
			}
		}
	} else if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_11$$7, parameter, "getdefaultvalue", NULL, 0);
		zephir_check_call_status();
		zephir_array_append(dependencies, &_11$$7, PH_SEPARATE, "yuga/Container/Container.zep", 425);
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

