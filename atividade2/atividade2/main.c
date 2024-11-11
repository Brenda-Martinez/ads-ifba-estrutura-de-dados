#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

typedef struct{

char nomes[21];
char end[50];
char telefone[9];

}Agenda;

int main()
{
    Agenda minhaagenda[10];

    for(int i = 0; i < TAM; i++){
        printf("======= CONTATO %i ========\n", i+1);

        printf("Digite o nome: ");
        gets(minhaagenda[i].nomes);
        printf("Digite o endereco: ");
        gets(minhaagenda[i].end);
        printf("Digite o telefone: ");
        gets(minhaagenda[i].telefone);

        system("cls");
    }

    printf("Limite máximo atingido.\n\n");

    for(int i = 0; i < TAM; i++){
        printf("======= CONTATO %i ========\n", i+1);

        printf("%s\n", minhaagenda[i].nomes);
        printf("%s\n", minhaagenda[i].end);
        printf("%s\n", minhaagenda[i].telefone);

        printf("==========================");
        printf("\n\n");
    }
}
