srcdir = /var/www/html/yuga-zephir/yuga/ext
builddir = /var/www/html/yuga-zephir/yuga/ext
top_srcdir = /var/www/html/yuga-zephir/yuga/ext
top_builddir = /var/www/html/yuga-zephir/yuga/ext
EGREP = /usr/bin/grep -E
SED = /usr/bin/sed
CONFIGURE_COMMAND = './configure' '--enable-yuga'
CONFIGURE_OPTIONS = '--enable-yuga'
SHLIB_SUFFIX_NAME = so
SHLIB_DL_SUFFIX_NAME = so
AWK = gawk
shared_objects_yuga = yuga.lo kernel/main.lo kernel/memory.lo kernel/exception.lo kernel/debug.lo kernel/backtrace.lo kernel/object.lo kernel/array.lo kernel/string.lo kernel/fcall.lo kernel/require.lo kernel/file.lo kernel/operators.lo kernel/math.lo kernel/concat.lo kernel/variables.lo kernel/filter.lo kernel/iterator.lo kernel/time.lo kernel/exit.lo yuga/route/support/iroute.lo yuga/route/router/route.lo yuga/route/support/iloadableroute.lo yuga/interfaces/providers/serviceproviderinterface.lo yuga/route/exceptions/httpexception.lo yuga/route/router/loadableroute.lo yuga/eventhandlers/handlerinterface.lo yuga/exceptions/iexception.lo yuga/interfaces/http/input/inputiteminterface.lo yuga/providers/serviceprovider.lo yuga/route/support/icontrollerroute.lo yuga/container/container.lo yuga/exceptions/routeexceptionhandler.lo yuga/interfaces/application/application.lo yuga/interfaces/events/dispatcherinterface.lo yuga/route/support/igrouproute.lo yuga/app.lo yuga/application/application.lo yuga/autoloader.lo yuga/booleantype.lo yuga/container/support/classnotinstantiableexception.lo yuga/cookie/cookie.lo yuga/csrftoken.lo yuga/eventhandlers/applicationstart.lo yuga/eventhandlers/applicationstop.lo yuga/events/dispatcher/dispatcher.lo yuga/events/event.lo yuga/events/eventserviceprovider.lo yuga/events/exceptions/eventexception.lo yuga/guid.lo yuga/http/exceptions/badformedurlexception.lo yuga/http/input/input.lo yuga/http/input/inputfile.lo yuga/http/input/inputitem.lo yuga/http/redirect.lo yuga/http/request.lo yuga/http/response.lo yuga/http/uri.lo yuga/route/exceptions/annotationparseexception.lo yuga/route/exceptions/annotationtargetexception.lo yuga/route/exceptions/notfoundhttpcontrollerexception.lo yuga/route/exceptions/notfoundhttpexception.lo yuga/route/exceptions/notfoundhttpexceptionhandler.lo yuga/route/exceptions/notfoundhttpmethodexception.lo yuga/route/route.lo yuga/route/routeserviceprovider.lo yuga/route/router.lo yuga/route/router/routecontroller.lo yuga/route/router/routegroup.lo yuga/route/router/routeresource.lo yuga/route/router/routeurl.lo yuga/route/support/irouterbootmanager.lo yuga/support/helpers.lo yuga/support/str.lo yuga/0__closure.lo yuga/1__closure.lo yuga/2__closure.lo yuga/3__closure.lo yuga/4__closure.lo yuga/5__closure.lo yuga/6__closure.lo
PHP_PECL_EXTENSION = yuga
YUGA_SHARED_LIBADD =
PHP_MODULES = $(phplibdir)/yuga.la
PHP_ZEND_EX =
all_targets = $(PHP_MODULES) $(PHP_ZEND_EX)
install_targets = install-modules install-headers
prefix = /usr
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /usr
phplibdir = /var/www/html/yuga-zephir/yuga/ext/modules
phpincludedir = /usr/include/php/20210902
CC = gcc
CFLAGS = -O2 -fvisibility=hidden -Wparentheses -flto -DZEPHIR_RELEASE=1
CFLAGS_CLEAN = $(CFLAGS)
CPP = gcc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX =
CXXFLAGS =
CXXFLAGS_CLEAN = $(CXXFLAGS)
EXTENSION_DIR = /usr/lib/php/20210902
PHP_EXECUTABLE = /usr/bin/php8.1
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/usr/include/php/20210902 -I/usr/include/php/20210902/main -I/usr/include/php/20210902/TSRM -I/usr/include/php/20210902/Zend -I/usr/include/php/20210902/ext -I/usr/include/php/20210902/ext/date/lib
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/bash
INSTALL_HEADERS = ext/yuga/php_YUGA.h
BUILD_CC = gcc
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)

