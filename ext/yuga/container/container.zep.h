
extern zend_class_entry *yuga_container_container_ce;

ZEPHIR_INIT_CLASS(Yuga_Container_Container);

PHP_METHOD(Yuga_Container_Container, offsetGet);
PHP_METHOD(Yuga_Container_Container, offsetSet);
PHP_METHOD(Yuga_Container_Container, offsetExists);
PHP_METHOD(Yuga_Container_Container, offsetUnset);
zend_object *zephir_init_properties_Yuga_Container_Container(zend_class_entry *class_type);
void zephir_init_static_properties_Yuga_Container_Container();

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_zephir_init_properties_yuga_container_container, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_zephir_init_static_properties_yuga_container_container, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_container_container_method_entry) {
	PHP_ME(Yuga_Container_Container, offsetGet, arginfo_yuga_container_container_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, offsetSet, arginfo_yuga_container_container_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, offsetExists, arginfo_yuga_container_container_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, offsetUnset, arginfo_yuga_container_container_offsetunset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
