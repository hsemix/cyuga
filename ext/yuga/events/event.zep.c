
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
#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Yuga_Events_Event)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Events, Event, yuga, events_event, yuga_events_event_method_entry, 0);

	/**
	 * @var array list of attributes
	 */
	zend_declare_property_null(yuga_events_event_ce, SL("attributes"), ZEND_ACC_PRIVATE);
	/**
	 * @var array list of listeners
	 */
	zend_declare_property_null(yuga_events_event_ce, SL("listeners"), ZEND_ACC_PROTECTED);
	/**
	 * @var string name of the default events
	 */
	zend_declare_property_string(yuga_events_event_ce, SL("name"), "yuga.auto.events", ZEND_ACC_PROTECTED);
	yuga_events_event_ce->create_object = zephir_init_properties_Yuga_Events_Event;

	zend_class_implements(yuga_events_event_ce, 1, yuga_interfaces_events_dispatcherinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Events_Event, __get)
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
PHP_METHOD(Yuga_Events_Event, __set)
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

PHP_METHOD(Yuga_Events_Event, setAttribute)
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
PHP_METHOD(Yuga_Events_Event, getAttribute)
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
	zephir_array_fetch(&_1, &_0, name, PH_NOISY | PH_READONLY, "yuga/Events/Event.zep", 53);
	RETURN_CTORW(&_1);
}

/**
 * Attach callback to event
 *
 * @param  string   eventName
 * @param  callable callback|null
 * @param  int  priority
 *
 * @return void
 */
PHP_METHOD(Yuga_Events_Event, attach)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName = NULL, eventName_sub, *callback = NULL, callback_sub, *priority = NULL, priority_sub, __$null, args, _0$$4, _1$$6, _3$$6, _4$$6, _2$$7, _5$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&priority_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_5$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(callback)
		Z_PARAM_ZVAL(priority)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &eventName, &callback, &priority);
	ZEPHIR_SEPARATE_PARAM(eventName);
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}
	if (!priority) {
		priority = &priority_sub;
		ZEPHIR_INIT_VAR(priority);
		ZVAL_LONG(priority, 1);
	}


	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	if (!(Z_TYPE_P(eventName) == IS_STRING)) {
		if (zephir_instance_of_ev(eventName, yuga_events_dispatcher_dispatcher_ce)) {
			ZEPHIR_CALL_METHOD(&_0$$4, eventName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(eventName, &_0$$4);
		}
	}
	if (zephir_fast_count_int(&args) == 1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "triggerobjecthandlers", NULL, 0, eventName);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_1$$6, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_1$$6, eventName))) {
			ZEPHIR_INIT_VAR(&_2$$7);
			array_init(&_2$$7);
			zephir_update_property_array(this_ptr, SL("listeners"), eventName, &_2$$7);
		}
		zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$6, &_3$$6, eventName, PH_READONLY, "yuga/Events/Event.zep", 81);
		if (!(zephir_array_isset(&_4$$6, priority))) {
			ZEPHIR_INIT_VAR(&_5$$8);
			array_init(&_5$$8);
			zephir_update_property_array_multi(this_ptr, SL("listeners"), &_5$$8, SL("zz"), 2, eventName, priority);
		}
		zephir_update_property_array_multi(this_ptr, SL("listeners"), callback, SL("zza"), 3, eventName, priority);
	}
	RETURN_THIS();
}

/**
 * Allias to the attach method
 *
 * @param  string   eventName
 * @param  callable callback|null
 * @param  int  priority
 *
 * @return void
 */
PHP_METHOD(Yuga_Events_Event, on)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName, eventName_sub, *callback = NULL, callback_sub, *priority = NULL, priority_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&priority_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(callback)
		Z_PARAM_ZVAL(priority)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &eventName, &callback, &priority);
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}
	if (!priority) {
		priority = &priority_sub;
		ZEPHIR_INIT_VAR(priority);
		ZVAL_LONG(priority, 1);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "attach", NULL, 0, eventName, callback, priority);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Some times the name provided in the attach method might be an instance of the HandlerInterface
 * When that happens, Make sure the event has the handle method
 * 
 * @param array|string handlers
 * 
 * @return void
 */
