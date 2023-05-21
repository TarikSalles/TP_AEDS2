// Guilherme Broedel Zorzal, Tarik Salles Paiva, Danilo Matos de Oliveira, Alvaro Gomes da Silva Neto

#include "documento.h"

int inicializaDoc(Tdocumento* doc){
    doc->inicio = 0;
    doc->fim = 0;
    Inicializar_Arvore(&doc->Patricia);
    return 0;
}

int insereDoc(Tdocumento* doc, int idDoc, int totalTermos){
    doc->doc[doc->fim].idDoc = idDoc;
    doc->doc[doc->fim].totalTermos = totalTermos;
    doc->fim++;
    return 0;
}

int inserePalavraDoc(Tdocumento* doc, char* palavra, int idDoc){
    Insere_Palavra_Arvore(&doc->Patricia, palavra, idDoc);
}

float calculaRelevancia(Tdocumento doc, Arvore raiz, char* entradaBusca, int numDocs){
    int i;
    for(i=0; i<numDocs; i++){
        doc.doc[i].relevancia = 0;
        doc.doc[i].idDoc = i + 1;
        /*numTermos = strlen(entradaBusca) - 1;
        for(j=0; j<numTermos; j++)*/
        doc.doc[i].relevancia += (1/doc.doc[i].totalTermos) * termo(raiz, entradaBusca, numDocs, idDoc); //precisa ter alguma função que calcula no numero de termos em cada documento
        doc.fim++;
    }
}

void printaEmOrdemMaisRelevante(Tdocumento doc){
    int i, j;
    for(i=0; i<doc.fim; i++){
        for(j=0; j<doc.fim; j++){
            if(doc.doc[i].relevancia > doc.doc[j].relevancia){
                celulaDoc aux = doc.doc[i];
                doc.doc[i] = doc.doc[j];
                doc.doc[j] = aux;
            }
        }
    }
    for(i=0; i<doc.fim; i++){
        printf("Documento %d: %f\n", doc.doc[i].idDoc, doc.doc[i].relevancia);
    }
}

/*
float termo(Arvore* raiz, char* entradaBusca, int numDocs){
    char* token = strtok(entradaBusca, " ");
    Arvore* aux;
    float peso = 0;
    while(token != NULL){
        aux = Pesquisa(token, &raiz);
        if(aux)
            peso += pesoTermo(aux->lista.lista[i].num_ocorrencias, numDocs, aux->lista.fim);
        else
            peso += 0;
        token = strtok(NULL, " ");
    }
    return peso;
}

float pesoTermo(int numOcorrencias, int numDocs, int docsComTermo){
    if(numOcorrencias == 0)
        return 0;
    else
        return numOcorrencias * (log10(numDocs) / docsComTermo);
}
*/