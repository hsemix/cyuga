
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yuga_Application_Application)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Application, Application, yuga, application_application, yuga_container_container_ce, yuga_application_application_method_entry, 0);

	/**
	 * Store the configuration instance in this variable so we can use it as
	 * <code>this->app->config->get("db.default.settings")</code> from a controller
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerconfig", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Get the base path of the Laravel installation.
 *
 * @param  string  path
 * @return string
 */
PHP_METHOD(Yuga_Application_Application, basePath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path = NULL, path_sub, _0$$3, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path);
	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(path);
	}


	if (!ZEPHIR_IS_STRING(path, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, "/", path);
		ZEPHIR_CPY_WRT(path, &_0$$3);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("basePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_1, path);
	RETURN_MM();
}

/**
 * Get the path to the boot directory.
 *
 * @param  string  path
 * @return string
 */
PHP_METHOD(Yuga_Application_Application, bootPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path = NULL, path_sub, _0$$3, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path);
	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(path);
	}


	if (!ZEPHIR_IS_STRING(path, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, "/", path);
		ZEPHIR_CPY_WRT(path, &_0$$3);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("basePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VSSV(return_value, &_1, "/", "boot", path);
	RETURN_MM();
}

/**
 * Get the path to the application configuration files.
 *
 * @param  string  path
 * @return string
 */
PHP_METHOD(Yuga_Application_Application, configPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path = NULL, path_sub, _0$$3, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path);
	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(path);
	}


	if (!ZEPHIR_IS_STRING(path, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, "/", path);
		ZEPHIR_CPY_WRT(path, &_0$$3);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("basePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VSSV(return_value, &_1, "/", "config", path);
	RETURN_MM();
}

/**
 * Get the path to the configuration cache file.
 *
 * @return string
 */
PHP_METHOD(Yuga_Application_Application, getCachedConfigPath)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "APP_CONFIG_CACHE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cache/config.php");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "normalizecachepath", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the path to the cached services.php file.
 *
 * @return string
 */
PHP_METHOD(Yuga_Application_Application, getCachedServicesPath)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "APP_SERVICES_CACHE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cache/services.php");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "normalizecachepath", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the path to the cached packages.php file.
 *
 * @return string
 */
PHP_METHOD(Yuga_Application_Application, getCachedPackagesPath)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "APP_PACKAGES_CACHE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cache/packages.php");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "normalizecachepath", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Normalize a relative or absolute path to a cache file.
 *
 * @param  string  key
 * @param  string  default
 * @return string
 */
PHP_METHOD(Yuga_Application_Application, normalizeCachePath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *key, key_sub, *defaultValue, defaultValue_sub, env, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&env);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &defaultValue);


	ZEPHIR_CALL_CE_STATIC(&env, yuga_support_helpers_ce, "env", &_0, 0, key);
	zephir_check_call_status();
	if (Z_TYPE_P(&env) == IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "bootpath", NULL, 0, defaultValue);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("absoluteCachePathPrefixes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, yuga_support_str_ce, "startswith", &_2, 0, &env, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_CCTOR(&env);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "basepath", NULL, 0, &env);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Yuga_Application_Application, setVendorDir)
{
	zval *vendorDir, vendorDir_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&vendorDir_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(vendorDir)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &vendorDir);


	zephir_update_property_zval(this_ptr, ZEND_STRL("vendorDir"), vendorDir);
	RETURN_THISW();
}

PHP_METHOD(Yuga_Application_Application, getVendorDir)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "vendorDir");
}

/**
 * Determine if we are running in the console.
 *
 * @return bool
 */
PHP_METHOD(Yuga_Application_Application, runningInConsole)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "php_sapi_name", NULL, 8);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "cli"));
}

/**
 * Return a static instance of the Application instance through out the entire application
 * 
 * @param null
 * 
 * @return \Yuga\Application\Application
 */
PHP_METHOD(Yuga_Application_Application, getInstance)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_static_property_ce(&_0, yuga_application_application_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);
}

/**
 * Register the basic bindings into the container.
 *
 * @return void
 */
