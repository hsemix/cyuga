
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yuga_Application_Application)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Application, Application, yuga, application_application, yuga_container_container_ce, yuga_application_application_method_entry, 0);

	/**
	 * Store the configuration instance in this variable so we can use it as
	 * <code>$this->app->config->get('db.default.settings')</code> from a controller
	 *
	 * @var \Yuga\Support\Config
	 */
	zend_declare_property_null(yuga_application_application_ce, SL("config"), ZEND_ACC_PUBLIC);
	/**
	 * The base file path of the application so we can install the framework 
	 * in a different directory and access it entiry
	 *
	 * @var string
	 */
	zend_declare_property_null(yuga_application_application_ce, SL("basePath"), ZEND_ACC_PROTECTED);
	/**
	 * The application instance is to be stored in this variable
	 *
	 * @var \Yuga\Application\Application
	 */
	zend_declare_property_null(yuga_application_application_ce, SL("app"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * The Default Application language we shall use
	 * can be changed
	 *
	 * @var string
	 */
	zend_declare_property_string(yuga_application_application_ce, SL("locale"), "en", ZEND_ACC_PROTECTED);
	/**
	 * The Application debug mode default is false 
	 * can be changed in the .env file
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(yuga_application_application_ce, SL("debugEnabled"), 0, ZEND_ACC_PROTECTED);
	/**
	 * The names of the loaded service providers.
	 *
	 * @var array
	 */
	zend_declare_property_null(yuga_application_application_ce, SL("loadedProviders"), ZEND_ACC_PROTECTED);
	/**
	 * The encryption method we shall use throught the entire application
	 * can be changed later
	 *
	 * @var string
	 */
	zend_declare_property_string(yuga_application_application_ce, SL("encryptionMethod"), "AES-256-CBC", ZEND_ACC_PROTECTED);
	zend_declare_property_bool(yuga_application_application_ce, SL("debuggerStarted"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_bool(yuga_application_application_ce, SL("booted"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(yuga_application_application_ce, SL("charset"), ZEND_ACC_PROTECTED);
	/**
	 * composer vendor directory
	 */
	zend_declare_property_null(yuga_application_application_ce, SL("vendorDir"), ZEND_ACC_PROTECTED);
	/**
	 * The prefixes of absolute cache paths for use during normalization.
	 *
	 * @var string[]
	 */
	zend_declare_property_null(yuga_application_application_ce, SL("absoluteCachePathPrefixes"), ZEND_ACC_PROTECTED);
	yuga_application_application_ce->create_object = zephir_init_properties_Yuga_Application_Application;
	zephir_declare_class_constant_string(yuga_application_application_ce, SL("VERSION"), "6.0.0");

	zephir_declare_class_constant_string(yuga_application_application_ce, SL("CHARSET_UTF8"), "UTF-8");

	zend_class_implements(yuga_application_application_ce, 1, yuga_interfaces_application_application_ce);
	return SUCCESS;
}

PHP_METHOD(Yuga_Application_Application, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *root = NULL, root_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&root_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(root)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &root);
	if (!root) {
		root = &root_sub;
		root = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("basePath"), root);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "UTF-8");
	zephir_update_property_zval(this_ptr, ZEND_STRL("charset"), &_0);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Yuga_Application_Application(zend_class_entry *class_type)
{
		zval _1$$3;
	zval _0, _3, _5, _7, _9, _2$$3, _4$$4, _6$$5, _8$$6, _10$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("absoluteCachePathPrefixes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 2, 0);
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "/");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "\\");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("absoluteCachePathPrefixes"), &_1$$3);
		}
		zephir_read_property_ex(&_3, this_ptr, ZEND_STRL("resolved"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_3) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_4$$4);
			array_init(&_4$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("resolved"), &_4$$4);
		}
		zephir_read_property_ex(&_5, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_5) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_6$$5);
			array_init(&_6$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("instances"), &_6$$5);
		}
		zephir_read_property_ex(&_7, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_7) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_8$$6);
			array_init(&_8$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindings"), &_8$$6);
		}
		zephir_read_property_ex(&_9, this_ptr, ZEND_STRL("loadedProviders"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_9) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_10$$7);
			array_init(&_10$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("loadedProviders"), &_10$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

