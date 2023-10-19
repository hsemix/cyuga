
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Middleware_IMiddleware)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Http\\Middleware, IMiddleware, yuga, http_middleware_imiddleware, yuga_http_middleware_imiddleware_method_entry);

	return SUCCESS;
}

/**
 * Route Middleware
 * @param Request request
 * @return Request|null
 */
ZEPHIR_DOC_METHOD(Yuga_Http_Middleware_IMiddleware, run);
