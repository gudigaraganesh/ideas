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
 */

#include <globaldef.h>
#include <gtk/gtk.h>
#include <mysql.h>
#include <events.h>
#include <database.h>
#include <uicontrol.h>


/*
 *      Function    : on_dbwin_show
 *      Description : this function is a callback
 *                    function which handles show event
 *                    for creating database window and
 *                    gets updated data from mysql database. 
 *	Arguments   : database window widget
 *		      user data if any.
 *		      
 *      Return      : none
 *
 *
 *
 */

void
on_dbwin_show (GtkWidget * widget, gpointer user_data)
{
  int tbindex = 0;
  MYSQL *sqlconn;
  GtkWidget *dbobject;



  if (create_connection (sqlconn) < 0)
    {
      feedback_msg (ERROR, MSGCONNFAILED);
      return;
    }
  close_connection (sqlconn);

  tbindex = *((int *) user_data);
  reinitialize_dbwin (dbwin);
  recreate_dbobject (dbwin, dbobject, tbindex);
  DPRINT("Executed on show\n");
}



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

gboolean
on_dbwin_delete_event (GtkWidget * widget,
		       GdkEvent * event, gpointer user_data)
{
  DPRINT ("on_frm_delete_event.\n");
  gtk_widget_hide (widget);
  return FALSE;
}

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
 */
gboolean
delete_mainwindow (GtkWidget * widget, GdkEvent * event, gpointer data)
{
  gtk_main_quit ();
  return FALSE;
}
