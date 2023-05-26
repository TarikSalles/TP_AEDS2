// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto
#include "../Tad_lista/lista.h"

typedef struct celulaDoc * ApontaCelulaDoc;
typedef struct celulaDoc{
    int idDoc;                                  // Identificador do documento
    int totalTermos;                            // No momento da inserção da palavra, irá incrementar o total de termos distintos no documento
    char nomeDoc[50];
    ApontaCelulaDoc prox;
} CDoc;

typedef struct documento {
    ApontaCelulaDoc primeiro, ultimo;           // Ponteiros para a primeira e última célula da lista de documentos
} Tdocumento;

// Inicializa a lista de documentos
int inicializaDoc(Tdocumento* doc);

// Verifica se a lista de documentos está vazia
int docVazio(Tdocumento* doc);

// Insere um novo documento na lista
int insereDoc(Tdocumento*doc, int idDoc, char* nomeDoc);

// Calcula a quantidade de documentos na lista
int quantidadeDocs(Tdocumento * doc);

// Imprime as informações de um documento com base em seu ID
void imprimeDoc(Tdocumento* doc, int idDoc);
