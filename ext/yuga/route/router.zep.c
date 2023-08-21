
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Router)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Route, Router, yuga, route_router, yuga_route_router_method_entry, 0);

	/**
	 * The instance of this class
	 * @var static
	 */
	zend_declare_property_null(yuga_route_router_ce, SL("instance"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * Current request
	 * @var Request
	 */
	zend_declare_property_null(yuga_route_router_ce, SL("request"), ZEND_ACC_PROTECTED);
	/**
	 * Defines if a route is currently being processed.
	 * @var bool
	 */
	zend_declare_property_null(yuga_route_router_ce, SL("processingRoute"), ZEND_ACC_PROTECTED);
	/**
	 * All added routes
	 * @var array
	 */
	zend_declare_property_null(yuga_route_router_ce, SL("routes"), ZEND_ACC_PROTECTED);
	/**
	 * List of processed routes
	 * @var array
	 */
	zend_declare_property_null(yuga_route_router_ce, SL("processedRoutes"), ZEND_ACC_PROTECTED);
	/**
	 * Stack of routes used to keep track of sub-routes added
	 * when a route is being processed.
	 * @var array
	 */
	zend_declare_property_null(yuga_route_router_ce, SL("routeStack"), ZEND_ACC_PROTECTED);
	/**
	 * List of added bootmanagers
	 * @var array
	 */
	zend_declare_property_null(yuga_route_router_ce, SL("bootManagers"), ZEND_ACC_PROTECTED);
	/**
	 * Csrf verifier class
	 * @var BaseCsrfVerifier
	 */
	zend_declare_property_null(yuga_route_router_ce, SL("csrfVerifier"), ZEND_ACC_PROTECTED);
	/**
	 * Get exception handlers
	 * @var array
	 */
	zend_declare_property_null(yuga_route_router_ce, SL("exceptionHandlers"), ZEND_ACC_PROTECTED);
	/**
	 * Get default router
	 * 
	 * @var array
	 */
	zend_declare_property_null(yuga_route_router_ce, SL("defaultRouteCollection"), ZEND_ACC_PROTECTED);
	yuga_route_router_ce->create_object = zephir_init_properties_Yuga_Route_Router;

	return SUCCESS;
}

PHP_METHOD(Yuga_Route_Router, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reset", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Route_Router, reset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);


	ZEPHIR_MM_GROW();

	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("processingRoute"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("processingRoute"), &__$false);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, yuga_http_request_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 21);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routes"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("bootManagers"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routeStack"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval(this_ptr, ZEND_STRL("processedRoutes"), &_4);
	ZEPHIR_INIT_VAR(&_5);
	array_init(&_5);
	zephir_update_property_zval(this_ptr, ZEND_STRL("exceptionHandlers"), &_5);
	ZEPHIR_MM_RESTORE();
}

/**
 * Add route
 * @param IRoute route
 * @return IRoute
 */
