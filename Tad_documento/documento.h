// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "../Patricia.h"
#define Max_tam_doc 4

typedef struct celulaDoc{
    int idDoc;
    int totalTermos; // No momento da inserção da palavra, irá incrementar o total de termos distintos no documento
    float relevancia; // Será calculado no momento da busca
} celulaDoc;

typedef struct Tdocumento * Aponta_doc;
typedef struct Tdocumento {
    celulaDoc doc[Max_tam_doc]; // Vetor de documentos
    int inicio, fim;
    Arvore Patricia;
}Tdocumento;

int inicializaDoc(Tdocumento* doc);
float calculaRelevancia(Tdocumento doc, Arvore raiz, char* entradaBusca, int numDocs);
/*
float termo(Arvore* raiz, char* entradaBusca, int numDocs);
float pesoTermo(int numOcorrencias, int numDocs, int docsComTermo);
*/
