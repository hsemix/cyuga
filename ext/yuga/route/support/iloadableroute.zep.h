
extern zend_class_entry *yuga_route_support_iloadableroute_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Support_ILoadableRoute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iloadableroute_findurl, 0, 0, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iloadableroute_loadmiddleware, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iloadableroute_geturl, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iloadableroute_seturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iloadableroute_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iloadableroute_hasname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iloadableroute_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iloadableroute_getmatch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_iloadableroute_setmatch, 0, 0, 1)
	ZEND_ARG_INFO(0, regex)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_support_iloadableroute_method_entry) {
	PHP_ABSTRACT_ME(Yuga_Route_Support_ILoadableRoute, findUrl, arginfo_yuga_route_support_iloadableroute_findurl)
	PHP_ABSTRACT_ME(Yuga_Route_Support_ILoadableRoute, loadMiddleware, arginfo_yuga_route_support_iloadableroute_loadmiddleware)
	PHP_ABSTRACT_ME(Yuga_Route_Support_ILoadableRoute, getUrl, arginfo_yuga_route_support_iloadableroute_geturl)
	PHP_ABSTRACT_ME(Yuga_Route_Support_ILoadableRoute, setUrl, arginfo_yuga_route_support_iloadableroute_seturl)
	PHP_ABSTRACT_ME(Yuga_Route_Support_ILoadableRoute, getName, arginfo_yuga_route_support_iloadableroute_getname)
	PHP_ABSTRACT_ME(Yuga_Route_Support_ILoadableRoute, hasName, arginfo_yuga_route_support_iloadableroute_hasname)
	PHP_ABSTRACT_ME(Yuga_Route_Support_ILoadableRoute, setName, arginfo_yuga_route_support_iloadableroute_setname)
	PHP_ABSTRACT_ME(Yuga_Route_Support_ILoadableRoute, getMatch, arginfo_yuga_route_support_iloadableroute_getmatch)
	PHP_ABSTRACT_ME(Yuga_Route_Support_ILoadableRoute, setMatch, arginfo_yuga_route_support_iloadableroute_setmatch)
	PHP_FE_END
};
