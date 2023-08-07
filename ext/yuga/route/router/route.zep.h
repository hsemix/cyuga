
extern zend_class_entry *yuga_route_router_route_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Router_Route);

PHP_METHOD(Yuga_Route_Router_Route, loadClass);
PHP_METHOD(Yuga_Route_Router_Route, instantiated);
PHP_METHOD(Yuga_Route_Router_Route, isSingleton);
PHP_METHOD(Yuga_Route_Router_Route, runMiddleware);
PHP_METHOD(Yuga_Route_Router_Route, renderRoute);
PHP_METHOD(Yuga_Route_Router_Route, processBindings);
PHP_METHOD(Yuga_Route_Router_Route, methodInjection);
PHP_METHOD(Yuga_Route_Router_Route, parseParameters);
PHP_METHOD(Yuga_Route_Router_Route, getIdentifier);
PHP_METHOD(Yuga_Route_Router_Route, setRequestMethods);
PHP_METHOD(Yuga_Route_Router_Route, getRequestMethods);
PHP_METHOD(Yuga_Route_Router_Route, getParent);
PHP_METHOD(Yuga_Route_Router_Route, getGroup);
PHP_METHOD(Yuga_Route_Router_Route, setGroup);
PHP_METHOD(Yuga_Route_Router_Route, setParent);
PHP_METHOD(Yuga_Route_Router_Route, setCallback);
PHP_METHOD(Yuga_Route_Router_Route, getCallback);
PHP_METHOD(Yuga_Route_Router_Route, getMethod);
PHP_METHOD(Yuga_Route_Router_Route, getClass);
PHP_METHOD(Yuga_Route_Router_Route, setMethod);
PHP_METHOD(Yuga_Route_Router_Route, setClass);
PHP_METHOD(Yuga_Route_Router_Route, setNamespace);
PHP_METHOD(Yuga_Route_Router_Route, setDefaultNamespace);
PHP_METHOD(Yuga_Route_Router_Route, getDefaultNamespace);
PHP_METHOD(Yuga_Route_Router_Route, getNamespace);
PHP_METHOD(Yuga_Route_Router_Route, toArray);
PHP_METHOD(Yuga_Route_Router_Route, setSettings);
PHP_METHOD(Yuga_Route_Router_Route, getWhere);
PHP_METHOD(Yuga_Route_Router_Route, setWhere);
PHP_METHOD(Yuga_Route_Router_Route, where);
PHP_METHOD(Yuga_Route_Router_Route, getParameters);
PHP_METHOD(Yuga_Route_Router_Route, setParameters);
PHP_METHOD(Yuga_Route_Router_Route, setMiddleware);
PHP_METHOD(Yuga_Route_Router_Route, addMiddleware);
PHP_METHOD(Yuga_Route_Router_Route, setMiddlewares);
PHP_METHOD(Yuga_Route_Router_Route, getMiddlewares);
PHP_METHOD(Yuga_Route_Router_Route, setDefaultParameterRegex);
PHP_METHOD(Yuga_Route_Router_Route, getDefaultParameterRegex);
void zephir_init_static_properties_Yuga_Route_Router_Route();
zend_object *zephir_init_properties_Yuga_Route_Router_Route(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_loadclass, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_instantiated, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_issingleton, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, app, Yuga\\Application\\Application, 0)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_runmiddleware, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
	ZEND_ARG_INFO(0, middleware)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_renderroute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_processbindings, 0, 0, 0)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_methodinjection, 0, 0, 3)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_parseparameters, 0, 0, 2)
	ZEND_ARG_INFO(0, route)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, parameterRegex)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getidentifier, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setrequestmethods, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, methods, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getrequestmethods, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getparent, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getgroup, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setgroup, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, group, Yuga\\Route\\Support\\IGroupRoute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setparent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, parent, Yuga\\Route\\Support\\IRoute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setcallback, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getcallback, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getmethod, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getclass, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setclass, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getdefaultnamespace, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getnamespace, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_toarray, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setsettings, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getwhere, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setwhere, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_where, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getparameters, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setparameters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setmiddleware, 0, 0, 1)
	ZEND_ARG_INFO(0, middleware)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_addmiddleware, 0, 0, 1)
	ZEND_ARG_INFO(0, middleware)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setmiddlewares, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, middlewares, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getmiddlewares, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_setdefaultparameterregex, 0, 0, 1)
	ZEND_ARG_INFO(0, regex)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_getdefaultparameterregex, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_zephir_init_static_properties_yuga_route_router_route, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_router_route_zephir_init_properties_yuga_route_router_route, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_router_route_method_entry) {
	PHP_ME(Yuga_Route_Router_Route, loadClass, arginfo_yuga_route_router_route_loadclass, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Route_Router_Route, instantiated, arginfo_yuga_route_router_route_instantiated, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Route_Router_Route, isSingleton, arginfo_yuga_route_router_route_issingleton, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Route_Router_Route, runMiddleware, arginfo_yuga_route_router_route_runmiddleware, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Route_Router_Route, renderRoute, arginfo_yuga_route_router_route_renderroute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_Route, processBindings, arginfo_yuga_route_router_route_processbindings, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Route_Router_Route, methodInjection, arginfo_yuga_route_router_route_methodinjection, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Route_Router_Route, parseParameters, arginfo_yuga_route_router_route_parseparameters, ZEND_ACC_PROTECTED)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getIdentifier, arginfo_yuga_route_router_route_getidentifier, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getIdentifier, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_Route, setRequestMethods, arginfo_yuga_route_router_route_setrequestmethods, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getRequestMethods, arginfo_yuga_route_router_route_getrequestmethods, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getRequestMethods, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getParent, arginfo_yuga_route_router_route_getparent, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getParent, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getGroup, arginfo_yuga_route_router_route_getgroup, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getGroup, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_Route, setGroup, arginfo_yuga_route_router_route_setgroup, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_Route, setParent, arginfo_yuga_route_router_route_setparent, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_Route, setCallback, arginfo_yuga_route_router_route_setcallback, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getCallback, arginfo_yuga_route_router_route_getcallback, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getCallback, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getMethod, arginfo_yuga_route_router_route_getmethod, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getMethod, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getClass, arginfo_yuga_route_router_route_getclass, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getClass, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_Route, setMethod, arginfo_yuga_route_router_route_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_Route, setClass, arginfo_yuga_route_router_route_setclass, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_Route, setNamespace, arginfo_yuga_route_router_route_setnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_Route, setDefaultNamespace, arginfo_yuga_route_router_route_setdefaultnamespace, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getDefaultNamespace, arginfo_yuga_route_router_route_getdefaultnamespace, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getDefaultNamespace, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getNamespace, arginfo_yuga_route_router_route_getnamespace, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getNamespace, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, toArray, arginfo_yuga_route_router_route_toarray, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, toArray, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_Route, setSettings, arginfo_yuga_route_router_route_setsettings, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getWhere, arginfo_yuga_route_router_route_getwhere, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getWhere, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_Route, setWhere, arginfo_yuga_route_router_route_setwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_Route, where, arginfo_yuga_route_router_route_where, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getParameters, arginfo_yuga_route_router_route_getparameters, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getParameters, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_Route, setParameters, arginfo_yuga_route_router_route_setparameters, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_Route, setMiddleware, arginfo_yuga_route_router_route_setmiddleware, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_Route, addMiddleware, arginfo_yuga_route_router_route_addmiddleware, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Route_Router_Route, setMiddlewares, arginfo_yuga_route_router_route_setmiddlewares, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getMiddlewares, arginfo_yuga_route_router_route_getmiddlewares, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getMiddlewares, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Route_Router_Route, setDefaultParameterRegex, arginfo_yuga_route_router_route_setdefaultparameterregex, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Router_Route, getDefaultParameterRegex, arginfo_yuga_route_router_route_getdefaultparameterregex, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Route_Router_Route, getDefaultParameterRegex, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
