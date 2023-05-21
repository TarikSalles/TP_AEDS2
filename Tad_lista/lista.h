// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define Total_Doc 10

typedef struct celula{
    char index_arquivo;
    int num_ocorrencias;
}celula;

typedef struct Tlista * Aponta_lista;

typedef struct Tlista{
    celula lista[Total_Doc
    int inicio, fim;
}Tlista;


int Inicializa(Tlista * lista);
int Insere(Tlista * lista, char index);
int Lista_cheia(Tlista * lista);
int Imprime_lista(Tlista * lista);
