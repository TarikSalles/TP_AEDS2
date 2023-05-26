// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "busca.h"

int InicializaBusca(TBusca * busca){
    busca->primeiro = (ApontaBusca)malloc(sizeof(CBusca));
    if (busca->primeiro){
        busca->ultimo = busca->primeiro;
        busca->ultimo->prox = NULL;
    }
    // Inicializa a lista encadeada de busca com uma célula de cabeça vazia
}

int BuscaVazia(TBusca * busca){
    return busca->primeiro == busca->ultimo;
    // Verifica se a lista de busca está vazia, comparando o primeiro e último elementos
}

int InsereBuscaOrdenado(TBusca* busca, int idDoc, double relevancia) {
    ApontaBusca novaCelula = (ApontaBusca)malloc(sizeof(CBusca));
    novaCelula->idDoc = idDoc;
    novaCelula->relevancia = relevancia;
    novaCelula->prox = NULL;

    ApontaBusca atual = busca->primeiro->prox;
    ApontaBusca anterior = busca->primeiro;

    while (atual != NULL && relevancia < atual->relevancia) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = novaCelula;
    novaCelula->prox = atual;

    if (atual == NULL) {
        busca->ultimo = novaCelula;
    }
    // Insere uma nova célula na lista encadeada de busca em ordem crescente de relevância
    // A nova célula é inserida na posição correta mantendo a ordem da lista
}

void ImprimeBusca(TBusca* busca, Tdocumento* doc) {
    ApontaBusca aux = busca->primeiro->prox;

    while (aux != NULL) {
        imprimeDoc(doc, aux->idDoc);
        printf("Relevancia: %.2lf\n", aux->relevancia);
        aux = aux->prox;
    }
    // Percorre a lista de busca e imprime os resultados, juntamente com a relevância
    // A função imprimeDoc() imprime informações do documento associado ao ID armazenado na célula de busca
}

int calculoRelevancia(Arvore raiz, char* entradaBusca, Tdocumento* doc, TBusca* busca){
    double relevancia;
    int qtDocs = quantidadeDocs(doc);
    ApontaCelulaDoc aux = doc->primeiro->prox;
    while(aux){
        relevancia = (1 / aux->totalTermos) * termo(raiz, entradaBusca, qtDocs, aux->idDoc);
        if(relevancia > 0)
            InsereBuscaOrdenado(busca, aux->idDoc, relevancia);
        aux = aux->prox;
    }
    ImprimeBusca(busca, doc);
    // Realiza o cálculo da relevância para cada documento e insere na lista encadeada de busca
    // A relevância é calculada utilizando a função termo() e os resultados são inseridos em ordem na lista
    // Em seguida, os resultados são impressos utilizando a função ImprimeBusca()
}


/*
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
*/