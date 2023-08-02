
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
#include "kernel/file.h"
#include "kernel/require.h"
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
	zval *app, app_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
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
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "events");
	ZEPHIR_CALL_METHOD(&_3, app, "make", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "\\Yuga\\Events\\Event");
	ZEPHIR_CALL_METHOD(NULL, app, "singleton", NULL, 0, &_2, &_3);
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
	zval _13$$7, _22$$10, _36$$16, _45$$19;
	zend_string *_10;
	zend_ulong _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_18 = NULL, *_21 = NULL, *_27 = NULL, *_30 = NULL, *_33 = NULL, *_41 = NULL, *_44 = NULL, *_50 = NULL, *_53 = NULL, *_56 = NULL;
	zval *dispatcher, dispatcher_sub, otherApplicationEvents, handlers, event, handles, _0, _2, _6, *_7, _8, _3$$3, _4$$3, _5$$3, handle$$5, *_11$$5, _12$$5, _14$$7, _15$$7, _16$$7, _17$$7, _19$$8, _20$$8, _23$$10, _24$$10, _25$$10, _26$$10, _28$$11, _29$$11, _31$$12, _32$$12, handle$$14, *_34$$14, _35$$14, _37$$16, _38$$16, _39$$16, _40$$16, _42$$17, _43$$17, _46$$19, _47$$19, _48$$19, _49$$19, _51$$20, _52$$20, _54$$21, _55$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&otherApplicationEvents);
	ZVAL_UNDEF(&handlers);
	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&handles);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&handle$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&handle$$14);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_38$$16);
	ZVAL_UNDEF(&_39$$16);
	ZVAL_UNDEF(&_40$$16);
	ZVAL_UNDEF(&_42$$17);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_47$$19);
	ZVAL_UNDEF(&_48$$19);
	ZVAL_UNDEF(&_49$$19);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_54$$21);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_45$$19);
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
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "config/AppEvents.php");
	ZEPHIR_CALL_CE_STATIC(&_0, yuga_support_helpers_ce, "path", &_1, 0, &_2);
	zephir_check_call_status();
	if ((zephir_file_exists(&_0) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "config/AppEvents.php");
		ZEPHIR_CALL_CE_STATIC(&_3$$3, yuga_support_helpers_ce, "path", &_1, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_5$$3);
		if (zephir_require_zval_ret(&_5$$3, &_3$$3) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CPY_WRT(&otherApplicationEvents, &_5$$3);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&handlers);
	zephir_fast_array_merge(&handlers, &_6, &otherApplicationEvents);
	zephir_is_iterable(&handlers, 0, "yuga/Events/EventServiceProvider.zep", 90);
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&handlers), _9, _10, _7)
		{
			ZEPHIR_INIT_NVAR(&event);
			if (_10 != NULL) { 
				ZVAL_STR_COPY(&event, _10);
			} else {
				ZVAL_LONG(&event, _9);
			}
			ZEPHIR_INIT_NVAR(&handles);
			ZVAL_COPY(&handles, _7);
			if (Z_TYPE_P(&handles) == IS_ARRAY) {
				zephir_is_iterable(&handles, 0, "yuga/Events/EventServiceProvider.zep", 86);
				if (Z_TYPE_P(&handles) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handles), _11$$5)
					{
						ZEPHIR_INIT_NVAR(&handle$$5);
						ZVAL_COPY(&handle$$5, _11$$5);
						if (Z_TYPE_P(&handle$$5) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_13$$7);
							zephir_create_array(&_13$$7, 2, 0);
							zephir_read_property(&_14$$7, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch_long(&_16$$7, &handle$$5, 0, PH_NOISY | PH_READONLY, "yuga/Events/EventServiceProvider.zep", 81);
							ZEPHIR_CALL_METHOD(&_15$$7, &_14$$7, "resolve", NULL, 0, &_16$$7);
							zephir_check_call_status();
							zephir_array_fast_append(&_13$$7, &_15$$7);
							ZEPHIR_OBS_NVAR(&_17$$7);
							zephir_array_fetch_long(&_17$$7, &handle$$5, 1, PH_NOISY, "yuga/Events/EventServiceProvider.zep", 81);
							zephir_array_fast_append(&_13$$7, &_17$$7);
							ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_18, 0, &event, &_13$$7);
							zephir_check_call_status();
						} else {
							zephir_read_property(&_19$$8, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(&_20$$8, &_19$$8, "resolve", NULL, 0, &handle$$5);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_21, 0, &event, &_20$$8);
							zephir_check_call_status();
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &handles, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_12$$5, &handles, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_12$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&handle$$5, &handles, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&handle$$5) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_22$$10);
								zephir_create_array(&_22$$10, 2, 0);
								zephir_read_property(&_23$$10, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch_long(&_25$$10, &handle$$5, 0, PH_NOISY | PH_READONLY, "yuga/Events/EventServiceProvider.zep", 81);
								ZEPHIR_CALL_METHOD(&_24$$10, &_23$$10, "resolve", NULL, 0, &_25$$10);
								zephir_check_call_status();
								zephir_array_fast_append(&_22$$10, &_24$$10);
								ZEPHIR_OBS_NVAR(&_26$$10);
								zephir_array_fetch_long(&_26$$10, &handle$$5, 1, PH_NOISY, "yuga/Events/EventServiceProvider.zep", 81);
								zephir_array_fast_append(&_22$$10, &_26$$10);
								ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_27, 0, &event, &_22$$10);
								zephir_check_call_status();
							} else {
								zephir_read_property(&_28$$11, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(&_29$$11, &_28$$11, "resolve", NULL, 0, &handle$$5);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_30, 0, &event, &_29$$11);
								zephir_check_call_status();
							}
						ZEPHIR_CALL_METHOD(NULL, &handles, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&handle$$5);
			} else {
				zephir_read_property(&_31$$12, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_32$$12, &_31$$12, "resolve", NULL, 0, &handles);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_33, 0, &event, &_32$$12);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &handlers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &handlers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&event, &handlers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&handles, &handlers, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&handles) == IS_ARRAY) {
					zephir_is_iterable(&handles, 0, "yuga/Events/EventServiceProvider.zep", 86);
					if (Z_TYPE_P(&handles) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handles), _34$$14)
						{
							ZEPHIR_INIT_NVAR(&handle$$14);
							ZVAL_COPY(&handle$$14, _34$$14);
							if (Z_TYPE_P(&handle$$14) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_36$$16);
								zephir_create_array(&_36$$16, 2, 0);
								zephir_read_property(&_37$$16, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch_long(&_39$$16, &handle$$14, 0, PH_NOISY | PH_READONLY, "yuga/Events/EventServiceProvider.zep", 81);
								ZEPHIR_CALL_METHOD(&_38$$16, &_37$$16, "resolve", NULL, 0, &_39$$16);
								zephir_check_call_status();
								zephir_array_fast_append(&_36$$16, &_38$$16);
								ZEPHIR_OBS_NVAR(&_40$$16);
								zephir_array_fetch_long(&_40$$16, &handle$$14, 1, PH_NOISY, "yuga/Events/EventServiceProvider.zep", 81);
								zephir_array_fast_append(&_36$$16, &_40$$16);
								ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_41, 0, &event, &_36$$16);
								zephir_check_call_status();
							} else {
								zephir_read_property(&_42$$17, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(&_43$$17, &_42$$17, "resolve", NULL, 0, &handle$$14);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_44, 0, &event, &_43$$17);
								zephir_check_call_status();
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &handles, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_35$$14, &handles, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_35$$14)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&handle$$14, &handles, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&handle$$14) == IS_ARRAY) {
									ZEPHIR_INIT_NVAR(&_45$$19);
									zephir_create_array(&_45$$19, 2, 0);
									zephir_read_property(&_46$$19, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch_long(&_48$$19, &handle$$14, 0, PH_NOISY | PH_READONLY, "yuga/Events/EventServiceProvider.zep", 81);
									ZEPHIR_CALL_METHOD(&_47$$19, &_46$$19, "resolve", NULL, 0, &_48$$19);
									zephir_check_call_status();
									zephir_array_fast_append(&_45$$19, &_47$$19);
									ZEPHIR_OBS_NVAR(&_49$$19);
									zephir_array_fetch_long(&_49$$19, &handle$$14, 1, PH_NOISY, "yuga/Events/EventServiceProvider.zep", 81);
									zephir_array_fast_append(&_45$$19, &_49$$19);
									ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_50, 0, &event, &_45$$19);
									zephir_check_call_status();
								} else {
									zephir_read_property(&_51$$20, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(&_52$$20, &_51$$20, "resolve", NULL, 0, &handle$$14);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_53, 0, &event, &_52$$20);
									zephir_check_call_status();
								}
							ZEPHIR_CALL_METHOD(NULL, &handles, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&handle$$14);
				} else {
					zephir_read_property(&_54$$21, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_55$$21, &_54$$21, "resolve", NULL, 0, &handles);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, dispatcher, "attach", &_56, 0, &event, &_55$$21);
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
		zval _1$$3;
	zval _0;
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
			zephir_create_array(&_1$$3, 2, 0);
			add_assoc_stringl_ex(&_1$$3, SL("on:app-start"), SL("\\Yuga\\EventHandlers\\ApplicationStart"));
			add_assoc_stringl_ex(&_1$$3, SL("on:app-stop"), SL("\\Yuga\\EventHandlers\\ApplicationStop"));
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("events"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

