
extern zend_class_entry *yuga_interfaces_providers_serviceproviderinterface_ce;

ZEPHIR_INIT_CLASS(Yuga_Interfaces_Providers_ServiceProviderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_interfaces_providers_serviceproviderinterface_register, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Yuga\\Interfaces\\Application\\Application, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_interfaces_providers_serviceproviderinterface_method_entry) {
	PHP_ABSTRACT_ME(Yuga_Interfaces_Providers_ServiceProviderInterface, register, arginfo_yuga_interfaces_providers_serviceproviderinterface_register)
	PHP_FE_END
};