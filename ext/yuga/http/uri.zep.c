
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Yuga_Http_Uri)
{
	ZEPHIR_REGISTER_CLASS(Yuga\\Http, Uri, yuga, http_uri, yuga_http_uri_method_entry, 0);

	zend_declare_property_null(yuga_http_uri_ce, SL("originalUrl"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(yuga_http_uri_ce, SL("scheme"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(yuga_http_uri_ce, SL("host"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(yuga_http_uri_ce, SL("port"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(yuga_http_uri_ce, SL("username"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(yuga_http_uri_ce, SL("password"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(yuga_http_uri_ce, SL("path"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(yuga_http_uri_ce, SL("params"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(yuga_http_uri_ce, SL("fragment"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * Url constructor.
 *
 * @param string url
 * @throws BadFormedUrlException
 */
PHP_METHOD(Yuga_Http_Uri, __construct)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, __$null, data$$3, _1$$4, _2$$5, _3$$6, _4$$7, _5$$8, _6$$9, _7$$10, params$$11, _8$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&params$$11);
	ZVAL_UNDEF(&_8$$11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(url)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url);


	zephir_update_property_zval(this_ptr, ZEND_STRL("originalUrl"), url);
	_0 = Z_TYPE_P(url) != IS_NULL;
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(url, "/");
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&data$$3, this_ptr, "parseurl", NULL, 0, url);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("scheme"), &__$null);
		zephir_update_property_zval(this_ptr, ZEND_STRL("host"), &__$null);
		zephir_update_property_zval(this_ptr, ZEND_STRL("port"), &__$null);
		zephir_update_property_zval(this_ptr, ZEND_STRL("username"), &__$null);
		zephir_update_property_zval(this_ptr, ZEND_STRL("password"), &__$null);
		zephir_update_property_zval(this_ptr, ZEND_STRL("fragment"), &__$null);
		if (zephir_array_isset_string(&data$$3, SL("scheme"))) {
			zephir_array_fetch_string(&_1$$4, &data$$3, SL("scheme"), PH_NOISY | PH_READONLY, "yuga/Http/Uri.zep", 38);
			zephir_update_property_zval(this_ptr, ZEND_STRL("scheme"), &_1$$4);
		}
		if (zephir_array_isset_string(&data$$3, SL("host"))) {
			zephir_array_fetch_string(&_2$$5, &data$$3, SL("host"), PH_NOISY | PH_READONLY, "yuga/Http/Uri.zep", 42);
			zephir_update_property_zval(this_ptr, ZEND_STRL("host"), &_2$$5);
		}
		if (zephir_array_isset_string(&data$$3, SL("port"))) {
			zephir_array_fetch_string(&_3$$6, &data$$3, SL("port"), PH_NOISY | PH_READONLY, "yuga/Http/Uri.zep", 46);
			zephir_update_property_zval(this_ptr, ZEND_STRL("port"), &_3$$6);
		}
		if (zephir_array_isset_string(&data$$3, SL("user"))) {
			zephir_array_fetch_string(&_4$$7, &data$$3, SL("user"), PH_NOISY | PH_READONLY, "yuga/Http/Uri.zep", 50);
			zephir_update_property_zval(this_ptr, ZEND_STRL("username"), &_4$$7);
		}
		if (zephir_array_isset_string(&data$$3, SL("pass"))) {
			zephir_array_fetch_string(&_5$$8, &data$$3, SL("pass"), PH_NOISY | PH_READONLY, "yuga/Http/Uri.zep", 54);
			zephir_update_property_zval(this_ptr, ZEND_STRL("password"), &_5$$8);
		}
		if (zephir_array_isset_string(&data$$3, SL("path")) == 1) {
			zephir_array_fetch_string(&_6$$9, &data$$3, SL("path"), PH_NOISY | PH_READONLY, "yuga/Http/Uri.zep", 58);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpath", NULL, 0, &_6$$9);
			zephir_check_call_status();
		}
		if (zephir_array_isset_string(&data$$3, SL("fragment"))) {
			zephir_array_fetch_string(&_7$$10, &data$$3, SL("fragment"), PH_NOISY | PH_READONLY, "yuga/Http/Uri.zep", 62);
			zephir_update_property_zval(this_ptr, ZEND_STRL("fragment"), &_7$$10);
		}
		if (zephir_array_isset_string(&data$$3, SL("query")) == 1) {
			ZEPHIR_INIT_VAR(&params$$11);
			array_init(&params$$11);
			zephir_array_fetch_string(&_8$$11, &data$$3, SL("query"), PH_NOISY | PH_READONLY, "yuga/Http/Uri.zep", 67);
			ZEPHIR_MAKE_REF(&params$$11);
			ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 58, &_8$$11, &params$$11);
			ZEPHIR_UNREF(&params$$11);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparams", NULL, 0, &params$$11);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Check if url is using a secure protocol like https
 *
 * @return bool
 */
PHP_METHOD(Yuga_Http_Uri, isSecure)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	zephir_fast_strtolower(&_0, &_1);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "https"));
}

/**
 * Checks if url is relative
 *
 * @return bool
 */
PHP_METHOD(Yuga_Http_Uri, isRelative)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gethost", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(&_0) == IS_NULL);
}

/**
 * Get url scheme
 *
 * @return string|null
 */
PHP_METHOD(Yuga_Http_Uri, getScheme)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "scheme");
}

/**
 * Set the scheme of the url
 *
 * @param string scheme
 * @return static
 */
PHP_METHOD(Yuga_Http_Uri, setScheme)
{
	zval *scheme, scheme_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(scheme)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &scheme);


	zephir_update_property_zval(this_ptr, ZEND_STRL("scheme"), scheme);
	RETURN_THISW();
}

/**
 * Get url host
 *
 * @return string|null
 */
PHP_METHOD(Yuga_Http_Uri, getHost)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "host");
}

/**
 * Set the host of the url
 *
 * @param string host
 * @return static
 */
PHP_METHOD(Yuga_Http_Uri, setHost)
{
	zval *host, host_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(host)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &host);


	zephir_update_property_zval(this_ptr, ZEND_STRL("host"), host);
	RETURN_THISW();
}

/**
 * Get url port
 *
 * @return int|null
 */
PHP_METHOD(Yuga_Http_Uri, getPort)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("port"), PH_NOISY_CC);
		RETURN_MM_LONG(zephir_get_intval(&_1$$3));
	}
	RETURN_MM_NULL();
}

/**
 * Set the port of the url
 *
 * @param int port
 * @return static
 */
PHP_METHOD(Yuga_Http_Uri, setPort)
{
	zval *port, port_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&port_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(port)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &port);


	zephir_update_property_zval(this_ptr, ZEND_STRL("port"), port);
	RETURN_THISW();
}

/**
 * Parse username from url
 *
 * @return string|null
 */
PHP_METHOD(Yuga_Http_Uri, getUsername)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "username");
}

