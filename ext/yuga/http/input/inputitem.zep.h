
extern zend_class_entry *yuga_http_input_inputitem_ce;

ZEPHIR_INIT_CLASS(Yuga_Http_Input_InputItem);

PHP_METHOD(Yuga_Http_Input_InputItem, __construct);
PHP_METHOD(Yuga_Http_Input_InputItem, getIndex);
PHP_METHOD(Yuga_Http_Input_InputItem, setIndex);
PHP_METHOD(Yuga_Http_Input_InputItem, getName);
PHP_METHOD(Yuga_Http_Input_InputItem, setName);
PHP_METHOD(Yuga_Http_Input_InputItem, getValue);
PHP_METHOD(Yuga_Http_Input_InputItem, setValue);
PHP_METHOD(Yuga_Http_Input_InputItem, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputitem___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputitem_getindex, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputitem_setindex, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputitem_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputitem_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputitem_getvalue, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputitem_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_yuga_http_input_inputitem___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_http_input_inputitem___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_http_input_inputitem_method_entry) {
	PHP_ME(Yuga_Http_Input_InputItem, __construct, arginfo_yuga_http_input_inputitem___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputItem, getIndex, arginfo_yuga_http_input_inputitem_getindex, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputItem, getIndex, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_InputItem, setIndex, arginfo_yuga_http_input_inputitem_setindex, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputItem, getName, arginfo_yuga_http_input_inputitem_getname, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputItem, getName, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_InputItem, setName, arginfo_yuga_http_input_inputitem_setname, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputItem, getValue, arginfo_yuga_http_input_inputitem_getvalue, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputItem, getValue, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Http_Input_InputItem, setValue, arginfo_yuga_http_input_inputitem_setvalue, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Http_Input_InputItem, __toString, arginfo_yuga_http_input_inputitem___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Http_Input_InputItem, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
