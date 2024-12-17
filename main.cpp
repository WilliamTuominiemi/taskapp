#include <iostream>
#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *label;

    // Create a new window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Simple GTK+ GUI");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Create a label
    label = gtk_label_new("Hello, GTK+!");
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER); // Center horizontally
    gtk_widget_set_valign(label, GTK_ALIGN_CENTER); // Center vertically
    gtk_container_add(GTK_CONTAINER(window), label);

    // Show all widgets
    gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    // Create a new application
    app = gtk_application_new("org.example.gtkapp", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}