/**
 * Set the username of the url
 *
 * @param string username
 * @return static
 */
PHP_METHOD(Yuga_Http_Uri, setUsername)
{
	zval *username, username_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&username_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(username)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &username);


	zephir_update_property_zval(this_ptr, ZEND_STRL("username"), username);
	RETURN_THISW();
}

/**
 * Parse password from url
 * @return string|null
 */
PHP_METHOD(Yuga_Http_Uri, getPassword)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "password");
}

/**
 * Set the url password
 *
 * @param string password
 * @return static
 */
PHP_METHOD(Yuga_Http_Uri, setPassword)
{
	zval *password, password_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(password)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &password);


	zephir_update_property_zval(this_ptr, ZEND_STRL("password"), password);
	RETURN_THISW();
}

/**
 * Get path from url
 * @return string
 */
PHP_METHOD(Yuga_Http_Uri, getPath)
{
	zval *this_ptr = getThis();



	if (zephir_isset_property(this_ptr, SL("path"))) {
		RETURN_MEMBER(getThis(), "path");
	}
	RETURN_STRING("/");
}

/**
 * Set the url path
 *
 * @param string path
 * @return static
 */
PHP_METHOD(Yuga_Http_Uri, setPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path, path_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, path, &_1, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_0, "/");
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &_2);
	RETURN_THIS();
}

/**
 * Get query-string from url
 *
 * @return array
 */
PHP_METHOD(Yuga_Http_Uri, getParams)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "params");
}

/**
 * Merge parameters array
 *
 * @param array params
 * @return static
 */
PHP_METHOD(Yuga_Http_Uri, mergeParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, _0, _1;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);
	zephir_get_arrval(&params, params_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getparams", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &params);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setparams", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set the url params
 *
 * @param array params
 * @return static
 */
PHP_METHOD(Yuga_Http_Uri, setParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *params_param = NULL;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);
	zephir_get_arrval(&params, params_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &params);
	RETURN_THIS();
}

/**
 * Get query-string params as string
 *
 * @return string
 */
