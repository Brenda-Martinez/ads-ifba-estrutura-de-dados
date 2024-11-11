#include <stdio.h>

typedef struct{
    int matricula;
    char nome[50];
    float n1;
    float n2;
    float n3;
}materia;

void cadastro(materia *estru, int max){
    for(int i = 0; i < max; i++){
        printf("========== ALUNO %d =========\n", i+1);
        printf("Nome: ");
        scanf("%s", &estru[i].nome);
        printf("Matricula: ");
        scanf("%d", &estru[i].matricula);
        printf("Nota 1: ");
        scanf("%f", &estru[i].n1);
        printf("Nota 2: ");
        scanf("%f", &estru[i].n2);
        printf("Nota 3: ");
        scanf("%f", &estru[i].n3);
    }
    system("pause");
    system("cls");
}

float media(materia dados2, int tamanho){
    return (dados2.n1 + dados2.n2 + dados2.n3)/3;
}

void maiorNota1(materia *dados, int maximo){

    int nomes[maximo];
    float maior = 0;
    int max = 0;

    for(int i = 0; i < maximo; i++){
        if(dados[i].n1 > maior){
            maior = dados[i].n1;
        }
    }

    for(int i = 0; i < maximo; i++){
        if(dados[i].n1 == maior){
            nomes[max] = dados[i].nome;
            max++;
        }
    }

    printf("==== ALUNOS COM AS MAIORES NOTAS ====\n");
    printf("Maior nota: %.1f\n", maior);

    for(int i = 0; i < max; i++){
        printf("%s\n", nomes[i]);
    }

    system("pause");
    system("cls");
}

void maiorMedia(materia *dados, int maximo){

    int nomes[maximo];
    int nomes2[maximo];
    float maior = 0;
    float menor = 500;
    int max = 0;
    int max2 = 0;

    for(int i = 0; i < maximo; i++){
        if(media(dados[i], maximo) > maior){
            maior = media(dados[i], maximo);
        }

        if(media(dados[i], maximo) < menor){
            menor = media(dados[i], maximo);
        }
    }

    for(int i = 0; i < maximo; i++){
        if(media(dados[i], maximo) == maior){
            nomes[max] = dados[i].nome;
            max++;
        }
        if(media(dados[i], maximo) == menor){
            nomes2[max2] = dados[i].nome;
            max2++;
        }
    }

    printf("==== ALUNOS COM AS MAIORES MEDIAS ====\n");
    printf("Maior media: %.1f\n", maior);

    for(int i = 0; i < max; i++){
        printf("%s\n", nomes[i]);
    }

    printf("==== ALUNOS COM AS MENORES MEDIAS ====\n");
    printf("Menor media: %.1f\n", menor);

    for(int i = 0; i < max2; i++){
        printf("%s\n", nomes2[i]);
    }
    system("pause");
    system("cls");
}

int main(){

    int tam = 20;
    materia LP[tam];

    printf("======= DADOS ALUNOS ========\n");
    cadastro(&LP, tam);

    maiorNota1(&LP, tam);
    maiorMedia(&LP, tam);
}
