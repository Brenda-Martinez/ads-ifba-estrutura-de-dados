#include <stdio.h>

typedef struct{
    int codigo;
    char nome[16];
    float preco;
    int quant;
}produtos;

void preencherEstoque(produtos *estru, int num, int *vazio){
    int existe, codigo, cods[num];
    for(int i = 0; i < num; i++){
        printf("======== PREENCHENDO O ESTOQUE =======\n");
        printf("============= PRODUTO %i ==============\n", i+1);

        do{
            existe = 0;
            do{
              printf("Codigo: ");
              scanf("%d", &codigo);
              getchar();

              if(codigo == 0){
                printf("\nCodigo da mercadoria nao pode ser nulo.\n");
              }
            }while(codigo == 0);

            for(int i = 0; i < num; i++)
            {
                if(codigo == cods[i])
                {
                  existe = 1;
                  break;
                }
            }
            if(existe == 1)
            {
                printf("\nMercadoria com esse codigo ja cadastrada. Digite outro codigo.\n");
            }

        }while(existe == 1);

            printf("Nome: ");
            gets(estru[i].nome);
            printf("Preco: ");
            scanf("%f", &estru[i].preco);
            printf("Quantidade: ");
            scanf("%d", &estru[i].quant);

            estru[i].codigo = codigo;
            cods[i] = codigo;
            system("cls");
        }
    *vazio = 1;
}

void consultaEstoque(produtos *estru, int num){
        int cod_produto, indice;
        int existe = 0;
        printf("Informe o codigo do produto: ");
        scanf("%i", &cod_produto);
        getchar();

        for(int i = 0; i < num; i++)
        {
          if(cod_produto == estru[i].codigo)
          {
            existe = 1;
            indice = i;
            break;
          }
        }

        if(existe == 1)
        {
          printf("\n");
          printf("Nome: ");
          puts(estru[indice].nome);
          printf("Quantidade: %i\n", estru[indice].quant);
          printf("Preco: %.2f\n\n", estru[indice].preco);
        }

        if (existe == 0)
        {
          printf("Produto nao existe.\n\n");
        }
        system("pause");
        system("cls");
}

void listagem(produtos *estru, int num, int vazio){
    if(vazio > 0){
            printf("=== MERCADORIAS CADASTRADAS ===\n");
            printf("===============================\n\n");

            for(int i = 0; i < num; i++){

                if(estru[i].codigo != 0){
                    printf("Codigo: %i\n", estru[i].codigo);
                    printf("Nome: ");
                    puts(estru[i].nome);
                    printf("Quantidade: %i\n", estru[i].quant);
                    printf("Preco: %.2f\n", estru[i].preco);
                    printf("\n===============================\n");
            }
            }
        }
        else{
            printf("\nNao ha mercadorias cadastradas.\n");
        }
        system("pause");
        system("cls");
}

void pedido(produtos *estru, int num, int vazio){
    int quantidade, existe, suficiente, indice;
    int codigo = 500;

    if(vazio == 0){
        printf("\nNao ha mercadorias cadastradas.\n");
        system("pause");
        system("cls");
        return;
    }

    do{
        printf("=== FACA SEU PEDIDO ===\n");
        printf("ENVIE CODIGO 0 PARA SAIR.\n");
        printf("Codigo: ");
        scanf("%d", &codigo);
        getchar();

        if(codigo == 0){
            system("cls");
            return;
        }else{
            for(int i = 0; i <= num; i++){
                if(codigo == estru[i].codigo){
                    existe = 1;
                    indice = i;
                    break;
                }else{
                    existe = 0;
                }
            }

            if(existe == 1){
                printf("Quantidade: ");
                scanf("%d", &quantidade);

                if(quantidade <= estru[indice].quant){
                    estru[indice].quant -= quantidade;
                    printf("Compra registrada.  ");
                    system("pause");
                    system("cls");
                }else{
                    printf("Quantidade insuficiente. ");
                    system("pause");
                    system("cls");
                }
            }

            if(existe == 0){
                printf("Produto nao existe. ");
                system("pause");
                system("cls");
            }

        }

    }while(codigo != 0);
}

int main(){
    int n;
    printf("Quantos produtos terao no estoque?: ");
    scanf("%i", &n);

    produtos estoque[n];
    int opcao;
    int sair = 0;
    int nulo = 0;

    system("cls");

    while(sair == 0){
        printf("==== SEJA BEM VINDO! ====\n");
        printf("========= Menu ==========\n");
        printf("1 - Preencher estoque\n");
        printf("2 - Consultar mercadoria\n");
        printf("3 - Listar mercadorias\n");
        printf("4 - Fazer um pedido\n");
        printf("5 - Sair\n");
        scanf("%i", &opcao);

        switch(opcao){
        case 1:
            system("cls");
            preencherEstoque(&estoque, n, &nulo);
            break;
        case 2:
            system("cls");
            consultaEstoque(&estoque, n);
            break;
        case 3:
            system("cls");
            listagem(&estoque, n, nulo);
            break;
        case 4:
            system("cls");
            pedido(&estoque, n, nulo);
            break;
        case 5:
            sair = 1;
            break;
        default:
            printf("Opcao invalida. ");
            system("pause");
            system("cls");
        }
    }
}
