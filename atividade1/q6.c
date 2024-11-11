#include <stdio.h>

int main(){

    int n = 10;
    int vet[n];
    for(int i = 0; i < 10; i++){
        vet[i] = rand()% 9;
        printf("V[%i]: = %i\n",i, vet[i]);
    }
    printf("\n\n");

    inverter(vet);
}

void inverter(int *vetor, int tam){

    for(int i = tam; i >= 0; i--){
        printf("V[%i]: = %i\n",i, vetor[i]);
    }

}
