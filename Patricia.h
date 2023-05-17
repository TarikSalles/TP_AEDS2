#include <stdlib.h> 
#include <time.h>
#include <stdio.h>
#include <string.h>
#define D               8   /* depende de ChaveTipo */
typedef  char * ChaveTipo;
   /* a definir, dependendo da aplicacao */
typedef unsigned char IndexAmp;

typedef unsigned char Dib;

typedef enum {
  Interno, Externo
} NoTipo;
typedef struct PatNo* Arvore;
 
typedef struct PatNo {
  NoTipo nt;
  union {
    struct {
      IndexAmp Index;
      char caract;
      Arvore Esq, Dir;
    }NInterno ;
    ChaveTipo Chave;
  } NO;
} PatNo;


char Pegar_Caractere_Indice(int index, ChaveTipo k);
short EExterno(Arvore p);
Arvore CriaNoInt(int i, Arvore *Esq,  Arvore *Dir, char caract);
Arvore CriaNoExt(ChaveTipo k);
void Pesquisa(ChaveTipo k, Arvore t);
Arvore InsereEntre(ChaveTipo k, Arvore *t, int i);
Arvore Insere(ChaveTipo k, Arvore *t);
void printPalavra(Arvore no);
void Ordem(Arvore ap);
void insere_palavra(Arvore * raiz, const char *palavra);
void pesquisa_palavra(Arvore raiz, const char *palavra);