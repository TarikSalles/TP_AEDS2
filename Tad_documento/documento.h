// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto
#include "../Tad_lista/lista.h"

typedef struct celulaDoc * ApontaCelulaDoc;
typedef struct celulaDoc{
    int idDoc; // Identificador do documento
    int totalTermos; // No momento da inserção da palavra, irá incrementar o total de termos distintos no documento
    char nomeDoc[50];
    ApontaCelulaDoc prox;
} CDoc;

typedef struct documento {
    ApontaCelulaDoc primeiro, ultimo;
} Tdocumento;

int inicializaDoc(Tdocumento* doc);
int docVazio(Tdocumento* doc);
int insereDoc(Tdocumento*doc, int idDoc, char* nomeDoc);
int quantidadeDocs(Tdocumento * doc);
void imprimeDoc(Tdocumento* doc, int idDoc);