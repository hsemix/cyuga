
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "Zend/zend_closures.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Input_Input)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Http\\Input, Input, yuga, http_input_input, yuga_http_input_input_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(yuga_http_input_input_ce, SL("get"), ZEND_ACC_PUBLIC);
	/**
	 * @var array
	 */
	zend_declare_property_null(yuga_http_input_input_ce, SL("post"), ZEND_ACC_PUBLIC);
	/**
	 * @var array
	 */
	zend_declare_property_null(yuga_http_input_input_ce, SL("file"), ZEND_ACC_PUBLIC);
	/**
	 * @var Request
	 */
	zend_declare_property_null(yuga_http_input_input_ce, SL("request"), ZEND_ACC_PROTECTED);
	yuga_http_input_input_ce->create_object = zephir_init_properties_Yuga_Http_Input_Input;

	return SUCCESS;
}

PHP_METHOD(Yuga_Http_Input_Input, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);


	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseinputs", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Http_Input_Input, parseInputs)
{
	zval _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zval _GET, _POST, __$false, _FILES, postValues, _5, _6, _8, _9, _0$$3, _1$$3, _2$$3, _10$$4, _11$$4, _12$$5, _13$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_POST);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&postValues);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_7);


	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_GET, SL("_GET"));

	if (zephir_fast_count_int(&_GET) > 0) {
		ZVAL_LONG(&_1$$3, 522);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "filter_var_array", &_3, 51, &_GET, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "handlegetpost", &_4, 0, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("get"), &_0$$3);
	}
	ZVAL_LONG(&_5, 522);
	ZEPHIR_CALL_FUNCTION(&postValues, "filter_var_array", &_3, 51, &_POST, &_5);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_6, &_5, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 3, 0);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "put");
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "patch");
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "delete");
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_CALL_FUNCTION(&_9, "in_array", NULL, 52, &_6, &_7, &__$false);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_9)) {
		ZEPHIR_INIT_VAR(&_10$$4);
		ZEPHIR_INIT_VAR(&_11$$4);
		ZVAL_STRING(&_11$$4, "php://input");
		zephir_file_get_contents(&_10$$4, &_11$$4);
		ZEPHIR_MAKE_REF(&postValues);
		ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 53, &_10$$4, &postValues);
		ZEPHIR_UNREF(&postValues);
		zephir_check_call_status();
	}
	if (zephir_fast_count_int(&postValues) > 0) {
		ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "handlegetpost", &_4, 0, &postValues);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("post"), &_12$$5);
	}
	if (zephir_fast_count_int(&_FILES) > 0) {
		ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "parsefiles", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("file"), &_13$$6);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Http_Input_Input, parseFiles)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _FILES, list, key, value, keys, files, values, *_0, _1, _4$$3, _8$$3, _5$$4, _7$$4, _10$$7, _13$$7, _11$$8, _12$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&list);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);


	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));

	ZEPHIR_INIT_VAR(&list);
	array_init(&list);
	zephir_is_iterable(&_FILES, 0, "yuga/Http/Input/Input.zep", 84);
	if (Z_TYPE_P(&_FILES) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_FILES), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			zephir_array_fetch_string(&_4$$3, &value, SL("name"), PH_NOISY | PH_READONLY, "yuga/Http/Input/Input.zep", 67);
			if (Z_TYPE_P(&_4$$3) == IS_ARRAY == 0) {
				zephir_array_update_string(&values, SL("index"), &key, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_fast_array_merge(&_7$$4, &value, &values);
				ZEPHIR_CALL_CE_STATIC(&_5$$4, yuga_http_input_inputfile_ce, "createfromarray", &_6, 0, &_7$$4);
				zephir_check_call_status();
				zephir_array_update_zval(&list, &key, &_5$$4, PH_COPY | PH_SEPARATE);
				continue;
			}
			ZEPHIR_INIT_NVAR(&keys);
			array_init(&keys);
			zephir_array_fetch_string(&_8$$3, &value, SL("name"), PH_NOISY | PH_READONLY, "yuga/Http/Input/Input.zep", 75);
			ZEPHIR_CALL_METHOD(&files, this_ptr, "rearrangefiles", &_9, 0, &_8$$3, &keys, &value);
			zephir_check_call_status();
			if (zephir_array_isset(&list, &key)) {
				zephir_array_update_multi(&list, &files, SL("za"), 2, &key);
			} else {
				zephir_array_update_zval(&list, &key, &files, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_FILES, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &_FILES, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_FILES, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_FILES, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_10$$7, &value, SL("name"), PH_NOISY | PH_READONLY, "yuga/Http/Input/Input.zep", 67);
				if (Z_TYPE_P(&_10$$7) == IS_ARRAY == 0) {
					zephir_array_update_string(&values, SL("index"), &key, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_12$$8);
					zephir_fast_array_merge(&_12$$8, &value, &values);
					ZEPHIR_CALL_CE_STATIC(&_11$$8, yuga_http_input_inputfile_ce, "createfromarray", &_6, 0, &_12$$8);
					zephir_check_call_status();
					zephir_array_update_zval(&list, &key, &_11$$8, PH_COPY | PH_SEPARATE);
					continue;
				}
				ZEPHIR_INIT_NVAR(&keys);
				array_init(&keys);
				zephir_array_fetch_string(&_13$$7, &value, SL("name"), PH_NOISY | PH_READONLY, "yuga/Http/Input/Input.zep", 75);
				ZEPHIR_CALL_METHOD(&files, this_ptr, "rearrangefiles", &_9, 0, &_13$$7, &keys, &value);
				zephir_check_call_status();
				if (zephir_array_isset(&list, &key)) {
					zephir_array_update_multi(&list, &files, SL("za"), 2, &key);
				} else {
					zephir_array_update_zval(&list, &key, &files, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_FILES, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&list);
}

PHP_METHOD(Yuga_Http_Input_Input, generateFiles)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *getItem, getItem_sub, value, key, output, *_0, _1, index$$3, files$$3, file$$3, possibleFiles$$3, index$$9, files$$9, file$$9, possibleFiles$$9;
	zval values, _4$$3, _7$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&getItem_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&index$$3);
	ZVAL_UNDEF(&files$$3);
	ZVAL_UNDEF(&file$$3);
	ZVAL_UNDEF(&possibleFiles$$3);
	ZVAL_UNDEF(&index$$9);
	ZVAL_UNDEF(&files$$9);
	ZVAL_UNDEF(&file$$9);
	ZVAL_UNDEF(&possibleFiles$$9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(values)
		Z_PARAM_OBJECT_OF_CLASS(getItem, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &values_param, &getItem);
	zephir_get_arrval(&values, values_param);


	zephir_is_iterable(&values, 0, "yuga/Http/Input/Input.zep", 116);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&index$$3);
			array_init(&index$$3);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_create_array(&_4$$3, 1, 0);
			zephir_array_fast_append(&_4$$3, &key);
			ZEPHIR_INIT_NVAR(&possibleFiles$$3);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&possibleFiles$$3, getItem, &_4$$3);
			zephir_check_call_status();
			if (Z_TYPE_P(&possibleFiles$$3) == IS_ARRAY == 0) {
				ZEPHIR_CALL_METHOD(&file$$3, this_ptr, "getfile", &_5, 0, &key, getItem);
				zephir_check_call_status();
				if (zephir_array_isset(&output, &key)) {
					zephir_array_update_multi(&output, &file$$3, SL("za"), 2, &key);
				} else {
					zephir_array_update_zval(&output, &key, &file$$3, PH_COPY | PH_SEPARATE);
				}
				continue;
			}
			zephir_array_append(&index$$3, &key, PH_SEPARATE, "yuga/Http/Input/Input.zep", 106);
			ZEPHIR_CALL_METHOD(&files$$3, this_ptr, "rearrangefiles", &_6, 0, &value, &index$$3, &index$$3);
			zephir_check_call_status();
			if (zephir_array_isset(&output, &key)) {
				zephir_array_update_multi(&output, &files$$3, SL("za"), 2, &key);
			} else {
				zephir_array_update_zval(&output, &key, &files$$3, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&index$$9);
				array_init(&index$$9);
				ZEPHIR_INIT_NVAR(&_7$$9);
				zephir_create_array(&_7$$9, 1, 0);
				zephir_array_fast_append(&_7$$9, &key);
				ZEPHIR_INIT_NVAR(&possibleFiles$$9);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&possibleFiles$$9, getItem, &_7$$9);
				zephir_check_call_status();
				if (Z_TYPE_P(&possibleFiles$$9) == IS_ARRAY == 0) {
					ZEPHIR_CALL_METHOD(&file$$9, this_ptr, "getfile", &_5, 0, &key, getItem);
					zephir_check_call_status();
					if (zephir_array_isset(&output, &key)) {
						zephir_array_update_multi(&output, &file$$9, SL("za"), 2, &key);
					} else {
						zephir_array_update_zval(&output, &key, &file$$9, PH_COPY | PH_SEPARATE);
					}
					continue;
				}
				zephir_array_append(&index$$9, &key, PH_SEPARATE, "yuga/Http/Input/Input.zep", 106);
				ZEPHIR_CALL_METHOD(&files$$9, this_ptr, "rearrangefiles", &_6, 0, &value, &index$$9, &index$$9);
				zephir_check_call_status();
				if (zephir_array_isset(&output, &key)) {
					zephir_array_update_multi(&output, &files$$9, SL("za"), 2, &key);
				} else {
					zephir_array_update_zval(&output, &key, &files$$9, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&output);
}

