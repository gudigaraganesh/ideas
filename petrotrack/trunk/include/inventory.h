#ifndef _INVENTORY_H
#define _INVENTORY_H
#include<gtk/gtk.h>





void create_report ();

static void hide_dialog (GtkWidget * w, gpointer data);







static void append_text (GtkWidget * w, gpointer data);

static void enter_callback (GtkWidget * widget, gpointer data);

static void toggle_activity_mode (GtkWidget * widget, gpointer data);

static void dialog (GtkWidget * widget, gpointer data);

static GtkWidget *create_list (void);

void create_inventory ();

#endif /*_INVENTORY_H */
