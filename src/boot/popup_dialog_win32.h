/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#ifndef KRBOOT_POPUP_DIALOG_H_
#define KRBOOT_POPUP_DIALOG_H_

#include <windows.h>
#include <string>
#include <map>

#define MAX_INPUT_LENGTH 1024

namespace TideBoot {

    class Win32PopupDialog {
    
    public:
        Win32PopupDialog(HWND _windowHandle);
        virtual ~Win32PopupDialog();

        void SetShowInputText(bool flag) { this->showInputText = flag; }
        void SetTitle(std::string _title) { this->title = _title; }
        void SetMessage(std::string _message) { this->message = _message; }
        void SetInputText(std::string _inputText) { this->inputText = _inputText; }
        std::string GetInputText() { return this->inputText; }
        void SetShowCancelButton(bool flag) { this->showCancelButton = flag; }

        int Show();
    
    private:
        HWND windowHandle;

        bool showInputText;
        std::string title;
        std::string message;
        std::string inputText;
        bool showCancelButton;
        int result;

        BOOL ShowMessageBox(HWND hwnd);

        static std::map<DWORD, Win32PopupDialog*> popups;

        static void HandleOKClick(HWND hDlg);
        static INT_PTR CALLBACK CALLBACK Callback(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
    };

}

#endif /* TI_POPUP_DIALOG_H_ */
