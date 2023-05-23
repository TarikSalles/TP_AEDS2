// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "lista.h"

int Inicializa(Tlista * lista){
    lista->primeiro = (Aponta_lista)malloc(sizeof(TCelula));
    if (lista->primeiro){
        lista->ultimo = lista->primeiro;
        lista->ultimo->prox = NULL;
    }
}

int Lista_cheia(Tlista * lista){
    return lista->primeiro == lista->ultimo;
}

int Insere(Tlista * lista, int index){
    Aponta_lista aux;
    
    aux = lista->primeiro->prox;
    while(aux != NULL){
        if (aux->index_arquivo == index){
            aux->num_ocorrencias += 1;
            return 0;
        }
        aux = aux->prox;
    }
    lista->ultimo->prox = (Aponta_lista)malloc(sizeof(TCelula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->index_arquivo = index;
    lista->ultimo->num_ocorrencias = 1;
    lista->ultimo->prox = NULL;
    return 0;
        
}

int Imprime_lista(Tlista * lista){
    Aponta_lista aux;
    aux = lista->primeiro->prox;
    printf("Tuplas < qtde, idDoc >:\n");
    while(aux != NULL){
        printf("< %d, %d >\n", aux->num_ocorrencias,aux->index_arquivo );
        aux = aux->prox;
    }
    return 0;
}

//Numero total de ocorrencia da palavra nos documentos
int Numero_Ocorrencias_Total(Tlista * lista){
    int contador;
    Aponta_lista aux;

    aux = lista->primeiro->prox;
    contador = 0;

    while(aux != NULL){
        contador += aux->num_ocorrencias;
        aux = aux->prox;
    }
    return contador;
}

//Numero total de tuplas para aquela palavra
int Numero_Total_Tuplas(Tlista * lista){
    int contador;
    Aponta_lista aux;

    aux = lista->primeiro->prox;
    contador = 0;

    while(aux != NULL){
        contador += 1;
        aux = aux->prox;
    }
    return contador;
}

int Numero_Ocorrencias_Especifico(Tlista * lista, int idDoc){

    Aponta_lista aux;

    aux = lista->primeiro->prox;

    while(aux != NULL){
        if (aux->index_arquivo == idDoc){
            return aux->num_ocorrencias;
        }
        aux = aux->prox;
    }
    printf("Nao ha ocorrencias no doc %d", idDoc);
    return 0;
}

// Eu preciso que verifique a tupla de acordo com o idDoc mandado
// int contaNumeroOcorrencias(aux->NO.lista, idDoc) ?????
// int numeroTuplas(aux->NO.lista, idDoc) ?????

