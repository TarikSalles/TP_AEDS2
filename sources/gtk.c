#include "../headers/gtk.h"



 void on_bt_pesquisar_clicked (GtkButton *bt_pesquisar, void *data) {

    AppWidgets *widgets = (AppWidgets *)data;
    
    //copia o valor do entry para uma string
   // const char *path = gtk_entry_get_text(GTK_ENTRY(widgets->entry_path));

   const char *path = selecionar_arquivo();
    //imprime o valor da variavel

    //substituir o valor do entry pelo valor da string
    gtk_entry_set_text(GTK_ENTRY(widgets->entry_path), path);
    printf("path: %s\n", path);

    //usa a funcao message para imprimir o valor da entrada
    

    
    


    //exibir mensagem na tela, informando que o documento foi encontrado
    
    


 }
//crie uma funcao que verifica se o entrypath e o endereco de um arquivo valido
int verificaPath(const char *path){
    //verificar se o arquivo existe
    FILE *arquivo = fopen(path, "r");
    if (arquivo == NULL) {
        return 0;
    }
    fclose(arquivo);
    return 1;
}



 void on_bt_confirmar_clicked (GtkButton *bt_pesquisar, void *data) {

    AppWidgets *widgets = (AppWidgets *)data;
    //pegar o valor do entry_path e usar a funcao message para imprimir o arquivo
    const char *path = gtk_entry_get_text(GTK_ENTRY(widgets->entry_path));
    
    //fazer a variavel path_atual dentro de dadopegar o valor de path
   widgets->interno->path_atual = path;

    //Usar a funcao inicializaPrograma para a avariavel widgets->path_atual, se a funcao retornar NULL, exibir mensagem de erro
    if (verificaPath(widgets->interno->path_atual) == 0|| strcmp(widgets->interno->path_atual, "") == 0) {
        mensagem("Arquivo nao encontrado", "O arquivo nao foi encontrado, tente novamente", "dialog-error");
        return;
    }
    
    else{
        mensagem("Arquivo encontrado", widgets->interno->path_atual, "dialog-information");

        if(Inicializa_geral(&(widgets->interno->raiz), &(widgets->interno->doc), &(widgets->interno->busca))){
            mensagem("Arvore inicializada", "A arvore foi inicializada com sucesso", "face-smile");
        }
        
        widgets->interno->verif_patricia=0;
        gtk_stack_set_visible_child_name(widgets->stack, "view_menu");
        
    }
    


    //mensagem("Arquivo encontrado", widgets->path_atual, "dialog-information");

    //trocar o gtkstack para view_menu
   

    
    printf("Clicou no botao confirmar\n");
 }

 void on_bt_voltar_clicked (GtkButton *bt_voltar1, void *data) {
    printf("Clicou no botao voltar\n");

    AppWidgets *widgets = (AppWidgets *)data;
    //exibir mensagem na tela, informando que o documento foi encontrado
    
    gtk_stack_set_visible_child_name(widgets->stack, "view_menu");
 }

 
void on_bt_MontarPatricia_clicked (GtkButton *bt_MontarPatricia, void *data) {
        AppWidgets *widgets = (AppWidgets *)data;
        int verificado;
      //  const char *path = widgets->interno->path_atual;


        
        printf("Clicou no botao Montar\n");
        
        if(Leitura(widgets->interno->path_atual, &(widgets->interno->raiz), &(widgets->interno->doc)) == 0){
            mensagem("Arvore montada", "A arvore foi montada com sucesso", "dialog-information");
             verificado = 1;
        }
        else{
            mensagem("Erro", "Erro ao montar a arvore", "dialog-error");
            verificado =0;
        }

        widgets->interno->verif_patricia = verificado;
        


}

//criar uma funcao que verifica se a arvore ja foi montada
int verificaArvoreMontada(int verificado){
    if(verificado == 0){
        mensagem("Arvore nao montada", "A arvore ainda nao foi montada, monte a arvore primeiro", "dialog-error");
        return 0;
    }
    else{
        return 1;
    }
}

