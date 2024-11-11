#include <stdio.h>
#include <stdlib.h>

leitura(int *valor, int *cont){
    printf("V[%i]: = %i\n",*cont, *valor);
}

float media_calculo(float *pMed, int valor, int j){
    *pMed = *pMed + valor;

    if(j == 100){
        return *pMed/100;
    }else{
        return *pMed;
    }
}

int main() {
    srand(time(NULL));

    int v[100];
    float media = 0;

    for(int i = 0; i <= 100; i++){

        v[i] = rand()% 99;
        leitura(&v[i], &i);
        media = media_calculo(&media, v[i], i);

    }

    printf("A media dos valores do vetor eh %.1f", media);

}
