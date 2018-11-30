#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vetorOrdem.h"
#define tam 243000
// #include "leitorString.h"

void main(){
    Vetor* array = vetor_criarParcialOrdenado(tam, 50);
    vetor_ordenarBuble(array);
    desaloca(array);
}
