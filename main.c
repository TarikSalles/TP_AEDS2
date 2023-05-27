#include "Tad_busca/busca.h"

int main() {
    Arvore raiz;
    Tdocumento doc;
    TBusca busca;
    Inicializar_Arvore(&raiz);
    inicializaDoc(&doc);
    InicializaBusca(&busca);
    // Inserção de palavras na árvore
    Insere_Palavra_Arvore(&raiz, "carro", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "casa", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "cadeira", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "computador", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "laranja", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "livro", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "mesa", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "celular", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "teclado", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "mouse", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "lapis", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "abacate", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "banana", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "abacaxi", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "laranja", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "morango", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "limao", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "manga", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "uva", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "pera", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "laranja", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "kiwi", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "manga", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "carro", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "manga", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "carro", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "casa", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "cadeira", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "computador", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "livro", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "mesa", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "celular", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "teclado", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "mouse", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "lapis", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "abacate", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "banana", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "abacaxi", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "laranja", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "morango", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "limao", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "manga", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "uva", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "pera", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "kiwi", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "manga", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "carro", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "manga", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "abacate", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "banana", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "laranja", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "limao", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "abacaxi", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "uva", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "laranja", 2, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "pera", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "kiwi", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "abacate", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "banana", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "laranja", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "limao", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "abacaxi", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "uva", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "pera", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "kiwi", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "manga", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "abacate", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "banana", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "laranja", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "limao", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "abacaxi", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "uva", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "pera", 2, "arquivo2.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "kiwi", 3, "arquivo3.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "monitor", 1, "arquivo1.txt", &doc);
    Insere_Palavra_Arvore(&raiz, "laranja", 3, "arquivo1.txt", &doc);

    // Impressão em ordem das palavras na árvore
    Ordem(raiz);
    printf("quantidade de docs: %d\n", quantidadeDocs(&doc));
    //imprimeDoc(&doc, 1);
    //imprimeDoc(&doc, 2);
    //imprimeDoc(&doc, 3);
    // Busca por palavra
    printf("\nBusca por palavra: manga\n");
    calculoRelevancia(raiz, "manga", &doc, &busca);
    printf("\nBusca por palavra: carro\n");
    calculoRelevancia(raiz, "carro", &doc, &busca);
    printf("\nBusca por palavra: casa\n");
    calculoRelevancia(raiz, "casa", &doc, &busca);
    printf("\nBusca por palavra: mesa\n");
    calculoRelevancia(raiz, "mesa", &doc, &busca);
    printf("\nBusca por palavra: teclado\n");
    calculoRelevancia(raiz, "teclado", &doc, &busca);
    printf("\nBusca por palavra: mouse\n");
    calculoRelevancia(raiz, "mouse", &doc, &busca);
    printf("\nBusca por palavra: monitor\n");
    calculoRelevancia(raiz, "monitor", &doc, &busca);
    printf("\nBusca por palavra: laranja\n");
    calculoRelevancia(raiz, "laranja", &doc, &busca);
    return 0;
}
int maini(){

    int index_do_arquivo = 0;
    int contador = -1, tam, c; //auxilia na verificação de qual arquivo se está lendo
    char string[50] , string_aux[50], nome_do_arquivo[100];
    FILE * arq;
    Arvore raiz = NULL;

    printf("Digite o nome do arquivo que deseja ler:\n");
    scanf("%s", &nome_do_arquivo);

    arq = fopen(nome_do_arquivo, "r");

    if (arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return 1;
    }

    while(fscanf(arq,"%s",string) != EOF){
        tam = strlen(string);
        //printf("%d %c", tam, string[tam-1]);
        if (string[tam-1] == ';'){
            contador = (contador + 1)%3;
            //printf("Contador: %d\n", contador);
            if (contador == 0){
                index_do_arquivo += 1;
                continue;
            }
            for (c = 0; c < (tam - 1); c++){
                string_aux[c] = string[c];
            }
            string_aux[tam-1] = '\0';
            strcpy(string, string_aux);
        }
        printf("string: %s \nindex: %d\n\n", string, index_do_arquivo);
        //Insere(string, &raiz); 
        // Insere(string, index_do_arquivo, &raiz); 

    }

    fclose(arq);
    return 0;
}

/*
int main(){
   Arvore raiz = NULL;
   insere_palavra(&raiz,"oi");
   insere_palavra(&raiz,"teste");
   insere_palavra(&raiz,"teste123");
  Ordem(raiz);   
    return 1;
}
*/