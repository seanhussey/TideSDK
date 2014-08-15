/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _OSX_UI_BINDING_H_
#define _OSX_UI_BINDING_H_
#include <tide/tide.h>
#include "../ui_module.h"
namespace ti
{
    class OSXMenuItem;
    class OSXUIBinding : public UIBinding
    {

        public:
        OSXUIBinding(Host *host);
        ~OSXUIBinding();

        AutoMenu CreateMenu();
        AutoMenuItem CreateMenuItem();
        AutoMenuItem CreateCheckMenuItem();
        AutoMenuItem CreateSeparatorMenuItem();
        AutoMenu GetMenu();
        AutoMenu GetContextMenu();
        AutoMenu GetDockMenu();
        NSMenu* GetNativeDockMenu();
        void SetMenu(AutoMenu);
        void SetContextMenu(AutoMenu);
        void SetDockMenu(AutoMenu);

        AutoTrayItem AddTray(std::string& icon_path, TiMethodRef cb);
        void SetIcon(std::string& iconPath);
        virtual void SetDockIcon(std::string& iconPath);
        virtual void SetBadge(std::string& badgeLabel);
        virtual void SetBadgeImage(std::string& badgeImage);

        AutoPtr<OSXMenu> GetActiveMenu();
        void WindowFocused(AutoPtr<OSXUserWindow> window);
        void WindowUnfocused(AutoPtr<OSXUserWindow> window);
        void SetupMainMenu(bool force = false);
        void SetupAppMenuParts(NSMenu* mainMenu);
        void ReplaceMainMenu();
        NSMenu* GetDefaultMenu();
        long GetIdleTime();

        static NSImage* MakeImage(std::string&);
        static void ErrorDialog(std::string);

    protected:
        NSMenu* defaultMenu;
        AutoPtr<OSXMenu> menu;
        NSMenu* nativeMenu;
        AutoPtr<OSXMenu> contextMenu;
        AutoPtr<OSXMenu> dockMenu;
        NSMenu* nativeDockMenu;
        NSView *savedDockView;
        NSObject* application;
        AutoPtr<OSXMenu> activeMenu;
        AutoPtr<OSXUserWindow> activeWindow;

        void InstallMenu (OSXMenuItem*);
    };
}

#endif
