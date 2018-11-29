typedef struct{
    char* str;
    char delimitador;
    int qtdeString;
    int breakString;
}LeitorToken;

/***************************** PROTOTIPOS ******************************/
LeitorToken* leitor_criar(char* str, char delimitador);
void leitor_desalocar(LeitorToken* leitor);
char* leitor_consumir1(LeitorToken* leitor);
int leitor_temMais(LeitorToken* leitor);
void leitorString_adicionaDelimitador(LeitorString* l, char delimitador);
/*************************** IMPLEMENTACAO *****************************/
LeitorToken* leitor_criar(char* str, char delimitador) {
    LeitorToken* l1 = (LeitorToken*) malloc(sizeof(LeitorToken));
    l1->str = (char*) calloc (strlen(str)+1,sizeof(char)); // srtlen nao inclui '\0'
    strcpy(l1->str, str);
    l1->delimitador = delimitador;
    l1->qtdeString = 20;
    l1->breakString = 0;
    return l1;
}
/**********************************************************************/
char* leitor_consumir1(LeitorToken* leitor) {
    char* tmp = (char*) calloc(leitor->qtdeString,sizeof(char));
        int i=0;
    while(leitor->str[leitor->breakString] != leitor->delimitador) {
        if (leitor->breakString >= leitor->qtdeString) break;
        tmp[i] = leitor->str[leitor->breakString++]; // cópia -> pós-incremento
        i++;
    }
    tmp[i] = '\0';
    leitor->breakString++;
    return tmp;
}
/**********************************************************************/
int leitor_temMais(LeitorToken* leitor) {
    return (leitor->breakString < leitor->qtdeString);
}
/**********************************************************************/
void leitor_desalocar(LeitorToken* leitor) {
    free(leitor->str);
    free(leitor);
}
/**********************************************************************/
void leitorString_adicionaDelimitador(LeitorString* l, char delimitador){
    l->delimitador = delimitador;
}