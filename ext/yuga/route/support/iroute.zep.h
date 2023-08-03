
extern zend_class_entry *yuga_route_support_iroute_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Support_IRoute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_matchroute, 0, 0, 2)
	ZEND_ARG_INFO(0, route)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_renderroute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getidentifier, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setrequestmethods, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, methods, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getrequestmethods, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getparent, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getgroup, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setgroup, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, group, Yuga\\Route\\Support\\IGroupRoute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setparent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, parent, Yuga\\Route\\Support\\IRoute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setcallback, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getcallback, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getmethod, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getclass, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getnamespace, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getdefaultnamespace, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getwhere, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setwhere, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getparameters, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setparameters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setsettings, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, settings, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_toarray, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_getmiddlewares, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_addmiddleware, 0, 0, 1)
	ZEND_ARG_INFO(0, middleware)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iroute_setmiddlewares, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, middlewares, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_support_iroute_method_entry) {
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, matchRoute, arginfo_yuga_route_support_iroute_matchroute)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, renderRoute, arginfo_yuga_route_support_iroute_renderroute)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getIdentifier, arginfo_yuga_route_support_iroute_getidentifier)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setRequestMethods, arginfo_yuga_route_support_iroute_setrequestmethods)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getRequestMethods, arginfo_yuga_route_support_iroute_getrequestmethods)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getParent, arginfo_yuga_route_support_iroute_getparent)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getGroup, arginfo_yuga_route_support_iroute_getgroup)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setGroup, arginfo_yuga_route_support_iroute_setgroup)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setParent, arginfo_yuga_route_support_iroute_setparent)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setCallback, arginfo_yuga_route_support_iroute_setcallback)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getCallback, arginfo_yuga_route_support_iroute_getcallback)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getMethod, arginfo_yuga_route_support_iroute_getmethod)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getClass, arginfo_yuga_route_support_iroute_getclass)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setMethod, arginfo_yuga_route_support_iroute_setmethod)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setNamespace, arginfo_yuga_route_support_iroute_setnamespace)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getNamespace, arginfo_yuga_route_support_iroute_getnamespace)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setDefaultNamespace, arginfo_yuga_route_support_iroute_setdefaultnamespace)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getDefaultNamespace, arginfo_yuga_route_support_iroute_getdefaultnamespace)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getWhere, arginfo_yuga_route_support_iroute_getwhere)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setWhere, arginfo_yuga_route_support_iroute_setwhere)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getParameters, arginfo_yuga_route_support_iroute_getparameters)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setParameters, arginfo_yuga_route_support_iroute_setparameters)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setSettings, arginfo_yuga_route_support_iroute_setsettings)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, toArray, arginfo_yuga_route_support_iroute_toarray)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, getMiddlewares, arginfo_yuga_route_support_iroute_getmiddlewares)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, addMiddleware, arginfo_yuga_route_support_iroute_addmiddleware)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IRoute, setMiddlewares, arginfo_yuga_route_support_iroute_setmiddlewares)
	PHP_FE_END
};
