
extern zend_class_entry *yuga_http_input_inputfile_ce;

ZEPHIR_INIT_CLASS(Yuga_Http_Input_InputFile);

PHP_METHOD(Yuga_Http_Input_InputFile, __construct);
PHP_METHOD(Yuga_Http_Input_InputFile, createFromArray);
PHP_METHOD(Yuga_Http_Input_InputFile, getIndex);
PHP_METHOD(Yuga_Http_Input_InputFile, setIndex);
PHP_METHOD(Yuga_Http_Input_InputFile, getSize);
PHP_METHOD(Yuga_Http_Input_InputFile, setSize);
PHP_METHOD(Yuga_Http_Input_InputFile, getMime);
PHP_METHOD(Yuga_Http_Input_InputFile, getType);
PHP_METHOD(Yuga_Http_Input_InputFile, setType);
PHP_METHOD(Yuga_Http_Input_InputFile, getExtension);
PHP_METHOD(Yuga_Http_Input_InputFile, getName);
PHP_METHOD(Yuga_Http_Input_InputFile, setName);
PHP_METHOD(Yuga_Http_Input_InputFile, setFilename);
PHP_METHOD(Yuga_Http_Input_InputFile, getFilename);
PHP_METHOD(Yuga_Http_Input_InputFile, move);
PHP_METHOD(Yuga_Http_Input_InputFile, getContents);
PHP_METHOD(Yuga_Http_Input_InputFile, hasError);
PHP_METHOD(Yuga_Http_Input_InputFile, getError);
PHP_METHOD(Yuga_Http_Input_InputFile, setError);
PHP_METHOD(Yuga_Http_Input_InputFile, getTmpName);
PHP_METHOD(Yuga_Http_Input_InputFile, setTmpName);
PHP_METHOD(Yuga_Http_Input_InputFile, __toString);
PHP_METHOD(Yuga_Http_Input_InputFile, getValue);
PHP_METHOD(Yuga_Http_Input_InputFile, toArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_createfromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_getindex, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_setindex, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_getsize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_setsize, 0, 0, 1)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_getmime, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_gettype, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_getextension, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_setfilename, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_getfilename, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_move, 0, 0, 2)
	ZEND_ARG_INFO(0, destination)
	ZEND_ARG_INFO(0, newFilename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_getcontents, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_haserror, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_geterror, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_seterror, 0, 0, 1)
	ZEND_ARG_INFO(0, error)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_gettmpname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_settmpname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_yuga_http_input_inputfile___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_getvalue, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputfile_toarray, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_http_input_inputfile_method_entry) {
	PHP_ME(Yuga_Http_Input_InputFile, __construct, arginfo_yuga_http_input_inputfile___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yuga_Http_Input_InputFile, createFromArray, arginfo_yuga_http_input_inputfile_createfromarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getIndex, arginfo_yuga_http_input_inputfile_getindex, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getIndex, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_InputFile, setIndex, arginfo_yuga_http_input_inputfile_setindex, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getSize, arginfo_yuga_http_input_inputfile_getsize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getSize, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_InputFile, setSize, arginfo_yuga_http_input_inputfile_setsize, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getMime, arginfo_yuga_http_input_inputfile_getmime, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getMime, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getType, arginfo_yuga_http_input_inputfile_gettype, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getType, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_InputFile, setType, arginfo_yuga_http_input_inputfile_settype, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getExtension, arginfo_yuga_http_input_inputfile_getextension, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getExtension, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getName, arginfo_yuga_http_input_inputfile_getname, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getName, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_InputFile, setName, arginfo_yuga_http_input_inputfile_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Http_Input_InputFile, setFilename, arginfo_yuga_http_input_inputfile_setfilename, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getFilename, arginfo_yuga_http_input_inputfile_getfilename, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getFilename, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_InputFile, move, arginfo_yuga_http_input_inputfile_move, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getContents, arginfo_yuga_http_input_inputfile_getcontents, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getContents, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, hasError, arginfo_yuga_http_input_inputfile_haserror, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, hasError, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getError, arginfo_yuga_http_input_inputfile_geterror, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getError, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_InputFile, setError, arginfo_yuga_http_input_inputfile_seterror, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getTmpName, arginfo_yuga_http_input_inputfile_gettmpname, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getTmpName, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_InputFile, setTmpName, arginfo_yuga_http_input_inputfile_settmpname, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, __toString, arginfo_yuga_http_input_inputfile___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, getValue, arginfo_yuga_http_input_inputfile_getvalue, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, getValue, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputFile, toArray, arginfo_yuga_http_input_inputfile_toarray, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputFile, toArray, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
