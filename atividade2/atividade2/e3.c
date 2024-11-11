#include <stdio.h>
#define TAM 40

typedef struct{
    char nome[16];
    int n_apt;
    int area;
    int n_moradores;
    float valor_mensal;
}condominio;

void preencherDados(condominio *estru, int *vazio){
    for(int i = 0; i < TAM; i++){
        printf("======= APTO %i ========\n", i+1);

        printf("Digite o nome do proprietario: ");
        scanf("%s", &estru[i].nome);
        getchar();
        printf("Digite o no do apartamento: ");
        scanf("%d", &estru[i].n_apt);
        printf("Digite a area do apartamento: ");
        scanf("%d", &estru[i].area);
        printf("Digite a quantidade de moradores: ");
        scanf("%d", &estru[i].n_moradores);

        system("cls");
    }

    *vazio = 1;
}

void leitura(condominio *dados, int vazio){
    if(vazio == 0){
        printf("\nNenhum cadastro encontrado.\n");
    }else{
        printf("==== INFO APARTAMENTOS ====\n");
        printf("===========================\n");

        for(int i = 0; i < TAM; i++){
            printf("========= APTO %d ========\n", i+1);
            printf("Proprietario: %s\n", dados[i].nome);
            printf("Moradores: %d\n", dados[i].n_moradores);
            printf("No Apto: %d\n", dados[i].n_apt);
            printf("Area: %d m2\n", dados[i].area);
        }
    }
    system("pause");
    system("cls");
}

int calculoArea(condominio *dados){
    int soma = 0;

    for(int i = 0; i <= TAM; i++){
        soma += dados->area;
    }

    return soma;
}

void valorMensal(int area, condominio *dados){
    float despesas;

    printf("Total de despesas mensais do condominio R$: ");
    scanf("%f", &despesas);

    for(int i = 0; i <= TAM; i++){
        dados[i].valor_mensal = (dados[i].area * despesas) / area;
    }

    for(int i = 0; i < TAM; i++){
        printf("========= APTO %d ========\n", i+1);
        printf("Valor da fatura: %f\n", dados[i].valor_mensal);
    }
}

void maisMoradores(condominio *dados){
    int armazenaDados[TAM];
    int indice_dados[TAM];
    int maior = 0;
    int max = 0;

    for(int i = 0; i < TAM; i++){
        if(dados[i].n_moradores > maior){
            maior = dados[i].n_moradores;
        }
    }

    for(int i = 0; i < TAM; i++){
        if(dados[i].n_moradores == maior){
            armazenaDados[i] = dados[i].n_moradores;
            indice_dados[i] = i;
            max++;
        }
    }

    printf("==== APTOS MAIS MORADORES ====\n");

    for(int i = 0; i < max; i++){
        printf("APTO %d: %d moradores.\n", indice_dados[i+1], armazenaDados[i+1]);
    }

    system("pause");
    system("cls");
}

int main(){
    int opcao, areaTotal;
    int nulo = 0;
    int sair = 0;

    condominio apartamentos[TAM];

    while(sair == 0){
        printf("==== SEJA BEM VINDO! ====\n");
        printf("========= Menu ==========\n");
        printf("1 - Preencher dados\n");
        printf("2 - Info apartamentos\n");
        printf("3 - Area total do condominio\n");
        printf("4 - Calcular valor mensal\n");
        printf("5 - Verificar maior numero de moradores\n");
        printf("6 - Sair\n");
        scanf("%i", &opcao);

        switch(opcao){
        case 1:
            system("cls");
            preencherDados(&apartamentos, &nulo);
            areaTotal = calculoArea(&apartamentos);
            break;
        case 2:
            system("cls");
            leitura(&apartamentos, nulo);
            break;
        case 3:
            system("cls");
            printf("Area total do condominio: %i\n\n", areaTotal);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            valorMensal(areaTotal, &apartamentos);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            maisMoradores(&apartamentos);
            break;
        case 6:
            sair = 1;
            break;
        default:
            printf("Opcao invalida. ");
            system("pause");
            system("cls");
        }
    }

}
