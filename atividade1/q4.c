#include <stdio.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));

    int vetor[10], v1[5], v2[5], i;

    printf("VETOR INICIAL: \n");

    for(i = 0; i < 10; i++){
        vetor[i] = rand()% 9;
        printf("V[%i]: = %i\n",i, vetor[i]);
    }

    for(i = 0; i < 5; i++){
        separar1(&vetor[i], &v1[i]);
    }
    for(i = 5; i < 10; i++){
        separar2(&vetor[i], &v2[i]);
    }

    printf("\nVETOR 1: \n");

    for(i = 0; i < 5; i++){
        printf("V[%i]: = %i\n",i, v1[i]);
    }

    printf("\nVETOR 2: \n");

    for(i = 5; i < 10; i++){
        printf("V[%i]: = %i\n",i, v2[i]);
    }

    ordenar(v1, v2, 5);

    printf("\nORDENANDO VETORES EM ORDEM CRESCENTE\n");
    printf("\nVETOR 1: \n");

    for(i = 0; i < 5; i++){
        printf("V[%i]: = %i\n",i, v1[i]);
    }

    printf("\nVETOR 2: \n");

    for(i = 5; i < 10; i++){
        printf("V[%i]: = %i\n",i, v2[i]);
    }

    int vetor_final[10];
    ordenar_novo(vetor_final, v1, v2);
    printf("\nJUNCAO DOS VETORES 1 E 2 EM ORDEM CRESCENTE\n");
    for(i = 0; i < 10; i++){
        printf("V[%i]: = %i\n",i, vetor_final[i]);
    }

}

int separar1(int *original, int *vetor1){
    *vetor1 = *original;
    return *vetor1;
}

int separar2(int *resto, int *vetor2){
    *vetor2 = *resto;
    return *vetor2;
}

void ordenar(int *vv1, int *vv2, int tamanho){

    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = i + 1; j < tamanho; ++j) {
            if (vv1[i] > vv1[j]) {
                int auxiliar = vv1[i];
                vv1[i] = vv1[j];
                vv1[j] = auxiliar;
            }

            if (vv2[i+5] > vv2[j+5]) {
                int auxiliar = vv2[i+5];
                vv2[i+5] = vv2[j+5];
                vv2[j+5] = auxiliar;
            }
        }
    }

}

int ordenar_novo(int *vetore, int *vetor1, int *vetor2){
    for(int i = 0; i < 5; i++){
        vetore[i] = vetor1[i];
    }
    for(int i = 5; i < 10; i++){
        vetore[i] = vetor2[i];
    }

    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (vetore[i] > vetore[j]) {
                int aux = vetore[i];
                vetore[i] = vetore[j];
                vetore[j] = aux;
            }
        }
    }

    return vetore;
}
