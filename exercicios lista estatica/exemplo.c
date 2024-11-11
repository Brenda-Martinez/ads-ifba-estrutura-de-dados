#include <stdio.h>
#include <stdlib.h>
#define tam 5

typedef int apontador;

typedef struct{
    int valor;
}tipoDado;

typedef struct{
    tipoDado vDados[tam];
    apontador primeiro, ultimo;
}tipoLista;

int Lvazia(tipoLista l){
    return (l.primeiro == l.ultimo);
}

void inicializar(tipoLista *l){
    l -> primeiro = 0;
    l -> ultimo = l -> primeiro;
}

void inserir(tipoLista *l, tipoDado dado){
    if(l -> ultimo == tam){
        printf("ERRO!\a Lista cheia.");
    }else{
        l -> vDados[l -> ultimo] = dado;
        l -> ultimo++;
    }
}

int remover(tipoLista *l){
    int v;
    v = l -> vDados[l -> ultimo -1].valor;
    l -> ultimo--;
    return v;

    if(Lvazia(*l) == 1){
        return -1;
    }
}

void imprimir(tipoLista l){
    apontador aux;
    if(Lvazia(l) == 1){
        printf("Lista vazia.\a");
    }else{
        for(aux == l.primeiro; aux < l.ultimo; aux++){
            printf("\n%d . %d", aux, l.vDados[aux].valor);
        }
    }
}

int main()
{
    tipoLista teste;

    inicializar(&teste);
    imprimir(teste);
}
