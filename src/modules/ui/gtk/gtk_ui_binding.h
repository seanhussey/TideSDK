/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _GTK_UI_BINDING_H_
#define _GTK_UI_BINDING_H_

#include "../ui_module.h"

namespace ti
{
    class GtkUIBinding : public UIBinding
    {

        public:
        GtkUIBinding(Host* host);

        AutoMenu CreateMenu();
        AutoMenuItem CreateMenuItem();
        AutoMenuItem CreateSeparatorMenuItem();
        AutoMenuItem CreateCheckMenuItem();
        void SetMenu(AutoMenu newMenu);
        void SetContextMenu(AutoMenu);
        void SetIcon(std::string&);
        AutoTrayItem AddTray(std::string&, TiMethodRef cb);
        long GetIdleTime();
        AutoMenu GetMenu();
        AutoMenu GetContextMenu();
        std::string& GetIcon();

        static void ErrorDialog(std::string);

        protected:
#ifndef TIDE_LITE
        SharedPtr<ScriptEvaluator> evaluator;
#endif
        AutoPtr<GtkMenu> menu;
        AutoPtr<GtkMenu> contextMenu;
        std::string iconPath;
    };
}

#endif
