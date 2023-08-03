
extern zend_class_entry *yuga_route_support_irouterbootmanager_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Support_IRouterBootManager);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_irouterbootmanager_boot, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_support_irouterbootmanager_method_entry) {
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRouterBootManager, boot, arginfo_yuga_route_support_irouterbootmanager_boot)
	PHP_FE_END
};
