
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Yuga_Route_Router_Route)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Route\\Router, Route, yuga, route_router_route, yuga_route_router_route_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yuga_route_router_route_ce, SL("requestTypes"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	/**
	 * If enabled parameters containing null-value
	 * will not be passed along to the callback.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(yuga_route_router_route_ce, SL("filterEmptyParams"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("defaultParameterRegex"), ZEND_ACC_PROTECTED);
	zend_declare_property_string(yuga_route_router_route_ce, SL("paramModifiers"), "{}", ZEND_ACC_PROTECTED);
	zend_declare_property_string(yuga_route_router_route_ce, SL("paramOptionalSymbol"), "?", ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("group"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("parent"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("callback"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("defaultNamespace"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("namespaceValue"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("requestMethods"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("where"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("parameters"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("originalParameters"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_route_router_route_ce, SL("middlewares"), ZEND_ACC_PROTECTED);
	yuga_route_router_route_ce->create_object = zephir_init_properties_Yuga_Route_Router_Route;
	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("PARAMETERS_REGEX_FORMAT"), "%s([\\w]+)(\\%s?)%s");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("PARAMETERS_DEFAULT_REGEX"), "[\\w]+");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_GET"), "get");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_POST"), "post");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_PUT"), "put");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_PATCH"), "patch");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_OPTIONS"), "options");

	zephir_declare_class_constant_string(yuga_route_router_route_ce, SL("REQUEST_TYPE_DELETE"), "delete");

	zend_class_implements(yuga_route_router_route_ce, 1, yuga_route_support_iroute_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Route_Router_Route, loadClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *name, name_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_CALL_CE_STATIC(&_0, yuga_application_application_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "resolve", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get parameters
 *
 * @param array parameters
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_Route, setParameters)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *parameters_param = NULL, _1, _2, _3;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);
	zephir_get_arrval(&parameters, parameters_param);


	_0 = zephir_fast_count_int(&parameters) > 0;
	if (_0) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_fast_count_int(&_1) == 0;
	}
	if (_0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("originalParameters"), &parameters);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_2, &_3, &parameters);
	zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &_2);
	RETURN_THIS();
}

/**
 * Add middleware class-name
 *
 * @deprecated This method is deprecated and will be removed in the near future.
 * @param IMiddleware|string middleware
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_Route, setMiddleware)
{
	zval *middleware, middleware_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middleware_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(middleware)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &middleware);


	zephir_update_property_array_append(this_ptr, SL("middlewares"), middleware);
	RETURN_THISW();
}

/**
 * Add middleware class-name
 *
 * @param IMiddleware|string middleware
 * @return static
 */
PHP_METHOD(Yuga_Route_Router_Route, addMiddleware)
{
	zval *middleware, middleware_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middleware_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(middleware)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &middleware);


	zephir_update_property_array_append(this_ptr, SL("middlewares"), middleware);
	RETURN_THISW();
}

/**
 * Set middlewares array
 *
 * @param array middlewares
 * @return this
 */
PHP_METHOD(Yuga_Route_Router_Route, setMiddlewares)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *middlewares_param = NULL;
	zval middlewares;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middlewares);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(middlewares)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &middlewares_param);
	zephir_get_arrval(&middlewares, middlewares_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("middlewares"), &middlewares);
	RETURN_THIS();
}

/**
 * @return string|array
 */
PHP_METHOD(Yuga_Route_Router_Route, getMiddlewares)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "middlewares");
}

/**
 * Set default regular expression used when matching parameters.
 * This is used when no custom parameter regex is found.
 *
 * @param string regex
 * @return static this
 */
PHP_METHOD(Yuga_Route_Router_Route, setDefaultParameterRegex)
{
	zval *regex, regex_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&regex_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(regex)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &regex);


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultParameterRegex"), regex);
	RETURN_THISW();
}

/**
 * Get default regular expression used when matching parameters.
 *
 * @return string
 */
PHP_METHOD(Yuga_Route_Router_Route, getDefaultParameterRegex)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultParameterRegex");
}

void zephir_init_static_properties_Yuga_Route_Router_Route()
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 6, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "get");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "post");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "put");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "patch");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "options");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "delete");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_static_property_ce(yuga_route_router_route_ce, ZEND_STRL("requestTypes"), &_0);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Yuga_Route_Router_Route(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("middlewares"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("middlewares"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("originalParameters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("originalParameters"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("parameters"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("where"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("where"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("requestMethods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("requestMethods"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

