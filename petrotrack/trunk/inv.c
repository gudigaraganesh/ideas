

#include <gdk/gdkkeysyms.h>
#include <stdio.h>
#include <mysql.h>
#include <events.h>
#include <uicontrol.h>


gchar *a;
gchar *name[50];
gchar *fuel[50];
gchar *qty[50];
gchar *bill[50];
static gint count;
GtkWidget *entry;
GtkWidget *entry1;
GtkWidget *combo1;
GtkWidget *combo2;
GList *combo2_items = NULL;
GtkWidget *combo_entry2;
GtkWidget *dialog1;
GtkWidget *entry6;

GtkListStore *model;
GtkListStore *store;
GtkTreeIter iter;
GList *combo1_items = NULL;
GtkWidget *combo_entry1;

void
create_report ()
{
  //gtk_widget_show (dbwin);
}



static GType *
get_model_types (void)
{
  static GType column_types[4] = { 0 };

  if (column_types[0] == 0)
    {
      column_types[0] = G_TYPE_STRING;
      column_types[1] = G_TYPE_STRING;
      column_types[2] = G_TYPE_STRING;
      column_types[3] = G_TYPE_STRING;
    }

  return column_types;
}





static void
hide_dialog (GtkWidget * w, gpointer data)
{
  gtk_widget_hide (GTK_WIDGET (data));
}


static void
append_text (GtkWidget * w, gpointer data)
{
  a = gtk_entry_get_text (GTK_ENTRY (data));
  gtk_entry_set_text (GTK_ENTRY (combo_entry2), a);




  gtk_widget_hide (GTK_WIDGET (dialog1));

}
static void
enter_callback (GtkWidget * widget, gpointer data)
{

 MYSQL   *conx;
  gchar   *sql;

  gint i;
  name[count] = gtk_entry_get_text (GTK_ENTRY (GTK_COMBO (combo2)->entry));
  fuel[count] = gtk_entry_get_text (GTK_ENTRY (GTK_COMBO (combo1)->entry));
  bill[count] = gtk_entry_get_text (GTK_ENTRY (entry1));
  qty[count] = gtk_entry_get_text (GTK_ENTRY (entry));
  printf ("Entry contents: %s\n", name[count]);
  printf ("Entry contents: %s\n", fuel[count]);
  printf ("Entry contents: %s\n", bill[count]);
  printf ("Entry contents: %s\n", qty[count]);

      g_print ("mysql_init start...\n");
  conx = mysql_init((MYSQL *)0L);
  if (conx == 0L)
    {
      g_print ("mysql_init failure...\n");
      return 0L;
    }
      g_print ("mysql_init success..\n");
  mysql_real_connect (conx, "localhost", "sumeeth",
		      "test", "oil", 0, 0L, 0);
  if (conx == 0L)
    {
      g_print ("mysql_real_connect failure...\n");
      return 0L;
    }
  sql = g_strconcat ("insert into  inventory values", "('",name[count],"','",fuel[count],"','",qty[count],"','",bill[count],"'",")",0L);
  g_print ("sql is: %s\n", sql);
  if (mysql_query (conx, sql) != 0)
    {
      g_print ("query failure...\n");
      return 0L;
    }

      g_print ("insertion complete\n");










  gtk_list_store_append (GTK_LIST_STORE (store), &iter);
  gtk_list_store_set (GTK_LIST_STORE (store), &iter, 0, name[count], 1,
		      fuel[count], 2, qty[count], 3, bill[count], -1);

  count++;

}





static void
toggle_activity_mode (GtkWidget * widget, gpointer data)
{




  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget)))
    {
      printf ("in activei\n");

      gtk_widget_show (GTK_WIDGET (data));

    }

  else

    {

      printf ("in in active\n");
      gtk_widget_hide (GTK_WIDGET (data));
      printf ("in in active\n");
      // g_signal_connect (G_OBJECT (data),
      //                      "toggled", G_CALLBACK (hide_dialog), dialog1);



    }



}

static void
dialog (GtkWidget * widget, gpointer data)
{

  GtkWidget *dialog;





  GtkWidget *entry3;
  GtkWidget *label;

  GtkWidget *frame;
  GtkWidget *fixed;
  GtkWidget *fixed1;
  GtkWidget *frame1;
  GtkWidget *frame2;
  GtkWidget *frame3;
  GtkWidget *vbox;
  GtkWidget *button4;
  GSList *group;
  GtkWidget *button;
  GtkWidget *button3;
  GtkWidget *button6;
  GtkWidget *button5;
  GtkWidget *check;
  GtkWidget *check1;
//dialog for new name


//creation of new name dialog1
  dialog1 = gtk_dialog_new ();

  gtk_widget_set_size_request (dialog1, 200, 200);


  button5 = gtk_button_new_with_label ("cancel");
  button6 = gtk_button_new_with_label ("submit");
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog1)->action_area), button5,
		      TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog1)->action_area), button6,
		      TRUE, TRUE, 0);

  fixed = gtk_fixed_new ();
  fixed1 = gtk_fixed_new ();

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog1)->vbox), fixed1, TRUE,
		      TRUE, 0);

  g_signal_connect (G_OBJECT (button5),
		    "clicked", G_CALLBACK (hide_dialog), dialog1);


