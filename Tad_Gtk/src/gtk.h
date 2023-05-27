
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>




typedef struct dadosGTK{
    
    const char *path_atual;
    char *pesq_relevancia;
    int verif_patricia;

}dadosGTK;

typedef struct
{
    GtkStack *stack;
    GtkWidget *window;
    GtkWidget *bt_pesquisar;
    GtkWidget *bt_confirmar;
    GtkWidget *bt_relevanciaPesq;
    GtkWidget *entry_path;
    GtkWidget *entry_relevancia;
    GtkWidget *bt_pesqDoc;
    GtkWidget *bt_voltar;
    GtkWidget *bt_voltar2;
    GtkWidget *bt_voltar3;
    GtkWidget *bt_MontarPatricia;
    GtkWidget *bt_ImprimirPatricia;
    GtkWidget *bt_RealizarBusca;


    dadosGTK *interno;

} AppWidgets;

 void on_bt_pesquisar_clicked (GtkButton *bt_pesquisar, void *data);
//crie uma funcao que verifica se o entrypath e o endereco de um arquivo valido
int verificaPath(const char *path);



 void on_bt_confirmar_clicked (GtkButton *bt_pesquisar, void *data) ;

 void on_bt_voltar_clicked (GtkButton *bt_voltar1, void *data) ;

 
void on_bt_MontarPatricia_clicked (GtkButton *bt_MontarPatricia, void *data) ;

//criar uma funcao que verifica se a arvore ja foi montada
int verificaArvoreMontada(int verificado);


void on_bt_ImprimirPatricia_clicked (GtkButton *bt_ImprimirPatricia, void *data) ;


void on_bt_RealizarBusca_clicked (GtkButton *bt_RealizarBusca, void *data);


void on_bt_pesqDoc_clicked (GtkButton *bt_pesqDoc, void *data) ;


void on_bt_relevanciaPesq_clicked (GtkButton *bt_relevancia, void *data) ;

void mensagem(const char *texto_principal, const char *texto_secundario, const char *icone);


char *selecionar_arquivo() ;