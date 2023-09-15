
extern zend_class_entry *yuga_carbon_carbon_ce;

ZEPHIR_INIT_CLASS(Yuga_Carbon_Carbon);

PHP_METHOD(Yuga_Carbon_Carbon, __construct);
PHP_METHOD(Yuga_Carbon_Carbon, __toString);
PHP_METHOD(Yuga_Carbon_Carbon, jsonSerialize);
PHP_METHOD(Yuga_Carbon_Carbon, toDateString);
PHP_METHOD(Yuga_Carbon_Carbon, toFormattedDateString);
PHP_METHOD(Yuga_Carbon_Carbon, toTimeString);
PHP_METHOD(Yuga_Carbon_Carbon, toDateTimeString);
PHP_METHOD(Yuga_Carbon_Carbon, toDayDateTimeString);
PHP_METHOD(Yuga_Carbon_Carbon, safeCreateDateTimeZone);
PHP_METHOD(Yuga_Carbon_Carbon, now);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_carbon_carbon___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_INFO(0, tz)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_yuga_carbon_carbon___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_carbon_carbon___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_carbon_carbon_jsonserialize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_carbon_carbon_todatestring, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_carbon_carbon_toformatteddatestring, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_carbon_carbon_totimestring, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_carbon_carbon_todatetimestring, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_carbon_carbon_todaydatetimestring, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_carbon_carbon_safecreatedatetimezone, 0, 0, 1)
	ZEND_ARG_INFO(0, objectVal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_carbon_carbon_now, 0, 0, 0)
	ZEND_ARG_INFO(0, tz)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_carbon_carbon_method_entry) {
	PHP_ME(Yuga_Carbon_Carbon, __construct, arginfo_yuga_carbon_carbon___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Carbon_Carbon, __toString, arginfo_yuga_carbon_carbon___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Carbon_Carbon, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Carbon_Carbon, jsonSerialize, arginfo_yuga_carbon_carbon_jsonserialize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Carbon_Carbon, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Carbon_Carbon, toDateString, arginfo_yuga_carbon_carbon_todatestring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Carbon_Carbon, toDateString, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Carbon_Carbon, toFormattedDateString, arginfo_yuga_carbon_carbon_toformatteddatestring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Carbon_Carbon, toFormattedDateString, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Carbon_Carbon, toTimeString, arginfo_yuga_carbon_carbon_totimestring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Carbon_Carbon, toTimeString, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Carbon_Carbon, toDateTimeString, arginfo_yuga_carbon_carbon_todatetimestring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Carbon_Carbon, toDateTimeString, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Carbon_Carbon, toDayDateTimeString, arginfo_yuga_carbon_carbon_todaydatetimestring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Carbon_Carbon, toDayDateTimeString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Carbon_Carbon, safeCreateDateTimeZone, arginfo_yuga_carbon_carbon_safecreatedatetimezone, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Carbon_Carbon, now, arginfo_yuga_carbon_carbon_now, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
