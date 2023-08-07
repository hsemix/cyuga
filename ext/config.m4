PHP_ARG_ENABLE(yuga, whether to enable yuga, [ --enable-yuga   Enable Yuga])

if test "$PHP_YUGA" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, YUGA_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_YUGA, 1, [Whether you have Yuga])
	yuga_sources="yuga.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c yuga/route/support/iroute.zep.c
	yuga/route/router/route.zep.c
	yuga/route/support/iloadableroute.zep.c
	yuga/interfaces/providers/serviceproviderinterface.zep.c
	yuga/route/exceptions/httpexception.zep.c
	yuga/route/router/loadableroute.zep.c
	yuga/eventhandlers/handlerinterface.zep.c
	yuga/exceptions/iexception.zep.c
	yuga/interfaces/http/input/inputiteminterface.zep.c
	yuga/providers/serviceprovider.zep.c
	yuga/route/support/icontrollerroute.zep.c
	yuga/container/container.zep.c
	yuga/exceptions/routeexceptionhandler.zep.c
	yuga/interfaces/application/application.zep.c
	yuga/interfaces/events/dispatcherinterface.zep.c
	yuga/route/support/igrouproute.zep.c
	yuga/app.zep.c
	yuga/application/application.zep.c
	yuga/autoloader.zep.c
	yuga/booleantype.zep.c
	yuga/container/support/classnotinstantiableexception.zep.c
	yuga/cookie/cookie.zep.c
	yuga/csrftoken.zep.c
	yuga/eventhandlers/applicationstart.zep.c
	yuga/eventhandlers/applicationstop.zep.c
	yuga/events/dispatcher/dispatcher.zep.c
	yuga/events/event.zep.c
	yuga/events/eventserviceprovider.zep.c
	yuga/events/exceptions/eventexception.zep.c
	yuga/guid.zep.c
	yuga/http/exceptions/badformedurlexception.zep.c
	yuga/http/input/input.zep.c
	yuga/http/input/inputfile.zep.c
	yuga/http/input/inputitem.zep.c
	yuga/http/redirect.zep.c
	yuga/http/request.zep.c
	yuga/http/response.zep.c
	yuga/http/uri.zep.c
	yuga/route/exceptions/annotationparseexception.zep.c
	yuga/route/exceptions/annotationtargetexception.zep.c
	yuga/route/exceptions/notfoundhttpcontrollerexception.zep.c
	yuga/route/exceptions/notfoundhttpexception.zep.c
	yuga/route/exceptions/notfoundhttpexceptionhandler.zep.c
	yuga/route/exceptions/notfoundhttpmethodexception.zep.c
	yuga/route/route.zep.c
	yuga/route/routeserviceprovider.zep.c
	yuga/route/router.zep.c
	yuga/route/router/routecontroller.zep.c
	yuga/route/router/routegroup.zep.c
	yuga/route/router/routeresource.zep.c
	yuga/route/router/routeurl.zep.c
	yuga/route/support/irouterbootmanager.zep.c
	yuga/support/helpers.zep.c
	yuga/support/str.zep.c
	yuga/0__closure.zep.c
	yuga/1__closure.zep.c
	yuga/2__closure.zep.c
	yuga/3__closure.zep.c
	yuga/4__closure.zep.c
	yuga/5__closure.zep.c
	yuga/6__closure.zep.c "
	PHP_NEW_EXTENSION(yuga, $yuga_sources, $ext_shared,, )
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	for dir in "yuga yuga/application yuga/container yuga/container/support yuga/cookie yuga/eventhandlers yuga/events yuga/events/dispatcher yuga/events/exceptions yuga/exceptions yuga/http yuga/http/exceptions yuga/http/input yuga/interfaces/application yuga/interfaces/events yuga/interfaces/http/input yuga/interfaces/providers yuga/providers yuga/route yuga/route/exceptions yuga/route/router yuga/route/support yuga/support"; do
		PHP_ADD_BUILD_DIR([$ext_builddir/$dir])
	done
	PHP_SUBST(YUGA_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([yuga], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([yuga], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/yuga], [php_YUGA.h])

fi
