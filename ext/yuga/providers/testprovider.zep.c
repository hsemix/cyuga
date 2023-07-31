
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


ZEPHIR_INIT_CLASS(Yuga_Providers_TestProvider)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Providers, TestProvider, yuga, providers_testprovider, yuga_providers_serviceprovider_ce, yuga_providers_testprovider_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Yuga_Providers_TestProvider, getName)
{
	zval *this_ptr = getThis();



	RETURN_STRING("Hello world!");
}

PHP_METHOD(Yuga_Providers_TestProvider, load)
{
	zval *app, app_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(app, zephir_get_internal_ce(SL("yuga\\interfaces\\application\\application")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &app);


}

