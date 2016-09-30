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
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include <uicontrol.h>
#include <events.h>
#include <database.h>




















GtkWidget *
create_dbwin (char *title, int width, int height)
{
  GtkWidget *vertholder;
  GtkWidget *statusbar;

  dbwin = gtk_scrolled_window_new (NULL,NULL);
  gtk_object_set_data (GTK_OBJECT (dbwin), "dbwin", dbwin);
  fprintf (stderr, "Creating objects\n");
  //gtk_window_set_title (GTK_SCROLLED_WINDOW (dbwin), title);

  fprintf (stderr, "%d %d\n", width, height);
  vertholder = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (vertholder);
  gtk_object_set_data_full (GTK_OBJECT (vertholder),
			    "vertholder", vertholder,
			    (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vertholder);
  gtk_container_add (GTK_CONTAINER (dbwin), vertholder);
  fprintf(stderr,"creating scrolled window\n");
  fprintf(stderr,"trying to pack\n");
  statusbar = gtk_statusbar_new ();
  gtk_widget_ref (statusbar);
  gtk_object_set_data_full (GTK_OBJECT (dbwin),
			    "statusbar", statusbar,
			    (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (statusbar);
  gtk_box_pack_start (GTK_BOX (vertholder), statusbar, FALSE, FALSE, 0);



  gtk_signal_connect (GTK_OBJECT (dbwin), "show",
		      GTK_SIGNAL_FUNC (on_dbwin_show), NULL);

  gtk_signal_connect (GTK_OBJECT (dbwin),
		      "delete_event",
		      GTK_SIGNAL_FUNC (on_dbwin_delete_event), NULL);
  fprintf(stderr,"trying to set dbwin\n");
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (dbwin),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
  return dbwin;
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
 *
 *
 *
 *
 *
 */

void
reinitialize_dbwin (GtkWidget * dbparent)
{



}


void
recreate_dbobject (GtkWidget * dbparent, GtkWidget * dbwidget, int tbindex)
{




}


void
feedback_msg (int status, char *msg)
{



}






/*************** All Menu and Toolbar Functions ********************/

GtkWidget *toolbar;
GtkWidget *menubar;
GtkWidget *main_vbox;
GtkWidget *sort_item;
GtkWidget *close_button;
GtkWidget *tooltips_button;
GtkWidget *text_button, *icon_button, *both_button;
GtkWidget *entry;

/* Global Menu table */

static GtkItemFactoryEntry menu_items[] = {
  {"/_File", NULL, NULL, 0, "<Branch>"},
  {"/File/_New", "<control>N", NULL, 0, "<StockItem>", GTK_STOCK_NEW},
  {"/File/_Open...", "<control>O", NULL, 0, "<StockItem>",
   GTK_STOCK_OPEN},
  {"/File/_Save", "<control>S", NULL, 0, "<StockItem>",
   GTK_STOCK_SAVE},
  {"/File/Save _As", NULL, NULL, 0, "<Item>"},

  {"/File/Page Set_up...", NULL, NULL, 0, "<Item>"},
  {"/File/Print Previe_w", "<SHIFT><control>P", NULL, 0, "<StockItem>",
   GTK_STOCK_PRINT_PREVIEW},
  {"/File/_Print...", "<control>P", NULL, 0, "<StockItem>", GTK_STOCK_PRINT},

  {"/File/sep1", NULL, NULL, 0, "<Separator>"},
  {"/File/_Close", "<control>W", NULL, 0, "<StockItem>", GTK_STOCK_CLOSE},

  {"/File/_Quit", "<CTRL>Q", gtk_main_quit, 0, "<StockItem>", GTK_STOCK_QUIT},
  {"/_Edit", NULL, NULL, 0, "<Branch>"},
  {"/Edit/_Undo", "<control>Z", NULL, 0, "<StockItem>", GTK_STOCK_UNDO},
  {"/Edit/_Redo", "<SHIFT><control>Z", NULL, 0, "<StockItem>",
   GTK_STOCK_REDO},
  {"/Edit/sep1", NULL, NULL, 0, "<Separator>"},


  {"/Edit/_Copy", "<control>C", NULL, 0, "<StockItem>", GTK_STOCK_COPY},
  {"/Edit/_Paste", "<control>V", NULL, 1, "<StockItem>", GTK_STOCK_PASTE},
  {"/Edit/_Cut", "<control>X", NULL, 0, "<StockItem>", GTK_STOCK_CUT},
  {"/Edit/sep1", NULL, NULL, 0, "<Separator>"},
  {"/Edit/Select _All", "<control>A", NULL, 0, "<Item>"},
  {"/_Inventory", NULL, NULL, 0, "<Branch>"},
  {"/Inventory/Create _Report", NULL, NULL, 0, "<Item>"},
  {"/Inventory/Show _Report", NULL, NULL, 0, "<Item>"},
  {"/Inventory/_Sort", NULL, NULL, 0, "<Branch>"},
  {"/Inventory/_Sort/byname", NULL, NULL, 0, "<Item>"},
  {"/Inventory/_Sort/bydate", NULL, NULL, 0, "<Item>"},


  {"/_Settings", NULL, NULL, 0, "<Branch>"},
  {"/Settings/_General", NULL, NULL, 0, "<Item>"},
  {"/Settings/_Print", NULL, NULL, 0, "<Item>"},
  {"/Settings/_Inventory", NULL, NULL, 0, "<Item>"},
  {"/_Help", NULL, NULL, 0, "<Branch>"},
  {"/_Help/About", NULL, NULL, 0, "<StockItem>", GTK_STOCK_ABOUT},
};

static gint nmenu_items = sizeof (menu_items) / sizeof (menu_items[0]);





GtkWidget *
get_menubar_menu (GtkWidget * window)
{
  GtkItemFactory *item_factory;
  GtkAccelGroup *accel_group;
  GdkColor color;
  /* Make an accelerator group (shortcut keys) */
  accel_group = gtk_accel_group_new ();

  /* Make an ItemFactory (that makes a menubar) */
  item_factory = gtk_item_factory_new (GTK_TYPE_MENU_BAR, "<main>",
				       accel_group);

  /* This function generates the menu items. Pass the item factory,
     the number of items in the array, the array itself, and any
     callback data for the the menu items. */
  gtk_item_factory_create_items (item_factory, nmenu_items, menu_items, NULL);

  /* Attach the new accelerator group to the window. */
  gtk_window_add_accel_group (GTK_WINDOW (window), accel_group);

  /* Finally, return the actual menu bar created by the item factory. */
  return gtk_item_factory_get_widget (item_factory, "<main>");
}









GtkWidget *
get_toolbar (GtkWidget * window)
{
  GtkWidget *toolbar;
  GtkWidget *iconw;
  toolbar = gtk_toolbar_new ();
  gtk_toolbar_set_orientation (GTK_TOOLBAR (toolbar),
			       GTK_ORIENTATION_HORIZONTAL);

  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_BOTH);
  iconw = gtk_image_new_from_file ("document-new.png");
  close_button = gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
					  "New",
					  "new",
					  "Private",
					  iconw,
					  GTK_SIGNAL_FUNC (NULL), NULL);
  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));


  iconw = gtk_image_new_from_file ("document-open.png");
  icon_button = gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
					 "Open",
					 "open",
					 "Private",
					 iconw, GTK_SIGNAL_FUNC (NULL), NULL);
  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));
  iconw = gtk_image_new_from_file ("save_all.png");
  text_button =
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
			     "Save",
			     "save",
			     "Private", iconw, GTK_SIGNAL_FUNC (NULL), NULL);
  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));

  iconw = gtk_image_new_from_file ("document-print.png");
  both_button =
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
			     "Print...",
			     "print",
			     "Private", iconw, GTK_SIGNAL_FUNC (NULL), NULL);
  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));

  iconw = gtk_image_new_from_file ("edit-undo.png");
  tooltips_button =
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
			     "Undo",
			     "first page",
			     "Private", iconw, GTK_SIGNAL_FUNC (NULL), NULL);
  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));


  iconw = gtk_image_new_from_file ("edit-redo.png");
  tooltips_button =
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
			     "Redo",
			     "first page",
			     "Private", iconw, GTK_SIGNAL_FUNC (NULL), NULL);
  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));




  iconw = gtk_image_new_from_file ("edit-delete.png");
  tooltips_button =
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
			     "Delete",
			     "first page",
			     "Private", iconw, GTK_SIGNAL_FUNC (NULL), NULL);
  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));
}



