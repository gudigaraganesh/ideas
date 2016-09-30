#ifndef _DATABASE_H
#define _DATABASE_H
#include<gtk/gtk.h>

#define SERVERNAME "localhost"
#define USERNAME   "sumeeth"
#define PASSWORD   "test"
#define DBNAME     "oil"
#define TABLENAME  "inventory"
#define MAXSERVERNSIZE  255
#define MAXUSERNSIZE    255
#define MAXPASSWORDSIZE 255
#define MAXDBNSIZE      255
#define MAXTABLENSIZE   255
#define MAXTABLES       10
#include<mysql.h>

GtkWidget *create_ddc (gchar * table_name, gchar * server_name,
		       gchar * user_name, gchar * user_pwd,
		       gchar * db_name, GtkWidget * frm_target);




void set_dbserver (char *server);
void set_dbuser (char *user);
void set_dbpassword (char *passwd);
void set_dbname (char *name);
void set_tablename (char *table, int index);
int create_connection (MYSQL * sqlconnection);
void close_connection (MYSQL * sqlconnection);
#endif /*_DATABASE_H */
