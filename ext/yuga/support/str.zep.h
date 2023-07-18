
extern zend_class_entry *yuga_support_str_ce;

ZEPHIR_INIT_CLASS(Yuga_Support_Str);

PHP_METHOD(Yuga_Support_Str, contains);
PHP_METHOD(Yuga_Support_Str, startsWith);
PHP_METHOD(Yuga_Support_Str, endsWith);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_str_contains, 0, 0, 2)
	ZEND_ARG_INFO(0, haystack)
	ZEND_ARG_INFO(0, needles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_support_str_startswith, 0, 0, 2)
	ZEND_ARG_INFO(0, haystack)
	ZEND_ARG_INFO(0, needles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_yuga_support_str_endswith, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, haystack, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, needle, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_support_str_method_entry) {
	PHP_ME(Yuga_Support_Str, contains, arginfo_yuga_support_str_contains, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Support_Str, startsWith, arginfo_yuga_support_str_startswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Support_Str, endsWith, arginfo_yuga_support_str_endswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