//end of new dialog1


  dialog = gtk_dialog_new ();

  gtk_widget_set_size_request (dialog, 300, 300);

  button3 = gtk_button_new_with_label ("cancel");
  button4 = gtk_button_new_with_label ("  OK  ");
  g_signal_connect (G_OBJECT (button3),
		    "clicked", G_CALLBACK (hide_dialog), dialog);

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog)->action_area), button3,
		      TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog)->action_area), button4,
		      TRUE, TRUE, 0);

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog)->vbox), fixed, TRUE,
		      TRUE, 0);
  frame = gtk_frame_new (NULL);
  gtk_frame_set_label (GTK_FRAME (frame), "customer");
  gtk_fixed_put (GTK_FIXED (fixed), frame, 10, 10);
  gtk_frame_set_label_align (GTK_FRAME (frame), 1.0, 0.0);
  gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_ETCHED_OUT);

  vbox = gtk_vbox_new (TRUE, 0);

  gtk_container_add (GTK_CONTAINER (frame), vbox);
  check = gtk_check_button_new_with_label ("regular");


  gtk_box_pack_start (GTK_BOX (vbox), check, TRUE, TRUE, 0);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check), TRUE);


  gtk_widget_show (check);

  check1 = gtk_check_button_new_with_label ("new");
  gtk_box_pack_start (GTK_BOX (vbox), check1, TRUE, TRUE, 0);
  g_signal_connect (G_OBJECT (check1), "toggled",
		    G_CALLBACK (toggle_activity_mode), dialog1);
  gtk_widget_show (check1);

  frame1 = gtk_frame_new (NULL);
  gtk_frame_set_label (GTK_FRAME (frame1), "fuel");
  gtk_fixed_put (GTK_FIXED (fixed), frame1, 10, 85);
  gtk_frame_set_label_align (GTK_FRAME (frame1), 0.0, 0.0);
  gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_ETCHED_OUT);

  combo1 = gtk_combo_new ();


  gtk_widget_show (combo1);
  gtk_container_add (GTK_CONTAINER (frame1), combo1);
  gtk_widget_set_size_request (combo1, 180, 27);
  combo1_items = g_list_append (combo1_items, (gpointer) ("petrol"));
  combo1_items = g_list_append (combo1_items, (gpointer) ("diesel"));
  combo1_items = g_list_append (combo1_items, (gpointer) ("leaded petrol"));
  combo1_items = g_list_append (combo1_items, (gpointer) ("unleaded petol"));
  gtk_combo_set_popdown_strings (GTK_COMBO (combo1), combo1_items);
  g_list_free (combo1_items);

  combo_entry1 = GTK_COMBO (combo1)->entry;
  gtk_widget_show (combo_entry1);
  gtk_entry_set_text (GTK_ENTRY (combo_entry1), ("--select--"));


  frame2 = gtk_frame_new (NULL);
  gtk_frame_set_label (GTK_FRAME (frame2), "quantity");
  gtk_fixed_put (GTK_FIXED (fixed), frame2, 10, 140);
  gtk_frame_set_label_align (GTK_FRAME (frame), 0.0, 0.0);
  gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_ETCHED_OUT);


  //qty entry


  entry = gtk_entry_new ();
  gtk_widget_set_size_request (entry, 180, 27);

  gtk_container_add (GTK_CONTAINER (frame2), entry);

  frame3 = gtk_frame_new (NULL);
  gtk_frame_set_label (GTK_FRAME (frame3), "Bill");
  gtk_fixed_put (GTK_FIXED (fixed), frame3, 10, 190);
  gtk_frame_set_label_align (GTK_FRAME (frame), 0.0, 0.0);
  gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_ETCHED_OUT);

  //bill entry

  entry1 = gtk_entry_new ();
  gtk_widget_set_size_request (entry1, 180, 27);

  gtk_container_add (GTK_CONTAINER (frame3), entry1);


  combo2 = gtk_combo_new ();


  gtk_widget_show (combo2);


  gtk_fixed_put (GTK_FIXED (fixed1), label, 10, 60);
  gtk_fixed_put (GTK_FIXED (fixed), combo2, 100, 10);
  gtk_widget_set_size_request (combo2, 180, 27);
  combo2_items = g_list_append (combo2_items, (gpointer) ("sumeeth"));
  combo2_items = g_list_append (combo2_items, (gpointer) ("sudhier"));
  combo2_items = g_list_append (combo2_items, (gpointer) ("shankar"));
  combo2_items = g_list_append (combo2_items, (gpointer) ("rohith"));
  gtk_combo_set_popdown_strings (GTK_COMBO (combo2), combo2_items);
  g_list_free (combo2_items);

  combo_entry2 = GTK_COMBO (combo2)->entry;
  gtk_widget_show (combo_entry2);
  gtk_entry_set_text (GTK_ENTRY (combo_entry2), ("--select--"));

