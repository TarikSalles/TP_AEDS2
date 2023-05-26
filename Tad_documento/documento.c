// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "documento.h"

int inicializaDoc(Tdocumento* doc){
    doc->primeiro = (ApontaCelulaDoc)malloc(sizeof(celulaDoc));
    if(doc->primeiro){
        doc->ultimo = doc->primeiro;
        doc->ultimo->prox = NULL;
    }
    return 1;
}

int docVazio(Tdocumento* doc){
    return doc->primeiro == doc->ultimo;
}

int insereDoc(Tdocumento*doc, int idDoc, char* nomeDoc){
    ApontaCelulaDoc aux;
    aux = doc->primeiro->prox;
    while(aux){
        if(aux->idDoc == idDoc){
            aux->totalTermos++;
            return 1;
        }
        aux = aux->prox;
    }

    ApontaCelulaDoc novaCelula = (ApontaCelulaDoc)malloc(sizeof(CDoc));
    novaCelula->idDoc = idDoc;
    strcpy(novaCelula->nomeDoc, nomeDoc);
    novaCelula->totalTermos = 0;

    doc->ultimo->prox = novaCelula;
    doc->ultimo = doc->ultimo->prox;
    doc->ultimo->prox = NULL;
}

int quantidadeDocs(Tdocumento * doc){
    int quantidade = 0;
    ApontaCelulaDoc aux = doc->primeiro->prox;
    while(aux){
        quantidade++;
        aux = aux->prox;
    }
    return quantidade;
}

void imprimeDoc(Tdocumento* doc, int idDoc){
    ApontaCelulaDoc aux = doc->primeiro->prox;
    while(aux){
        if(aux->idDoc == idDoc){
            printf("ID Documento: %d | Nome Documento: %s |", aux->idDoc, aux->nomeDoc);
            return;
        }
        aux = aux->prox;
    }
}
/*
int insereDoc(Tdocumento* doc, int idDoc, char* nomeDoc, int totalTermos){
    ApontaCelulaDoc novaCelula = (ApontaCelulaDoc)malloc(sizeof(CDoc));

    novaCelula->idDoc = idDoc;
    strcpy(novaCelula->nomeDoc, nomeDoc);
    novaCelula->totalTermos = totalTermos;

    doc->ultimo->prox = novaCelula;
    doc->ultimo = doc->ultimo->prox;
    doc->ultimo->prox = NULL;

    return 0;
}
 */