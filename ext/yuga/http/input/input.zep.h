
extern zend_class_entry *yuga_http_input_input_ce;

ZEPHIR_INIT_CLASS(Yuga_Http_Input_Input);

PHP_METHOD(Yuga_Http_Input_Input, __construct);
PHP_METHOD(Yuga_Http_Input_Input, parseInputs);
PHP_METHOD(Yuga_Http_Input_Input, parseFiles);
PHP_METHOD(Yuga_Http_Input_Input, generateFiles);
PHP_METHOD(Yuga_Http_Input_Input, getFile);
PHP_METHOD(Yuga_Http_Input_Input, handleGetPost);
PHP_METHOD(Yuga_Http_Input_Input, rearrangeFiles);
PHP_METHOD(Yuga_Http_Input_Input, findPost);
PHP_METHOD(Yuga_Http_Input_Input, findFile);
PHP_METHOD(Yuga_Http_Input_Input, findGet);
PHP_METHOD(Yuga_Http_Input_Input, getObject);
PHP_METHOD(Yuga_Http_Input_Input, get);
PHP_METHOD(Yuga_Http_Input_Input, exists);
PHP_METHOD(Yuga_Http_Input_Input, all);
PHP_METHOD(Yuga_Http_Input_Input, file);
PHP_METHOD(Yuga_Http_Input_Input, hasFile);
zend_object *zephir_init_properties_Yuga_Http_Input_Input(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Yuga\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_parseinputs, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_parsefiles, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_generatefiles, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_OBJ_INFO(0, getItem, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_getfile, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, getItem, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_handlegetpost, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrayList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_rearrangefiles, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, original)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_findpost, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_findfile, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_findget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_getobject, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, methods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, methods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_all, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filter, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, filter, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_file, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_hasfile, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_input_zephir_init_properties_yuga_http_input_input, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_http_input_input_method_entry) {
	PHP_ME(Yuga_Http_Input_Input, __construct, arginfo_yuga_http_input_input___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_Input, parseInputs, arginfo_yuga_http_input_input_parseinputs, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_Input, parseInputs, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_Input, parseFiles, arginfo_yuga_http_input_input_parsefiles, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_Input, parseFiles, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_Input, generateFiles, arginfo_yuga_http_input_input_generatefiles, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Http_Input_Input, getFile, arginfo_yuga_http_input_input_getfile, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Http_Input_Input, handleGetPost, arginfo_yuga_http_input_input_handlegetpost, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Http_Input_Input, rearrangeFiles, arginfo_yuga_http_input_input_rearrangefiles, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Http_Input_Input, findPost, arginfo_yuga_http_input_input_findpost, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Input_Input, findFile, arginfo_yuga_http_input_input_findfile, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Input_Input, findGet, arginfo_yuga_http_input_input_findget, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Input_Input, getObject, arginfo_yuga_http_input_input_getobject, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Input_Input, get, arginfo_yuga_http_input_input_get, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Input_Input, exists, arginfo_yuga_http_input_input_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Input_Input, all, arginfo_yuga_http_input_input_all, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Input_Input, file, arginfo_yuga_http_input_input_file, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Http_Input_Input, hasFile, arginfo_yuga_http_input_input_hasfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
