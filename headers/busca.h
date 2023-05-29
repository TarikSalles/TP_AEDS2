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
int BuscaVazia(TBusca * busca);

// Insere uma nova célula de busca na lista mantendo a ordem crescente de relevância
int InsereBuscaOrdenado(TBusca * busca, int idDoc, double relevancia);


// Remove a célula de busca
int removeBusca(TBusca * busca, ApontaBusca aux);

// Calcula o somatorio dos pesos dos termos da busca
double termo(Arvore raiz, char* entradaBusca, int numDocs, int idDoc);

// Calcula o peso do termo
double pesoTermo(int numOcorrencias, int numDocs, int docsComTermo);