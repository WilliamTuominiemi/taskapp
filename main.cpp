#include <gtk/gtk.h>

static void on_activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *label;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "TODO");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    label = gtk_label_new("TODOAPP");

    gtk_container_add(GTK_CONTAINER(window), label);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.example.Todo", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return status;
}

// g++ -o main main.cpp `pkg-config --cflags --libs gtk+-3.0`