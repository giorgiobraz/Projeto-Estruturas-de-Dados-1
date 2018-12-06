#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitorString"

typedef struct{
	FILE *arquivo;
	char delimitador;
	char* buffer;
	int pos;
	int tamBuffer;

}FileScanner;


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
//MARIA: "Fiz uma função para desalocar o Scanner, mas não sei se é realmente necessário, se quiser fiquem a vontade para exclui-lo"
void FileScanner_desalocar(FileScanner* scanner);

//IMPLEMENTACAO
LeitorArquivo* leitorArquivo_criar(char* arquivo, int tamBuffer){
	LeitorArquivo* leitor = (LeitorArquivo*)malloc(sizeof(LeitorArquivo));

	leitor->nomeArquivo = (char*)malloc(sizeof(arquivo));
	strcpy(leitor->nomeArquivo, arquivo);

	leitor->tamBuffer = tamBuffer;
	leitor->buffer = (char*)calloc(tamBuffer, sizeof(char));
	leitor->pos = 0;
	leitor->delimitador = '\0';

	leitor->arquivo = fopen(arquivo, "r");
    return leitor;
}

void leitorArquivo_desalocar(LeitorArquivo* leitor){
    fclose(leitor->arquivo);
    free(leitor->arquivo);
    free(leitor->nomeArquivo);
    free(leitor->buffer);
    free(leitor);
}

void FileScanner_desalocar(FileScanner* scanner){
    fclose(scanner->arquivo);
    free(scanner->arquivo);
    free(scanner->buffer);
    free(scanner);
}

int leitorArquivo_ler(LeitorArquivo* leitor, char* endereco){
    
    return 0;
}