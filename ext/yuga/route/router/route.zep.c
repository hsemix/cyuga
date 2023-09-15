
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Router_Route)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Route\\Router, Route, yuga, route_router_route, yuga_route_router_route_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yuga_route_router_route_ce, SL("requestTypes"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	/**
	 * If enabled parameters containing null-value
	 * will not be passed along to the callback.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(yuga_route_router_route_ce, SL("filterEmptyParams"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("defaultParameterRegex"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("paramModifiers"), ZEND_ACC_PROTECTED);
	zend_declare_property_string(yuga_route_router_route_ce, SL("paramOptionalSymbol"), "?", ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("group"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("parent"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("callback"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("defaultNamespace"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("namespaceValue"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("requestMethods"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("where"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("parameters"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("originalParameters"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("middlewares"), ZEND_ACC_PROTECTED);
	yuga_route_router_route_ce->create_object = zephir_init_properties_Yuga_Route_Router_Route;
	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("PARAMETERS_REGEX_FORMAT"), "%s([\\w]+)(\\%s?)%s");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("PARAMETERS_DEFAULT_REGEX"), "[\\w]+");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_GET"), "get");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_POST"), "post");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_PUT"), "put");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_PATCH"), "patch");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_OPTIONS"), "options");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_DELETE"), "delete");

	zend_class_implements(yuga_route_router_route_ce, 1, yuga_route_support_iroute_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Route_Router_Route, loadClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *name, name_sub, _0;
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


	ZEPHIR_CALL_CE_STATIC(&_0, yuga_application_application_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "resolve", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Route_Router_Route, instantiated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_7 = NULL, *_13 = NULL;
	zval *callback, callback_sub, *request = NULL, request_sub, __$null, reflection, classes, app, param, _1, *_2, _3, _4$$3, classValue$$4, _5$$4, _6$$4, binding$$5, _8$$5, _9$$6, _10$$6, _11$$7, _12$$7, _14$$8, _15$$8, _16$$8, _17$$8, _18$$9, classValue$$10, _19$$10, _20$$10, binding$$11, _21$$11, _22$$12, _23$$12, _24$$13, _25$$13, _26$$14, _27$$14, _28$$14, _29$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&app);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&classValue$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&binding$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&classValue$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&binding$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_29$$14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(request)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &request);
	if (!request) {
		request = &request_sub;
		request = &__$null;
	}


	ZEPHIR_INIT_VAR(&classes);
	array_init(&classes);
	ZEPHIR_CALL_CE_STATIC(&app, yuga_application_application_ce, "getinstance", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 1, callback);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &reflection, "getparameters", NULL, 2);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "yuga/Route/Router/Route.zep", 110);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&param);
			ZVAL_COPY(&param, _2);
			ZEPHIR_CALL_METHOD(&_4$$3, &param, "gettype", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&_4$$3) != IS_NULL) {
				ZEPHIR_CALL_METHOD(&_5$$4, &param, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&classValue$$4, &_5$$4, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "issingleton", &_7, 0, &app, &classValue$$4);
				zephir_check_call_status();
				if (zephir_is_true(&_6$$4)) {
					ZEPHIR_CALL_METHOD(&binding$$5, this_ptr, "issingleton", &_7, 0, &app, &classValue$$4);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&_8$$5);
					zephir_read_property(&_8$$5, &param, ZEND_STRL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&classes, &_8$$5, &binding$$5, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_CALL_METHOD(&_9$$6, &app, "resolve", NULL, 0, &classValue$$4);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&_10$$6);
					zephir_read_property(&_10$$6, &param, ZEND_STRL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&classes, &_10$$6, &_9$$6, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_read_property(&_11$$7, &param, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_12$$7, this_ptr, "getparameters", &_13, 0);
				zephir_check_call_status();
				if (zephir_array_key_exists(&_12$$7, &_11$$7)) {
					ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "getparameters", &_13, 0);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&_16$$8);
					zephir_read_property(&_16$$8, &param, ZEND_STRL("name"), PH_NOISY_CC);
					zephir_array_fetch(&_15$$8, &_14$$8, &_16$$8, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 105);
					ZEPHIR_OBS_NVAR(&_17$$8);
					zephir_read_property(&_17$$8, &param, ZEND_STRL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&classes, &_17$$8, &_15$$8, PH_COPY | PH_SEPARATE);
				}
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
			ZEPHIR_CALL_METHOD(&param, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_18$$9, &param, "gettype", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&_18$$9) != IS_NULL) {
					ZEPHIR_CALL_METHOD(&_19$$10, &param, "gettype", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&classValue$$10, &_19$$10, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_20$$10, this_ptr, "issingleton", &_7, 0, &app, &classValue$$10);
					zephir_check_call_status();
					if (zephir_is_true(&_20$$10)) {
						ZEPHIR_CALL_METHOD(&binding$$11, this_ptr, "issingleton", &_7, 0, &app, &classValue$$10);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&_21$$11);
						zephir_read_property(&_21$$11, &param, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_update_zval(&classes, &_21$$11, &binding$$11, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_CALL_METHOD(&_22$$12, &app, "resolve", NULL, 0, &classValue$$10);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&_23$$12);
						zephir_read_property(&_23$$12, &param, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_update_zval(&classes, &_23$$12, &_22$$12, PH_COPY | PH_SEPARATE);
					}
				} else {
					zephir_read_property(&_24$$13, &param, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_25$$13, this_ptr, "getparameters", &_13, 0);
					zephir_check_call_status();
					if (zephir_array_key_exists(&_25$$13, &_24$$13)) {
						ZEPHIR_CALL_METHOD(&_26$$14, this_ptr, "getparameters", &_13, 0);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&_28$$14);
						zephir_read_property(&_28$$14, &param, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_fetch(&_27$$14, &_26$$14, &_28$$14, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 105);
						ZEPHIR_OBS_NVAR(&_29$$14);
						zephir_read_property(&_29$$14, &param, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_update_zval(&classes, &_29$$14, &_27$$14, PH_COPY | PH_SEPARATE);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&param);
	RETURN_CCTOR(&classes);
}

PHP_METHOD(Yuga_Route_Router_Route, isSingleton)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, *className, className_sub, instance, _0, _1, *_2, _3, _4$$3, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(app, zephir_get_internal_ce(SL("yuga\\application\\application")))
		Z_PARAM_ZVAL(className)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &app, &className);


	ZEPHIR_CALL_METHOD(&_0, app, "getsingletons", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 3, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "yuga/Route/Router/Route.zep", 121);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&instance);
			ZVAL_COPY(&instance, _2);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_get_class(&_4$$3, &instance, 0);
			if (ZEPHIR_IS_EQUAL(&_4$$3, className)) {
				RETURN_CCTOR(&instance);
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
			ZEPHIR_CALL_METHOD(&instance, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				zephir_get_class(&_5$$5, &instance, 0);
				if (ZEPHIR_IS_EQUAL(&_5$$5, className)) {
					RETURN_CCTOR(&instance);
				}
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&instance);
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Yuga_Route_Router_Route, runMiddleware)
{
	zval *request, request_sub, *middleware, middleware_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&middleware_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
		Z_PARAM_ZVAL(middleware)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &request, &middleware);


}

PHP_METHOD(Yuga_Route_Router_Route, renderRoute)
{
	zend_class_entry *_20$$13;
	zend_bool _14$$7, _5$$10;
	zval _27;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, callback, classValue, result, controller, method, className, parameters, _24, _28, middleware$$5, _0$$5, _2$$6, controller$$7, _3$$7, namespaceValue$$7, _15$$7, _16$$7, viewModel$$8, _4$$8, _6$$10, _7$$10, _9$$10, _10$$10, _11$$10, _13$$10, _8$$11, _17$$12, exceptionClass$$13, _18$$13, _19$$13, _21$$13, _22$$13, _23$$13, _25$$14, _26$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&classValue);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&middleware$$5);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&controller$$7);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&namespaceValue$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&viewModel$$8);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&exceptionClass$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);


	ZEPHIR_CALL_METHOD(&callback, this_ptr, "getcallback", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&callback) == IS_NULL) {
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(&callback) == IS_ARRAY == 1) {
		if (zephir_array_isset_string(&callback, SL("middleware"))) {
			ZEPHIR_OBS_VAR(&middleware$$5);
			zephir_array_fetch_string(&middleware$$5, &callback, SL("middleware"), PH_NOISY, "yuga/Route/Router/Route.zep", 170);
			zephir_array_fetch_long(&_0$$5, &callback, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 171);
			ZEPHIR_CPY_WRT(&callback, &_0$$5);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "runmiddleware", NULL, 0, request, &middleware$$5);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(&controller);
		zephir_array_fetch_long(&controller, &callback, 0, PH_NOISY, "yuga/Route/Router/Route.zep", 175);
		ZEPHIR_CALL_METHOD(&classValue, this_ptr, "loadclass", &_1, 0, &controller);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&method);
		zephir_array_fetch_long(&method, &callback, 1, PH_NOISY, "yuga/Route/Router/Route.zep", 177);
	}
	if (zephir_is_callable(&callback) == 1) {
		ZEPHIR_CALL_METHOD(&_2$$6, this_ptr, "instantiated", NULL, 0, &callback, request);
		zephir_check_call_status();
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &callback, &_2$$6);
		zephir_check_call_status();
		RETURN_MM();
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(&callback) == IS_OBJECT == 1) {
	}
	if (Z_TYPE_P(&callback) == IS_STRING == 1) {
		ZEPHIR_INIT_VAR(&_3$$7);
		ZVAL_STRING(&_3$$7, "@");
		ZEPHIR_INIT_VAR(&controller$$7);
		zephir_fast_explode(&controller$$7, &_3$$7, &callback, LONG_MAX);
		ZEPHIR_CALL_METHOD(&namespaceValue$$7, this_ptr, "getnamespace", NULL, 0);
		zephir_check_call_status();
		if (zephir_fast_count_int(&controller$$7) == 1) {
			zephir_array_fetch_long(&_4$$8, &controller$$7, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 224);
			ZEPHIR_CALL_METHOD(&viewModel$$8, this_ptr, "loadclass", &_1, 0, &_4$$8);
			zephir_check_call_status();
			if (zephir_is_instance_of(&viewModel$$8, SL("Yuga\\View\\ViewModel"))) {
				zend_print_zval(&viewModel$$8, 0);
				RETURN_MM_NULL();
			} else {
				ZEPHIR_OBS_VAR(&className);
				zephir_array_fetch_long(&className, &controller$$7, 0, PH_NOISY, "yuga/Route/Router/Route.zep", 229);
				_5$$10 = Z_TYPE_P(&namespaceValue$$7) != IS_NULL;
				if (_5$$10) {
					zephir_array_fetch_long(&_6$$10, &controller$$7, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 230);
					zephir_array_fetch_long(&_7$$10, &_6$$10, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 230);
					_5$$10 = !ZEPHIR_IS_STRING_IDENTICAL(&_7$$10, "\\");
				}
				if (_5$$10) {
					zephir_array_fetch_long(&_8$$11, &controller$$7, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 231);
					ZEPHIR_INIT_NVAR(&className);
					ZEPHIR_CONCAT_VSV(&className, &namespaceValue$$7, "\\", &_8$$11);
				}
				ZEPHIR_INIT_VAR(&_9$$10);
				object_init_ex(&_9$$10, yuga_route_exceptions_notfoundhttpexception_ce);
				ZEPHIR_INIT_VAR(&_10$$10);
				ZVAL_STRING(&_10$$10, "Method not provided for controller class '%s'");
				ZEPHIR_CALL_FUNCTION(&_11$$10, "sprintf", &_12, 4, &_10$$10, &className);
				zephir_check_call_status();
				ZVAL_LONG(&_13$$10, 404);
				ZEPHIR_CALL_METHOD(NULL, &_9$$10, "__construct", NULL, 5, &_11$$10, &_13$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$10, "yuga/Route/Router/Route.zep", 233);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_OBS_NVAR(&className);
		zephir_array_fetch_long(&className, &controller$$7, 0, PH_NOISY, "yuga/Route/Router/Route.zep", 237);
		_14$$7 = Z_TYPE_P(&namespaceValue$$7) != IS_NULL;
		if (_14$$7) {
			zephir_array_fetch_long(&_15$$7, &controller$$7, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 239);
			zephir_array_fetch_long(&_16$$7, &_15$$7, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 239);
			_14$$7 = !ZEPHIR_IS_STRING_IDENTICAL(&_16$$7, "\\");
		}
		if (_14$$7) {
			zephir_array_fetch_long(&_17$$12, &controller$$7, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 240);
			ZEPHIR_INIT_NVAR(&className);
			ZEPHIR_CONCAT_VSV(&className, &namespaceValue$$7, "\\", &_17$$12);
		}
		ZEPHIR_CALL_METHOD(&classValue, this_ptr, "loadclass", &_1, 0, &className);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&method);
		zephir_array_fetch_long(&method, &controller$$7, 1, PH_NOISY, "yuga/Route/Router/Route.zep", 244);
	}
	if ((zephir_method_exists(&classValue, &method)  == SUCCESS) == 0) {
		ZEPHIR_INIT_VAR(&exceptionClass$$13);
		ZVAL_STRING(&exceptionClass$$13, "Yuga\\Route\\Exceptions\\NotFoundHttpException");
		ZEPHIR_INIT_VAR(&_18$$13);
		zephir_fetch_safe_class(&_19$$13, &exceptionClass$$13);
		_20$$13 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_19$$13), Z_STRLEN_P(&_19$$13), ZEND_FETCH_CLASS_AUTO);
		if(!_20$$13) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_18$$13, _20$$13);
		if (zephir_has_constructor(&_18$$13)) {
			ZEPHIR_INIT_VAR(&_21$$13);
			ZVAL_STRING(&_21$$13, "Method '%s' does not exist in class '%s'");
			ZEPHIR_CALL_FUNCTION(&_22$$13, "sprintf", &_12, 4, &_21$$13, &method, &className);
			zephir_check_call_status();
			ZVAL_LONG(&_23$$13, 404);
			ZEPHIR_CALL_METHOD(NULL, &_18$$13, "__construct", NULL, 0, &_22$$13, &_23$$13);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_18$$13, "yuga/Route/Router/Route.zep", 259);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&parameters, this_ptr, "getparameters", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_24, this_ptr, ZEND_STRL("filterEmptyParams"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_24)) {
		ZEPHIR_INIT_VAR(&_25$$14);
		ZEPHIR_INIT_NVAR(&_25$$14);
		zephir_create_closure_ex(&_25$$14, NULL, yuga_0__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(&_26$$14, "array_filter", NULL, 6, &parameters, &_25$$14);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&parameters, &_26$$14);
	}
	ZEPHIR_INIT_VAR(&_27);
	zephir_create_array(&_27, 2, 0);
	zephir_array_fast_append(&_27, &classValue);
	zephir_array_fast_append(&_27, &method);
	ZEPHIR_CALL_METHOD(&_28, this_ptr, "methodinjection", NULL, 0, &classValue, &method, &parameters, request);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&result);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&result, &_27, &_28);
	zephir_check_call_status();
	zend_print_zval(&result, 0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Route_Router_Route, processBindings)
{
	zend_string *_10$$4, *_31$$7, *_55$$12;
	zend_ulong _9$$4, _30$$7, _54$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_17 = NULL, *_25 = NULL, *_42 = NULL;
	zval *request = NULL, request_sub, __$null, modelBindingSettings, _0, _2, _3, _4$$3, _5$$3, _6$$3, routeBindings$$4, routeBinding$$4, fields$$4, *_7$$4, _8$$4, _11$$5, _12$$5, _13$$5, _14$$5, _15$$5, _16$$5, _18$$5, regex$$6, _19$$6, _20$$6, _21$$6, _22$$6, _23$$6, _24$$6, parameters$$6, _26$$6, index$$7, field$$7, _27$$7, *_28$$7, _29$$7, _32$$8, _33$$8, _34$$9, _35$$9, _36$$10, _37$$10, _38$$10, _39$$10, _40$$10, _41$$10, _43$$10, regex$$11, _44$$11, _45$$11, _46$$11, _47$$11, _48$$11, _49$$11, parameters$$11, _50$$11, index$$12, field$$12, _51$$12, *_52$$12, _53$$12, _56$$13, _57$$13, _58$$14, _59$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&modelBindingSettings);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&routeBindings$$4);
	ZVAL_UNDEF(&routeBinding$$4);
	ZVAL_UNDEF(&fields$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&regex$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&parameters$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&index$$7);
	ZVAL_UNDEF(&field$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&regex$$11);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_46$$11);
	ZVAL_UNDEF(&_47$$11);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&parameters$$11);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&index$$12);
	ZVAL_UNDEF(&field$$12);
	ZVAL_UNDEF(&_51$$12);
	ZVAL_UNDEF(&_53$$12);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_58$$14);
	ZVAL_UNDEF(&_59$$14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(request)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &request);
	if (!request) {
		request = &request_sub;
		request = &__$null;
	}


	ZEPHIR_INIT_VAR(&modelBindingSettings);
	array_init(&modelBindingSettings);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "config/AppRouteModelBinding.php");
	ZEPHIR_CALL_CE_STATIC(&_0, yuga_support_helpers_ce, "path", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "\file_exists", NULL, 7, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "config/AppRouteModelBinding.php");
		ZEPHIR_CALL_CE_STATIC(&_4$$3, yuga_support_helpers_ce, "path", &_1, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_6$$3);
		if (zephir_require_zval_ret(&_6$$3, &_4$$3) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CPY_WRT(&modelBindingSettings, &_6$$3);
	}
	if (zephir_fast_count_int(&modelBindingSettings) > 0) {
		ZEPHIR_INIT_VAR(&routeBindings$$4);
		array_init(&routeBindings$$4);
		zephir_is_iterable(&modelBindingSettings, 0, "yuga/Route/Router/Route.zep", 311);
		if (Z_TYPE_P(&modelBindingSettings) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&modelBindingSettings), _9$$4, _10$$4, _7$$4)
			{
				ZEPHIR_INIT_NVAR(&routeBinding$$4);
				if (_10$$4 != NULL) { 
					ZVAL_STR_COPY(&routeBinding$$4, _10$$4);
				} else {
					ZVAL_LONG(&routeBinding$$4, _9$$4);
				}
				ZEPHIR_INIT_NVAR(&fields$$4);
				ZVAL_COPY(&fields$$4, _7$$4);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "/");
				zephir_fast_trim(&_12$$5, &routeBinding$$4, &_13$$5, ZEPHIR_TRIM_BOTH);
				zephir_fast_explode_str(&_11$$5, SL("/"), &_12$$5, LONG_MAX);
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZEPHIR_INIT_NVAR(&_15$$5);
				ZEPHIR_CALL_METHOD(&_16$$5, request, "geturi", &_17, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZVAL_STRING(&_18$$5, "/");
				zephir_fast_trim(&_15$$5, &_16$$5, &_18$$5, ZEPHIR_TRIM_BOTH);
				zephir_fast_explode_str(&_14$$5, SL("/"), &_15$$5, LONG_MAX);
				if (zephir_fast_count_int(&_11$$5) == zephir_fast_count_int(&_14$$5)) {
					zephir_read_property(&_19$$6, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch_long(&_20$$6, &_19$$6, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 301);
					zephir_read_property(&_21$$6, this_ptr, ZEND_STRL("paramOptionalSymbol"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_22$$6, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch_long(&_23$$6, &_22$$6, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 301);
					ZEPHIR_INIT_NVAR(&_24$$6);
					ZVAL_STRING(&_24$$6, "%s([\\w]+)(\\%s?)%s");
					ZEPHIR_CALL_FUNCTION(&regex$$6, "sprintf", &_25, 4, &_24$$6, &_20$$6, &_21$$6, &_23$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_26$$6);
					ZEPHIR_CONCAT_SVS(&_26$$6, "/", &regex$$6, "/");
					ZEPHIR_INIT_NVAR(&_24$$6);
					zephir_preg_match(&_24$$6, &_26$$6, &routeBinding$$4, &parameters$$6, 1, 0 , 0 );
					if (zephir_is_true(&_24$$6)) {
						ZEPHIR_INIT_NVAR(&_27$$7);
						zephir_fast_explode_str(&_27$$7, SL(","), &fields$$4, LONG_MAX);
						zephir_is_iterable(&_27$$7, 0, "yuga/Route/Router/Route.zep", 308);
						if (Z_TYPE_P(&_27$$7) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_27$$7), _30$$7, _31$$7, _28$$7)
							{
								ZEPHIR_INIT_NVAR(&index$$7);
								if (_31$$7 != NULL) { 
									ZVAL_STR_COPY(&index$$7, _31$$7);
								} else {
									ZVAL_LONG(&index$$7, _30$$7);
								}
								ZEPHIR_INIT_NVAR(&field$$7);
								ZVAL_COPY(&field$$7, _28$$7);
								zephir_array_fetch_long(&_32$$8, &parameters$$6, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 306);
								ZEPHIR_OBS_NVAR(&_33$$8);
								zephir_array_fetch(&_33$$8, &_32$$8, &index$$7, PH_NOISY, "yuga/Route/Router/Route.zep", 306);
								zephir_array_update_zval(&routeBindings$$4, &_33$$8, &field$$7, PH_COPY | PH_SEPARATE);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_27$$7, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_29$$7, &_27$$7, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_29$$7)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&index$$7, &_27$$7, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&field$$7, &_27$$7, "current", NULL, 0);
								zephir_check_call_status();
									zephir_array_fetch_long(&_34$$9, &parameters$$6, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 306);
									ZEPHIR_OBS_NVAR(&_35$$9);
									zephir_array_fetch(&_35$$9, &_34$$9, &index$$7, PH_NOISY, "yuga/Route/Router/Route.zep", 306);
									zephir_array_update_zval(&routeBindings$$4, &_35$$9, &field$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, &_27$$7, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&field$$7);
						ZEPHIR_INIT_NVAR(&index$$7);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &modelBindingSettings, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_8$$4, &modelBindingSettings, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&routeBinding$$4, &modelBindingSettings, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&fields$$4, &modelBindingSettings, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_36$$10);
					ZEPHIR_INIT_NVAR(&_37$$10);
					ZEPHIR_INIT_NVAR(&_38$$10);
					ZVAL_STRING(&_38$$10, "/");
					zephir_fast_trim(&_37$$10, &routeBinding$$4, &_38$$10, ZEPHIR_TRIM_BOTH);
					zephir_fast_explode_str(&_36$$10, SL("/"), &_37$$10, LONG_MAX);
					ZEPHIR_INIT_NVAR(&_39$$10);
					ZEPHIR_INIT_NVAR(&_40$$10);
					ZEPHIR_CALL_METHOD(&_41$$10, request, "geturi", &_42, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_43$$10);
					ZVAL_STRING(&_43$$10, "/");
					zephir_fast_trim(&_40$$10, &_41$$10, &_43$$10, ZEPHIR_TRIM_BOTH);
					zephir_fast_explode_str(&_39$$10, SL("/"), &_40$$10, LONG_MAX);
					if (zephir_fast_count_int(&_36$$10) == zephir_fast_count_int(&_39$$10)) {
						zephir_read_property(&_44$$11, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch_long(&_45$$11, &_44$$11, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 301);
						zephir_read_property(&_46$$11, this_ptr, ZEND_STRL("paramOptionalSymbol"), PH_NOISY_CC | PH_READONLY);
						zephir_read_property(&_47$$11, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch_long(&_48$$11, &_47$$11, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 301);
						ZEPHIR_INIT_NVAR(&_49$$11);
						ZVAL_STRING(&_49$$11, "%s([\\w]+)(\\%s?)%s");
						ZEPHIR_CALL_FUNCTION(&regex$$11, "sprintf", &_25, 4, &_49$$11, &_45$$11, &_46$$11, &_48$$11);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_50$$11);
						ZEPHIR_CONCAT_SVS(&_50$$11, "/", &regex$$11, "/");
						ZEPHIR_INIT_NVAR(&_49$$11);
						zephir_preg_match(&_49$$11, &_50$$11, &routeBinding$$4, &parameters$$11, 1, 0 , 0 );
						if (zephir_is_true(&_49$$11)) {
							ZEPHIR_INIT_NVAR(&_51$$12);
							zephir_fast_explode_str(&_51$$12, SL(","), &fields$$4, LONG_MAX);
							zephir_is_iterable(&_51$$12, 0, "yuga/Route/Router/Route.zep", 308);
							if (Z_TYPE_P(&_51$$12) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_51$$12), _54$$12, _55$$12, _52$$12)
								{
									ZEPHIR_INIT_NVAR(&index$$12);
									if (_55$$12 != NULL) { 
										ZVAL_STR_COPY(&index$$12, _55$$12);
									} else {
										ZVAL_LONG(&index$$12, _54$$12);
									}
									ZEPHIR_INIT_NVAR(&field$$12);
									ZVAL_COPY(&field$$12, _52$$12);
									zephir_array_fetch_long(&_56$$13, &parameters$$11, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 306);
									ZEPHIR_OBS_NVAR(&_57$$13);
									zephir_array_fetch(&_57$$13, &_56$$13, &index$$12, PH_NOISY, "yuga/Route/Router/Route.zep", 306);
									zephir_array_update_zval(&routeBindings$$4, &_57$$13, &field$$12, PH_COPY | PH_SEPARATE);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_51$$12, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_53$$12, &_51$$12, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_53$$12)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&index$$12, &_51$$12, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&field$$12, &_51$$12, "current", NULL, 0);
									zephir_check_call_status();
										zephir_array_fetch_long(&_58$$14, &parameters$$11, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 306);
										ZEPHIR_OBS_NVAR(&_59$$14);
										zephir_array_fetch(&_59$$14, &_58$$14, &index$$12, PH_NOISY, "yuga/Route/Router/Route.zep", 306);
										zephir_array_update_zval(&routeBindings$$4, &_59$$14, &field$$12, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(NULL, &_51$$12, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&field$$12);
							ZEPHIR_INIT_NVAR(&index$$12);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &modelBindingSettings, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&fields$$4);
		ZEPHIR_INIT_NVAR(&routeBinding$$4);
		RETURN_CCTOR(&routeBindings$$4);
	}
	array_init(return_value);
	RETURN_MM();
}

PHP_METHOD(Yuga_Route_Router_Route, methodInjection)
{
	zend_class_entry *_40$$11 = NULL, *_91$$26 = NULL;
	zend_class_entry *_14$$6, *_67$$21;
	zend_bool _10$$5, _20$$6, _63$$20, _72$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_12 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_19 = NULL, *_22 = NULL, *_23 = NULL, *_29 = NULL, *_32 = NULL, *_43 = NULL, *_45 = NULL, *_58 = NULL, *_60 = NULL, *_61 = NULL, *_65 = NULL, *_68 = NULL, *_69 = NULL, *_71 = NULL, *_74 = NULL, *_75 = NULL, *_81 = NULL, *_94 = NULL;
	zval *className, className_sub, *method, method_sub, *params, params_sub, *request = NULL, request_sub, __$null, parameters, reflection, dependecies, app, _1, reflectionMethod$$3, reflectionParameters$$3, parameter$$3, *_2$$3, _3$$3, _4$$4, dependency$$5, _6$$5, type$$5, _9$$5, _11$$5, dependencyObject$$6, _13$$6, modelBindingSettings$$6, field$$6, _18$$6, _21$$6, _24$$6, _25$$6, value$$6, _27$$6, modelBound$$6, _28$$6, _26$$8, _30$$9, _31$$9, _33$$9, _34$$9, _35$$10, _36$$10, _37$$10, _38$$10, _39$$11, _41$$11, _42$$12, _44$$13, _46$$14, _47$$14, _48$$15, _49$$15, _50$$16, _51$$16, _52$$16, _53$$17, _54$$18, _55$$18, _56$$18, _57$$19, dependency$$20, _59$$20, type$$20, _62$$20, _64$$20, dependencyObject$$21, _66$$21, modelBindingSettings$$21, field$$21, _70$$21, _73$$21, _76$$21, _77$$21, value$$21, _79$$21, modelBound$$21, _80$$21, _78$$23, _82$$24, _83$$24, _84$$24, _85$$24, _86$$25, _87$$25, _88$$25, _89$$25, _90$$26, _92$$26, _93$$27, _95$$28, _96$$29, _97$$29, _98$$30, _99$$30, _100$$31, _101$$31, _102$$31, _103$$32, _104$$33, _105$$33, _106$$33;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&dependecies);
	ZVAL_UNDEF(&app);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&reflectionMethod$$3);
	ZVAL_UNDEF(&reflectionParameters$$3);
	ZVAL_UNDEF(&parameter$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&dependency$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&type$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&dependencyObject$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&modelBindingSettings$$6);
	ZVAL_UNDEF(&field$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&value$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&modelBound$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$11);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_42$$12);
	ZVAL_UNDEF(&_44$$13);
	ZVAL_UNDEF(&_46$$14);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_48$$15);
	ZVAL_UNDEF(&_49$$15);
	ZVAL_UNDEF(&_50$$16);
	ZVAL_UNDEF(&_51$$16);
	ZVAL_UNDEF(&_52$$16);
	ZVAL_UNDEF(&_53$$17);
	ZVAL_UNDEF(&_54$$18);
	ZVAL_UNDEF(&_55$$18);
	ZVAL_UNDEF(&_56$$18);
	ZVAL_UNDEF(&_57$$19);
	ZVAL_UNDEF(&dependency$$20);
	ZVAL_UNDEF(&_59$$20);
	ZVAL_UNDEF(&type$$20);
	ZVAL_UNDEF(&_62$$20);
	ZVAL_UNDEF(&_64$$20);
	ZVAL_UNDEF(&dependencyObject$$21);
	ZVAL_UNDEF(&_66$$21);
	ZVAL_UNDEF(&modelBindingSettings$$21);
	ZVAL_UNDEF(&field$$21);
	ZVAL_UNDEF(&_70$$21);
	ZVAL_UNDEF(&_73$$21);
	ZVAL_UNDEF(&_76$$21);
	ZVAL_UNDEF(&_77$$21);
	ZVAL_UNDEF(&value$$21);
	ZVAL_UNDEF(&_79$$21);
	ZVAL_UNDEF(&modelBound$$21);
	ZVAL_UNDEF(&_80$$21);
	ZVAL_UNDEF(&_78$$23);
	ZVAL_UNDEF(&_82$$24);
	ZVAL_UNDEF(&_83$$24);
	ZVAL_UNDEF(&_84$$24);
	ZVAL_UNDEF(&_85$$24);
	ZVAL_UNDEF(&_86$$25);
	ZVAL_UNDEF(&_87$$25);
	ZVAL_UNDEF(&_88$$25);
	ZVAL_UNDEF(&_89$$25);
	ZVAL_UNDEF(&_90$$26);
	ZVAL_UNDEF(&_92$$26);
	ZVAL_UNDEF(&_93$$27);
	ZVAL_UNDEF(&_95$$28);
	ZVAL_UNDEF(&_96$$29);
	ZVAL_UNDEF(&_97$$29);
	ZVAL_UNDEF(&_98$$30);
	ZVAL_UNDEF(&_99$$30);
	ZVAL_UNDEF(&_100$$31);
	ZVAL_UNDEF(&_101$$31);
	ZVAL_UNDEF(&_102$$31);
	ZVAL_UNDEF(&_103$$32);
	ZVAL_UNDEF(&_104$$33);
	ZVAL_UNDEF(&_105$$33);
	ZVAL_UNDEF(&_106$$33);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(className)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(params)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(request)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &className, &method, &params, &request);
	if (!request) {
		request = &request_sub;
		request = &__$null;
	}


	ZEPHIR_INIT_VAR(&parameters);
	ZVAL_NULL(&parameters);
	ZEPHIR_INIT_VAR(&dependecies);
	array_init(&dependecies);
	ZEPHIR_CALL_CE_STATIC(&app, yuga_application_application_ce, "getinstance", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 8, className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &reflection, "hasmethod", NULL, 9, method);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD(&reflectionMethod$$3, &reflection, "getmethod", NULL, 10, method);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters$$3, &reflectionMethod$$3, "getparameters", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&reflectionParameters$$3, 0, "yuga/Route/Router/Route.zep", 381);
		if (Z_TYPE_P(&reflectionParameters$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionParameters$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&parameter$$3);
				ZVAL_COPY(&parameter$$3, _2$$3);
				ZEPHIR_CALL_METHOD(&_4$$4, &parameter$$3, "gettype", &_5, 0);
				zephir_check_call_status();
				if (!(Z_TYPE_P(&_4$$4) == IS_NULL)) {
					ZEPHIR_CALL_METHOD(&_6$$5, &parameter$$3, "gettype", &_7, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&dependency$$5, &_6$$5, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&type$$5, &parameter$$3, "gettype", &_8, 0);
					zephir_check_call_status();
					zephir_read_property(&_9$$5, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
					_10$$5 = zephir_array_key_exists(params, &_9$$5);
					if (_10$$5) {
						ZEPHIR_CALL_METHOD(&_11$$5, &type$$5, "isbuiltin", &_12, 0);
						zephir_check_call_status();
						_10$$5 = !zephir_is_true(&_11$$5);
					}
					if (_10$$5) {
						ZEPHIR_INIT_NVAR(&dependencyObject$$6);
						zephir_fetch_safe_class(&_13$$6, &dependency$$5);
						_14$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_13$$6), Z_STRLEN_P(&_13$$6), ZEND_FETCH_CLASS_AUTO);
						if(!_14$$6) {
							RETURN_MM_NULL();
						}
						object_init_ex(&dependencyObject$$6, _14$$6);
						if (zephir_has_constructor(&dependencyObject$$6)) {
							ZEPHIR_CALL_METHOD(NULL, &dependencyObject$$6, "__construct", &_15, 0);
							zephir_check_call_status();
						}

						ZEPHIR_CALL_METHOD(&modelBindingSettings$$6, this_ptr, "processbindings", &_16, 0, request);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&field$$6, &dependencyObject$$6, "getprimarykey", &_17, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_18$$6, &dependencyObject$$6, "getroutekeyname", &_19, 0);
						zephir_check_call_status();
						_20$$6 = Z_TYPE_P(&_18$$6) != IS_NULL;
						if (_20$$6) {
							ZEPHIR_CALL_METHOD(&_21$$6, &dependencyObject$$6, "getroutekeyname", &_22, 0);
							zephir_check_call_status();
							_20$$6 = !ZEPHIR_IS_STRING_IDENTICAL(&_21$$6, "");
						}
						if (_20$$6) {
							ZEPHIR_CALL_METHOD(&field$$6, &dependencyObject$$6, "getroutekeyname", &_23, 0);
							zephir_check_call_status();
						}
						zephir_read_property(&_24$$6, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_25$$6);
						zephir_array_keys(&_25$$6, &modelBindingSettings$$6);
						if (zephir_fast_in_array(&_24$$6, &_25$$6)) {
							ZEPHIR_OBS_NVAR(&field$$6);
							ZEPHIR_OBS_NVAR(&_26$$8);
							zephir_read_property(&_26$$8, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_fetch(&field$$6, &modelBindingSettings$$6, &_26$$8, PH_NOISY, "yuga/Route/Router/Route.zep", 345);
						}
						ZEPHIR_OBS_NVAR(&value$$6);
						ZEPHIR_OBS_NVAR(&_27$$6);
						zephir_read_property(&_27$$6, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_fetch(&value$$6, params, &_27$$6, PH_NOISY, "yuga/Route/Router/Route.zep", 348);
						ZEPHIR_CALL_METHOD(&_28$$6, &dependencyObject$$6, "where", &_29, 0, &field$$6, &value$$6);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&modelBound$$6, &_28$$6, "first", NULL, 0);
						zephir_check_call_status();
						if (zephir_is_true(&modelBound$$6)) {
							ZEPHIR_OBS_NVAR(&_30$$9);
							zephir_read_property(&_30$$9, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_update_zval(&dependecies, &_30$$9, &modelBound$$6, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_33$$9);
							ZVAL_STRING(&_33$$9, "MODEL_BIND_VAR");
							ZVAL_BOOL(&_34$$9, 0);
							ZEPHIR_CALL_CE_STATIC(&_31$$9, yuga_support_helpers_ce, "env", &_32, 0, &_33$$9, &_34$$9);
							zephir_check_call_status();
							if (zephir_is_true(&_31$$9)) {
								ZEPHIR_OBS_NVAR(&_36$$10);
								zephir_read_property(&_36$$10, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
								zephir_array_fetch(&_35$$10, params, &_36$$10, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 354);
								zephir_read_property(&_37$$10, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_INIT_NVAR(&_38$$10);
								ZEPHIR_CONCAT_VS(&_38$$10, &_37$$10, "_var");
								zephir_array_update_zval(&dependecies, &_38$$10, &_35$$10, PH_COPY | PH_SEPARATE);
							}
						} else {
							ZEPHIR_INIT_NVAR(&_39$$11);
							if (!_40$$11) {
							_40$$11 = zephir_fetch_class_str_ex(SL("Yuga\\Route\\Router\\ModelNotFoundException"), ZEND_FETCH_CLASS_AUTO);
							}
							object_init_ex(&_39$$11, _40$$11);
							if (zephir_has_constructor(&_39$$11)) {
								ZEPHIR_INIT_NVAR(&_41$$11);
								ZVAL_STRING(&_41$$11, "Model dependency with field = 'value' not found");
								ZEPHIR_CALL_METHOD(NULL, &_39$$11, "__construct", NULL, 0, &_41$$11);
								zephir_check_call_status();
							}

							zephir_throw_exception_debug(&_39$$11, "yuga/Route/Router/Route.zep", 358);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CALL_METHOD(&_42$$12, &type$$5, "isbuiltin", &_43, 0);
						zephir_check_call_status();
						if (!zephir_is_true(&_42$$12)) {
							ZEPHIR_CALL_METHOD(&_44$$13, this_ptr, "issingleton", &_45, 0, &app, &dependency$$5);
							zephir_check_call_status();
							if (zephir_is_true(&_44$$13)) {
								ZEPHIR_CALL_METHOD(&_46$$14, this_ptr, "issingleton", &_45, 0, &app, &dependency$$5);
								zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&_47$$14);
								zephir_read_property(&_47$$14, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
								zephir_array_update_zval(&dependecies, &_47$$14, &_46$$14, PH_COPY | PH_SEPARATE);
							} else {
								ZEPHIR_CALL_METHOD(&_48$$15, &app, "resolve", NULL, 0, &dependency$$5);
								zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&_49$$15);
								zephir_read_property(&_49$$15, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
								zephir_array_update_zval(&dependecies, &_49$$15, &_48$$15, PH_COPY | PH_SEPARATE);
							}
						} else {
							ZEPHIR_OBS_NVAR(&_51$$16);
							zephir_read_property(&_51$$16, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_fetch(&_50$$16, params, &_51$$16, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 369);
							ZEPHIR_OBS_NVAR(&_52$$16);
							zephir_read_property(&_52$$16, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_update_zval(&dependecies, &_52$$16, &_50$$16, PH_COPY | PH_SEPARATE);
						}
					}
				} else {
					zephir_read_property(&_53$$17, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_key_exists(params, &_53$$17)) {
						ZEPHIR_OBS_NVAR(&_55$$18);
						zephir_read_property(&_55$$18, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_fetch(&_54$$18, params, &_55$$18, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 374);
						ZEPHIR_OBS_NVAR(&_56$$18);
						zephir_read_property(&_56$$18, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
						zephir_array_update_zval(&dependecies, &_56$$18, &_54$$18, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &reflectionParameters$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &reflectionParameters$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&parameter$$3, &reflectionParameters$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_57$$19, &parameter$$3, "gettype", &_58, 0);
					zephir_check_call_status();
					if (!(Z_TYPE_P(&_57$$19) == IS_NULL)) {
						ZEPHIR_CALL_METHOD(&_59$$20, &parameter$$3, "gettype", &_60, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&dependency$$20, &_59$$20, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&type$$20, &parameter$$3, "gettype", &_61, 0);
						zephir_check_call_status();
						zephir_read_property(&_62$$20, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
						_63$$20 = zephir_array_key_exists(params, &_62$$20);
						if (_63$$20) {
							ZEPHIR_CALL_METHOD(&_64$$20, &type$$20, "isbuiltin", &_65, 0);
							zephir_check_call_status();
							_63$$20 = !zephir_is_true(&_64$$20);
						}
						if (_63$$20) {
							ZEPHIR_INIT_NVAR(&dependencyObject$$21);
							zephir_fetch_safe_class(&_66$$21, &dependency$$20);
							_67$$21 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_66$$21), Z_STRLEN_P(&_66$$21), ZEND_FETCH_CLASS_AUTO);
							if(!_67$$21) {
								RETURN_MM_NULL();
							}
							object_init_ex(&dependencyObject$$21, _67$$21);
							if (zephir_has_constructor(&dependencyObject$$21)) {
								ZEPHIR_CALL_METHOD(NULL, &dependencyObject$$21, "__construct", &_68, 0);
								zephir_check_call_status();
							}

							ZEPHIR_CALL_METHOD(&modelBindingSettings$$21, this_ptr, "processbindings", &_16, 0, request);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&field$$21, &dependencyObject$$21, "getprimarykey", &_69, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_70$$21, &dependencyObject$$21, "getroutekeyname", &_71, 0);
							zephir_check_call_status();
							_72$$21 = Z_TYPE_P(&_70$$21) != IS_NULL;
							if (_72$$21) {
								ZEPHIR_CALL_METHOD(&_73$$21, &dependencyObject$$21, "getroutekeyname", &_74, 0);
								zephir_check_call_status();
								_72$$21 = !ZEPHIR_IS_STRING_IDENTICAL(&_73$$21, "");
							}
							if (_72$$21) {
								ZEPHIR_CALL_METHOD(&field$$21, &dependencyObject$$21, "getroutekeyname", &_75, 0);
								zephir_check_call_status();
							}
							zephir_read_property(&_76$$21, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_NVAR(&_77$$21);
							zephir_array_keys(&_77$$21, &modelBindingSettings$$21);
							if (zephir_fast_in_array(&_76$$21, &_77$$21)) {
								ZEPHIR_OBS_NVAR(&field$$21);
								ZEPHIR_OBS_NVAR(&_78$$23);
								zephir_read_property(&_78$$23, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
								zephir_array_fetch(&field$$21, &modelBindingSettings$$21, &_78$$23, PH_NOISY, "yuga/Route/Router/Route.zep", 345);
							}
							ZEPHIR_OBS_NVAR(&value$$21);
							ZEPHIR_OBS_NVAR(&_79$$21);
							zephir_read_property(&_79$$21, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_fetch(&value$$21, params, &_79$$21, PH_NOISY, "yuga/Route/Router/Route.zep", 348);
							ZEPHIR_CALL_METHOD(&_80$$21, &dependencyObject$$21, "where", &_81, 0, &field$$21, &value$$21);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&modelBound$$21, &_80$$21, "first", NULL, 0);
							zephir_check_call_status();
							if (zephir_is_true(&modelBound$$21)) {
								ZEPHIR_OBS_NVAR(&_82$$24);
								zephir_read_property(&_82$$24, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
								zephir_array_update_zval(&dependecies, &_82$$24, &modelBound$$21, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_84$$24);
								ZVAL_STRING(&_84$$24, "MODEL_BIND_VAR");
								ZVAL_BOOL(&_85$$24, 0);
								ZEPHIR_CALL_CE_STATIC(&_83$$24, yuga_support_helpers_ce, "env", &_32, 0, &_84$$24, &_85$$24);
								zephir_check_call_status();
								if (zephir_is_true(&_83$$24)) {
									ZEPHIR_OBS_NVAR(&_87$$25);
									zephir_read_property(&_87$$25, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
									zephir_array_fetch(&_86$$25, params, &_87$$25, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 354);
									zephir_read_property(&_88$$25, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_INIT_NVAR(&_89$$25);
									ZEPHIR_CONCAT_VS(&_89$$25, &_88$$25, "_var");
									zephir_array_update_zval(&dependecies, &_89$$25, &_86$$25, PH_COPY | PH_SEPARATE);
								}
							} else {
								ZEPHIR_INIT_NVAR(&_90$$26);
								if (!_91$$26) {
								_91$$26 = zephir_fetch_class_str_ex(SL("Yuga\\Route\\Router\\ModelNotFoundException"), ZEND_FETCH_CLASS_AUTO);
								}
								object_init_ex(&_90$$26, _91$$26);
								if (zephir_has_constructor(&_90$$26)) {
									ZEPHIR_INIT_NVAR(&_92$$26);
									ZVAL_STRING(&_92$$26, "Model dependency with field = 'value' not found");
									ZEPHIR_CALL_METHOD(NULL, &_90$$26, "__construct", NULL, 0, &_92$$26);
									zephir_check_call_status();
								}

								zephir_throw_exception_debug(&_90$$26, "yuga/Route/Router/Route.zep", 358);
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_CALL_METHOD(&_93$$27, &type$$20, "isbuiltin", &_94, 0);
							zephir_check_call_status();
							if (!zephir_is_true(&_93$$27)) {
								ZEPHIR_CALL_METHOD(&_95$$28, this_ptr, "issingleton", &_45, 0, &app, &dependency$$20);
								zephir_check_call_status();
								if (zephir_is_true(&_95$$28)) {
									ZEPHIR_CALL_METHOD(&_96$$29, this_ptr, "issingleton", &_45, 0, &app, &dependency$$20);
									zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&_97$$29);
									zephir_read_property(&_97$$29, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
									zephir_array_update_zval(&dependecies, &_97$$29, &_96$$29, PH_COPY | PH_SEPARATE);
								} else {
									ZEPHIR_CALL_METHOD(&_98$$30, &app, "resolve", NULL, 0, &dependency$$20);
									zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&_99$$30);
									zephir_read_property(&_99$$30, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
									zephir_array_update_zval(&dependecies, &_99$$30, &_98$$30, PH_COPY | PH_SEPARATE);
								}
							} else {
								ZEPHIR_OBS_NVAR(&_101$$31);
								zephir_read_property(&_101$$31, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
								zephir_array_fetch(&_100$$31, params, &_101$$31, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 369);
								ZEPHIR_OBS_NVAR(&_102$$31);
								zephir_read_property(&_102$$31, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
								zephir_array_update_zval(&dependecies, &_102$$31, &_100$$31, PH_COPY | PH_SEPARATE);
							}
						}
					} else {
						zephir_read_property(&_103$$32, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
						if (zephir_array_key_exists(params, &_103$$32)) {
							ZEPHIR_OBS_NVAR(&_105$$33);
							zephir_read_property(&_105$$33, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_fetch(&_104$$33, params, &_105$$33, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 374);
							ZEPHIR_OBS_NVAR(&_106$$33);
							zephir_read_property(&_106$$33, &parameter$$3, ZEND_STRL("name"), PH_NOISY_CC);
							zephir_array_update_zval(&dependecies, &_106$$33, &_104$$33, PH_COPY | PH_SEPARATE);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &reflectionParameters$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&parameter$$3);
	}
	RETURN_CCTOR(&dependecies);
}

PHP_METHOD(Yuga_Route_Router_Route, parseParameters)
{
	zend_bool _47$$18, _50$$20;
	zend_string *_13$$3;
	zend_ulong _12$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_21 = NULL, *_27 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *route, route_sub, *url, url_sub, *parameterRegex = NULL, parameterRegex_sub, __$null, regex, _0, _1, _2, _3, _4, _5, parameters, matches, urlRegex, _6, _42, _43, urlParts$$3, _7$$3, _8$$3, _9$$3, t$$3, key$$3, *_10$$3, _11$$3, regex$$4, _14$$4, _25$$4, _26$$4, _28$$4, name$$5, _15$$5, _16$$5, _19$$5, _20$$5, _22$$5, _23$$5, _24$$5, _17$$6, _18$$9, regex$$10, _29$$10, _39$$10, _40$$10, _41$$10, name$$11, _30$$11, _31$$11, _34$$11, _35$$11, _36$$11, _37$$11, _38$$11, _32$$12, _33$$15, values$$16, name$$17, _44$$17, *_45$$17, _46$$17, _48$$18, _49$$19, _51$$20, _52$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&parameterRegex_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&urlRegex);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&urlParts$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&t$$3);
	ZVAL_UNDEF(&key$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&regex$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_28$$4);
	ZVAL_UNDEF(&name$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&regex$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&name$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_34$$11);
	ZVAL_UNDEF(&_35$$11);
	ZVAL_UNDEF(&_36$$11);
	ZVAL_UNDEF(&_37$$11);
	ZVAL_UNDEF(&_38$$11);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&values$$16);
	ZVAL_UNDEF(&name$$17);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_48$$18);
	ZVAL_UNDEF(&_49$$19);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_52$$21);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(route)
		Z_PARAM_ZVAL(url)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameterRegex)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &route, &url, &parameterRegex);
	if (!parameterRegex) {
		parameterRegex = &parameterRegex_sub;
		parameterRegex = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_1, &_0, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 389);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("paramOptionalSymbol"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 389);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "%s([\\w]+)(\\%s?)%s");
	ZEPHIR_CALL_FUNCTION(&regex, "sprintf", NULL, 4, &_5, &_1, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&parameters);
	array_init(&parameters);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "/");
	ZEPHIR_CALL_FUNCTION(&urlRegex, "preg_quote", NULL, 11, route, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVS(&_6, "/", &regex, "/");
	ZEPHIR_INIT_NVAR(&_5);
	zephir_preg_match(&_5, &_6, route, &parameters, 1, 0 , 0 );
	if (zephir_is_true(&_5)) {
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "/");
		zephir_fast_trim(&_7$$3, route, &_8$$3, ZEPHIR_TRIM_RIGHT);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "/((\\-?\\/?)\\{[^}]+\\})/");
		ZEPHIR_CALL_FUNCTION(&urlParts$$3, "preg_split", NULL, 12, &_9$$3, &_7$$3);
		zephir_check_call_status();
		zephir_is_iterable(&urlParts$$3, 0, "yuga/Route/Router/Route.zep", 427);
		if (Z_TYPE_P(&urlParts$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&urlParts$$3), _12$$3, _13$$3, _10$$3)
			{
				ZEPHIR_INIT_NVAR(&key$$3);
				if (_13$$3 != NULL) { 
					ZVAL_STR_COPY(&key$$3, _13$$3);
				} else {
					ZVAL_LONG(&key$$3, _12$$3);
				}
				ZEPHIR_INIT_NVAR(&t$$3);
				ZVAL_COPY(&t$$3, _10$$3);
				ZEPHIR_INIT_NVAR(&regex$$4);
				ZVAL_STRING(&regex$$4, "");
				zephir_array_fetch_long(&_14$$4, &parameters, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 403);
				if (ZEPHIR_LT_LONG(&key$$3, zephir_fast_count_int(&_14$$4))) {
					zephir_array_fetch_long(&_15$$5, &parameters, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 405);
					ZEPHIR_OBS_NVAR(&name$$5);
					zephir_array_fetch(&name$$5, &_15$$5, &key$$3, PH_NOISY, "yuga/Route/Router/Route.zep", 405);
					zephir_read_property(&_16$$5, this_ptr, ZEND_STRL("where"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_16$$5, &name$$5) == 1) {
						zephir_read_property(&_17$$6, this_ptr, ZEND_STRL("where"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&regex$$4);
						zephir_array_fetch(&regex$$4, &_17$$6, &name$$5, PH_NOISY, "yuga/Route/Router/Route.zep", 409);
					} else {
						if (Z_TYPE_P(parameterRegex) != IS_NULL) {
							ZEPHIR_CPY_WRT(&regex$$4, parameterRegex);
						} else {
							zephir_read_property(&_18$$9, this_ptr, ZEND_STRL("defaultParameterRegex"), PH_NOISY_CC | PH_READONLY);
							if (Z_TYPE_P(&_18$$9) == IS_NULL) {
								ZEPHIR_INIT_NVAR(&regex$$4);
								ZVAL_STRING(&regex$$4, "[\\w]+");
							} else {
								ZEPHIR_OBS_NVAR(&regex$$4);
								zephir_read_property(&regex$$4, this_ptr, ZEND_STRL("defaultParameterRegex"), PH_NOISY_CC);
							}
						}
					}
					ZEPHIR_INIT_NVAR(&_19$$5);
					ZVAL_STRING(&_19$$5, "\\-?\\/?(?P<%s>%s)");
					ZEPHIR_CALL_FUNCTION(&_20$$5, "sprintf", &_21, 4, &_19$$5, &name$$5, &regex$$4);
					zephir_check_call_status();
					zephir_array_fetch_long(&_22$$5, &parameters, 2, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 420);
					zephir_array_fetch(&_23$$5, &_22$$5, &key$$3, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 420);
					ZEPHIR_INIT_NVAR(&_24$$5);
					ZEPHIR_CONCAT_VV(&_24$$5, &_20$$5, &_23$$5);
					ZEPHIR_CPY_WRT(&regex$$4, &_24$$5);
				}
				ZEPHIR_INIT_NVAR(&_25$$4);
				ZVAL_STRING(&_25$$4, "/");
				ZEPHIR_CALL_FUNCTION(&_26$$4, "preg_quote", &_27, 11, &t$$3, &_25$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_28$$4);
				ZEPHIR_CONCAT_VV(&_28$$4, &_26$$4, &regex$$4);
				zephir_array_update_zval(&urlParts$$3, &key$$3, &_28$$4, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &urlParts$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_11$$3, &urlParts$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_11$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key$$3, &urlParts$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&t$$3, &urlParts$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&regex$$10);
					ZVAL_STRING(&regex$$10, "");
					zephir_array_fetch_long(&_29$$10, &parameters, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 403);
					if (ZEPHIR_LT_LONG(&key$$3, zephir_fast_count_int(&_29$$10))) {
						zephir_array_fetch_long(&_30$$11, &parameters, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 405);
						ZEPHIR_OBS_NVAR(&name$$11);
						zephir_array_fetch(&name$$11, &_30$$11, &key$$3, PH_NOISY, "yuga/Route/Router/Route.zep", 405);
						zephir_read_property(&_31$$11, this_ptr, ZEND_STRL("where"), PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset(&_31$$11, &name$$11) == 1) {
							zephir_read_property(&_32$$12, this_ptr, ZEND_STRL("where"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&regex$$10);
							zephir_array_fetch(&regex$$10, &_32$$12, &name$$11, PH_NOISY, "yuga/Route/Router/Route.zep", 409);
						} else {
							if (Z_TYPE_P(parameterRegex) != IS_NULL) {
								ZEPHIR_CPY_WRT(&regex$$10, parameterRegex);
							} else {
								zephir_read_property(&_33$$15, this_ptr, ZEND_STRL("defaultParameterRegex"), PH_NOISY_CC | PH_READONLY);
								if (Z_TYPE_P(&_33$$15) == IS_NULL) {
									ZEPHIR_INIT_NVAR(&regex$$10);
									ZVAL_STRING(&regex$$10, "[\\w]+");
								} else {
									ZEPHIR_OBS_NVAR(&regex$$10);
									zephir_read_property(&regex$$10, this_ptr, ZEND_STRL("defaultParameterRegex"), PH_NOISY_CC);
								}
							}
						}
						ZEPHIR_INIT_NVAR(&_34$$11);
						ZVAL_STRING(&_34$$11, "\\-?\\/?(?P<%s>%s)");
						ZEPHIR_CALL_FUNCTION(&_35$$11, "sprintf", &_21, 4, &_34$$11, &name$$11, &regex$$10);
						zephir_check_call_status();
						zephir_array_fetch_long(&_36$$11, &parameters, 2, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 420);
						zephir_array_fetch(&_37$$11, &_36$$11, &key$$3, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 420);
						ZEPHIR_INIT_NVAR(&_38$$11);
						ZEPHIR_CONCAT_VV(&_38$$11, &_35$$11, &_37$$11);
						ZEPHIR_CPY_WRT(&regex$$10, &_38$$11);
					}
					ZEPHIR_INIT_NVAR(&_39$$10);
					ZVAL_STRING(&_39$$10, "/");
					ZEPHIR_CALL_FUNCTION(&_40$$10, "preg_quote", &_27, 11, &t$$3, &_39$$10);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_41$$10);
					ZEPHIR_CONCAT_VV(&_41$$10, &_40$$10, &regex$$10);
					zephir_array_update_zval(&urlParts$$3, &key$$3, &_41$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &urlParts$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&t$$3);
		ZEPHIR_INIT_NVAR(&key$$3);
		ZEPHIR_INIT_NVAR(&urlRegex);
		zephir_fast_join_str(&urlRegex, SL(""), &urlParts$$3);
	}
	ZEPHIR_INIT_VAR(&_42);
	ZEPHIR_CONCAT_SVS(&_42, "/^", &urlRegex, "(\\/?)/");
	ZEPHIR_INIT_VAR(&_43);
	zephir_preg_match(&_43, &_42, url, &matches, 0, 0 , 0 );
	if (ZEPHIR_GT_LONG(&_43, 0)) {
		ZEPHIR_INIT_VAR(&values$$16);
		array_init(&values$$16);
		if (zephir_array_isset_long(&parameters, 1) == 1) {
			zephir_array_fetch_long(&_44$$17, &parameters, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 438);
			zephir_is_iterable(&_44$$17, 0, "yuga/Route/Router/Route.zep", 446);
			if (Z_TYPE_P(&_44$$17) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_44$$17), _45$$17)
				{
					ZEPHIR_INIT_NVAR(&name$$17);
					ZVAL_COPY(&name$$17, _45$$17);
					zephir_array_update_zval(&values$$16, &name$$17, &__$null, PH_COPY | PH_SEPARATE);
					_47$$18 = zephir_array_isset(&matches, &name$$17);
					if (_47$$18) {
						zephir_array_fetch(&_48$$18, &matches, &name$$17, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 442);
						_47$$18 = !ZEPHIR_IS_STRING_IDENTICAL(&_48$$18, "");
					}
					if (_47$$18) {
						zephir_array_fetch(&_49$$19, &matches, &name$$17, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 443);
						zephir_array_update_zval(&values$$16, &name$$17, &_49$$19, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_44$$17, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_46$$17, &_44$$17, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_46$$17)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&name$$17, &_44$$17, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_update_zval(&values$$16, &name$$17, &__$null, PH_COPY | PH_SEPARATE);
						_50$$20 = zephir_array_isset(&matches, &name$$17);
						if (_50$$20) {
							zephir_array_fetch(&_51$$20, &matches, &name$$17, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 442);
							_50$$20 = !ZEPHIR_IS_STRING_IDENTICAL(&_51$$20, "");
						}
						if (_50$$20) {
							zephir_array_fetch(&_52$$21, &matches, &name$$17, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 443);
							zephir_array_update_zval(&values$$16, &name$$17, &_52$$21, PH_COPY | PH_SEPARATE);
						}
					ZEPHIR_CALL_METHOD(NULL, &_44$$17, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&name$$17);
		}
		RETURN_CCTOR(&values$$16);
	}
	RETURN_MM_NULL();
}

/**
 * Returns callback name/identifier for the current route based on the callback.
 * Useful if you need to get a unique identifier for the loaded route, for instance
 * when using translations etc.
 *
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_Route, getIdentifier)
{
	zend_bool _1;
	zval _0, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) == IS_STRING == 1;
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "@");
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_strpos(&_4, &_2, &_3, 0 );
		_1 = !ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	if (_1) {
		RETURN_MM_MEMBER(getThis(), "callback");
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
	zephir_md5(&_5, &_6);
	ZEPHIR_CONCAT_SV(return_value, "function_", &_5);
	RETURN_MM();
}

/**
 * Set allowed request methods
 *
 * @param array methods
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_Route, setRequestMethods)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *methods_param = NULL;
	zval methods;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(methods)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &methods_param);
	zephir_get_arrval(&methods, methods_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("requestMethods"), &methods);
	RETURN_THIS();
}

/**
 * Get allowed request methods
 *
 * @return array
 */
PHP_METHOD(Yuga_Route_Router_Route, getRequestMethods)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "requestMethods");
}

