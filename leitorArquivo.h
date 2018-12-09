/***************************************************************************/
/*                                ESTRUTURAS                               */
/***************************************************************************/
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
LeitorArquivo* leitorArquivo_criar(char* arquivo, int tamBuffer);   /* [X] */
// le a linha toda do arquivo.
int leitorArquivo_ler(LeitorArquivo* leitor, char* endereco);       /* [/] */
int leitorArquivo_temMaisLinhas(LeitorArquivo* leitor);             /* [X] */
void leitorArquivo_desalocar(LeitorArquivo* leitor);                /* [X] */
// AUXILIAR
int leitorArquivo_preencherBuffer(LeitorArquivo* leitor);           /* [/] */

/***************************************************************************/
/*                              IMPLEMENTACAO                              */
/***************************************************************************/
LeitorArquivo* leitorArquivo_criar(char* arquivo, int tamBuffer){
    LeitorArquivo* leitor = (LeitorArquivo*)malloc(sizeof(LeitorArquivo));
    leitor->nomeArquivo = (char*)calloc(strlen(arquivo)+1, sizeof(char)); // strlen não atribui '\0'
    strcpy(leitor->nomeArquivo, arquivo);
    leitor->tamBuffer = tamBuffer + 1;
    leitor->buffer = (char*)calloc(tamBuffer, sizeof(char));
    leitor->pos = 1;
    leitor->delimitador = '\n'; // final da linha
    leitor->arquivo = fopen(arquivo, "r");
    return leitor;
}
/***************************************************************************/
int leitorArquivo_ler(LeitorArquivo* leitor, char* endereco){
    // ler uma linha inteira
    endereco[0] = '\0';
    int flag = 1;
    while(flag){
        flag = leitorArquivo_preencherBuffer(leitor);
        strcat(endereco, leitor->buffer);
    }
    int tamEnd = strlen(endereco);
    for(int i = 0; endereco[i] != '\0'; i++){
        if(endereco[i] == '\r')
            endereco[i] = '\0';
    }
    return 0;
}
/***************************************************************************/
int leitorArquivo_preencherBuffer(LeitorArquivo* leitor){

    fgets(leitor->buffer, leitor->tamBuffer-1, leitor->arquivo); // enche o buffer

    int readLen = strlen(leitor->buffer);
    if (leitor->buffer[readLen-1] == leitor->delimitador) {
        
        return 0;
    }
    if (!leitorArquivo_temMaisLinhas(leitor)) {
        return 0;
    }
    return 1;
}
/***************************************************************************/
int leitorArquivo_temMaisLinhas(LeitorArquivo* leitor){
    if(feof(leitor->arquivo)) return 0; // arquivo chegou ao fim.
    return 1;
}
/***************************************************************************/
void leitorArquivo_desalocar(LeitorArquivo* leitor){
    fclose(leitor->arquivo);
    free(leitor->nomeArquivo);
    free(leitor->buffer);
    free(leitor);
}