#include <gtk/gtk.h>
#include <gio/gio.h>

GtkWidget *button;
GNetworkMonitor *monitor;
gboolean network_available;

void increase(GNetworkMonitor *monitor,gboolean available,gpointer user_data){
	
	if(netw_status()){
        	gtk_widget_set_sensitive(button,TRUE);}
	else{ gtk_widget_set_sensitive(button,FALSE);}
	}

int netw_status(){
	monitor = g_network_monitor_get_default ();
	network_available = g_network_monitor_get_network_available (monitor);
	return network_available;
}


int main (int argc,char *argv[]){

  GtkWidget *window;
  GtkWidget *frame;

  gtk_init (&argc, &argv);
 
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  gtk_widget_set_size_request(window,400,400);

  frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), frame);
  
  button = gtk_button_new_with_label("Add Account");
  gtk_widget_set_size_request(button, 100, 35);
  gtk_fixed_put(GTK_FIXED(frame), button, 150, 150);
 
  if(netw_status()){
	  gtk_widget_set_sensitive(button,TRUE);} 
  else{
	  gtk_widget_set_sensitive(button,FALSE);}

  g_signal_connect(monitor,"network-changed",G_CALLBACK(increase),window);

  gtk_widget_show_all (window);
  
  gtk_main ();

  return 0;
}