PHP_METHOD(Yuga_Application_Application, registerBaseBindings)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(container)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "app");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Yuga\\Container\\Container");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_0, this_ptr);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("basePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "base_path");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Yuga\\Interfaces\\Application\\Application");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Yuga\\Application\\Application");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, &_0, &_2);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("vendorDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "vendor_path");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, &_0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Register the Service providers
 *
 * @return void
 */
PHP_METHOD(Yuga_Application_Application, registerConfig)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, yuga_application_application_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		zephir_update_static_property_ce(yuga_application_application_ce, ZEND_STRL("app"), this_ptr);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerconfigproviders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Run the Yuga application
 */
PHP_METHOD(Yuga_Application_Application, run)
{
	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "config");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Yuga\\Support\\Config");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("debuggerStarted"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_2)) {
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerbasebindings", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerdefaultproviders", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, this_ptr, SL("events"), PH_NOISY | PH_READONLY, "yuga/Application/Application.zep", 310);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "on:app-start");
	ZEPHIR_CALL_METHOD(NULL, &_3, "dispatch", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Get the debug mode if set
 * 
 * @param null
 * 
 * @return bool
 */
PHP_METHOD(Yuga_Application_Application, getDebugEnabled)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "debugEnabled");
}

/**
 * Set the default application's encryption methode
 * 
 * @param string method
 * 
 * @return \Yuga\Application\Application this
 */
PHP_METHOD(Yuga_Application_Application, setEncryptionMethod)
{
	zval *method, method_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &method);


	zephir_update_property_zval(this_ptr, ZEND_STRL("encryptionMethod"), method);
	RETURN_THISW();
}

/**
 * Get the Encryption method
 * 
 * @param null
 * 
 * @return string
 */
PHP_METHOD(Yuga_Application_Application, getEncryptionMethod)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "encryptionMethod");
}

/**
 * Register those providers that need to be loaded before any other providers
 * 
 * @return void
 */
PHP_METHOD(Yuga_Application_Application, registerConfigProviders)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, yuga_events_eventserviceprovider_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 9, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerprovider", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Register all of the base service providers.
 *
 * @return void
 */
PHP_METHOD(Yuga_Application_Application, registerDefaultProviders)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, yuga_route_routeserviceprovider_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, this_ptr);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerprovider", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Set the application request for the console environment.
 *
 * @return void
 */
PHP_METHOD(Yuga_Application_Application, setRequestForYugaConsole)
{
	zval *this_ptr = getThis();



}

/**
 * Refresh the bound request instance in the container.
 *
 * @param  \Yuga\Http\Request  request
 * @return void
 */
PHP_METHOD(Yuga_Application_Application, refreshRequest)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("yuga\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "request");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "singleton", NULL, 0, &_0, request);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Call a method on the default request class.
 *
 * @param  string  method
 * @param  array  parameters
 * @return mixed
 */
PHP_METHOD(Yuga_Application_Application, onRequest)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, *parameters = NULL, parameters_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(method)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method, &parameters);
	if (!parameters) {
		parameters = &parameters_sub;
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, yuga_http_request_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 10);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, method);
	ZEPHIR_RETURN_CALL_FUNCTION("forward_static_call_array", NULL, 11, &_0, parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param \Yuga\Interfaces\Providers\IServiceProvider provider
 * 
 * @return \Yuga\Application\Application this
 */
PHP_METHOD(Yuga_Application_Application, registerProvider)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider, provider_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(provider, zephir_get_internal_ce(SL("yuga\\interfaces\\providers\\serviceproviderinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "providerloaded", NULL, 0, provider);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		if ((zephir_method_exists_ex(provider, ZEND_STRL("register")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, provider, "register", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "bootprovider", NULL, 0, provider);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_get_class(&_1$$3, provider, 0);
		zephir_update_property_array_append(this_ptr, SL("loadedProviders"), &_1$$3);
		RETURN_THIS();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Yuga_Application_Application, getProviders)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "loadedProviders");
}

/**
 * @param \Yuga\Interfaces\Providers\ServiceProviderInterface provider
 * 
 * @return mixed
 */
PHP_METHOD(Yuga_Application_Application, bootProvider)
{
	zval _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider, provider_sub, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(provider, zephir_get_internal_ce(SL("yuga\\interfaces\\providers\\serviceproviderinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);


	if ((zephir_method_exists_ex(provider, ZEND_STRL("boot")) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 2, 0);
		zephir_array_fast_append(&_0$$3, provider);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "boot");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "call", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Determine whether a service provider has been loaded or not
 * 
 * @param ServiceProviderInterface provider
 * 
 * @return bool
 */
PHP_METHOD(Yuga_Application_Application, providerLoaded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *provider, provider_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(provider, zephir_get_internal_ce(SL("yuga\\interfaces\\providers\\serviceproviderinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, provider, 0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("loadedProviders"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_key_exists(&_1, &_0));
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

