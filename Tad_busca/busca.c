// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "busca.h"

int InicializaBusca(TBusca* busca){
    printf("InicializaBusca\n");
    busca->primeiro = (ApontaBusca)malloc(sizeof(CBusca));
    if (busca->primeiro){
        busca->ultimo = busca->primeiro;
        busca->ultimo->prox = NULL;
    }
    return 1;
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

    if (atual == NULL)
        busca->ultimo = novaCelula;
    // Insere uma nova célula na lista encadeada de busca em ordem decrescente de relevância
}

void ImprimeBusca(TBusca* busca, Tdocumento* doc) {
    ApontaBusca aux = busca->primeiro->prox;

    while (aux != NULL) {
        imprimeDoc(doc, aux->idDoc);
        printf(" Relevancia: %.2lf\n", aux->relevancia);
        removeBusca(busca, aux);
        aux = aux->prox;
    }
    // Percorre a lista de busca e imprime os resultados, juntamente com a relevância
    // A função imprimeDoc() imprime informações do documento associado ao ID armazenado na célula de busca
}

int removeBusca(TBusca* busca, ApontaBusca aux){
    ApontaBusca remove;
    if(aux == busca->primeiro->prox)
        busca->primeiro->prox = aux->prox;
    else if(aux == busca->ultimo)
        busca->ultimo = aux->prox;
    else {
        remove = busca->primeiro;
        while (remove->prox != aux)
            remove = remove->prox;

        remove = aux;
        aux = remove->prox;
        free(remove);

        if (aux->prox == NULL)
            busca->ultimo = aux;
    }

    return 1;
    // Remove uma célula da lista de busca
}

int calculoRelevancia(Arvore raiz, char* entradaBusca, Tdocumento* doc, TBusca* busca){
    double relevancia;
    int qtDocs = quantidadeDocs(doc);
    ApontaCelulaDoc aux = doc->primeiro->prox;
    while(aux){
        relevancia = (1.0 / aux->totalTermos) * termo(raiz, entradaBusca, qtDocs, aux->idDoc);
        if(relevancia > 0)
            InsereBuscaOrdenado(busca, aux->idDoc, relevancia);
        aux = aux->prox;
    }
    printf("Resultado da busca para \"%s\":\n",entradaBusca);
    ImprimeBusca(busca, doc);
    // Realiza o cálculo da relevância para cada documento e insere na lista encadeada de busca
    // A relevância é calculada utilizando a função termo() e os resultados são inseridos em ordem na lista
    // Em seguida, os resultados são impressos utilizando a função ImprimeBusca()
}

double termo(Arvore raiz, char* entradaBusca, int numDocs, int idDoc){
    char palavra[50];
    strcpy(palavra, entradaBusca);
    char* token = strtok(palavra, " ");
    int i;
    Arvore aux;
    float peso = 0;
    while(token){
        aux = Pesquisa_Palavra_Arvore(raiz, token);
        if(aux) {
            // condicional para verificar em qual tupla esta o documento que estou acessando
            peso += pesoTermo(Numero_Ocorrencias_Especifico(&(aux->tuplas), idDoc), numDocs, Numero_Total_Tuplas(&(aux->tuplas)));
            //peso += pesoTermo(aux->NO.lista.lista[i].num_ocorrencias, numDocs, aux->NO.lista.fim);
        }
        else
            peso += 0;
        token = strtok(NULL, " ");
    }
    return peso;
}

double pesoTermo(int numOcorrencias, int numDocs, int docsComTermo) {
    if (numOcorrencias == 0)
        return 0;
    return (numOcorrencias * (log(numDocs) / docsComTermo));
}
