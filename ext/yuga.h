
/* This file was generated automatically by Zephir do not modify it! */

#ifndef ZEPHIR_CLASS_ENTRIES_H
#define ZEPHIR_CLASS_ENTRIES_H

#include "yuga/route/support/iroute.zep.h"
#include "yuga/route/router/route.zep.h"
#include "yuga/interfaces/providers/serviceproviderinterface.zep.h"
#include "yuga/route/support/iloadableroute.zep.h"
#include "yuga/providers/serviceprovider.zep.h"
#include "yuga/route/exceptions/httpexception.zep.h"
#include "yuga/route/router/loadableroute.zep.h"
#include "yuga/eventhandlers/handlerinterface.zep.h"
#include "yuga/exceptions/iexception.zep.h"
#include "yuga/interfaces/http/input/inputiteminterface.zep.h"
#include "yuga/interfaces/session/isession.zep.h"
#include "yuga/route/support/icontrollerroute.zep.h"
#include "yuga/container/container.zep.h"
#include "yuga/exceptions/routeexceptionhandler.zep.h"
#include "yuga/interfaces/application/application.zep.h"
#include "yuga/interfaces/events/dispatcherinterface.zep.h"
#include "yuga/route/support/igrouproute.zep.h"
#include "yuga/session/session.zep.h"
#include "yuga/app.zep.h"
#include "yuga/application/application.zep.h"
#include "yuga/autoloader.zep.h"
#include "yuga/booleantype.zep.h"
#include "yuga/carbon/carbon.zep.h"
#include "yuga/container/support/classnotinstantiableexception.zep.h"
#include "yuga/cookie/cookie.zep.h"
#include "yuga/csrftoken.zep.h"
#include "yuga/eventhandlers/applicationstart.zep.h"
#include "yuga/eventhandlers/applicationstop.zep.h"
#include "yuga/events/dispatcher/dispatcher.zep.h"
#include "yuga/events/event.zep.h"
#include "yuga/events/eventserviceprovider.zep.h"
#include "yuga/events/exceptions/eventexception.zep.h"
#include "yuga/guid.zep.h"
#include "yuga/http/exceptions/badformedurlexception.zep.h"
#include "yuga/http/input/input.zep.h"
#include "yuga/http/input/inputfile.zep.h"
#include "yuga/http/input/inputitem.zep.h"
#include "yuga/http/redirect.zep.h"
#include "yuga/http/request.zep.h"
#include "yuga/http/response.zep.h"
#include "yuga/http/uri.zep.h"
#include "yuga/pipeline/pipeline.zep.h"
#include "yuga/route/exceptions/annotationparseexception.zep.h"
#include "yuga/route/exceptions/annotationtargetexception.zep.h"
#include "yuga/route/exceptions/notfoundhttpcontrollerexception.zep.h"
#include "yuga/route/exceptions/notfoundhttpexception.zep.h"
#include "yuga/route/exceptions/notfoundhttpexceptionhandler.zep.h"
#include "yuga/route/exceptions/notfoundhttpmethodexception.zep.h"
#include "yuga/route/route.zep.h"
#include "yuga/route/routeserviceprovider.zep.h"
#include "yuga/route/router.zep.h"
#include "yuga/route/router/routecontroller.zep.h"
#include "yuga/route/router/routegroup.zep.h"
#include "yuga/route/router/routeresource.zep.h"
#include "yuga/route/router/routeurl.zep.h"
#include "yuga/route/support/irouterbootmanager.zep.h"
#include "yuga/session/messagebag.zep.h"
#include "yuga/session/sessionserviceprovider.zep.h"
#include "yuga/support/config.zep.h"
#include "yuga/support/helpers.zep.h"
#include "yuga/support/str.zep.h"
#include "yuga/0__closure.zep.h"
#include "yuga/1__closure.zep.h"
#include "yuga/2__closure.zep.h"
#include "yuga/3__closure.zep.h"
#include "yuga/4__closure.zep.h"
#include "yuga/5__closure.zep.h"
#include "yuga/6__closure.zep.h"
#include "yuga/7__closure.zep.h"
#include "yuga/8__closure.zep.h"
#include "yuga/9__closure.zep.h"
#include "yuga/10__closure.zep.h"

#endif