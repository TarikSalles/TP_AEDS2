// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "lista.h"

int Inicializa(Tlista * lista){
    Aponta_lista celula_aux = (Aponta_lista)malloc(sizeof(TCelula));
    if(celula_aux == NULL){
        printf("Problemas de alocacao de memoria\n");
        return 1;
    }
    lista->primeiro = celula_aux;
    lista->ultimo = celula_aux;
    lista->ultimo->prox = NULL;
}

int Lista_vazia(Tlista * lista){
    return lista->primeiro == lista->ultimo;
}

int Insere(Tlista * lista, int index){
    
    Aponta_lista aux, celula_aux;
    
    aux = lista->primeiro;
    if (Lista_vazia(lista)){
        lista->ultimo->prox = (Aponta_lista)malloc(sizeof(TCelula));
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->index_arquivo = index;
        lista->ultimo->num_ocorrencias = 1;
        lista->ultimo->prox = NULL;
        return 0;
    }
    while(1){
        
        if (aux->prox == NULL){
            aux->prox = (Aponta_lista)malloc(sizeof(TCelula));
            aux->prox->index_arquivo = index;
            aux->prox->num_ocorrencias = 1;
            aux->prox->prox = NULL;
            lista->ultimo = aux->prox;
            return 0;
        }
        if (aux->prox->index_arquivo == index){
            aux->prox->num_ocorrencias += 1;
            //printf("index == aux\n");
            //printf("< %d , %d >\n", lista->ultimo->num_ocorrencias, lista->ultimo->index_arquivo);
            return 0;
        }
        if (aux->prox->index_arquivo < index){
            aux = aux->prox;
            continue;
        }
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


int Insere_novo(Tlista * lista, int index){
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
    return 1;
}

int Insere_original(Tlista * lista, int index){
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
    return 1;
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
    //printf("Nao ha ocorrencias no doc %d", idDoc);
    return 0;
}

// Eu preciso que verifique a tupla de acordo com o idDoc mandado
// int contaNumeroOcorrencias(aux->NO.lista, idDoc) ?????
// int numeroTuplas(aux->NO.lista, idDoc) ?????

