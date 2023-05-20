//
// Created by alvaro on 5/19/23.
//
#include <stdio.h>
#include <string.h>

void calculaRelevancia(char* entradaBusca){
    //char string[];
    //int tamanho = strlen(entradaBusca);
    //int i=0;
    //string = strtok(entradaBusca, " ");
    char *token = strtok(entradaBusca, " ");
    printf("\n\n%d", strlen(token));
    while(token != NULL){
        printf("\n%s", token);
        token = strtok(NULL, " ");
    }

}

int main(){
    char frase[30] = "alvaro arthur carlos oi aviao";
    calculaRelevancia(frase);

    /*char *token = strtok(frutas, ",");
    for(int i = 0; i < tamanho; i++){
        //printf(token[i] == 0? "\\0" : "%c", token[i]);
    }
    while(token != NULL){
        printf("\n%s", token);
        token = strtok(NULL, ",");
    }*/
    //printf("\n\n%s", token);
}