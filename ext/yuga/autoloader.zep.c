
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Yuga_AutoLoader)
{
	ZEPHIR_REGISTER_CLASS(Yuga, AutoLoader, yuga, autoloader, yuga_autoloader_method_entry, 0);

	zend_declare_property_null(yuga_autoloader_ce, SL("namespaces"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_autoloader_ce, SL("instance"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	yuga_autoloader_ce->create_object = zephir_init_properties_Yuga_AutoLoader;

	return SUCCESS;
}

PHP_METHOD(Yuga_AutoLoader, __construct)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_static_property_ce(&_0, yuga_autoloader_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_update_static_property_ce(yuga_autoloader_ce, ZEND_STRL("instance"), this_ptr);
	}
}

/**
 * Return a static instance of the ClassLoad object through out the request
 * 
 * @return object instance
 */
PHP_METHOD(Yuga_AutoLoader, getInstance)
{
	zval _0, _2, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, yuga_autoloader_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, yuga_autoloader_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 28);
		zephir_check_call_status();
		zephir_update_static_property_ce(yuga_autoloader_ce, ZEND_STRL("instance"), &_1$$3);
	}
	zephir_read_static_property_ce(&_2, yuga_autoloader_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_2);
}

/**
 * Load classes using psr-4 autoload
 * 
 * @param array
 */
PHP_METHOD(Yuga_AutoLoader, addPsr4)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classes_param = NULL, namespaceValue, root, *_0, _1;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&namespaceValue);
	ZVAL_UNDEF(&root);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(classes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classes_param);
	zephir_get_arrval(&classes, classes_param);


	zephir_is_iterable(&classes, 0, "yuga/AutoLoader.zep", 41);
	if (Z_TYPE_P(&classes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&classes), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&namespaceValue);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&namespaceValue, _3);
			} else {
				ZVAL_LONG(&namespaceValue, _2);
			}
			ZEPHIR_INIT_NVAR(&root);
			ZVAL_COPY(&root, _0);
			zephir_update_property_array(this_ptr, SL("namespaces"), &namespaceValue, &root);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &classes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &classes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&namespaceValue, &classes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&root, &classes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("namespaces"), &namespaceValue, &root);
			ZEPHIR_CALL_METHOD(NULL, &classes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&root);
	ZEPHIR_INIT_NVAR(&namespaceValue);
	RETURN_THIS();
}

/**
 * Include the file and load the class
 * 
 * @param null
 * 
 * @return resource
 */
PHP_METHOD(Yuga_AutoLoader, load)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "includeFile");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_FUNCTION("spl_autoload_register", NULL, 29, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check the file to find out whether it exists
 * 
 * @param string classValue
 * 
 * @return null
 */
PHP_METHOD(Yuga_AutoLoader, includeFile)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classValue, classValue_sub, parts, namespaceKey, src, filtered, file, namespaces, _0, *_1, _2, _5$$3, _6$$3, _7$$3, _8$$4, _9$$4, _10$$5, _11$$5, _12$$5, _13$$6, _14$$6, _15$$7, _16$$7, _17$$7, _18$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classValue_sub);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&namespaceKey);
	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(classValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classValue);


	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("\\"), classValue, LONG_MAX);
	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&namespaces, &_0);
	zephir_is_iterable(&namespaces, 0, "yuga/AutoLoader.zep", 75);
	if (Z_TYPE_P(&namespaces) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespaces), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&namespaceKey);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&namespaceKey, _4);
			} else {
				ZVAL_LONG(&namespaceKey, _3);
			}
			ZEPHIR_INIT_NVAR(&src);
			ZVAL_COPY(&src, _1);
			zephir_array_fetch_long(&_5$$3, &parts, 0, PH_NOISY | PH_READONLY, "yuga/AutoLoader.zep", 69);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_STRING(&_7$$3, "\\");
			zephir_fast_trim(&_6$$3, &namespaceKey, &_7$$3, ZEPHIR_TRIM_RIGHT);
			if (ZEPHIR_IS_EQUAL(&_5$$3, &_6$$3)) {
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZVAL_STRING(&_9$$4, "/");
				zephir_fast_trim(&_8$$4, &src, &_9$$4, ZEPHIR_TRIM_RIGHT);
				zephir_array_update_long(&parts, 0, &_8$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				ZEPHIR_CPY_WRT(&filtered, &parts);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &namespaces, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &namespaces, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&namespaceKey, &namespaces, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&src, &namespaces, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_10$$5, &parts, 0, PH_NOISY | PH_READONLY, "yuga/AutoLoader.zep", 69);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "\\");
				zephir_fast_trim(&_11$$5, &namespaceKey, &_12$$5, ZEPHIR_TRIM_RIGHT);
				if (ZEPHIR_IS_EQUAL(&_10$$5, &_11$$5)) {
					ZEPHIR_INIT_NVAR(&_13$$6);
					ZEPHIR_INIT_NVAR(&_14$$6);
					ZVAL_STRING(&_14$$6, "/");
					zephir_fast_trim(&_13$$6, &src, &_14$$6, ZEPHIR_TRIM_RIGHT);
					zephir_array_update_long(&parts, 0, &_13$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					ZEPHIR_CPY_WRT(&filtered, &parts);
				}
			ZEPHIR_CALL_METHOD(NULL, &namespaces, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&src);
	ZEPHIR_INIT_NVAR(&namespaceKey);
	if (zephir_fast_count_int(&filtered) > 0) {
		ZEPHIR_INIT_VAR(&_15$$7);
		ZEPHIR_INIT_VAR(&_16$$7);
		zephir_fast_join_str(&_16$$7, SL("/"), &parts);
		ZEPHIR_INIT_VAR(&_17$$7);
		ZVAL_STRING(&_17$$7, "\\");
		ZEPHIR_INIT_VAR(&_18$$7);
		ZVAL_STRING(&_18$$7, "/");
		zephir_fast_str_replace(&_15$$7, &_17$$7, &_18$$7, &_16$$7);
		ZEPHIR_INIT_VAR(&file);
		ZEPHIR_CONCAT_VS(&file, &_15$$7, ".php");
		if ((zephir_file_exists(&file) == SUCCESS)) {
			if (zephir_require_zval(&file) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Add a namespace to the psr-4 autoloaded namespaces array
 * 
 * @param array|string namespaces
 * 
 * @param string|null root
 * 
 * @return static
 */
PHP_METHOD(Yuga_AutoLoader, loadPsr4)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespaces_param = NULL, _0;
	zval namespaces;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(namespaces)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaces_param);
	zephir_get_arrval(&namespaces, namespaces_param);


	ZEPHIR_CALL_STATIC(&_0, "getinstance", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "addpsr4", NULL, 0, &namespaces);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_STATIC("getinstance", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Yuga_AutoLoader(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("namespaces"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("namespaces"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

