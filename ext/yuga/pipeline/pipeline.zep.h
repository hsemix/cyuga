
extern zend_class_entry *yuga_pipeline_pipeline_ce;

ZEPHIR_INIT_CLASS(Yuga_Pipeline_Pipeline);

PHP_METHOD(Yuga_Pipeline_Pipeline, send);
PHP_METHOD(Yuga_Pipeline_Pipeline, through);
PHP_METHOD(Yuga_Pipeline_Pipeline, then);
PHP_METHOD(Yuga_Pipeline_Pipeline, thenReturn);
PHP_METHOD(Yuga_Pipeline_Pipeline, carry);
PHP_METHOD(Yuga_Pipeline_Pipeline, passable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_pipeline_pipeline_send, 0, 0, 1)
	ZEND_ARG_INFO(0, passable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_pipeline_pipeline_through, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, pipes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_pipeline_pipeline_then, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, destination, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_pipeline_pipeline_thenreturn, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_pipeline_pipeline_carry, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yuga_pipeline_pipeline_passable, 0, 0, 2)
	ZEND_ARG_INFO(0, pipeStack)
	ZEND_ARG_INFO(0, pipe)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yuga_pipeline_pipeline_method_entry) {
	PHP_ME(Yuga_Pipeline_Pipeline, send, arginfo_yuga_pipeline_pipeline_send, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yuga_Pipeline_Pipeline, through, arginfo_yuga_pipeline_pipeline_through, ZEND_ACC_PUBLIC)
	PHP_ME(Yuga_Pipeline_Pipeline, then, arginfo_yuga_pipeline_pipeline_then, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Pipeline_Pipeline, thenReturn, arginfo_yuga_pipeline_pipeline_thenreturn, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Yuga_Pipeline_Pipeline, thenReturn, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Yuga_Pipeline_Pipeline, carry, arginfo_yuga_pipeline_pipeline_carry, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Yuga_Pipeline_Pipeline, carry, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_ME(Yuga_Pipeline_Pipeline, passable, arginfo_yuga_pipeline_pipeline_passable, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
