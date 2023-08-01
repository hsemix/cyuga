
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Yuga_Events_EventServiceProvider)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Events, EventServiceProvider, yuga, events_eventserviceprovider, yuga_providers_serviceprovider_ce, yuga_events_eventserviceprovider_method_entry, 0);

	zend_declare_property_null(yuga_events_eventserviceprovider_ce, SL("app"), ZEND_ACC_PROTECTED);
	/**
	 * All Yuga default events registered here!
	 * 
	 * @var array events
	 */
	zend_declare_property_null(yuga_events_eventserviceprovider_ce, SL("events"), ZEND_ACC_PROTECTED);
	yuga_events_eventserviceprovider_ce->create_object = zephir_init_properties_Yuga_Events_EventServiceProvider;

	return SUCCESS;
}

/**
 * Boot the event service provider with app 
 * 
 * @param \Yuga\Interfaces\Application\Application app
 * 
 * @return void
 */
PHP_METHOD(Yuga_Events_EventServiceProvider, __construct)
{
	zval *app, app_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(app, zephir_get_internal_ce(SL("yuga\\interfaces\\application\\application")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &app);


	zephir_update_property_zval(this_ptr, ZEND_STRL("app"), app);
}

/**
 * Load a service provider
 * 
 * @param \Yuga\Interfaces\Application\Application app
 * 
 * @return mixed
 */
PHP_METHOD(Yuga_Events_EventServiceProvider, load)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(app, zephir_get_internal_ce(SL("yuga\\interfaces\\application\\application")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);


	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, yuga_events_event_ce);
	if (zephir_has_constructor(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, app);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "loadevents", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "events");
	ZEPHIR_CALL_METHOD(NULL, app, "singleton", NULL, 0, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Load all event handlers that have been registered by the developer
 * 
 * @param \Yuga\Events\DispatcherInterface dispatcher
 * 
 * @return \Yuga\Events\Event dispatcher
 */
PHP_METHOD(Yuga_Events_EventServiceProvider, loadEvents)
{
	zval _7$$6, _16$$9, _30$$15, _39$$18;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_15 = NULL, *_21 = NULL, *_24 = NULL, *_27 = NULL, *_35 = NULL, *_38 = NULL, *_44 = NULL, *_47 = NULL, *_50 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dispatcher, dispatcher_sub, otherApplicationEvents, handlers, event, handles, _0, *_1, _2, handle$$4, *_5$$4, _6$$4, _8$$6, _9$$6, _10$$6, _11$$6, _13$$7, _14$$7, _17$$9, _18$$9, _19$$9, _20$$9, _22$$10, _23$$10, _25$$11, _26$$11, handle$$13, *_28$$13, _29$$13, _31$$15, _32$$15, _33$$15, _34$$15, _36$$16, _37$$16, _40$$18, _41$$18, _42$$18, _43$$18, _45$$19, _46$$19, _48$$20, _49$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&otherApplicationEvents);
	ZVAL_UNDEF(&handlers);
	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&handles);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&handle$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&handle$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_34$$15);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_40$$18);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_48$$20);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_39$$18);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(dispatcher, zephir_get_internal_ce(SL("yuga\\interfaces\\events\\dispatcherinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dispatcher);


	ZEPHIR_INIT_VAR(&otherApplicationEvents);
	array_init(&otherApplicationEvents);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&handlers);
	zephir_fast_array_merge(&handlers, &_0, &otherApplicationEvents);
	zephir_is_iterable(&handlers, 0, "yuga/Events/EventServiceProvider.zep", 88);
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&handlers), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&event);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&event, _4);
			} else {
				ZVAL_LONG(&event, _3);
			}
			ZEPHIR_INIT_NVAR(&handles);
			ZVAL_COPY(&handles, _1);
			if (Z_TYPE_P(&handles) == IS_ARRAY) {
				zephir_is_iterable(&handles, 0, "yuga/Events/EventServiceProvider.zep", 84);
				if (Z_TYPE_P(&handles) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handles), _5$$4)
					{
						ZEPHIR_INIT_NVAR(&handle$$4);
						ZVAL_COPY(&handle$$4, _5$$4);
						if (Z_TYPE_P(&handle$$4) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_7$$6);
							zephir_create_array(&_7$$6, 2, 0);
							zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch_long(&_10$$6, &handle$$4, 0, PH_NOISY | PH_READONLY, "yuga/Events/EventServiceProvider.zep", 79);
							ZEPHIR_CALL_METHOD(&_9$$6, &_8$$6, "resolve", NULL, 0, &_10$$6);
							zephir_check_call_status();
							zephir_array_fast_append(&_7$$6, &_9$$6);
							ZEPHIR_OBS_NVAR(&_11$$6);
							zephir_array_fetch_long(&_11$$6, &handle$$4, 1, PH_NOISY, "yuga/Events/EventServiceProvider.zep", 79);
							zephir_array_fast_append(&_7$$6, &_11$$6);
							ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_12, 0, &event, &_7$$6);
							zephir_check_call_status();
						} else {
							zephir_read_property(&_13$$7, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(&_14$$7, &_13$$7, "resolve", NULL, 0, &handle$$4);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_15, 0, &event, &_14$$7);
							zephir_check_call_status();
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &handles, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_6$$4, &handles, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_6$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&handle$$4, &handles, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&handle$$4) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_16$$9);
								zephir_create_array(&_16$$9, 2, 0);
								zephir_read_property(&_17$$9, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch_long(&_19$$9, &handle$$4, 0, PH_NOISY | PH_READONLY, "yuga/Events/EventServiceProvider.zep", 79);
								ZEPHIR_CALL_METHOD(&_18$$9, &_17$$9, "resolve", NULL, 0, &_19$$9);
								zephir_check_call_status();
								zephir_array_fast_append(&_16$$9, &_18$$9);
								ZEPHIR_OBS_NVAR(&_20$$9);
								zephir_array_fetch_long(&_20$$9, &handle$$4, 1, PH_NOISY, "yuga/Events/EventServiceProvider.zep", 79);
								zephir_array_fast_append(&_16$$9, &_20$$9);
								ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_21, 0, &event, &_16$$9);
								zephir_check_call_status();
							} else {
								zephir_read_property(&_22$$10, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(&_23$$10, &_22$$10, "resolve", NULL, 0, &handle$$4);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_24, 0, &event, &_23$$10);
								zephir_check_call_status();
							}
						ZEPHIR_CALL_METHOD(NULL, &handles, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&handle$$4);
			} else {
				zephir_read_property(&_25$$11, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_26$$11, &_25$$11, "resolve", NULL, 0, &handles);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_27, 0, &event, &_26$$11);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &handlers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &handlers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&event, &handlers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&handles, &handlers, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&handles) == IS_ARRAY) {
					zephir_is_iterable(&handles, 0, "yuga/Events/EventServiceProvider.zep", 84);
					if (Z_TYPE_P(&handles) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handles), _28$$13)
						{
							ZEPHIR_INIT_NVAR(&handle$$13);
							ZVAL_COPY(&handle$$13, _28$$13);
							if (Z_TYPE_P(&handle$$13) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_30$$15);
								zephir_create_array(&_30$$15, 2, 0);
								zephir_read_property(&_31$$15, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch_long(&_33$$15, &handle$$13, 0, PH_NOISY | PH_READONLY, "yuga/Events/EventServiceProvider.zep", 79);
								ZEPHIR_CALL_METHOD(&_32$$15, &_31$$15, "resolve", NULL, 0, &_33$$15);
								zephir_check_call_status();
								zephir_array_fast_append(&_30$$15, &_32$$15);
								ZEPHIR_OBS_NVAR(&_34$$15);
								zephir_array_fetch_long(&_34$$15, &handle$$13, 1, PH_NOISY, "yuga/Events/EventServiceProvider.zep", 79);
								zephir_array_fast_append(&_30$$15, &_34$$15);
								ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_35, 0, &event, &_30$$15);
								zephir_check_call_status();
							} else {
								zephir_read_property(&_36$$16, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(&_37$$16, &_36$$16, "resolve", NULL, 0, &handle$$13);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_38, 0, &event, &_37$$16);
								zephir_check_call_status();
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &handles, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_29$$13, &handles, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_29$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&handle$$13, &handles, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&handle$$13) == IS_ARRAY) {
									ZEPHIR_INIT_NVAR(&_39$$18);
									zephir_create_array(&_39$$18, 2, 0);
									zephir_read_property(&_40$$18, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch_long(&_42$$18, &handle$$13, 0, PH_NOISY | PH_READONLY, "yuga/Events/EventServiceProvider.zep", 79);
									ZEPHIR_CALL_METHOD(&_41$$18, &_40$$18, "resolve", NULL, 0, &_42$$18);
									zephir_check_call_status();
									zephir_array_fast_append(&_39$$18, &_41$$18);
									ZEPHIR_OBS_NVAR(&_43$$18);
									zephir_array_fetch_long(&_43$$18, &handle$$13, 1, PH_NOISY, "yuga/Events/EventServiceProvider.zep", 79);
									zephir_array_fast_append(&_39$$18, &_43$$18);
									ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_44, 0, &event, &_39$$18);
									zephir_check_call_status();
								} else {
									zephir_read_property(&_45$$19, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(&_46$$19, &_45$$19, "resolve", NULL, 0, &handle$$13);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_47, 0, &event, &_46$$19);
									zephir_check_call_status();
								}
							ZEPHIR_CALL_METHOD(NULL, &handles, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&handle$$13);
				} else {
					zephir_read_property(&_48$$20, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_49$$20, &_48$$20, "resolve", NULL, 0, &handles);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_50, 0, &event, &_49$$20);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &handlers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&handles);
	ZEPHIR_INIT_NVAR(&event);
	RETVAL_ZVAL(dispatcher, 1, 0);
	RETURN_MM();
}

zend_object *zephir_init_properties_Yuga_Events_EventServiceProvider(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("events"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

