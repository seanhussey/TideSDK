/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _UI_MODULE_H_
#define _UI_MODULE_H_

#include <tide/tide.h>

namespace ti {
    class UIBinding;
    class Menu;
    class MenuItem;
    class TrayItem;
    class UserWindow;

    typedef AutoPtr<UserWindow> AutoUserWindow;
    typedef AutoPtr<UIBinding> AutoUIBinding;
    typedef AutoPtr<Menu> AutoMenu;
    typedef AutoPtr<MenuItem> AutoMenuItem;
    typedef AutoPtr<TrayItem> AutoTrayItem;
}

#include <JavaScriptCore/JSObjectRef.h>
#include <JavaScriptCore/JSStringRef.h>
#include <JavaScriptCore/JSContextRef.h>

#include <iostream>
#include <tide/javascript/javascript_module.h>
#include "window_config.h"
#include "user_window.h"
#include "menu.h"
#include "menu_item.h"
#include "tray_item.h"
#include "ui_binding.h"

#ifndef TIDE_LITE
#include "lang_binding/script_evaluator.h"
#endif

#include "clipboard.h"

#ifdef OS_LINUX
#include "gtk/ui_module_gtk.h"
#elif defined(OS_OSX)
#include "osx/ui_module_osx.h"
#elif defined(OS_WIN32)
#include "win32/ui_module_win32.h"
#endif

#include "url/url.h"

namespace ti {

    class UIModule : public tide::Module
    {
        TIDE_MODULE_CLASS(UIModule)

        public:
        static UIModule* GetInstance() { return instance_; }
        AutoUIBinding GetUIBinding() { return uiBinding; }
        void Start();
        static bool IsResourceLocalFile(std::string string);

        protected:
        DISALLOW_EVIL_CONSTRUCTORS(UIModule);
        static UIModule* instance_;
        AutoUIBinding uiBinding;

    };
}

#endif
