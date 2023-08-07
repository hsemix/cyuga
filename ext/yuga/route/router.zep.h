
extern zend_class_entry *yuga_route_router_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Router);

PHP_METHOD(Yuga_Route_Router, __construct);
PHP_METHOD(Yuga_Route_Router, reset);
PHP_METHOD(Yuga_Route_Router, addRoute);
PHP_METHOD(Yuga_Route_Router, processRoutes);
PHP_METHOD(Yuga_Route_Router, loadRoutes);
PHP_METHOD(Yuga_Route_Router, routeRequest);
PHP_METHOD(Yuga_Route_Router, handleException);
PHP_METHOD(Yuga_Route_Router, arrayToParams);
PHP_METHOD(Yuga_Route_Router, findRoute);
PHP_METHOD(Yuga_Route_Router, getUrl);
PHP_METHOD(Yuga_Route_Router, getBootManagers);
PHP_METHOD(Yuga_Route_Router, setBootManagers);
PHP_METHOD(Yuga_Route_Router, addBootManager);
PHP_METHOD(Yuga_Route_Router, getRoutes);
PHP_METHOD(Yuga_Route_Router, setRoutes);
PHP_METHOD(Yuga_Route_Router, getRequest);
PHP_METHOD(Yuga_Route_Router, getCsrfVerifier);
zend_object *zephir_init_properties_Yuga_Route_Router(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_reset, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_addroute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route, Yuga\\Route\\Support\\IRoute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_processroutes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, routes, 0)
	ZEND_ARG_OBJ_INFO(0, group, Yuga\\Route\\Support\\IGroupRoute, 1)
	ZEND_ARG_OBJ_INFO(0, parent, Yuga\\Route\\Support\\IRoute, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadroutes, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routerequest, 0, 0, 0)
	ZEND_ARG_INFO(0, rewrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_handleexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, e, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_arraytoparams, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, getParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, getParams, 0)
#endif
	ZEND_ARG_INFO(0, includeEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_findroute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_geturl, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, getParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_getbootmanagers, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_setbootmanagers, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bootManagers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_addbootmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootManager, Yuga\\Route\\Support\\IRouterBootManager, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_getroutes, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_setroutes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, routes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_getrequest, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_getcsrfverifier, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_zephir_init_properties_yuga_route_router, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_router_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router, __construct, arginfo_yuga_route_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Yuga_Route_Router, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router, reset, arginfo_yuga_route_router_reset, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router, reset, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router, addRoute, arginfo_yuga_route_router_addroute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router, processRoutes, arginfo_yuga_route_router_processroutes, ZEND_ACC_PROTECTED)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router, loadRoutes, arginfo_yuga_route_router_loadroutes, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router, loadRoutes, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router, routeRequest, arginfo_yuga_route_router_routerequest, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router, handleException, arginfo_yuga_route_router_handleexception, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Route_Router, arrayToParams, arginfo_yuga_route_router_arraytoparams, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router, findRoute, arginfo_yuga_route_router_findroute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router, getUrl, arginfo_yuga_route_router_geturl, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router, getBootManagers, arginfo_yuga_route_router_getbootmanagers, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router, getBootManagers, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router, setBootManagers, arginfo_yuga_route_router_setbootmanagers, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router, addBootManager, arginfo_yuga_route_router_addbootmanager, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router, getRoutes, arginfo_yuga_route_router_getroutes, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router, getRoutes, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router, setRoutes, arginfo_yuga_route_router_setroutes, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router, getRequest, arginfo_yuga_route_router_getrequest, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router, getRequest, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router, getCsrfVerifier, arginfo_yuga_route_router_getcsrfverifier, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router, getCsrfVerifier, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
