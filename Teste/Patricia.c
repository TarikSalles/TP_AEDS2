// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto 
//C:\Users\tarik\OneDrive\Área de Trabalho\TP_AEDS2-Tarik\Tad_documento
#include "Patricia.h"
void Inicializar_Arvore(Arvore *p){
	/*Funcao para inicializar a Patricia */
	*p = NULL;
  
}
char Pegar_Caractere_Indice(int index, ChaveTipo k){ 

	/*Funcao com o objetivo de pegar o caractere na posicao index dentro de uma palavra, caso esse indice existir, 
    retorna o caractere, caso nao ,retorna nulo  */

  if ((int)strlen(k) <= index || index < 0)
      return NULL;
  return k[index];
}
/*
Dib Bit(IndexAmp i, ChaveTipo k)
{ // Retorna o i-esimo bit da chave k a partir da esquerda 
  int  c, j;
  if (i == 0)
  return 0;
  else 
    { c = k;
      for (j = 1; j <= D - i; j++)
	c /= 2;
      return (c & 1);
    }
} 
*/


short EExterno(Arvore p){ 
    /* Verifica se p e um no externo */

  return (p->nt == Externo);
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
    
  Arvore p;
  p = (Arvore)malloc(sizeof(PatNo)); //Alocacao de memoria
  p->nt = Externo; //No do tipo externo
  p->NO.Chave = k; //Sua palavra
  Inicializa(&(p->NO.tuplas));
  
  Insere(&((p)->NO.tuplas),idDoc);
  return p;
}
Arvore Pesquisa_Arvore(ChaveTipo k, Arvore t){

    

  if (EExterno(t))  //Se o no for externo
  { if (strncmp(k,t->NO.Chave,(int)strlen(k)) ==0){ 
    return t;
  }
    else{
      return NULL;
    }
  } 
  if(Pegar_Caractere_Indice(t->NO.NInterno.Index,k) <= t->NO.NInterno.caract){
      return Pesquisa_Arvore(k,t->NO.NInterno.Esq);
  }
  else{
      return Pesquisa_Arvore(k,t->NO.NInterno.Dir); //Caso nao for menor, analisamos seu filho direito
  }
}

Arvore InsereEntre_Arvore(ChaveTipo k, Arvore *t, int i,int idDoc)
{ Arvore p;
  char caract;
  if (EExterno(*t) || i < (*t)->NO.NInterno.Index) 
  { /* cria um novo no externo */
    if(EExterno(*t)){
            caract = Pegar_Caractere_Indice(i,(*t)->NO.Chave);
        }
        else{
          caract = (*t)->NO.NInterno.caract;
        }

        p = CriaNoExt(k,idDoc);
        if (Pegar_Caractere_Indice(i, k) <= caract)
            return (CriaNoInt(i,&p,t,Pegar_Caractere_Indice(i, k)));
        else return (CriaNoInt(i,t,&p,caract));
  } 
  else 
    { 
        if (Pegar_Caractere_Indice((*t)->NO.NInterno.Index, k) <= (*t)->NO.NInterno.caract)
            (*t)->NO.NInterno.Esq = InsereEntre_Arvore(k,&(*t)->NO.NInterno.Esq,i,idDoc);
        else
            (*t)->NO.NInterno.Dir = InsereEntre_Arvore(k,&(*t)->NO.NInterno.Dir,i,idDoc);
        return (*t);
    }
}

Arvore Insere_Arvore(ChaveTipo k, Arvore *t, int idDoc){

    /*Funcao com o objetivo de inserir palavra na PATRICIA*/
  Arvore p;
  int i;
  if (*t == NULL){//Caso a arvore for nula, cria-se um No externo, que sera nesse caso o unico elemento da arvore
  return (CriaNoExt(k,idDoc));
 
}else 
    { p = *t;
      while (!EExterno(p)) { //Enquanto nao encontrarmos um no externo seguimos na arvore

          /*Se o caractere na posicao index da palavra for menor do que o caractere no no interno analisado, 
         seguimos para o filho a esquerda */
         if (Pegar_Caractere_Indice(p->NO.NInterno.Index,k) <= p->NO.NInterno.caract)
                p = p->NO.NInterno.Esq;
            else  //Caso contrario seguimos para o filho a direita
                p = p->NO.NInterno.Dir;
        }
      i= 0;
    if(strlen(k)>strlen(p->NO.Chave)){ //Se a palavra analisada for maior do que a contida no No externo

              /*Incrementamos o inteiro i ate i ser maior que o tamanho da palavra analisada e o caractere na posicao i da palavra 
              analisada ser diferente do caractere na posicao i da palavra armazenada no No externo*/

            while ((i <=(int) strlen(k)) && (Pegar_Caractere_Indice(i, k) == Pegar_Caractere_Indice(i, p->NO.Chave))) 
                i++;
        
              if (i >=(int) strlen(k)){ //Se i for maior do que o tamanho da palavra analisada, a palavra ja esta na arvore
                printf("Chave ja esta na arvore");

                //Função que insere ou incrementa na tupla
                Insere(&((*t))->NO.tuplas,idDoc);
            
                return (*t);
              }
              else { //Caso contrario, inserimos ela na arvore
                
                return (InsereEntre_Arvore(k, t, i,idDoc));
              }
        } 
     else{  //Caso a palavra analisada ser menor que a contida no No externo

	        /*Incrementamos o inteiro i ate i ser maior que o tamanho da palavra analisada e o caractere na posicao i da palavra 
            analisada ser diferente do caractere na posicao i da palavra armazenada no No externo*/

              while ((i <= (int)strlen(p->NO.Chave)) && (Pegar_Caractere_Indice(i, k) == Pegar_Caractere_Indice(i, p->NO.Chave))) 
                i++;
        
              if (i >= (int)strlen(p->NO.Chave)){ //Se i for maior do que o tamanho da palavra analisada, a palavra ja esta na arvore
                printf("Chave esta na arvore");
                Insere(&((*t))->NO.tuplas,idDoc);
                return (*t);
              }
            else {
                return (InsereEntre_Arvore(k, t, i,idDoc));  //Caso contrario, inserimos ela na arvore
            }
        }



    }

}
void printPalavra(Arvore no) {

    /* Funcao com o objetivo de imprimir todas as palavras dentro da Patricia*/

    if(no == NULL)
        printf("No Nulo\n");
    else if(no->nt == Externo){
        printf("Chave:%s ",no->NO.Chave);
        Imprime_lista(&no->NO.tuplas);
        
        
    }
    
}

void Ordem(Arvore ap)
{
	/*Funcao com o objetivo de imprimir todas as palavras contidas na Patricia em ordem */

    if(ap == NULL)
        return;
    if(!EExterno(ap))
        Ordem(ap->NO.NInterno.Esq);
    printPalavra(ap);
    if(!EExterno(ap))
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
