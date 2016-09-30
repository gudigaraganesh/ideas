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
 */

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include <mysql.h>
#include <database.h>
#include <stdlib.h>
#include <string.h>
#include <globaldef.h>


/* global declaration of     */
static servername[MAXSERVERNSIZE];
static username[MAXUSERNSIZE];
static password[MAXPASSWORDSIZE];
static dbname[MAXDBNSIZE];
static tablename[MAXTABLES][MAXTABLENSIZE];



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
 */
void
set_dbserver (char *server)
{
  if (server != NULL)
    {
      memset (servername, 0, MAXSERVERNSIZE);
      strncpy (servername, server, strlen (server));
    }

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
 */
void
set_dbuser (char *user)
{
  if (user != NULL)
    {
      memset (username, 0, MAXUSERNSIZE);
      strncpy (username, user, strlen (user));
    }

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
 */

void
set_dbpassword (char *passwd)
{
  if (passwd != NULL)
    {
      memset (password, 0, MAXPASSWORDSIZE);
      strncpy (password, passwd, strlen (passwd));
    }

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
 */
void
set_dbname (char *name)
{
  if (name != NULL)
    {
      memset (dbname, 0, MAXDBNSIZE);
      strncpy (dbname, name, strlen (name));
    }

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
 */

void
set_tablename (char *table, int index)
{
  if (table != NULL && index > 0 && index < MAXTABLES)
    {
      memset (&tablename[index][0], 0, MAXTABLENSIZE);
      strncpy (&tablename[index][0], table, strlen (table));
    }

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
 */

int
create_connection (MYSQL * sqlconnection)
{


  sqlconnection = mysql_init ((MYSQL *) 0L);
  sqlconnection = mysql_real_connect (sqlconnection, servername, username,
				      password, dbname, 0, 0L, 0);

  if (sqlconnection == 0L)
    return -1;
  else
    return 0;
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
 */
void
close_connection (MYSQL * sqlconnection)
{
  mysql_close (sqlconnection);
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
 */


GtkWidget *
create_dbwidget (int tableindex, GtkWidget * dbparent, GtkWidget * dbwidget)
{
  GtkWidget *dbmsg;
  GtkWidget *dblist;
  gint iterator;
  gint dbcolumns = 1;
  gint rowiterator = 0;
  MYSQL *query;
  MYSQL *sqlconn;
  MYSQL_RES *result_set;
  MYSQL_ROW db_sqlrow;
  MYSQL_FIELD *field;


  dbwidget = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (dbwidget);

  create_connection (sqlconn);

  if (sqlconn == 0L)
    {
      feedback_msg (ERROR, MSGCONNFAILED);
      return 0L;
    }




  query = g_strconcat ("select * from ", tablename[tableindex], 0L);

  if (mysql_query (sqlconn, query) != 0)
    {
      feedback_msg (ERROR, MSGQUERYFAILED);
      return 0L;
    }

  result_set = mysql_store_result (sqlconn);

  dbcolumns = mysql_num_fields (result_set);

  dblist = gtk_clist_new (dbcolumns);

  gtk_object_set_data_full (GTK_OBJECT (dbparent), "dblist", dblist, 0L);

  gtk_widget_show (dblist);

  gtk_container_add (GTK_CONTAINER (dbwidget), dblist);
  gtk_clist_column_titles_show (GTK_CLIST (dblist));


  /* First iterate through the columns. */


  for (iterator = 0; iterator < dbcolumns; iterator++)
    {
      mysql_field_seek (result_set, iterator);
      field = mysql_fetch_field (result_set);
      dbmsg = gtk_label_new (field->name);
      gtk_widget_show (dbmsg);
      gtk_clist_set_column_widget (GTK_CLIST (dblist), iterator, dbmsg);
      gtk_clist_set_column_width (GTK_CLIST (dblist), iterator, 80);
    }


  /* Next iterate through the rows. */

  while ((db_sqlrow = mysql_fetch_row (result_set)) != 0L)
    {
      for (iterator = 0; iterator < dbcolumns; iterator++)
	{
	  gtk_clist_set_text (GTK_CLIST (dblist), rowiterator, iterator,
			      (gchar *) db_sqlrow[rowiterator][iterator]);
	}
      rowiterator++;
    }
  close_connection (sqlconn);
  return dbwidget;
}
