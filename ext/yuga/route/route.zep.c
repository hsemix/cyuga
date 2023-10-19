
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Route)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Route, Route, yuga, route_route, yuga_route_route_method_entry, 0);

	/**
	 * Default namespace added to all routes
	 * @var string
	 */
	zend_declare_property_null(yuga_route_route_ce, SL("defaultNamespace"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * The response object
	 * @var Response
	 */
	zend_declare_property_null(yuga_route_route_ce, SL("response"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * Router instance
	 * @var Router
	 */
	zend_declare_property_null(yuga_route_route_ce, SL("router"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	return SUCCESS;
}

/**
 * Start/route request
 *
 * @throws HttpException
 * @throws NotFoundHttpException
 */
PHP_METHOD(Yuga_Route_Route, start)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_SELF(&_0, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "routerequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Route the given url to your callback on GET request method.
 *
 * @param string url
 * @param string|\Closure callback
 * @param array|null settings
 * @return RouteUrl
 */
PHP_METHOD(Yuga_Route_Route, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings, _0;
	zval *url, url_sub, *callback, callback_sub, *settings_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&settings);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &callback, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "get");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_SELF("match", NULL, 0, &_0, url, callback, &settings);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set default namespace which will be prepended to all routes.
 *
 * @param string defaultNamespace
 */
PHP_METHOD(Yuga_Route_Route, setDefaultNamespace)
{
	zval *defaultNamespace, defaultNamespace_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultNamespace_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultNamespace)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &defaultNamespace);


	zephir_update_static_property_ce(yuga_route_route_ce, ZEND_STRL("defaultNamespace"), defaultNamespace);
}

/**
 * Prepends the default namespace to all new routes added.
 *
 * @param IRoute route
 * @return IRoute
 */
PHP_METHOD(Yuga_Route_Route, addDefaultNamespace)
{
	zend_bool _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *route, route_sub, _0, callback$$3, _2$$3, namespaceValue$$4, currentNamespace$$4, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&callback$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&namespaceValue$$4);
	ZVAL_UNDEF(&currentNamespace$$4);
	ZVAL_UNDEF(&_3$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(route, zephir_get_internal_ce(SL("yuga\\route\\support\\iroute")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route);


	zephir_read_static_property_ce(&_0, yuga_route_route_ce, SL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&callback$$3, route, "getcallback", NULL, 0);
		zephir_check_call_status();
		_1$$3 = Z_TYPE_P(&callback$$3) == IS_NULL;
		if (!(_1$$3)) {
			zephir_array_fetch_long(&_2$$3, &callback$$3, 0, PH_NOISY | PH_READONLY, "yuga/Route/Route.zep", 84);
			_1$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_2$$3, "\\");
		}
		if (_1$$3) {
			ZEPHIR_OBS_VAR(&namespaceValue$$4);
			zephir_read_static_property_ce(&namespaceValue$$4, yuga_route_route_ce, SL("defaultNamespace"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&currentNamespace$$4, route, "getnamespace", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&currentNamespace$$4) != IS_NULL) {
				ZEPHIR_INIT_VAR(&_3$$5);
				ZEPHIR_CONCAT_SV(&_3$$5, "\\", &currentNamespace$$4);
				zephir_concat_self(&namespaceValue$$4, &_3$$5);
			}
			ZEPHIR_CALL_METHOD(NULL, route, "setdefaultnamespace", NULL, 0, &namespaceValue$$4);
			zephir_check_call_status();
		}
	}
	RETVAL_ZVAL(route, 1, 0);
	RETURN_MM();
}

/**
 * Route the given url to your callback on POST request method.
 *
 * @param string url
 * @param string|\Closure callback
 * @param array|null settings
 * @return RouteUrl
 */
PHP_METHOD(Yuga_Route_Route, post)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings, _0;
	zval *url, url_sub, *callback, callback_sub, *settings_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&settings);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &callback, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "post");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_SELF("match", NULL, 0, &_0, url, callback, &settings);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Route the given url to your callback on PUT request method.
 *
 * @param string url
 * @param string|\Closure callback
 * @param array|null settings
 * @return RouteUrl
 */
