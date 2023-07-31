
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Providers_ServiceProvider)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Providers, ServiceProvider, yuga, providers_serviceprovider, yuga_providers_serviceprovider_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yuga_providers_serviceprovider_ce, SL("app"), ZEND_ACC_PROTECTED);
	/**
	 * The paths that should be published.
	 *
	 * @var array
	 */
	zend_declare_property_null(yuga_providers_serviceprovider_ce, SL("publishes"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	zend_class_implements(yuga_providers_serviceprovider_ce, 1, yuga_interfaces_providers_serviceproviderinterface_ce);
	return SUCCESS;
}

/**
 * Register a service provider to the container and resolve it or later
 * 
 * @param \Yuga\Interfaces\Application\Application app
 * 
 * @return \Yuga\Interfaces\Application\Application
 */
PHP_METHOD(Yuga_Providers_ServiceProvider, register)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(app, zephir_get_internal_ce(SL("yuga\\interfaces\\application\\application")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "load", NULL, 0, app);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Register a service provider to the container and resolve it or later
 * 
 * @param \Yuga\Container\Container app
 * 
 * @return void
 */
PHP_METHOD(Yuga_Providers_ServiceProvider, load)
{
}

/**
 * Register the package's custom Yuga commands.
 *
 * @param  array  commands
 * @return void
 */
PHP_METHOD(Yuga_Providers_ServiceProvider, commands)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *commands = NULL, commands_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&commands_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(commands)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &commands);
	ZEPHIR_SEPARATE_PARAM(commands);


	if (Z_TYPE_P(commands) == IS_ARRAY) {
	} else {
		ZEPHIR_INIT_NVAR(commands);
		zephir_get_args(commands);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Get the services provided by the provider.
 *
 * @return array
 */
PHP_METHOD(Yuga_Providers_ServiceProvider, provides)
{
	zval *this_ptr = getThis();



	array_init(return_value);
	return;
}

void zephir_init_static_properties_Yuga_Providers_ServiceProvider()
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(yuga_providers_serviceprovider_ce, ZEND_STRL("publishes"), &_0);
	ZEPHIR_MM_RESTORE();
}