void
create_frontdisplay (char *customerlogo, GtkWidget * window, int width,
		     int height)
{
  int counter = 0;
  GtkWidget *image;
  GtkWidget *hbox;
  GtkWidget *vbox;
  GtkWidget *frame;
  GtkWidget *fixed, *fixed_container;
  GtkWidget *toolboxframe;
  GtkWidget *button[MAXBUTTONS];

  hbox = gtk_hbox_new (FALSE, 1);
  vbox = gtk_vbox_new (TRUE, 0);

  fprintf (stderr, "created vbox hbox %d %d\n", width, height);
  frame = gtk_frame_new ("");
  toolboxframe = gtk_frame_new ("");
  fixed = gtk_fixed_new ();
  fixed_container = gtk_fixed_new ();

  image = gtk_image_new_from_file (customerlogo);

  gtk_fixed_put (GTK_FIXED (fixed), image, 400, 10);
  gtk_widget_set_size_request (GTK_WIDGET (toolboxframe), width / 6, 500);


  fprintf (stderr, "Before starting vbox\n");
  gtk_box_pack_start (GTK_BOX (main_vbox), menubar, FALSE, TRUE, 0);
  fprintf (stderr, "creating %s %d\n", __FILE__, __LINE__);
  gtk_box_pack_start (GTK_BOX (main_vbox), toolbar, FALSE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (main_vbox), fixed, FALSE, FALSE, 0);
  gtk_box_pack_start (GTK_BOX (main_vbox), hbox, FALSE, FALSE, 0);
  gtk_box_pack_start (GTK_BOX (hbox), toolboxframe, FALSE, FALSE, 0);
  gtk_container_add (GTK_CONTAINER (toolboxframe), fixed_container);

  for (counter = 0; counter < MAXBUTTONS; counter++)
    {
      button[counter] = gtk_button_new_with_label ("TOOLS");
      gtk_fixed_put (GTK_FIXED (fixed_container), button[counter], 10,
		     10 + (counter + 1) * 40);
    }
}



void
get_screensize (gint * width, gint * height)
{
  GdkScreen *screen;
  /* Make a window */
  screen = gdk_screen_get_default ();
  *width = gdk_screen_get_width (screen);
  *height = gdk_screen_get_height (screen);
}


GtkWidget *
create_mainwindow (GtkWidget * window, char *prodname, int width, int height)
{
  GtkWidget *main_vbox;
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  g_signal_connect (G_OBJECT (window), "destroy",
		    G_CALLBACK (gtk_main_quit), NULL);
  gtk_window_set_title (GTK_WINDOW (window), prodname);
  gtk_window_set_default_size (window, width, height);

  /* Make a vbox to put the three menus in */
  main_vbox = gtk_vbox_new (FALSE, 1);
  gtk_container_set_border_width (GTK_CONTAINER (main_vbox), 1);
  gtk_container_add (GTK_CONTAINER (window), main_vbox);
  menubar = get_menubar_menu (window);
  toolbar = get_toolbar (window);
  fprintf (stderr, "Creating main window success\n");
}

/********************************* End ****************************************/