PHP_METHOD(Yuga_Route_Router, addRoute)
{
	zval *route, route_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(route, zephir_get_internal_ce(SL("yuga\\route\\support\\iroute")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &route);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("processingRoute"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE(&_0)) {
		zephir_update_property_array_append(this_ptr, SL("routeStack"), route);
	} else {
		zephir_update_property_array_append(this_ptr, SL("routes"), route);
	}
	RETVAL_ZVAL(route, 1, 0);
	return;
}

/**
 * Process added routes.
 *
 * @param array routes
 * @param IGroupRoute|null group
 * @param IRoute|null parent
 * @throws NotFoundHttpException
 */
PHP_METHOD(Yuga_Route_Router, processRoutes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routes_param = NULL, *group = NULL, group_sub, *parentRoute = NULL, parentRoute_sub, __$true, __$false, __$null, exceptionHandlers, route, url, _0, _1, _2, _3, *_4, _5, _25, _26, _6$$4, _7$$4, _8$$4, _9$$5, _10$$6, _11$$8, _12$$8, _13$$3, stack$$10, _14$$10, _16$$12, _17$$12, _18$$12, _19$$13, _20$$14, _21$$16, _22$$16, _23$$11, stack$$18, _24$$18;
	zval routes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&parentRoute_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&exceptionHandlers);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&stack$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&stack$$18);
	ZVAL_UNDEF(&_24$$18);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ARRAY(routes)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(group, zephir_get_internal_ce(SL("yuga\\route\\support\\igrouproute")))
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parentRoute, zephir_get_internal_ce(SL("yuga\\route\\support\\iroute")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &routes_param, &group, &parentRoute);
	zephir_get_arrval(&routes, routes_param);
	if (!group) {
		group = &group_sub;
		ZEPHIR_CPY_WRT(group, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(group);
	}
	if (!parentRoute) {
		parentRoute = &parentRoute_sub;
		parentRoute = &__$null;
	}


	ZEPHIR_INIT_VAR(&exceptionHandlers);
	array_init(&exceptionHandlers);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getrewriteurl", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_1) != IS_NULL) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&url, &_2, "getrewriteurl", NULL, 0);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&url, &_3, "geturi", NULL, 0);
		zephir_check_call_status();
	}
	zephir_is_iterable(&routes, 0, "yuga/Route/Router.zep", 225);
	if (Z_TYPE_P(&routes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routes), _4)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _4);
			if (zephir_instance_of_ev(&route, yuga_route_support_igrouproute_ce)) {
				ZEPHIR_CPY_WRT(group, &route);
				if (1) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("processingRoute"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, ZEND_STRL("processingRoute"), &__$false);
				}
				zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &route, "renderroute", NULL, 0, &_6$$4);
				zephir_check_call_status();
				if (0) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("processingRoute"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, ZEND_STRL("processingRoute"), &__$false);
				}
				zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_7$$4, &route, "matchroute", NULL, 0, &url, &_8$$4);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_7$$4)) {
					ZEPHIR_CALL_METHOD(&_9$$5, &route, "getexceptionhandlers", NULL, 0);
					zephir_check_call_status();
					if (zephir_fast_count_int(&_9$$5) > 0) {
						ZEPHIR_CALL_METHOD(&_10$$6, &route, "getexceptionhandlers", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_ADD_ASSIGN(&exceptionHandlers, &_10$$6);
					}
				}
			}
			if (Z_TYPE_P(group) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &route, "setgroup", NULL, 0, group);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(parentRoute) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &route, "setparent", NULL, 0, parentRoute);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11$$8, parentRoute, "toarray", NULL, 0);
				zephir_check_call_status();
				ZVAL_BOOL(&_12$$8, 1);
				ZEPHIR_CALL_METHOD(NULL, &route, "setsettings", NULL, 0, &_11$$8, &_12$$8);
				zephir_check_call_status();
			}
			if (zephir_instance_of_ev(&route, yuga_route_support_iloadableroute_ce)) {
				zephir_update_property_array_append(this_ptr, SL("processedRoutes"), &route);
			}
			zephir_read_property(&_13$$3, this_ptr, ZEND_STRL("routeStack"), PH_NOISY_CC | PH_READONLY);
			if (zephir_fast_count_int(&_13$$3) > 0) {
				ZEPHIR_OBS_NVAR(&stack$$10);
				zephir_read_property(&stack$$10, this_ptr, ZEND_STRL("routeStack"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(&_14$$10);
				array_init(&_14$$10);
				zephir_update_property_zval(this_ptr, ZEND_STRL("routeStack"), &_14$$10);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "processroutes", &_15, 86, &stack$$10, &route, group);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &routes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &routes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &routes, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_instance_of_ev(&route, yuga_route_support_igrouproute_ce)) {
					ZEPHIR_CPY_WRT(group, &route);
					if (1) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("processingRoute"), &__$true);
					} else {
						zephir_update_property_zval(this_ptr, ZEND_STRL("processingRoute"), &__$false);
					}
					zephir_read_property(&_16$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &route, "renderroute", NULL, 0, &_16$$12);
					zephir_check_call_status();
					if (0) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("processingRoute"), &__$true);
					} else {
						zephir_update_property_zval(this_ptr, ZEND_STRL("processingRoute"), &__$false);
					}
					zephir_read_property(&_18$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_17$$12, &route, "matchroute", NULL, 0, &url, &_18$$12);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_17$$12)) {
						ZEPHIR_CALL_METHOD(&_19$$13, &route, "getexceptionhandlers", NULL, 0);
						zephir_check_call_status();
						if (zephir_fast_count_int(&_19$$13) > 0) {
							ZEPHIR_CALL_METHOD(&_20$$14, &route, "getexceptionhandlers", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_ADD_ASSIGN(&exceptionHandlers, &_20$$14);
						}
					}
				}
				if (Z_TYPE_P(group) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &route, "setgroup", NULL, 0, group);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(parentRoute) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &route, "setparent", NULL, 0, parentRoute);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_21$$16, parentRoute, "toarray", NULL, 0);
					zephir_check_call_status();
					ZVAL_BOOL(&_22$$16, 1);
					ZEPHIR_CALL_METHOD(NULL, &route, "setsettings", NULL, 0, &_21$$16, &_22$$16);
					zephir_check_call_status();
				}
				if (zephir_instance_of_ev(&route, yuga_route_support_iloadableroute_ce)) {
					zephir_update_property_array_append(this_ptr, SL("processedRoutes"), &route);
				}
				zephir_read_property(&_23$$11, this_ptr, ZEND_STRL("routeStack"), PH_NOISY_CC | PH_READONLY);
				if (zephir_fast_count_int(&_23$$11) > 0) {
					ZEPHIR_OBS_NVAR(&stack$$18);
					zephir_read_property(&stack$$18, this_ptr, ZEND_STRL("routeStack"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(&_24$$18);
					array_init(&_24$$18);
					zephir_update_property_zval(this_ptr, ZEND_STRL("routeStack"), &_24$$18);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "processroutes", &_15, 86, &stack$$18, &route, group);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &routes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_VAR(&_25);
	zephir_read_property(&_26, this_ptr, ZEND_STRL("exceptionHandlers"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_25, &exceptionHandlers, &_26);
	zephir_update_property_zval(this_ptr, ZEND_STRL("exceptionHandlers"), &_25);
	ZEPHIR_MM_RESTORE();
}

/**
 * Load routes
 * @throws NotFoundHttpException
 * @return void
 */
PHP_METHOD(Yuga_Route_Router, loadRoutes)
{
	zval _0, _7, manager$$3, managers$$3, *_1$$3, _2$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&manager$$3);
	ZVAL_UNDEF(&managers$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("bootManagers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0) > 0) {
		ZEPHIR_OBS_VAR(&managers$$3);
		zephir_read_property(&managers$$3, this_ptr, ZEND_STRL("bootManagers"), PH_NOISY_CC);
		zephir_is_iterable(&managers$$3, 0, "yuga/Route/Router.zep", 247);
		if (Z_TYPE_P(&managers$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&managers$$3), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&manager$$3);
				ZVAL_COPY(&manager$$3, _1$$3);
				zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &manager$$3, "boot", &_4, 0, &_3$$4);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &managers$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &managers$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&manager$$3, &managers$$3, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &manager$$3, "boot", &_6, 0, &_5$$5);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &managers$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&manager$$3);
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processroutes", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Route_Router, routeRequest)
{
	zend_string *_12$$3;
	zend_ulong _11$$3;
	zend_bool routeNotAllowed, _18$$7, _33$$7, _46$$12, _60$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL, *_17 = NULL, *_22 = NULL, *_24 = NULL, *_26 = NULL, *_29 = NULL, *_31 = NULL, *_35 = NULL, *_37 = NULL, *_40 = NULL, *_43 = NULL, *_45 = NULL, *_50 = NULL, *_53 = NULL, *_56 = NULL, *_58 = NULL, *_65 = NULL, *_75 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rewrite = NULL, rewrite_sub, __$false, rewriteUrl, message, e, _66, _70, _71, _0$$4, _1$$5, _2$$5, _3$$5, url$$3, _4$$3, _5$$3, _6$$3, _7$$3, i$$3, route$$3, processedRoutes$$3, _8$$3, *_9$$3, _10$$3, _13$$6, _14$$6, _16$$7, _19$$7, _20$$7, _21$$7, _23$$7, _25$$7, rewriteRoute$$7, _27$$7, _32$$7, _38$$7, _39$$7, _28$$9, _30$$9, _34$$10, _36$$10, _41$$11, _42$$11, _44$$12, _47$$12, _48$$12, _49$$12, _51$$12, _52$$12, rewriteRoute$$12, _54$$12, _59$$12, _63$$12, _64$$12, _55$$14, _57$$14, _61$$15, _62$$15, _67$$17, _68$$17, _69$$17, _72$$18, uri$$18, _73$$18, _74$$19, _76$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rewrite_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&rewriteUrl);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_66);
	ZVAL_UNDEF(&_70);
	ZVAL_UNDEF(&_71);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&url$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&i$$3);
	ZVAL_UNDEF(&route$$3);
	ZVAL_UNDEF(&processedRoutes$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&rewriteRoute$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_38$$7);
	ZVAL_UNDEF(&_39$$7);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_42$$11);
	ZVAL_UNDEF(&_44$$12);
	ZVAL_UNDEF(&_47$$12);
	ZVAL_UNDEF(&_48$$12);
	ZVAL_UNDEF(&_49$$12);
	ZVAL_UNDEF(&_51$$12);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&rewriteRoute$$12);
	ZVAL_UNDEF(&_54$$12);
	ZVAL_UNDEF(&_59$$12);
	ZVAL_UNDEF(&_63$$12);
	ZVAL_UNDEF(&_64$$12);
	ZVAL_UNDEF(&_55$$14);
	ZVAL_UNDEF(&_57$$14);
	ZVAL_UNDEF(&_61$$15);
	ZVAL_UNDEF(&_62$$15);
	ZVAL_UNDEF(&_67$$17);
	ZVAL_UNDEF(&_68$$17);
	ZVAL_UNDEF(&_69$$17);
	ZVAL_UNDEF(&_72$$18);
	ZVAL_UNDEF(&uri$$18);
	ZVAL_UNDEF(&_73$$18);
	ZVAL_UNDEF(&_74$$19);
	ZVAL_UNDEF(&_76$$20);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(rewrite)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &rewrite);
	if (!rewrite) {
		rewrite = &rewrite_sub;
		rewrite = &__$false;
	}


	routeNotAllowed = 0;

	/* try_start_1: */

		if (ZEPHIR_IS_FALSE_IDENTICAL(rewrite)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadroutes", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_read_property(&_0$$4, this_ptr, ZEND_STRL("csrfVerifier"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_0$$4) != IS_NULL) {
				zephir_read_property(&_1$$5, this_ptr, ZEND_STRL("csrfVerifier"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_2$$5, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_3$$5);
				ZEPHIR_INIT_NVAR(&_3$$5);
				zephir_create_closure_ex(&_3$$5, NULL, yuga_5__closure_ce, SL("__invoke"));
				ZEPHIR_CALL_METHOD(NULL, &_1$$5, "run", NULL, 0, &_2$$5, &_3$$5);
				zephir_check_call_status_or_jump(try_end_1);
			}
		}
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "getrewriteurl", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&_5$$3) != IS_NULL) {
			zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&url$$3, &_6$$3, "getrewriteurl", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		} else {
			zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&url$$3, &_7$$3, "geturi", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("processedRoutes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&processedRoutes$$3, &_8$$3);
		zephir_is_iterable(&processedRoutes$$3, 0, "yuga/Route/Router.zep", 340);
		if (Z_TYPE_P(&processedRoutes$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&processedRoutes$$3), _11$$3, _12$$3, _9$$3)
			{
				ZEPHIR_INIT_NVAR(&i$$3);
				if (_12$$3 != NULL) { 
					ZVAL_STR_COPY(&i$$3, _12$$3);
				} else {
					ZVAL_LONG(&i$$3, _11$$3);
				}
				ZEPHIR_INIT_NVAR(&route$$3);
				ZVAL_COPY(&route$$3, _9$$3);
				zephir_read_property(&_14$$6, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_13$$6, &route$$3, "matchroute", &_15, 0, &url$$3, &_14$$6);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_13$$6)) {
					ZEPHIR_CALL_METHOD(&_16$$7, &route$$3, "getrequestmethods", &_17, 0);
					zephir_check_call_status_or_jump(try_end_1);
					_18$$7 = zephir_fast_count_int(&_16$$7) > 0;
					if (_18$$7) {
						zephir_read_property(&_19$$7, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(&_20$$7, &_19$$7, "getmethod", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_CALL_METHOD(&_21$$7, &route$$3, "getrequestmethods", &_22, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_CALL_FUNCTION(&_23$$7, "in_array", &_24, 47, &_20$$7, &_21$$7, &__$false);
						zephir_check_call_status_or_jump(try_end_1);
						_18$$7 = ZEPHIR_IS_FALSE_IDENTICAL(&_23$$7);
					}
					if (_18$$7) {
						routeNotAllowed = 1;
						continue;
					}
					zephir_read_property(&_25$$7, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &route$$3, "loadmiddleware", &_26, 0, &_25$$7);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_read_property(&_27$$7, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&rewriteRoute$$7, &_27$$7, "getrewriteroute", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					if (Z_TYPE_P(&rewriteRoute$$7) != IS_NULL) {
						zephir_read_property(&_28$$9, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &rewriteRoute$$7, "loadmiddleware", &_29, 0, &_28$$9);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_30$$9, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &rewriteRoute$$7, "renderroute", &_31, 0, &_30$$9);
						zephir_check_call_status_or_jump(try_end_1);
						RETURN_MM_NULL();
					}
					zephir_read_property(&_32$$7, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&rewriteUrl, &_32$$7, "getrewriteurl", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					_33$$7 = Z_TYPE_P(&rewriteUrl) != IS_NULL;
					if (_33$$7) {
						_33$$7 = !ZEPHIR_IS_IDENTICAL(&rewriteUrl, &url$$3);
					}
					if (_33$$7) {
						zephir_array_unset(&processedRoutes$$3, &i$$3, PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_34$$10, "array_values", &_35, 3, &processedRoutes$$3);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_update_property_zval(this_ptr, ZEND_STRL("processedRoutes"), &_34$$10);
						ZVAL_BOOL(&_36$$10, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "routerequest", &_37, 87, &_36$$10);
						zephir_check_call_status_or_jump(try_end_1);
						RETURN_MM_NULL();
					}
					routeNotAllowed = 0;
					zephir_read_property(&_38$$7, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_38$$7, "setloadedroute", NULL, 0, &route$$3);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_read_property(&_39$$7, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &route$$3, "renderroute", &_40, 0, &_39$$7);
					zephir_check_call_status_or_jump(try_end_1);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &processedRoutes$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$3, &processedRoutes$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&i$$3, &processedRoutes$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&route$$3, &processedRoutes$$3, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_property(&_42$$11, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_41$$11, &route$$3, "matchroute", &_43, 0, &url$$3, &_42$$11);
					zephir_check_call_status_or_jump(try_end_1);
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_41$$11)) {
						ZEPHIR_CALL_METHOD(&_44$$12, &route$$3, "getrequestmethods", &_45, 0);
						zephir_check_call_status_or_jump(try_end_1);
						_46$$12 = zephir_fast_count_int(&_44$$12) > 0;
						if (_46$$12) {
							zephir_read_property(&_47$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(&_48$$12, &_47$$12, "getmethod", NULL, 0);
							zephir_check_call_status_or_jump(try_end_1);
							ZEPHIR_CALL_METHOD(&_49$$12, &route$$3, "getrequestmethods", &_50, 0);
							zephir_check_call_status_or_jump(try_end_1);
							ZEPHIR_CALL_FUNCTION(&_51$$12, "in_array", &_24, 47, &_48$$12, &_49$$12, &__$false);
							zephir_check_call_status_or_jump(try_end_1);
							_46$$12 = ZEPHIR_IS_FALSE_IDENTICAL(&_51$$12);
						}
						if (_46$$12) {
							routeNotAllowed = 1;
							continue;
						}
						zephir_read_property(&_52$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &route$$3, "loadmiddleware", &_53, 0, &_52$$12);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_54$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(&rewriteRoute$$12, &_54$$12, "getrewriteroute", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						if (Z_TYPE_P(&rewriteRoute$$12) != IS_NULL) {
							zephir_read_property(&_55$$14, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(NULL, &rewriteRoute$$12, "loadmiddleware", &_56, 0, &_55$$14);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_57$$14, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(NULL, &rewriteRoute$$12, "renderroute", &_58, 0, &_57$$14);
							zephir_check_call_status_or_jump(try_end_1);
							RETURN_MM_NULL();
						}
						zephir_read_property(&_59$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(&rewriteUrl, &_59$$12, "getrewriteurl", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						_60$$12 = Z_TYPE_P(&rewriteUrl) != IS_NULL;
						if (_60$$12) {
							_60$$12 = !ZEPHIR_IS_IDENTICAL(&rewriteUrl, &url$$3);
						}
						if (_60$$12) {
							zephir_array_unset(&processedRoutes$$3, &i$$3, PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_61$$15, "array_values", &_35, 3, &processedRoutes$$3);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_update_property_zval(this_ptr, ZEND_STRL("processedRoutes"), &_61$$15);
							ZVAL_BOOL(&_62$$15, 1);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "routerequest", &_37, 87, &_62$$15);
							zephir_check_call_status_or_jump(try_end_1);
							RETURN_MM_NULL();
						}
						routeNotAllowed = 0;
						zephir_read_property(&_63$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_63$$12, "setloadedroute", NULL, 0, &route$$3);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_64$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &route$$3, "renderroute", &_65, 0, &_64$$12);
						zephir_check_call_status_or_jump(try_end_1);
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, &processedRoutes$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route$$3);
		ZEPHIR_INIT_NVAR(&i$$3);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_66);
		ZVAL_OBJ(&_66, EG(exception));
		Z_ADDREF_P(&_66);
		if (zephir_is_instance_of(&_66, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_66);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "handleexception", NULL, 0, &e);
			zephir_check_call_status();
		}
	}
	if (routeNotAllowed == 1) {
		ZEPHIR_INIT_VAR(&_67$$17);
		object_init_ex(&_67$$17, yuga_route_exceptions_httpexception_ce);
		ZEPHIR_INIT_VAR(&_68$$17);
		ZVAL_STRING(&_68$$17, "Route or method not allowed");
		ZVAL_LONG(&_69$$17, 403);
		ZEPHIR_CALL_METHOD(NULL, &_67$$17, "__construct", NULL, 5, &_68$$17, &_69$$17);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "handleexception", NULL, 0, &_67$$17);
		zephir_check_call_status();
	}
	zephir_read_property(&_70, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_71, &_70, "getloadedroute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_71) == IS_NULL) {
		zephir_read_property(&_72$$18, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&rewriteUrl, &_72$$18, "getrewriteurl", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_73$$18, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&uri$$18, &_73$$18, "geturi", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&rewriteUrl) != IS_NULL) {
			ZEPHIR_INIT_VAR(&_74$$19);
			ZVAL_STRING(&_74$$19, "Route not found: \"%s\" (rewrite from: \"%s\")");
			ZEPHIR_CALL_FUNCTION(&message, "sprintf", &_75, 4, &_74$$19, &rewriteUrl, &uri$$18);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_76$$20);
			ZVAL_STRING(&_76$$20, "Route not found: \"%s\"");
			ZEPHIR_CALL_FUNCTION(&message, "sprintf", &_75, 4, &_76$$20, &uri$$18);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Route_Router, handleException)
{
	zend_bool _23$$6, _43$$12;
	zend_class_entry *_10$$4, *_31$$10;
	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_19 = NULL, *_21 = NULL, *_27 = NULL, *_29 = NULL, *_39 = NULL, *_41 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *e, e_sub, url, _0, _1, _2, _3, i, handler, exceptionHandlers, _4, *_5, _6, _9$$4, _11$$5, _12$$5, _13$$5, _15$$3, _16$$3, rewriteRoute$$6, _17$$6, rewriteUrl$$6, _22$$6, _18$$7, _20$$7, _24$$8, _25$$8, _26$$8, _28$$8, _30$$10, _32$$11, _33$$11, _34$$11, _35$$9, _36$$9, rewriteRoute$$12, _37$$12, rewriteUrl$$12, _42$$12, _38$$13, _40$$13, _44$$14, _45$$14, _46$$14, _47$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&exceptionHandlers);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&rewriteRoute$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&rewriteUrl$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_34$$11);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&rewriteRoute$$12);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&rewriteUrl$$12);
	ZVAL_UNDEF(&_42$$12);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_40$$13);
	ZVAL_UNDEF(&_44$$14);
	ZVAL_UNDEF(&_45$$14);
	ZVAL_UNDEF(&_46$$14);
	ZVAL_UNDEF(&_47$$14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(e, zend_ce_exception)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &e);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getrewriteurl", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_1) != IS_NULL) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&url, &_2, "getrewriteurl", NULL, 0);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&url, &_3, "geturi", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("exceptionHandlers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&exceptionHandlers, &_4);
	zephir_is_iterable(&exceptionHandlers, 0, "yuga/Route/Router.zep", 457);
	if (Z_TYPE_P(&exceptionHandlers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&exceptionHandlers), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&i);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&i, _8);
			} else {
				ZVAL_LONG(&i, _7);
			}
			ZEPHIR_INIT_NVAR(&handler);
			ZVAL_COPY(&handler, _5);
			if (Z_TYPE_P(&handler) == IS_OBJECT == 0) {
				ZEPHIR_INIT_NVAR(&handler);
				zephir_fetch_safe_class(&_9$$4, &handler);
				_10$$4 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_9$$4), Z_STRLEN_P(&_9$$4), ZEND_FETCH_CLASS_AUTO);
				if(!_10$$4) {
					RETURN_MM_NULL();
				}
				object_init_ex(&handler, _10$$4);
				if (zephir_has_constructor(&handler)) {
					ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0);
					zephir_check_call_status();
				}

			}
			if ((zephir_instance_of_ev(&handler, yuga_exceptions_iexception_ce)) == 0) {
				ZEPHIR_INIT_NVAR(&_11$$5);
				object_init_ex(&_11$$5, yuga_route_exceptions_httpexception_ce);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "Exception  must implement the IException interface.");
				ZVAL_LONG(&_13$$5, 500);
				ZEPHIR_CALL_METHOD(NULL, &_11$$5, "__construct", &_14, 5, &_12$$5, &_13$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$5, "yuga/Route/Router.zep", 430);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property(&_16$$3, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_15$$3, &handler, "handleerror", NULL, 0, &_16$$3, e);
			zephir_check_call_status();
			if (Z_TYPE_P(&_15$$3) != IS_NULL) {
				zephir_read_property(&_17$$6, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&rewriteRoute$$6, &_17$$6, "getrewriteroute", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&rewriteRoute$$6) != IS_NULL) {
					zephir_read_property(&_18$$7, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &rewriteRoute$$6, "loadmiddleware", &_19, 0, &_18$$7);
					zephir_check_call_status();
					zephir_read_property(&_20$$7, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &rewriteRoute$$6, "renderroute", &_21, 0, &_20$$7);
					zephir_check_call_status();
					RETURN_MM_NULL();
				}
				zephir_read_property(&_22$$6, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&rewriteUrl$$6, &_22$$6, "getrewriteurl", NULL, 0);
				zephir_check_call_status();
				_23$$6 = Z_TYPE_P(&rewriteUrl$$6) != IS_NULL;
				if (_23$$6) {
					_23$$6 = !ZEPHIR_IS_IDENTICAL(&rewriteUrl$$6, &url);
				}
				if (_23$$6) {
					zephir_unset_property_array(this_ptr, ZEND_STRL("exceptionHandlers"), &i);
					zephir_read_property(&_24$$8, this_ptr, ZEND_STRL("exceptionHandlers"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_24$$8, &i, PH_SEPARATE);
					zephir_read_property(&_25$$8, this_ptr, ZEND_STRL("exceptionHandlers"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_FUNCTION(&_26$$8, "array_values", &_27, 3, &_25$$8);
					zephir_check_call_status();
					zephir_update_property_zval(this_ptr, ZEND_STRL("exceptionHandlers"), &_26$$8);
					ZVAL_BOOL(&_28$$8, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "routerequest", &_29, 0, &_28$$8);
					zephir_check_call_status();
					RETURN_MM_NULL();
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &exceptionHandlers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &exceptionHandlers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&i, &exceptionHandlers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&handler, &exceptionHandlers, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&handler) == IS_OBJECT == 0) {
					ZEPHIR_INIT_NVAR(&handler);
					zephir_fetch_safe_class(&_30$$10, &handler);
					_31$$10 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_30$$10), Z_STRLEN_P(&_30$$10), ZEND_FETCH_CLASS_AUTO);
					if(!_31$$10) {
						RETURN_MM_NULL();
					}
					object_init_ex(&handler, _31$$10);
					if (zephir_has_constructor(&handler)) {
						ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0);
						zephir_check_call_status();
					}

				}
				if ((zephir_instance_of_ev(&handler, yuga_exceptions_iexception_ce)) == 0) {
					ZEPHIR_INIT_NVAR(&_32$$11);
					object_init_ex(&_32$$11, yuga_route_exceptions_httpexception_ce);
					ZEPHIR_INIT_NVAR(&_33$$11);
					ZVAL_STRING(&_33$$11, "Exception  must implement the IException interface.");
					ZVAL_LONG(&_34$$11, 500);
					ZEPHIR_CALL_METHOD(NULL, &_32$$11, "__construct", &_14, 5, &_33$$11, &_34$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_32$$11, "yuga/Route/Router.zep", 430);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property(&_36$$9, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_35$$9, &handler, "handleerror", NULL, 0, &_36$$9, e);
				zephir_check_call_status();
				if (Z_TYPE_P(&_35$$9) != IS_NULL) {
					zephir_read_property(&_37$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&rewriteRoute$$12, &_37$$12, "getrewriteroute", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&rewriteRoute$$12) != IS_NULL) {
						zephir_read_property(&_38$$13, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &rewriteRoute$$12, "loadmiddleware", &_39, 0, &_38$$13);
						zephir_check_call_status();
						zephir_read_property(&_40$$13, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &rewriteRoute$$12, "renderroute", &_41, 0, &_40$$13);
						zephir_check_call_status();
						RETURN_MM_NULL();
					}
					zephir_read_property(&_42$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&rewriteUrl$$12, &_42$$12, "getrewriteurl", NULL, 0);
					zephir_check_call_status();
					_43$$12 = Z_TYPE_P(&rewriteUrl$$12) != IS_NULL;
					if (_43$$12) {
						_43$$12 = !ZEPHIR_IS_IDENTICAL(&rewriteUrl$$12, &url);
					}
					if (_43$$12) {
						zephir_unset_property_array(this_ptr, ZEND_STRL("exceptionHandlers"), &i);
						zephir_read_property(&_44$$14, this_ptr, ZEND_STRL("exceptionHandlers"), PH_NOISY_CC | PH_READONLY);
						zephir_array_unset(&_44$$14, &i, PH_SEPARATE);
						zephir_read_property(&_45$$14, this_ptr, ZEND_STRL("exceptionHandlers"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(&_46$$14, "array_values", &_27, 3, &_45$$14);
						zephir_check_call_status();
						zephir_update_property_zval(this_ptr, ZEND_STRL("exceptionHandlers"), &_46$$14);
						ZVAL_BOOL(&_47$$14, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "routerequest", &_29, 87, &_47$$14);
						zephir_check_call_status();
						RETURN_MM_NULL();
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &exceptionHandlers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&handler);
	ZEPHIR_INIT_NVAR(&i);
	zephir_throw_exception_debug(e, "yuga/Route/Router.zep", 457);
	ZEPHIR_MM_RESTORE();
	return;
}

PHP_METHOD(Yuga_Route_Router, arrayToParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *getParams_param = NULL, *includeEmpty = NULL, includeEmpty_sub, __$true, _0$$4, _1$$4, _2$$3;
	zval getParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&getParams);
	ZVAL_UNDEF(&includeEmpty_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(getParams)
		Z_PARAM_ZVAL(includeEmpty)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &getParams_param, &includeEmpty);
	if (!getParams_param) {
		ZEPHIR_INIT_VAR(&getParams);
		array_init(&getParams);
	} else {
		zephir_get_arrval(&getParams, getParams_param);
	}
	if (!includeEmpty) {
		includeEmpty = &includeEmpty_sub;
		includeEmpty = &__$true;
	}


	if (zephir_fast_count_int(&getParams) > 0) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(includeEmpty)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_INIT_NVAR(&_0$$4);
			zephir_create_closure_ex(&_0$$4, NULL, yuga_6__closure_ce, SL("__invoke"));
			ZEPHIR_CALL_FUNCTION(&_1$$4, "array_filter", NULL, 6, &getParams, &_0$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&getParams, &_1$$4);
		}
		ZEPHIR_CALL_FUNCTION(&_2$$3, "http_build_query", NULL, 71, &getParams);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SV(return_value, "?", &_2$$3);
		RETURN_MM();
	}
	RETURN_MM_STRING("");
}

