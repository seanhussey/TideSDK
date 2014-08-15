/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../ui_module.h"

namespace ti
{

    void TrayClickedCallback(GtkStatusIcon*, gpointer);
    void TrayMenuCallback(GtkStatusIcon*, guint, guint, gpointer);

    GtkTrayItem::GtkTrayItem(std::string& iconURL, TiMethodRef cb) :
        TrayItem(iconURL),
        item(gtk_status_icon_new()),
        menu(0),
        callback(cb),
        active(true)
    {
        g_signal_connect(
            G_OBJECT(this->item), "activate",
            G_CALLBACK(TrayClickedCallback), this);
        g_signal_connect(
            G_OBJECT(this->item), "popup-menu",
            G_CALLBACK(TrayMenuCallback), this);

        this->SetIcon(this->iconPath);
        gtk_status_icon_set_visible(this->item, TRUE);
    }

    GtkTrayItem::~GtkTrayItem()
    {
    }

    void GtkTrayItem::SetIcon(std::string& iconPath)
    {
        if (active) {
            if (iconPath.empty()) {
                gtk_status_icon_set_from_file(this->item, NULL);
            } else {
                gtk_status_icon_set_from_file(this->item, iconPath.c_str());
            }
        }
    }

    void GtkTrayItem::SetMenu(AutoMenu menu)
    {
        this->menu = menu.cast<GtkMenu>();
    }

    void GtkTrayItem::SetHint(std::string& hint)
    {
        if (active) {
            if (hint.empty()) {
                gtk_status_icon_set_tooltip(this->item, NULL);
            } else {
                gtk_status_icon_set_tooltip(this->item, hint.c_str());
            }
        }
    }

    void GtkTrayItem::Remove()
    {
        if (active) {
            this->active = false;
            g_object_unref(this->item);
        }
    }

    GtkStatusIcon* GtkTrayItem::GetWidget()
    {
        if (active)
            return this->item;
        else
            return NULL;
    }

    AutoPtr<GtkMenu> GtkTrayItem::GetMenu()
    {
        return this->menu;
    }

    TiMethodRef GtkTrayItem::GetCallback()
    {
        return this->callback;
    }

    void TrayClickedCallback(GtkStatusIcon *status_icon, gpointer data)
    {
        GtkTrayItem* item = static_cast<GtkTrayItem*>(data);
        TiMethodRef cb = item->GetCallback();

        if (cb.isNull())
            return;

        try {
            ValueList args;
            cb->Call(args);

        } catch (ValueException& e) {
            Logger* logger = Logger::Get("UI.GtkTrayItem");
            SharedString ss = e.DisplayString();
            logger->Error("Tray icon callback failed: %s", ss->c_str());
        }
    }

    void TrayMenuCallback(
        GtkStatusIcon *status_icon, guint button,
        guint activate_time, gpointer data)
    {
        GtkTrayItem* item = static_cast<GtkTrayItem*>(data);
        GtkStatusIcon* trayWidget = item->GetWidget();
        AutoPtr<GtkMenu> menu = item->GetMenu();

        if (!menu.isNull()) {
            ::GtkMenu* nativeMenu = (::GtkMenu*) menu->CreateNative(false);
            gtk_menu_popup(
                nativeMenu, NULL, NULL,
                gtk_status_icon_position_menu,
                trayWidget, button, activate_time);
        }
    }
}
