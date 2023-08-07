
extern zend_class_entry *yuga_route_route_ce;

ZEPHIR_INIT_CLASS(Yuga_Route_Route);

PHP_METHOD(Yuga_Route_Route, start);
PHP_METHOD(Yuga_Route_Route, get);
PHP_METHOD(Yuga_Route_Route, setDefaultNamespace);
PHP_METHOD(Yuga_Route_Route, addDefaultNamespace);
PHP_METHOD(Yuga_Route_Route, post);
PHP_METHOD(Yuga_Route_Route, put);
PHP_METHOD(Yuga_Route_Route, patch);
PHP_METHOD(Yuga_Route_Route, options);
PHP_METHOD(Yuga_Route_Route, delete);
PHP_METHOD(Yuga_Route_Route, group);
PHP_METHOD(Yuga_Route_Route, basic);
PHP_METHOD(Yuga_Route_Route, form);
PHP_METHOD(Yuga_Route_Route, match);
PHP_METHOD(Yuga_Route_Route, all);
PHP_METHOD(Yuga_Route_Route, controller);
PHP_METHOD(Yuga_Route_Route, error);
PHP_METHOD(Yuga_Route_Route, getDefaultNamespace);
PHP_METHOD(Yuga_Route_Route, resources);
PHP_METHOD(Yuga_Route_Route, router);
PHP_METHOD(Yuga_Route_Route, getUrl);
PHP_METHOD(Yuga_Route_Route, request);
PHP_METHOD(Yuga_Route_Route, response);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_start, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_get, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultNamespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_adddefaultnamespace, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route, Yuga\\Route\\Support\\IRoute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_post, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_put, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_patch, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_options, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_group, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, settings, 0)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_basic, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_form, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_match, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, requestMethods, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_all, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_controller, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, controller)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_error, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_getdefaultnamespace, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_resources, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, controller)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, settings, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_router, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_geturl, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, getParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_request, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_route_route_response, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_route_route_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Route, start, arginfo_yuga_route_route_start, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_Route_Route, start, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(Yuga_Route_Route, get, arginfo_yuga_route_route_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, setDefaultNamespace, arginfo_yuga_route_route_setdefaultnamespace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, addDefaultNamespace, arginfo_yuga_route_route_adddefaultnamespace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, post, arginfo_yuga_route_route_post, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, put, arginfo_yuga_route_route_put, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, patch, arginfo_yuga_route_route_patch, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, options, arginfo_yuga_route_route_options, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, delete, arginfo_yuga_route_route_delete, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, group, arginfo_yuga_route_route_group, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, basic, arginfo_yuga_route_route_basic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, form, arginfo_yuga_route_route_form, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, match, arginfo_yuga_route_route_match, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, all, arginfo_yuga_route_route_all, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, controller, arginfo_yuga_route_route_controller, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Route_Route, error, arginfo_yuga_route_route_error, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Route, getDefaultNamespace, arginfo_yuga_route_route_getdefaultnamespace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_Route_Route, getDefaultNamespace, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(Yuga_Route_Route, resources, arginfo_yuga_route_route_resources, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Route, router, arginfo_yuga_route_route_router, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_Route_Route, router, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(Yuga_Route_Route, getUrl, arginfo_yuga_route_route_geturl, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Route, request, arginfo_yuga_route_route_request, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_Route_Route, request, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Route_Route, response, arginfo_yuga_route_route_response, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_Route_Route, response, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_FE_END
};
