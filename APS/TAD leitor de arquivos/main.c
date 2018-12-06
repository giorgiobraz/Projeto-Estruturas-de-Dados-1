#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitorArquivo.h"
#include "leitorString.h"

int main(){
    char* recebe;
    char* mostrar;
    LeitorArquivo* leitorArq = leitorArquivo_criar("Sadtxt", 21);
    LeitorString* leitorStr = leitorString_criar(recebe, D);          

    while(leitorArquivo_ler(leitorArq) == 1){
        printf("-%s----//",leitorArq->buffer);
        printf("\n");
    }
    
    leitorString_desalocar(leitorStr);
    leitorArquivo_desalocar(leitorArq);
}