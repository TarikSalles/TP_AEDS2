#include "headers/gtk.h"


int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    AppWidgets *widgets = g_slice_new(AppWidgets);

    gtk_init(&argc, &argv);

    // Adiciona o xml ao builder, conseguindo a descricao de cada objeto
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "glade/window.glade", NULL);
    printf("builder: %p\n", builder);

    if (builder == NULL)
    {
        g_critical("Nao foi possivel carregar o arquivo");
        return 1;
    }

    // Conseguir o endereco da window da janela principal

    widgets->stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));
    widgets->window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

    widgets->bt_pesquisar = GTK_WIDGET(gtk_builder_get_object(builder, "bt_pesquisar"));
    widgets->bt_confirmar = GTK_WIDGET(gtk_builder_get_object(builder, "bt_confirmar"));
    widgets->bt_relevanciaPesq = GTK_WIDGET(gtk_builder_get_object(builder, "bt_relevanciaPesq"));
    widgets->bt_voltar = GTK_WIDGET(gtk_builder_get_object(builder, "bt_voltar"));
    widgets->bt_voltar2 = GTK_WIDGET(gtk_builder_get_object(builder, "bt_voltar2"));
    widgets->bt_voltar3 = GTK_WIDGET(gtk_builder_get_object(builder, "bt_voltar3"));
    widgets->entry_path = GTK_WIDGET(gtk_builder_get_object(builder, "entry_path"));
    widgets->entry_relevancia = GTK_WIDGET(gtk_builder_get_object(builder, "entry_relevancia"));
    widgets->bt_pesqDoc = GTK_WIDGET(gtk_builder_get_object(builder, "bt_pesqDoc"));
    widgets->bt_MontarPatricia = GTK_WIDGET(gtk_builder_get_object(builder, "bt_MontarPatricia"));
    widgets->bt_ImprimirPatricia = GTK_WIDGET(gtk_builder_get_object(builder, "bt_ImprimirPatricia"));
    widgets->bt_RealizarBusca = GTK_WIDGET(gtk_builder_get_object(builder, "bt_RealizarBusca"));
    





    if (widgets->window == NULL)
    {
        g_critical("Falha ao obter o objeto window do arquivo glade");
        return 1;
    }

    // Conseguir o endereco do botao e dos sinais
    gtk_builder_connect_signals(builder, widgets);

    // Nao preciso mais do construtor(builder)
    g_object_unref(builder);

    gtk_widget_show(widgets->window);
    
    gtk_main();

    // Destroi o builder
    g_slice_free(AppWidgets, widgets);

    return 0;
}
