
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


ZEPHIR_INIT_CLASS(Yuga_Route_Exceptions_AnnotationParseException)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Route\\Exceptions, AnnotationParseException, yuga, route_exceptions_annotationparseexception, zend_ce_exception, NULL, 0);

	return SUCCESS;
}

