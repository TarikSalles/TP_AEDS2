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

// Inicializa a lista de documentos
// Cria a célula de cabeça vazia e retorna 1 em caso de sucesso

int docVazio(Tdocumento* doc){
    return doc->primeiro == doc->ultimo;
}

// Verifica se a lista de documentos está vazia
// Retorna 1 se estiver vazia, caso contrário retorna 0

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

    // Verifica se o documento já existe na lista e, se existir, incrementa o total de termos

    ApontaCelulaDoc novaCelula = (ApontaCelulaDoc)malloc(sizeof(CDoc));
    novaCelula->idDoc = idDoc;
    strcpy(novaCelula->nomeDoc, nomeDoc);
    novaCelula->totalTermos = 0;

    doc->ultimo->prox = novaCelula;
    doc->ultimo = doc->ultimo->prox;
    doc->ultimo->prox = NULL;

    // Insere uma nova célula de documento no final da lista

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

// Calcula a quantidade de documentos na lista encadeada
// Percorre a lista e incrementa um contador a cada iteração

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

// Imprime as informações de um documento com base em seu ID
// Percorre a lista de documentos até encontrar o documento com o ID fornecido
// e imprime o ID e o nome do documento

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