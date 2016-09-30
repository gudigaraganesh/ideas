/*               File        : events.h
 *               Description : 
 *
 *
 *
 *
 *
 *
 *               Author        :
 *
 *
 *
 *               Copyright      :
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */



#ifndef _EVENTS_H
#define _EVENTS_H

#include <gtk/gtk.h>



/* */

void on_dbwin_show (GtkWidget * widget, gpointer user_data);

gboolean
on_dbwin_delete_event (GtkWidget * widget,
		       GdkEvent * event, gpointer user_data);



gboolean
delete_mainwindow (GtkWidget * widget, GdkEvent * event, gpointer data);

extern GtkWidget *dbwin;
#endif /*_EVENTS_H */