void on_bt_ImprimirPatricia_clicked(GtkButton *bt_ImprimirPatricia, void *data) {
        
        AppWidgets *widgets = (AppWidgets *)data;
        int verificado;
        verificado = widgets->interno->verif_patricia;

        printf("Clicou no botao Imprimir\n");

        if(verificaArvoreMontada(verificado) == 1){
            
            printf("Arvore ja esta montada\nProximaTela\n");
            gtk_stack_set_visible_child_name(widgets->stack, "view_imprimir");  
            //limpar o gtkliststore
            gtk_list_store_clear(widgets->liststore);
        }
        
        
        

        

}

void on_bt_listar_clicked(GtkButton *bt_listar, void *data) {
        AppWidgets *widgets = (AppWidgets *)data;
        GtkListStore *modelo_armazenamento = widgets->liststore;

        printf("Clicou no botao Listar\n");
        gtk_list_store_clear(modelo_armazenamento);
        Ordem(widgets->interno->raiz, widgets);
        
        
        

        

}




void on_bt_RealizarBusca_clicked (GtkButton *bt_RealizarBusca, void *data) {
        AppWidgets *widgets = (AppWidgets *)data;
        int verificado;
        verificado = widgets->interno->verif_patricia;
        
        
        printf("Clicou no botao Buscar\n");



        if(verificaArvoreMontada(verificado) == 1){
            
            printf("Arvore ja esta montada\nProximaTela\n");
            gtk_stack_set_visible_child_name(widgets->stack, "view_relevanciaPesq");
        }

}


void on_bt_pesqDoc_clicked (GtkButton *bt_pesqDoc, void *data) {
        AppWidgets *widgets = (AppWidgets *)data;


        
        
        printf("Clicou no botao pesqDoc\n");


        gtk_stack_set_visible_child_name(widgets->stack, "view_inicial");

}



void on_bt_relevanciaPesq_clicked (GtkButton *bt_relevancia, void *data) {
         AppWidgets *widgets = (AppWidgets *)data;
        const char *pesq;

        pesq = gtk_entry_get_text(GTK_ENTRY(widgets->entry_relevancia));

        widgets->interno->pesq_relevancia = pesq;
        printf("Clicou no botao pesqDoc\n");

        //verifica se a entry esta vazia
        if(strcmp(widgets->interno->pesq_relevancia, "") == 0){
        
            mensagem("Pesquisa invalida", "Digite um termo para pesquisar", "dialog-error");
            return;
        }else{
            mensagem("Pesquisa realizada", widgets->interno->pesq_relevancia, "dialog-information");
        }
  
        


        gtk_stack_set_visible_child_name(widgets->stack, "view_relevanciaImprimir");

}








void on_bt_listar2_clicked (GtkButton *bt_listar2, void *data) {
        AppWidgets *widgets = (AppWidgets *)data;
        GtkListStore *modelo_armazenamento = widgets->liststore2;

        printf("Clicou no botao Listar2\n");
        gtk_list_store_clear(modelo_armazenamento);
     //   Ordem2(widgets->interno->raiz, widgets);
        
        
        

        

}

void mensagem(const char *texto_principal, const char *texto_secundario, const char *icone) {
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, "%s", texto_principal);
    gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), "%s", texto_secundario);

    if (icone != NULL) {
        gtk_window_set_icon_name(GTK_WINDOW(dialog), icone);
    }

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

char *selecionar_arquivo() {
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

    dialog = gtk_file_chooser_dialog_new("Selecionar Arquivo", NULL, action, "_Cancelar", GTK_RESPONSE_CANCEL, "_Abrir", GTK_RESPONSE_ACCEPT, NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT) {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        char *filename = gtk_file_chooser_get_filename(chooser);
        gtk_widget_destroy(dialog);
        return filename;
    } else {
        gtk_widget_destroy(dialog);
        return NULL;
    }
}



int Inicializa_geral(Arvore * raiz, Tdocumento * documento, TBusca * busca){
    Inicializar_Arvore(raiz);
    inicializaDoc(documento);
    InicializaBusca(busca);
    return 1;
}

