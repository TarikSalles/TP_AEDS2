#include "lista.h"

int main(){
    Tlista lista;
    Inicializa(&lista);
    Insere(&lista, 2);
    Insere(&lista, 1);
    Insere(&lista, 1);
    Insere(&lista, 3);
    Insere(&lista, 3);
    Insere(&lista, 1);
    Insere(&lista, 4);
    Insere(&lista, 2);
    Insere(&lista, 2);
    Insere(&lista, 1);
    Insere(&lista, 3);
    Insere(&lista, 1);
    Insere(&lista, 4);
    Insere(&lista, 5);
    Insere(&lista, 1);
    Imprime_lista(&lista);
    printf("Numero tuplas %d\n", Numero_Total_Tuplas(&lista));
    printf("Numero ocorrencias %d\n", Numero_Ocorrencias_Total(&lista));
    printf("Numero ocorrencias especifico em %d : %d\n", 1, Numero_Ocorrencias_Especifico(&lista,1));
    return 0;
}