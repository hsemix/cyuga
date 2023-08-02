
extern zend_class_entry *yuga_guid_ce;

ZEPHIR_INIT_CLASS(Yuga_Guid);

PHP_METHOD(Yuga_Guid, create);
PHP_METHOD(Yuga_Guid, encrypt);
PHP_METHOD(Yuga_Guid, decrypt);
PHP_METHOD(Yuga_Guid, createRandomPassword);
PHP_METHOD(Yuga_Guid, generateSalt);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_guid_create, 0, 0, 0)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_guid_encrypt, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_guid_decrypt, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_guid_createrandompassword, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_guid_generatesalt, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_guid_method_entry) {
	PHP_ME(Yuga_Guid, create, arginfo_yuga_guid_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Guid, encrypt, arginfo_yuga_guid_encrypt, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Guid, decrypt, arginfo_yuga_guid_decrypt, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Guid, createRandomPassword, arginfo_yuga_guid_createrandompassword, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Guid, generateSalt, arginfo_yuga_guid_generatesalt, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_Guid, generateSalt, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_FE_END
};
