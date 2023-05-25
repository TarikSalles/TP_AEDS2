// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "busca.h"

int InicializaBusca(TBusca * busca){
    busca->primeiro = (ApontaBusca)malloc(sizeof(CBusca));
    if (busca->primeiro){
        busca->ultimo = busca->primeiro;
        busca->ultimo->prox = NULL;
    }
}

int BuscaVazia(TBusca * busca){
    return busca->primeiro == busca->ultimo;
}

int InsereBusca(TBusca * busca, int idDoc, double relevancia){
    ApontaBusca aux;
    aux = busca->primeiro->prox;
    while(aux != NULL){
        if(aux->idDoc == idDoc){
            aux->relevancia = relevancia;
            return 0;
        }
        aux = aux->prox;
    }
    busca->ultimo->prox = (ApontaBusca)malloc(sizeof(CBusca));
    busca->ultimo = busca->ultimo->prox;
    busca->ultimo->idDoc = idDoc;
    busca->ultimo->relevancia = relevancia;
    busca->ultimo->prox = NULL;
    return 0;
}

int InsereBuscaOrdenado(TBusca * busca, int idDoc, double relevancia){
    ApontaBusca aux, ant;
    aux = busca->primeiro->prox;
    ant = busca->primeiro;
    while(aux != NULL){
        if(aux->relevancia < relevancia){
            ant->prox = (ApontaBusca)malloc(sizeof(CBusca));
            ant->prox->idDoc = idDoc;
            ant->prox->relevancia = relevancia;
            ant->prox->prox = aux;
            return 0;
        }
        ant = aux;
        aux = aux->prox;
    }
    busca->ultimo->prox = (ApontaBusca)malloc(sizeof(CBusca));
    busca->ultimo = busca->ultimo->prox;
    busca->ultimo->idDoc = idDoc;
    busca->ultimo->relevancia = relevancia;
    busca->ultimo->prox = NULL;
    return 0;
}