PHP_METHOD(Yuga_Http_Uri, getQueryString)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_STATIC("arraytoparams", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get fragment from url (everything after #)
 *
 * @return string|null
 */
PHP_METHOD(Yuga_Http_Uri, getFragment)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "fragment");
}

/**
 * Set url fragment
 *
 * @param string fragment
 * @return static
 */
PHP_METHOD(Yuga_Http_Uri, setFragment)
{
	zval *fragment, fragment_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fragment_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(fragment)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &fragment);


	zephir_update_property_zval(this_ptr, ZEND_STRL("fragment"), fragment);
	RETURN_THISW();
}

/**
 * @return string
 */
PHP_METHOD(Yuga_Http_Uri, getOriginalUrl)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "originalUrl");
}

/**
 * Get position of value.
 * Returns -1 on failure.
 *
 * @param string value
 * @return int
 */
PHP_METHOD(Yuga_Http_Uri, indexOf)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, index, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoriginalurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&index, "stripos", NULL, 14, &_0, value);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&index)) {
		RETURN_MM_LONG(-1);
	}
	RETURN_CCTOR(&index);
}

/**
 * Check if url contains value.
 *
 * @param string value
 * @return bool
 */
PHP_METHOD(Yuga_Http_Uri, contains)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoriginalurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "stripos", NULL, 14, &_0, value);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_1));
}

/**
 * Check if url contains parameter/query string.
 *
 * @param string name
 * @return bool
 */
PHP_METHOD(Yuga_Http_Uri, hasParam)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, __$true, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("\in_array", NULL, 76, name, &_0, &__$true);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Removes parameter from query-string
 *
 * @param string name
 */
PHP_METHOD(Yuga_Http_Uri, removeParam)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, __$true, _0, params$$3, key$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&params$$3);
	ZVAL_UNDEF(&key$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasparam", NULL, 0, name);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_METHOD(&params$$3, this_ptr, "getparams", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&key$$3, "\array_search", NULL, 77, name, &params$$3, &__$true);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&key$$3)) {
			zephir_array_unset(&params$$3, &key$$3, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparams", NULL, 0, &params$$3);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Get parameter by name.
 * Returns parameter value or default value.
 *
 * @param string name
 * @param string|null defaultValue
 * @return string|null
 */
PHP_METHOD(Yuga_Http_Uri, getParam)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *defaultValue = NULL, defaultValue_sub, __$true, __$null, output, _0, params$$3, key$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&params$$3);
	ZVAL_UNDEF(&key$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_INIT_VAR(&output);
	ZVAL_NULL(&output);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasparam", NULL, 0, name);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_METHOD(&params$$3, this_ptr, "getparams", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&key$$3, "\array_search", NULL, 77, name, &params$$3, &__$true);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&key$$3)) {
			ZEPHIR_OBS_NVAR(&output);
			zephir_array_fetch(&output, &params$$3, &key$$3, PH_NOISY, "yuga/Http/Uri.zep", 388);
		}
	}
	if (zephir_is_true(&output)) {
		RETURN_CCTOR(&output);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

/**
 * UTF-8 aware parse_url() replacement.
 * @param string url
 * @param int component
 * @return array
 * @throws BadFormedUrlException
 */
PHP_METHOD(Yuga_Http_Uri, parseUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url, url_sub, *component = NULL, component_sub, encodedUrl, parts, _0, _1, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&component_sub);
	ZVAL_UNDEF(&encodedUrl);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(url)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(component)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url, &component);
	if (!component) {
		component = &component_sub;
		ZEPHIR_INIT_VAR(component);
		ZVAL_LONG(component, -1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, yuga_4__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/[^:\\/@?&=#]+/u");
	ZEPHIR_CALL_FUNCTION(&encodedUrl, "preg_replace_callback", NULL, 78, &_1, &_0, url);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&parts, "parse_url", NULL, 79, &encodedUrl, component);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&parts)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, yuga_http_exceptions_badformedurlexception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Failed to parse url: \"%s\"");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 4, &_3$$3, url);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 5, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "yuga/Http/Uri.zep", 420);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "urldecode");
	ZEPHIR_RETURN_CALL_FUNCTION("array_map", NULL, 70, &_1, &parts);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Convert array to query-string params
 *
 * @param array getParams
 * @param bool includeEmpty
 * @return string
 */
