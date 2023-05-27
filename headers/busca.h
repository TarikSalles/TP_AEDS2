// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "Patricia.h"

typedef struct CelulaBusca * ApontaBusca;
typedef struct CelulaBusca {
    int idDoc;                  // Identificador do documento
    double relevancia;          // Relevância do documento em relação à busca
    ApontaBusca prox;           // Ponteiro para a próxima célula de busca
} CBusca;

typedef struct Busca {
    ApontaBusca primeiro, ultimo;    // Ponteiros para a primeira e última células de busca
} TBusca;

// Inicializa a lista de busca
int InicializaBusca(TBusca * busca);

// Verifica se a lista de busca está vazia
int Busca_vazia(TBusca * busca);

// Insere uma nova célula de busca na lista mantendo a ordem crescente de relevância
int InsereBuscaOrdenado(TBusca * busca, int idDoc, double relevancia);

// Imprime os resultados da busca
void ImprimeBusca(TBusca * busca, Tdocumento * doc);

// Realiza o cálculo da relevância para cada documento e insere na lista de busca
int calculoRelevancia(Arvore raiz, char* entradaBusca, Tdocumento * doc, TBusca * busca);

// Remove a célula de busca
int removeBusca(TBusca * busca, ApontaBusca aux);