PHP_METHOD(Yuga_Http_Input_Input, getFile)
{
	zval _1, _3, _4, _6, _7, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key, key_sub, *getItem, getItem_sub, _2, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&getItem_sub);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OBJECT_OF_CLASS(getItem, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &getItem);


	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 6, 0);
	zephir_array_update_string(&_1, SL("index"), key, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	zephir_array_fast_append(&_3, key);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_2, getItem, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("name"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_fast_append(&_4, key);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "error");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_2, getItem, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("error"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	zephir_array_fast_append(&_6, key);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "tmp_name");
	zephir_array_fast_append(&_6, &_5);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_2, getItem, &_6);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("tmp_name"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0);
	zephir_array_fast_append(&_7, key);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "type");
	zephir_array_fast_append(&_7, &_5);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_2, getItem, &_7);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("type"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 2, 0);
	zephir_array_fast_append(&_8, key);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "size");
	zephir_array_fast_append(&_8, &_5);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_2, getItem, &_8);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("size"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_CE_STATIC(yuga_http_input_inputfile_ce, "createfromarray", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Input_Input, handleGetPost)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrayList_param = NULL, list, key, value, *_0, _1, output$$3, _4$$4, output$$5, _7$$6;
	zval arrayList;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrayList);
	ZVAL_UNDEF(&list);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&output$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&output$$5);
	ZVAL_UNDEF(&_7$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(arrayList)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrayList_param);
	zephir_get_arrval(&arrayList, arrayList_param);


	ZEPHIR_INIT_VAR(&list);
	array_init(&list);
	zephir_is_iterable(&arrayList, 0, "yuga/Http/Input/Input.zep", 149);
	if (Z_TYPE_P(&arrayList) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arrayList), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&value) == IS_ARRAY == 0) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				object_init_ex(&_4$$4, yuga_http_input_inputitem_ce);
				ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", &_5, 54, &key, &value);
				zephir_check_call_status();
				zephir_array_update_zval(&list, &key, &_4$$4, PH_COPY | PH_SEPARATE);
				continue;
			}
			ZEPHIR_CALL_METHOD(&output$$3, this_ptr, "handlegetpost", &_6, 55, &value);
			zephir_check_call_status();
			zephir_array_update_zval(&list, &key, &output$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arrayList, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &arrayList, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &arrayList, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &arrayList, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) == IS_ARRAY == 0) {
					ZEPHIR_INIT_NVAR(&_7$$6);
					object_init_ex(&_7$$6, yuga_http_input_inputitem_ce);
					ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", &_5, 54, &key, &value);
					zephir_check_call_status();
					zephir_array_update_zval(&list, &key, &_7$$6, PH_COPY | PH_SEPARATE);
					continue;
				}
				ZEPHIR_CALL_METHOD(&output$$5, this_ptr, "handlegetpost", &_6, 55, &value);
				zephir_check_call_status();
				zephir_array_update_zval(&list, &key, &output$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &arrayList, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&list);
}

