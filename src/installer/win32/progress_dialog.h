/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <windows.h>
#include <shlobj.h>
#include <shlguid.h>
#include <string>

class ProgressDialog
{
public:
    ProgressDialog();
    ~ProgressDialog();

    void SetTitle(const std::wstring& title);
    void SetCancelMessage(const std::wstring& message);
    void SetLineText(DWORD line, const std::wstring& message, bool compact);
    void Update(DWORD value, DWORD max);
    void Show();
    void Hide();
    bool IsCancelled();
    HWND GetWindowHandle() { return this->dialogWindow; }

private:
    IProgressDialog* dialog;
    HWND dialogWindow;
};