PHP_METHOD(Yuga_Http_Uri, arrayToParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *getParams_param = NULL, *includeEmpty = NULL, includeEmpty_sub, __$true, _0$$4, _1$$4;
	zval getParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&getParams);
	ZVAL_UNDEF(&includeEmpty_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(getParams)
		Z_PARAM_ZVAL(includeEmpty)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &getParams_param, &includeEmpty);
	if (!getParams_param) {
		ZEPHIR_INIT_VAR(&getParams);
	} else {
		zephir_get_arrval(&getParams, getParams_param);
	}
	if (!includeEmpty) {
		includeEmpty = &includeEmpty_sub;
		includeEmpty = &__$true;
	}


	if (!ZEPHIR_IS_NULL(&getParams)) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(includeEmpty)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_INIT_NVAR(&_0$$4);
			zephir_create_closure_ex(&_0$$4, NULL, yuga_5__closure_ce, SL("__invoke"));
			ZEPHIR_CALL_FUNCTION(&_1$$4, "array_filter", NULL, 6, &getParams, &_0$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&getParams, &_1$$4);
		}
		ZEPHIR_RETURN_CALL_FUNCTION("http_build_query", NULL, 80, &getParams);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_STRING("");
}

/**
 * Returns the relative url
 *
 * @return string
 */
PHP_METHOD(Yuga_Http_Uri, getRelativeUrl)
{
	zval params, path, query, fragment, _1, _0$$3, _2$$5, _3$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&fragment);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&params, this_ptr, "getquerystring", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&path);
	ZVAL_STRING(&path, "");
	ZEPHIR_INIT_VAR(&query);
	ZVAL_STRING(&query, "");
	ZEPHIR_INIT_VAR(&fragment);
	ZVAL_STRING(&fragment, "");
	if (zephir_isset_property(this_ptr, SL("path"))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&path, &_0$$3);
	}
	if (!ZEPHIR_IS_STRING_IDENTICAL(&params, "")) {
		ZEPHIR_INIT_NVAR(&query);
		ZEPHIR_CONCAT_SV(&query, "?", &params);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("fragment"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_1) != IS_NULL) {
		zephir_read_property(&_2$$5, this_ptr, ZEND_STRL("fragment"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_SV(&_3$$5, "#", &_2$$5);
		ZEPHIR_CPY_WRT(&fragment, &_3$$5);
	}
	ZEPHIR_CONCAT_VVV(return_value, &path, &query, &fragment);
	RETURN_MM();
}

/**
 * Returns the absolute url
 *
 * @return string
 */
PHP_METHOD(Yuga_Http_Uri, getAbsoluteUrl)
{
	zend_bool _9;
	zval scheme, host, port, user, pass, _0, _4, _7, _11, _1$$3, _2$$3, _3$$4, _5$$5, _6$$5, _8$$7, _10$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&pass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$8);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&scheme);
	ZVAL_STRING(&scheme, "");
	ZEPHIR_INIT_VAR(&host);
	ZVAL_STRING(&host, "");
	ZEPHIR_INIT_VAR(&port);
	ZVAL_STRING(&port, "");
	ZEPHIR_INIT_VAR(&user);
	ZVAL_STRING(&user, "");
	ZEPHIR_INIT_VAR(&pass);
	ZVAL_STRING(&pass, "");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VS(&_2$$3, &_1$$3, "://");
		ZEPHIR_CPY_WRT(&scheme, &_2$$3);
	}
	if (zephir_isset_property(this_ptr, SL("host"))) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("host"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&host, &_3$$4);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_4) != IS_NULL) {
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZEPHIR_CONCAT_SV(&_6$$5, ":", &_5$$5);
		ZEPHIR_CPY_WRT(&port, &_6$$5);
	}
	if (zephir_isset_property(this_ptr, SL("username"))) {
		ZEPHIR_OBS_NVAR(&user);
		zephir_read_property(&user, this_ptr, ZEND_STRL("username"), PH_NOISY_CC);
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("password"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_7) != IS_NULL) {
		zephir_read_property(&_8$$7, this_ptr, ZEND_STRL("password"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&pass);
		ZEPHIR_CONCAT_SV(&pass, ":", &_8$$7);
	}
	_9 = zephir_is_true(&user);
	if (!(_9)) {
		_9 = zephir_is_true(&pass);
	}
	if (_9) {
		ZEPHIR_INIT_VAR(&_10$$8);
		ZEPHIR_CONCAT_VS(&_10$$8, &pass, "@");
		ZEPHIR_CPY_WRT(&pass, &_10$$8);
	}
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "getrelativeurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVVVVV(return_value, &scheme, &user, &pass, &host, &port, &_11);
	RETURN_MM();
}

PHP_METHOD(Yuga_Http_Uri, __toString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelativeurl", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