PHP_METHOD(Yuga_Http_Input_Input, rearrangeFiles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *index, index_sub, *original, original_sub, output, getItem;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&original_sub);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&getItem);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(values)
		Z_PARAM_ZVAL(index)
		Z_PARAM_ZVAL(original)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &values_param, &index, &original);
	zephir_get_arrval(&values, values_param);


	ZEPHIR_INIT_VAR(&output);
	array_init(&output);
	ZEPHIR_INIT_VAR(&getItem);
	zephir_create_closure_ex(&getItem, NULL, yuga_2__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(yuga_2__closure_ce, ZEND_STRL("original"), original);
	zephir_update_static_property_ce(yuga_2__closure_ce, ZEND_STRL("index"), index);
	ZEPHIR_CALL_METHOD(&output, this_ptr, "generatefiles", NULL, 0, &values, &getItem);
	zephir_check_call_status();
	RETURN_CCTOR(&output);
}

/**
 * Find post-value by index or return default value.
 *
 * @param string index
 * @param string|null defaultValue
 * @return InputItem|string
 */
PHP_METHOD(Yuga_Http_Input_Input, findPost)
{
	zval _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index, index_sub, *defaultValue = NULL, defaultValue_sub, __$true, __$null, input, stringVar, _0, _6, _1$$3, _2$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&stringVar);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_OBS_VAR(&input);
	zephir_read_property(&input, this_ptr, ZEND_STRL("post"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://input");
	ZEPHIR_INIT_VAR(&stringVar);
	zephir_file_get_contents(&stringVar, &_0);
	if (!(Z_TYPE_P(&stringVar) == IS_NULL)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("post"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_json_decode(&_2$$3, &stringVar, zephir_get_intval(&__$true) );
		zephir_get_arrval(&_3$$3, &_2$$3);
		ZVAL_LONG(&_4$$3, 522);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "filter_var_array", NULL, 51, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&input);
		zephir_fast_array_merge(&input, &_1$$3, &_5$$3);
	}
	ZEPHIR_INIT_VAR(&_6);
	if (zephir_array_isset(&input, index)) {
		zephir_array_fetch(&_6, &input, index, PH_NOISY, "yuga/Http/Input/Input.zep", 189);
	} else {
		ZEPHIR_CPY_WRT(&_6, defaultValue);
	}
	RETURN_CCTOR(&_6);
}

/**
 * Find file by index or return default value.
 *
 * @param string index
 * @param string|null defaultValue
 * @return InputFile|string
 */
PHP_METHOD(Yuga_Http_Input_Input, findFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index, index_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, index)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, index, PH_NOISY, "yuga/Http/Input/Input.zep", 201);
	} else {
		ZEPHIR_CPY_WRT(&_0, defaultValue);
	}
	RETURN_CCTOR(&_0);
}

