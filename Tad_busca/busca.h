// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "../Tad_Patricia/Patricia.h"

typedef struct CelulaBusca * ApontaBusca;
typedef struct CelulaBusca{
    int idDoc;
    double relevancia;
    ApontaBusca prox;
}CBusca;

typedef struct Busca{
    ApontaBusca primeiro, ultimo;
}TBusca;

int InicializaBusca(TBusca * busca);
int Busca_vazia(TBusca * busca);
int InsereBuscaOrdenado(TBusca * busca, int idDoc, double relevancia);
void ImprimeBusca(TBusca * busca);
int quantidadeDocs(Tdocumento * doc);
int calculoRelevancia(Arvore raiz, char* entradaBusca, Tdocumento* doc, TBusca* busca);

//precisa ter uma função que preenche o tad documento