PHP_METHOD(Yuga_Route_Route, put)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings, _0;
	zval *url, url_sub, *callback, callback_sub, *settings_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&settings);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &callback, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "put");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_SELF("match", NULL, 0, &_0, url, callback, &settings);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Route the given url to your callback on PATCH request method.
 *
 * @param string url
 * @param string|\Closure callback
 * @param array|null settings
 * @return RouteUrl
 */
PHP_METHOD(Yuga_Route_Route, patch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings, _0;
	zval *url, url_sub, *callback, callback_sub, *settings_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&settings);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &callback, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "patch");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_SELF("match", NULL, 0, &_0, url, callback, &settings);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Route the given url to your callback on OPTIONS request method.
 *
 * @param string url
 * @param string|\Closure callback
 * @param array|null settings
 * @return RouteUrl
 */
PHP_METHOD(Yuga_Route_Route, options)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings, _0;
	zval *url, url_sub, *callback, callback_sub, *settings_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&settings);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &callback, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "options");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_SELF("match", NULL, 0, &_0, url, callback, &settings);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Route the given url to your callback on DELETE request method.
 *
 * @param string url
 * @param string|\Closure callback
 * @param array|null settings
 * @return RouteUrl
 */
PHP_METHOD(Yuga_Route_Route, delete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings, _0;
	zval *url, url_sub, *callback, callback_sub, *settings_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&settings);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &callback, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "delete");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_SELF("match", NULL, 0, &_0, url, callback, &settings);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Groups allows for encapsulating routes with special settings.
 *
 * @param array settings
 * @param \Closure callback
 * @throws \InvalidArgumentException
 * @return RouteGroup
 */
PHP_METHOD(Yuga_Route_Route, group)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *settings_param = NULL, *callback, callback_sub, group, _0;
	zval settings;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&settings);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(settings)
		Z_PARAM_OBJECT_OF_CLASS(callback, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &settings_param, &callback);
	zephir_get_arrval(&settings, settings_param);


	ZEPHIR_INIT_VAR(&group);
	object_init_ex(&group, yuga_route_router_routegroup_ce);
	if (zephir_has_constructor(&group)) {
		ZEPHIR_CALL_METHOD(NULL, &group, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(NULL, &group, "setcallback", NULL, 83, callback);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &group, "setsettings", NULL, 84, &settings);
	zephir_check_call_status();
	if (zephir_is_callable(callback) == 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid callback provided. Only functions or methods supported", "yuga/Route/Route.zep", 183);
		return;
	}
	ZEPHIR_CALL_SELF(&_0, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "addroute", NULL, 0, &group);
	zephir_check_call_status();
	RETURN_CCTOR(&group);
}

/**
 * Alias for the form method
 *
 * @param string url
 * @param callable callback
 * @param array|null settings
 * @see Route::form
 * @return RouteUrl
 */
PHP_METHOD(Yuga_Route_Route, basic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings, _0;
	zval *url, url_sub, *callback, callback_sub, *settings_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&settings);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &callback, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "get");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "post");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_SELF("match", NULL, 0, &_0, url, callback, &settings);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * This type will route the given url to your callback on the provided request methods.
 * Route the given url to your callback on POST and GET request method.
 *
 * @param string url
 * @param string|\Closure callback
 * @param array|null settings
 * @see Route::form
 * @return RouteUrl
 */
PHP_METHOD(Yuga_Route_Route, form)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings, _0;
	zval *url, url_sub, *callback, callback_sub, *settings_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&settings);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &callback, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "get");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "post");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_SELF("match", NULL, 0, &_0, url, callback, &settings);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * This type will route the given url to your callback on the provided request methods.
 *
 * @param array requestMethods
 * @param string url
 * @param string|\Closure callback
 * @param array|null settings
 * @return RouteUrl|IRoute
 */
