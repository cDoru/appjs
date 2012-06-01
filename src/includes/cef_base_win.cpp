#include "include/cef_app.h"
#include "includes/cef_handler.h"
#include "includes/cef_base_win.h"

extern CefRefPtr<ClientHandler> g_handler;

namespace appjs {

void CefBase::Init() {

};

void CefBase::AddWebView(CefWindowHandle hWndParent,RECT windowRect,char* url,Settings* settings) {

  CefWindowInfo window_info;
  CefBrowserSettings browserSettings;

  browser_settings.web_security_disabled = settings->getBoolean("disableSecurity",false);

  window_info.SetAsChild(hWndParent, windowRect);

  CefBrowser::CreateBrowserSync(window_info,
                                static_cast<CefRefPtr<CefClient> >(g_handler),
                                url, browserSettings);

}

} /* appjs */

