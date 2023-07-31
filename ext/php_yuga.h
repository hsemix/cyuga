
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_YUGA_H
#define PHP_YUGA_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_YUGA_NAME        "yuga"
#define PHP_YUGA_VERSION     "6.0.0"
#define PHP_YUGA_EXTNAME     "yuga"
#define PHP_YUGA_AUTHOR      "Hamid Semitala <semix.hamidouh@gmail.com>"
#define PHP_YUGA_ZEPVERSION  "0.17.0-$Id$"
#define PHP_YUGA_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(yuga)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(yuga)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(yuga)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(yuga, v)
#else
	#define ZEPHIR_GLOBAL(v) (yuga_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_yuga_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(yuga_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(yuga_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def yuga_globals
#define zend_zephir_globals_def zend_yuga_globals

extern zend_module_entry yuga_module_entry;
#define phpext_yuga_ptr &yuga_module_entry

#endif
