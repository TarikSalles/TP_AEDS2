// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto 

#include "Patricia.h"

char Pegar_Caractere_Indice(int index, ChaveTipo k){
  if ((int)strlen(k) <= index)
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


short EExterno(Arvore p){ /* Verifica se p^ e nodo externo */
  return (p->nt == Externo);
}

Arvore CriaNoInt(int i, Arvore *Esq,  Arvore *Dir, char caract)
{ Arvore p;
  p = (Arvore)malloc(sizeof(PatNo));
  p->nt = Interno;
  p->NO.NInterno.Esq = *Esq;
  p->NO.NInterno.Dir = *Dir;
  p->NO.NInterno.Index = i;
  p->NO.NInterno.caract = caract;
  return p;
} 
Arvore CriaNoExt(ChaveTipo k)
{ Arvore p;
  p = (Arvore)malloc(sizeof(PatNo));
  p->nt = Externo;
  p->NO.Chave = k;
  return p;
}
void Pesquisa(ChaveTipo k, Arvore t)

{
  
  if (EExterno(t)) 
  { if (strncmp(k,t->NO.Chave,(int)strlen(k)) ==0){
    printf("Elemento encontrado\n");
  }
    else{
      printf("%s",t->NO.Chave);
      printf("Elemento nao encontrado\n");
    }
    return NULL;
  } 
  if(Pegar_Caractere_Indice(t->NO.NInterno.Index,k) <= t->NO.NInterno.caract)
      return Pesquisa(k,t->NO.NInterno.Esq);
  else return Pesquisa(k,t->NO.NInterno.Dir);
}

Arvore InsereEntre(ChaveTipo k, Arvore *t, int i)
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
        p = CriaNoExt(k);
        if (Pegar_Caractere_Indice(i, k) <= caract)
            return (CriaNoInt(i,&p,t,Pegar_Caractere_Indice(i, k)));
        else return (CriaNoInt(i,t,&p,caract));
  } 
  else 
    { 
        if (Pegar_Caractere_Indice((*t)->NO.NInterno.Index, k) <= (*t)->NO.NInterno.caract)
            (*t)->NO.NInterno.Esq = InsereEntre(k,&(*t)->NO.NInterno.Esq,i);
        else
            (*t)->NO.NInterno.Dir = InsereEntre(k,&(*t)->NO.NInterno.Dir,i);
        return (*t);
    }
}

Arvore Insere(ChaveTipo k, Arvore *t)
{ Arvore p;
  int i;
  if (*t == NULL)
  return (CriaNoExt(k));
  else 
    { p = *t;
      while (!EExterno(p)) {
         if (Pegar_Caractere_Indice(p->NO.NInterno.Index,k) <= p->NO.NInterno.caract)
                p = p->NO.NInterno.Esq;
            else 
                p = p->NO.NInterno.Dir;
        }
      i= 0;
    if(strlen(k)>strlen(p->NO.Chave)){
              
            while ((i <=(int) strlen(k)) && (Pegar_Caractere_Indice(i, k) == Pegar_Caractere_Indice(i, p->NO.Chave)))
                i++;
        
              if (i >=(int) strlen(k)){
                printf("Chave esta na arvore");
                return (*t);
              }
              else {
              
                return (InsereEntre(k, t, i));
              }
        } 
     else{ /* Else inutil, checar*/
              while ((i <= (int)strlen(p->NO.Chave)) && (Pegar_Caractere_Indice(i, k) == Pegar_Caractere_Indice(i, p->NO.Chave)))
                i++;
        
              if (i >= (int)strlen(p->NO.Chave)){
                printf("Chave esta na arvore");

                return (*t);
              }
            else {
                return (InsereEntre(k, t, i));
            }
        }



    }

}
void printPalavra(Arvore no)
{
    if(no == NULL)
        printf("No Nulo\n");
    else if(no->nt == Externo){
        printf("Chave:%s ",no->NO.Chave);
        pesquisa_palavra(no,no->NO.Chave);

    }
    
}

void Ordem(Arvore ap)
{

    if(ap == NULL)
        return;
    if(!EExterno(ap))
        Ordem(ap->NO.NInterno.Esq);
    printPalavra(ap);
    if(!EExterno(ap))
        Ordem(ap->NO.NInterno.Dir);
}
void insere_palavra(Arvore * raiz, const char *palavra){
  ChaveTipo chave = (ChaveTipo) malloc(30);
  strcpy(chave,palavra);
  *raiz= Insere(chave,raiz);


}
void pesquisa_palavra(Arvore raiz, const char *palavra){
  ChaveTipo chave = (ChaveTipo) malloc(30);
  strcpy(chave,palavra);
  Pesquisa(chave,raiz);

}
