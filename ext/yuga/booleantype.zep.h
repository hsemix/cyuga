
extern zend_class_entry *yuga_booleantype_ce;

ZEPHIR_INIT_CLASS(Yuga_BooleanType);

PHP_METHOD(Yuga_BooleanType, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_booleantype_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_booleantype_method_entry) {
	PHP_ME(Yuga_BooleanType, parse, arginfo_yuga_booleantype_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
