// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "documento.h"

int inicializaDoc(Tdocumento* doc){
    doc->inicio = 0;
    doc->fim = 0;
    return 0;
}

float calculaRelevancia(Tdocumento doc, Arvore raiz, char* entradaBusca, int numDocs){
    int i, j, numTermos;
    for(i=0; i<numDocs; i++){
        doc.doc[i]->relevancia = 0;
        doc.doc[i]->idDoc = i + 1;
        /*numTermos = strlen(entradaBusca) - 1;
        for(j=0; j<numTermos; j++)*/
        doc.doc[i]->relevancia += (1/numTermos) * termo(&raiz, entradaBusca, numDocs); //precisa ter alguma função que calcula no numero de termos em cada documento
        doc.fim++;
    }
}

float termo(Arvore* raiz, char* entradaBusca, int numDocs){
    char* token = strtok(entradaBusca, " ");
    Arvore* aux;
    float peso = 0;
    while(token != NULL){
        aux = Pesquisa(token, &raiz);
        if(aux)
            peso += pesoTermo(aux->lista.lista[i].num_ocorrencias, numDocs, aux->lista.fim);
        else
            peso += 0;
        token = strtok(NULL, " ");
    }
    return peso;
}

float pesoTermo(int numOcorrencias, int numDocs, int docsComTermo){
    if(numOcorrencias == 0)
        return 0;
    else
        return numOcorrencias * (log10(numDocs) / docsComTermo);
}