
extern zend_class_entry *yuga_session_session_ce;

ZEPHIR_INIT_CLASS(Yuga_Session_Session);

PHP_METHOD(Yuga_Session_Session, __construct);
PHP_METHOD(Yuga_Session_Session, getName);
PHP_METHOD(Yuga_Session_Session, is_logged_in);
PHP_METHOD(Yuga_Session_Session, isLoggedIn);
PHP_METHOD(Yuga_Session_Session, login);
PHP_METHOD(Yuga_Session_Session, getUserId);
PHP_METHOD(Yuga_Session_Session, logout);
PHP_METHOD(Yuga_Session_Session, check_login);
PHP_METHOD(Yuga_Session_Session, put);
PHP_METHOD(Yuga_Session_Session, exists);
PHP_METHOD(Yuga_Session_Session, has);
PHP_METHOD(Yuga_Session_Session, delete);
PHP_METHOD(Yuga_Session_Session, getSecret);
PHP_METHOD(Yuga_Session_Session, get);
PHP_METHOD(Yuga_Session_Session, flash);
void zephir_init_static_properties_Yuga_Session_Session();

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Yuga\\Application\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_is_logged_in, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_isloggedin, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_login, 0, 0, 0)
	ZEND_ARG_INFO(0, user)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_getuserid, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_logout, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_check_login, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_put, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_getsecret, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_flash, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, stringVal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_session_zephir_init_static_properties_yuga_session_session, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_session_session_method_entry) {
	PHP_ME(Yuga_Session_Session, __construct, arginfo_yuga_session_session___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Session_Session, getName, arginfo_yuga_session_session_getname, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Session_Session, getName, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Session_Session, is_logged_in, arginfo_yuga_session_session_is_logged_in, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Session_Session, is_logged_in, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Session_Session, isLoggedIn, arginfo_yuga_session_session_isloggedin, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Session_Session, isLoggedIn, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Session_Session, login, arginfo_yuga_session_session_login, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Session_Session, getUserId, arginfo_yuga_session_session_getuserid, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Session_Session, getUserId, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Session_Session, logout, arginfo_yuga_session_session_logout, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Session_Session, logout, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Session_Session, check_login, arginfo_yuga_session_session_check_login, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Session_Session, check_login, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Session_Session, put, arginfo_yuga_session_session_put, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Session_Session, exists, arginfo_yuga_session_session_exists, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Session_Session, has, arginfo_yuga_session_session_has, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Session_Session, delete, arginfo_yuga_session_session_delete, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Session_Session, getSecret, arginfo_yuga_session_session_getsecret, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_Session_Session, getSecret, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(Yuga_Session_Session, get, arginfo_yuga_session_session_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Session_Session, flash, arginfo_yuga_session_session_flash, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
