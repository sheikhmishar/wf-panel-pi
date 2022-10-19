#include "../lxutils.h"

/*----------------------------------------------------------------------------*/
/* Plug-in global data                                                        */
/*----------------------------------------------------------------------------*/

typedef struct {

    GtkWidget *plugin;              /* Back pointer to the widget */
    //LXPanel *panel;                 /* Back pointer to panel */
    GtkWidget *tray_icon;           /* Displayed image */
    //config_setting_t *settings;     /* Plugin settings */
    int icon_size;                      /* Variables used under wf-panel */
    gboolean bottom;
    GtkWidget *menu;                /* Popup menu */
    GtkWidget *update_dlg;          /* Widget used to display pending update list */
    int n_updates;                  /* Number of pending updates */
    gchar **ids;                    /* ID strings for pending updates */
    int interval;                   /* Number of hours between periodic checks */
    guint timer;                    /* Periodic check timer ID */
} UpdaterPlugin;

extern void updater_init (UpdaterPlugin *up);
extern void updater_update_display (UpdaterPlugin *up);

