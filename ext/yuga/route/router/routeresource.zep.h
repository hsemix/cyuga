
extern zend_class_entry *yuga_route_router_routeresource_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Router_RouteResource);

PHP_METHOD(Yuga_Route_Router_RouteResource, __construct);
PHP_METHOD(Yuga_Route_Router_RouteResource, hasName);
PHP_METHOD(Yuga_Route_Router_RouteResource, findUrl);
PHP_METHOD(Yuga_Route_Router_RouteResource, call);
PHP_METHOD(Yuga_Route_Router_RouteResource, matchRoute);
PHP_METHOD(Yuga_Route_Router_RouteResource, getController);
PHP_METHOD(Yuga_Route_Router_RouteResource, setController);
PHP_METHOD(Yuga_Route_Router_RouteResource, setName);
PHP_METHOD(Yuga_Route_Router_RouteResource, setMethodNames);
PHP_METHOD(Yuga_Route_Router_RouteResource, getMethodNames);
PHP_METHOD(Yuga_Route_Router_RouteResource, setSettings);
zend_object *zephir_init_properties_Yuga_Route_Router_RouteResource(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_hasname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_findurl, 0, 0, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_matchroute, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_getcontroller, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_setcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_setmethodnames, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, names, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_getmethodnames, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_setsettings, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeresource_zephir_init_properties_yuga_route_router_routeresource, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_router_routeresource_method_entry) {
	PHP_ME(Yuga_Route_Router_RouteResource, __construct, arginfo_yuga_route_router_routeresource___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yuga_Route_Router_RouteResource, hasName, arginfo_yuga_route_router_routeresource_hasname, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteResource, findUrl, arginfo_yuga_route_router_routeresource_findurl, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteResource, call, arginfo_yuga_route_router_routeresource_call, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Route_Router_RouteResource, matchRoute, arginfo_yuga_route_router_routeresource_matchroute, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_RouteResource, getController, arginfo_yuga_route_router_routeresource_getcontroller, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_RouteResource, getController, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_RouteResource, setController, arginfo_yuga_route_router_routeresource_setcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteResource, setName, arginfo_yuga_route_router_routeresource_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteResource, setMethodNames, arginfo_yuga_route_router_routeresource_setmethodnames, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_RouteResource, getMethodNames, arginfo_yuga_route_router_routeresource_getmethodnames, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_RouteResource, getMethodNames, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_RouteResource, setSettings, arginfo_yuga_route_router_routeresource_setsettings, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
