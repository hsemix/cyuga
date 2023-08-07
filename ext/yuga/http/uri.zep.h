
extern zend_class_entry *yuga_http_uri_ce;

ZEPHIR_INIT_CLASS(Yuga_Http_Uri);

PHP_METHOD(Yuga_Http_Uri, __construct);
PHP_METHOD(Yuga_Http_Uri, isSecure);
PHP_METHOD(Yuga_Http_Uri, isRelative);
PHP_METHOD(Yuga_Http_Uri, getScheme);
PHP_METHOD(Yuga_Http_Uri, setScheme);
PHP_METHOD(Yuga_Http_Uri, getHost);
PHP_METHOD(Yuga_Http_Uri, setHost);
PHP_METHOD(Yuga_Http_Uri, getPort);
PHP_METHOD(Yuga_Http_Uri, setPort);
PHP_METHOD(Yuga_Http_Uri, getUsername);
PHP_METHOD(Yuga_Http_Uri, setUsername);
PHP_METHOD(Yuga_Http_Uri, getPassword);
PHP_METHOD(Yuga_Http_Uri, setPassword);
PHP_METHOD(Yuga_Http_Uri, getPath);
PHP_METHOD(Yuga_Http_Uri, setPath);
PHP_METHOD(Yuga_Http_Uri, getParams);
PHP_METHOD(Yuga_Http_Uri, mergeParams);
PHP_METHOD(Yuga_Http_Uri, setParams);
PHP_METHOD(Yuga_Http_Uri, getQueryString);
PHP_METHOD(Yuga_Http_Uri, getFragment);
PHP_METHOD(Yuga_Http_Uri, setFragment);
PHP_METHOD(Yuga_Http_Uri, getOriginalUrl);
PHP_METHOD(Yuga_Http_Uri, indexOf);
PHP_METHOD(Yuga_Http_Uri, contains);
PHP_METHOD(Yuga_Http_Uri, hasParam);
PHP_METHOD(Yuga_Http_Uri, removeParam);
PHP_METHOD(Yuga_Http_Uri, getParam);
PHP_METHOD(Yuga_Http_Uri, parseUrl);
PHP_METHOD(Yuga_Http_Uri, arrayToParams);
PHP_METHOD(Yuga_Http_Uri, getRelativeUrl);
PHP_METHOD(Yuga_Http_Uri, getAbsoluteUrl);
PHP_METHOD(Yuga_Http_Uri, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_issecure, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_isrelative, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getscheme, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_setscheme, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_gethost, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_sethost, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getport, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_setport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getusername, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_setusername, 0, 0, 1)
	ZEND_ARG_INFO(0, username)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getpassword, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_setpassword, 0, 0, 1)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getpath, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getparams, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_mergeparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_setparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getquerystring, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getfragment, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_setfragment, 0, 0, 1)
	ZEND_ARG_INFO(0, fragment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getoriginalurl, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_indexof, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_hasparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_removeparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_parseurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, component)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_arraytoparams, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, getParams, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, getParams, 1)
#endif
	ZEND_ARG_INFO(0, includeEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getrelativeurl, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri_getabsoluteurl, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_yuga_http_uri___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_uri___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_http_uri_method_entry) {
	PHP_ME(Yuga_Http_Uri, __construct, arginfo_yuga_http_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, isSecure, arginfo_yuga_http_uri_issecure, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, isSecure, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, isRelative, arginfo_yuga_http_uri_isrelative, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, isRelative, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getScheme, arginfo_yuga_http_uri_getscheme, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getScheme, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Uri, setScheme, arginfo_yuga_http_uri_setscheme, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getHost, arginfo_yuga_http_uri_gethost, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getHost, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Uri, setHost, arginfo_yuga_http_uri_sethost, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getPort, arginfo_yuga_http_uri_getport, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getPort, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Uri, setPort, arginfo_yuga_http_uri_setport, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getUsername, arginfo_yuga_http_uri_getusername, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getUsername, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Uri, setUsername, arginfo_yuga_http_uri_setusername, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getPassword, arginfo_yuga_http_uri_getpassword, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getPassword, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Uri, setPassword, arginfo_yuga_http_uri_setpassword, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getPath, arginfo_yuga_http_uri_getpath, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getPath, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Uri, setPath, arginfo_yuga_http_uri_setpath, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getParams, arginfo_yuga_http_uri_getparams, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getParams, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Uri, mergeParams, arginfo_yuga_http_uri_mergeparams, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Uri, setParams, arginfo_yuga_http_uri_setparams, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getQueryString, arginfo_yuga_http_uri_getquerystring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getQueryString, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getFragment, arginfo_yuga_http_uri_getfragment, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getFragment, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Uri, setFragment, arginfo_yuga_http_uri_setfragment, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getOriginalUrl, arginfo_yuga_http_uri_getoriginalurl, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getOriginalUrl, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Uri, indexOf, arginfo_yuga_http_uri_indexof, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Uri, contains, arginfo_yuga_http_uri_contains, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Uri, hasParam, arginfo_yuga_http_uri_hasparam, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Uri, removeParam, arginfo_yuga_http_uri_removeparam, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Uri, getParam, arginfo_yuga_http_uri_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Uri, parseUrl, arginfo_yuga_http_uri_parseurl, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Uri, arrayToParams, arginfo_yuga_http_uri_arraytoparams, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getRelativeUrl, arginfo_yuga_http_uri_getrelativeurl, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getRelativeUrl, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, getAbsoluteUrl, arginfo_yuga_http_uri_getabsoluteurl, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, getAbsoluteUrl, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Uri, __toString, arginfo_yuga_http_uri___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Uri, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
