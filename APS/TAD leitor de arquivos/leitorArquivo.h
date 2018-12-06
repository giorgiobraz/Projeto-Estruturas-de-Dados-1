#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define D '/'

typedef struct{    
    FILE* arquivo;
    char* nomeArquivo;
    char delimitador;
    char* buffer;
    int tamBuffer;
    int pos;
}LeitorArquivo;


//PROTOTIPOS
LeitorArquivo* leitorArquivo_criar(char* arquivo, int tamBuffer);
void leitorArquivo_desalocar(LeitorArquivo* leitor);
int leitorArquivo_ler(LeitorArquivo* leitor, char* endereco);
int leitorArquivo_temMaisLinhas(LeitorArquivo* leitor);

//IMPLEMENTACAO
LeitorArquivo* leitorArquivo_criar(char* arquivo, int tamBuffer){
	LeitorArquivo* leitor = (LeitorArquivo*)malloc(sizeof(LeitorArquivo));

	leitor->nomeArquivo = (char*)calloc(strlen(arquivo), sizeof(char));
	strcpy(leitor->nomeArquivo, arquivo);

	leitor->tamBuffer = tamBuffer;
	leitor->buffer = (char*)calloc(tamBuffer, sizeof(char));
	leitor->pos = 1;
	leitor->delimitador = D;

	leitor->arquivo = fopen("arquivo.txt", "r");
    return leitor;
}

void leitorArquivo_desalocar(LeitorArquivo* leitor){
    fclose(leitor->arquivo);
    free(leitor->arquivo);
    free(leitor->nomeArquivo);
    free(leitor->buffer);
    free(leitor);
}

int leitorArquivo_ler(LeitorArquivo* leitor, char* endereco){
    int i;
    if(leitor->pos > leitor->tamBuffer){
        while(leitor->buffer[leitor->pos] != D){
            leitor->pos--;
        }
        for(i = leitor->pos; i < leitor->tambuffer; i++){
            if((leitor->buffer[i] = fgetc(leitor->arquivo)) == EOF) break;
        }
        leitor->pos = i;
        leitor->buffer[leitor->pos] = '\0'; 
        return 1;
    }
    return 0;
}

int leitorArquivo_temMaisLinhas(LeitorArquivo* leitor){
    char* endereco;
    int retornar = leitorArquivo_ler(leitor, &endereco);
    return retornar;
}