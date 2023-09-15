
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(yuga_8__closure)
{
	ZEPHIR_REGISTER_CLASS(yuga, 8__closure, yuga, 8__closure, yuga_8__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(yuga_8__closure_ce, SL("pipeStack"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	zend_declare_property_null(yuga_8__closure_ce, SL("pipe"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(yuga_8__closure, __invoke)
{
	zval _1$$3, _5$$3;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pipeStack, pipe, *passable, passable_sub, _2$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pipeStack);
	ZVAL_UNDEF(&pipe);
	ZVAL_UNDEF(&passable_sub);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(passable)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&pipe, yuga_8__closure_ce, SL("pipe"), PH_NOISY_CC);
	zephir_read_static_property_ce(&pipeStack, yuga_8__closure_ce, SL("pipeStack"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &passable);


	_0 = Z_TYPE_P(&pipe) == IS_STRING;
	if (_0) {
		_0 = zephir_class_exists(&pipe, 1);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		ZEPHIR_CALL_CE_STATIC(&_2$$3, yuga_support_helpers_ce, "app", &_3, 0, &pipe);
		zephir_check_call_status();
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "run");
		zephir_array_fast_append(&_1$$3, &_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 2, 0);
		zephir_array_fast_append(&_5$$3, passable);
		zephir_array_fast_append(&_5$$3, &pipeStack);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_1$$3, &_5$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid pipe type.", "yuga/Pipeline/Pipeline.zep", 88);
		return;
	}
}

