
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


ZEPHIR_INIT_CLASS(Yuga_Session_MessageBag)
{
	ZEPHIR_REGISTER_CLASS_EX(Yuga\\Session, MessageBag, yuga, session_messagebag, yuga_session_session_ce, NULL, 0);

	return SUCCESS;
}

