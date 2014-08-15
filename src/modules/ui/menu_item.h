/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _MENU_ITEM_H_
#define _MENU_ITEM_H_
#include <tide/tide.h>
namespace ti
{
    class MenuItem : public EventObject
    {
    public:
        enum MenuItemType
        {
            NORMAL,
            SEPARATOR,
            CHECK
        };

        MenuItem(MenuItemType type);
        ~MenuItem();

        void _IsSeparator(const ValueList& args, ValueRef result);
        void _IsCheck(const ValueList& args, ValueRef result);
        void _SetLabel(const ValueList& args, ValueRef result);
        void _GetLabel(const ValueList& args, ValueRef result);
        void _SetIcon(const ValueList& args, ValueRef result);
        void _GetIcon(const ValueList& args, ValueRef result);
        void _SetState(const ValueList& args, ValueRef result);
        void _GetState(const ValueList& args, ValueRef result);
        void _SetAutoCheck(const ValueList& args, ValueRef result);
        void _IsAutoCheck(const ValueList& args, ValueRef result);
        void _SetSubmenu(const ValueList& args, ValueRef result);
        void _GetSubmenu(const ValueList& args, ValueRef result);
        void _Enable(const ValueList& args, ValueRef result);
        void _Disable(const ValueList& args, ValueRef result);
        void _IsEnabled(const ValueList& args, ValueRef result);
        void _Click(const ValueList& args, ValueRef result);

        void _AddItem(const ValueList& args, ValueRef result);
        void _AddSeparatorItem(const ValueList& args, ValueRef result);
        void _AddCheckItem(const ValueList& args, ValueRef result);

        void SetLabel(string& label);
        std::string& GetLabel();
        void SetIcon(string& iconURL);
        bool GetState();
        void SetState(bool);
        bool IsSeparator();
        bool IsCheck();
        bool IsEnabled();
        virtual void HandleClickEvent(TiObjectRef source);
        void EnsureHasSubmenu();
        bool ContainsItem(MenuItem* item);
        bool ContainsSubmenu(Menu* submenu);

        // Platform-specific implementation
        virtual void SetLabelImpl(std::string newLabel) = 0;
        virtual void SetIconImpl(std::string newIconPath) = 0;
        virtual void SetStateImpl(bool newState) = 0;
        virtual void SetSubmenuImpl(AutoMenu newSubmenu) = 0;
        virtual void SetEnabledImpl(bool enabled) = 0;

    protected:
        MenuItemType type;
        bool enabled;
        std::string label;
        std::string iconURL;
        std::string iconPath;
        TiMethodRef callback;
        AutoMenu submenu;
        std::vector<TiMethodRef> eventListeners;
        bool state;
        bool autoCheck;
    };
}
#endif

