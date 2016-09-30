/*
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


#include <globaldef.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <events.h>
#include <uicontrol.h>
#include <support.h>
#include <database.h>
#include <inventory.h>
#include <glib.h>
#include <database.h>



GtkWidget *window;

int
main (int argc, char *argv[])
{
  GtkWidget *dbobject;
  gint width=600;
  gint height=400;

  set_dbserver (SERVERNAME);
  set_dbuser (USERNAME);
  set_dbpassword (PASSWORD);
  set_dbname (DBNAME);
  set_tablename (TABLENAME, 0);

  /* Initialize GTK */
  gtk_init (&argc, &argv);


  get_screensize (&width, &height);
  fprintf(stderr,"%d %d\n",width,height);
  width=600;
  height=400;
  window=create_mainwindow (PRODNAME, width,
		     height);
  create_frontdisplay (DBTITLE,CUSTOMERLOGO,window,width,height);
  DPRINT("show all windows\n");
  gtk_widget_show_all (window);

  /* call continuous loop */
  gtk_main ();

  return 0;
}


/********************************* End ****************************************/
