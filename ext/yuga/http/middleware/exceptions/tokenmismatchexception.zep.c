
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Middleware_Exceptions_TokenMismatchException)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Http\\Middleware\\Exceptions, TokenMismatchException, yuga, http_middleware_exceptions_tokenmismatchexception, zend_ce_exception, NULL, 0);

	return SUCCESS;
}