PHP_METHOD(Yuga_Route_Route, match)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *requestMethods_param = NULL, *url, url_sub, *callback, callback_sub, *settings_param = NULL, route, _0;
	zval requestMethods, settings;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestMethods);
	ZVAL_UNDEF(&settings);
	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ARRAY(requestMethods)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &requestMethods_param, &url, &callback, &settings_param);
	zephir_get_arrval(&requestMethods, requestMethods_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, yuga_route_router_routeurl_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 73, url, callback);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &route, "setrequestmethods", NULL, 85, &requestMethods);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_0, "adddefaultnamespace", NULL, 0, &route);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&route, &_0);
	if (!ZEPHIR_IS_NULL(&settings)) {
		ZEPHIR_CALL_METHOD(NULL, &route, "setsettings", NULL, 86, &settings);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_SELF(&_0, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "addroute", NULL, 0, &route);
	zephir_check_call_status();
	RETURN_CCTOR(&route);
}

/**
 * This type will route the given url to your callback and allow any type of request method
 *
 * @param string url
 * @param string|\Closure callback
 * @param array|null settings
 * @return RouteUrl|IRoute
 */
PHP_METHOD(Yuga_Route_Route, all)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings;
	zval *url, url_sub, *callback, callback_sub, *settings_param = NULL, route, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&settings);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &callback, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, yuga_route_router_routeurl_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 73, url, callback);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_0, "adddefaultnamespace", NULL, 0, &route);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&route, &_0);
	if (!ZEPHIR_IS_NULL(&settings)) {
		ZEPHIR_CALL_METHOD(NULL, &route, "setsettings", NULL, 86, &settings);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_SELF(&_0, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "addroute", NULL, 0, &route);
	zephir_check_call_status();
	RETURN_CCTOR(&route);
}

/**
 * This route will route request from the given url to the controller.
 *
 * @param string url
 * @param string controller
 * @param array|null settings
 * @return RouteController|IRoute
 */
PHP_METHOD(Yuga_Route_Route, controller)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings;
	zval *url, url_sub, *controller, controller_sub, *settings_param = NULL, route, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&controller_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&settings);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(controller)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &controller, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, yuga_route_router_routecontroller_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 87, url, controller);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_0, "adddefaultnamespace", NULL, 0, &route);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&route, &_0);
	if (!ZEPHIR_IS_NULL(&settings)) {
		ZEPHIR_CALL_METHOD(NULL, &route, "setsettings", NULL, 88, &settings);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_SELF(&_0, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "addroute", NULL, 0, &route);
	zephir_check_call_status();
	RETURN_CCTOR(&route);
}

/**
 * Add exception callback handler.
 *
 * @param \Closure callback
 * @return CallbackException callbackException
 */
PHP_METHOD(Yuga_Route_Route, error)
{
	zend_class_entry *_1 = NULL;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, routes, group, callbackException, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&callbackException);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(callback, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);


	ZEPHIR_CALL_SELF(&_0, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&routes, &_0, "getroutes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&callbackException);
	if (!_1) {
	_1 = zephir_fetch_class_str_ex(SL("Yuga\\Exceptions\\CallbackException"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&callbackException, _1);
	if (zephir_has_constructor(&callbackException)) {
		ZEPHIR_CALL_METHOD(NULL, &callbackException, "__construct", NULL, 0, callback);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&group);
	object_init_ex(&group, yuga_route_router_routegroup_ce);
	if (zephir_has_constructor(&group)) {
		ZEPHIR_CALL_METHOD(NULL, &group, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(NULL, &group, "addexceptionhandler", NULL, 89, &callbackException);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&routes);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 90, &routes, &group);
	ZEPHIR_UNREF(&routes);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_2, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "setroutes", NULL, 0, &routes);
	zephir_check_call_status();
	RETURN_CCTOR(&callbackException);
}

PHP_METHOD(Yuga_Route_Route, getDefaultNamespace)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_static_property_ce(&_0, yuga_route_route_ce, SL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);
}

