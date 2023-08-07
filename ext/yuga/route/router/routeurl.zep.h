
extern zend_class_entry *yuga_route_router_routeurl_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Router_RouteUrl);

PHP_METHOD(Yuga_Route_Router_RouteUrl, __construct);
PHP_METHOD(Yuga_Route_Router_RouteUrl, matchRoute);
PHP_METHOD(Yuga_Route_Router_RouteUrl, getParams);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeurl___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeurl_matchroute, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_routeurl_getparams, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_router_routeurl_method_entry) {
	PHP_ME(Yuga_Route_Router_RouteUrl, __construct, arginfo_yuga_route_router_routeurl___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yuga_Route_Router_RouteUrl, matchRoute, arginfo_yuga_route_router_routeurl_matchroute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_RouteUrl, getParams, arginfo_yuga_route_router_routeurl_getparams, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
