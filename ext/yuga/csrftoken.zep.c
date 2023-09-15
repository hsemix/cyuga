
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yuga_CsrfToken)
{
	ZEPHIR_REGISTER_CLASS(Yuga, CsrfToken, yuga, csrftoken, yuga_csrftoken_method_entry, 0);

	zend_declare_property_null(yuga_csrftoken_ce, SL("token"), ZEND_ACC_PROTECTED);
	zephir_declare_class_constant_string(yuga_csrftoken_ce, SL("CSRF_KEY"), "CSRF-TOKEN");

	return SUCCESS;
}

/**
 * Generate random identifier for CSRF token
 *
 * @throws \RuntimeException
 * @return string
 */
PHP_METHOD(Yuga_CsrfToken, generateToken)
{
	zend_bool isSourceStrong, _5;
	zval _0$$3, _1$$3, random, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&random);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_GROW();

	if ((zephir_function_exists_ex(ZEND_STRL("random_bytes")) == SUCCESS)) {
		ZVAL_LONG(&_0$$3, 32);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "random_bytes", NULL, 37, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("bin2hex", NULL, 38, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	isSourceStrong = 0;
	ZVAL_LONG(&_2, 32);
	if (isSourceStrong) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_MAKE_REF(&_3);
	ZEPHIR_CALL_FUNCTION(&_4, "openssl_random_pseudo_bytes", NULL, 39, &_2, &_3);
	ZEPHIR_UNREF(&_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&random, "bin2hex", NULL, 38, &_4);
	zephir_check_call_status();
	_5 = isSourceStrong == 0;
	if (!(_5)) {
		_5 = ZEPHIR_IS_FALSE_IDENTICAL(&random);
	}
	if (_5) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "IV generation failed", "yuga/CsrfToken.zep", 27);
		return;
	}
	RETURN_CCTOR(&random);
}

/**
 * Validate valid CSRF token
 *
 * @param string token
 * @return bool
 */
PHP_METHOD(Yuga_CsrfToken, validate)
{
	zend_bool _0$$3, _4$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *token, token_sub, _1$$3, _3$$4, _5$$5, _6$$6, _7$$6, _8$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(token)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &token);


	if ((zephir_function_exists_ex(ZEND_STRL("hash_equals")) == SUCCESS)) {
		_0$$3 = Z_TYPE_P(token) != IS_NULL;
		if (_0$$3) {
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "gettoken", &_2, 0);
			zephir_check_call_status();
			_0$$3 = Z_TYPE_P(&_1$$3) != IS_NULL;
		}
		if (_0$$3) {
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "gettoken", &_2, 0);
			zephir_check_call_status();
			RETURN_MM_BOOL(zephir_hash_equals(token, &_3$$4));
		}
	} else {
		_4$$5 = Z_TYPE_P(token) != IS_NULL;
		if (_4$$5) {
			ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "gettoken", &_2, 0);
			zephir_check_call_status();
			_4$$5 = Z_TYPE_P(&_5$$5) != IS_NULL;
		}
		if (_4$$5) {
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "gettoken", &_2, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_IDENTICAL(token, &_7$$6))) {
				ZVAL_BOOL(&_6$$6, 0);
			} else {
				ZEPHIR_CALL_METHOD(&_8$$8, this_ptr, "gettoken", &_2, 0);
				zephir_check_call_status();
				ZVAL_BOOL(&_6$$6, ZEPHIR_IS_IDENTICAL(token, &_8$$8));
			}
			RETURN_CCTOR(&_6$$6);
		}
	}
	RETURN_MM_BOOL(0);
}

/**
 * Set csrf token cookie
 *
 * @param token
 */
PHP_METHOD(Yuga_CsrfToken, setToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *token, token_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(token)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &token);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "CSRF-TOKEN");
	ZVAL_LONG(&_2, 7200);
	ZEPHIR_CALL_CE_STATIC(NULL, yuga_cookie_cookie_ce, "put", &_0, 0, &_1, token, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Get csrf token
 * @return string|null
 */
PHP_METHOD(Yuga_CsrfToken, getToken)
{
	zval _0, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hastoken", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "CSRF-TOKEN");
		ZEPHIR_RETURN_CALL_CE_STATIC(yuga_cookie_cookie_ce, "get", &_1, 0, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

/**
 * Returns whether the csrf token has been defined
 * @return bool
 */
PHP_METHOD(Yuga_CsrfToken, hasToken)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "CSRF-TOKEN");
	ZEPHIR_RETURN_CALL_CE_STATIC(yuga_cookie_cookie_ce, "exists", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

