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