//name entry in dialog1


  label = gtk_label_new ("enter your name:");
  gtk_fixed_put (GTK_FIXED (fixed1), label, 10, 60);
  entry3 = gtk_entry_new ();
  gtk_widget_set_size_request (entry3, 180, 27);


  gtk_fixed_put (GTK_FIXED (fixed1), entry3, 10, 80);



  gtk_widget_show (entry3);

  g_signal_connect (G_OBJECT (button6),
		    "clicked", G_CALLBACK (append_text), entry3);

  g_signal_connect (G_OBJECT (button4),
		    "clicked", G_CALLBACK (enter_callback), NULL);

  gtk_widget_show (label);
  gtk_widget_show (fixed1);
  gtk_widget_show (entry);
  gtk_widget_show (entry1);
  gtk_widget_show (vbox);
  gtk_widget_show (frame);
  gtk_widget_show (frame1);
  gtk_widget_show (frame2);
  gtk_widget_show (frame3);
  gtk_widget_show (fixed);
  gtk_widget_show (button3);
  gtk_widget_show (button4);
  gtk_widget_show (button5);
  gtk_widget_show (button6);
  gtk_widget_show (dialog);
}

static GtkWidget *
create_list (void)
{
  GtkWidget *scrolled_window;
  GtkWidget *tree_view;
  GtkCellRenderer *cell;
  GtkTreeViewColumn *column4;

  GtkTreeViewColumn *column1;
  GtkTreeViewColumn *column2;
  GtkTreeViewColumn *column3;
  GType *t;


  /* Create a new scrolled window, with scrollbars only if needed */
  scrolled_window = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);



  t = get_model_types ();

  store = gtk_list_store_new (4, t[0], t[1], t[2], t[3]);


  tree_view = gtk_tree_view_new ();
  gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW
					 (scrolled_window), tree_view);
  gtk_tree_view_set_model (GTK_TREE_VIEW (tree_view), GTK_TREE_MODEL (store));
  gtk_widget_show (tree_view);






  cell = gtk_cell_renderer_text_new ();

  column1 = gtk_tree_view_column_new_with_attributes ("customer",
						      cell, "text", 0, NULL);

  column2 = gtk_tree_view_column_new_with_attributes ("fuel",
						      cell, "text", 1, NULL);

  column3 = gtk_tree_view_column_new_with_attributes ("quantity",
						      cell, "text", 2, NULL);

  column4 = gtk_tree_view_column_new_with_attributes ("bill",
						      cell, "text", 3, NULL);



  gtk_tree_view_column_pack_start (GTK_TREE_VIEW_COLUMN (column1),
				   GTK_CELL_RENDERER (cell), TRUE);

  gtk_tree_view_column_pack_start (GTK_TREE_VIEW_COLUMN (column2),
				   GTK_CELL_RENDERER (cell), TRUE);
  gtk_tree_view_column_pack_start (GTK_TREE_VIEW_COLUMN (column3),
				   GTK_CELL_RENDERER (cell), TRUE);
  gtk_tree_view_column_pack_start (GTK_TREE_VIEW_COLUMN (column4),
				   GTK_CELL_RENDERER (cell), TRUE);

  gtk_tree_view_append_column (GTK_TREE_VIEW (tree_view),
			       GTK_TREE_VIEW_COLUMN (column1));
  gtk_tree_view_append_column (GTK_TREE_VIEW (tree_view),
			       GTK_TREE_VIEW_COLUMN (column2));
  gtk_tree_view_append_column (GTK_TREE_VIEW (tree_view),
			       GTK_TREE_VIEW_COLUMN (column3));
  gtk_tree_view_append_column (GTK_TREE_VIEW (tree_view),
			       GTK_TREE_VIEW_COLUMN (column4));
  return scrolled_window;
}





void create_inventory()
{
  GtkWidget *window;
  GtkWidget *hpaned;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *vbox;
  GtkWidget *list;







  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "inventory");
  g_signal_connect (G_OBJECT (window), "destroy",
		    G_CALLBACK (gtk_main_quit), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);
  gtk_widget_set_size_request (GTK_WIDGET (window), 400, 500);

  hpaned = gtk_hpaned_new ();
  gtk_container_add (GTK_CONTAINER (window), hpaned);
  gtk_widget_show (hpaned);


  vbox = gtk_vbox_new (TRUE, 0);
  gtk_paned_add1 (GTK_PANED (hpaned), vbox);
  gtk_widget_show (vbox);

  button1 = gtk_button_new_with_label ("report");
  button2 = gtk_button_new_with_label ("inventory");

  gtk_box_pack_start (GTK_BOX (vbox), button1, FALSE, FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), button2, FALSE, FALSE, 0);

  gtk_widget_show (button1);
  gtk_widget_show (button2);
 
  g_signal_connect (button2, "clicked", G_CALLBACK (dialog), NULL);
  g_signal_connect (button1, "clicked", G_CALLBACK (create_report), NULL);


  list = create_list ();
  gtk_paned_add2 (GTK_PANED (hpaned), list);
  gtk_widget_show (list);
  gtk_widget_show (window);



}
