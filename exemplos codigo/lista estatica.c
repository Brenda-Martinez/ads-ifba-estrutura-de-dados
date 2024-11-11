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

void remover(apontador p, tipoLista *Lista, tipoDado *Item)
{
    int Aux;
    *Item = Lista->vDados[p - 1];
    for (Aux = p; Aux < Lista->ultimo; Aux++){
        Lista->vDados[Aux - 1] = Lista->vDados[Aux];
    }
    Lista->ultimo--;
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
    tipoDado x;
    tipoDado y;
    tipoDado z;
    tipoDado h;

    x.valor = 5;
    y.valor = 35;
    z.valor = 10;
    h.valor = 12;

    inicializar(&teste);
    inserir(&teste, x);
    inserir(&teste, y);
    inserir(&teste, z);
    inserir(&teste, h);
    imprimir(teste);
    remover(4, &teste, &z);

    imprimir(teste);
}
