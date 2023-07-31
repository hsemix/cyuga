
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yuga_Events_Dispatcher_Dispatcher)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Events\\Dispatcher, Dispatcher, yuga, events_dispatcher_dispatcher, yuga_events_dispatcher_dispatcher_method_entry, 0);

	/**
	 * @var string event name
	 */
	zend_declare_property_null(yuga_events_dispatcher_dispatcher_ce, SL("name"), ZEND_ACC_PROTECTED);
	/**
	 * @var array the event parameters
	 */
	zend_declare_property_null(yuga_events_dispatcher_dispatcher_ce, SL("params"), ZEND_ACC_PROTECTED);
	/**
	 * @var array list of attributes
	 */
	zend_declare_property_null(yuga_events_dispatcher_dispatcher_ce, SL("attributes"), ZEND_ACC_PRIVATE);
	/**
	 * The event instance is to be stored in this variable
	 *
	 * @var \Yuga\Events\Dispatcher\Dispatcher
	 */
	zend_declare_property_null(yuga_events_dispatcher_dispatcher_ce, SL("event"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	yuga_events_dispatcher_dispatcher_ce->create_object = zephir_init_properties_Yuga_Events_Dispatcher_Dispatcher;

	return SUCCESS;
}

PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, *params = NULL, params_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name, &params);
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}


	if (zephir_is_true(name)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setname", NULL, 0, name);
		zephir_check_call_status();
	}
	if (zephir_is_true(params)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparams", NULL, 0, params);
		zephir_check_call_status();
	}
	zephir_read_static_property_ce(&_0, yuga_events_dispatcher_dispatcher_ce, SL("event"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_update_static_property_ce(yuga_events_dispatcher_dispatcher_ce, ZEND_STRL("event"), this_ptr);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Get event name
 *
 * @return string|null
 */
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Overwrites parameters
 *
 * @param  array|object params
 *
 * @return void
 * @throws EventException
 */
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, setParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params, params_sub, _0$$3, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params);


	if (!(Z_TYPE_P(params) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, yuga_events_exceptions_eventexception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_gettype(&_1$$3, params);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Event parameters must be an array; received `", &_1$$3, "`");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 2, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "yuga/Events/Dispatcher/Dispatcher.zep", 68);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("params"), params);
	ZEPHIR_MM_RESTORE();
}

/**
 * Get all parameters
 *
 * @return array|object
 */
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, getParams)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "params");
}

/**
 * Get an individual parameter
 *
 * If the parameter does not exist, the default value will be returned.
 *
 * @param  string|int name
 * @param  mixed      default
 *
 * @return mixed
 */
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, getParam)
{
	zval *name, name_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1$$3, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 1, &name, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_1$$3, name)) {
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_3$$4, &_2$$4, name, PH_NOISY | PH_READONLY, "yuga/Events/Dispatcher/Dispatcher.zep", 100);
			RETURN_CTORW(&_3$$4);
		}
		RETVAL_ZVAL(defaultValue, 1, 0);
		return;
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;
}

/**
 * Set the event name
 *
 * @param  string name
 *
 * @return void
 */
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, setName)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	zephir_cast_to_string(&_0, name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &_0);
	RETURN_THIS();
}

/**
 * Set an individual parameter to a value
 *
 * @param  string|int name
 * @param  mixed      value
 *
 * @return void
 */
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, setParam)
{
	zval *name, name_sub, *value, value_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &name, &value);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		zephir_update_property_array(this_ptr, SL("params"), name, value);
	}
}

PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, __get)
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getattribute", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set a variable and make an object point to it
 */
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, __set)
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setattribute", NULL, 0, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, setAttribute)
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


	zephir_update_property_array(this_ptr, SL("attributes"), key, value);
	RETURN_THISW();
}

/**
 * Get an attribute from the event.
 *
 * @param  string  key
 * @return mixed
 */
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, getAttribute)
{
	zval *name, name_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &name);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, name, PH_NOISY | PH_READONLY, "yuga/Events/Dispatcher/Dispatcher.zep", 165);
	RETURN_CTORW(&_1);
}

PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, setAttributes)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, key, value, *_0, _1;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	zephir_is_iterable(&attributes, 0, "yuga/Events/Dispatcher/Dispatcher.zep", 176);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			zephir_update_property_array(this_ptr, SL("attributes"), &key, &value);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("attributes"), &key, &value);
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();
}

/**
 * Return a static instance of the event instance throught the entire application
 * 
 * @param null
 * 
 * @return \Yuga\Events\Dispatcher\Dispatcher
 */
PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, getInstance)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_static_property_ce(&_0, yuga_events_dispatcher_dispatcher_ce, SL("event"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);
}

PHP_METHOD(Yuga_Events_Dispatcher_Dispatcher, __call)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, *parameters, parameters_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method, &parameters);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "dispatcher");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getattribute", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Yuga_Events_Dispatcher_Dispatcher(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

