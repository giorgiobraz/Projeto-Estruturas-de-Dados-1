#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitorArquivo.h"

int main(){
    char linha[50] = {0};
    LeitorArquivo* l1 = leitorArquivo_criar("arquivo.txt", 10);

    while(leitorArquivo_temMaisLinhas(l1)){
        leitorArquivo_ler(l1, linha);
        printf("[%s]\n", linha);
    }









    leitorArquivo_desalocar(l1);
	return 0;
}