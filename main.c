#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vetorOrdem.h"
#include "leitorString.h"
#include "leitorArquivo.h"
/**********************************************************************************/
/*                            	  	PROTOTIPOS                             	      */
/**********************************************************************************/
LeitorString* leitorString_criar(char* str, char delimitador);      	   /* [ ] */
void leitorString_desalocar(LeitorString* leitor);						   /* [ ] */
int leitorString_ler(LeitorString* leitor, char* endereco);				   /* [ ] */
int leitorString_temMais(LeitorString* leitor);						       /* [ ] */
void leitorString_adicionaDelimitador(LeitorString* l, char delimitador);  /* [ ] */
/**********************************************************************************/
LeitorArquivo* leitorArquivo_criar(char* arquivo, int tamBuffer);		   /* [ ] */
void leitorArquivo_desalocar(LeitorArquivo* leitor);					   /* [ ] */
int leitorArquivo_ler(LeitorArquivo* leitor, char* endereco);			   /* [ ] */
int leitorArquivo_temMaisLinhas(LeitorArquivo* leitor);					   /* [ ] */
/**********************************************************************************/
/*                              		MAIN                               	      */
/**********************************************************************************/
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

void main(){
    // Vetor* array = vetor_criarParcialOrdenado(TAM, 50);
    // vetor_ordenarSelection(array);
    // desaloca(array);
}