/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _UI_MODULE_GTK_H_
#define _UI_MODULE_GTK_H_

#include <tide/tide.h>

using tide::Value;
using tide::TiObject;
using tide::StaticBoundObject;
using tide::TiMethod;
using tide::StaticBoundMethod;
using tide::TiList;
using tide::StaticBoundList;

#include <gdk/gdk.h>
#include <gdk/gdkx.h>
#include <webkit/webkit.h>

#ifndef TIDE_LITE
#include <webkit/webkittitanium.h>
#endif

// X11 defines this again for some reason
#undef DisplayString

#include "gtk_menu.h"
#include "gtk_menu_item.h"
#include "gtk_user_window.h"
#include "gtk_tray_item.h"
#include "gtk_ui_binding.h"

#endif
