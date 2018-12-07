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
LeitorArquivo* leitorArquivo_criar(char* arquivo, int tamBuffer);   /* [/] */
void leitorArquivo_desalocar(LeitorArquivo* leitor);                /* [/] */
// le a linha toda do arquivo.
int leitorArquivo_ler(LeitorArquivo* leitor, char* endereco);       /* [/] */
int leitorArquivo_temMaisLinhas(LeitorArquivo* leitor);             /* [/] */
// AUXILIAR
int leitorArquivo_preencherBuffer(LeitorArquivo* leitor);           /* [/] */

/***************************************************************************/
/*                              IMPLEMENTACAO                              */
/***************************************************************************/
LeitorArquivo* leitorArquivo_criar(char* arquivo, int tamBuffer){
    LeitorArquivo* leitor = (LeitorArquivo*)malloc(sizeof(LeitorArquivo));

    // pesquisar: strdup
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
void leitorArquivo_desalocar(LeitorArquivo* leitor){
    fclose(leitor->arquivo);
    free(leitor->nomeArquivo);
    free(leitor->buffer);
    free(leitor);
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
    return 0;
}
/***************************************************************************/
int leitorArquivo_temMaisLinhas(LeitorArquivo* leitor){
    if(feof(leitor->arquivo)) return 0; // arquivo chegou ao fim.
    return 1;
}
/***************************************************************************/
int leitorArquivo_preencherBuffer(LeitorArquivo* leitor){
    // verifica se cheguei no delimitador (buffer[i] == delim)
    // verifica se cheguei no fim do arquivo (arq == EOF)
    // verifica se completei o buffer (i < tam_buffer), neste caso preciso continuar executando esta funcao
    int i;
    char c;
    //fgets(leitor->buffer, leitor->tam_buffer-1, leitor->arquivo);

    for(i = 0; i < leitor->tamBuffer-2; i++){ // -1 para o '\0' do buffer.
        c = fgetc(leitor->arquivo);
        if(c == EOF || c == leitor->delimitador){
            leitor->buffer[i-1] = '\0';
            return 0;
        }
        leitor->buffer[i] = c;
    }
    
    return 1;
}