/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _WIN32_UI_MODULE_H_
#define _WiN32_UI_MODULE_H_

namespace ti
{
    class Win32Menu;
    class Win32MenuItem;
}

#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <shellapi.h>
#include <shlwapi.h>
#include <cderr.h>
#include <comutil.h>
#include <commdlg.h>
#include <commctrl.h>
#include <shlobj.h>
#include <winbase.h>
#define FormatMessage FormatMessageW
#include <comdef.h>

#undef IsMaximized
#undef IsMinimized

#include <WebKit/WebKit.h>
#include <WebKit/WebKitCOMAPI.h>

#include <WebKit/WebKitTitanium.h>

#include <cairo/cairo.h>
#include <cairo/cairo-win32.h>
#include "../url/url.h"
#include "popup_dialog.h"
#include "webkit_frame_load_delegate.h"
#include "webkit_policy_delegate.h"
#include "webkit_ui_delegate.h"
#include "webkit_resource_load_delegate.h"
#include "win32_user_window.h"
#include "win32_menu.h"
#include "win32_menu_item.h"
#include "win32_tray_item.h"
#include "win32_ui_binding.h"
#endif
