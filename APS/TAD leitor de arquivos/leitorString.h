#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* str;
    char delimitadores[11];
    int tamStr;
    int pos;
}LeitorString;
/***********************************************************************************/
/*                                  PROTOTIPOS                                     */
/***********************************************************************************/
LeitorString* leitorString_criar(char* str, char delimitador);
void leitorString_desalocar(LeitorString* leitor);
int leitorString_ler(LeitorString* leitor, char* endereco);
int leitorString_temMais(LeitorString* leitor);
void leitorString_adicionaDelimitador(LeitorString* l, char delimitador);
int ehDelimitador(char* delimitadores, char c);
/***********************************************************************************/
/*                                  IMPLEMENTACAO                                  */
/***********************************************************************************/
LeitorString* leitorString_criar(char* str, char delimitador) {

    LeitorString* l1 = (LeitorString*) malloc(sizeof(LeitorString));
    l1->str = (char*) calloc (strlen(str)+1,sizeof(char)); // srtlen nao inclui '\0'
    strcpy(l1->str, str);
    l1->delimitadores[0] = delimitador;
    l1->delimitadores[1] = '\0';
    l1->tamStr = strlen(str);
    l1->pos = 0;
    return l1;
}
/***********************************************************************************/
void leitorString_desalocar(LeitorString* leitor) {
    free(leitor->str);
    free(leitor);
}
/***********************************************************************************/
int leitorString_ler(LeitorString* leitor, char* endereco){
    int inicio, fim, tamToken;
    inicio = leitor->pos;
    char c = leitor->str[leitor->pos];

    // while((leitor->pos < leitor->tamStr) && (!ehDelimitador(leitor->delimitadores, c))){
    //     c = leitor->str[++leitor->pos];
    // }
    while((leitor->pos < leitor->tamStr) && (!ehDelimitador(leitor->delimitadores, c))){
        c = leitor->str[leitor->pos];
        leitor->pos++;
    }

    //fim = leitor->pos++;
    fim = leitor->pos;

    tamToken = fim - inicio;

    endereco = (char*)malloc(tamToken * sizeof(char));

    
    for(int i = 0; i < tamToken; i++){
        endereco[i] = leitor->str[inicio+i];
        printf("%c", endereco[i]);
    }
    //strncpy(endereco, leitor->str+inicioç, tamToken);
    // endereco[tamToken] = '\0';
    return 1;
}
/***********************************************************************************/
int leitorString_temMais(LeitorString* leitor) {
    return (leitor->pos < leitor->tamStr);
}

int ehDelimitador(char* delimitadores, char c){
    int i;
    for(i=0; i<strlen(delimitadores); i++){
        if(c == delimitadores[i]){
            return 1;
        }
    }
    return 0;
}

void leitorString_adicionaDelimitador(LeitorString* l, char delimitador){
    int pos = strlen(l->delimitadores);
    l->delimitadores[pos] = delimitador;
    l->delimitadores[pos+1] = '\0';
}


