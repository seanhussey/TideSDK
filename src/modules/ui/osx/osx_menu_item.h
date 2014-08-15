/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _OSX_MENU_ITEM_H_
#define _OSX_MENU_ITEM_H_
namespace ti
{
    class OSXMenuItem : public MenuItem
    {
    public:
        OSXMenuItem(MenuItemType type);
        virtual ~OSXMenuItem();

        void SetLabelImpl(std::string newLabel);
        void SetIconImpl(std::string newIconPath);
        void SetStateImpl(bool newState);
        void SetCallbackImpl(TiMethodRef callback);
        void SetSubmenuImpl(AutoMenu newSubmenu);
        void SetEnabledImpl(bool enabled);

        NSMenuItem* CreateNative(bool registerNative=true);
        void DestroyNative(NSMenuItem* realization);
        void UpdateNativeMenuItems();
        virtual void HandleClickEvent(TiObjectRef source);

    private:
        static void SetNSMenuItemTitle(NSMenuItem* item, std::string& title);
        static void SetNSMenuItemState(NSMenuItem* item, bool state);
        static void SetNSMenuItemIconPath(
            NSMenuItem* item, std::string& iconPath, NSImage* image = nil);
        static void SetNSMenuItemSubmenu(
            NSMenuItem* item, AutoMenu submenu, bool registerNative=true);
        static void SetNSMenuItemEnabled(NSMenuItem* item, bool enabled);

        std::vector<NSMenuItem*> nativeItems;
    };
}
#endif
