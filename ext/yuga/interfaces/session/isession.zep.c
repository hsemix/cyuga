
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yuga_Interfaces_Session_ISession)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Interfaces\\Session, ISession, yuga, interfaces_session_isession, yuga_interfaces_session_isession_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Yuga_Interfaces_Session_ISession, check_login);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Session_ISession, isLoggedIn);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Session_ISession, is_logged_in);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Session_ISession, login);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Session_ISession, logout);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Session_ISession, put);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Session_ISession, exists);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Session_ISession, delete);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Session_ISession, get);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Session_ISession, flash);
