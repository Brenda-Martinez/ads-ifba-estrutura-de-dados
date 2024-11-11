#include <stdio.h>
#include <stdlib.h>
#define tam 10

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

void inserir(tipoLista *l, tipoDado dado){
    if(l -> ultimo == tam){
        printf("ERRO!\a Lista cheia.");
    }else{
        l -> vDados[l -> ultimo] = dado;
        l -> ultimo++;
    }
}

void ordenar(tipoLista *l){
    int temp;
    for(int i = 0; i < tam; i++){
        for(int j = 0;j < tam;j++){
            if(l -> vDados[i].valor < l -> vDados[j].valor){
                temp = l -> vDados[i].valor;
                l -> vDados[i].valor = l -> vDados[j].valor;
                l -> vDados[j].valor = temp;
            }
        }
    }
}

void imprimir(tipoLista l){
    apontador aux;
    for(aux == l.primeiro; aux < l.ultimo; aux++){
        printf("\n%d. %d", aux, l.vDados[aux].valor);
    }
}

int main()
{
    tipoLista teste;
    int valorlocal;
    tipoDado valores[tam];

    inicializar(&teste);
    for(int i = 0; i < 10; i++){
    	scanf("%d", &valorlocal);
    	valores[i].valor = valorlocal;
    	inserir(&teste, valores[i]);
	}
	ordenar(&teste);
    imprimir(teste);
}
