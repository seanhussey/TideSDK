/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _GTK_MENU_ITEM_H_
#define _GTK_MENU_ITEM_H_
namespace ti
{
    class GtkMenuItem : public MenuItem
    {
    public:
        GtkMenuItem(MenuItemType type);
        virtual ~GtkMenuItem();

        void SetLabelImpl(std::string newLabel);
        void SetIconImpl(std::string newIconPath);
        void SetStateImpl(bool newState);
        void SetCallbackImpl(TiMethodRef callback);
        void SetSubmenuImpl(AutoMenu newSubmenu);
        void SetEnabledImpl(bool enabled);

        void ReplaceNativeItem(::GtkMenuItem* nativeItem, ::GtkMenuItem* newNativeItem);
        void SetNativeItemIcon(::GtkMenuItem* nativeItem, std::string& newIconPath);
        void SetNativeItemSubmenu(::GtkMenuItem* nativeItem, AutoMenu newSubmenu);
        ::GtkMenuItem* CreateNative(bool registerNative);
        void DestroyNative(::GtkMenuItem* nativeItem);

    private:
        std::vector< ::GtkMenuItem* > nativeItems;
        AutoPtr<GtkMenu> oldSubmenu;
    };
}

#endif
