#include <stdio.h>

int main()
{
   int n1, n2;

   printf("Digite o valor de x: ");
   scanf("%d", &n1);
   printf("Digite o valor de y: ");
   scanf("%d", &n2);

   troca(&n1, &n2);

   printf("\n\n");
   printf("X = %d", n2);
   printf("\nY = %d", n1);
}

int troca(int *x, int *y){

    int aux;

    aux = *x;
    y = *x;
    x = aux;

    return;
}
