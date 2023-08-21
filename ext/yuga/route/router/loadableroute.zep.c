
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Router_LoadableRoute)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Route\\Router, LoadableRoute, yuga, route_router_loadableroute, yuga_route_router_route_ce, yuga_route_router_loadableroute_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(yuga_route_router_loadableroute_ce, SL("url"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(yuga_route_router_loadableroute_ce, SL("name"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_loadableroute_ce, SL("regex"), ZEND_ACC_PROTECTED);
	zend_class_implements(yuga_route_router_loadableroute_ce, 1, yuga_route_support_iloadableroute_ce);
	return SUCCESS;
}

/**
 * Loads and renders middlewares-classes
 *
 * @param Request request
 * @throws HttpException
 */
PHP_METHOD(Yuga_Route_Router_LoadableRoute, loadMiddleware)
{
	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &request);


}

PHP_METHOD(Yuga_Route_Router_LoadableRoute, matchRegex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *url, url_sub, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
		Z_PARAM_ZVAL(url)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &request, &url);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("regex"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("regex"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, request, "gethost", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_3, url);
	ZEPHIR_INIT_VAR(&_5);
	zephir_preg_match(&_5, &_2, &_4, &_1, 0, 0 , 0 );
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_5, 0));
}

/**
 * Set url
 *
 * @param string url
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_LoadableRoute, setUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, __$null, _0, _1, _2, _3, _4, _5, _6, matches$$3, regex$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$4, _16$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&matches$$3);
	ZVAL_UNDEF(&regex$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(url)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url);


	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_STRING_IDENTICAL(url, "/")) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "/");
	} else {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "/");
		zephir_fast_trim(&_1, url, &_2, ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_SVS(&_0, "/", &_1, "/");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("url"), &_0);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_5, &_4, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 82);
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_strpos(&_6, &_3, &_5, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_6)) {
		zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_8$$3, &_7$$3, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 86);
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("paramOptionalSymbol"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_11$$3, &_10$$3, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 89);
		ZEPHIR_INIT_VAR(&_12$$3);
		ZVAL_STRING(&_12$$3, "%s([\\w]+)(\\%s?)%s");
		ZEPHIR_CALL_FUNCTION(&regex$$3, "sprintf", NULL, 4, &_12$$3, &_8$$3, &_9$$3, &_11$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$3);
		ZEPHIR_CONCAT_SVS(&_13$$3, "/", &regex$$3, "/");
		zephir_read_property(&_14$$3, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_12$$3);
		zephir_preg_match(&_12$$3, &_13$$3, &_14$$3, &matches$$3, 1, 0 , 0 );
		if (zephir_is_true(&_12$$3)) {
			zephir_array_fetch_long(&_15$$4, &matches$$3, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 92);
			ZEPHIR_CALL_FUNCTION(&_16$$4, "array_fill_keys", NULL, 13, &_15$$4, &__$null);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &_16$$4);
		}
	}
	RETURN_THIS();
}

PHP_METHOD(Yuga_Route_Router_LoadableRoute, getUrl)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "url");
}

/**
 * Find url that matches method, parameters or name.
 * Used when calling the url() helper.
 *
 * @param string|null method
 * @param array|null parameters
 * @param string|null name
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_LoadableRoute, findUrl)
{
	zval _26$$7, _37$$12;
	zend_string *_17;
	zend_ulong _16;
	zend_bool _0, _18$$4, _19$$4, _24$$4, _30$$9, _31$$9, _35$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_23 = NULL, *_28 = NULL, *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, *parameters = NULL, parameters_sub, *name = NULL, name_sub, __$null, url, paramOne, paramTwo, max, keys, group, _1, unknownParams, _5, _6, _7, _8, _9, _10, _11, _12, _13, params, param, value, *_14, _15, _39, _40, _41, _42, _2$$3, _3$$3, _4$$3, _20$$4, _22$$4, _25$$4, _21$$6, _27$$7, _32$$9, _34$$9, _36$$9, _33$$11, _38$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&paramOne);
	ZVAL_UNDEF(&paramTwo);
	ZVAL_UNDEF(&max);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&unknownParams);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_37$$12);
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


	ZEPHIR_CALL_METHOD(&url, this_ptr, "geturl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&group, this_ptr, "getgroup", NULL, 0);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&group) != IS_NULL;
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1, &group, "getdomains", NULL, 0);
		zephir_check_call_status();
		_0 = zephir_fast_count_int(&_1) > 0;
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_2$$3, &group, "getdomains", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_long(&_3$$3, &_2$$3, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 121);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVV(&_4$$3, "//", &_3$$3, &url);
		ZEPHIR_CPY_WRT(&url, &_4$$3);
	}
	ZEPHIR_INIT_VAR(&unknownParams);
	array_init(&unknownParams);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_6, &_5, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 128);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_8, &_7, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 128);
	ZEPHIR_INIT_VAR(&paramOne);
	ZEPHIR_CONCAT_VSV(&paramOne, &_6, "%s", &_8);
	zephir_read_property(&_9, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_10, &_9, 0, PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 131);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("paramOptionalSymbol"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_12, this_ptr, ZEND_STRL("paramModifiers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_13, &_12, 1, PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 131);
	ZEPHIR_INIT_VAR(&paramTwo);
	ZEPHIR_CONCAT_VSVV(&paramTwo, &_10, "%s", &_11, &_13);
	ZEPHIR_CALL_METHOD(&params, this_ptr, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&max);
	ZVAL_LONG(&max, (zephir_fast_count_int(&params) - 1));
	ZEPHIR_INIT_VAR(&keys);
	zephir_array_keys(&keys, &params);
	zephir_is_iterable(&params, 0, "yuga/Route/Router/LoadableRoute.zep", 164);
	if (Z_TYPE_P(&params) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _16, _17, _14)
		{
			ZEPHIR_INIT_NVAR(&param);
			if (_17 != NULL) { 
				ZVAL_STR_COPY(&param, _17);
			} else {
				ZVAL_LONG(&param, _16);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _14);
			_18$$4 = Z_TYPE_P(parameters) != IS_NULL;
			if (_18$$4) {
				_18$$4 = zephir_array_key_exists(parameters, &param);
			}
			if (_18$$4) {
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, parameters, &param, PH_NOISY, "yuga/Route/Router/LoadableRoute.zep", 148);
			}
			_19$$4 = Z_TYPE_P(&value) == IS_NULL;
			if (_19$$4) {
				zephir_read_property(&_20$$4, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC | PH_READONLY);
				_19$$4 = zephir_array_isset(&_20$$4, &param);
			}
			if (_19$$4) {
				zephir_read_property(&_21$$6, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &_21$$6, &param, PH_NOISY, "yuga/Route/Router/LoadableRoute.zep", 153);
			}
			ZEPHIR_CALL_FUNCTION(&_22$$4, "stripos", &_23, 14, &url, &paramOne);
			zephir_check_call_status();
			_24$$4 = !ZEPHIR_IS_FALSE_IDENTICAL(&_22$$4);
			if (!(_24$$4)) {
				ZEPHIR_CALL_FUNCTION(&_25$$4, "stripos", &_23, 14, &url, &param);
				zephir_check_call_status();
				_24$$4 = !ZEPHIR_IS_FALSE_IDENTICAL(&_25$$4);
			}
			if (_24$$4) {
				ZEPHIR_INIT_NVAR(&_26$$7);
				zephir_create_array(&_26$$7, 2, 0);
				ZEPHIR_CALL_FUNCTION(&_27$$7, "sprintf", &_28, 4, &paramOne, &param);
				zephir_check_call_status();
				zephir_array_fast_append(&_26$$7, &_27$$7);
				ZEPHIR_CALL_FUNCTION(&_27$$7, "sprintf", &_28, 4, &paramTwo, &param);
				zephir_check_call_status();
				zephir_array_fast_append(&_26$$7, &_27$$7);
				ZEPHIR_CALL_FUNCTION(&_27$$7, "str_ireplace", &_29, 15, &_26$$7, &value, &url);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&url, &_27$$7);
			} else {
				zephir_array_update_zval(&unknownParams, &param, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &params, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_15, &params, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&param, &params, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &params, "current", NULL, 0);
			zephir_check_call_status();
				_30$$9 = Z_TYPE_P(parameters) != IS_NULL;
				if (_30$$9) {
					_30$$9 = zephir_array_key_exists(parameters, &param);
				}
				if (_30$$9) {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch(&value, parameters, &param, PH_NOISY, "yuga/Route/Router/LoadableRoute.zep", 148);
				}
				_31$$9 = Z_TYPE_P(&value) == IS_NULL;
				if (_31$$9) {
					zephir_read_property(&_32$$9, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC | PH_READONLY);
					_31$$9 = zephir_array_isset(&_32$$9, &param);
				}
				if (_31$$9) {
					zephir_read_property(&_33$$11, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch(&value, &_33$$11, &param, PH_NOISY, "yuga/Route/Router/LoadableRoute.zep", 153);
				}
				ZEPHIR_CALL_FUNCTION(&_34$$9, "stripos", &_23, 14, &url, &paramOne);
				zephir_check_call_status();
				_35$$9 = !ZEPHIR_IS_FALSE_IDENTICAL(&_34$$9);
				if (!(_35$$9)) {
					ZEPHIR_CALL_FUNCTION(&_36$$9, "stripos", &_23, 14, &url, &param);
					zephir_check_call_status();
					_35$$9 = !ZEPHIR_IS_FALSE_IDENTICAL(&_36$$9);
				}
				if (_35$$9) {
					ZEPHIR_INIT_NVAR(&_37$$12);
					zephir_create_array(&_37$$12, 2, 0);
					ZEPHIR_CALL_FUNCTION(&_38$$12, "sprintf", &_28, 4, &paramOne, &param);
					zephir_check_call_status();
					zephir_array_fast_append(&_37$$12, &_38$$12);
					ZEPHIR_CALL_FUNCTION(&_38$$12, "sprintf", &_28, 4, &paramTwo, &param);
					zephir_check_call_status();
					zephir_array_fast_append(&_37$$12, &_38$$12);
					ZEPHIR_CALL_FUNCTION(&_38$$12, "str_ireplace", &_29, 15, &_37$$12, &value, &url);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&url, &_38$$12);
				} else {
					zephir_array_update_zval(&unknownParams, &param, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &params, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&param);
	ZEPHIR_INIT_VAR(&_39);
	zephir_fast_join_str(&_39, SL("/"), &unknownParams);
	zephir_concat_self(&url, &_39);
	ZEPHIR_INIT_VAR(&_40);
	ZEPHIR_INIT_VAR(&_41);
	ZVAL_STRING(&_41, "/");
	zephir_fast_trim(&_40, &url, &_41, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&_42);
	ZEPHIR_CONCAT_VS(&_42, &_40, "/");
	ZEPHIR_CPY_WRT(&url, &_42);
	RETURN_CCTOR(&url);
}

/**
 * Returns the provided name for the router.
 *
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_LoadableRoute, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Check if route has given name.
 *
 * @param string name
 * @return bool
 */
