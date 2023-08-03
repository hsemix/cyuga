
extern zend_class_entry *yuga_route_support_igrouproute_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Support_IGroupRoute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_igrouproute_matchdomain, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_igrouproute_addexceptionhandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_igrouproute_setexceptionhandlers, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, handlers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_igrouproute_getexceptionhandlers, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_igrouproute_getdomains, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_igrouproute_setdomains, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, domains, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_igrouproute_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_support_igrouproute_getprefix, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_support_igrouproute_method_entry) {
	PHP_ABSTRACT_ME(Yuga_Route_Support_IGroupRoute, matchDomain, arginfo_yuga_route_support_igrouproute_matchdomain)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IGroupRoute, addExceptionHandler, arginfo_yuga_route_support_igrouproute_addexceptionhandler)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IGroupRoute, setExceptionHandlers, arginfo_yuga_route_support_igrouproute_setexceptionhandlers)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IGroupRoute, getExceptionHandlers, arginfo_yuga_route_support_igrouproute_getexceptionhandlers)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IGroupRoute, getDomains, arginfo_yuga_route_support_igrouproute_getdomains)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IGroupRoute, setDomains, arginfo_yuga_route_support_igrouproute_setdomains)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IGroupRoute, setPrefix, arginfo_yuga_route_support_igrouproute_setprefix)
	PHP_ABSTRACT_ME(Yuga_Route_Support_IGroupRoute, getPrefix, arginfo_yuga_route_support_igrouproute_getprefix)
	PHP_FE_END
};
