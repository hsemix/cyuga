
extern zend_class_entry *yuga_session_sessionserviceprovider_ce;

ZEPHIR_INIT_CLASS(Yuga_Session_SessionServiceProvider);

PHP_METHOD(Yuga_Session_SessionServiceProvider, load);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_session_sessionserviceprovider_load, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Yuga\\Interfaces\\Application\\Application, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_session_sessionserviceprovider_method_entry) {
	PHP_ME(Yuga_Session_SessionServiceProvider, load, arginfo_yuga_session_sessionserviceprovider_load, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
