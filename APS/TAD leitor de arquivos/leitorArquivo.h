#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void leitorArquivo_desalocar(LeitorArquivo* leitor){
    free(leitor->arquivo);
    free(leitor->nomeArquivo);
    free(leitor->buffer);
    free(leitor);
}

void FileScanner_desalocar(FileScanner* scanner){
    free(scanner->arquivo);
    free(scanner->buffer);
    free(scanner);
}