// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "../headers/busca.h"

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

double termo(Arvore raiz, char* entradaBusca, int numDocs, int idDoc){
    char palavra[50];
    int i=0,c;
    for (i = 0, c = 0; entradaBusca[i] != ' '; i++, c++){
            if (entradaBusca[i] == ' ' || entradaBusca[i] == '\0'){
                palavra[c] = '\0';
                break;
            }
            palavra[c] = tolower(entradaBusca[i]);

    }
    palavra[i] = '\0';
    Arvore aux;
    float peso = 0;
    while(palavra){
        //printf("palavra: %s\n", palavra);
        aux = Pesquisa_Palavra_Arvore(raiz, palavra);
        if(aux) {
            // condicional para verificar em qual tupla esta o documento que estou acessando
            peso += pesoTermo(Numero_Ocorrencias_Especifico(&(aux->tuplas), idDoc), numDocs, Numero_Total_Tuplas(&(aux->tuplas)));
        }
        else
            peso += 0;
        //printf("peso: %f\n", peso);
        if (entradaBusca[i] == '\0'){
            return peso;
        }
        i = i+1;
        for (c = 0; c < 50 ; c++){
            palavra[c] = '\0';
        }
        for (c = 0; entradaBusca[i] != ' '; i++, c++){
            if (entradaBusca[i] == ' ' || entradaBusca[i] == '\0'){
                palavra[c] = '\0';
                break;
            }
            palavra[c] = tolower(entradaBusca[i]);

        }
    }
    return peso;
}

double pesoTermo(int numOcorrencias, int numDocs, int docsComTermo) {
    if (numOcorrencias == 0)
        return 0;
    //printf("numOcorrencias: %d\n", numOcorrencias);
    return (numOcorrencias * ( log10(numDocs) / docsComTermo));
}
