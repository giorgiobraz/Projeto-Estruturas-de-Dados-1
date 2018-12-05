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
/***********************************************************************************/
/*                                  IMPLEMENTACAO                                  */
/***********************************************************************************/
LeitorString* leitorString_criar(char* str, char delimitador) {
    LeitorString* l1 = (LeitorString*) malloc(sizeof(LeitorString));
    l1->str = (char*) calloc (strlen(str)+1,sizeof(char)); // srtlen nao inclui '\0'
    strcpy(l1->str, str);
    l1->delimitadores[0] = delimitador;
    l1->tamStr = 20;
    l1->pos = 0;
    return l1;
}
/***********************************************************************************/
void leitor_desalocar(LeitorToken* leitor) {
    free(leitor->str);
    free(leitor);
}
/***********************************************************************************/
int leitorString_ler(LeitorString* leitor, char* endereco){{
    int inicio, fim, tamToken;
    inicio = leitor->pos;
    char c = leitor->string[leitor->pos];

    while(leitor->pos < leitor->tamString && !ehDelimitador(leitor, c)){
        c = leitor->string[++leitor->pos];
    }

    fim = leitor->pos++;
    tamToken = fim - inicio;

    strncpy(endereco, leitor->string+inicio, tamToken);
    endereco[tamToken] = '\0';
    return 1;
}
int leitorString_ler(LeitorString* leitor, char* endereco){
    endereco = (char*) calloc(leitor->tamStr,sizeof(char));
    int i=0;
    while(!ehDelimitador(char* delimitadores, char c)) {
        if (leitor->pos >= leitor->tamStr) break;
        endereco[i] = leitor->str[leitor->pos++]; // cópia -> pós-incremento
        i++;
    }
    endereco[i] = '\0';
    leitor->pos++;
    return 1;
}
/***********************************************************************************/
int leitorString_temMais(LeitorToken* leitor) {
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
    int pos = strlen(leitor->delimitadores);
    leitor->delimitadores[pos] = delimitador;
    leitor->delimitadores[pos+1] = '\0';
}


