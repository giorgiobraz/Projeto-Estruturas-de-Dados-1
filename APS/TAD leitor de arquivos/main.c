#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitorArquivo.h"
#include "leitorString.h"

int main(){
    char* recebe;
    LeitorArquivo* leitorArq = leitorArquivo_criar("Sadtxt", 20);
    leitorArquivo_ler(leitorArq, recebe);
    LeitorString* leitorStr = leitorString_criar(recebe, D);
    
    while(leitorString_temMais(leitorStr)){
        leitorString_ler(leitorStr, recebe);
        printf("-%s--",recebe);          
    }
    printf("\n");
    
    leitorString_desalocar(leitorStr);
    leitorArquivo_desalocar(leitorArq);
}