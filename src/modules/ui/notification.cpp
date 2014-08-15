/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "notification.h"

namespace ti
{

Notification::Notification() : AccessorObject("Notification"),
    timeout(-1)
{
    SetMethod("setTitle", &Notification::_SetTitle);
    SetMethod("setMessage", &Notification::_SetMessage);
    SetMethod("setIcon", &Notification::_SetIcon);
    SetMethod("setTimeout", &Notification::_SetTimeout);
    SetMethod("setDelay", &Notification::_SetTimeout);
    SetMethod("show", &Notification::_Show);
    SetMethod("hide", &Notification::_Hide);

    SetBool("nativeNotifications", Notification::InitializeImpl());
    this->CreateImpl();
}

Notification::~Notification()
{
    this->DestroyImpl();
}

void Notification::_SetTitle(const ValueList& args, ValueRef result)
{
    args.VerifyException("setTitle", "s");
    this->title = args.GetString(0);
}

void Notification::_SetMessage(const ValueList& args, ValueRef result)
{
    args.VerifyException("setMessage", "s");
    this->message = args.GetString(0);
}

void Notification::_SetIcon(const ValueList& args, ValueRef result)
{
    args.VerifyException("setIcon", "s");
    this->iconURL = args.GetString(0);
}

void Notification::_SetTimeout(const ValueList& args, ValueRef result)
{
    args.VerifyException("setTimeout", "i");
    this->timeout = args.GetInt(0);
}

void Notification::_Show(const ValueList& args, ValueRef result)
{
    result->SetBool(this->ShowImpl());
}

void Notification::_Hide(const ValueList& args, ValueRef result)
{
    result->SetBool(this->HideImpl());
}

void Notification::Configure(TiObjectRef properties)
{
    this->title = properties->GetString("title");
    this->message = properties->GetString("message");
    this->iconURL = properties->GetString("icon");
    this->timeout = properties->GetInt("timeout", -1);
}

}
