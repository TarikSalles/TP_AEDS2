#include "Tad_busca/busca.h"

//Inicializa_geral(Arvore * raiz, Tdocumento * doc, Tbusca * busca);

int main(){
    //Cabecalho dos tads
    // Arvore raiz;
    // Tdocumento documento;
    // TBusca busca;
    
    FILE * arq;

    //cabecalhos da main
    char path_arquivo[300];
    char string[50] , string_aux[50];
    int index_do_arquivo = 0;
    int contador = -1, tam, c; //auxilia na verificação de qual arquivo se está lendo
    int index_convertido;


    //Funcoes de inicializaçao

    // Inicializa_geral(&raiz, &doc, &busca);
    // //! ISOLAR=========
    // Inicializar_Arvore(&raiz);
    // InicializaDoc(&doc);
    // InicializaBusca(&busca);
    // //! ISOLAR +++++++

    printf("Digite o path do arquivo:\n");
    //scanf("%s",&path_arquivo);
    strcpy(path_arquivo,"Data/sem_pontuacao_reduzido.txt");

    if (arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return 1;
    }

    arq = fopen(path_arquivo, "r");

    while(fscanf(arq,"%s",string) != EOF){
        tam = strlen(string);
        //printf("%d %c", tam, string[tam-1]);
        if (string[tam-1] == ';'){
            contador = (contador + 1)%3;
            //printf("Contador: %d\n", contador);
            for (c = 0; c < (tam - 1); c++){
                string_aux[c] = string[c];
            }
            string_aux[tam-1] = '\0';
            strcpy(string, string_aux);
            if (contador == 0){
                index_do_arquivo = atoi(string);
                continue;
            }

        }
        printf("string: %s \nindex: %d\n\n", string, index_do_arquivo);
    }
    //Insere_Palavra_Arvore(&raiz, "carro", 1, "arquivo1.txt", &documento);


    fclose(arq);
    return 0;
}
