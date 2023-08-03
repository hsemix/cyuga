
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Exceptions_IException)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Exceptions, IException, yuga, exceptions_iexception, yuga_exceptions_iexception_method_entry);

	return SUCCESS;
}

/**
 * @param Request request
 * @param \Exception error
 * @return Request|null
 */
ZEPHIR_DOC_METHOD(Yuga_Exceptions_IException, handleError);
