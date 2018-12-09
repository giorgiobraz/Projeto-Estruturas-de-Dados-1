#include <time.h>
#define TAM 10

typedef enum boolean{false=0, true=1} Boolean;

typedef enum ordem{ASCENDENTE=0, DESCENDENTE=1} Ordem;

typedef struct{
    int* array;
    int tam;
    int qtde;
}Vetor;
/************************************************************************/
void randomArray(Vetor* v, int inf, int sup, int tamanho) {
    srand((unsigned) time(NULL));

    for (int i = v->qtde; i < tamanho; i++) {
        v->array[v->qtde] = (inf + (rand() % sup));
        v->qtde++;
    }
}
/************************************************************************/
void realoca(Vetor* v){
    if (v->qtde < v->tam) return;
    int novoTamanho = v->tam * 2;
    int qtdeBytes = novoTamanho * sizeof(int);
    int* tmp = (int*) calloc(novoTamanho,sizeof(int));
    memcpy(tmp,v->array,qtdeBytes);
    free(v->array);
    v->array = tmp;
    v->tam = novoTamanho;
}
/************************************************************************/
Vetor* vetor_criar(){
    Vetor* p = (Vetor*) malloc(sizeof(Vetor));
    p->array = (int*) calloc(TAM, sizeof(int));
    p->tam = TAM;
    p->qtde = 0;
    return p;
}
/************************************************************************/
Boolean vetor_append(Vetor* v, int elemento){
    realoca(v);
    v->array[v->qtde] = elemento;
    v->qtde++;
    return v->qtde == elemento;
}
/************************************************************************/
Boolean vetor_inserir(Vetor* v, int elemento, int posicao){
    realoca(v);
    for(int i = v->qtde+1; i > posicao; i--){
        v->array[i] = v->array[i-1];
    }
    v->array[posicao] = elemento;
    v->qtde++;
    v->tam++;
    return v->array[posicao] == elemento;
}
/************************************************************************/
Boolean vetor_alterar(Vetor* v, int posicao, int novoElemento){
   v->array[posicao] = novoElemento;
   return v->array[posicao] == novoElemento; 
}
/************************************************************************/
int vetor_posElemento(Vetor* v, int elemento){
    for(int i = 0; i < v->qtde; i++){
        if(v->array[i] == elemento) return i;
    }
    return -1;
}
/************************************************************************/
Boolean vetor_remover1(Vetor* v, int posicao, int* endereco){
    *endereco = v->array[posicao];
    for(int i = posicao; i <= v->qtde; i++){
        v->array[i] = v->array[i+1];
    }
    v->qtde--;
    return 1;
}
/************************************************************************/
int vetor_remover2(Vetor* v, int elemento){
    int posicao = vetor_posElemento(v,elemento);
    if(v->array[v->qtde] == elemento){
        v->qtde--;
        return 1;
    }
    for(int i = posicao; i <= v->qtde; i++){
        v->array[i] = v->array[i+1];
    }
    v->qtde--;
    return 1;
}
/************************************************************************/
int vetor_tamanho(Vetor* v){
    return v->qtde;
}
/************************************************************************/
void vetor_imprimir(Vetor* v){
    for(int i = 0; i < v->qtde; i++){
        printf("%d ",v->array[i]);
    }
    printf("\n");
}
/************************************************************************/
Vetor* vetor_criarParcialOdenado(int tam, int percentual){
    percentual = (percentual*tam/100);
    Vetor* vet = vetor_criar();
    for(int i = 0; i < percentual; i++){
        vet->array[i] = i;
        vet->qtde++;
    }
    randomArray(vet, 4, 20, tam);
    return vet;
}
/************************************************************************/
void desaloca(Vetor* v){
    free(v->array);
    free(v);
}
/************************************************************************/
Vetor* vetor_criarAleatorio(int tam) {
    Vetor* vet = vetor_criar();
    randomArray(vet, 1, 15, TAM);
    return vet;
}
/************************************************************************/
Vetor* vetor_criarOdenado(int tam, Ordem ordem){
    Vetor* vet = vetor_criar();
    vet->array = (int*) calloc(tam,sizeof(int));
    vet->qtde = tam;
    if (ordem == 0){
        for (int i = 0; i < vet->qtde; i++){
            vet->array[i] = i;
        }
    }
    else {
        int j=0;
        for (int i = vet->qtde-1; i >= 0; i--){
            vet->array[j++] = i;
        }
    }
    return vet;
}
/************************************************************************/
Vetor* vetor_clone(Vetor* v){
    Vetor* vClone = (Vetor*) malloc(sizeof(Vetor));
    int qtdeBytes = v->tam * sizeof(int);
    memcpy(vClone->array,v->array,qtdeBytes);
    vClone->tam = v->tam;
    vClone->qtde = v->qtde;
    return vClone;
}
/************************************************************************/
void vetor_ordenarBuble(Vetor* v){
    int i, fim;
    for (fim=v->qtde-1; fim>0; fim--) {
        int houve_troca = 0;
        for (i=0; i<fim; i++){
            if (v->array[i]>v->array[i+1]) {
                troca(&v->array[i], &v->array[i+1]);
                houve_troca = 1;
            }
        }
        if (!houve_troca) return;
    }
}
/************************************************************************/
void vetor_ordenarSelection(Vetor* v){
     int i, min;    
     for (i=0; i<v->qtde-1; i++){
         min = menorElemento(v->array, v->qtde, i);
         troca(&v->array[i], &v->array[min]);
     }
 }

 int menorElemento(int v[], int n, int indice){
     int i, min = indice;
     for(i=indice+1; i<n; i++){
         if(v[i] < v[min]){
             min = i;
         }
     }
     return min;
 }
/************************************************************************/
void vetor_ordenarInsertion(Vetor* v){
    int i,j;
    for(i=1; i < v->qtde; i++){
        int elemento = v->array[i];
        j = i - 1;
        while(j >= 0 && elemento < v->array[j]){
            v->array[j+1] = v->array[j];
            j--;        
        }
        v->array[j+1] = elemento;
    }
}