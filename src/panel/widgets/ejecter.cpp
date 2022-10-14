#include <glibmm.h>
#include "ejecter.hpp"

void WayfireEjecter::bar_pos_changed_cb (void)
{
    if ((std::string) bar_pos == "bottom") ej->bottom = TRUE;
    else ej->bottom = FALSE;
}

void WayfireEjecter::icon_size_changed_cb (void)
{
    ej->icon_size = icon_size;
    ej_update_display (ej);
}

gboolean set_icon (EjecterPlugin *ej)
{
    ej_update_display (ej);
    return FALSE;
}

void WayfireEjecter::init (Gtk::HBox *container)
{
    /* Create the button */
    plugin = std::make_unique <Gtk::Button> ();
    container->pack_start (*plugin, false, false);

    /* Setup structure */
    ej = &data;
    ej->plugin = (GtkWidget *)((*plugin).gobj());
    ej->icon_size = icon_size;
    g_idle_add (G_SOURCE_FUNC (set_icon), ej);
    bar_pos_changed_cb ();

    /* Initialise the plugin */
    ej_init (ej);

    /* Setup callbacks */
    icon_size.set_callback (sigc::mem_fun (*this, &WayfireEjecter::icon_size_changed_cb));
    bar_pos.set_callback (sigc::mem_fun (*this, &WayfireEjecter::bar_pos_changed_cb));
}

WayfireEjecter::~WayfireEjecter()
{
}
