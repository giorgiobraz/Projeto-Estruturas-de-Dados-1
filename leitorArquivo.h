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
    
    int tamArquivo;
    int qtdLida;
    
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
        if(endereco[i] == '\r') // 'r' recursivo
            endereco[i] = '\0';
    }
    return 0;
}
/***************************************************************************/
int leitorArquivo_preencherBuffer(LeitorArquivo* leitor){

    //int qtdeLida = fread(leitor->buffer, sizeof(char), leitor->tamBuffer, leitor->arquivo);
    // leitor->buffer[qtdeLida] = '\0';

    fgets(leitor->buffer, leitor->tamBuffer-1, leitor->arquivo); // enche o buffer
    // 
    // printf () // qtde x buffer carregado


    // leitor->buffer[leitor->tamBuffer-2] = '\0'; // tratando quebra de linha.

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