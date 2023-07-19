
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Input_InputItem)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Http\\Input, InputItem, yuga, http_input_inputitem, yuga_http_input_inputitem_method_entry, 0);

	zend_declare_property_null(yuga_http_input_inputitem_ce, SL("index"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(yuga_http_input_inputitem_ce, SL("name"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(yuga_http_input_inputitem_ce, SL("value"), ZEND_ACC_PUBLIC);
	zend_class_implements(yuga_http_input_inputitem_ce, 1, yuga_interfaces_http_input_inputiteminterface_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Http_Input_InputItem, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *index, index_sub, *value = NULL, value_sub, __$null, _0, _1, _3, _4, _9, _5$$3, _6$$3, _7$$3, _8$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index, &value);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("index"), index);
	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), value);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("index"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &_0);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "_");
	ZEPHIR_CALL_CE_STATIC(&_1, yuga_support_str_ce, "contains", &_2, 0, &_3, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "_");
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, " ");
		zephir_fast_str_replace(&_5$$3, &_7$$3, &_8$$3, &_6$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &_5$$3);
	}
	ZEPHIR_INIT_NVAR(&_4);
	zephir_read_property(&_9, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_ucfirst(&_4, &_9);
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &_4);
	ZEPHIR_MM_RESTORE();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputItem, getIndex)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "index");
}

PHP_METHOD(Yuga_Http_Input_InputItem, setIndex)
{
	zval *index, index_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &index);


	zephir_update_property_zval(this_ptr, ZEND_STRL("index"), index);
	RETURN_THISW();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputItem, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Set input name
 * @param string name
 * @return static this
 */
PHP_METHOD(Yuga_Http_Input_InputItem, setName)
{
	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &name);


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), name);
	RETURN_THISW();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputItem, getValue)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "value");
}

/**
 * Set input value
 * @param string value
 * @return static this
 */
PHP_METHOD(Yuga_Http_Input_InputItem, setValue)
{
	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &value);


	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), value);
	RETURN_THISW();
}

PHP_METHOD(Yuga_Http_Input_InputItem, __toString)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("value"), PH_NOISY_CC);
	zephir_cast_to_string(&_1, &_0);
	RETURN_CTOR(&_1);
}