/**
 * Find parameter/query-string by index or return default value.
 *
 * @param string index
 * @param string|null defaultValue
 * @return InputItem|string
 */
PHP_METHOD(Yuga_Http_Input_Input, findGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index, index_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("get"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, index)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("get"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, index, PH_NOISY, "yuga/Http/Input/Input.zep", 213);
	} else {
		ZEPHIR_CPY_WRT(&_0, defaultValue);
	}
	RETURN_CCTOR(&_0);
}

/**
 * Get input object
 *
 * @param string index
 * @param string|null defaultValue
 * @param array|string|null methods
 * @return IInputItem|string
 */
PHP_METHOD(Yuga_Http_Input_Input, getObject)
{
	zend_bool _0, _2, _4, _5, _6, _8, _9, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *defaultValue = NULL, defaultValue_sub, *methods = NULL, methods_sub, __$null, element, _3, _7, _11, _12, _1$$3;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&methods_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_ZVAL_OR_NULL(methods)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &index_param, &defaultValue, &methods);
	zephir_get_strval(&index, index_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!methods) {
		methods = &methods_sub;
		ZEPHIR_CPY_WRT(methods, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(methods);
	}


	_0 = Z_TYPE_P(methods) != IS_NULL;
	if (_0) {
		_0 = Z_TYPE_P(methods) == IS_STRING == 1;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		zephir_array_fast_append(&_1$$3, methods);
		ZEPHIR_CPY_WRT(methods, &_1$$3);
	}
	ZEPHIR_INIT_VAR(&element);
	ZVAL_NULL(&element);
	_2 = Z_TYPE_P(methods) == IS_NULL;
	if (!(_2)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "get");
		_2 = zephir_fast_in_array(&_3, methods);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&element, this_ptr, "findget", NULL, 0, &index);
		zephir_check_call_status();
	}
	_4 = Z_TYPE_P(&element) == IS_NULL;
	if (_4) {
		_4 = Z_TYPE_P(methods) == IS_NULL;
	}
	_5 = _4;
	if (!(_5)) {
		_6 = Z_TYPE_P(methods) != IS_NULL;
		if (_6) {
			ZEPHIR_INIT_VAR(&_7);
			ZVAL_STRING(&_7, "post");
			_6 = zephir_fast_in_array(&_7, methods);
		}
		_5 = _6;
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(&element, this_ptr, "findpost", NULL, 0, &index);
		zephir_check_call_status();
	}
	_8 = Z_TYPE_P(&element) == IS_NULL;
	if (_8) {
		_8 = Z_TYPE_P(methods) == IS_NULL;
	}
	_9 = _8;
	if (!(_9)) {
		_10 = Z_TYPE_P(methods) != IS_NULL;
		if (_10) {
			ZEPHIR_INIT_VAR(&_11);
			ZVAL_STRING(&_11, "file");
			_10 = zephir_fast_in_array(&_11, methods);
		}
		_9 = _10;
	}
	if (_9) {
		ZEPHIR_CALL_METHOD(&element, this_ptr, "findfile", NULL, 0, &index);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_12);
	if (Z_TYPE_P(&element) != IS_NULL) {
		ZEPHIR_CPY_WRT(&_12, &element);
	} else {
		ZEPHIR_CPY_WRT(&_12, defaultValue);
	}
	RETURN_CCTOR(&_12);
}

