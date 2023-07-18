
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * @author Mahad Tech Solutions
 */
ZEPHIR_INIT_CLASS(Yuga_Interfaces_Http_Input_InputItemInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Yuga\\Interfaces\\Http\\Input, InputItemInterface, yuga, interfaces_http_input_inputiteminterface, yuga_interfaces_http_input_inputiteminterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Yuga_Interfaces_Http_Input_InputItemInterface, getIndex);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Http_Input_InputItemInterface, setIndex);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Http_Input_InputItemInterface, getName);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Http_Input_InputItemInterface, setName);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Http_Input_InputItemInterface, getValue);
ZEPHIR_DOC_METHOD(Yuga_Interfaces_Http_Input_InputItemInterface, __toString);
