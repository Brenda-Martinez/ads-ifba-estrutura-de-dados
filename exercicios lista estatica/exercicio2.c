#include <stdio.h>
#include <string.h>
#define tam 10

typedef int apontador;

typedef struct{
    char nome[40];
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

void imprimir(tipoLista l){
    apontador aux;
    for(aux == l.primeiro; aux < l.ultimo; aux++){
        printf("\nAluno %d. %s", aux+1, l.vDados[aux].nome);
    }
}

int main()
{
    tipoLista alunos;
    tipoDado nomelocal;

    inicializar(&alunos);
    for(int i = 0; i < 10; i++){
        printf("Aluno %d: ", i+1);
    	fgets(nomelocal.nome, 40, stdin);
    	inserir(&alunos, nomelocal);
	}
    imprimir(alunos);
}
