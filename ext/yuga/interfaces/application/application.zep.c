
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Interfaces_Application_Application)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Interfaces\\Application, Application, yuga, interfaces_application_application, NULL);

	return SUCCESS;
}

