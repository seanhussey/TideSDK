/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _WIN32_MENU_H_
#define _WIN32_MENU_H_
namespace ti
{
    class Win32Menu : public Menu
    {
        public:
        Win32Menu();
        ~Win32Menu();

        void AppendItemImpl(AutoMenuItem item);
        void InsertItemAtImpl(AutoMenuItem item, unsigned int index);
        void RemoveItemAtImpl(unsigned int index);
        void ClearImpl();

        void ClearNativeMenu(HMENU nativeMenu);
        void DestroyNative(HMENU nativeMenu);
        HMENU CreateNative(bool registerNative);
        HMENU CreateNativeTopLevel(bool registerNative);
        void AddChildrenToNativeMenu(HMENU nativeMenu, bool registerNative);

        static void InsertItemIntoNativeMenu(
            Win32MenuItem* menuItem, HMENU nativeMenu,
            bool registerNative, int position=-1);
        static void RemoveItemAtFromNativeMenu(
            Win32MenuItem* item, HMENU nativeMenu, int position);
        static void ApplyNotifyByPositionStyleToNativeMenu(HMENU nativeMenu);

        private:
        std::vector<AutoMenuItem> oldChildren;
        std::vector<HMENU> nativeMenus;
    };
}
#endif
