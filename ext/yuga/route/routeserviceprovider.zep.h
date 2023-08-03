
extern zend_class_entry *yuga_route_routeserviceprovider_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_RouteServiceProvider);

PHP_METHOD(Yuga_Route_RouteServiceProvider, load);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_routeserviceprovider_load, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Yuga\\Interfaces\\Application\\Application, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_routeserviceprovider_method_entry) {
	PHP_ME(Yuga_Route_RouteServiceProvider, load, arginfo_yuga_route_routeserviceprovider_load, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
