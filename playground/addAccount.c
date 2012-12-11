#include <gtk/gtk.h>
#include <gio/gio.h>

int main (int argc,char *argv[]){

  GtkWidget *window;
  GtkWidget *frame;
  GtkWidget *button;
  GNetworkMonitor *monitor;
  gboolean network_available;

  gtk_init (&argc, &argv);
 
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  gtk_widget_set_size_request(window,400,400);

  frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), frame);
  
  button = gtk_button_new_with_label("Add Account");
  gtk_widget_set_size_request(button, 100, 35);
  gtk_fixed_put(GTK_FIXED(frame), button, 150, 150);
  
  monitor=g_network_monitor_get_default();
  g_object_bind_property (monitor, "network-available",
                          button, "sensitive",
                          G_BINDING_SYNC_CREATE);
  gtk_widget_show_all (window);
  
  printf("test1");
  gtk_main ();

  return 0;
}