PHP_METHOD(Yuga_Events_Event, triggerObjectHandlers)
{
	zval _18, _6$$4, _12$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handlers, handlers_sub, handler, _19, _20, *_0$$3, _1$$3, _2$$5, _3$$5, _4$$5, _7$$4, _8$$4, _9$$7, _10$$7, _11$$7, _13$$6, _14$$6, _15$$8, _16$$8, _17$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlers_sub);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_12$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handlers)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &handlers);


	if (Z_TYPE_P(handlers) == IS_ARRAY) {
		zephir_is_iterable(handlers, 0, "yuga/Events/Event.zep", 122);
		if (Z_TYPE_P(handlers) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(handlers), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&handler);
				ZVAL_COPY(&handler, _0$$3);
				if (!((zephir_method_exists_ex(&handler, ZEND_STRL("handle")) == SUCCESS))) {
					ZEPHIR_INIT_NVAR(&_2$$5);
					object_init_ex(&_2$$5, yuga_events_exceptions_eventexception_ce);
					ZEPHIR_INIT_NVAR(&_3$$5);
					zephir_get_class(&_3$$5, &handler, 0);
					ZEPHIR_INIT_NVAR(&_4$$5);
					ZEPHIR_CONCAT_VS(&_4$$5, &_3$$5, " must implement the `handle` method");
					ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", &_5, 2, &_4$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_2$$5, "yuga/Events/Event.zep", 118);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_create_array(&_6$$4, 2, 0);
				zephir_array_fast_append(&_6$$4, &handler);
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_STRING(&_7$$4, "handle");
				zephir_array_fast_append(&_6$$4, &_7$$4);
				ZEPHIR_OBS_NVAR(&_8$$4);
				zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("name"), PH_NOISY_CC);
				zephir_update_property_array_multi(this_ptr, SL("listeners"), &_6$$4, SL("zla"), 3, &_8$$4, 1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, handlers, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, handlers, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&handler, handlers, "current", NULL, 0);
				zephir_check_call_status();
					if (!((zephir_method_exists_ex(&handler, ZEND_STRL("handle")) == SUCCESS))) {
						ZEPHIR_INIT_NVAR(&_9$$7);
						object_init_ex(&_9$$7, yuga_events_exceptions_eventexception_ce);
						ZEPHIR_INIT_NVAR(&_10$$7);
						zephir_get_class(&_10$$7, &handler, 0);
						ZEPHIR_INIT_NVAR(&_11$$7);
						ZEPHIR_CONCAT_VS(&_11$$7, &_10$$7, " must implement the `handle` method");
						ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", &_5, 2, &_11$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$7, "yuga/Events/Event.zep", 118);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_12$$6);
					zephir_create_array(&_12$$6, 2, 0);
					zephir_array_fast_append(&_12$$6, &handler);
					ZEPHIR_INIT_NVAR(&_13$$6);
					ZVAL_STRING(&_13$$6, "handle");
					zephir_array_fast_append(&_12$$6, &_13$$6);
					ZEPHIR_OBS_NVAR(&_14$$6);
					zephir_read_property(&_14$$6, this_ptr, ZEND_STRL("name"), PH_NOISY_CC);
					zephir_update_property_array_multi(this_ptr, SL("listeners"), &_12$$6, SL("zla"), 3, &_14$$6, 1);
				ZEPHIR_CALL_METHOD(NULL, handlers, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&handler);
		RETURN_MM_NULL();
	}
	if (!((zephir_method_exists_ex(handlers, ZEND_STRL("handle")) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_15$$8);
		object_init_ex(&_15$$8, yuga_events_exceptions_eventexception_ce);
		ZEPHIR_INIT_VAR(&_16$$8);
		zephir_get_class(&_16$$8, handlers, 0);
		ZEPHIR_INIT_VAR(&_17$$8);
		ZEPHIR_CONCAT_VS(&_17$$8, &_16$$8, " must implement the `handle` method");
		ZEPHIR_CALL_METHOD(NULL, &_15$$8, "__construct", &_5, 2, &_17$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_15$$8, "yuga/Events/Event.zep", 125);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 2, 0);
	zephir_array_fast_append(&_18, handlers);
	ZEPHIR_INIT_VAR(&_19);
	ZVAL_STRING(&_19, "handle");
	zephir_array_fast_append(&_18, &_19);
	ZEPHIR_OBS_VAR(&_20);
	zephir_read_property(&_20, this_ptr, ZEND_STRL("name"), PH_NOISY_CC);
	zephir_update_property_array_multi(this_ptr, SL("listeners"), &_18, SL("zla"), 3, &_20, 1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Dispatch event
 *
 * @param  string|Event  event
 * @param  array  parameters
 *
 * @return Event event
 */
PHP_METHOD(Yuga_Events_Event, dispatch)
{
	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event = NULL, event_sub, *parameters = NULL, parameters_sub, *callback = NULL, callback_sub, __$null, params, eventObject, _0, _1, _2, paramValue, _4, _5, _15, _16, items$$3, eventNamespace$$8, _6$$8, _7$$8, _8$$8, _9$$8, _10$$8, _11$$8, _12$$9, _13$$9, _17$$10, _18$$10, _19$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&eventObject);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&items$$3);
	ZVAL_UNDEF(&eventNamespace$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(event)
		Z_PARAM_ZVAL_OR_NULL(parameters)
		Z_PARAM_ZVAL_OR_NULL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &event, &parameters, &callback);
	if (!event) {
		event = &event_sub;
		ZEPHIR_CPY_WRT(event, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(event);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!callback) {
		callback = &callback_sub;
		ZEPHIR_CPY_WRT(callback, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(callback);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	if (zephir_fast_count_int(&_0) == 2) {
		ZEPHIR_CALL_METHOD(&items$$3, this_ptr, "getparameters", NULL, 0, parameters);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&params);
		zephir_array_fetch_string(&params, &items$$3, SL("params"), PH_NOISY, "yuga/Events/Event.zep", 147);
		ZEPHIR_OBS_NVAR(callback);
		zephir_array_fetch_string(callback, &items$$3, SL("callback"), PH_NOISY, "yuga/Events/Event.zep", 148);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	if (!zephir_is_true(event)) {
		ZEPHIR_OBS_NVAR(event);
		zephir_read_property(event, this_ptr, ZEND_STRL("name"), PH_NOISY_CC);
	}
	ZEPHIR_CPY_WRT(&eventObject, event);
	if (Z_TYPE_P(event) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&eventObject);
		object_init_ex(&eventObject, yuga_events_dispatcher_dispatcher_ce);
		ZEPHIR_CALL_METHOD(NULL, &eventObject, "__construct", NULL, 18, event, &params);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &eventObject, "setattributes", NULL, 19, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "dispatcher");
	ZEPHIR_CALL_METHOD(NULL, &eventObject, "setattribute", NULL, 20, &_2, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&paramValue);
	array_init(&paramValue);
	if (zephir_is_true(&params)) {
		ZEPHIR_CPY_WRT(&paramValue, &params);
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	zephir_array_fast_append(&_3, &eventObject);
	ZEPHIR_INIT_NVAR(&params);
	zephir_fast_array_merge(&params, &_3, &paramValue);
	ZEPHIR_CALL_METHOD(&_4, &eventObject, "getname", NULL, 21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, ":");
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_strpos(&_5, &_4, &_2, 0 );
	if (!ZEPHIR_IS_FALSE(&_5)) {
		ZEPHIR_CALL_METHOD(&_6$$8, &eventObject, "getname", NULL, 21);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$8, &eventObject, "getname", NULL, 21);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$8);
		ZVAL_STRING(&_8$$8, ":");
		ZEPHIR_INIT_VAR(&_9$$8);
		zephir_fast_strpos(&_9$$8, &_7$$8, &_8$$8, 0 );
		ZVAL_LONG(&_10$$8, 0);
		ZEPHIR_INIT_VAR(&eventNamespace$$8);
		zephir_substr(&eventNamespace$$8, &_6$$8, 0 , zephir_get_intval(&_9$$8), 0);
		zephir_read_property(&_11$$8, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_11$$8, &eventNamespace$$8)) {
			zephir_read_property(&_12$$9, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_13$$9, &_12$$9, &eventNamespace$$8, PH_NOISY | PH_READONLY, "yuga/Events/Event.zep", 180);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "fire", &_14, 0, &_13$$9, &eventObject, &params, callback);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	zephir_read_property(&_15, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_16, &eventObject, "getname", NULL, 21);
	zephir_check_call_status();
	if (zephir_array_isset(&_15, &_16)) {
		zephir_read_property(&_17$$10, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_19$$10, &eventObject, "getname", NULL, 21);
		zephir_check_call_status();
		zephir_array_fetch(&_18$$10, &_17$$10, &_19$$10, PH_NOISY | PH_READONLY, "yuga/Events/Event.zep", 185);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "fire", &_14, 0, &_18$$10, &eventObject, &params, callback);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Alias for dispatch
 * 
 * @param  string|Event  event
 * @param  array  parameters
 *
 * @return Event event
 */
PHP_METHOD(Yuga_Events_Event, trigger)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event = NULL, event_sub, *parameters = NULL, parameters_sub, *callback = NULL, callback_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(event)
		Z_PARAM_ZVAL_OR_NULL(parameters)
		Z_PARAM_ZVAL_OR_NULL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &event, &parameters, &callback);
	if (!event) {
		event = &event_sub;
		event = &__$null;
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	if (zephir_fast_count_int(&_0) == 2) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dispatch", &_1, 0, event, parameters);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dispatch", &_1, 0, event, parameters, callback);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Organise parameters to suit both two and three arguments as a user dispatches or triggers the event
 * 
 * @param parameters
 * 
 * @return array items
 */
PHP_METHOD(Yuga_Events_Event, getParameters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *parameters = NULL, parameters_sub, __$null, items, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&items);
	array_init(&items);
	if (zephir_is_instance_of(parameters, SL("Closure"))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_array_update_string(&items, SL("params"), &_0$$3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&items, SL("callback"), parameters, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_string(&items, SL("params"), parameters, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&items, SL("callback"), &__$null, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&items);
}

PHP_METHOD(Yuga_Events_Event, fire)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *listeners, listeners_sub, *event, event_sub, *params_param = NULL, *callback = NULL, callback_sub, __$null, list, listener, *_0, _1, *_2$$3, _3$$3, eventParams$$4, eventListener$$4, _9$$4, _10$$4, _4$$7, _5$$7, _6$$8, _8$$9, eventParams$$11, eventListener$$11, _16$$11, _17$$11, _12$$14, _13$$14, _14$$15, _15$$16, *_18$$18, _19$$18, eventParams$$19, eventListener$$19, _24$$19, _25$$19, _20$$22, _21$$22, _22$$23, _23$$24, eventParams$$26, eventListener$$26, _30$$26, _31$$26, _26$$29, _27$$29, _28$$30, _29$$31;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&listeners_sub);
	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&list);
	ZVAL_UNDEF(&listener);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&eventParams$$4);
	ZVAL_UNDEF(&eventListener$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&eventParams$$11);
	ZVAL_UNDEF(&eventListener$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&eventParams$$19);
	ZVAL_UNDEF(&eventListener$$19);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_20$$22);
	ZVAL_UNDEF(&_21$$22);
	ZVAL_UNDEF(&_22$$23);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&eventParams$$26);
	ZVAL_UNDEF(&eventListener$$26);
	ZVAL_UNDEF(&_30$$26);
	ZVAL_UNDEF(&_31$$26);
	ZVAL_UNDEF(&_26$$29);
	ZVAL_UNDEF(&_27$$29);
	ZVAL_UNDEF(&_28$$30);
	ZVAL_UNDEF(&_29$$31);
	ZVAL_UNDEF(&params);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_ZVAL(listeners)
		Z_PARAM_ZVAL(event)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(params)
		Z_PARAM_ZVAL_OR_NULL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &listeners, &event, &params_param, &callback);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	ZEPHIR_MAKE_REF(listeners);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 22, listeners);
	ZEPHIR_UNREF(listeners);
	zephir_check_call_status();
	zephir_is_iterable(listeners, 0, "yuga/Events/Event.zep", 262);
	if (Z_TYPE_P(listeners) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(listeners), _0)
		{
			ZEPHIR_INIT_NVAR(&list);
			ZVAL_COPY(&list, _0);
			zephir_is_iterable(&list, 0, "yuga/Events/Event.zep", 261);
			if (Z_TYPE_P(&list) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&list), _2$$3)
				{
					ZEPHIR_INIT_NVAR(&listener);
					ZVAL_COPY(&listener, _2$$3);
					ZEPHIR_CPY_WRT(&eventParams$$4, &params);
					if (Z_TYPE_P(&listener) == IS_ARRAY) {
						ZEPHIR_CPY_WRT(&eventListener$$4, &listener);
					} else if (zephir_is_instance_of(&listener, SL("Closure"))) {
						ZEPHIR_CPY_WRT(&eventListener$$4, &listener);
					} else {
						ZEPHIR_INIT_NVAR(&_4$$7);
						zephir_create_array(&_4$$7, 2, 0);
						zephir_array_fast_append(&_4$$7, &listener);
						ZEPHIR_INIT_NVAR(&_5$$7);
						ZVAL_STRING(&_5$$7, "handle");
						zephir_array_fast_append(&_4$$7, &_5$$7);
						ZEPHIR_CPY_WRT(&eventListener$$4, &_4$$7);
						if (zephir_instance_of_ev(&listener, yuga_eventhandlers_handlerinterface_ce)) {
							ZEPHIR_CALL_FUNCTION(&_6$$8, "array_values", &_7, 1, &params);
							zephir_check_call_status();
							if (!ZEPHIR_IS_IDENTICAL(&_6$$8, &params)) {
								ZEPHIR_CALL_METHOD(NULL, event, "setattributes", NULL, 0, &params);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_8$$9);
								zephir_create_array(&_8$$9, 1, 0);
								zephir_array_fast_append(&_8$$9, event);
								ZEPHIR_CPY_WRT(&eventParams$$4, &_8$$9);
							}
						}
					}
					ZEPHIR_INIT_NVAR(&_9$$4);
					ZEPHIR_CALL_FUNCTION(&_10$$4, "array_values", &_7, 1, &eventParams$$4);
					zephir_check_call_status();
					ZEPHIR_CALL_USER_FUNC_ARRAY(&_9$$4, &eventListener$$4, &_10$$4);
					zephir_check_call_status();
					if (zephir_is_instance_of(callback, SL("Closure"))) {
						ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", &_11, 23, callback, event);
						zephir_check_call_status();
						RETURN_MM();
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &list, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$3, &list, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&listener, &list, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CPY_WRT(&eventParams$$11, &params);
						if (Z_TYPE_P(&listener) == IS_ARRAY) {
							ZEPHIR_CPY_WRT(&eventListener$$11, &listener);
						} else if (zephir_is_instance_of(&listener, SL("Closure"))) {
							ZEPHIR_CPY_WRT(&eventListener$$11, &listener);
						} else {
							ZEPHIR_INIT_NVAR(&_12$$14);
							zephir_create_array(&_12$$14, 2, 0);
							zephir_array_fast_append(&_12$$14, &listener);
							ZEPHIR_INIT_NVAR(&_13$$14);
							ZVAL_STRING(&_13$$14, "handle");
							zephir_array_fast_append(&_12$$14, &_13$$14);
							ZEPHIR_CPY_WRT(&eventListener$$11, &_12$$14);
							if (zephir_instance_of_ev(&listener, yuga_eventhandlers_handlerinterface_ce)) {
								ZEPHIR_CALL_FUNCTION(&_14$$15, "array_values", &_7, 1, &params);
								zephir_check_call_status();
								if (!ZEPHIR_IS_IDENTICAL(&_14$$15, &params)) {
									ZEPHIR_CALL_METHOD(NULL, event, "setattributes", NULL, 0, &params);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_15$$16);
									zephir_create_array(&_15$$16, 1, 0);
									zephir_array_fast_append(&_15$$16, event);
									ZEPHIR_CPY_WRT(&eventParams$$11, &_15$$16);
								}
							}
						}
						ZEPHIR_INIT_NVAR(&_16$$11);
						ZEPHIR_CALL_FUNCTION(&_17$$11, "array_values", &_7, 1, &eventParams$$11);
						zephir_check_call_status();
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_16$$11, &eventListener$$11, &_17$$11);
						zephir_check_call_status();
						if (zephir_is_instance_of(callback, SL("Closure"))) {
							ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", &_11, 23, callback, event);
							zephir_check_call_status();
							RETURN_MM();
						}
					ZEPHIR_CALL_METHOD(NULL, &list, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&listener);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, listeners, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, listeners, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&list, listeners, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&list, 0, "yuga/Events/Event.zep", 261);
				if (Z_TYPE_P(&list) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&list), _18$$18)
					{
						ZEPHIR_INIT_NVAR(&listener);
						ZVAL_COPY(&listener, _18$$18);
						ZEPHIR_CPY_WRT(&eventParams$$19, &params);
						if (Z_TYPE_P(&listener) == IS_ARRAY) {
							ZEPHIR_CPY_WRT(&eventListener$$19, &listener);
						} else if (zephir_is_instance_of(&listener, SL("Closure"))) {
							ZEPHIR_CPY_WRT(&eventListener$$19, &listener);
						} else {
							ZEPHIR_INIT_NVAR(&_20$$22);
							zephir_create_array(&_20$$22, 2, 0);
							zephir_array_fast_append(&_20$$22, &listener);
							ZEPHIR_INIT_NVAR(&_21$$22);
							ZVAL_STRING(&_21$$22, "handle");
							zephir_array_fast_append(&_20$$22, &_21$$22);
							ZEPHIR_CPY_WRT(&eventListener$$19, &_20$$22);
							if (zephir_instance_of_ev(&listener, yuga_eventhandlers_handlerinterface_ce)) {
								ZEPHIR_CALL_FUNCTION(&_22$$23, "array_values", &_7, 1, &params);
								zephir_check_call_status();
								if (!ZEPHIR_IS_IDENTICAL(&_22$$23, &params)) {
									ZEPHIR_CALL_METHOD(NULL, event, "setattributes", NULL, 0, &params);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_23$$24);
									zephir_create_array(&_23$$24, 1, 0);
									zephir_array_fast_append(&_23$$24, event);
									ZEPHIR_CPY_WRT(&eventParams$$19, &_23$$24);
								}
							}
						}
						ZEPHIR_INIT_NVAR(&_24$$19);
						ZEPHIR_CALL_FUNCTION(&_25$$19, "array_values", &_7, 1, &eventParams$$19);
						zephir_check_call_status();
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_24$$19, &eventListener$$19, &_25$$19);
						zephir_check_call_status();
						if (zephir_is_instance_of(callback, SL("Closure"))) {
							ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", &_11, 23, callback, event);
							zephir_check_call_status();
							RETURN_MM();
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &list, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_19$$18, &list, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_19$$18)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&listener, &list, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CPY_WRT(&eventParams$$26, &params);
							if (Z_TYPE_P(&listener) == IS_ARRAY) {
								ZEPHIR_CPY_WRT(&eventListener$$26, &listener);
							} else if (zephir_is_instance_of(&listener, SL("Closure"))) {
								ZEPHIR_CPY_WRT(&eventListener$$26, &listener);
							} else {
								ZEPHIR_INIT_NVAR(&_26$$29);
								zephir_create_array(&_26$$29, 2, 0);
								zephir_array_fast_append(&_26$$29, &listener);
								ZEPHIR_INIT_NVAR(&_27$$29);
								ZVAL_STRING(&_27$$29, "handle");
								zephir_array_fast_append(&_26$$29, &_27$$29);
								ZEPHIR_CPY_WRT(&eventListener$$26, &_26$$29);
								if (zephir_instance_of_ev(&listener, yuga_eventhandlers_handlerinterface_ce)) {
									ZEPHIR_CALL_FUNCTION(&_28$$30, "array_values", &_7, 1, &params);
									zephir_check_call_status();
									if (!ZEPHIR_IS_IDENTICAL(&_28$$30, &params)) {
										ZEPHIR_CALL_METHOD(NULL, event, "setattributes", NULL, 0, &params);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_29$$31);
										zephir_create_array(&_29$$31, 1, 0);
										zephir_array_fast_append(&_29$$31, event);
										ZEPHIR_CPY_WRT(&eventParams$$26, &_29$$31);
									}
								}
							}
							ZEPHIR_INIT_NVAR(&_30$$26);
							ZEPHIR_CALL_FUNCTION(&_31$$26, "array_values", &_7, 1, &eventParams$$26);
							zephir_check_call_status();
							ZEPHIR_CALL_USER_FUNC_ARRAY(&_30$$26, &eventListener$$26, &_31$$26);
							zephir_check_call_status();
							if (zephir_is_instance_of(callback, SL("Closure"))) {
								ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", &_11, 23, callback, event);
								zephir_check_call_status();
								RETURN_MM();
							}
						ZEPHIR_CALL_METHOD(NULL, &list, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&listener);
			ZEPHIR_CALL_METHOD(NULL, listeners, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&list);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Yuga_Events_Event(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("listeners"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

