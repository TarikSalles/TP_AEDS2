#include "Patricia.h"

int main(){
   Arvore raiz = NULL;
   insere_palavra(&raiz,"oi");
   insere_palavra(&raiz,"teste");
   insere_palavra(&raiz,"teste123");

  Ordem(raiz);   

    return 1;
}
