#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	FILE *arquivo;
	char delimitador;
	char* buffer;
	int pos;
	int tamBuffer;

}FileScanner;


typedef struct {
	FILE* arquivo;
	char* nomeArquivo;
	char delimitador;
	char* buffer;
	int tamBuffer;
	int pos;
}LeitorArquivo;


//PROTOTIPOS
LeitorArquivo* leitorArquivo_criar(char* arquivo, int tamBuffer)

{

	LeitorArquivo* leitor = (LeitorArquivo*)malloc(sizeof(LeitorArquivo));

	leitor->nomeArquivo = (char*)malloc(sizeof(arquivo));
	strcpy(leitor->nomeArquivo, arquivo);

	leitor->tamBuffer = tamBuffer;
	leitor->buffer = (char*)calloc(tamBuffer, sizeof(char));
	leitor->pos = 0;
	leitor->delimitador = '\0';

	leitor->arquivo = fopen(arquivo, "r");
	fclose(leitor->arquivo);

	
	
}