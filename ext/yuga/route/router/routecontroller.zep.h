
extern zend_class_entry *yuga_route_router_routecontroller_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Router_RouteController);

PHP_METHOD(Yuga_Route_Router_RouteController, __construct);
PHP_METHOD(Yuga_Route_Router_RouteController, hasName);
PHP_METHOD(Yuga_Route_Router_RouteController, findUrl);
PHP_METHOD(Yuga_Route_Router_RouteController, matchRoute);
PHP_METHOD(Yuga_Route_Router_RouteController, getController);
PHP_METHOD(Yuga_Route_Router_RouteController, setController);
PHP_METHOD(Yuga_Route_Router_RouteController, getMethod);
PHP_METHOD(Yuga_Route_Router_RouteController, setMethod);
PHP_METHOD(Yuga_Route_Router_RouteController, setSettings);
zend_object *zephir_init_properties_Yuga_Route_Router_RouteController(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routecontroller___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routecontroller_hasname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routecontroller_findurl, 0, 0, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routecontroller_matchroute, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routecontroller_getcontroller, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routecontroller_setcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routecontroller_getmethod, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routecontroller_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routecontroller_setsettings, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routecontroller_zephir_init_properties_yuga_route_router_routecontroller, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_router_routecontroller_method_entry) {
	PHP_ME(Yuga_Route_Router_RouteController, __construct, arginfo_yuga_route_router_routecontroller___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yuga_Route_Router_RouteController, hasName, arginfo_yuga_route_router_routecontroller_hasname, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteController, findUrl, arginfo_yuga_route_router_routecontroller_findurl, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteController, matchRoute, arginfo_yuga_route_router_routecontroller_matchroute, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_RouteController, getController, arginfo_yuga_route_router_routecontroller_getcontroller, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_RouteController, getController, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_RouteController, setController, arginfo_yuga_route_router_routecontroller_setcontroller, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_RouteController, getMethod, arginfo_yuga_route_router_routecontroller_getmethod, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_RouteController, getMethod, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_RouteController, setMethod, arginfo_yuga_route_router_routecontroller_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteController, setSettings, arginfo_yuga_route_router_routecontroller_setsettings, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
