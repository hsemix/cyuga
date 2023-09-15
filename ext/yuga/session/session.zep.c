
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yuga_Session_Session)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Session, Session, yuga, session_session, yuga_session_session_method_entry, 0);

	zend_declare_property_bool(yuga_session_session_ce, SL("logged_in"), 0, ZEND_ACC_PRIVATE);
	zend_declare_property_null(yuga_session_session_ce, SL("user_id"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(yuga_session_session_ce, SL("instances"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);
	zend_declare_property_null(yuga_session_session_ce, SL("app"), ZEND_ACC_PRIVATE);
	zend_declare_property_string(yuga_session_session_ce, SL("sessionName"), "yuga_session", ZEND_ACC_PRIVATE);
	zend_class_implements(yuga_session_session_ce, 1, yuga_interfaces_session_isession_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Session_Session, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, _0, config, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(app, zephir_get_internal_ce(SL("yuga\\application\\application")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);


	ZEPHIR_CALL_FUNCTION(&_0, "session_status", NULL, 19);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_0, 1)) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL, 20);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, app, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "config.Settings");
	ZEPHIR_CALL_METHOD(&config, &_1, "load", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "session.name");
	ZEPHIR_CALL_METHOD(&_3, &config, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("sessionName"), &_3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "check_login", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Session_Session, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "sessionName");
}

PHP_METHOD(Yuga_Session_Session, is_logged_in)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _1, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_1, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_SELF(&_0, "exists", NULL, 0, &_1);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (_2) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_SELF(&_3, "get", NULL, 0, &_4);
		zephir_check_call_status();
		_2 = zephir_is_true(&_3);
	}
	if (_2) {
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("logged_in"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("logged_in"), &__$false);
		}
	}
	RETURN_MM_MEMBER(getThis(), "logged_in");
}

PHP_METHOD(Yuga_Session_Session, isLoggedIn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "is_logged_in", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Session_Session, login)
{
	zval *user = NULL, user_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(user)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &user);
	if (!user) {
		user = &user_sub;
		user = &__$null;
	}


}

PHP_METHOD(Yuga_Session_Session, getUserId)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Session_Session, logout)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_SELF(NULL, "delete", NULL, 0, &_0);
	zephir_check_call_status();
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("logged_in"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("logged_in"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Session_Session, check_login)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _1, _2$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_1, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_SELF(&_0, "exists", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_SELF(&_2$$3, "get", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("user_id"), &_2$$3);
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("logged_in"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("logged_in"), &__$false);
		}
	} else {
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("logged_in"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("logged_in"), &__$false);
		}
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Session_Session, put)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, _SESSION, data, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 2, 0, &name, &value);


	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 2, 0);
	ZEPHIR_CALL_FUNCTION(&_0, "serialize", NULL, 21, value);
	zephir_check_call_status();
	zephir_array_fast_append(&data, &_0);
	ZEPHIR_CALL_STATIC(&_0, "getsecret", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&data, &_0);
	ZEPHIR_CALL_STATIC(&_0, "getsecret", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_join_str(&_2, SL("|"), &data);
	ZEPHIR_CALL_CE_STATIC(&data, yuga_guid_ce, "encrypt", &_1, 0, &_0, &_2);
	zephir_check_call_status();
	zephir_array_update_zval(&_SESSION, name, &data, PH_COPY | PH_SEPARATE);
	zephir_array_fetch(&_3, &_SESSION, name, PH_NOISY | PH_READONLY, "yuga/Session/Session.zep", 83);
	RETURN_CTOR(&_3);
}

PHP_METHOD(Yuga_Session_Session, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name, name_sub, _SESSION, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_array_isset(&_SESSION, name)) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Yuga_Session_Session, has)
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


	ZEPHIR_RETURN_CALL_SELF("exists", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Session_Session, delete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _SESSION, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_CALL_SELF(&_0, "exists", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_array_unset(&_SESSION, name, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Yuga_Session_Session, getSecret)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "APP_SECRET");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "NoApplicationSecretDefined");
	ZEPHIR_CALL_FUNCTION(&_2, "env", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	zephir_md5(return_value, &_2);
	RETURN_MM();
}

PHP_METHOD(Yuga_Session_Session, get)
{
	zend_bool _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *defaultValue = NULL, defaultValue_sub, _SESSION, __$null, _0, value$$3, _1$$3, value$$4, _2$$4, _4$$4, data$$4, _6$$4, _7$$4, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&value$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&value$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&data$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 1, &name, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_STATIC(&_0, "exists", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_OBS_VAR(&value$$3);
		zephir_array_fetch(&value$$3, &_SESSION, name, PH_NOISY, "yuga/Session/Session.zep", 121);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_trim(&_1$$3, &value$$3, NULL , ZEPHIR_TRIM_BOTH);
		if (!ZEPHIR_IS_STRING_IDENTICAL(&_1$$3, "")) {
			ZEPHIR_CALL_STATIC(&_4$$4, "getsecret", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_CE_STATIC(&_2$$4, yuga_guid_ce, "decrypt", &_3, 0, &_4$$4, &value$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value$$4, &_2$$4);
			ZEPHIR_INIT_VAR(&data$$4);
			zephir_fast_explode_str(&data$$4, SL("|"), &value$$4, LONG_MAX);
			_5$$4 = Z_TYPE_P(&data$$4) == IS_ARRAY;
			if (_5$$4) {
				ZEPHIR_INIT_VAR(&_6$$4);
				ZEPHIR_MAKE_REF(&data$$4);
				ZEPHIR_CALL_FUNCTION(&_2$$4, "end", NULL, 22, &data$$4);
				ZEPHIR_UNREF(&data$$4);
				zephir_check_call_status();
				zephir_fast_trim(&_6$$4, &_2$$4, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CALL_STATIC(&_7$$4, "getsecret", NULL, 0);
				zephir_check_call_status();
				_5$$4 = ZEPHIR_IS_IDENTICAL(&_6$$4, &_7$$4);
			}
			if (_5$$4) {
				zephir_array_fetch_long(&_8$$5, &data$$4, 0, PH_NOISY | PH_READONLY, "yuga/Session/Session.zep", 126);
				ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 23, &_8$$5);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

PHP_METHOD(Yuga_Session_Session, flash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *stringVal = NULL, stringVal_sub, __$null, _0, session$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&stringVal_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&session$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(stringVal)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &stringVal);
	if (!stringVal) {
		stringVal = &stringVal_sub;
		stringVal = &__$null;
	}


	ZEPHIR_CALL_SELF(&_0, "exists", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_SELF(&session$$3, "get", NULL, 0, name);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(NULL, "delete", NULL, 0, name);
		zephir_check_call_status();
		RETURN_CCTOR(&session$$3);
	} else {
		if (zephir_is_true(stringVal)) {
			ZEPHIR_CALL_SELF(NULL, "put", NULL, 0, name, stringVal);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

void zephir_init_static_properties_Yuga_Session_Session()
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(yuga_session_session_ce, ZEND_STRL("instances"), &_0);
	ZEPHIR_MM_RESTORE();
}

