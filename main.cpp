#include <gtk/gtk.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*i have grouped all the widgets in one structure. this technique will
 * help if you have huge number of  windows in your project.
 * as the number of window will increase the variable we declare will increase
 * and the declared variables can have same name of different windows */
struct login_window
{
   GtkEntry *e1; //textbox1
   GtkEntry *e2; //textbox2
   GtkEntry *e3; //textbox3
};
typedef struct login_window   widgets;



extern "C" {
void on_button1_clicked(GtkButton *button, widgets *widg)
{
   char ch1[5], ch2[5], ch[5];
   int  a;
//getting text from the text boxes
   const gchar *text1 = gtk_entry_get_text(widg->e2);
   const gchar *text2 = gtk_entry_get_text(widg->e1);



   //converting integer to character
   gtk_entry_set_text(widg->e3, "Texto Salida"); //setting or displaying text(output) to the third text box


   g_print("El texto escrito es:");
   g_print(text1);
   g_print(" y: ");
   g_print(text2);
   g_print("\n");
}

void on_quit_menu_activate()
{
   gtk_main_quit();
}
} //fin extern c
int main(int argc, char **argv)
{
   GtkBuilder *builder;
   GtkWidget  *window;
   widgets    widg;

   //init gtk lib
   gtk_init(&argc, &argv);

   //add glade files
   builder = gtk_builder_new();
   gtk_builder_add_from_file(builder, "test1.glade", NULL);

   //Get main window widget
   window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));

   widg.e1 = GTK_ENTRY(gtk_builder_get_object(builder, "entry1"));
   widg.e2 = GTK_ENTRY(gtk_builder_get_object(builder, "entry2"));
   widg.e3 = GTK_ENTRY(gtk_builder_get_object(builder, "entry3"));

/*connecting signals so that appropriate handlers can be called when button is clicked*/
   gtk_builder_connect_signals(builder, &widg);

   g_object_unref(builder);
   gtk_widget_show(window);
   gtk_main();
   return(0);
}
