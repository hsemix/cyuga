
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Interfaces_Providers_ServiceProviderInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Interfaces\\Providers, ServiceProviderInterface, yuga, interfaces_providers_serviceproviderinterface, yuga_interfaces_providers_serviceproviderinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Yuga_Interfaces_Providers_ServiceProviderInterface, register);
