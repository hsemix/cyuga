
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


ZEPHIR_INIT_CLASS(Yuga_Session_SessionServiceProvider)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Session, SessionServiceProvider, yuga, session_sessionserviceprovider, yuga_providers_serviceprovider_ce, yuga_session_sessionserviceprovider_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Yuga_Session_SessionServiceProvider, load)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
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
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "session");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Yuga\\Session\\Session");
		ZEPHIR_CALL_METHOD(NULL, app, "singleton", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "session");
		ZEPHIR_CALL_METHOD(NULL, app, "resolve", NULL, 0, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

