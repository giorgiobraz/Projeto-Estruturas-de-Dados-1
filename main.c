#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vetorOrdem.h"
// #include "leitorString.h"

void main(){
    Vetor* array = vetor_criarParcialOrdenado(TAM, 50);
    vetor_ordenarSelection(array);
    desaloca(array);
}
