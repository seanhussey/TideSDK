/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _MENU_H_
#define _MENU_H_
#include <tide/tide.h>
namespace ti
{
    class Menu : public AccessorObject
    {
    public:
        // Platform-independent implementation
        Menu();
        ~Menu();

        void _AppendItem(const ValueList& args, ValueRef result);
        void _GetItemAt(const ValueList& args, ValueRef result);
        void _InsertItemAt(const ValueList& args, ValueRef result);
        void _RemoveItemAt(const ValueList& args, ValueRef result);
        void _GetLength(const ValueList& args, ValueRef result);
        void _Clear(const ValueList& args, ValueRef result);

        void _AddItem(const ValueList& args, ValueRef result);
        void _AddSeparatorItem(const ValueList& args, ValueRef result);
        void _AddCheckItem(const ValueList& args, ValueRef result);

        void AppendItem(AutoMenuItem item);
        AutoMenuItem GetItemAt(int index);
        void InsertItemAt(AutoMenuItem item, size_t index);
        void RemoveItemAt(size_t index);
        bool ContainsItem(MenuItem* item);
        bool ContainsSubmenu(Menu* submenu);

        // Platform-specific implementation
        virtual void AppendItemImpl(AutoMenuItem item) = 0;
        virtual void InsertItemAtImpl(AutoMenuItem item, unsigned int index) = 0;
        virtual void RemoveItemAtImpl(unsigned int index) = 0;
        virtual void ClearImpl() = 0;

    protected:
        std::vector<AutoMenuItem> children;
    };
}
#endif