/**
 * @return IRoute|null
 */
PHP_METHOD(Yuga_Route_Router_Route, getParent)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "parent");
}

/**
 * Get the group for the route.
 *
 * @return IGroupRoute|null
 */
PHP_METHOD(Yuga_Route_Router_Route, getGroup)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "group");
}

/**
 * Set group
 *
 * @param IGroupRoute group
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_Route, setGroup)
{
	zval *group, group_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(group, zephir_get_internal_ce(SL("yuga\\route\\support\\igrouproute")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &group);


	zephir_update_property_zval(this_ptr, ZEND_STRL("group"), group);
	RETURN_THISW();
}

/**
 * Set parent route
 *
 * @param IRoute parent
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_Route, setParent)
{
	zval *parent, parent_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parent_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(parent, zephir_get_internal_ce(SL("yuga\\route\\support\\iroute")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &parent);


	zephir_update_property_zval(this_ptr, ZEND_STRL("parent"), parent);
	RETURN_THISW();
}

/**
 * Set callback
 *
 * @param string callback
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_Route, setCallback)
{
	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &callback);


	zephir_update_property_zval(this_ptr, ZEND_STRL("callback"), callback);
	RETURN_THISW();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_Route, getCallback)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "callback");
}

PHP_METHOD(Yuga_Route_Router_Route, getMethod)
{
	zend_bool _1;
	zval _0, _2, _3, _4, tmp$$3, _5$$3, _6$$3, _7$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&tmp$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) == IS_STRING == 1;
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "@");
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_strpos(&_4, &_2, &_3, 0 );
		_1 = !ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	if (_1) {
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "@");
		ZEPHIR_INIT_VAR(&tmp$$3);
		zephir_fast_explode(&tmp$$3, &_6$$3, &_5$$3, LONG_MAX);
		zephir_array_fetch_long(&_7$$3, &tmp$$3, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 563);
		RETURN_CTOR(&_7$$3);
	}
	RETURN_MM_NULL();
}

PHP_METHOD(Yuga_Route_Router_Route, getClass)
{
	zend_bool _1;
	zval _0, _2, _3, _4, tmp$$3, _5$$3, _6$$3, _7$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&tmp$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) == IS_STRING == 1;
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "@");
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_strpos(&_4, &_2, &_3, 0 );
		_1 = !ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	if (_1) {
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "@");
		ZEPHIR_INIT_VAR(&tmp$$3);
		zephir_fast_explode(&tmp$$3, &_6$$3, &_5$$3, LONG_MAX);
		zephir_array_fetch_long(&_7$$3, &tmp$$3, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 574);
		RETURN_CTOR(&_7$$3);
	}
	RETURN_MM_NULL();
}

PHP_METHOD(Yuga_Route_Router_Route, setMethod)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclass", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "%s@%s");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 4, &_1, &_0, method);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("callback"), &_2);
	RETURN_THIS();
}

PHP_METHOD(Yuga_Route_Router_Route, setClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className, className_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(className)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "%s@%s");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 4, &_1, className, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("callback"), &_2);
	RETURN_THIS();
}

/**
 * @param string namespace
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_Route, setNamespace)
{
	zval *namespaceValue, namespaceValue_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceValue_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(namespaceValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &namespaceValue);


	zephir_update_property_zval(this_ptr, ZEND_STRL("namespaceValue"), namespaceValue);
	RETURN_THISW();
}

/**
 * @param string namespace
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_Route, setDefaultNamespace)
{
	zval *namespaceValue, namespaceValue_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceValue_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(namespaceValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &namespaceValue);


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultNamespace"), namespaceValue);
	RETURN_THISW();
}

PHP_METHOD(Yuga_Route_Router_Route, getDefaultNamespace)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultNamespace");
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_Route, getNamespace)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaceValue"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MEMBER(getThis(), "defaultNamespace");
	}
	RETURN_MEMBER(getThis(), "namespaceValue");
}

/**
 * Export route settings to array so they can be merged with another route.
 *
 * @return array
 */
