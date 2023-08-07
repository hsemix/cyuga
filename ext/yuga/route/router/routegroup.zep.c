
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Router_RouteGroup)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Route\\Router, RouteGroup, yuga, route_router_routegroup, yuga_route_router_route_ce, yuga_route_router_routegroup_method_entry, 0);

	zend_declare_property_null(yuga_route_router_routegroup_ce, SL("prefix"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_routegroup_ce, SL("name"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_routegroup_ce, SL("domains"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_routegroup_ce, SL("exceptionHandlers"), ZEND_ACC_PROTECTED);
	yuga_route_router_routegroup_ce->create_object = zephir_init_properties_Yuga_Route_Router_RouteGroup;

	zend_class_implements(yuga_route_router_routegroup_ce, 1, yuga_route_support_igrouproute_ce);
	return SUCCESS;
}

/**
 * Method called to check if a domain matches
 *
 * @param Request request
 * @return bool
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, matchDomain)
{
	zend_bool _1, _10$$4, _13$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, domain, _0, _2, _3, *_4, _5, parameters$$4, _6$$4, _8$$4, parameters$$6, _11$$6, _12$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&parameters$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&parameters$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("domains"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) == IS_NULL;
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("domains"), PH_NOISY_CC | PH_READONLY);
		_1 = zephir_fast_count_int(&_2) == 0;
	}
	if (_1) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("domains"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "yuga/Route/Router/RouteGroup.zep", 39);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&domain);
			ZVAL_COPY(&domain, _4);
			ZEPHIR_CALL_METHOD(&_6$$4, request, "gethost", &_7, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, ".*");
			ZEPHIR_CALL_METHOD(&parameters$$4, this_ptr, "parseparameters", &_9, 0, &domain, &_6$$4, &_8$$4);
			zephir_check_call_status();
			_10$$4 = Z_TYPE_P(&parameters$$4) != IS_NULL;
			if (_10$$4) {
				_10$$4 = zephir_fast_count_int(&parameters$$4) > 0;
			}
			if (_10$$4) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &parameters$$4);
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&domain, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11$$6, request, "gethost", &_7, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$6);
				ZVAL_STRING(&_12$$6, ".*");
				ZEPHIR_CALL_METHOD(&parameters$$6, this_ptr, "parseparameters", &_9, 0, &domain, &_11$$6, &_12$$6);
				zephir_check_call_status();
				_13$$6 = Z_TYPE_P(&parameters$$6) != IS_NULL;
				if (_13$$6) {
					_13$$6 = zephir_fast_count_int(&parameters$$6) > 0;
				}
				if (_13$$6) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &parameters$$6);
					RETURN_MM_BOOL(1);
				}
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&domain);
	RETURN_MM_BOOL(0);
}

/**
 * Method called to check if route matches
 *
 * @param string url
 * @param Request request
 * @return bool
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, matchRoute)
{
	zend_bool _1, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, *request, request_sub, _0, _2, _3, _4, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(url)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url, &request);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getgroup", NULL, 0);
	zephir_check_call_status();
	_1 = Z_TYPE_P(&_0) != IS_NULL;
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getgroup", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3, &_2, "matchroute", NULL, 0, url, request);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_FALSE_IDENTICAL(&_3);
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	_5 = Z_TYPE_P(&_4) != IS_NULL;
	if (_5) {
		zephir_read_property(&_6, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_7, "stripos", NULL, 14, url, &_6);
		zephir_check_call_status();
		_5 = ZEPHIR_IS_FALSE_IDENTICAL(&_7);
	}
	if (_5) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "matchdomain", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Add exception handler
 *
 * @param IExceptionHandler|string handler
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, addExceptionHandler)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	zephir_update_property_array_append(this_ptr, SL("exceptionHandlers"), handler);
	RETURN_THISW();
}

/**
 * Set exception-handlers for group
 *
 * @param array handlers
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, setExceptionHandlers)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handlers_param = NULL;
	zval handlers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlers);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(handlers)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &handlers_param);
	zephir_get_arrval(&handlers, handlers_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("exceptionHandlers"), &handlers);
	RETURN_THIS();
}

/**
 * Get exception-handlers for group
 *
 * @return array
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, getExceptionHandlers)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "exceptionHandlers");
}

/**
 * Get allowed domains for domain.
 *
 * @return array
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, getDomains)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "domains");
}

/**
 * Set allowed domains for group.
 *
 * @param array domains
 * @return this
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, setDomains)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *domains_param = NULL;
	zval domains;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domains);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(domains)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domains_param);
	zephir_get_arrval(&domains, domains_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("domains"), &domains);
	RETURN_THIS();
}

/**
 * @param string prefix
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, setPrefix)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prefix, prefix_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(prefix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, prefix, &_1, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "/", &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_2);
	RETURN_THIS();
}

/**
 * Set prefix that child-routes will inherit.
 *
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, getPrefix)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "prefix");
}

/**
 * Merge with information from another route.
 *
 * @param array values
 * @param bool merge
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, setSettings)
{
	zend_bool _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *merge = NULL, merge_sub, __$false, _0$$3, _1$$3, _2$$3, _3$$4, _5$$5, _7$$6, _9$$7, _10$$7, _11$$7, _12$$8;
	zval values, _4$$4, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&merge_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
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


	if (zephir_array_isset_string(&values, SL("prefix"))) {
		zephir_array_fetch_string(&_0$$3, &values, SL("prefix"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteGroup.zep", 153);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VV(&_2$$3, &_0$$3, &_1$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprefix", NULL, 0, &_2$$3);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&values, SL("exceptionHandler"))) {
		ZEPHIR_OBS_VAR(&_3$$4);
		zephir_array_fetch_string(&_3$$4, &values, SL("exceptionHandler"), PH_NOISY, "yuga/Route/Router/RouteGroup.zep", 157);
		zephir_get_arrval(&_4$$4, &_3$$4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setexceptionhandlers", NULL, 0, &_4$$4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&values, SL("domain"))) {
		ZEPHIR_OBS_VAR(&_5$$5);
		zephir_array_fetch_string(&_5$$5, &values, SL("domain"), PH_NOISY, "yuga/Route/Router/RouteGroup.zep", 161);
		zephir_get_arrval(&_6$$5, &_5$$5);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdomains", NULL, 0, &_6$$5);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&values, SL("as"))) {
		zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		_8$$6 = Z_TYPE_P(&_7$$6) != IS_NULL;
		if (_8$$6) {
			_8$$6 = !ZEPHIR_IS_FALSE_IDENTICAL(merge);
		}
		if (_8$$6) {
			zephir_array_fetch_string(&_9$$7, &values, SL("as"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteGroup.zep", 166);
			zephir_read_property(&_10$$7, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_11$$7);
			ZEPHIR_CONCAT_VSV(&_11$$7, &_9$$7, ".", &_10$$7);
			zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &_11$$7);
		} else {
			zephir_array_fetch_string(&_12$$8, &values, SL("as"), PH_NOISY | PH_READONLY, "yuga/Route/Router/RouteGroup.zep", 168);
			zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &_12$$8);
		}
	}
	ZEPHIR_CALL_PARENT(NULL, yuga_route_router_routegroup_ce, getThis(), "setsettings", &_13, 0, &values, merge);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Export route settings to array so they can be merged with another route.
 *
 * @return array
 */
PHP_METHOD(Yuga_Route_Router_RouteGroup, toArray)
{
	zval values, _0, _2, _4, _6, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getprefix", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&values, SL("prefix"), &_1$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_2) != IS_NULL) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&values, SL("as"), &_3$$4, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_4) > 0) {
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&values, SL("parameters"), &_5$$5, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(&_6, yuga_route_router_routegroup_ce, getThis(), "toarray", &_7, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(return_value, &values, &_6);
	RETURN_MM();
}

zend_object *zephir_init_properties_Yuga_Route_Router_RouteGroup(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _12, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("exceptionHandlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("exceptionHandlers"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("middlewares"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("middlewares"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("originalParameters"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("parameters"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("where"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("where"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("requestMethods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("requestMethods"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("domains"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("domains"), &_13$$9);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

