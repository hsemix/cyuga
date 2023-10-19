
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Middleware_MiddleWare)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Http\\Middleware, MiddleWare, yuga, http_middleware_middleware, yuga_http_middleware_middleware_method_entry, 0);

	/**
	 * The apps route's middleware is to be registered here
	 *
	 * @var array
	 */
	zend_declare_property_null(yuga_http_middleware_middleware_ce, SL("routerMiddleWare"), ZEND_ACC_PUBLIC);
	/**
	 * The routes exceptions
	 */
	zend_declare_property_null(yuga_http_middleware_middleware_ce, SL("except"), ZEND_ACC_PUBLIC);
	yuga_http_middleware_middleware_ce->create_object = zephir_init_properties_Yuga_Http_Middleware_MiddleWare;

	return SUCCESS;
}

PHP_METHOD(Yuga_Http_Middleware_MiddleWare, except)
{
	zval *except = NULL, except_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&except_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(except)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &except);
	if (!except) {
		except = &except_sub;
		except = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("except"), except);
	RETURN_THISW();
}

zend_object *zephir_init_properties_Yuga_Http_Middleware_MiddleWare(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("except"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("except"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("routerMiddleWare"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routerMiddleWare"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

