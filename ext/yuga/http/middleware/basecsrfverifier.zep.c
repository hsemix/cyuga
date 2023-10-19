
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Middleware_BaseCsrfVerifier)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Http\\Middleware, BaseCsrfVerifier, yuga, http_middleware_basecsrfverifier, yuga_http_middleware_basecsrfverifier_method_entry, 0);

	zend_declare_property_null(yuga_http_middleware_basecsrfverifier_ce, SL("except"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_middleware_basecsrfverifier_ce, SL("csrfToken"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_http_middleware_basecsrfverifier_ce, SL("token"), ZEND_ACC_PROTECTED);
	zephir_declare_class_constant_string(yuga_http_middleware_basecsrfverifier_ce, SL("POST_KEY"), "_token");

	zephir_declare_class_constant_string(yuga_http_middleware_basecsrfverifier_ce, SL("HEADER_KEY"), "X-CSRF-TOKEN");

	zend_class_implements(yuga_http_middleware_basecsrfverifier_ce, 1, yuga_http_middleware_imiddleware_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, __construct)
{
	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, yuga_csrftoken_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("csrfToken"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "hastoken", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "generatetoken", NULL, 0);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("csrfToken"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1, &_3, "gettoken", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("token"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Check if the url matches the urls in the except property
 * @param Request request
 * @return bool
 */
PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, skip)
{
	zend_bool skip = 0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, url, _0, _2, excepts, *_3, _4, _5$$4, _6$$4, _7$$4, _8$$5, _9$$5, _10$$5, _12$$5, _14$$6, _15$$6, _16$$6, _17$$8, _18$$8, _19$$8, _20$$9, _21$$9, _22$$9, _23$$9, _24$$10, _25$$10, _26$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&excepts);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("except"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) == IS_NULL;
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("except"), PH_NOISY_CC | PH_READONLY);
		_1 = Z_TYPE_P(&_2) == IS_ARRAY == 0;
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(&excepts);
	zephir_read_property(&excepts, this_ptr, ZEND_STRL("except"), PH_NOISY_CC);
	zephir_is_iterable(&excepts, 0, "yuga/Http/Middleware/BaseCsrfVerifier.zep", 55);
	if (Z_TYPE_P(&excepts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&excepts), _3)
		{
			ZEPHIR_INIT_NVAR(&url);
			ZVAL_COPY(&url, _3);
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "/");
			zephir_fast_trim(&_5$$4, &url, &_6$$4, ZEPHIR_TRIM_RIGHT);
			ZEPHIR_CPY_WRT(&url, &_5$$4);
			zephir_array_fetch_long(&_7$$4, &url, (zephir_fast_strlen_ev(&url) - 1), PH_NOISY | PH_READONLY, "yuga/Http/Middleware/BaseCsrfVerifier.zep", 43);
			if (ZEPHIR_IS_STRING_IDENTICAL(&_7$$4, "*")) {
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_STRING(&_9$$5, "*");
				zephir_fast_trim(&_8$$5, &url, &_9$$5, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_CPY_WRT(&url, &_8$$5);
				ZEPHIR_CALL_METHOD(&_10$$5, request, "geturi", &_11, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_12$$5, "stripos", &_13, 14, &_10$$5, &url);
				zephir_check_call_status();
				skip = ZEPHIR_IS_LONG_IDENTICAL(&_12$$5, 0);
			} else {
				ZEPHIR_INIT_NVAR(&_14$$6);
				ZEPHIR_CALL_METHOD(&_15$$6, request, "geturi", &_11, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZVAL_STRING(&_16$$6, "/");
				zephir_fast_trim(&_14$$6, &_15$$6, &_16$$6, ZEPHIR_TRIM_RIGHT);
				skip = ZEPHIR_IS_IDENTICAL(&url, &_14$$6);
			}
			if (skip == 1) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &excepts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &excepts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&url, &excepts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$8);
				ZEPHIR_INIT_NVAR(&_18$$8);
				ZVAL_STRING(&_18$$8, "/");
				zephir_fast_trim(&_17$$8, &url, &_18$$8, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_CPY_WRT(&url, &_17$$8);
				zephir_array_fetch_long(&_19$$8, &url, (zephir_fast_strlen_ev(&url) - 1), PH_NOISY | PH_READONLY, "yuga/Http/Middleware/BaseCsrfVerifier.zep", 43);
				if (ZEPHIR_IS_STRING_IDENTICAL(&_19$$8, "*")) {
					ZEPHIR_INIT_NVAR(&_20$$9);
					ZEPHIR_INIT_NVAR(&_21$$9);
					ZVAL_STRING(&_21$$9, "*");
					zephir_fast_trim(&_20$$9, &url, &_21$$9, ZEPHIR_TRIM_RIGHT);
					ZEPHIR_CPY_WRT(&url, &_20$$9);
					ZEPHIR_CALL_METHOD(&_22$$9, request, "geturi", &_11, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_23$$9, "stripos", &_13, 14, &_22$$9, &url);
					zephir_check_call_status();
					skip = ZEPHIR_IS_LONG_IDENTICAL(&_23$$9, 0);
				} else {
					ZEPHIR_INIT_NVAR(&_24$$10);
					ZEPHIR_CALL_METHOD(&_25$$10, request, "geturi", &_11, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_26$$10);
					ZVAL_STRING(&_26$$10, "/");
					zephir_fast_trim(&_24$$10, &_25$$10, &_26$$10, ZEPHIR_TRIM_RIGHT);
					skip = ZEPHIR_IS_IDENTICAL(&url, &_24$$10);
				}
				if (skip == 1) {
					RETURN_MM_BOOL(1);
				}
			ZEPHIR_CALL_METHOD(NULL, &excepts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&url);
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, run)
{
	zval _13$$4;
	zval _3;
	zend_bool _1, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *next, next_sub, __$false, _0, _2, _4, _5, _7, _8, token$$3, _9$$3, _10$$3, _11$$3, _12$$3, _14$$3, _15$$6, _17$$6, _18$$8, _19$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&next_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&token$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_13$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
		Z_PARAM_OBJECT_OF_CLASS(next, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &request, &next);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "skip", NULL, 0, request);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_FALSE_IDENTICAL(&_0);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, request, "getmethod", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3);
		zephir_create_array(&_3, 3, 0);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "post");
		zephir_array_fast_append(&_3, &_4);
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_STRING(&_4, "put");
		zephir_array_fast_append(&_3, &_4);
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_STRING(&_4, "delete");
		zephir_array_fast_append(&_3, &_4);
		ZEPHIR_CALL_FUNCTION(&_5, "in_array", NULL, 57, &_2, &_3, &__$false);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_5);
	}
	_6 = _1;
	if (_6) {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_STRING(&_4, "CSRF_PROTECT");
		ZVAL_BOOL(&_7, 1);
		ZEPHIR_CALL_FUNCTION(&_8, "env", NULL, 0, &_4, &_7);
		zephir_check_call_status();
		_6 = ZEPHIR_IS_TRUE_IDENTICAL(&_8);
	}
	if (_6) {
		ZEPHIR_CALL_METHOD(&_9$$3, request, "getinput", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "_token");
		ZVAL_NULL(&_11$$3);
		ZEPHIR_INIT_VAR(&_12$$3);
		ZVAL_STRING(&_12$$3, "post");
		ZEPHIR_CALL_METHOD(&token$$3, &_9$$3, "get", NULL, 0, &_10$$3, &_11$$3, &_12$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&token$$3) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$4);
			ZEPHIR_CONCAT_SS(&_13$$4, "http-", "X-CSRF-TOKEN");
			ZEPHIR_CALL_METHOD(&token$$3, request, "getheader", NULL, 0, &_13$$4);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(&token$$3) == IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yuga_http_middleware_exceptions_tokenmismatchexception_ce, "Invalid form, Add csrf-token.", "yuga/Http/Middleware/BaseCsrfVerifier.zep", 71);
			return;
		}
		zephir_read_property(&_11$$3, this_ptr, ZEND_STRL("csrfToken"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_14$$3, &_11$$3, "validate", NULL, 0, &token$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_14$$3)) {
			ZEPHIR_CALL_CE_STATIC(&_15$$6, yuga_support_helpers_ce, "app", &_16, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_17$$6, &_15$$6, "getdebugenabled", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_17$$6)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yuga_http_middleware_exceptions_tokenmismatchexception_ce, "Invalid csrf-token.", "yuga/Http/Middleware/BaseCsrfVerifier.zep", 76);
				return;
			} else {
				ZEPHIR_CALL_METHOD(&_18$$8, request, "isajax", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_18$$8)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yuga_http_middleware_exceptions_tokenmismatchexception_ce, "Your form has expired, please refresh the page and try again.", "yuga/Http/Middleware/BaseCsrfVerifier.zep", 79);
					return;
				} else {
					ZEPHIR_INIT_VAR(&_19$$10);
					ZVAL_STRING(&_19$$10, "Yuga\\Controllers\\PageController@formExpired");
					ZEPHIR_CALL_METHOD(NULL, request, "setrewritecallback", NULL, 0, &_19$$10);
					zephir_check_call_status();
					RETVAL_ZVAL(request, 1, 0);
					RETURN_MM();
				}
			}
		}
		ZEPHIR_MAKE_REF(request);
		ZEPHIR_RETURN_CALL_FUNCTION("next", NULL, 68, request);
		ZEPHIR_UNREF(request);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, generateToken)
{
	zval token, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&token, yuga_csrftoken_ce, "generatetoken", &_0, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("csrfToken"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "settoken", NULL, 0, &token);
	zephir_check_call_status();
	RETURN_CCTOR(&token);
}

PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, hasToken)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("token"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("csrfToken"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "hastoken", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Middleware_BaseCsrfVerifier, getToken)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "token");
}

