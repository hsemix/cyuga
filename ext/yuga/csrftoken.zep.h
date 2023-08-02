
extern zend_class_entry *yuga_csrftoken_ce;

ZEPHIR_INIT_CLASS(Yuga_CsrfToken);

PHP_METHOD(Yuga_CsrfToken, generateToken);
PHP_METHOD(Yuga_CsrfToken, validate);
PHP_METHOD(Yuga_CsrfToken, setToken);
PHP_METHOD(Yuga_CsrfToken, getToken);
PHP_METHOD(Yuga_CsrfToken, hasToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_csrftoken_generatetoken, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_csrftoken_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_csrftoken_settoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_csrftoken_gettoken, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_csrftoken_hastoken, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_csrftoken_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_CsrfToken, generateToken, arginfo_yuga_csrftoken_generatetoken, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Yuga_CsrfToken, generateToken, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(Yuga_CsrfToken, validate, arginfo_yuga_csrftoken_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_CsrfToken, setToken, arginfo_yuga_csrftoken_settoken, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_CsrfToken, getToken, arginfo_yuga_csrftoken_gettoken, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_CsrfToken, getToken, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_CsrfToken, hasToken, arginfo_yuga_csrftoken_hastoken, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_CsrfToken, hasToken, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