PHP_METHOD(Yuga_Route_Router_Route, toArray)
{
	zval values, _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaceValue"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("namespaceValue"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&values, SL("namespace"), &_1$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("requestMethods"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_2) > 0) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("requestMethods"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&values, SL("method"), &_3$$4, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("where"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_4) > 0) {
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("where"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&values, SL("where"), &_5$$5, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("middlewares"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_6) > 0) {
		zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("middlewares"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&values, SL("middleware"), &_7$$6, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("defaultParameterRegex"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_8) != IS_NULL) {
		zephir_read_property(&_9$$7, this_ptr, ZEND_STRL("defaultParameterRegex"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&values, SL("defaultParameterRegex"), &_9$$7, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&values);
}

/**
 * Merge with information from another route.
 *
 * @param array values
 * @param bool merge
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_Route, setSettings)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *merge = NULL, merge_sub, __$false, _0, _2$$3, _3$$4, _4$$4, _5$$4, _7$$5, _8$$5, _9$$5, _11$$6, _12$$6, _13$$6, _15$$7, _16$$7, _18$$7, _19$$8;
	zval values, _6$$4, _10$$5, _14$$6, _17$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&merge_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(values)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &merge);
	zephir_get_arrval(&values, values_param);
	if (!merge) {
		merge = &merge_sub;
		merge = &__$false;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaceValue"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) == IS_NULL;
	if (_1) {
		_1 = zephir_array_isset_string(&values, SL("namespace"));
	}
	if (_1) {
		zephir_array_fetch_string(&_2$$3, &values, SL("namespace"), PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 675);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setnamespace", NULL, 0, &_2$$3);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&values, SL("method"))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("requestMethods"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_5$$4);
		zephir_array_fetch_string(&_5$$4, &values, SL("method"), PH_NOISY, "yuga/Route/Router/Route.zep", 679);
		zephir_get_arrval(&_6$$4, &_5$$4);
		zephir_fast_array_merge(&_3$$4, &_4$$4, &_6$$4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrequestmethods", NULL, 0, &_3$$4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&values, SL("where"))) {
		ZEPHIR_INIT_VAR(&_7$$5);
		zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("where"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_9$$5);
		zephir_array_fetch_string(&_9$$5, &values, SL("where"), PH_NOISY, "yuga/Route/Router/Route.zep", 683);
		zephir_get_arrval(&_10$$5, &_9$$5);
		zephir_fast_array_merge(&_7$$5, &_8$$5, &_10$$5);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setwhere", NULL, 0, &_7$$5);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&values, SL("parameters"))) {
		ZEPHIR_INIT_VAR(&_11$$6);
		zephir_read_property(&_12$$6, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_13$$6);
		zephir_array_fetch_string(&_13$$6, &values, SL("parameters"), PH_NOISY, "yuga/Route/Router/Route.zep", 687);
		zephir_get_arrval(&_14$$6, &_13$$6);
		zephir_fast_array_merge(&_11$$6, &_12$$6, &_14$$6);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparameters", NULL, 0, &_11$$6);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&values, SL("middleware"))) {
		ZEPHIR_INIT_VAR(&_15$$7);
		ZEPHIR_OBS_VAR(&_16$$7);
		zephir_array_fetch_string(&_16$$7, &values, SL("middleware"), PH_NOISY, "yuga/Route/Router/Route.zep", 692);
		zephir_get_arrval(&_17$$7, &_16$$7);
		zephir_read_property(&_18$$7, this_ptr, ZEND_STRL("middlewares"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_15$$7, &_17$$7, &_18$$7);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmiddlewares", NULL, 0, &_15$$7);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&values, SL("defaultParameterRegex"))) {
		zephir_array_fetch_string(&_19$$8, &values, SL("defaultParameterRegex"), PH_NOISY | PH_READONLY, "yuga/Route/Router/Route.zep", 696);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultparameterregex", NULL, 0, &_19$$8);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Get parameter names.
 *
 * @return array
 */
PHP_METHOD(Yuga_Route_Router_Route, getWhere)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "where");
}

/**
 * Set parameter names.
 *
 * @param array options
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_Route, setWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("where"), &options);
	RETURN_THIS();
}

/**
 * Add regular expression parameter match.
 * Alias for LoadableRoute::where()
 *
 * @see LoadableRoute::where()
 * @param array options
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_Route, where)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setwhere", NULL, 0, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get parameters
 *
 * @return array
 */
PHP_METHOD(Yuga_Route_Router_Route, getParameters)
{
	zval parameters, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&parameters);
	array_init(&parameters);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0) > 0) {
		ZEPHIR_OBS_NVAR(&parameters);
		zephir_read_property(&parameters, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(return_value, &parameters, &_1);
	RETURN_MM();
}

/**
 * Get parameters
 *
 * @param array parameters
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_Route, setParameters)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *parameters_param = NULL, _1, _2, _3;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);
	zephir_get_arrval(&parameters, parameters_param);


	_0 = zephir_fast_count_int(&parameters) > 0;
	if (_0) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_fast_count_int(&_1) == 0;
	}
	if (_0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("originalParameters"), &parameters);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_2, &_3, &parameters);
	zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &_2);
	RETURN_THIS();
}

/**
 * Add middleware class-name
 *
 * @deprecated This method is deprecated and will be removed in the near future.
 * @param IMiddleware|string middleware
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_Route, setMiddleware)
{
	zval *middleware, middleware_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middleware_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(middleware)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &middleware);


	zephir_update_property_array_append(this_ptr, SL("middlewares"), middleware);
	RETURN_THISW();
}

/**
 * Add middleware class-name
 *
 * @param IMiddleware|string middleware
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_Route, addMiddleware)
{
	zval *middleware, middleware_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middleware_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(middleware)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &middleware);


	zephir_update_property_array_append(this_ptr, SL("middlewares"), middleware);
	RETURN_THISW();
}

/**
 * Set middlewares array
 *
 * @param array middlewares
 * @return this
 */
PHP_METHOD(Yuga_Route_Router_Route, setMiddlewares)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *middlewares_param = NULL;
	zval middlewares;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middlewares);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(middlewares)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &middlewares_param);
	zephir_get_arrval(&middlewares, middlewares_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("middlewares"), &middlewares);
	RETURN_THIS();
}

