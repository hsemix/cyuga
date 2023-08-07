
extern zend_class_entry *yuga_http_request_ce;

ZEPHIR_INIT_CLASS(Yuga_Http_Request);

PHP_METHOD(Yuga_Http_Request, __construct);
PHP_METHOD(Yuga_Http_Request, parseHeaders);
PHP_METHOD(Yuga_Http_Request, getHeaders);
PHP_METHOD(Yuga_Http_Request, getHeader);
PHP_METHOD(Yuga_Http_Request, getBearerToken);
PHP_METHOD(Yuga_Http_Request, getInput);
PHP_METHOD(Yuga_Http_Request, isFormatAccepted);
PHP_METHOD(Yuga_Http_Request, getAcceptFormats);
PHP_METHOD(Yuga_Http_Request, setUri);
PHP_METHOD(Yuga_Http_Request, setHost);
PHP_METHOD(Yuga_Http_Request, setMethod);
PHP_METHOD(Yuga_Http_Request, getRewriteRoute);
PHP_METHOD(Yuga_Http_Request, setRewriteUrl);
PHP_METHOD(Yuga_Http_Request, getLoadedRoute);
PHP_METHOD(Yuga_Http_Request, setLoadedRoute);
PHP_METHOD(Yuga_Http_Request, __isset);
PHP_METHOD(Yuga_Http_Request, __set);
PHP_METHOD(Yuga_Http_Request, __get);
PHP_METHOD(Yuga_Http_Request, isAjax);
PHP_METHOD(Yuga_Http_Request, model);
PHP_METHOD(Yuga_Http_Request, setModel);
PHP_METHOD(Yuga_Http_Request, getMethod);
PHP_METHOD(Yuga_Http_Request, create);
PHP_METHOD(Yuga_Http_Request, isSecure);
PHP_METHOD(Yuga_Http_Request, getPort);
PHP_METHOD(Yuga_Http_Request, getUri);
PHP_METHOD(Yuga_Http_Request, formatUrl);
PHP_METHOD(Yuga_Http_Request, getHost);
PHP_METHOD(Yuga_Http_Request, getServer);
PHP_METHOD(Yuga_Http_Request, getUser);
PHP_METHOD(Yuga_Http_Request, getPassword);
PHP_METHOD(Yuga_Http_Request, getIp);
PHP_METHOD(Yuga_Http_Request, getRemoteAddr);
PHP_METHOD(Yuga_Http_Request, getReferer);
PHP_METHOD(Yuga_Http_Request, getUserAgent);
PHP_METHOD(Yuga_Http_Request, get);
PHP_METHOD(Yuga_Http_Request, exists);
PHP_METHOD(Yuga_Http_Request, files);
PHP_METHOD(Yuga_Http_Request, hasFile);
PHP_METHOD(Yuga_Http_Request, all);
PHP_METHOD(Yuga_Http_Request, only);
PHP_METHOD(Yuga_Http_Request, except);
PHP_METHOD(Yuga_Http_Request, setRewriteRoute);
PHP_METHOD(Yuga_Http_Request, setRewriteCallback);
PHP_METHOD(Yuga_Http_Request, getRewriteUrl);
PHP_METHOD(Yuga_Http_Request, getRouteParams);
zend_object *zephir_init_properties_Yuga_Http_Request(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_parseheaders, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getheaders, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getheader, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, defaultValue, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getbearertoken, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getinput, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_isformataccepted, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getacceptformats, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_seturi, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_sethost, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, host, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_setmethod, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getrewriteroute, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_setrewriteurl, 0, 0, 1)
	ZEND_ARG_INFO(0, rewriteUrl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getloadedroute, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_setloadedroute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route, Yuga\\Route\\Support\\ILoadableRoute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request___set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_isajax, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_model, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_setmodel, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getmethod, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_create, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_issecure, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getport, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_geturi, 0, 0, 0)
	ZEND_ARG_INFO(0, trim)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_formaturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_gethost, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getserver, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getuser, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getpassword, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getip, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getremoteaddr, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getreferer, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getuseragent, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_files, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_hasfile, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_all, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filter, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, filter, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_only, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, onlyFields, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, onlyFields, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_except, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, exceptFields, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, exceptFields, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_setrewriteroute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route, Yuga\\Route\\Support\\ILoadableRoute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_setrewritecallback, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getrewriteurl, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_getrouteparams, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_request_zephir_init_properties_yuga_http_request, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_http_request_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, __construct, arginfo_yuga_http_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Yuga_Http_Request, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, parseHeaders, arginfo_yuga_http_request_parseheaders, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Yuga_Http_Request, parseHeaders, NULL, ZEND_ACC_PROTECTED)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getHeaders, arginfo_yuga_http_request_getheaders, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getHeaders, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Request, getHeader, arginfo_yuga_http_request_getheader, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getBearerToken, arginfo_yuga_http_request_getbearertoken, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getBearerToken, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getInput, arginfo_yuga_http_request_getinput, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getInput, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Request, isFormatAccepted, arginfo_yuga_http_request_isformataccepted, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getAcceptFormats, arginfo_yuga_http_request_getacceptformats, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getAcceptFormats, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Request, setUri, arginfo_yuga_http_request_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, setHost, arginfo_yuga_http_request_sethost, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, setMethod, arginfo_yuga_http_request_setmethod, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getRewriteRoute, arginfo_yuga_http_request_getrewriteroute, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getRewriteRoute, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Request, setRewriteUrl, arginfo_yuga_http_request_setrewriteurl, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getLoadedRoute, arginfo_yuga_http_request_getloadedroute, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getLoadedRoute, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Request, setLoadedRoute, arginfo_yuga_http_request_setloadedroute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, __isset, arginfo_yuga_http_request___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, __set, arginfo_yuga_http_request___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, __get, arginfo_yuga_http_request___get, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, isAjax, arginfo_yuga_http_request_isajax, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, isAjax, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, model, arginfo_yuga_http_request_model, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, model, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Request, setModel, arginfo_yuga_http_request_setmodel, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getMethod, arginfo_yuga_http_request_getmethod, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, create, arginfo_yuga_http_request_create, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, create, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, isSecure, arginfo_yuga_http_request_issecure, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, isSecure, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getPort, arginfo_yuga_http_request_getport, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getPort, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Request, getUri, arginfo_yuga_http_request_geturi, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, formatUrl, arginfo_yuga_http_request_formaturl, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getHost, arginfo_yuga_http_request_gethost, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getHost, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getServer, arginfo_yuga_http_request_getserver, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getServer, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getUser, arginfo_yuga_http_request_getuser, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getUser, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getPassword, arginfo_yuga_http_request_getpassword, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getPassword, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getIp, arginfo_yuga_http_request_getip, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getIp, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getRemoteAddr, arginfo_yuga_http_request_getremoteaddr, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getRemoteAddr, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getReferer, arginfo_yuga_http_request_getreferer, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getReferer, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getUserAgent, arginfo_yuga_http_request_getuseragent, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getUserAgent, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Request, get, arginfo_yuga_http_request_get, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, exists, arginfo_yuga_http_request_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, files, arginfo_yuga_http_request_files, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, hasFile, arginfo_yuga_http_request_hasfile, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, all, arginfo_yuga_http_request_all, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, only, arginfo_yuga_http_request_only, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, except, arginfo_yuga_http_request_except, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, setRewriteRoute, arginfo_yuga_http_request_setrewriteroute, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Request, setRewriteCallback, arginfo_yuga_http_request_setrewritecallback, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Request, getRewriteUrl, arginfo_yuga_http_request_getrewriteurl, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Request, getRewriteUrl, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Request, getRouteParams, arginfo_yuga_http_request_getrouteparams, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
