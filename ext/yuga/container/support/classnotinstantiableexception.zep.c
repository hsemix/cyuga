
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Container_Support_ClassNotInstantiableException)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Container\\Support, ClassNotInstantiableException, yuga, container_support_classnotinstantiableexception, zend_ce_exception, NULL, 0);

	return SUCCESS;
}