/**
 * Get input element value matching index
 *
 * @param string index
 * @param string|null defaultValue
 * @param array|string|null methods
 * @return InputItem|string
 */
PHP_METHOD(Yuga_Http_Input_Input, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *defaultValue = NULL, defaultValue_sub, *methods = NULL, methods_sub, __$null, inputObject, _0$$3, _1$$3, _2$$3;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&methods_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&inputObject);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_ZVAL_OR_NULL(methods)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &index_param, &defaultValue, &methods);
	zephir_get_strval(&index, index_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!methods) {
		methods = &methods_sub;
		methods = &__$null;
	}


	ZEPHIR_CALL_METHOD(&inputObject, this_ptr, "getobject", NULL, 0, &index, defaultValue, methods);
	zephir_check_call_status();
	if (zephir_instance_of_ev(&inputObject, yuga_http_input_inputitem_ce)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CALL_METHOD(&_2$$3, &inputObject, "getvalue", NULL, 0);
		zephir_check_call_status();
		zephir_fast_trim(&_1$$3, &_2$$3, NULL , ZEPHIR_TRIM_BOTH);
		if (ZEPHIR_IS_STRING(&_1$$3, "")) {
			ZEPHIR_CPY_WRT(&_0$$3, defaultValue);
		} else {
			ZEPHIR_CALL_METHOD(&_0$$3, &inputObject, "getvalue", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_CCTOR(&_0$$3);
	}
	RETURN_CCTOR(&inputObject);
}

/**
 * Check if a input-item exist
 *
 * @param string index
 * @return bool
 */
PHP_METHOD(Yuga_Http_Input_Input, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index, index_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getobject", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

/**
 * Get all get/post items
 * @param array|null filter Only take items in filter
 * @return array
 */
PHP_METHOD(Yuga_Http_Input_Input, all)
{
	zend_bool _2, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter_param = NULL, __$true, output, contents, _0, _1, _3, _4, _6, _7, _12, _13, _14, _8$$3, _9$$3, _10$$3, _11$$3;
	zval filter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(filter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filter_param);
	if (!filter_param) {
		ZEPHIR_INIT_VAR(&filter);
	} else {
		zephir_get_arrval(&filter, filter_param);
	}


	ZEPHIR_OBS_VAR(&output);
	zephir_read_property(&output, this_ptr, ZEND_STRL("post"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getmethod", NULL, 0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_STRING(&_1, "post");
	if (!(_2)) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4, &_3, "getmethod", NULL, 0);
		zephir_check_call_status();
		_2 = ZEPHIR_IS_STRING(&_4, "patch");
	}
	_5 = _2;
	if (!(_5)) {
		zephir_read_property(&_6, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7, &_6, "getmethod", NULL, 0);
		zephir_check_call_status();
		_5 = ZEPHIR_IS_STRING(&_7, "put");
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "php://input");
		ZEPHIR_INIT_VAR(&contents);
		zephir_file_get_contents(&contents, &_8$$3);
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_fast_trim(&_9$$3, &contents, NULL , ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "{");
		ZEPHIR_INIT_VAR(&_11$$3);
		zephir_fast_strpos(&_11$$3, &_9$$3, &_10$$3, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(&_11$$3, 0)) {
			ZEPHIR_INIT_NVAR(&output);
			zephir_json_decode(&output, &contents, zephir_get_intval(&__$true) );
			if (ZEPHIR_IS_FALSE_IDENTICAL(&output)) {
				ZEPHIR_INIT_NVAR(&output);
				array_init(&output);
			}
		}
	}
	ZEPHIR_INIT_VAR(&_12);
	if (!ZEPHIR_IS_NULL(&filter)) {
		ZEPHIR_CALL_FUNCTION(&_13, "array_flip", NULL, 56, &filter);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_12, "array_intersect_key", NULL, 57, &output, &_13);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_14, this_ptr, ZEND_STRL("get"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_12, &_14, &output);
	}
	RETURN_CCTOR(&_12);
}

