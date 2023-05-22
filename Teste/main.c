#include "Patricia.h"

int main(){
  Arvore raiz;
  Inicializar_Arvore(&raiz);
   Insere_Palavra_Arvore(&raiz,"oi",1);
   
   Ordem(raiz);   

    return 1;


}