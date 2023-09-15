
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Yuga_Pipeline_Pipeline)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Pipeline, Pipeline, yuga, pipeline_pipeline, yuga_pipeline_pipeline_method_entry, 0);

	zend_declare_property_null(yuga_pipeline_pipeline_ce, SL("passable"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_pipeline_pipeline_ce, SL("pipes"), ZEND_ACC_PROTECTED);
	zend_declare_property_string(yuga_pipeline_pipeline_ce, SL("method"), "run", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Yuga_Pipeline_Pipeline, send)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *passable, passable_sub, pipeline;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&passable_sub);
	ZVAL_UNDEF(&pipeline);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(passable)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &passable);


	ZEPHIR_INIT_VAR(&pipeline);
	object_init_ex(&pipeline, yuga_pipeline_pipeline_ce);
	if (zephir_has_constructor(&pipeline)) {
		ZEPHIR_CALL_METHOD(NULL, &pipeline, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(&pipeline, ZEND_STRL("passable"), passable);
	RETURN_CCTOR(&pipeline);
}

PHP_METHOD(Yuga_Pipeline_Pipeline, through)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *pipes_param = NULL;
	zval pipes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pipes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(pipes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pipes_param);
	zephir_get_arrval(&pipes, pipes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("pipes"), &pipes);
	RETURN_THIS();
}

PHP_METHOD(Yuga_Pipeline_Pipeline, then)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destination, destination_sub, pipeline, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&pipeline);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(destination, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &destination);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("pipes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "carry", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&pipeline, "array_reduce", NULL, 77, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("passable"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&pipeline, NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Pipeline_Pipeline, thenReturn)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, yuga_6__closure_ce, SL("__invoke"));
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "then", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Pipeline_Pipeline, carry)
{
	zval currentObject;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&currentObject);


	ZEPHIR_MM_GROW();

	ZEPHIR_CPY_WRT(&currentObject, this_ptr);
	zephir_create_closure_ex(return_value, NULL, yuga_7__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(yuga_7__closure_ce, ZEND_STRL("currentObject"), &currentObject);
	RETURN_MM();
}

PHP_METHOD(Yuga_Pipeline_Pipeline, passable)
{
	zval *pipeStack, pipeStack_sub, *pipe, pipe_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pipeStack_sub);
	ZVAL_UNDEF(&pipe_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(pipeStack)
		Z_PARAM_ZVAL(pipe)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &pipeStack, &pipe);


	zephir_create_closure_ex(return_value, NULL, yuga_8__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(yuga_8__closure_ce, ZEND_STRL("pipeStack"), pipeStack);
	zephir_update_static_property_ce(yuga_8__closure_ce, ZEND_STRL("pipe"), pipe);
	return;
}

