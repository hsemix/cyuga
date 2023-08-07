
extern zend_class_entry *yuga_route_router_routegroup_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Router_RouteGroup);

PHP_METHOD(Yuga_Route_Router_RouteGroup, matchDomain);
PHP_METHOD(Yuga_Route_Router_RouteGroup, matchRoute);
PHP_METHOD(Yuga_Route_Router_RouteGroup, addExceptionHandler);
PHP_METHOD(Yuga_Route_Router_RouteGroup, setExceptionHandlers);
PHP_METHOD(Yuga_Route_Router_RouteGroup, getExceptionHandlers);
PHP_METHOD(Yuga_Route_Router_RouteGroup, getDomains);
PHP_METHOD(Yuga_Route_Router_RouteGroup, setDomains);
PHP_METHOD(Yuga_Route_Router_RouteGroup, setPrefix);
PHP_METHOD(Yuga_Route_Router_RouteGroup, getPrefix);
PHP_METHOD(Yuga_Route_Router_RouteGroup, setSettings);
PHP_METHOD(Yuga_Route_Router_RouteGroup, toArray);
zend_object *zephir_init_properties_Yuga_Route_Router_RouteGroup(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_matchdomain, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_matchroute, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_addexceptionhandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_setexceptionhandlers, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, handlers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_getexceptionhandlers, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_getdomains, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_setdomains, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, domains, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_getprefix, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_setsettings, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_toarray, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routegroup_zephir_init_properties_yuga_route_router_routegroup, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_router_routegroup_method_entry) {
	PHP_ME(Yuga_Route_Router_RouteGroup, matchDomain, arginfo_yuga_route_router_routegroup_matchdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteGroup, matchRoute, arginfo_yuga_route_router_routegroup_matchroute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteGroup, addExceptionHandler, arginfo_yuga_route_router_routegroup_addexceptionhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteGroup, setExceptionHandlers, arginfo_yuga_route_router_routegroup_setexceptionhandlers, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_RouteGroup, getExceptionHandlers, arginfo_yuga_route_router_routegroup_getexceptionhandlers, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_RouteGroup, getExceptionHandlers, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_RouteGroup, getDomains, arginfo_yuga_route_router_routegroup_getdomains, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_RouteGroup, getDomains, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_RouteGroup, setDomains, arginfo_yuga_route_router_routegroup_setdomains, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteGroup, setPrefix, arginfo_yuga_route_router_routegroup_setprefix, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_RouteGroup, getPrefix, arginfo_yuga_route_router_routegroup_getprefix, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_RouteGroup, getPrefix, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_RouteGroup, setSettings, arginfo_yuga_route_router_routegroup_setsettings, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_RouteGroup, toArray, arginfo_yuga_route_router_routegroup_toarray, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_RouteGroup, toArray, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
