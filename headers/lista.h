// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

typedef struct TCelula * Aponta_lista;

typedef struct TCelula{
    int index_arquivo;
    int num_ocorrencias;
    struct TCelula * prox;
    
}TCelula;


typedef struct Tlista{
    Aponta_lista primeiro, ultimo;
}Tlista;


int Inicializa(Tlista * lista);
int Insere(Tlista * lista, int index);
int Lista_vazia(Tlista * lista);

int Numero_Ocorrencias_Total(Tlista * lista);
int Numero_Total_Tuplas(Tlista * lista);
int Numero_Ocorrencias_Especifico(Tlista * lista, int idDoc);
int Imprime_lista(Tlista * lista);

// Eu preciso que verifique a tupla de acordo com o idDoc mandado
// int contaNumeroOcorrencias(aux->NO.lista, idDoc) ?????
// int numeroTuplas(aux->NO.lista, idDoc) ?????