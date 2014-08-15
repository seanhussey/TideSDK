/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _GTK_TRAY_ITEM_H_
#define _GTK_TRAY_ITEM_H_

namespace ti
{
    class GtkTrayItem : public TrayItem
    {

    public:
        GtkTrayItem(std::string& iconURL, TiMethodRef cb);
        ~GtkTrayItem();

        void SetIcon(std::string& iconPath);
        void SetMenu(AutoMenu menu);
        void SetHint(std::string& hint);
        void Remove();

        GtkStatusIcon* GetWidget();
        AutoPtr<GtkMenu> GetMenu();
        TiMethodRef GetCallback();

    protected:
        GtkStatusIcon* item;
        AutoPtr<GtkMenu> menu;
        TiMethodRef callback;
        bool active;
    };
}

#endif