/**
 * Find route by alias, class, callback or method.
 *
 * @param string name
 * @return ILoadableRoute|null
 */
PHP_METHOD(Yuga_Route_Router, findRoute)
{
	zend_bool _3$$3, _7$$3, _17$$3, _19$$3, _22$$3, _26$$3, _14$$6, _30$$8, _38$$11, _42$$11, _51$$11, _53$$11, _56$$11, _60$$11, _48$$14, _64$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, route, routes, *_0, _1, _2$$3, _4$$3, _5$$3, _6$$3, _8$$3, _9$$3, _18$$3, _20$$3, _21$$3, _23$$3, _24$$3, _25$$3, _27$$3, filteredControllerMethod$$6, _10$$6, _11$$6, controller$$6, method$$6, _13$$6, _15$$6, _16$$6, _28$$8, _29$$8, _31$$8, _32$$8, _33$$8, _34$$8, _35$$8, _36$$8, _37$$11, _39$$11, _40$$11, _41$$11, _43$$11, _44$$11, _52$$11, _54$$11, _55$$11, _57$$11, _58$$11, _59$$11, _61$$11, filteredControllerMethod$$14, _45$$14, _46$$14, controller$$14, method$$14, _47$$14, _49$$14, _50$$14, _62$$16, _63$$16, _65$$16, _66$$16, _67$$16, _68$$16, _69$$16, _70$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_27$$3);
	ZVAL_UNDEF(&filteredControllerMethod$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&controller$$6);
	ZVAL_UNDEF(&method$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_37$$11);
	ZVAL_UNDEF(&_39$$11);
	ZVAL_UNDEF(&_40$$11);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_43$$11);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_52$$11);
	ZVAL_UNDEF(&_54$$11);
	ZVAL_UNDEF(&_55$$11);
	ZVAL_UNDEF(&_57$$11);
	ZVAL_UNDEF(&_58$$11);
	ZVAL_UNDEF(&_59$$11);
	ZVAL_UNDEF(&_61$$11);
	ZVAL_UNDEF(&filteredControllerMethod$$14);
	ZVAL_UNDEF(&_45$$14);
	ZVAL_UNDEF(&_46$$14);
	ZVAL_UNDEF(&controller$$14);
	ZVAL_UNDEF(&method$$14);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_49$$14);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_62$$16);
	ZVAL_UNDEF(&_63$$16);
	ZVAL_UNDEF(&_65$$16);
	ZVAL_UNDEF(&_66$$16);
	ZVAL_UNDEF(&_67$$16);
	ZVAL_UNDEF(&_68$$16);
	ZVAL_UNDEF(&_69$$16);
	ZVAL_UNDEF(&_70$$16);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_OBS_VAR(&routes);
	zephir_read_property(&routes, this_ptr, ZEND_STRL("processedRoutes"), PH_NOISY_CC);
	zephir_is_iterable(&routes, 0, "yuga/Route/Router.zep", 531);
	if (Z_TYPE_P(&routes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routes), _0)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _0);
			ZEPHIR_CALL_METHOD(&_2$$3, &route, "hasname", NULL, 0, name);
			zephir_check_call_status();
			if (zephir_is_true(&_2$$3)) {
				RETURN_CCTOR(&route);
			}
			_3$$3 = zephir_instance_of_ev(&route, yuga_route_support_icontrollerroute_ce);
			if (_3$$3) {
				ZEPHIR_INIT_NVAR(&_4$$3);
				ZEPHIR_CALL_METHOD(&_5$$3, &route, "getcontroller", NULL, 0);
				zephir_check_call_status();
				zephir_fast_strtolower(&_4$$3, &_5$$3);
				ZEPHIR_INIT_NVAR(&_6$$3);
				zephir_fast_strtolower(&_6$$3, name);
				_3$$3 = ZEPHIR_IS_IDENTICAL(&_4$$3, &_6$$3);
			}
			if (_3$$3) {
				RETURN_CCTOR(&route);
			}
			_7$$3 = Z_TYPE_P(name) == IS_STRING == 1;
			if (_7$$3) {
				ZEPHIR_INIT_NVAR(&_8$$3);
				ZVAL_STRING(&_8$$3, "@");
				ZEPHIR_INIT_NVAR(&_9$$3);
				zephir_fast_strpos(&_9$$3, name, &_8$$3, 0 );
				_7$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(&_9$$3);
			}
			if (_7$$3) {
				ZEPHIR_INIT_NVAR(&_10$$6);
				zephir_fast_explode_str(&_10$$6, SL("@"), name, LONG_MAX);
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_STRING(&_11$$6, "strtolower");
				ZEPHIR_CALL_FUNCTION(&filteredControllerMethod$$6, "array_map", &_12, 61, &_11$$6, &_10$$6);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&controller$$6);
				zephir_array_fetch_long(&controller$$6, &filteredControllerMethod$$6, 0, PH_NOISY, "yuga/Route/Router.zep", 508);
				ZEPHIR_OBS_NVAR(&method$$6);
				zephir_array_fetch_long(&method$$6, &filteredControllerMethod$$6, 1, PH_NOISY, "yuga/Route/Router.zep", 509);
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZEPHIR_CALL_METHOD(&_13$$6, &route, "getclass", NULL, 0);
				zephir_check_call_status();
				zephir_fast_strtolower(&_11$$6, &_13$$6);
				_14$$6 = ZEPHIR_IS_IDENTICAL(&controller$$6, &_11$$6);
				if (_14$$6) {
					ZEPHIR_INIT_NVAR(&_15$$6);
					ZEPHIR_CALL_METHOD(&_16$$6, &route, "getmethod", NULL, 0);
					zephir_check_call_status();
					zephir_fast_strtolower(&_15$$6, &_16$$6);
					_14$$6 = ZEPHIR_IS_IDENTICAL(&method$$6, &_15$$6);
				}
				if (_14$$6) {
					RETURN_CCTOR(&route);
				}
			}
			_17$$3 = Z_TYPE_P(name) == IS_STRING == 1;
			if (_17$$3) {
				ZEPHIR_CALL_METHOD(&_18$$3, &route, "getcallback", NULL, 0);
				zephir_check_call_status();
				_17$$3 = Z_TYPE_P(&_18$$3) == IS_STRING;
			}
			_19$$3 = _17$$3;
			if (_19$$3) {
				ZEPHIR_INIT_NVAR(&_20$$3);
				ZVAL_STRING(&_20$$3, "@");
				ZEPHIR_INIT_NVAR(&_21$$3);
				zephir_fast_strpos(&_21$$3, name, &_20$$3, 0 );
				_19$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(&_21$$3);
			}
			_22$$3 = _19$$3;
			if (_22$$3) {
				ZEPHIR_CALL_METHOD(&_23$$3, &route, "getcallback", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_24$$3);
				ZVAL_STRING(&_24$$3, "@");
				ZEPHIR_INIT_NVAR(&_25$$3);
				zephir_fast_strpos(&_25$$3, &_23$$3, &_24$$3, 0 );
				_22$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(&_25$$3);
			}
			_26$$3 = _22$$3;
			if (_26$$3) {
				ZEPHIR_CALL_METHOD(&_27$$3, &route, "getcallback", NULL, 0);
				zephir_check_call_status();
				_26$$3 = zephir_is_callable(&_27$$3) == 0;
			}
			if (_26$$3) {
				ZEPHIR_CALL_METHOD(&_28$$8, &route, "getcallback", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_29$$8);
				zephir_fast_strpos(&_29$$8, &_28$$8, name, 0 );
				_30$$8 = ZEPHIR_IS_LONG_IDENTICAL(&_29$$8, 0);
				if (!(_30$$8)) {
					ZEPHIR_INIT_NVAR(&_31$$8);
					ZEPHIR_CALL_METHOD(&_32$$8, &route, "getcallback", NULL, 0);
					zephir_check_call_status();
					zephir_fast_strtolower(&_31$$8, &_32$$8);
					ZEPHIR_INIT_NVAR(&_33$$8);
					zephir_fast_strtolower(&_33$$8, name);
					_30$$8 = ZEPHIR_IS_IDENTICAL(&_31$$8, &_33$$8);
				}
				if (_30$$8) {
					RETURN_CCTOR(&route);
				}
				ZEPHIR_INIT_NVAR(&_34$$8);
				zephir_fast_strtolower(&_34$$8, name);
				ZEPHIR_INIT_NVAR(&_35$$8);
				ZEPHIR_CALL_METHOD(&_36$$8, &route, "getclass", NULL, 0);
				zephir_check_call_status();
				zephir_fast_strtolower(&_35$$8, &_36$$8);
				if (ZEPHIR_IS_IDENTICAL(&_34$$8, &_35$$8)) {
					RETURN_CCTOR(&route);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &routes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &routes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &routes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_37$$11, &route, "hasname", NULL, 0, name);
				zephir_check_call_status();
				if (zephir_is_true(&_37$$11)) {
					RETURN_CCTOR(&route);
				}
				_38$$11 = zephir_instance_of_ev(&route, yuga_route_support_icontrollerroute_ce);
				if (_38$$11) {
					ZEPHIR_INIT_NVAR(&_39$$11);
					ZEPHIR_CALL_METHOD(&_40$$11, &route, "getcontroller", NULL, 0);
					zephir_check_call_status();
					zephir_fast_strtolower(&_39$$11, &_40$$11);
					ZEPHIR_INIT_NVAR(&_41$$11);
					zephir_fast_strtolower(&_41$$11, name);
					_38$$11 = ZEPHIR_IS_IDENTICAL(&_39$$11, &_41$$11);
				}
				if (_38$$11) {
					RETURN_CCTOR(&route);
				}
				_42$$11 = Z_TYPE_P(name) == IS_STRING == 1;
				if (_42$$11) {
					ZEPHIR_INIT_NVAR(&_43$$11);
					ZVAL_STRING(&_43$$11, "@");
					ZEPHIR_INIT_NVAR(&_44$$11);
					zephir_fast_strpos(&_44$$11, name, &_43$$11, 0 );
					_42$$11 = !ZEPHIR_IS_FALSE_IDENTICAL(&_44$$11);
				}
				if (_42$$11) {
					ZEPHIR_INIT_NVAR(&_45$$14);
					zephir_fast_explode_str(&_45$$14, SL("@"), name, LONG_MAX);
					ZEPHIR_INIT_NVAR(&_46$$14);
					ZVAL_STRING(&_46$$14, "strtolower");
					ZEPHIR_CALL_FUNCTION(&filteredControllerMethod$$14, "array_map", &_12, 61, &_46$$14, &_45$$14);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&controller$$14);
					zephir_array_fetch_long(&controller$$14, &filteredControllerMethod$$14, 0, PH_NOISY, "yuga/Route/Router.zep", 508);
					ZEPHIR_OBS_NVAR(&method$$14);
					zephir_array_fetch_long(&method$$14, &filteredControllerMethod$$14, 1, PH_NOISY, "yuga/Route/Router.zep", 509);
					ZEPHIR_INIT_NVAR(&_46$$14);
					ZEPHIR_CALL_METHOD(&_47$$14, &route, "getclass", NULL, 0);
					zephir_check_call_status();
					zephir_fast_strtolower(&_46$$14, &_47$$14);
					_48$$14 = ZEPHIR_IS_IDENTICAL(&controller$$14, &_46$$14);
					if (_48$$14) {
						ZEPHIR_INIT_NVAR(&_49$$14);
						ZEPHIR_CALL_METHOD(&_50$$14, &route, "getmethod", NULL, 0);
						zephir_check_call_status();
						zephir_fast_strtolower(&_49$$14, &_50$$14);
						_48$$14 = ZEPHIR_IS_IDENTICAL(&method$$14, &_49$$14);
					}
					if (_48$$14) {
						RETURN_CCTOR(&route);
					}
				}
				_51$$11 = Z_TYPE_P(name) == IS_STRING == 1;
				if (_51$$11) {
					ZEPHIR_CALL_METHOD(&_52$$11, &route, "getcallback", NULL, 0);
					zephir_check_call_status();
					_51$$11 = Z_TYPE_P(&_52$$11) == IS_STRING;
				}
				_53$$11 = _51$$11;
				if (_53$$11) {
					ZEPHIR_INIT_NVAR(&_54$$11);
					ZVAL_STRING(&_54$$11, "@");
					ZEPHIR_INIT_NVAR(&_55$$11);
					zephir_fast_strpos(&_55$$11, name, &_54$$11, 0 );
					_53$$11 = !ZEPHIR_IS_FALSE_IDENTICAL(&_55$$11);
				}
				_56$$11 = _53$$11;
				if (_56$$11) {
					ZEPHIR_CALL_METHOD(&_57$$11, &route, "getcallback", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_58$$11);
					ZVAL_STRING(&_58$$11, "@");
					ZEPHIR_INIT_NVAR(&_59$$11);
					zephir_fast_strpos(&_59$$11, &_57$$11, &_58$$11, 0 );
					_56$$11 = !ZEPHIR_IS_FALSE_IDENTICAL(&_59$$11);
				}
				_60$$11 = _56$$11;
				if (_60$$11) {
					ZEPHIR_CALL_METHOD(&_61$$11, &route, "getcallback", NULL, 0);
					zephir_check_call_status();
					_60$$11 = zephir_is_callable(&_61$$11) == 0;
				}
				if (_60$$11) {
					ZEPHIR_CALL_METHOD(&_62$$16, &route, "getcallback", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_63$$16);
					zephir_fast_strpos(&_63$$16, &_62$$16, name, 0 );
					_64$$16 = ZEPHIR_IS_LONG_IDENTICAL(&_63$$16, 0);
					if (!(_64$$16)) {
						ZEPHIR_INIT_NVAR(&_65$$16);
						ZEPHIR_CALL_METHOD(&_66$$16, &route, "getcallback", NULL, 0);
						zephir_check_call_status();
						zephir_fast_strtolower(&_65$$16, &_66$$16);
						ZEPHIR_INIT_NVAR(&_67$$16);
						zephir_fast_strtolower(&_67$$16, name);
						_64$$16 = ZEPHIR_IS_IDENTICAL(&_65$$16, &_67$$16);
					}
					if (_64$$16) {
						RETURN_CCTOR(&route);
					}
					ZEPHIR_INIT_NVAR(&_68$$16);
					zephir_fast_strtolower(&_68$$16, name);
					ZEPHIR_INIT_NVAR(&_69$$16);
					ZEPHIR_CALL_METHOD(&_70$$16, &route, "getclass", NULL, 0);
					zephir_check_call_status();
					zephir_fast_strtolower(&_69$$16, &_70$$16);
					if (ZEPHIR_IS_IDENTICAL(&_68$$16, &_69$$16)) {
						RETURN_CCTOR(&route);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &routes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	RETURN_MM_NULL();
}

/**
 * Get url for a route by using either name/alias, class or method name.
 *
 * The name parameter supports the following values:
 * - Route name
 * - Controller/resource name (with or without method)
 * - Controller class name
 *
 * When searching for controller/resource by name, you can use this syntax "route.name@method".
 * You can also use the same syntax when searching for a specific controller-class "MyController@home".
 * If no arguments is specified, it will return the url for the current loaded route.
 *
 * @param string|null name
 * @param string|array|null parameters
 * @param array|null getParams
 * @throws \InvalidArgumentException
 * @return string
 */
PHP_METHOD(Yuga_Route_Router, getUrl)
{
	zval _53, _54, _3$$5;
	zend_bool _0, _1, _2, _4, _14, _30$$12, _43$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_26 = NULL, *_28 = NULL, *_33 = NULL, *_36 = NULL, *_39 = NULL, *_41 = NULL, *_46 = NULL, *_49 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, *parameters = NULL, parameters_sub, *getParams = NULL, getParams_sub, _GET, __$null, loadedRoute, _13, route, url, _51, _52, _55, _57, url$$6, _5$$6, _6$$6, _7$$6, _8$$6, _9$$6, _12$$6, _10$$7, _15$$8, _16$$8, _17$$8, _18$$9, _19$$9, _20$$9, _21$$10, _22$$10, explodedValues$$11, controller$$11, method$$11, route$$11, routes$$11, *_23$$11, _24$$11, _25$$12, _31$$12, _32$$12, _34$$12, _27$$13, _29$$13, _35$$14, _37$$14, _38$$15, _44$$15, _45$$15, _47$$15, _40$$16, _42$$16, _48$$17, _50$$17, _56$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&getParams_sub);
	ZVAL_UNDEF(&_GET);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&loadedRoute);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&url$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&explodedValues$$11);
	ZVAL_UNDEF(&controller$$11);
	ZVAL_UNDEF(&method$$11);
	ZVAL_UNDEF(&route$$11);
	ZVAL_UNDEF(&routes$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_44$$15);
	ZVAL_UNDEF(&_45$$15);
	ZVAL_UNDEF(&_47$$15);
	ZVAL_UNDEF(&_40$$16);
	ZVAL_UNDEF(&_42$$16);
	ZVAL_UNDEF(&_48$$17);
	ZVAL_UNDEF(&_50$$17);
	ZVAL_UNDEF(&_56$$18);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_54);
	ZVAL_UNDEF(&_3$$5);
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
	zephir_get_global(&_GET, SL("_GET"));
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
		ZEPHIR_CPY_WRT(getParams, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(getParams);
	}


	_0 = Z_TYPE_P(getParams) != IS_NULL;
	if (_0) {
		_0 = Z_TYPE_P(getParams) == IS_ARRAY == 0;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid type for getParams. Must be array or null", "yuga/Route/Router.zep", 555);
		return;
	}
	_1 = Z_TYPE_P(name) == IS_NULL;
	if (_1) {
		_1 = Z_TYPE_P(parameters) == IS_NULL;
	}
	_2 = _1;
	if (_2) {
		_2 = Z_TYPE_P(getParams) == IS_NULL;
	}
	if (_2) {
		ZEPHIR_CPY_WRT(getParams, &_GET);
	} else {
		zephir_get_arrval(&_3$$5, getParams);
		ZEPHIR_CPY_WRT(getParams, &_3$$5);
	}
	_4 = Z_TYPE_P(name) == IS_NULL;
	if (_4) {
		_4 = Z_TYPE_P(parameters) == IS_NULL;
	}
	if (_4) {
		zephir_read_property(&_5$$6, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_6$$6, &_5$$6, "geturi", NULL, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_7$$6, 5);
		ZEPHIR_CALL_FUNCTION(&_8$$6, "parse_url", NULL, 70, &_6$$6, &_7$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$6);
		ZVAL_STRING(&_9$$6, "/");
		ZEPHIR_INIT_VAR(&url$$6);
		zephir_fast_trim(&url$$6, &_8$$6, &_9$$6, ZEPHIR_TRIM_RIGHT);
		if (ZEPHIR_IS_STRING_IDENTICAL(&url$$6, "")) {
			ZEPHIR_CALL_METHOD(&_10$$7, this_ptr, "arraytoparams", &_11, 0, getParams);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SV(return_value, "/", &_10$$7);
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "arraytoparams", &_11, 0, getParams);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, &url$$6, "/", &_12$$6);
		RETURN_MM();
	}
	zephir_read_property(&_13, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&loadedRoute, &_13, "getloadedroute", NULL, 0);
	zephir_check_call_status();
	_14 = Z_TYPE_P(name) == IS_NULL;
	if (_14) {
		_14 = Z_TYPE_P(&loadedRoute) != IS_NULL;
	}
	if (_14) {
		ZEPHIR_CALL_METHOD(&_16$$8, &loadedRoute, "getmethod", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$8, &loadedRoute, "findurl", NULL, 0, &_16$$8, parameters, name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_17$$8, this_ptr, "arraytoparams", &_11, 0, getParams);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &_15$$8, &_17$$8);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&route, this_ptr, "findroute", NULL, 0, name);
	zephir_check_call_status();
	if (Z_TYPE_P(&route) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&_19$$9, &route, "getmethod", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_18$$9, &route, "findurl", NULL, 0, &_19$$9, parameters, name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_20$$9, this_ptr, "arraytoparams", &_11, 0, getParams);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &_18$$9, &_20$$9);
		RETURN_MM();
	}
	if (Z_TYPE_P(name) == IS_STRING == 1) {
		ZEPHIR_INIT_VAR(&_21$$10);
		ZVAL_STRING(&_21$$10, "@");
		ZEPHIR_INIT_VAR(&_22$$10);
		zephir_fast_strpos(&_22$$10, name, &_21$$10, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_22$$10)) {
			ZEPHIR_INIT_VAR(&explodedValues$$11);
			zephir_fast_explode_str(&explodedValues$$11, SL("@"), name, LONG_MAX);
			ZEPHIR_OBS_VAR(&controller$$11);
			zephir_array_fetch_long(&controller$$11, &explodedValues$$11, 0, PH_NOISY, "yuga/Route/Router.zep", 596);
			ZEPHIR_OBS_VAR(&method$$11);
			zephir_array_fetch_long(&method$$11, &explodedValues$$11, 1, PH_NOISY, "yuga/Route/Router.zep", 597);
			ZEPHIR_OBS_VAR(&routes$$11);
			zephir_read_property(&routes$$11, this_ptr, ZEND_STRL("processedRoutes"), PH_NOISY_CC);
			zephir_is_iterable(&routes$$11, 0, "yuga/Route/Router.zep", 621);
			if (Z_TYPE_P(&routes$$11) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routes$$11), _23$$11)
				{
					ZEPHIR_INIT_NVAR(&route$$11);
					ZVAL_COPY(&route$$11, _23$$11);
					ZEPHIR_CALL_METHOD(&_25$$12, &route$$11, "hasname", &_26, 0, &controller$$11);
					zephir_check_call_status();
					if (zephir_is_true(&_25$$12)) {
						ZEPHIR_CALL_METHOD(&_27$$13, &route$$11, "findurl", &_28, 0, &method$$11, parameters, name);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_29$$13, this_ptr, "arraytoparams", &_11, 0, getParams);
						zephir_check_call_status();
						ZEPHIR_CONCAT_VV(return_value, &_27$$13, &_29$$13);
						RETURN_MM();
					}
					_30$$12 = zephir_instance_of_ev(&route$$11, yuga_route_support_icontrollerroute_ce);
					if (_30$$12) {
						ZEPHIR_INIT_NVAR(&_31$$12);
						ZEPHIR_CALL_METHOD(&_32$$12, &route$$11, "getcontroller", &_33, 0);
						zephir_check_call_status();
						zephir_fast_strtolower(&_31$$12, &_32$$12);
						ZEPHIR_INIT_NVAR(&_34$$12);
						zephir_fast_strtolower(&_34$$12, &controller$$11);
						_30$$12 = ZEPHIR_IS_IDENTICAL(&_31$$12, &_34$$12);
					}
					if (_30$$12) {
						ZEPHIR_CALL_METHOD(&_35$$14, &route$$11, "findurl", &_36, 0, &method$$11, parameters, name);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_37$$14, this_ptr, "arraytoparams", &_11, 0, getParams);
						zephir_check_call_status();
						ZEPHIR_CONCAT_VV(return_value, &_35$$14, &_37$$14);
						RETURN_MM();
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &routes$$11, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_24$$11, &routes$$11, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_24$$11)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&route$$11, &routes$$11, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_38$$15, &route$$11, "hasname", &_39, 0, &controller$$11);
						zephir_check_call_status();
						if (zephir_is_true(&_38$$15)) {
							ZEPHIR_CALL_METHOD(&_40$$16, &route$$11, "findurl", &_41, 0, &method$$11, parameters, name);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_42$$16, this_ptr, "arraytoparams", &_11, 0, getParams);
							zephir_check_call_status();
							ZEPHIR_CONCAT_VV(return_value, &_40$$16, &_42$$16);
							RETURN_MM();
						}
						_43$$15 = zephir_instance_of_ev(&route$$11, yuga_route_support_icontrollerroute_ce);
						if (_43$$15) {
							ZEPHIR_INIT_NVAR(&_44$$15);
							ZEPHIR_CALL_METHOD(&_45$$15, &route$$11, "getcontroller", &_46, 0);
							zephir_check_call_status();
							zephir_fast_strtolower(&_44$$15, &_45$$15);
							ZEPHIR_INIT_NVAR(&_47$$15);
							zephir_fast_strtolower(&_47$$15, &controller$$11);
							_43$$15 = ZEPHIR_IS_IDENTICAL(&_44$$15, &_47$$15);
						}
						if (_43$$15) {
							ZEPHIR_CALL_METHOD(&_48$$17, &route$$11, "findurl", &_49, 0, &method$$11, parameters, name);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_50$$17, this_ptr, "arraytoparams", &_11, 0, getParams);
							zephir_check_call_status();
							ZEPHIR_CONCAT_VV(return_value, &_48$$17, &_50$$17);
							RETURN_MM();
						}
					ZEPHIR_CALL_METHOD(NULL, &routes$$11, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&route$$11);
		}
	}
	ZEPHIR_INIT_VAR(&_51);
	ZEPHIR_INIT_VAR(&_52);
	zephir_get_arrval(&_53, name);
	zephir_get_arrval(&_54, parameters);
	zephir_fast_array_merge(&_52, &_53, &_54);
	zephir_fast_join_str(&_51, SL("/"), &_52);
	ZEPHIR_INIT_VAR(&_55);
	ZVAL_STRING(&_55, "/");
	ZEPHIR_INIT_VAR(&url);
	zephir_fast_trim(&url, &_51, &_55, ZEPHIR_TRIM_BOTH);
	if (ZEPHIR_IS_STRING_IDENTICAL(&url, "")) {
		ZEPHIR_CALL_METHOD(&_56$$18, this_ptr, "arraytoparams", &_11, 0, getParams);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SV(return_value, "/", &_56$$18);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_57, this_ptr, "arraytoparams", &_11, 0, getParams);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "/", &url, "/", &_57);
	RETURN_MM();
}

