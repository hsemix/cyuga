
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Router_RouteController)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Route\\Router, RouteController, yuga, route_router_routecontroller, yuga_route_router_loadableroute_ce, yuga_route_router_routecontroller_method_entry, 0);

	zend_declare_property_string(yuga_route_router_routecontroller_ce, SL("defaultMethod"), "index", ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_routecontroller_ce, SL("controller"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_routecontroller_ce, SL("method"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_routecontroller_ce, SL("names"), ZEND_ACC_PROTECTED);
	yuga_route_router_routecontroller_ce->create_object = zephir_init_properties_Yuga_Route_Router_RouteController;

	zend_class_implements(yuga_route_router_routecontroller_ce, 1, yuga_route_support_icontrollerroute_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Route_Router_RouteController, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, *controller, controller_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&controller_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(controller)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url, &controller);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seturl", NULL, 0, url);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, ".");
	zephir_fast_str_replace(&_1, &_2, &_3, url);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/");
	zephir_fast_trim(&_0, &_1, &_4, ZEPHIR_TRIM_BOTH);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setname", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("controller"), controller);
	ZEPHIR_MM_RESTORE();
}

/**
 * Check if route has given name.
 *
 * @param string name
 * @return bool
 */
PHP_METHOD(Yuga_Route_Router_RouteController, hasName)
{
	zend_bool _11$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_14 = NULL;
	zval *name, name_sub, __$false, _0, _1, _2, method$$4, newName$$4, _3$$4, _4$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _12$$4, _13$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&method$$4);
	ZVAL_UNDEF(&newName$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ".");
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, name, &_1, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, ".");
		ZEPHIR_CALL_FUNCTION(&_4$$4, "strrpos", &_5, 94, name, &_3$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$4, (zephir_get_numberval(&_4$$4) + 1));
		ZEPHIR_INIT_VAR(&method$$4);
		zephir_substr(&method$$4, name, zephir_get_intval(&_6$$4), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, ".");
		ZEPHIR_CALL_FUNCTION(&_7$$4, "strrpos", &_5, 94, name, &_3$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$4, 0);
		ZEPHIR_INIT_VAR(&newName$$4);
		zephir_substr(&newName$$4, name, 0 , zephir_get_intval(&_7$$4), 0);
		zephir_read_property(&_9$$4, this_ptr, ZEND_STRL("names"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_10$$4, "in_array", NULL, 52, &method$$4, &_9$$4, &__$false);
		zephir_check_call_status();
		_11$$4 = ZEPHIR_IS_TRUE_IDENTICAL(&_10$$4);
		if (_11$$4) {
			ZEPHIR_INIT_NVAR(&_3$$4);
			zephir_read_property(&_12$$4, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			zephir_fast_strtolower(&_3$$4, &_12$$4);
			ZEPHIR_INIT_VAR(&_13$$4);
			zephir_fast_strtolower(&_13$$4, &newName$$4);
			_11$$4 = ZEPHIR_IS_IDENTICAL(&_3$$4, &_13$$4);
		}
		if (_11$$4) {
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_RETURN_CALL_PARENT(yuga_route_router_routecontroller_ce, getThis(), "hasname", &_14, 0, name);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string|null method
 * @param string|array|null parameters
 * @param string|null name
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_RouteController, findUrl)
{
	zval _6$$4, _15$$7, _19$$9;
	zend_bool _20;
	zval _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, *parameters = NULL, parameters_sub, *name = NULL, name_sub, __$false, __$null, _0, _1, url, requestType, group, _21, _25, _26, _27, _28, _29, _30, _31, _32, found$$3, _2$$3, _3$$3, _4$$3, _5$$3, requestTypes$$5, _8$$5, *_9$$5, _10$$5, _11$$6, _13$$7, _14$$7, _16$$8, _17$$9, _18$$9, _22$$10, _23$$10, _24$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&requestType);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&found$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&requestTypes$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_19$$9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(method)
		Z_PARAM_ZVAL_OR_NULL(parameters)
		Z_PARAM_ZVAL_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &method, &parameters, &name);
	if (!method) {
		method = &method_sub;
		ZEPHIR_CPY_WRT(method, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(method);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		ZEPHIR_CPY_WRT(parameters, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(parameters);
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, ".");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, name, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, ".");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "strrpos", NULL, 94, name, &_2$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, (zephir_get_numberval(&_3$$3) + 1));
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_substr(&_2$$3, name, zephir_get_intval(&_4$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("names"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&found$$3, "array_search", NULL, 95, &_2$$3, &_5$$3, &__$false);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&found$$3)) {
			zephir_cast_to_string(&_6$$4, &found$$3);
			ZEPHIR_CPY_WRT(method, &_6$$4);
		}
	}
	ZEPHIR_INIT_VAR(&url);
	ZVAL_STRING(&url, "");
	zephir_get_arrval(&_7, parameters);
	ZEPHIR_CPY_WRT(parameters, &_7);
	if (Z_TYPE_P(method) != IS_NULL) {
		ZEPHIR_OBS_VAR(&_8$$5);
		zephir_read_static_property_ce(&_8$$5, yuga_route_router_routecontroller_ce, SL("requestTypes"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(&requestTypes$$5, &_8$$5);
		zephir_is_iterable(&requestTypes$$5, 0, "yuga/Route/Router/RouteController.zep", 76);
		if (Z_TYPE_P(&requestTypes$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&requestTypes$$5), _9$$5)
			{
				ZEPHIR_INIT_NVAR(&requestType);
				ZVAL_COPY(&requestType, _9$$5);
				ZEPHIR_CALL_FUNCTION(&_11$$6, "stripos", &_12, 14, method, &requestType);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_11$$6, 0)) {
					ZVAL_LONG(&_13$$7, zephir_fast_strlen_ev(&requestType));
					ZEPHIR_INIT_NVAR(&_14$$7);
					zephir_substr(&_14$$7, method, zephir_get_intval(&_13$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_cast_to_string(&_15$$7, &_14$$7);
					ZEPHIR_CPY_WRT(method, &_15$$7);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &requestTypes$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$5, &requestTypes$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&requestType, &requestTypes$$5, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_16$$8, "stripos", &_12, 14, method, &requestType);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_16$$8, 0)) {
						ZVAL_LONG(&_17$$9, zephir_fast_strlen_ev(&requestType));
						ZEPHIR_INIT_NVAR(&_18$$9);
						zephir_substr(&_18$$9, method, zephir_get_intval(&_17$$9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_cast_to_string(&_19$$9, &_18$$9);
						ZEPHIR_CPY_WRT(method, &_19$$9);
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, &requestTypes$$5, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&requestType);
		zephir_concat_self_str(&method, SL("/"));
	}
	ZEPHIR_CALL_METHOD(&group, this_ptr, "getgroup", NULL, 0);
	zephir_check_call_status();
	_20 = Z_TYPE_P(&group) != IS_NULL;
	if (_20) {
		ZEPHIR_CALL_METHOD(&_21, &group, "getdomains", NULL, 0);
		zephir_check_call_status();
		_20 = zephir_fast_count_int(&_21) > 0;
	}
	if (_20) {
		ZEPHIR_CALL_METHOD(&_22$$10, &group, "getdomains", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_long(&_23$$10, &_22$$10, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteController.zep", 82);
		ZEPHIR_INIT_VAR(&_24$$10);
		ZEPHIR_CONCAT_SV(&_24$$10, "//", &_23$$10);
		zephir_concat_self(&url, &_24$$10);
	}
	ZEPHIR_INIT_VAR(&_25);
	ZEPHIR_CALL_METHOD(&_26, this_ptr, "geturl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_STRING(&_27, "/");
	zephir_fast_trim(&_25, &_26, &_27, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_28);
	zephir_fast_strtolower(&_28, method);
	ZEPHIR_INIT_VAR(&_29);
	zephir_fast_join_str(&_29, SL("/"), parameters);
	ZEPHIR_INIT_VAR(&_30);
	ZEPHIR_CONCAT_SVSVV(&_30, "/", &_25, "/", &_28, &_29);
	zephir_concat_self(&url, &_30);
	ZEPHIR_INIT_VAR(&_31);
	ZEPHIR_INIT_VAR(&_32);
	ZVAL_STRING(&_32, "/");
	zephir_fast_trim(&_31, &url, &_32, ZEPHIR_TRIM_BOTH);
	ZEPHIR_CONCAT_SVS(return_value, "/", &_31, "/");
	RETURN_MM();
}

PHP_METHOD(Yuga_Route_Router_RouteController, matchRoute)
{
	zend_bool _0, _3, _10$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, *request, request_sub, regexMatch, strippedUrl, path, _1, _2, _4, _5, _6, _7, _8, _9, method$$4, _11$$4, _12$$4, _13$$4, _14$$4, _15$$4, _16$$4, _17$$4, _18$$4, _19$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&regexMatch);
	ZVAL_UNDEF(&strippedUrl);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&method$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(url)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url, &request);


	ZEPHIR_CALL_METHOD(&regexMatch, this_ptr, "matchregex", NULL, 0, request, url);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(&regexMatch);
	if (!(_0)) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_2, "stripos", NULL, 14, url, &_1);
		zephir_check_call_status();
		_3 = !ZEPHIR_IS_LONG_IDENTICAL(&_2, 0);
		if (_3) {
			ZEPHIR_INIT_VAR(&_4);
			zephir_fast_strtolower(&_4, url);
			ZEPHIR_INIT_VAR(&_5);
			zephir_read_property(&_6, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
			zephir_fast_strtolower(&_5, &_6);
			_3 = !ZEPHIR_IS_IDENTICAL(&_4, &_5);
		}
		_0 = _3;
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "/");
	ZEPHIR_CALL_FUNCTION(&_9, "str_ireplace", NULL, 15, &_7, &_8, url);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "/");
	ZEPHIR_INIT_VAR(&strippedUrl);
	zephir_fast_trim(&strippedUrl, &_9, &_8, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&path);
	zephir_fast_explode_str(&path, SL("/"), &strippedUrl, LONG_MAX);
	if (zephir_fast_count_int(&path) > 0) {
		_10$$4 = zephir_array_isset_long(&path, 0) == 0;
		if (!(_10$$4)) {
			ZEPHIR_INIT_VAR(&_11$$4);
			zephir_array_fetch_long(&_12$$4, &path, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteController.zep", 105);
			zephir_fast_trim(&_11$$4, &_12$$4, NULL , ZEPHIR_TRIM_BOTH);
			_10$$4 = ZEPHIR_IS_STRING_IDENTICAL(&_11$$4, "");
		}
		if (_10$$4) {
			ZEPHIR_OBS_VAR(&method$$4);
			zephir_read_property(&method$$4, this_ptr, ZEND_STRL("defaultMethod"), PH_NOISY_CC);
		} else {
			ZEPHIR_OBS_NVAR(&method$$4);
			zephir_array_fetch_long(&method$$4, &path, 0, PH_NOISY, "yuga/Route/Router/RouteController.zep", 105);
		}
		ZEPHIR_CALL_METHOD(&_13$$4, request, "getmethod", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_14$$4);
		zephir_ucfirst(&_14$$4, &method$$4);
		ZEPHIR_INIT_VAR(&_15$$4);
		ZEPHIR_CONCAT_VV(&_15$$4, &_13$$4, &_14$$4);
		zephir_update_property_zval(this_ptr, ZEND_STRL("method"), &_15$$4);
		ZVAL_LONG(&_16$$4, 1);
		ZEPHIR_CALL_FUNCTION(&_17$$4, "array_slice", NULL, 96, &path, &_16$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &_17$$4);
		zephir_read_property(&_16$$4, this_ptr, ZEND_STRL("controller"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_18$$4, this_ptr, ZEND_STRL("method"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_19$$4);
		ZEPHIR_CONCAT_VSV(&_19$$4, &_16$$4, "@", &_18$$4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcallback", NULL, 0, &_19$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

/**
 * Get controller class-name.
 *
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_RouteController, getController)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "controller");
}

/**
 * Get controller class-name.
 *
 * @param string controller
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_RouteController, setController)
{
	zval *controller, controller_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controller_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(controller)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &controller);


	zephir_update_property_zval(this_ptr, ZEND_STRL("controller"), controller);
	RETURN_THISW();
}

/**
 * Return active method
 *
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_RouteController, getMethod)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "method");
}

/**
 * Set active method
 *
 * @param string method
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_RouteController, setMethod)
{
	zval *method, method_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &method);


	zephir_update_property_zval(this_ptr, ZEND_STRL("method"), method);
	RETURN_THISW();
}

/**
 * Merge with information from another route.
 *
 * @param array values
 * @param bool merge
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_RouteController, setSettings)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *values_param = NULL, *merge = NULL, merge_sub, __$false, _0$$3;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&merge_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0$$3);
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


	if (zephir_array_isset_string(&values, SL("names"))) {
		zephir_array_fetch_string(&_0$$3, &values, SL("names"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteController.zep", 175);
		zephir_update_property_zval(this_ptr, ZEND_STRL("names"), &_0$$3);
	}
	ZEPHIR_CALL_PARENT(NULL, yuga_route_router_routecontroller_ce, getThis(), "setsettings", &_1, 0, &values, merge);
	zephir_check_call_status();
	RETURN_THIS();
}

zend_object *zephir_init_properties_Yuga_Route_Router_RouteController(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("names"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("names"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

