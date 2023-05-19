#include "lista.h"

int Inicializa(Tlista * lista){
    lista->inicio = 0;
    lista->fim = 0;
    return 0;
}

int Lista_cheia(Tlista * lista){
    if (lista->fim == (Max_tam - 1)){
        printf("\n A lista para alocação dos indices invertidos está cheia!!\n");
        return 1;
    }
    return 0;
}

int Insere(Tlista * lista, char index){
    int c;
    if (Lista_cheia(lista)){
        return 1;
    }

    for (c = lista->inicio; c < lista->fim; c++){
        if (lista->lista[c].index_arquivo == index){
            lista->lista[c].num_ocorrencias++;
            return 0;
        }
    }
    lista->lista[lista->fim].index_arquivo = index;
    lista->lista[lista->fim].num_ocorrencias = 1;
    lista->fim++;
}

int Imprime_lista(Tlista * lista){
    int c;
    for (c = lista->inicio; c < lista->fim; c++){
        printf("< %c, %i >\n", lista->lista[c].index_arquivo, lista->lista[c].num_ocorrencias);
    }
    return 0;
}
