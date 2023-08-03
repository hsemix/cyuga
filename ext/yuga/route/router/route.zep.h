
extern zend_class_entry *yuga_route_router_route_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Router_Route);

PHP_METHOD(Yuga_Route_Router_Route, loadClass);
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
