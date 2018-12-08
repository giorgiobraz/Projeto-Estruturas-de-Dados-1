#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitorArquivo.h"
#include "leitorString.h"


void teste1(){
    LeitorArquivo* leitorArq = leitorArquivo_criar("Sadtxt", 21);      
    char linha[300];
    while(leitorArquivo_temMaisLinhas(leitorArq)){
        leitorArquivo_ler(leitorArq, linha);
        printf("[%s]\n", linha);
    }

}


int main(){

    teste1();
    // char* recebe;
    // char* mostrar;
    // LeitorArquivo* leitorArq = leitorArquivo_criar("Sadtxt", 21);      
    // LeitorString* leitorStr;
   
    // //while(leitorArquivo_ler(leitorArq) == 1){
    // leitorArquivo_ler(leitorArq);    

  
    // leitorStr = leitorString_criar(leitorArq->buffer, D);
    
    // //while(leitorString_temMais(leitorStr)){
    // leitorString_ler(leitorStr, mostrar);
    // printf("-- [ %s ] --", mostrar);
    // //}
    // leitorString_desalocar(leitorStr);
    // //}
    
    // leitorArquivo_desalocar(leitorArq);
}