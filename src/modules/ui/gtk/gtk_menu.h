/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _GTK_MENU_H_
#define _GTK_MENU_H_
namespace ti
{
    class GtkMenu : public Menu
    {
    public:
        GtkMenu();
        ~GtkMenu();

        void AppendItemImpl(AutoMenuItem item);
        void InsertItemAtImpl(AutoMenuItem item, unsigned int index);
        void RemoveItemAtImpl(unsigned int index);
        void ClearImpl();

        void ClearNativeMenu(::GtkMenuShell* nativeMenu);
        void RemoveItemAtFromNativeMenu(::GtkMenuShell* nativeMenu, unsigned int index);
        void DestroyNative(::GtkMenuShell* nativeMenu);
        GtkMenuShell* CreateNativeBar(bool registerNative);
        ::GtkMenuShell* CreateNative(bool registerNative);
        void AddChildrenToNativeMenu(::GtkMenuShell* nativeMenu, bool registerNative);
        void RegisterNativeMenuItem(AutoMenuItem item, ::GtkMenuItem* nativeItem);
        void DestroyNativeMenuItem(::GtkMenuItem* nativeItem);

    private:
        std::vector<AutoMenuItem> oldChildren;
        std::vector< ::GtkMenuShell* > nativeMenus;
    };
}

#endif
