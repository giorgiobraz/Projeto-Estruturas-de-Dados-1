#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitorArquivo.h"

int main(){
    char linha[5000];
    LeitorArquivo* l1 = leitorArquivo_criar("algoritmo.md", 500);

    while(leitorArquivo_temMaisLinhas(l1)){
        leitorArquivo_ler(l1, linha);
        printf("%s\n", linha);
    }

    leitorArquivo_desalocar(l1);
	return 0;
}