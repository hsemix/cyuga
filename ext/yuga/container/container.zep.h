
extern zend_class_entry *yuga_container_container_ce;

ZEPHIR_INIT_CLASS(Yuga_Container_Container);

PHP_METHOD(Yuga_Container_Container, offsetGet);
PHP_METHOD(Yuga_Container_Container, offsetSet);
PHP_METHOD(Yuga_Container_Container, offsetExists);
PHP_METHOD(Yuga_Container_Container, offsetUnset);
PHP_METHOD(Yuga_Container_Container, bind);
PHP_METHOD(Yuga_Container_Container, bound);
PHP_METHOD(Yuga_Container_Container, resolved);
PHP_METHOD(Yuga_Container_Container, has);
PHP_METHOD(Yuga_Container_Container, singleton);
PHP_METHOD(Yuga_Container_Container, getBinding);
PHP_METHOD(Yuga_Container_Container, getBindings);
PHP_METHOD(Yuga_Container_Container, make);
PHP_METHOD(Yuga_Container_Container, get);
PHP_METHOD(Yuga_Container_Container, getSingletons);
PHP_METHOD(Yuga_Container_Container, isSingleton);
PHP_METHOD(Yuga_Container_Container, singletonResolved);
PHP_METHOD(Yuga_Container_Container, getSingletonInstance);
PHP_METHOD(Yuga_Container_Container, prepareObject);
PHP_METHOD(Yuga_Container_Container, resolve);
PHP_METHOD(Yuga_Container_Container, inSingletons);
PHP_METHOD(Yuga_Container_Container, buildDependencies);
PHP_METHOD(Yuga_Container_Container, buildObject);
PHP_METHOD(Yuga_Container_Container, call);
PHP_METHOD(Yuga_Container_Container, callClass);
PHP_METHOD(Yuga_Container_Container, isCallableWithAtSign);
PHP_METHOD(Yuga_Container_Container, getMethodDependencies);
PHP_METHOD(Yuga_Container_Container, getCallReflector);
PHP_METHOD(Yuga_Container_Container, addDependencyForCallParameter);
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_bind, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, singleton)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_bound, 0, 0, 1)
	ZEND_ARG_INFO(0, abstractValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_resolved, 0, 0, 1)
	ZEND_ARG_INFO(0, abstractValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_singleton, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_getbinding, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_getbindings, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_make, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_getsingletons, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_issingleton, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_singletonresolved, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_getsingletoninstance, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_prepareobject, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, objectValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_resolve, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, arguments, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_insingletons, 0, 0, 1)
	ZEND_ARG_INFO(0, classValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_builddependencies, 0, 0, 3)
	ZEND_ARG_INFO(0, arguments)
	ZEND_ARG_INFO(0, dependencies)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_buildobject, 0, 0, 1)
	ZEND_ARG_INFO(0, classValue)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, arguments, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_call, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, parameters, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
#endif
	ZEND_ARG_INFO(0, defaultMethod)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_callclass, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, parameters, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
#endif
	ZEND_ARG_INFO(0, defaultMethod)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_iscallablewithatsign, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_getmethoddependencies, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, parameters, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_getcallreflector, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_container_container_adddependencyforcallparameter, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, parameter, ReflectionParameter, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
	ZEND_ARG_INFO(0, dependencies)
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
	PHP_ME(Yuga_Container_Container, bind, arginfo_yuga_container_container_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, bound, arginfo_yuga_container_container_bound, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, resolved, arginfo_yuga_container_container_resolved, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, has, arginfo_yuga_container_container_has, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, singleton, arginfo_yuga_container_container_singleton, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, getBinding, arginfo_yuga_container_container_getbinding, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Container_Container, getBindings, arginfo_yuga_container_container_getbindings, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Container_Container, getBindings, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Container_Container, make, arginfo_yuga_container_container_make, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, get, arginfo_yuga_container_container_get, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Container_Container, getSingletons, arginfo_yuga_container_container_getsingletons, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Container_Container, getSingletons, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Yuga_Container_Container, isSingleton, arginfo_yuga_container_container_issingleton, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Container_Container, singletonResolved, arginfo_yuga_container_container_singletonresolved, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Container_Container, getSingletonInstance, arginfo_yuga_container_container_getsingletoninstance, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Container_Container, prepareObject, arginfo_yuga_container_container_prepareobject, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Container_Container, resolve, arginfo_yuga_container_container_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, inSingletons, arginfo_yuga_container_container_insingletons, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, buildDependencies, arginfo_yuga_container_container_builddependencies, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Container_Container, buildObject, arginfo_yuga_container_container_buildobject, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Container_Container, call, arginfo_yuga_container_container_call, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Container_Container, callClass, arginfo_yuga_container_container_callclass, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Container_Container, isCallableWithAtSign, arginfo_yuga_container_container_iscallablewithatsign, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Container_Container, getMethodDependencies, arginfo_yuga_container_container_getmethoddependencies, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Container_Container, getCallReflector, arginfo_yuga_container_container_getcallreflector, ZEND_ACC_PROTECTED)
	PHP_ME(Yuga_Container_Container, addDependencyForCallParameter, arginfo_yuga_container_container_adddependencyforcallparameter, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
