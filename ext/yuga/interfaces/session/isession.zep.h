
extern zend_class_entry *yuga_interfaces_session_isession_ce;

ZEPHIR_INIT_CLASS(Yuga_Interfaces_Session_ISession);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_session_isession_check_login, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_session_isession_isloggedin, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_session_isession_is_logged_in, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_session_isession_login, 0, 0, 0)
	ZEND_ARG_INFO(0, user)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_session_isession_logout, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_session_isession_put, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_session_isession_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_session_isession_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_session_isession_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_session_isession_flash, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, stringVal)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_interfaces_session_isession_method_entry) {
	PHP_ABSTRACT_ME(Yuga_Interfaces_Session_ISession, check_login, arginfo_yuga_interfaces_session_isession_check_login)
	PHP_ABSTRACT_ME(Yuga_Interfaces_Session_ISession, isLoggedIn, arginfo_yuga_interfaces_session_isession_isloggedin)
	PHP_ABSTRACT_ME(Yuga_Interfaces_Session_ISession, is_logged_in, arginfo_yuga_interfaces_session_isession_is_logged_in)
	PHP_ABSTRACT_ME(Yuga_Interfaces_Session_ISession, login, arginfo_yuga_interfaces_session_isession_login)
	PHP_ABSTRACT_ME(Yuga_Interfaces_Session_ISession, logout, arginfo_yuga_interfaces_session_isession_logout)
	ZEND_FENTRY(put, NULL, arginfo_yuga_interfaces_session_isession_put, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(exists, NULL, arginfo_yuga_interfaces_session_isession_exists, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(delete, NULL, arginfo_yuga_interfaces_session_isession_delete, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(get, NULL, arginfo_yuga_interfaces_session_isession_get, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(flash, NULL, arginfo_yuga_interfaces_session_isession_flash, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