/**
 * Get bootmanagers
 * @return array
 */
PHP_METHOD(Yuga_Route_Router, getBootManagers)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "bootManagers");
}

/**
 * Set bootmanagers
 * @param array bootManagers
 */
PHP_METHOD(Yuga_Route_Router, setBootManagers)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *bootManagers_param = NULL;
	zval bootManagers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bootManagers);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(bootManagers)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bootManagers_param);
	zephir_get_arrval(&bootManagers, bootManagers_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("bootManagers"), &bootManagers);
	ZEPHIR_MM_RESTORE();
}

/**
 * Add bootmanager
 * @param IRouterBootManager bootManager
 */
PHP_METHOD(Yuga_Route_Router, addBootManager)
{
	zval *bootManager, bootManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bootManager_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(bootManager, zephir_get_internal_ce(SL("yuga\\route\\support\\irouterbootmanager")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &bootManager);


	zephir_update_property_array_append(this_ptr, SL("bootManagers"), bootManager);
}

/**
 * @return array
 */
PHP_METHOD(Yuga_Route_Router, getRoutes)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "routes");
}

/**
 * Set routes
 *
 * @param array routes
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router, setRoutes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *routes_param = NULL;
	zval routes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(routes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &routes_param);
	zephir_get_arrval(&routes, routes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("routes"), &routes);
	RETURN_THIS();
}

/**
 * Get current request
 *
 * @return Request
 */
PHP_METHOD(Yuga_Route_Router, getRequest)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "request");
}

/**
 * Get csrf verifier class
 * @return BaseCsrfVerifier
 */
PHP_METHOD(Yuga_Route_Router, getCsrfVerifier)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "csrfVerifier");
}

zend_object *zephir_init_properties_Yuga_Route_Router(zend_class_entry *class_type)
{
		zval _1$$3;
	zval _0, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("defaultRouteCollection"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 3, 0);
			add_assoc_stringl_ex(&_1$$3, SL("controller"), SL("Home"));
			add_assoc_stringl_ex(&_1$$3, SL("method"), SL("index"));
			ZEPHIR_INIT_VAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("params"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("defaultRouteCollection"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

