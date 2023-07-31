
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "yuga.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *yuga_interfaces_http_input_inputiteminterface_ce;
zend_class_entry *yuga_interfaces_providers_serviceproviderinterface_ce;
zend_class_entry *yuga_interfaces_application_application_ce;
zend_class_entry *yuga_interfaces_events_dispatcher_ce;
zend_class_entry *yuga_container_container_ce;
zend_class_entry *yuga_providers_serviceprovider_ce;
zend_class_entry *yuga_0__closure_ce;
zend_class_entry *yuga_1__closure_ce;
zend_class_entry *yuga_application_application_ce;
zend_class_entry *yuga_container_support_classnotinstantiableexception_ce;
zend_class_entry *yuga_events_dispatcher_dispatcher_ce;
zend_class_entry *yuga_events_exceptions_eventexception_ce;
zend_class_entry *yuga_http_input_input_ce;
zend_class_entry *yuga_http_input_inputfile_ce;
zend_class_entry *yuga_http_input_inputitem_ce;
zend_class_entry *yuga_http_redirect_ce;
zend_class_entry *yuga_http_request_ce;
zend_class_entry *yuga_http_response_ce;
zend_class_entry *yuga_providers_testprovider_ce;
zend_class_entry *yuga_support_str_ce;

ZEND_DECLARE_MODULE_GLOBALS(yuga)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(yuga)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Yuga_Interfaces_Http_Input_InputItemInterface);
	ZEPHIR_INIT(Yuga_Interfaces_Providers_ServiceProviderInterface);
	ZEPHIR_INIT(Yuga_Interfaces_Application_Application);
	ZEPHIR_INIT(Yuga_Interfaces_Events_Dispatcher);
	ZEPHIR_INIT(Yuga_Container_Container);
	ZEPHIR_INIT(Yuga_Providers_ServiceProvider);
	ZEPHIR_INIT(Yuga_Application_Application);
	ZEPHIR_INIT(Yuga_Container_Support_ClassNotInstantiableException);
	ZEPHIR_INIT(Yuga_Events_Dispatcher_Dispatcher);
	ZEPHIR_INIT(Yuga_Events_Exceptions_EventException);
	ZEPHIR_INIT(Yuga_Http_Input_Input);
	ZEPHIR_INIT(Yuga_Http_Input_InputFile);
	ZEPHIR_INIT(Yuga_Http_Input_InputItem);
	ZEPHIR_INIT(Yuga_Http_Redirect);
	ZEPHIR_INIT(Yuga_Http_Request);
	ZEPHIR_INIT(Yuga_Http_Response);
	ZEPHIR_INIT(Yuga_Providers_TestProvider);
	ZEPHIR_INIT(Yuga_Support_Str);
	ZEPHIR_INIT(yuga_0__closure);
	ZEPHIR_INIT(yuga_1__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(yuga)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_yuga_globals *yuga_globals)
{
	yuga_globals->initialized = 0;

	/* Cache Enabled */
	yuga_globals->cache_enabled = 1;

	/* Recursive Lock */
	yuga_globals->recursive_lock = 0;

	/* Static cache */
	memset(yuga_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_yuga_globals *yuga_globals)
{
	
}

static PHP_RINIT_FUNCTION(yuga)
{
	zend_yuga_globals *yuga_globals_ptr;
	yuga_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(yuga_globals_ptr);
	zephir_initialize_memory(yuga_globals_ptr);

		zephir_init_static_properties_Yuga_Container_Container();
		zephir_init_static_properties_Yuga_Providers_ServiceProvider();
	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(yuga)
{
	
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(yuga)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_YUGA_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_YUGA_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_YUGA_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_YUGA_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_YUGA_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(yuga)
{
#if defined(COMPILE_DL_YUGA) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(yuga_globals);
	php_zephir_init_module_globals(yuga_globals);
}

static PHP_GSHUTDOWN_FUNCTION(yuga)
{
	
}


zend_function_entry php_yuga_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_yuga_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry yuga_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_yuga_deps,
	PHP_YUGA_EXTNAME,
	php_yuga_functions,
	PHP_MINIT(yuga),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(yuga),
#else
	NULL,
#endif
	PHP_RINIT(yuga),
	PHP_RSHUTDOWN(yuga),
	PHP_MINFO(yuga),
	PHP_YUGA_VERSION,
	ZEND_MODULE_GLOBALS(yuga),
	PHP_GINIT(yuga),
	PHP_GSHUTDOWN(yuga),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(yuga),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_YUGA
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(yuga)
#endif
