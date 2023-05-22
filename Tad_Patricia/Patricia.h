// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto 

#include "../Tad_lista/lista.h"

#define D               8   /* depende de ChaveTipo */
#define MAX_WORD_LENGHT 30 //Numero maximo de caracteres de uma palavra
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
    struct {  //No interno armazena um caractere, index desse caractere, alem do endereco de seus filhos na esquerda e direita
      IndexAmp Index;
      char caract;
      Arvore Esq, Dir;
    }NInterno;
    ChaveTipo Chave; //No externo armazena a palavra em si, com um tamanho fixo(MAX_WORD_LENGHT)
  } NO;
} PatNo;

/*--------------------------Prototipos--------------------------*/
char Pegar_Caractere_Indice(int index, ChaveTipo k);
short EExterno(Arvore p);
void Inicializar_Arvore(Arvore *p);
Arvore CriaNoInt(int i, Arvore *Esq,  Arvore *Dir, char caract);
Arvore CriaNoExt(ChaveTipo k);
Arvore Pesquisa_Arvore(ChaveTipo k, Arvore t);
Arvore InsereEntre_Arvore(ChaveTipo k, Arvore *t, int i);
Arvore Insere_Arvore(ChaveTipo k, Arvore *t);
void printPalavra(Arvore no);
void Ordem(Arvore ap);
void Insere_Palavra_Arvore(Arvore * raiz, const char *palavra, int IdDoc);
void Pesquisa_Palavra_Arvore(Arvore raiz, const char *palavra);
float termo(Arvore raiz, char* entradaBusca, int numDocs, int idDoc);
float pesoTermo(int numOcorrencias, int numDocs, int docsComTermo);

/*--------------------------Prototipos--------------------------*/
