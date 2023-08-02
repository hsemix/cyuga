
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Input_InputFile)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Http\\Input, InputFile, yuga, http_input_inputfile, yuga_http_input_inputfile_method_entry, 0);

	zend_declare_property_null(yuga_http_input_inputfile_ce, SL("index"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(yuga_http_input_inputfile_ce, SL("name"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(yuga_http_input_inputfile_ce, SL("filename"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(yuga_http_input_inputfile_ce, SL("size"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(yuga_http_input_inputfile_ce, SL("type"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(yuga_http_input_inputfile_ce, SL("error"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(yuga_http_input_inputfile_ce, SL("tmpName"), ZEND_ACC_PUBLIC);
	zend_class_implements(yuga_http_input_inputfile_ce, 1, yuga_interfaces_http_input_inputiteminterface_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Http_Input_InputFile, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index, index_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);


	zephir_update_property_zval(this_ptr, ZEND_STRL("index"), index);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("index"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "_");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, " ");
	zephir_fast_str_replace(&_1, &_3, &_4, &_2);
	zephir_ucfirst(&_0, &_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Create from array
 *
 * @param array values
 * @throws \InvalidArgumentException
 * @return static
 */
PHP_METHOD(Yuga_Http_Input_InputFile, createFromArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, __$null, _0, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12;
	zval values, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values_param);
	zephir_get_arrval(&values, values_param);


	if (!(zephir_array_isset_string(&values, SL("index")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Index key is required", "yuga/Http/Input/InputFile.zep", 33);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 5, 0);
	zephir_array_update_string(&_1, SL("tmp_name"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("type"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("size"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("name"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("error"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(&_0, &_1, &values);
	ZEPHIR_CPY_WRT(&values, &_0);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, yuga_http_input_inputfile_ce);
	zephir_array_fetch_string(&_3, &values, SL("index"), PH_NOISY | PH_READONLY, "yuga/Http/Input/InputFile.zep", 46);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 31, &_3);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, &values, SL("size"), PH_NOISY | PH_READONLY, "yuga/Http/Input/InputFile.zep", 47);
	ZEPHIR_CALL_METHOD(&_4, &_2, "setsize", NULL, 32, &_5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_7, &values, SL("error"), PH_NOISY | PH_READONLY, "yuga/Http/Input/InputFile.zep", 48);
	ZEPHIR_CALL_METHOD(&_6, &_4, "seterror", NULL, 0, &_7);
	zephir_check_call_status();
	zephir_array_fetch_string(&_9, &values, SL("type"), PH_NOISY | PH_READONLY, "yuga/Http/Input/InputFile.zep", 49);
	ZEPHIR_CALL_METHOD(&_8, &_6, "settype", NULL, 0, &_9);
	zephir_check_call_status();
	zephir_array_fetch_string(&_11, &values, SL("tmp_name"), PH_NOISY | PH_READONLY, "yuga/Http/Input/InputFile.zep", 50);
	ZEPHIR_CALL_METHOD(&_10, &_8, "settmpname", NULL, 0, &_11);
	zephir_check_call_status();
	zephir_array_fetch_string(&_12, &values, SL("name"), PH_NOISY | PH_READONLY, "yuga/Http/Input/InputFile.zep", 51);
	ZEPHIR_RETURN_CALL_METHOD(&_10, "setfilename", NULL, 0, &_12);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputFile, getIndex)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "index");
}

/**
 * Set input index
 * @param string index
 * @return static this
 */
PHP_METHOD(Yuga_Http_Input_InputFile, setIndex)
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
PHP_METHOD(Yuga_Http_Input_InputFile, getSize)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "size");
}

/**
 * Set file size
 * @param int size
 * @return static this
 */
PHP_METHOD(Yuga_Http_Input_InputFile, setSize)
{
	zval *size, size_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&size_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(size)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &size);


	zephir_update_property_zval(this_ptr, ZEND_STRL("size"), size);
	RETURN_THISW();
}

/**
 * Get mime-type of file
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputFile, getMime)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gettype", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputFile, getType)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "type");
}

/**
 * Set type
 * @param string type
 * @return static this
 */
PHP_METHOD(Yuga_Http_Input_InputFile, setType)
{
	zval *type, type_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &type);


	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), type);
	RETURN_THISW();
}

/**
 * Returns extension without "."
 *
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputFile, getExtension)
{
	zval file, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getfilename", NULL, 0);
	zephir_check_call_status();
	zephir_basename(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ".");
	ZEPHIR_INIT_VAR(&file);
	zephir_fast_explode(&file, &_2, &_0, LONG_MAX);
	ZEPHIR_MAKE_REF(&file);
	ZEPHIR_RETURN_CALL_FUNCTION("end", NULL, 33, &file);
	ZEPHIR_UNREF(&file);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get human friendly name
 *
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputFile, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Set human friendly name.
 * Useful for adding validation etc.
 *
 * @param string name
 * @return static this
 */
PHP_METHOD(Yuga_Http_Input_InputFile, setName)
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
 * Set filename
 *
 * @param string name
 * @return static this
 */
PHP_METHOD(Yuga_Http_Input_InputFile, setFilename)
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


	zephir_update_property_zval(this_ptr, ZEND_STRL("filename"), name);
	RETURN_THISW();
}

/**
 * Get filename
 *
 * @return string mixed
 */
PHP_METHOD(Yuga_Http_Input_InputFile, getFilename)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "filename");
}

/**
 * Move the uploaded temporary file to it's new home
 *
 * @param string destination
 * @return bool
 */
PHP_METHOD(Yuga_Http_Input_InputFile, move)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destination, destination_sub, *newFilename, newFilename_sub, __$true, _0, _2, _3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&newFilename_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(destination)
		Z_PARAM_ZVAL(newFilename)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &destination, &newFilename);


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 34, destination);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZVAL_LONG(&_1$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 35, destination, &_1$$3, &__$true);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("tmpName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSV(&_3, destination, "/", newFilename);
	ZEPHIR_RETURN_CALL_FUNCTION("move_uploaded_file", NULL, 36, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get file contents
 *
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputFile, getContents)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("tmpName"), PH_NOISY_CC | PH_READONLY);
	zephir_file_get_contents(return_value, &_0);
	return;
}

/**
 * Return true if an upload error occurred.
 *
 * @return bool
 */
PHP_METHOD(Yuga_Http_Input_InputFile, hasError)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "geterror", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_LONG_IDENTICAL(&_0, 0));
}

/**
 * Get upload-error code.
 *
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputFile, getError)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "error");
}

/**
 * Set error
 *
 * @param int error
 * @return static this
 */
PHP_METHOD(Yuga_Http_Input_InputFile, setError)
{
	zval *error, error_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&error_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(error)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &error);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, zephir_get_intval(error));
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), &_0);
	RETURN_THISW();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Http_Input_InputFile, getTmpName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "tmpName");
}

/**
 * Set file temp. name
 * @param string name
 * @return static this
 */
PHP_METHOD(Yuga_Http_Input_InputFile, setTmpName)
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


	zephir_update_property_zval(this_ptr, ZEND_STRL("tmpName"), name);
	RETURN_THISW();
}

PHP_METHOD(Yuga_Http_Input_InputFile, __toString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gettmpname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Input_InputFile, getValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfilename", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Input_InputFile, toArray)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 5, 0);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("tmpName"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("tmp_name"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("type"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("type"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("size"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("size"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("filename"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("name"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("error"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("error"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