PHP_METHOD(Yuga_Http_Input_Input, file)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *defaultValue = NULL, defaultValue_sub, _FILES, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_FILES);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(key)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params(1, 0, 2, &key, &defaultValue);
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_RETURN_CALL_FUNCTION("array_get", NULL, 0, &_FILES, key, defaultValue);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Determine if the input contains a file
 */
PHP_METHOD(Yuga_Http_Input_Input, hasFile)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, file, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VS(&_0, key, ".tmp_name");
	ZEPHIR_CALL_STATIC(&file, "file", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&file) == IS_ARRAY) {
		zephir_array_fetch_long(&_1$$3, &file, 0, PH_NOISY | PH_READONLY, "yuga/Http/Input/Input.zep", 320);
		if (ZEPHIR_IS_STRING_IDENTICAL(&_1$$3, "")) {
			RETURN_MM_BOOL(0);
		}
		RETURN_MM_BOOL(1);
	}
	_2 = ZEPHIR_IS_STRING_IDENTICAL(&file, "");
	if (!(_2)) {
		_2 = Z_TYPE_P(&file) == IS_NULL;
	}
	if (_2) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

zend_object *zephir_init_properties_Yuga_Http_Input_Input(zend_class_entry *class_type)
{
		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("file"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("post"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("post"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("get"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("get"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

