#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitorArquivo.h"
#include "leitorString.h"



void teste2(){
    char token[50];
    LeitorString* l = leitorArquivo_criar("aaaa;bbb-cccc ccccc # dddd ", ';');
    leitorString_adicionaDelimitador(l, '-');
    //leitorString_adicionaDelimitador(l, '#');

    while(leitorString_temMais(l)){
        leitorString_ler(l, token);
        printf("[%s]\n", token);
    }

    //[aaaa]
    //[bbb]
    //[cccc ccccc ]
    //[ dddd ]

}


int main(){
    
    char linha[500];
    LeitorArquivo* l1 = leitorArquivo_criar("arquivo.txt", 5);
    while(leitorArquivo_temMaisLinhas(l1)){
        leitorArquivo_ler(l1, linha);
        printf("[%s]\n", linha);
    }
    leitorArquivo_desalocar(l1);


    //[aaaaaaaaa aaaaaa]
    //[bbbbbbbbb]
    //[ccccc]
}