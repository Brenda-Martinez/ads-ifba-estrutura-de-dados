#include <stdio.h>
#include <string.h>
#define tam 3
/*Escreva uma função que recebe como parâmetros uma lista de alunos L e um valor z e que modifique o conteúdo de L, retirando todos os alunos com nota maior que z. Após a execução da função, o conteúdo de L deverá estar alterado*/
typedef int apontador;

typedef struct{
    char nome[40];
    float nota;
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
        printf("Nota: %f", l.vDados[aux].nota);
    }
}

void remover(tipoLista *l, tipoDado *d, float passou){
    int aux;
    if(l->primeiro == l->ultimo){
        printf("Erro. Lista vazia.");
    }
    
    for(int p = 0; p < l->ultimo - 1; p++){
        if(l->vDados[p].nota > passou){
            *d = l->vDados[p-1];
            for(aux = p; aux < l->ultimo; aux++){
                l->vDados[aux-1] = l->vDados[aux];
             }
            l->ultimo--;
        }
    }
}

int main()
{
    tipoLista alunos;
    tipoDado nomelocal;

    inicializar(&alunos);
    for(int i = 0; i < tam; i++){
        printf("Aluno %d: ", i+1);
    	fgets(nomelocal.nome, 40, stdin);
    	printf("Nota: ");
    	scanf("%f", &nomelocal.nota);
    	getchar();
    	inserir(&alunos, nomelocal);
	}

	remover(&alunos, &alunos.vDados, 7);
    imprimir(alunos);
}
