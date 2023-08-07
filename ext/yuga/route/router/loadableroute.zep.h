
extern zend_class_entry *yuga_route_router_loadableroute_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Router_LoadableRoute);

PHP_METHOD(Yuga_Route_Router_LoadableRoute, loadMiddleware);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, matchRegex);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, setUrl);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, getUrl);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, findUrl);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, getName);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, hasName);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, setMatch);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, getMatch);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, name);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, setName);
PHP_METHOD(Yuga_Route_Router_LoadableRoute, setSettings);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_loadmiddleware, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_matchregex, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_seturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_geturl, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_findurl, 0, 0, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_hasname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_setmatch, 0, 0, 1)
	ZEND_ARG_INFO(0, regex)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_getmatch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_name, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_loadableroute_setsettings, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_router_loadableroute_method_entry) {
	PHP_ME(Yuga_Route_Router_LoadableRoute, loadMiddleware, arginfo_yuga_route_router_loadableroute_loadmiddleware, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_LoadableRoute, matchRegex, arginfo_yuga_route_router_loadableroute_matchregex, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_LoadableRoute, setUrl, arginfo_yuga_route_router_loadableroute_seturl, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_LoadableRoute, getUrl, arginfo_yuga_route_router_loadableroute_geturl, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_LoadableRoute, getUrl, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_LoadableRoute, findUrl, arginfo_yuga_route_router_loadableroute_findurl, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_LoadableRoute, getName, arginfo_yuga_route_router_loadableroute_getname, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_LoadableRoute, getName, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_LoadableRoute, hasName, arginfo_yuga_route_router_loadableroute_hasname, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_LoadableRoute, setMatch, arginfo_yuga_route_router_loadableroute_setmatch, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_LoadableRoute, getMatch, arginfo_yuga_route_router_loadableroute_getmatch, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_LoadableRoute, getMatch, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_LoadableRoute, name, arginfo_yuga_route_router_loadableroute_name, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_LoadableRoute, setName, arginfo_yuga_route_router_loadableroute_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_LoadableRoute, setSettings, arginfo_yuga_route_router_loadableroute_setsettings, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
