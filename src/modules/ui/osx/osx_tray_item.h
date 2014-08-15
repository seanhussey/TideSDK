/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef TI_OSX_TRAY_ITEM_H_
#define TI_OSX_TRAY_ITEM_H_
namespace ti
{
    class OSXTrayItem: public TrayItem
    {
    public:
        OSXTrayItem(std::string& iconURL, TiMethodRef cb);
        virtual ~OSXTrayItem();

        void SetIcon(std::string& iconPath);
        void SetMenu(AutoMenu menu);
        void SetHint(std::string& hint);
        void Remove();
        void InvokeCallback();

    private:
        NSMenu* nativeMenu;
        AutoPtr<OSXMenu> menu;
        TiMethodRef callback;
        NSStatusItem* nativeItem;
    };
}

#endif
