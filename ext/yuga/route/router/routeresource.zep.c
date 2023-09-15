
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Router_RouteResource)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Route\\Router, RouteResource, yuga, route_router_routeresource, yuga_route_router_loadableroute_ce, yuga_route_router_routeresource_method_entry, 0);

	zend_declare_property_null(yuga_route_router_routeresource_ce, SL("urls"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_routeresource_ce, SL("methodNames"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_routeresource_ce, SL("names"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_routeresource_ce, SL("controller"), ZEND_ACC_PROTECTED);
	yuga_route_router_routeresource_ce->create_object = zephir_init_properties_Yuga_Route_Router_RouteResource;

	zend_class_implements(yuga_route_router_routeresource_ce, 1, yuga_route_support_icontrollerroute_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Route_Router_RouteResource, __construct)
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("controller"), controller);
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
	ZEPHIR_MM_RESTORE();
}

/**
 * Check if route has given name.
 *
 * @param string name
 * @return bool
 */
PHP_METHOD(Yuga_Route_Router_RouteResource, hasName)
{
	zval _9$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, _0, _1, _2, _3, _4, _5, _10, _11, _12, _6$$5, _7$$5, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);
	ZEPHIR_SEPARATE_PARAM(name);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_strtolower(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_strtolower(&_3, name);
	if (ZEPHIR_IS_IDENTICAL(&_1, &_3)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, ".");
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_strpos(&_5, name, &_4, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_5)) {
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, ".");
		ZEPHIR_CALL_FUNCTION(&_7$$5, "strrpos", NULL, 94, name, &_6$$5);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$5, 0);
		ZEPHIR_INIT_NVAR(&_6$$5);
		zephir_substr(&_6$$5, name, 0 , zephir_get_intval(&_7$$5), 0);
		zephir_cast_to_string(&_9$$5, &_6$$5);
		ZEPHIR_CPY_WRT(name, &_9$$5);
	}
	ZEPHIR_INIT_VAR(&_10);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_strtolower(&_10, &_11);
	ZEPHIR_INIT_VAR(&_12);
	zephir_fast_strtolower(&_12, name);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_10, &_12));
}

PHP_METHOD(Yuga_Route_Router_RouteResource, findUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, *parameters = NULL, parameters_sub, *name = NULL, name_sub, __$false, __$null, url, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
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
		method = &__$null;
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("names"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&url, "array_search", NULL, 95, name, &_0, &__$false);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&url)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("urls"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$3, &_3$$3, &url, PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 67);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_VV(&_5$$3, &_2$$3, &_4$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "/");
		zephir_fast_trim(&_1$$3, &_5$$3, &_6$$3, ZEPHIR_TRIM_RIGHT);
		ZEPHIR_CONCAT_VS(return_value, &_1$$3, "/");
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "url");
}

PHP_METHOD(Yuga_Route_Router_RouteResource, call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("controller"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &_0, "@", method);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcallback", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);
}

