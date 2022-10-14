#include <glibmm.h>
#include "smenu.hpp"

void WayfireSmenu::bar_pos_changed_cb (void)
{
    if ((std::string) bar_pos == "bottom") m->bottom = TRUE;
    else m->bottom = FALSE;
}

void WayfireSmenu::icon_size_changed_cb (void)
{
    m->icon_size = icon_size;
    menu_update_display (m);
}

gboolean set_icon (MenuPlugin *m)
{
    menu_update_display (m);
    return FALSE;
}

void WayfireSmenu::init (Gtk::HBox *container)
{
    /* Create the button */
    plugin = std::make_unique <Gtk::Button> ();
    container->pack_start (*plugin, false, false);

    /* Setup structure */
    m = &data;
    m->plugin = (GtkWidget *)((*plugin).gobj());
    m->icon_size = icon_size;
    g_idle_add (G_SOURCE_FUNC (set_icon), m);
    bar_pos_changed_cb ();

    /* Initialise the plugin */
    menu_init (m);

    /* Setup callbacks */
    icon_size.set_callback (sigc::mem_fun (*this, &WayfireSmenu::icon_size_changed_cb));
    bar_pos.set_callback (sigc::mem_fun (*this, &WayfireSmenu::bar_pos_changed_cb));
}

WayfireSmenu::~WayfireSmenu()
{
}
