/***********************************************************************/
/*                               ESTRUTURAS                            */
/***********************************************************************/
typedef struct{
	FILE *arquivo;
	char delimitador;
	char* buffer;
	int pos;
	int tamBuffer;
}FileScanner;
/***********************************************************************/
typedef struct{    
    FILE* arquivo;
    char* nomeArquivo;
    char delimitador;
    char* buffer;
    int tamBuffer;
    int pos;
}LeitorArquivo;
/***************************************************************************/
/*                                PROTOTIPOS                               */
/***************************************************************************/
LeitorArquivo* leitorArquivo_criar(char* arquivo, int tamBuffer);   /* [ ] */
void leitorArquivo_desalocar(LeitorArquivo* leitor);                /* [ ] */
int leitorArquivo_ler(LeitorArquivo* leitor, char* endereco);       /* [ ] */
int leitorArquivo_temMaisLinhas(LeitorArquivo* leitor);             /* [ ] */
/***************************************************************************/
/*                              IMPLEMENTACAO                              */
/***************************************************************************/