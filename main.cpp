#include <gtk/gtk.h>
#include <wiringPi.h>

static void print_hello(GtkWidget *widget, gpointer data)
{
   g_print("Boton 1 salida\n");
}

static void print_mes(GtkWidget *widget, gpointer data)
{
   g_print("Boton 2 salida\n");
}

static void activate(GtkApplication *app, gpointer user_data)
{
   GtkWidget *window;
   GtkWidget *grid;
   GtkWidget *button;

   //Parte creacción ventana
   window = gtk_application_window_new(app);
   gtk_window_set_title(GTK_WINDOW(window), "FcMaker 1.0");
   gtk_window_set_default_size(GTK_WINDOW(window), 1024, 860);
   gtk_container_set_border_width(GTK_CONTAINER(window), 10);

   //--------------------------------------------------------------//

   //Parte del boton



   grid = gtk_grid_new();                          //Contenedor para los botones
   gtk_container_add(GTK_CONTAINER(window), grid); //Añadimos el grid que contiene los botones.

   button = gtk_button_new_with_label("Botón 1");
   g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

   /* Place the first button in the grid cell (0, 0), and make it fill
    * Es una fila y una columna
    *
    */
   //Hay que hacer los cast siempre de GtkWidget al GTK correspondiente.
   gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);


   //Recreamos otro botón usando el mismo widget, no hace falta uno por cada uno.
   button = gtk_button_new_with_label("Boton 2");
   g_signal_connect(button, "clicked", G_CALLBACK(print_mes), NULL);

   //Ahora lo añadimos al grid
   gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);


   //Ultimo botón, el de cierre

   button = gtk_button_new_with_label("Salir");
   //Tiene que ser swapped para poder pasar datos y cerrar el window.
   g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);

   /* Place the Quit button in the grid cell (0, 1), and make it
    * span 2 columns.
    */
   gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

   /* Now that we are done packing our widgets, we show them all
    * in one go, by calling gtk_widget_show_all() on the window.
    * This call recursively calls gtk_widget_show() on all widgets
    * that are contained in the window, directly or indirectly.
    */



//Parte menu



   gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
   GtkApplication *app;
   int            status;

   app = gtk_application_new("fcmaker.aplication", G_APPLICATION_FLAGS_NONE); // Aquí es donde se inicializa la aplicaciópn app con las propiedades escritas en activate.

   g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);             // Esta utiliza el static void activate
   status = g_application_run(G_APPLICATION(app), argc, argv);                //Estatus guarda un integer que es un valor cuando se cierra la app
   g_object_unref(app);                                                       //libera el espacio ocupado por la app

   return(status);
}
