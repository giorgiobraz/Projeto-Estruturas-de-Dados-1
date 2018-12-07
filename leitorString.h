/***********************************************************************/
/*                               ESTRUTURAS                            */
/***********************************************************************/
typedef struct{
    char* str;
    char delimitadores[11];
    int tamStr;
    int pos;
}LeitorString;
/***********************************************************************/
/*                              PROTOTIPOS                             */
/***********************************************************************/
LeitorString* leitorString_criar(char* str, char delimitador);
void leitorString_desalocar(LeitorString* leitor);
int leitorString_ler(LeitorString* leitor, char* endereco);
int leitorString_temMais(LeitorString* leitor);
void leitorString_adicionaDelimitador(LeitorString* l, char delimitador);
/***********************************************************************/
/*                            IMPLEMENTACAO                            */
/***********************************************************************/