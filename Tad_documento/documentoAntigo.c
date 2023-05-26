// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "documentoAntigo.h"

// Inicializa a estrutura Tdocumento
int inicializaDoc(Tdocumento* doc){
    doc->primeiro = (Aponta_doc)malloc(sizeof(celulaDoc));
    if (doc->primeiro){
        doc->ultimo = doc->primeiro;
        doc->ultimo->prox = NULL;
    }
    Inicializar_Arvore(&doc->Patricia); // Inicializa a árvore PATRICIA
}

// Insere um documento na estrutura Tdocumento
int insereDoc(Tdocumento* doc, int idDoc, int totalTermos){
    doc->ultimo->prox = (Aponta_doc)malloc(sizeof(celulaDoc));
    doc->ultimo = doc->ultimo->prox;
    doc->ultimo->idDoc = idDoc; // Define o ID do documento
    doc->ultimo->totalTermos = totalTermos; // Define o número total de termos no documento
    doc->ultimo->relevancia = 0; // Define a relevância do documento
    doc->ultimo->prox = NULL;
    return 0;
}

// Insere uma palavra em um documento na árvore PATRICIA
int inserePalavraDoc(Tdocumento* doc, char* palavra, int idDoc){
    Insere_Palavra_Arvore(&doc->Patricia, palavra, idDoc); // Insere a palavra na árvore PATRICIA associada ao documento
    return 1;
}

// Calcula a relevância de cada documento em relação à entrada de busca e imprime em ordem de relevância
int relevancia(Tdocumento* doc, Arvore raiz, char* entradaBusca, int numDocs){
    Aponta_doc aux = doc->primeiro->prox;
    while(aux != NULL){ // Percorre a lista de documentos
        //aux->relevancia = 0;
        aux->relevancia = (1 / aux->totalTermos) * termo(&doc->Patricia, entradaBusca, aux->idDoc);
        aux = aux->prox;
    }
    /*
    for(i=0; i<numDocs; i++){
        doc->doc[i].relevancia = 0;
        doc->doc[i].relevancia += (1/doc->doc[i].totalTermos) * termo(doc->Patricia, entradaBusca, numDocs, doc->doc[i].idDoc);
        // termo() é uma função que calcula o peso de cada termo buscado para o documento em questão
        // O resultado é armazenado no campo relevancia do documento
    }*/
    printaEmOrdemMaisRelevante(doc); // Imprime os documentos em ordem de relevância
    return 1;
}
// int InsereBusca(TBusca * busca, int idDoc, double relevancia);

// Função auxiliar para trocar dois elementos de celulaDoc
void trocar(celulaDoc* a, celulaDoc* b) {
    celulaDoc temp = *a;
    *a = *b;
    *b = temp;
}

// Função auxiliar para particionar o array e obter o índice do pivô
int particionar(celulaDoc doc[], int esq, int dir) {
    float pivo = doc[dir].relevancia; // Define o pivô como o valor de relevancia do último elemento
    int i = esq - 1;

    for (int j = esq; j <= dir - 1; j++) {
        if (doc[j].relevancia >= pivo) {
            i++;
            trocar(&doc[i], &doc[j]); // Troca os elementos maiores ou iguais ao pivô para a esquerda
        }
    }
    trocar(&doc[i + 1], &doc[dir]); // Coloca o pivô na posição correta
    return (i + 1); // Retorna o índice do pivô
}

// Função principal do algoritmo QuickSort para ordenação do array de documentos por relevância
void quicksort(celulaDoc doc[], int esq, int dir) {
    if (esq < dir) {
        int pi = particionar(doc, esq, dir); // Obtém o índice do pivô
        quicksort(doc, esq, pi - 1); // Chama a função recursivamente para a partição da esquerda
        quicksort(doc, pi + 1, dir); // Chama a função recursivamente para a partição da direita
    }
}

// Imprime os documentos em ordem de relevância usando o algoritmo QuickSort para ordenação
void printaEmOrdemMaisRelevante(Tdocumento* doc) {
    quicksort(doc->doc, 0, doc->fim - 1); // Ordena os documentos por relevância usando o QuickSort

    for (int i = 0; i < doc->fim; i++) {
        printf("Documento %d: %f\n", doc->doc[i].idDoc, doc->doc[i].relevancia); // Imprime o ID do documento e sua relevância
    }
}



/*
void printaEmOrdemMaisRelevante(Tdocumento* doc){
    int i, j;
    for(i=0; i<doc->fim; i++){
        for(j=0; j<doc->fim; j++){
            if(doc->doc[i].relevancia > doc->doc[j].relevancia){
                celulaDoc aux = doc->doc[i];
                doc->doc[i] = doc->doc[j];
                doc->doc[j] = aux;
            }
        }
    }
    for(i=0; i<doc->fim; i++){
        printf("Documento %d: %f\n", doc->doc[i].idDoc, doc->doc[i].relevancia);
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
*/