/**
 * @return string|array
 */
PHP_METHOD(Yuga_Route_Router_Route, getMiddlewares)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "middlewares");
}

/**
 * Set default regular expression used when matching parameters.
 * This is used when no custom parameter regex is found.
 *
 * @param string regex
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_Route, setDefaultParameterRegex)
{
	zval *regex, regex_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&regex_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(regex)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &regex);


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultParameterRegex"), regex);
	RETURN_THISW();
}

/**
 * Get default regular expression used when matching parameters.
 *
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_Route, getDefaultParameterRegex)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultParameterRegex");
}

void zephir_init_static_properties_Yuga_Route_Router_Route()
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 6, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "get");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "post");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "put");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "patch");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "options");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "delete");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_static_property_ce(yuga_route_router_route_ce, ZEND_STRL("requestTypes"), &_0);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Yuga_Route_Router_Route(zend_class_entry *class_type)
{
		zval _11$$8;
	zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _12$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_11$$8);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("middlewares"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("middlewares"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("originalParameters"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("parameters"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("where"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("where"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("requestMethods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("requestMethods"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			zephir_create_array(&_11$$8, 2, 0);
			ZEPHIR_INIT_VAR(&_12$$8);
			ZVAL_STRING(&_12$$8, "{");
			zephir_array_fast_append(&_11$$8, &_12$$8);
			ZEPHIR_INIT_NVAR(&_12$$8);
			ZVAL_STRING(&_12$$8, "}");
			zephir_array_fast_append(&_11$$8, &_12$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("paramModifiers"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

