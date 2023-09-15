
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yuga_Guid)
{
	ZEPHIR_REGISTER_CLASS(Yuga, Guid, yuga, guid, yuga_guid_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Yuga_Guid, create)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *separator = NULL, separator_sub, __$false, guid$$3, _0$$3, _1$$3, _2$$4, _3$$4, _4$$4, pattern, _5, _6, _7, _9, _10, _11, _12, _13, _14, _15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&guid$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(separator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &separator);
	if (!separator) {
		separator = &separator_sub;
		separator = &__$false;
	}


	if ((zephir_function_exists_ex(ZEND_STRL("com_create_guid")) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "com_create_guid", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "{}");
		ZEPHIR_INIT_VAR(&guid$$3);
		zephir_fast_trim(&guid$$3, &_0$$3, &_1$$3, ZEPHIR_TRIM_BOTH);
		if (!(zephir_is_true(separator))) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "-");
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "");
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_fast_str_replace(&_4$$4, &_2$$4, &_3$$4, &guid$$3);
			RETURN_CCTOR(&_4$$4);
		}
		RETURN_CCTOR(&guid$$3);
	}
	ZEPHIR_INIT_VAR(&pattern);
	ZVAL_STRING(&pattern, "%04X%04X-%04X-%04X-%04X-%04X%04X%04X");
	if (!zephir_is_true(separator)) {
		ZEPHIR_INIT_NVAR(&pattern);
		ZVAL_STRING(&pattern, "%04X%04X%04X%04X%04X%04X%04X%04X");
	}
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 65535);
	ZEPHIR_CALL_FUNCTION(&_7, "mt_rand", &_8, 41, &_5, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 65535);
	ZEPHIR_CALL_FUNCTION(&_9, "mt_rand", &_8, 41, &_5, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 65535);
	ZEPHIR_CALL_FUNCTION(&_10, "mt_rand", &_8, 41, &_5, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 16384);
	ZVAL_LONG(&_6, 20479);
	ZEPHIR_CALL_FUNCTION(&_11, "mt_rand", &_8, 41, &_5, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 32768);
	ZVAL_LONG(&_6, 49151);
	ZEPHIR_CALL_FUNCTION(&_12, "mt_rand", &_8, 41, &_5, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 65535);
	ZEPHIR_CALL_FUNCTION(&_13, "mt_rand", &_8, 41, &_5, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 65535);
	ZEPHIR_CALL_FUNCTION(&_14, "mt_rand", &_8, 41, &_5, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 65535);
	ZEPHIR_CALL_FUNCTION(&_15, "mt_rand", &_8, 41, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 4, &pattern, &_7, &_9, &_10, &_11, &_12, &_13, &_14, &_15);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Guid, encrypt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *key = NULL, key_sub, *data = NULL, data_sub, *method = NULL, method_sub, __$true, __$null, _0$$3, _2, _3, _4, _5, iv, _6, _7, _8, _9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&method_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &data, &method);
	ZEPHIR_SEPARATE_PARAM(key);
	ZEPHIR_SEPARATE_PARAM(data);
	if (!method) {
		method = &method_sub;
		ZEPHIR_CPY_WRT(method, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(method);
	}


	if (Z_TYPE_P(method) == IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(&_0$$3, yuga_support_helpers_ce, "app", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(method, &_0$$3, "getencryptionmethod", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "sha256");
	ZEPHIR_CALL_FUNCTION(&_3, "hash", NULL, 42, &_2, key, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_5, 16);
	ZEPHIR_INIT_NVAR(key);
	zephir_substr(key, &_3, 0 , 16 , 0);
	ZEPHIR_CALL_FUNCTION(&_6, "openssl_cipher_iv_length", NULL, 43, method);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&iv, "openssl_random_pseudo_bytes", NULL, 34, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "openssl_encrypt", NULL, 44, data, method, key, &_7, &iv);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, &_8);
	ZEPHIR_CALL_FUNCTION(&_8, "bin2hex", NULL, 33, &iv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_VSV(&_9, data, "|", &_8);
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 45, &_9);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Guid, decrypt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *key = NULL, key_sub, *data = NULL, data_sub, *method = NULL, method_sub, __$true, __$null, _0$$3, _2, _3, _4, _5, exploded, _6, iv, binary, _7, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&method_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&exploded);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&binary);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &data, &method);
	ZEPHIR_SEPARATE_PARAM(key);
	ZEPHIR_SEPARATE_PARAM(data);
	if (!method) {
		method = &method_sub;
		ZEPHIR_CPY_WRT(method, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(method);
	}


	if (Z_TYPE_P(method) == IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(&_0$$3, yuga_support_helpers_ce, "app", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(method, &_0$$3, "getencryptionmethod", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "sha256");
	ZEPHIR_CALL_FUNCTION(&_3, "hash", NULL, 42, &_2, key, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_5, 16);
	ZEPHIR_INIT_NVAR(key);
	zephir_substr(key, &_3, 0 , 16 , 0);
	ZEPHIR_CALL_FUNCTION(&_6, "base64_decode", NULL, 46, data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&exploded);
	zephir_fast_explode_str(&exploded, SL("|"), &_6, LONG_MAX);
	ZEPHIR_OBS_NVAR(data);
	zephir_array_fetch_long(data, &exploded, 0, PH_NOISY, "yuga/Guid.zep", 54);
	ZEPHIR_OBS_VAR(&iv);
	zephir_array_fetch_long(&iv, &exploded, 1, PH_NOISY, "yuga/Guid.zep", 55);
	ZEPHIR_CALL_FUNCTION(&binary, "hex2bin", NULL, 47, &iv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(&binary)) {
		RETURN_MM_BOOL(0);
	}
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "openssl_decrypt", NULL, 48, data, method, key, &_7, &binary);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, &_8);
	RETVAL_ZVAL(data, 1, 0);
	RETURN_MM();
}

/**
 * Creates an random password, with a given length.
 * @param int length
 * @return string
 * @throws \Exception
 */
PHP_METHOD(Yuga_Guid, createRandomPassword)
{
	zval *length, length_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(length)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &length);


}

/**
 * Creates random very unique string
 * @return string
 */
PHP_METHOD(Yuga_Guid, generateSalt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "mt_rand", NULL, 41);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "uniqid", NULL, 49, &_0, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "2y");
	ZEPHIR_RETURN_CALL_FUNCTION("password_hash", NULL, 50, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

