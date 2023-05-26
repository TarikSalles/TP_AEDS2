// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto 

#include "Patricia.h"
void Inicializar_Arvore(Arvore *p){
	/*Funcao para inicializar a Patricia */
	*p = NULL;
}
char Pegar_Caractere_Indice(int index, ChaveTipo k){ 

	/*Funcao com o objetivo de pegar o caractere na posicao index dentro de uma palavra, caso esse indice existir, 
    retorna o caractere, caso nao ,retorna nulo  */

  if ((int)strlen(k) <= index || index < 0)
      return '\0';
  return k[index];
}

short EExterno(Arvore p){ 
    /* Verifica se p e um no externo */

  return (p->nt == Externo);
}
short EInterno(Arvore p){ 
    /* Verifica se p e um no externo */

  return (p->nt == Interno);
}

Arvore CriaNoInt(int i, Arvore *Esq,  Arvore *Dir, char caract) { 

/*Funcao que cria um No interno, passando para o mesmo seu respectivo indice e caractere, 
alem do endereco de seus filhos na esquerda e na direita */

Arvore p;
  p = (Arvore)malloc(sizeof(PatNo)); //Alocacao de memoria
  p->nt = Interno; //No do tipo interno
  p->NO.NInterno.Esq = *Esq; //Endereco filho esquerdo
  p->NO.NInterno.Dir = *Dir; //Endereco filho direito
  p->NO.NInterno.Index = i; //Seu indice
  p->NO.NInterno.caract = caract; //Seu caractere
  return p;
} 
Arvore CriaNoExt(ChaveTipo k,int idDoc){

/*Funcao que cria um No externo, passando para o mesmo sua respectiva palavra armazenada*/
  if (strlen(k) > MAX_WORD_LENGHT)
    return NULL;
  Arvore p;
  p = (Arvore)malloc(sizeof(PatNo)); //Alocacao de memoria
  p->nt = Externo; //No do tipo externo
  p->NO.Chave = (char*) malloc(MAX_WORD_LENGHT);
  
  strcpy(p->NO.Chave,k);
  p->NO.Chave =k; //Sua palavra
  Tlista Aux;
  Inicializa(&Aux);
  Insere(&Aux,idDoc);
  
   p->tuplas = Aux;
 
  return p;
}
Arvore Pesquisa_Arvore(ChaveTipo k, Arvore t){

  int tam_word = strlen(k);
  int index_char = t->NO.NInterno.Index;

  if (EExterno(t))  //Se o no for externo
  { if (strncmp(k,t->NO.Chave,(int)strlen(k)) ==0){ 

    return t;

  }
    else{
      return NULL;
    }
  } 
  if(tam_word < t->NO.NInterno.Index){
      return Pesquisa_Arvore(k,t->NO.NInterno.Esq);
  }
   else if (k[index_char] < t->NO.NInterno.caract)
  {
      return Pesquisa_Arvore(k,t->NO.NInterno.Esq);
  }
  else
  {
      return Pesquisa_Arvore(k,t->NO.NInterno.Dir);
  }
}

Arvore InsereEntre_Arvore(ChaveTipo k, Arvore *t, int i,char char_diferente,int idDoc)
{ Arvore p = NULL;
  char caract;

  if (EExterno(*t)) 
  { /* cria um novo no externo */
        p = CriaNoExt(k,idDoc);
        if(strcmp((*t)->NO.Chave,k) < 0){
          
          return CriaNoInt(i,t , &p,char_diferente);
        }
        else if(strcmp((*t)->NO.Chave,k) > 0){
          return CriaNoInt(i,&p , t,char_diferente);

        }
        return NULL;
  
}else if(i < (*t)->NO.NInterno.Index){
  p = CriaNoExt(k,idDoc);
  if(k[i] < char_diferente){
    return CriaNoInt(i,&p,t,char_diferente);
  }else{
    return CriaNoInt(i,t,&p,char_diferente);
  }
 
}else{
int Index_Mudado = (*t)->NO.NInterno.Index;
if(k[Index_Mudado] < (*t)->NO.NInterno.caract){
  
(*t)->NO.NInterno.Esq = InsereEntre_Arvore(k,&(*t)->NO.NInterno.Esq,i,char_diferente,idDoc);


}else{
  (*t)->NO.NInterno.Dir = InsereEntre_Arvore(k,&(*t)->NO.NInterno.Dir,i,char_diferente,idDoc);

}
return (*t);


}
}

