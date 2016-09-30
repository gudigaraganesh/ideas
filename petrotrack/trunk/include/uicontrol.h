



#ifndef _UICONTROL_H
#define _UICONTROL_H
#include<gtk/gtk.h>

#define MAXBUTTONS 10
GtkWidget *create_dbwin (char *title, int width,
			 int height);

void reinitialize_dbwin (GtkWidget * dbwidget);
void recreate_dbobject (GtkWidget * dbparent, GtkWidget * dbobj,
			int tableindex);
GtkWidget *get_toolbar (GtkWidget * window);
GtkWidget *get_menubar_menu (GtkWidget * window);

void get_screensize (gint * width, gint * height);
GtkWidget *create_mainwindow (
			      char *prodname, int width, int height);
void
create_frontdisplay (char *dbtitle,char *customerlogo, GtkWidget * window, int width,
		     int height);
#endif /*_UICONTROL_H */
