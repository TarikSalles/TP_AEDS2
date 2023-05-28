// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

//O tipo de lista e lista encadeada com cabeca

#include "../headers/lista.h"

int Inicializa(Tlista * lista){
    //Cria a celula cabeca
    Aponta_lista celula_aux = (Aponta_lista)malloc(sizeof(TCelula));
    if(celula_aux == NULL){
        printf("Problemas de alocacao de memoria\n");
        return 1;
    }
    lista->primeiro = celula_aux;
    lista->ultimo = celula_aux;
    lista->ultimo->prox = NULL;
}

//Retorna se a lista e vazia
int Lista_vazia(Tlista * lista){
    return lista->primeiro == lista->ultimo;
}

//Insere as tuplas em ordem na lista
int Insere(Tlista * lista, int index){
    
    Aponta_lista aux, celula_aux;
    
    aux = lista->primeiro;
    //Se lista e vazia:
    if (Lista_vazia(lista)){
        lista->ultimo->prox = (Aponta_lista)malloc(sizeof(TCelula));
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->index_arquivo = index;
        lista->ultimo->num_ocorrencias = 1;
        lista->ultimo->prox = NULL;
        return 0;
    }
    while(1){
        //Se e o fim da lista:
        if (aux->prox == NULL){
            aux->prox = (Aponta_lista)malloc(sizeof(TCelula));
            aux->prox->index_arquivo = index;
            aux->prox->num_ocorrencias = 1;
            aux->prox->prox = NULL;
            lista->ultimo = aux->prox;
            return 0;
        }
        //Se a tupla ja existe:
        if (aux->prox->index_arquivo == index){
            aux->prox->num_ocorrencias += 1;
            //printf("index == aux\n");
            //printf("< %d , %d >\n", lista->ultimo->num_ocorrencias, lista->ultimo->index_arquivo);
            return 0;
        }
        //Se e necessario continuar avancando nas listas:
        if (aux->prox->index_arquivo < index){
            aux = aux->prox;
            continue;
        }
        //Insere no meio:
        if (aux->prox->index_arquivo > index){
            celula_aux = (Aponta_lista)malloc(sizeof(TCelula));
            if(celula_aux == NULL){
                printf("Problemas de alocacao de memoria\n");
                return 1;
            }
            celula_aux->index_arquivo = index;
            celula_aux->num_ocorrencias = 1;
            celula_aux->prox = aux->prox;
            aux->prox = celula_aux;
            return 0;
        }
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

//Numero total de tuplas para aquela palavra (em outras palavras, em quantos documentos ela aparece)
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
    return 0;
}

int Imprime_lista(Tlista * lista){
    Aponta_lista aux;
    if (Lista_vazia(lista)){
        printf("Essa lista e vazia\n");
        return 1;
    }
    aux = lista->primeiro->prox;
    printf("Tuplas < qtde, idDoc >:\n");
    while(aux != NULL){
        printf("< %d, %d >\n", aux->num_ocorrencias,aux->index_arquivo );
        aux = aux->prox;
    }
    return 0;
}
