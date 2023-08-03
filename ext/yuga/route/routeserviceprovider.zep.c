
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
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Yuga_Route_RouteServiceProvider)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Route, RouteServiceProvider, yuga, route_routeserviceprovider, yuga_providers_serviceprovider_ce, yuga_route_routeserviceprovider_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Yuga_Route_RouteServiceProvider, load)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(app, zephir_get_internal_ce(SL("yuga\\interfaces\\application\\application")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);


	ZEPHIR_CALL_METHOD(&_0, app, "runninginconsole", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
	}
	ZEPHIR_MM_RESTORE();
}