Arvore Insere_Arvore(ChaveTipo k, Arvore *t, int idDoc){

    /*Funcao com o objetivo de inserir palavra na PATRICIA*/

  Arvore p;
  /*Talvez seja*/
  if (*t == NULL){ //Caso a arvore for nula, cria-se um No externo, que sera nesse caso o unico elemento da arvore
  return (CriaNoExt(k,idDoc));
  }else 
    { p = *t;
      int i;
      char aux;

      while (!EExterno(p)) { //Enquanto nao encontrarmos um no externo seguimos na arvore

          /*Se o caractere na posicao index da palavra for menor do que o caractere no no interno analisado, 
         seguimos para o filho a esquerda */
         if (Pegar_Caractere_Indice(p->NO.NInterno.Index,k) < p->NO.NInterno.caract)
                p = p->NO.NInterno.Esq;
          else if (Pegar_Caractere_Indice(p->NO.NInterno.Index,k) >= p->NO.NInterno.caract)
                p = p->NO.NInterno.Dir;
          else
                p = p->NO.NInterno.Esq;

        }
      i= 0;
    if(strcmp(p->NO.Chave,k) == 0){
       Insere(&p->tuplas,idDoc);
       printf("\nPalavra %s ja existe na Arvore\n",p->NO.Chave);
       return (*t);

    }else{
            printf("%s-%s",p->NO.Chave,k);

      char char_diferente;
      int menor_tamanho = (strlen(k) < strlen(p->NO.Chave)) ? strlen(k) : strlen(p->NO.Chave);
      for(i = 0; i <= menor_tamanho; i++){
        if(k[i] != p->NO.Chave[i]){
            if(k[i] < p->NO.Chave[i]){
              char_diferente = p->NO.Chave[i];
              break;
            }else{
              char_diferente = k[i];
              break;
            }

        }
      }
    return (InsereEntre_Arvore(k, t, i,char_diferente,idDoc)); 

    }
    
    }
    

}
void printPalavra(Arvore no) {

    /* Funcao com o objetivo de imprimir todas as palavras dentro da Patricia*/

    if(no == NULL)
        printf("No Nulo\n");
    else if(no->nt == Externo){
        printf("Chave:%s ",no->NO.Chave);
        Imprime_lista(&no->tuplas);
    }
    
}

void Ordem(Arvore ap)
{
	/*Funcao com o objetivo de imprimir todas as palavras contidas na Patricia em ordem */

    if(ap == NULL)
        return;
    if(EInterno(ap))
        Ordem(ap->NO.NInterno.Esq);
    printPalavra(ap);
    if(EInterno(ap))
        Ordem(ap->NO.NInterno.Dir);
}

void Insere_Palavra_Arvore(Arvore * raiz, const char *palavra,int idDoc){

	/*Funcao auxiliar com o objetivo de inserir uma palavra na Patricia, recebendo o endereco da Arvore em si 
    e um vetor constante char(String) como parametro */

  ChaveTipo chave = (ChaveTipo) malloc(MAX_WORD_LENGHT); //Aloca memoria para armazenar a palavra dentro do elemento chave
  strcpy(chave,palavra); //Funcao de string.h que passa a palavra para dentro do elemento chave
  *raiz= Insere_Arvore(chave,raiz, idDoc); //Chamamos a funcao Insere e atribuimos seu retorno(Nova Arvore) para a Arvore antiga
 

}
Arvore Pesquisa_Palavra_Arvore(Arvore raiz, const char *palavra){

		/*Funcao auxiliar com o objetivo de pesquisar uma palavra na Patricia, recebendo uma copia da Arvore em si 
        e um vetor constante char(String) como parametro */

  ChaveTipo chave = (ChaveTipo) malloc(MAX_WORD_LENGHT); //Aloca memoria para armazenar a palavra dentro do elemento chave
  strcpy(chave,palavra); //Funcao de string.h que passa a palavra para dentro do elemento chave
  return Pesquisa_Arvore(chave,raiz); //Chamamos a funcao Pesquisa

}