PHP_METHOD(Yuga_Route_Router_RouteResource, matchRoute)
{
	zval _28;
	zend_bool _5, _7, _15, _23, _27, _33, _34, _37, _42;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url = NULL, url_sub, *request, request_sub, __$false, route, action, id, method, _0, _1, _2, _3, _4, regexMatch, _6, _8, _9, _10, _11, _12, _13, _14, _16, _17, _18, _19, _20, _21, _22, _29, _30, _45, _46, _24$$5, _25$$5, _31$$6, _32$$6, _35$$7, _36$$7, _38$$8, _39$$8, _40$$9, _41$$9, _43$$10, _44$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&regexMatch);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_36$$7);
	ZVAL_UNDEF(&_38$$8);
	ZVAL_UNDEF(&_39$$8);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_28);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(url)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url, &request);
	ZEPHIR_SEPARATE_PARAM(url);


	ZEPHIR_CALL_FUNCTION(&_0, "urldecode", NULL, 97, url);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 5);
	ZEPHIR_CALL_FUNCTION(url, "parse_url", NULL, 75, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/");
	zephir_fast_trim(&_2, url, &_3, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_2, "/");
	ZEPHIR_CPY_WRT(url, &_4);
	ZEPHIR_CALL_METHOD(&regexMatch, this_ptr, "matchregex", NULL, 0, request, url);
	zephir_check_call_status();
	_5 = ZEPHIR_IS_FALSE_IDENTICAL(&regexMatch);
	if (!(_5)) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_6, "stripos", NULL, 14, url, &_1);
		zephir_check_call_status();
		_7 = !ZEPHIR_IS_LONG_IDENTICAL(&_6, 0);
		if (_7) {
			ZEPHIR_INIT_VAR(&_8);
			zephir_fast_strtolower(&_8, url);
			ZEPHIR_INIT_VAR(&_9);
			zephir_read_property(&_10, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
			zephir_fast_strtolower(&_9, &_10);
			_7 = !ZEPHIR_IS_IDENTICAL(&_8, &_9);
		}
		_5 = _7;
	}
	if (_5) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_11);
	zephir_read_property(&_12, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "/");
	zephir_fast_trim(&_11, &_12, &_13, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&route);
	ZEPHIR_CONCAT_VS(&route, &_11, "/{id?}/{action?}");
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "parseparameters", NULL, 0, &route, url);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &_14);
	_15 = Z_TYPE_P(&regexMatch) == IS_NULL;
	if (_15) {
		zephir_read_property(&_16, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		_15 = Z_TYPE_P(&_16) == IS_NULL;
	}
	if (_15) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_17);
	zephir_read_property(&_18, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_19, &_18, SL("action"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 103);
	zephir_fast_trim(&_17, &_19, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&action);
	zephir_fast_strtolower(&action, &_17);
	zephir_read_property(&_20, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&id);
	zephir_array_fetch_string(&id, &_20, SL("id"), PH_NOISY, "yuga/Route/Router/RouteResource.zep", 104);
	zephir_read_property(&_21, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	ZVAL_STR(&_21, "action");
	zephir_unset_property_array(this_ptr, ZEND_STRL("parameters"), &_21);
	zephir_read_property(&_22, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset_string(&_22, SL("action"), PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	_23 = ZEPHIR_IS_STRING_IDENTICAL(&method, "delete");
	if (_23) {
		_23 = Z_TYPE_P(&id) != IS_NULL;
	}
	if (_23) {
		zephir_read_property(&_24$$5, this_ptr, ZEND_STRL("methodNames"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_25$$5, &_24$$5, SL("destroy"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 113);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "call", &_26, 0, &_25$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	_27 = Z_TYPE_P(&id) != IS_NULL;
	if (_27) {
		ZEPHIR_INIT_VAR(&_28);
		zephir_create_array(&_28, 2, 0);
		ZEPHIR_INIT_VAR(&_29);
		ZVAL_STRING(&_29, "patch");
		zephir_array_fast_append(&_28, &_29);
		ZEPHIR_INIT_NVAR(&_29);
		ZVAL_STRING(&_29, "put");
		zephir_array_fast_append(&_28, &_29);
		ZEPHIR_CALL_FUNCTION(&_30, "in_array", NULL, 52, &method, &_28, &__$false);
		zephir_check_call_status();
		_27 = ZEPHIR_IS_TRUE_IDENTICAL(&_30);
	}
	if (_27) {
		zephir_read_property(&_31$$6, this_ptr, ZEND_STRL("methodNames"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_32$$6, &_31$$6, SL("update"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 118);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "call", &_26, 0, &_32$$6);
		zephir_check_call_status();
		RETURN_MM();
	}
	_33 = ZEPHIR_IS_STRING_IDENTICAL(&method, "get");
	if (_33) {
		_33 = Z_TYPE_P(&id) != IS_NULL;
	}
	_34 = _33;
	if (_34) {
		_34 = ZEPHIR_IS_STRING_IDENTICAL(&action, "edit");
	}
	if (_34) {
		zephir_read_property(&_35$$7, this_ptr, ZEND_STRL("methodNames"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_36$$7, &_35$$7, SL("edit"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 123);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "call", &_26, 0, &_36$$7);
		zephir_check_call_status();
		RETURN_MM();
	}
	_37 = ZEPHIR_IS_STRING_IDENTICAL(&method, "get");
	if (_37) {
		_37 = ZEPHIR_IS_STRING_IDENTICAL(&id, "create");
	}
	if (_37) {
		zephir_read_property(&_38$$8, this_ptr, ZEND_STRL("methodNames"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_39$$8, &_38$$8, SL("create"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 128);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "call", &_26, 0, &_39$$8);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&method, "post")) {
		zephir_read_property(&_40$$9, this_ptr, ZEND_STRL("methodNames"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_41$$9, &_40$$9, SL("store"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 133);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "call", &_26, 0, &_41$$9);
		zephir_check_call_status();
		RETURN_MM();
	}
	_42 = ZEPHIR_IS_STRING_IDENTICAL(&method, "get");
	if (_42) {
		_42 = Z_TYPE_P(&id) != IS_NULL;
	}
	if (_42) {
		zephir_read_property(&_43$$10, this_ptr, ZEND_STRL("methodNames"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_44$$10, &_43$$10, SL("show"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 138);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "call", &_26, 0, &_44$$10);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_45, this_ptr, ZEND_STRL("methodNames"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_46, &_45, SL("index"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 142);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "call", &_26, 0, &_46);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_RouteResource, getController)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "controller");
}

/**
 * @param string controller
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_RouteResource, setController)
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

PHP_METHOD(Yuga_Route_Router_RouteResource, setName)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name, name_sub, _1, _2, _3, _4, _5, _6, _7, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), name);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 7, 0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_1, ".index");
	zephir_array_update_string(&_0, SL("index"), &_2, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_3, ".create");
	zephir_array_update_string(&_0, SL("create"), &_2, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_4, ".store");
	zephir_array_update_string(&_0, SL("store"), &_2, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_5, ".show");
	zephir_array_update_string(&_0, SL("show"), &_2, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_6, ".edit");
	zephir_array_update_string(&_0, SL("edit"), &_2, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_7, ".update");
	zephir_array_update_string(&_0, SL("update"), &_2, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_8, ".destroy");
	zephir_array_update_string(&_0, SL("destroy"), &_2, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("names"), &_0);
	RETURN_THIS();
}

/**
 * Define custom method name for resource controller
 *
 * @param array names
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_RouteResource, setMethodNames)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *names_param = NULL;
	zval names;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&names);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(names)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &names_param);
	zephir_get_arrval(&names, names_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("methodNames"), &names);
	RETURN_THIS();
}

/**
 * Get method names
 *
 * @return array this
 */
PHP_METHOD(Yuga_Route_Router_RouteResource, getMethodNames)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "methodNames");
}

/**
 * Merge with information from another route.
 *
 * @param array values
 * @param bool merge
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_RouteResource, setSettings)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *values_param = NULL, *merge = NULL, merge_sub, __$false, _0$$3, _1$$4;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&merge_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
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
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!merge) {
		merge = &merge_sub;
		merge = &__$false;
	}


	if (zephir_array_isset_string(&values, SL("names"))) {
		zephir_array_fetch_string(&_0$$3, &values, SL("names"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 214);
		zephir_update_property_zval(this_ptr, ZEND_STRL("names"), &_0$$3);
	}
	if (zephir_array_isset_string(&values, SL("methods"))) {
		zephir_array_fetch_string(&_1$$4, &values, SL("methods"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteResource.zep", 218);
		zephir_update_property_zval(this_ptr, ZEND_STRL("methodNames"), &_1$$4);
	}
	ZEPHIR_CALL_PARENT(NULL, yuga_route_router_routeresource_ce, getThis(), "setsettings", &_2, 0, &values, merge);
	zephir_check_call_status();
	RETURN_THIS();
}

zend_object *zephir_init_properties_Yuga_Route_Router_RouteResource(zend_class_entry *class_type)
{
		zval _3$$4, _5$$5;
	zval _0, _2, _4, _1$$3;
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("names"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("names"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("methodNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 7, 0);
			add_assoc_stringl_ex(&_3$$4, SL("index"), SL("index"));
			add_assoc_stringl_ex(&_3$$4, SL("create"), SL("create"));
			add_assoc_stringl_ex(&_3$$4, SL("store"), SL("store"));
			add_assoc_stringl_ex(&_3$$4, SL("show"), SL("show"));
			add_assoc_stringl_ex(&_3$$4, SL("edit"), SL("edit"));
			add_assoc_stringl_ex(&_3$$4, SL("update"), SL("update"));
			add_assoc_stringl_ex(&_3$$4, SL("destroy"), SL("destroy"));
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methodNames"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("urls"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_create_array(&_5$$5, 7, 0);
			add_assoc_stringl_ex(&_5$$5, SL("index"), SL(""));
			add_assoc_stringl_ex(&_5$$5, SL("create"), SL("create"));
			add_assoc_stringl_ex(&_5$$5, SL("store"), SL(""));
			add_assoc_stringl_ex(&_5$$5, SL("show"), SL(""));
			add_assoc_stringl_ex(&_5$$5, SL("edit"), SL("edit"));
			add_assoc_stringl_ex(&_5$$5, SL("update"), SL(""));
			add_assoc_stringl_ex(&_5$$5, SL("destroy"), SL(""));
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("urls"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