int Leitura(const char *path, Arvore * raiz, Tdocumento * documento){
    //cabecalhos de constantes na main
    char string[50] , string_tratada[50], string_nome_arquivo[50];
    FILE *arq;
    int index_do_arquivo = 0, contador = -1, tamanho_string, c; //auxilia na verificação de qual arquivo se está lendo
    /** Explicações:
     * string = guarda as strings provenientes da leitura do arquivo
     * string_tratada = string sem ';'
     * contador = conta o "estagio" da leitura do arquivo(necessario para saber quando trata-se de uma string ou de um index de arquivo)
     * index_do_arquivo = autoexplicativo
     * tamanho_string = auto_explicativo
     */
    

    //Abertura e verificacao do estado do arquivo
    arq = fopen(path, "r");
    if (arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return 1;
    }

    while(fscanf(arq,"%s",string) != EOF){

        tamanho_string = strlen(string);

        if (string[tamanho_string-1] == ';'){
            //Cada arquivo tem 3 partes: Index, titulo e abstract. Isso explica o porque do mod 3
            contador = (contador + 1)%3; 

            //remove o ';' da string:
            for (c = 0; c < (tamanho_string - 1); c++){
                string_tratada[c] = string[c];
            }
            //Substitui o ';' pelo '\0'
            string_tratada[tamanho_string-1] = '\0';

            //Atualiza string para ser a string tratada
            strcpy(string, string_tratada);

            //caso esteja no estado de leitura do index:
            if (contador == 0){
                strcpy(string_nome_arquivo, "arquivo");
                strcat(string_nome_arquivo, string);
                strcat(string_nome_arquivo, ".txt");
                index_do_arquivo = atoi(string);
                continue;
            }

        }
        Insere_Palavra_Arvore(raiz, string , index_do_arquivo, string_nome_arquivo, documento);
    }
    fclose(arq);
    return 0;
}



void Ordem(Arvore ap, void *data)
{
    AppWidgets *widgets = (AppWidgets *)data;
	/*Funcao com o objetivo de imprimir todas as palavras contidas na Patricia em ordem */
    
    if(ap == NULL)
        return;
    if(EInterno(ap))
        Ordem(ap->NO.NInterno.Esq, data);
    printPalavra(ap, data);
    if(EInterno(ap))
        Ordem(ap->NO.NInterno.Dir, data);
}

void printPalavra(Arvore no, void *data) { 
    AppWidgets *widgets = (AppWidgets *)data;
    
    GtkListStore *modelo_armazenamento = widgets->liststore;
    GtkTreeIter *iter;
    

    /* Funcao com o objetivo de imprimir todas as palavras dentro da Patricia*/

    

    if(no == NULL)
        printf("No Nulo\n");
    else if(no->nt == Externo){
        //printf("\nChave:%s \n",no->NO.Chave);

        //Ids = Imprime_lista(&no->tuplas);
        //strcpy(Ids, "Imprime_lista(&no->tuplas, data, iter)");
        //fazer a variavel IDs receber o retorno da funcao Imprime_lista
        
        

        gtk_list_store_append(modelo_armazenamento, &iter);
        const char *Ids= Imprime_lista(&no->tuplas);

        
        gtk_list_store_set(modelo_armazenamento, &iter, 
                            0, no->NO.Chave,
                            1, Ids,
                            -1);

        free(Ids);
        }
    
}




char* Imprime_lista(Tlista * lista){
    
    

    

    
   char IdNovo[100];
    char* stringCompleta = NULL;
    size_t tamanhoTotal = 0;

    
    
    

    Aponta_lista aux;
    if (Lista_vazia(lista)){
        //printf("Essa lista e vazia\n");
        return NULL;
    }

    aux = lista->primeiro->prox;

    
    

    while(aux != NULL){
       

       //funcao que formata e guarda os dados em uma string

         
        sprintf(IdNovo, " <%d,%d>", aux->num_ocorrencias,aux->index_arquivo);
        
        size_t tamanhoID = strlen(IdNovo);
        
        char* novaString = realloc(stringCompleta, tamanhoTotal + tamanhoID + 1);
        
        
        if (novaString == NULL) {
            printf("Erro de alocação de memória!\n");
            free(stringCompleta);
            return NULL;
        }

        stringCompleta = novaString;

        // Concatena a nova palavra na string completa
        strcpy(stringCompleta + tamanhoTotal, IdNovo);

        tamanhoTotal += tamanhoID;
    
        

       
        


        aux = aux->prox;


    }

    
    //libera memoria das strings
    
    //retorna a string com os dados formatados
    return stringCompleta;
}

