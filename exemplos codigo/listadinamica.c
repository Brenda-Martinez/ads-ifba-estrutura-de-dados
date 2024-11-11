#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num_matricula;
    char nome[80];
    float media;
}tipoDado;

typedef struct TipoNo *apontador;

typedef struct TipoNo{
    tipoDado dado;
    apontador proximo;
}TipoNo;

typedef struct{
    apontador primeiro, ultimo;
    int tam;
}tipoLista;

void inicializar(tipoLista *l){
    l->primeiro=(apontador) malloc(sizeof(TipoNo));
    l->ultimo = l->primeiro;
    l->ultimo->proximo = NULL;
    l->tam = 0;
}

void inserir(tipoLista *l, tipoDado valor){
    l->ultimo->proximo =(apontador) malloc(sizeof(TipoNo));
    l->ultimo = l->ultimo->proximo;
    l->ultimo->dado = valor;
    l->ultimo->proximo = NULL;
    l->tam++;
}

void imprimir(tipoLista l){
    apontador aux;
    aux = l.primeiro->proximo;
    while(aux =! NULL){
        printf("%d\n", aux->dado.num_matricula);
        aux = aux->proximo;
    }
}

void ordena(tipoLista *l){
    apontador aux;
    int aux2, menor = l.primeiro.dado;
    aux=l.primeiro->proximo;

}

void main(){

}
