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
int InsereBusca(TBusca * busca, int idDoc, double relevancia);
int Busca_vazia(TBusca * busca);
int ImprimeBusca(TBusca * busca);



