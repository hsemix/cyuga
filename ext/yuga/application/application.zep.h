
extern zend_class_entry *yuga_application_application_ce;

ZEPHIR_INIT_CLASS(Yuga_Application_Application);

PHP_METHOD(Yuga_Application_Application, __construct);
zend_object *zephir_init_properties_Yuga_Application_Application(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, root)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_application_application_zephir_init_properties_yuga_application_application, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_application_application_method_entry) {
	PHP_ME(Yuga_Application_Application, __construct, arginfo_yuga_application_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
