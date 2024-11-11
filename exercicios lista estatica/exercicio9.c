#include <stdio.h>
#include <string.h>
#define tam 3
//Implemente uma função para inserir um elemento numa lista L em uma posição pos.
typedef int apontador;

typedef struct{
    int valor;
}tipoDado;

typedef struct{
    tipoDado vDados[tam];
    apontador primeiro, ultimo;
}tipoLista;


void inicializar(tipoLista *l){
    l -> primeiro = 0;
    l -> ultimo = l -> primeiro;
}

void inserir(tipoLista *l, tipoDado dado, apontador pos){
    apontador aux;

    if(l -> ultimo == tam){
        printf("ERRO!\a Lista cheia.");
    }else if((pos > l->ultimo) || (pos < 0)){
        printf("ERRO!\a Posicao não existe.");
    }else{
      //  for(aux = tam - 1; aux > pos; aux--){
          //  l->vDados[aux].valor = l->vDados[aux-1].valor;
            l->ultimo++;
            l->vDados[pos] = dado;
        //}
    }
}

void imprimir(tipoLista l){
    apontador aux;
    for(aux == l.primeiro; aux < l.ultimo; aux++){
        printf("\n%d", l.vDados[aux].valor);
    }
}

int main()
{
    tipoLista lista;
    tipoDado d1;
    d1.valor = 4;
    tipoDado d2;
    d2.valor = 3;
    tipoDado d3;
    d3.valor = 1;

    inicializar(&lista);
    inserir(&lista, d1, 0);
    inserir(&lista, d2, 1);
    inserir(&lista, d3, 2);

    imprimir(lista);
}
