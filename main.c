// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto 

#include "Patricia.h"

/*
void menu(){
    int opcao;
    printf("Menu:\n");
    printf("1 - Receber arquivo de entrada\n");
    printf("2 - Construir índice invertido\n");
    printf("3 - Imprimir índice invertido\n");
    printf("4 - Realizar busca por termo(s)\n");
    printf("5 - Sair\n");
    while (1){
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
}
*/



int main(){

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