/**
 * This type will route all REST-supported requests to different methods in the provided controller.
 *
 * @param string url
 * @param string controller
 * @param array|null settings
 * @return RouteResource|IRoute
 */
PHP_METHOD(Yuga_Route_Route, resources)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval settings;
	zval *url, url_sub, *controller, controller_sub, *settings_param = NULL, route, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&controller_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&settings);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(url)
		Z_PARAM_ZVAL(controller)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url, &controller, &settings_param);
	if (!settings_param) {
		ZEPHIR_INIT_VAR(&settings);
	} else {
		zephir_get_arrval(&settings, settings_param);
	}


	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, yuga_route_router_routeresource_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 91, url, controller);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_0, "adddefaultnamespace", NULL, 0, &route);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&route, &_0);
	if (!ZEPHIR_IS_NULL(&settings)) {
		ZEPHIR_CALL_METHOD(NULL, &route, "setsettings", NULL, 92, &settings);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_SELF(&_0, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "addroute", NULL, 0, &route);
	zephir_check_call_status();
	RETURN_CCTOR(&route);
}

/**
 * Returns the router instance
 *
 * @return Router
 */
PHP_METHOD(Yuga_Route_Route, router)
{
	zval _0, _2, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, yuga_route_route_ce, SL("router"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, yuga_route_router_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 93);
		zephir_check_call_status();
		zephir_update_static_property_ce(yuga_route_route_ce, ZEND_STRL("router"), &_1$$3);
	}
	zephir_read_static_property_ce(&_2, yuga_route_route_ce, SL("router"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_2);
}

PHP_METHOD(Yuga_Route_Route, getUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, *parameters = NULL, parameters_sub, *getParams = NULL, getParams_sub, __$null, e, exce, _1, _0$$3, _2$$5, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&getParams_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&exce);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(parameters)
		Z_PARAM_ZVAL_OR_NULL(getParams)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name, &parameters, &getParams);
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!getParams) {
		getParams = &getParams_sub;
		getParams = &__$null;
	}



	/* try_start_1: */

		ZEPHIR_CALL_SELF(&_0$$3, "router", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_RETURN_CALL_METHOD(&_0$$3, "geturl", NULL, 0, name, parameters, getParams);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		if (zephir_is_instance_of(&_1, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_1);

			/* try_start_2: */

				object_init_ex(return_value, yuga_http_uri_ce);
				ZEPHIR_INIT_VAR(&_2$$5);
				ZVAL_STRING(&_2$$5, "/");
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 94, &_2$$5);
				zephir_check_call_status_or_jump(try_end_2);
				RETURN_MM();

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_VAR(&_3$$4);
				ZVAL_OBJ(&_3$$4, EG(exception));
				Z_ADDREF_P(&_3$$4);
				if (zephir_instance_of_ev(&_3$$4, yuga_http_exceptions_badformedurlexception_ce)) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&exce, &_3$$4);
				}
			}
		}
	}
	RETURN_MM_NULL();
}

/**
 * Get the request
 *
 * @return \Yuga\Http\Request
 */
PHP_METHOD(Yuga_Route_Route, request)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_SELF(&_0, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getrequest", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the response object
 *
 * @return Response
 */
PHP_METHOD(Yuga_Route_Route, response)
{
	zval _0, _5, _1$$3, _2$$3, _3$$3, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);


	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, yuga_route_route_ce, SL("response"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, yuga_http_response_ce);
		ZEPHIR_CALL_SELF(&_2$$3, "request", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, yuga_http_redirect_ce);
		ZEPHIR_CALL_SELF(&_4$$3, "request", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 95, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 96, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_update_static_property_ce(yuga_route_route_ce, ZEND_STRL("response"), &_1$$3);
	}
	zephir_read_static_property_ce(&_5, yuga_route_route_ce, SL("response"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_5);
}

