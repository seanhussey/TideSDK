/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _TRAY_ITEM_H_
#define _TRAY_ITEM_H_

#include <tide/tide.h>
#include "menu_item.h"

namespace ti
{
    class TrayItem : public EventObject
    {

    public:
        TrayItem(std::string& iconURL);
        ~TrayItem();

        virtual void SetIcon(std::string& iconPath) = 0;
        virtual void SetMenu(AutoMenu menu) = 0;
        virtual void SetHint(std::string& hint) = 0;
        virtual void Remove() = 0;

        void _SetIcon(const ValueList& args, ValueRef result);
        void _SetMenu(const ValueList& args, ValueRef result);
        void _SetHint(const ValueList& args, ValueRef result);
        void _GetIcon(const ValueList& args, ValueRef result);
        void _GetMenu(const ValueList& args, ValueRef result);
        void _GetHint(const ValueList& args, ValueRef result);
        void _Remove(const ValueList& args, ValueRef result);

    protected:
        AutoMenu menu;
        std::string iconURL;
        std::string iconPath;
        std::string hint;
        bool removed;
    };
}

#endif
