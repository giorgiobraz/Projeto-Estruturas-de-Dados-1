/***********************************************************************/
/*                               ESTRUTURAS                            */
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
// le a linha toda do arquivo.
int leitorArquivo_ler(LeitorArquivo* leitor, char* endereco);       /* [ ] */
int leitorArquivo_temMaisLinhas(LeitorArquivo* leitor);             /* [ ] */
/***************************************************************************/
/*                              IMPLEMENTACAO                              */
/***************************************************************************/