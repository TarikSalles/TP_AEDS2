// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "../Tad_Patricia/Patricia.h"

typedef struct celulaDoc * Aponta_doc;
typedef struct celulaDoc{
    int idDoc;
    int totalTermos; // No momento da inserção da palavra, irá incrementar o total de termos distintos no documento
    double relevancia; // Será calculado no momento da busca
    Aponta_doc prox;
} celulaDoc;

typedef struct Tdocumento {
    Aponta_doc primeiro, ultimo;
    Arvore Patricia;
} Tdocumento;

// Inicializa a estrutura Tdocumento
int inicializaDoc(Tdocumento* doc);

// Insere um documento na estrutura Tdocumento
int insereDoc(Tdocumento* doc, int idDoc, int totalTermos);

// Insere uma palavra em um documento na árvore PATRICIA
int inserePalavraDoc(Tdocumento* doc, char* palavra, int idDoc);

// Calcula a relevância de cada documento em relação à entrada de busca
int relevancia(Tdocumento doc, Arvore raiz, char* entradaBusca, int numDocs);

// Imprime os documentos em ordem de relevância usando o algoritmo QuickSort para ordenação
void printaEmOrdemMaisRelevante(Tdocumento* doc);

// Função principal do algoritmo QuickSort para ordenação do array de documentos por relevância
void quicksort(celulaDoc doc[], int esq, int dir);

// Função auxiliar para particionar o array e obter o índice do pivô
int particionar(celulaDoc doc[], int esq, int dir);

// Função auxiliar para trocar dois elementos de celulaDoc
void trocar(celulaDoc* a, celulaDoc* b);

