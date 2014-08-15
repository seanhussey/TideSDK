/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _TI_WEB_KIT_POLICY_DELEGATE_H_
#define _TI_WEB_KIT_POLICY_DELEGATE_H_
#include <windows.h>
namespace ti {

class Win32UserWindow;

class Win32WebKitPolicyDelegate : public IWebPolicyDelegate {
public:
    Win32WebKitPolicyDelegate(Win32UserWindow *window_);

    // These function declarations copied from WebKit source (PolicyDelegate.cpp)

    // IUnknown
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject);
    virtual ULONG STDMETHODCALLTYPE AddRef(void);
    virtual ULONG STDMETHODCALLTYPE Release(void);

    // IWebPolicyDelegate
    virtual HRESULT STDMETHODCALLTYPE decidePolicyForNavigationAction(
        /* [in] */ IWebView *webView,
        /* [in] */ IPropertyBag *actionInformation,
        /* [in] */ IWebURLRequest *request,
        /* [in] */ IWebFrame *frame,
        /* [in] */ IWebPolicyDecisionListener *listener);

    virtual HRESULT STDMETHODCALLTYPE decidePolicyForNewWindowAction(
        /* [in] */ IWebView *webView,
        /* [in] */ IPropertyBag *actionInformation,
        /* [in] */ IWebURLRequest *request,
        /* [in] */ BSTR frameName,
        /* [in] */ IWebPolicyDecisionListener *listener);

    virtual HRESULT STDMETHODCALLTYPE decidePolicyForMIMEType(
        /* [in] */ IWebView *webView,
        /* [in] */ BSTR type,
        /* [in] */ IWebURLRequest *request,
        /* [in] */ IWebFrame *frame,
        /* [in] */ IWebPolicyDecisionListener *listener);

    virtual HRESULT STDMETHODCALLTYPE unableToImplementPolicyWithError(
        /* [in] */ IWebView *webView,
        /* [in] */ IWebError *error,
        /* [in] */ IWebFrame *frame);

    // PolicyDelegate
    void setPermissive(bool permissive) { m_permissiveDelegate = permissive; }

private:
    ULONG m_refCount;
    Win32UserWindow *window;
    bool m_permissiveDelegate;
};

}

#endif /* _TI_WEB_KIT_POLICY_DELEGATE_H_ */
