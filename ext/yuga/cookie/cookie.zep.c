
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/time.h"


ZEPHIR_INIT_CLASS(Yuga_Cookie_Cookie)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Cookie, Cookie, yuga, cookie_cookie, yuga_cookie_cookie_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Yuga_Cookie_Cookie, exists)
{
	zval *name, name_sub, _COOKIE;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_COOKIE);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params_without_memory_grow(1, 0, &name);


	if (zephir_array_isset(&_COOKIE, name)) {
		RETURN_BOOL(1);
	}
	RETURN_BOOL(0);
}

PHP_METHOD(Yuga_Cookie_Cookie, get)
{
	zval *name, name_sub, _COOKIE, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params_without_memory_grow(1, 0, &name);


	zephir_array_fetch(&_0, &_COOKIE, name, PH_NOISY | PH_READONLY, "yuga/Cookie/Cookie.zep", 15);
	RETURN_CTORW(&_0);
}

PHP_METHOD(Yuga_Cookie_Cookie, put)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, *expiry = NULL, expiry_sub, *domain = NULL, domain_sub, *secure = NULL, secure_sub, *path = NULL, path_sub, __$null, __$true;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&expiry_sub);
	ZVAL_UNDEF(&domain_sub);
	ZVAL_UNDEF(&secure_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 6)
		Z_PARAM_ZVAL(name)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(expiry)
		Z_PARAM_ZVAL_OR_NULL(domain)
		Z_PARAM_ZVAL(secure)
		Z_PARAM_ZVAL(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 4, &name, &value, &expiry, &domain, &secure, &path);
	if (!expiry) {
		expiry = &expiry_sub;
		expiry = &__$null;
	}
	if (!domain) {
		domain = &domain_sub;
		domain = &__$null;
	}
	if (!secure) {
		secure = &secure_sub;
		secure = &__$true;
	}
	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/");
	}


	ZEPHIR_RETURN_CALL_SELF("create", NULL, 0, name, value, expiry, domain, secure, path);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Cookie_Cookie, create)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, *expiry = NULL, expiry_sub, *domain = NULL, domain_sub, *secure = NULL, secure_sub, *path = NULL, path_sub, __$null, __$true, _1$$4, _2$$5, _3$$5, expiryValue$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&expiry_sub);
	ZVAL_UNDEF(&domain_sub);
	ZVAL_UNDEF(&secure_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&expiryValue$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 6)
		Z_PARAM_ZVAL(name)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(expiry)
		Z_PARAM_ZVAL_OR_NULL(domain)
		Z_PARAM_ZVAL(secure)
		Z_PARAM_ZVAL(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 4, &name, &value, &expiry, &domain, &secure, &path);
	if (!expiry) {
		expiry = &expiry_sub;
		ZEPHIR_CPY_WRT(expiry, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(expiry);
	}
	if (!domain) {
		domain = &domain_sub;
		domain = &__$null;
	}
	if (!secure) {
		secure = &secure_sub;
		secure = &__$true;
	}
	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/");
	}


	_0 = !(ZEPHIR_IS_EMPTY(name));
	if (_0) {
		_0 = !(Z_TYPE_P(name) == IS_NULL);
	}
	if (_0) {
		if (Z_TYPE_P(expiry) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_time(&_1$$4);
			ZEPHIR_INIT_NVAR(expiry);
			ZVAL_LONG(expiry, (zephir_get_numberval(&_1$$4) + ((3600 * 24) * 6004)));
		} else {
			ZEPHIR_INIT_VAR(&_2$$5);
			zephir_time(&_2$$5);
			ZEPHIR_INIT_VAR(&_3$$5);
			zephir_add_function(&_3$$5, &_2$$5, expiry);
			ZEPHIR_CPY_WRT(expiry, &_3$$5);
		}
		ZEPHIR_INIT_VAR(&expiryValue$$3);
		ZVAL_NULL(&expiryValue$$3);
		if (ZEPHIR_GT_LONG(expiry, 0)) {
			ZEPHIR_CPY_WRT(&expiryValue$$3, expiry);
		}
		ZEPHIR_RETURN_CALL_FUNCTION("setcookie", NULL, 31, name, value, &expiryValue$$3, path, domain, secure);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Cookie_Cookie, delete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	ZVAL_LONG(&_1, -1);
	ZEPHIR_RETURN_CALL_SELF("put", NULL, 0, name, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

