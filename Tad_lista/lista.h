#include <stdio.h>
#include <stdlib.h>
#define Max_tam 10

typedef struct celula{
    int index_arquivo;
    int num_ocorrencias;
}celula;

typedef struct Tlista * Aponta_lista;

typedef struct Tlista{
    celula lista[Max_tam];
    int inicio, fim;
}Tlista;


int Inicializa(Tlista * lista);
int Insere(Tlista * lista, char index);
int Lista_cheia(Tlista * lista);
int Imprime_lista(Tlista * lista);
