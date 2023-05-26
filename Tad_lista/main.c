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

double termo(Arvore raiz, char* entradaBusca, int numDocs, int idDoc);
double pesoTermo(int numOcorrencias, int numDocs, int docsComTermo);

double termo(Arvore raiz, char* entradaBusca, int numDocs, int idDoc){
    char* token = strtok(entradaBusca, " ");
    int i;
    Arvore aux;
    float peso = 0;
    while(token != NULL){
        aux = Pesquisa(token, &raiz);
        if(aux) {
            // condicional para verificar em qual tupla esta o documento que estou acessando
            peso += pesoTermo(contaNumeroOcorrencias(&(aux->NO.lista), idDoc), numDocs, numeroTuplas(aux->NO.lista));
            //peso += pesoTermo(aux->NO.lista.lista[i].num_ocorrencias, numDocs, aux->NO.lista.fim);
        }
        else
            peso += 0;
        token = strtok(NULL, " ");
    }
    return peso;
}

float pesoTermo(int numOcorrencias, int numDocs, int docsComTermo) {
    if (numOcorrencias == 0)
        return 0;
}