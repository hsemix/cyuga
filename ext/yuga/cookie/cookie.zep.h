
extern zend_class_entry *yuga_cookie_cookie_ce;

ZEPHIR_INIT_CLASS(Yuga_Cookie_Cookie);

PHP_METHOD(Yuga_Cookie_Cookie, exists);
PHP_METHOD(Yuga_Cookie_Cookie, get);
PHP_METHOD(Yuga_Cookie_Cookie, put);
PHP_METHOD(Yuga_Cookie_Cookie, create);
PHP_METHOD(Yuga_Cookie_Cookie, delete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_cookie_cookie_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_cookie_cookie_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_cookie_cookie_put, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expiry)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_cookie_cookie_create, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expiry)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_cookie_cookie_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_cookie_cookie_method_entry) {
	PHP_ME(Yuga_Cookie_Cookie, exists, arginfo_yuga_cookie_cookie_exists, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Cookie_Cookie, get, arginfo_yuga_cookie_cookie_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Cookie_Cookie, put, arginfo_yuga_cookie_cookie_put, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Cookie_Cookie, create, arginfo_yuga_cookie_cookie_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Cookie_Cookie, delete, arginfo_yuga_cookie_cookie_delete, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
