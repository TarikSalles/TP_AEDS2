// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "headers/busca.h"

//? gcc .\headers\lista.h .\headers\documento.h .\headers\busca.h .\headers\Patricia.h .\sources\busca.c .\sources\documento.c .\sources\lista.c .\sources\Patricia.c .\main.c -o run


int Inicializa_geral(Arvore * raiz, Tdocumento * documento, TBusca * busca);
int Leitura(FILE * arq, Arvore * raiz, Tdocumento * documento);

int main(){
    //Cabecalho dos tads
    Arvore raiz;
    Tdocumento documento;
    TBusca busca;
    FILE * arq;

    // ? Funcao de inicializaçao
    Inicializa_geral(&raiz, &documento, &busca);

    // ? Funcao de leitura
    Leitura(arq, &raiz, &documento);


    Ordem(raiz);

    calculoRelevancia(raiz, "carro", &documento, &busca);
    calculoRelevancia(raiz, "the", &documento, &busca);
    calculoRelevancia(raiz, "great", &documento, &busca);
    calculoRelevancia(raiz, "a", &documento, &busca);
    calculoRelevancia(raiz, "is", &documento, &busca);
    calculoRelevancia(raiz, "ropper is a", &documento, &busca);
    calculoRelevancia(raiz, "is", &documento, &busca);

    return 0;
}

int Inicializa_geral(Arvore * raiz, Tdocumento * documento, TBusca * busca){
    Inicializar_Arvore(raiz);
    inicializaDoc(documento);
    InicializaBusca(busca);
    return 0;
}

int Leitura(FILE * arq, Arvore * raiz, Tdocumento * documento){
    //cabecalhos de constantes na main
    char path_arquivo[300], string[150] , string_tratada[150], string_nome_arquivo[150];
    int index_do_arquivo = 0, contador = -1, tamanho_string, c; //auxilia na verificação de qual arquivo se está lendo
    /** Explicações:
     * string = guarda as strings provenientes da leitura do arquivo
     * string_tratada = string sem ';'
     * contador = conta o "estagio" da leitura do arquivo(necessario para saber quando trata-se de uma string ou de um index de arquivo)
     * index_do_arquivo = autoexplicativo
     * tamanho_string = auto_explicativo
     */
    printf("Digite o path do arquivo:\n");

    // ! scanf("%s",&path_arquivo);
    strcpy(path_arquivo,"Data/sem_pontuacao_reduzido.txt");

    //Abertura e verificacao do estado do arquivo
    arq = fopen(path_arquivo, "r");
    if (arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return 1;
    }

    while(fscanf(arq,"%s",string) != EOF){

        tamanho_string = strlen(string);

        if (string[tamanho_string-1] == ';'){
            //Cada arquivo tem 3 partes: Index, titulo e abstract. Isso explica o porque do mod 3
            contador = (contador + 1)%4; 

            //remove o ';' da string:
            for (c = 0; c < (tamanho_string - 1); c++){
                if(isalnum(string[c])){
                    string_tratada[c] = tolower(string[c]);
                }
                else{
                    string_tratada[c] = string[c];
                }
            }
            //Substitui o ';' pelo '\0'

            //Atualiza string para ser a string tratada
            strcpy(string, string_tratada);
            string[tamanho_string-1] = '\0';

            //caso esteja no estado de leitura do index:
            if (contador == 0){
                index_do_arquivo = atoi(string);
                continue;
            }
            if (contador == 1){
                strcpy(string_nome_arquivo, string);
                continue;
            }

        }
        else{
            for (c = 0; c < (tamanho_string); c++){
                if(isalnum(string[c])){
                    string_tratada[c] = tolower(string[c]);
                }
                else{
                    string_tratada[c] = string[c];
                }
            }
            strcpy(string,string_tratada);
            string[tamanho_string] = '\0';
        }
        Insere_Palavra_Arvore(raiz, string , index_do_arquivo, string_nome_arquivo, documento);
    }
    fclose(arq);
    return 0;
}

