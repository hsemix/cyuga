
extern zend_class_entry *yuga_support_helpers_ce;

ZEPHIR_INIT_CLASS(Yuga_Support_Helpers);

PHP_METHOD(Yuga_Support_Helpers, view);
PHP_METHOD(Yuga_Support_Helpers, path);
PHP_METHOD(Yuga_Support_Helpers, storage);
PHP_METHOD(Yuga_Support_Helpers, env);
PHP_METHOD(Yuga_Support_Helpers, app);
PHP_METHOD(Yuga_Support_Helpers, event);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_helpers_view, 0, 0, 0)
	ZEND_ARG_INFO(0, template)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_helpers_path, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_helpers_storage, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_helpers_env, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_helpers_app, 0, 0, 0)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_helpers_event, 0, 0, 0)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_support_helpers_method_entry) {
	PHP_ME(Yuga_Support_Helpers, view, arginfo_yuga_support_helpers_view, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Support_Helpers, path, arginfo_yuga_support_helpers_path, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Support_Helpers, storage, arginfo_yuga_support_helpers_storage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Support_Helpers, env, arginfo_yuga_support_helpers_env, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Support_Helpers, app, arginfo_yuga_support_helpers_app, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Support_Helpers, event, arginfo_yuga_support_helpers_event, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
