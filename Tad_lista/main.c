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
    return 0;
}