all: $(all_targets)
	@echo
	@echo "Build complete."
	@echo "Don't forget to run 'make test'."
	@echo

build-modules: $(PHP_MODULES) $(PHP_ZEND_EX)

build-binaries: $(PHP_BINARIES)

libphp.la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(LIBPHP_CFLAGS) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp $@ $(phptempdir)/$@ >/dev/null 2>&1

libs/libphp.bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp.so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp.$(SHLIB_DL_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp.$(SHLIB_DL_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp.$(SHLIB_DL_SUFFIX_NAME).$$i $(phptempdir)/libphp.$(SHLIB_DL_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-binaries: build-binaries $(install_binary_targets)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-headers:
	-@if test "$(INSTALL_HEADERS)"; then \
		for i in `echo $(INSTALL_HEADERS)`; do \
			i=`$(top_srcdir)/build/shtool path -d $$i`; \
			paths="$$paths $(INSTALL_ROOT)$(phpincludedir)/$$i"; \
		done; \
		$(mkinstalldirs) $$paths && \
		echo "Installing header files:          $(INSTALL_ROOT)$(phpincludedir)/" && \
		for i in `echo $(INSTALL_HEADERS)`; do \
			if test "$(PHP_PECL_EXTENSION)"; then \
				src=`echo $$i | $(SED) -e "s#ext/$(PHP_PECL_EXTENSION)/##g"`; \
			else \
				src=$$i; \
			fi; \
			if test -f "$(top_srcdir)/$$src"; then \
				$(INSTALL_DATA) $(top_srcdir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			elif test -f "$(top_builddir)/$$src"; then \
				$(INSTALL_DATA) $(top_builddir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			else \
				(cd $(top_srcdir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i; \
				cd $(top_builddir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i) 2>/dev/null || true; \
			fi \
		done; \
	fi

PHP_TEST_SETTINGS = -d 'open_basedir=' -d 'output_buffering=0' -d 'memory_limit=-1'
PHP_TEST_SHARED_EXTENSIONS =  ` \
	if test "x$(PHP_MODULES)" != "x"; then \
		for i in $(PHP_MODULES)""; do \
			. $$i; \
			if test "x$$dlname" != "xdl_test.so"; then \
				$(top_srcdir)/build/shtool echo -n -- " -d extension=$$dlname"; \
			fi; \
		done; \
	fi; \
	if test "x$(PHP_ZEND_EX)" != "x"; then \
		for i in $(PHP_ZEND_EX)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d zend_extension=$(top_builddir)/modules/$$dlname"; \
		done; \
	fi`
PHP_DEPRECATED_DIRECTIVES_REGEX = '^(magic_quotes_(gpc|runtime|sybase)?|(zend_)?extension(_debug)?(_ts)?)[\t\ ]*='

test: all
	@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		INI_FILE=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r 'echo php_ini_loaded_file();' 2> /dev/null`; \
		if test "$$INI_FILE"; then \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_FILE" > $(top_builddir)/tmp-php.ini; \
		else \
			echo > $(top_builddir)/tmp-php.ini; \
		fi; \
		INI_SCANNED_PATH=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r '$$a = explode(",\n", trim(php_ini_scanned_files())); echo $$a[0];' 2> /dev/null`; \
		if test "$$INI_SCANNED_PATH"; then \
			INI_SCANNED_PATH=`$(top_srcdir)/build/shtool path -d $$INI_SCANNED_PATH`; \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_SCANNED_PATH"/*.ini >> $(top_builddir)/tmp-php.ini; \
		fi; \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(PHP_EXECUTABLE) -n -c $(top_builddir)/tmp-php.ini $(PHP_TEST_SETTINGS) $(top_srcdir)/run-tests.php -n -c $(top_builddir)/tmp-php.ini -d extension_dir=$(top_builddir)/modules/ $(PHP_TEST_SHARED_EXTENSIONS) $(TESTS); \
		TEST_RESULT_EXIT_CODE=$$?; \
		rm $(top_builddir)/tmp-php.ini; \
		exit $$TEST_RESULT_EXIT_CODE; \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.gcno -o -name \*.gcda | xargs rm -f
	find . -name \*.lo -o -name \*.o -o -name \*.dep | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	rm -f libphp.la $(SAPI_CLI_PATH) $(SAPI_CGI_PATH) $(SAPI_LITESPEED_PATH) $(SAPI_FPM_PATH) $(OVERALL_TARGET) modules/* libs/*
	rm -f ext/opcache/jit/zend_jit_x86.c
	rm -f ext/opcache/jit/zend_jit_arm64.c
	rm -f ext/opcache/minilua

distclean: clean
	rm -f Makefile config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h main/internal_functions_cli.c main/internal_functions.c Zend/zend_dtrace_gen.h Zend/zend_dtrace_gen.h.bak Zend/zend_config.h
	rm -f main/build-defs.h scripts/phpize
	rm -f ext/date/lib/timelib_config.h ext/mbstring/libmbfl/config.h ext/oci8/oci8_dtrace_gen.h ext/oci8/oci8_dtrace_gen.h.bak
	rm -f scripts/man1/phpize.1 scripts/php-config scripts/man1/php-config.1 sapi/cli/php.1 sapi/cgi/php-cgi.1 sapi/phpdbg/phpdbg.1 ext/phar/phar.1 ext/phar/phar.phar.1
	rm -f sapi/fpm/php-fpm.conf sapi/fpm/init.d.php-fpm sapi/fpm/php-fpm.service sapi/fpm/php-fpm.8 sapi/fpm/status.html
	rm -f ext/phar/phar.phar ext/phar/phar.php
	if test "$(srcdir)" != "$(builddir)"; then \
	  rm -f ext/phar/phar/phar.inc; \
	fi
	$(EGREP) define'.*include/php' $(top_srcdir)/configure | $(SED) 's/.*>//'|xargs rm -f

prof-gen:
	CCACHE_DISABLE=1 $(MAKE) PROF_FLAGS=-fprofile-generate all

prof-clean:
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f
	find . -name \*.so | xargs rm -f
	rm -f libphp.la $(SAPI_CLI_PATH) $(SAPI_CGI_PATH) $(SAPI_LITESPEED_PATH) $(SAPI_FPM_PATH) $(OVERALL_TARGET) modules/* libs/*

prof-use:
	CCACHE_DISABLE=1 $(MAKE) PROF_FLAGS=-fprofile-use all

%_arginfo.h: %.stub.php
	@if test -e "$(top_srcdir)/build/gen_stub.php"; then \
		if test ! -z "$(PHP)"; then \
			echo Parse $< to generate $@;\
			$(PHP) $(top_srcdir)/build/gen_stub.php $<; \
		elif test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
			echo Parse $< to generate $@;\
			$(PHP_EXECUTABLE) $(top_srcdir)/build/gen_stub.php $<; \
		fi; \
	fi;

.PHONY: all clean install distclean test prof-gen prof-clean prof-use
.NOEXPORT:
-include yuga.dep
yuga.lo: /var/www/html/yuga-zephir/yuga/ext/yuga.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga.c -o yuga.lo  -MMD -MF yuga.dep -MT yuga.lo
-include kernel/main.dep
kernel/main.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/main.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/main.c -o kernel/main.lo  -MMD -MF kernel/main.dep -MT kernel/main.lo
-include kernel/memory.dep
kernel/memory.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/memory.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/memory.c -o kernel/memory.lo  -MMD -MF kernel/memory.dep -MT kernel/memory.lo
-include kernel/exception.dep
kernel/exception.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/exception.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/exception.c -o kernel/exception.lo  -MMD -MF kernel/exception.dep -MT kernel/exception.lo
-include kernel/debug.dep
kernel/debug.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/debug.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/debug.c -o kernel/debug.lo  -MMD -MF kernel/debug.dep -MT kernel/debug.lo
-include kernel/backtrace.dep
kernel/backtrace.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/backtrace.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/backtrace.c -o kernel/backtrace.lo  -MMD -MF kernel/backtrace.dep -MT kernel/backtrace.lo
-include kernel/object.dep
kernel/object.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/object.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/object.c -o kernel/object.lo  -MMD -MF kernel/object.dep -MT kernel/object.lo
-include kernel/array.dep
kernel/array.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/array.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/array.c -o kernel/array.lo  -MMD -MF kernel/array.dep -MT kernel/array.lo
-include kernel/string.dep
kernel/string.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/string.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/string.c -o kernel/string.lo  -MMD -MF kernel/string.dep -MT kernel/string.lo
-include kernel/fcall.dep
kernel/fcall.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/fcall.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/fcall.c -o kernel/fcall.lo  -MMD -MF kernel/fcall.dep -MT kernel/fcall.lo
-include kernel/require.dep
kernel/require.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/require.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/require.c -o kernel/require.lo  -MMD -MF kernel/require.dep -MT kernel/require.lo
-include kernel/file.dep
kernel/file.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/file.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/file.c -o kernel/file.lo  -MMD -MF kernel/file.dep -MT kernel/file.lo
-include kernel/operators.dep
kernel/operators.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/operators.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/operators.c -o kernel/operators.lo  -MMD -MF kernel/operators.dep -MT kernel/operators.lo
-include kernel/math.dep
kernel/math.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/math.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/math.c -o kernel/math.lo  -MMD -MF kernel/math.dep -MT kernel/math.lo
-include kernel/concat.dep
kernel/concat.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/concat.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/concat.c -o kernel/concat.lo  -MMD -MF kernel/concat.dep -MT kernel/concat.lo
-include kernel/variables.dep
kernel/variables.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/variables.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/variables.c -o kernel/variables.lo  -MMD -MF kernel/variables.dep -MT kernel/variables.lo
-include kernel/filter.dep
kernel/filter.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/filter.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/filter.c -o kernel/filter.lo  -MMD -MF kernel/filter.dep -MT kernel/filter.lo
-include kernel/iterator.dep
kernel/iterator.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/iterator.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/iterator.c -o kernel/iterator.lo  -MMD -MF kernel/iterator.dep -MT kernel/iterator.lo
-include kernel/time.dep
kernel/time.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/time.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/time.c -o kernel/time.lo  -MMD -MF kernel/time.dep -MT kernel/time.lo
-include kernel/exit.dep
kernel/exit.lo: /var/www/html/yuga-zephir/yuga/ext/kernel/exit.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/kernel/exit.c -o kernel/exit.lo  -MMD -MF kernel/exit.dep -MT kernel/exit.lo
-include yuga/route/support/iroute.dep
yuga/route/support/iroute.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/support/iroute.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/support/iroute.zep.c -o yuga/route/support/iroute.lo  -MMD -MF yuga/route/support/iroute.dep -MT yuga/route/support/iroute.lo
-include yuga/route/router/route.dep
yuga/route/router/route.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/route.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/route.zep.c -o yuga/route/router/route.lo  -MMD -MF yuga/route/router/route.dep -MT yuga/route/router/route.lo
-include yuga/route/support/iloadableroute.dep
yuga/route/support/iloadableroute.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/support/iloadableroute.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/support/iloadableroute.zep.c -o yuga/route/support/iloadableroute.lo  -MMD -MF yuga/route/support/iloadableroute.dep -MT yuga/route/support/iloadableroute.lo
-include yuga/interfaces/providers/serviceproviderinterface.dep
yuga/interfaces/providers/serviceproviderinterface.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/interfaces/providers/serviceproviderinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/interfaces/providers/serviceproviderinterface.zep.c -o yuga/interfaces/providers/serviceproviderinterface.lo  -MMD -MF yuga/interfaces/providers/serviceproviderinterface.dep -MT yuga/interfaces/providers/serviceproviderinterface.lo
-include yuga/route/exceptions/httpexception.dep
yuga/route/exceptions/httpexception.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/httpexception.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/httpexception.zep.c -o yuga/route/exceptions/httpexception.lo  -MMD -MF yuga/route/exceptions/httpexception.dep -MT yuga/route/exceptions/httpexception.lo
-include yuga/route/router/loadableroute.dep
yuga/route/router/loadableroute.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/loadableroute.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/loadableroute.zep.c -o yuga/route/router/loadableroute.lo  -MMD -MF yuga/route/router/loadableroute.dep -MT yuga/route/router/loadableroute.lo
-include yuga/eventhandlers/handlerinterface.dep
yuga/eventhandlers/handlerinterface.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/eventhandlers/handlerinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/eventhandlers/handlerinterface.zep.c -o yuga/eventhandlers/handlerinterface.lo  -MMD -MF yuga/eventhandlers/handlerinterface.dep -MT yuga/eventhandlers/handlerinterface.lo
-include yuga/exceptions/iexception.dep
yuga/exceptions/iexception.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/exceptions/iexception.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/exceptions/iexception.zep.c -o yuga/exceptions/iexception.lo  -MMD -MF yuga/exceptions/iexception.dep -MT yuga/exceptions/iexception.lo
-include yuga/interfaces/http/input/inputiteminterface.dep
yuga/interfaces/http/input/inputiteminterface.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/interfaces/http/input/inputiteminterface.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/interfaces/http/input/inputiteminterface.zep.c -o yuga/interfaces/http/input/inputiteminterface.lo  -MMD -MF yuga/interfaces/http/input/inputiteminterface.dep -MT yuga/interfaces/http/input/inputiteminterface.lo
-include yuga/providers/serviceprovider.dep
yuga/providers/serviceprovider.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/providers/serviceprovider.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/providers/serviceprovider.zep.c -o yuga/providers/serviceprovider.lo  -MMD -MF yuga/providers/serviceprovider.dep -MT yuga/providers/serviceprovider.lo
-include yuga/route/support/icontrollerroute.dep
yuga/route/support/icontrollerroute.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/support/icontrollerroute.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/support/icontrollerroute.zep.c -o yuga/route/support/icontrollerroute.lo  -MMD -MF yuga/route/support/icontrollerroute.dep -MT yuga/route/support/icontrollerroute.lo
-include yuga/container/container.dep
yuga/container/container.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/container/container.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/container/container.zep.c -o yuga/container/container.lo  -MMD -MF yuga/container/container.dep -MT yuga/container/container.lo
-include yuga/exceptions/routeexceptionhandler.dep
yuga/exceptions/routeexceptionhandler.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/exceptions/routeexceptionhandler.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/exceptions/routeexceptionhandler.zep.c -o yuga/exceptions/routeexceptionhandler.lo  -MMD -MF yuga/exceptions/routeexceptionhandler.dep -MT yuga/exceptions/routeexceptionhandler.lo
-include yuga/interfaces/application/application.dep
yuga/interfaces/application/application.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/interfaces/application/application.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/interfaces/application/application.zep.c -o yuga/interfaces/application/application.lo  -MMD -MF yuga/interfaces/application/application.dep -MT yuga/interfaces/application/application.lo
-include yuga/interfaces/events/dispatcherinterface.dep
yuga/interfaces/events/dispatcherinterface.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/interfaces/events/dispatcherinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/interfaces/events/dispatcherinterface.zep.c -o yuga/interfaces/events/dispatcherinterface.lo  -MMD -MF yuga/interfaces/events/dispatcherinterface.dep -MT yuga/interfaces/events/dispatcherinterface.lo
-include yuga/route/support/igrouproute.dep
yuga/route/support/igrouproute.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/support/igrouproute.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/support/igrouproute.zep.c -o yuga/route/support/igrouproute.lo  -MMD -MF yuga/route/support/igrouproute.dep -MT yuga/route/support/igrouproute.lo
-include yuga/app.dep
yuga/app.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/app.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/app.zep.c -o yuga/app.lo  -MMD -MF yuga/app.dep -MT yuga/app.lo
-include yuga/application/application.dep
yuga/application/application.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/application/application.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/application/application.zep.c -o yuga/application/application.lo  -MMD -MF yuga/application/application.dep -MT yuga/application/application.lo
-include yuga/autoloader.dep
yuga/autoloader.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/autoloader.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/autoloader.zep.c -o yuga/autoloader.lo  -MMD -MF yuga/autoloader.dep -MT yuga/autoloader.lo
-include yuga/booleantype.dep
yuga/booleantype.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/booleantype.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/booleantype.zep.c -o yuga/booleantype.lo  -MMD -MF yuga/booleantype.dep -MT yuga/booleantype.lo
-include yuga/container/support/classnotinstantiableexception.dep
yuga/container/support/classnotinstantiableexception.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/container/support/classnotinstantiableexception.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/container/support/classnotinstantiableexception.zep.c -o yuga/container/support/classnotinstantiableexception.lo  -MMD -MF yuga/container/support/classnotinstantiableexception.dep -MT yuga/container/support/classnotinstantiableexception.lo
-include yuga/cookie/cookie.dep
yuga/cookie/cookie.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/cookie/cookie.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/cookie/cookie.zep.c -o yuga/cookie/cookie.lo  -MMD -MF yuga/cookie/cookie.dep -MT yuga/cookie/cookie.lo
-include yuga/csrftoken.dep
yuga/csrftoken.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/csrftoken.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/csrftoken.zep.c -o yuga/csrftoken.lo  -MMD -MF yuga/csrftoken.dep -MT yuga/csrftoken.lo
-include yuga/eventhandlers/applicationstart.dep
yuga/eventhandlers/applicationstart.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/eventhandlers/applicationstart.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/eventhandlers/applicationstart.zep.c -o yuga/eventhandlers/applicationstart.lo  -MMD -MF yuga/eventhandlers/applicationstart.dep -MT yuga/eventhandlers/applicationstart.lo
-include yuga/eventhandlers/applicationstop.dep
yuga/eventhandlers/applicationstop.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/eventhandlers/applicationstop.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/eventhandlers/applicationstop.zep.c -o yuga/eventhandlers/applicationstop.lo  -MMD -MF yuga/eventhandlers/applicationstop.dep -MT yuga/eventhandlers/applicationstop.lo
-include yuga/events/dispatcher/dispatcher.dep
yuga/events/dispatcher/dispatcher.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/events/dispatcher/dispatcher.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/events/dispatcher/dispatcher.zep.c -o yuga/events/dispatcher/dispatcher.lo  -MMD -MF yuga/events/dispatcher/dispatcher.dep -MT yuga/events/dispatcher/dispatcher.lo
-include yuga/events/event.dep
yuga/events/event.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/events/event.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/events/event.zep.c -o yuga/events/event.lo  -MMD -MF yuga/events/event.dep -MT yuga/events/event.lo
-include yuga/events/eventserviceprovider.dep
yuga/events/eventserviceprovider.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/events/eventserviceprovider.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/events/eventserviceprovider.zep.c -o yuga/events/eventserviceprovider.lo  -MMD -MF yuga/events/eventserviceprovider.dep -MT yuga/events/eventserviceprovider.lo
-include yuga/events/exceptions/eventexception.dep
yuga/events/exceptions/eventexception.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/events/exceptions/eventexception.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/events/exceptions/eventexception.zep.c -o yuga/events/exceptions/eventexception.lo  -MMD -MF yuga/events/exceptions/eventexception.dep -MT yuga/events/exceptions/eventexception.lo
-include yuga/guid.dep
yuga/guid.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/guid.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/guid.zep.c -o yuga/guid.lo  -MMD -MF yuga/guid.dep -MT yuga/guid.lo
-include yuga/http/exceptions/badformedurlexception.dep
yuga/http/exceptions/badformedurlexception.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/http/exceptions/badformedurlexception.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/http/exceptions/badformedurlexception.zep.c -o yuga/http/exceptions/badformedurlexception.lo  -MMD -MF yuga/http/exceptions/badformedurlexception.dep -MT yuga/http/exceptions/badformedurlexception.lo
-include yuga/http/input/input.dep
yuga/http/input/input.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/http/input/input.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/http/input/input.zep.c -o yuga/http/input/input.lo  -MMD -MF yuga/http/input/input.dep -MT yuga/http/input/input.lo
-include yuga/http/input/inputfile.dep
yuga/http/input/inputfile.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/http/input/inputfile.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/http/input/inputfile.zep.c -o yuga/http/input/inputfile.lo  -MMD -MF yuga/http/input/inputfile.dep -MT yuga/http/input/inputfile.lo
-include yuga/http/input/inputitem.dep
yuga/http/input/inputitem.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/http/input/inputitem.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/http/input/inputitem.zep.c -o yuga/http/input/inputitem.lo  -MMD -MF yuga/http/input/inputitem.dep -MT yuga/http/input/inputitem.lo
-include yuga/http/redirect.dep
yuga/http/redirect.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/http/redirect.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/http/redirect.zep.c -o yuga/http/redirect.lo  -MMD -MF yuga/http/redirect.dep -MT yuga/http/redirect.lo
-include yuga/http/request.dep
yuga/http/request.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/http/request.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/http/request.zep.c -o yuga/http/request.lo  -MMD -MF yuga/http/request.dep -MT yuga/http/request.lo
-include yuga/http/response.dep
yuga/http/response.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/http/response.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/http/response.zep.c -o yuga/http/response.lo  -MMD -MF yuga/http/response.dep -MT yuga/http/response.lo
-include yuga/http/uri.dep
yuga/http/uri.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/http/uri.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/http/uri.zep.c -o yuga/http/uri.lo  -MMD -MF yuga/http/uri.dep -MT yuga/http/uri.lo
-include yuga/route/exceptions/annotationparseexception.dep
yuga/route/exceptions/annotationparseexception.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/annotationparseexception.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/annotationparseexception.zep.c -o yuga/route/exceptions/annotationparseexception.lo  -MMD -MF yuga/route/exceptions/annotationparseexception.dep -MT yuga/route/exceptions/annotationparseexception.lo
-include yuga/route/exceptions/annotationtargetexception.dep
yuga/route/exceptions/annotationtargetexception.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/annotationtargetexception.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/annotationtargetexception.zep.c -o yuga/route/exceptions/annotationtargetexception.lo  -MMD -MF yuga/route/exceptions/annotationtargetexception.dep -MT yuga/route/exceptions/annotationtargetexception.lo
-include yuga/route/exceptions/notfoundhttpcontrollerexception.dep
yuga/route/exceptions/notfoundhttpcontrollerexception.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/notfoundhttpcontrollerexception.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/notfoundhttpcontrollerexception.zep.c -o yuga/route/exceptions/notfoundhttpcontrollerexception.lo  -MMD -MF yuga/route/exceptions/notfoundhttpcontrollerexception.dep -MT yuga/route/exceptions/notfoundhttpcontrollerexception.lo
-include yuga/route/exceptions/notfoundhttpexception.dep
yuga/route/exceptions/notfoundhttpexception.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/notfoundhttpexception.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/notfoundhttpexception.zep.c -o yuga/route/exceptions/notfoundhttpexception.lo  -MMD -MF yuga/route/exceptions/notfoundhttpexception.dep -MT yuga/route/exceptions/notfoundhttpexception.lo
-include yuga/route/exceptions/notfoundhttpexceptionhandler.dep
yuga/route/exceptions/notfoundhttpexceptionhandler.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/notfoundhttpexceptionhandler.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/notfoundhttpexceptionhandler.zep.c -o yuga/route/exceptions/notfoundhttpexceptionhandler.lo  -MMD -MF yuga/route/exceptions/notfoundhttpexceptionhandler.dep -MT yuga/route/exceptions/notfoundhttpexceptionhandler.lo
-include yuga/route/exceptions/notfoundhttpmethodexception.dep
yuga/route/exceptions/notfoundhttpmethodexception.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/notfoundhttpmethodexception.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/exceptions/notfoundhttpmethodexception.zep.c -o yuga/route/exceptions/notfoundhttpmethodexception.lo  -MMD -MF yuga/route/exceptions/notfoundhttpmethodexception.dep -MT yuga/route/exceptions/notfoundhttpmethodexception.lo
-include yuga/route/route.dep
yuga/route/route.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/route.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/route.zep.c -o yuga/route/route.lo  -MMD -MF yuga/route/route.dep -MT yuga/route/route.lo
-include yuga/route/routeserviceprovider.dep
yuga/route/routeserviceprovider.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/routeserviceprovider.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/routeserviceprovider.zep.c -o yuga/route/routeserviceprovider.lo  -MMD -MF yuga/route/routeserviceprovider.dep -MT yuga/route/routeserviceprovider.lo
-include yuga/route/router.dep
yuga/route/router.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/router.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/router.zep.c -o yuga/route/router.lo  -MMD -MF yuga/route/router.dep -MT yuga/route/router.lo
-include yuga/route/router/routecontroller.dep
yuga/route/router/routecontroller.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/routecontroller.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/routecontroller.zep.c -o yuga/route/router/routecontroller.lo  -MMD -MF yuga/route/router/routecontroller.dep -MT yuga/route/router/routecontroller.lo
-include yuga/route/router/routegroup.dep
yuga/route/router/routegroup.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/routegroup.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/routegroup.zep.c -o yuga/route/router/routegroup.lo  -MMD -MF yuga/route/router/routegroup.dep -MT yuga/route/router/routegroup.lo
-include yuga/route/router/routeresource.dep
yuga/route/router/routeresource.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/routeresource.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/routeresource.zep.c -o yuga/route/router/routeresource.lo  -MMD -MF yuga/route/router/routeresource.dep -MT yuga/route/router/routeresource.lo
-include yuga/route/router/routeurl.dep
yuga/route/router/routeurl.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/routeurl.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/router/routeurl.zep.c -o yuga/route/router/routeurl.lo  -MMD -MF yuga/route/router/routeurl.dep -MT yuga/route/router/routeurl.lo
-include yuga/route/support/irouterbootmanager.dep
yuga/route/support/irouterbootmanager.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/route/support/irouterbootmanager.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/route/support/irouterbootmanager.zep.c -o yuga/route/support/irouterbootmanager.lo  -MMD -MF yuga/route/support/irouterbootmanager.dep -MT yuga/route/support/irouterbootmanager.lo
-include yuga/support/helpers.dep
yuga/support/helpers.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/support/helpers.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/support/helpers.zep.c -o yuga/support/helpers.lo  -MMD -MF yuga/support/helpers.dep -MT yuga/support/helpers.lo
-include yuga/support/str.dep
yuga/support/str.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/support/str.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/support/str.zep.c -o yuga/support/str.lo  -MMD -MF yuga/support/str.dep -MT yuga/support/str.lo
-include yuga/0__closure.dep
yuga/0__closure.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/0__closure.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/0__closure.zep.c -o yuga/0__closure.lo  -MMD -MF yuga/0__closure.dep -MT yuga/0__closure.lo
-include yuga/1__closure.dep
yuga/1__closure.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/1__closure.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/1__closure.zep.c -o yuga/1__closure.lo  -MMD -MF yuga/1__closure.dep -MT yuga/1__closure.lo
-include yuga/2__closure.dep
yuga/2__closure.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/2__closure.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/2__closure.zep.c -o yuga/2__closure.lo  -MMD -MF yuga/2__closure.dep -MT yuga/2__closure.lo
-include yuga/3__closure.dep
yuga/3__closure.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/3__closure.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/3__closure.zep.c -o yuga/3__closure.lo  -MMD -MF yuga/3__closure.dep -MT yuga/3__closure.lo
-include yuga/4__closure.dep
yuga/4__closure.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/4__closure.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/4__closure.zep.c -o yuga/4__closure.lo  -MMD -MF yuga/4__closure.dep -MT yuga/4__closure.lo
-include yuga/5__closure.dep
yuga/5__closure.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/5__closure.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/5__closure.zep.c -o yuga/5__closure.lo  -MMD -MF yuga/5__closure.dep -MT yuga/5__closure.lo
-include yuga/6__closure.dep
yuga/6__closure.lo: /var/www/html/yuga-zephir/yuga/ext/yuga/6__closure.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/var/www/html/yuga-zephir/yuga/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /var/www/html/yuga-zephir/yuga/ext/yuga/6__closure.zep.c -o yuga/6__closure.lo  -MMD -MF yuga/6__closure.dep -MT yuga/6__closure.lo
$(phplibdir)/yuga.la: ./yuga.la
	$(LIBTOOL) --mode=install cp ./yuga.la $(phplibdir)

./yuga.la: $(shared_objects_yuga) $(YUGA_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) -shared $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS)  -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(EXTRA_LDFLAGS) $(shared_objects_yuga) $(YUGA_SHARED_LIBADD)