PHP_METHOD(Yuga_Route_Router_LoadableRoute, hasName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name, name_sub, localName, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&localName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_INIT_VAR(&localName);
	ZVAL_STRING(&localName, "");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_OBS_NVAR(&localName);
		zephir_read_property(&localName, this_ptr, ZEND_STRL("name"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &localName);
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strtolower(&_2, name);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_1, &_2));
}

/**
 * Add regular expression match for the entire route.
 *
 * @param string regex
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_LoadableRoute, setMatch)
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


	zephir_update_property_zval(this_ptr, ZEND_STRL("regex"), regex);
	RETURN_THISW();
}

/**
 * Get regular expression match used for matching route (if defined).
 *
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_LoadableRoute, getMatch)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "regex");
}

/**
 * Sets the router name, which makes it easier to obtain the url or router at a later point.
 * Alias for LoadableRoute::setName().
 *
 * @see LoadableRoute::setName()
 * @param string|array name
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_LoadableRoute, name)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setname", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the router name, which makes it easier to obtain the url or router at a later point.
 *
 * @param string name
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_LoadableRoute, setName)
{
	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &name);


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), name);
	RETURN_THISW();
}

/**
 * Merge with information from another route.
 *
 * @param array values
 * @param bool merge
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_LoadableRoute, setSettings)
{
	zend_bool _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *merge = NULL, merge_sub, __$false, _0$$3, _2$$4, _3$$4, _4$$4, _6$$5, _7$$6, _8$$6, _9$$6;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&merge_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
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


	if (zephir_array_isset_string(&values, SL("as"))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		_1$$3 = Z_TYPE_P(&_0$$3) != IS_NULL;
		if (_1$$3) {
			_1$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(merge);
		}
		if (_1$$3) {
			zephir_array_fetch_string(&_2$$4, &values, SL("as"), PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 257);
			zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZEPHIR_CONCAT_VSV(&_4$$4, &_2$$4, ".", &_3$$4);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setname", &_5, 0, &_4$$4);
			zephir_check_call_status();
		} else {
			zephir_array_fetch_string(&_6$$5, &values, SL("as"), PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 259);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setname", &_5, 0, &_6$$5);
			zephir_check_call_status();
		}
	}
	if (zephir_array_isset_string(&values, SL("prefix"))) {
		zephir_array_fetch_string(&_7$$6, &values, SL("prefix"), PH_NOISY | PH_READONLY, "yuga/Route/Router/LoadableRoute.zep", 264);
		ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "geturl", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$6);
		ZEPHIR_CONCAT_VV(&_9$$6, &_7$$6, &_8$$6);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seturl", NULL, 0, &_9$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, yuga_route_router_loadableroute_ce, getThis(), "setsettings", &_10, 0, &values, merge);
	zephir_check_call_status();
	RETURN_THIS();
}

