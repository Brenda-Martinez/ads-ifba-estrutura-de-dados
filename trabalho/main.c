#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct {
  char nome[50];
  int numContato;
  long long int tel;
  char email[80];
} tipoDado;

typedef struct TipoNo *apontador;

typedef struct TipoNo {
  tipoDado dado;
  apontador proximo;
} TipoNo;

typedef struct {
  apontador primeiro, ultimo;
  int tam;
} tipoLista;

void inicializar(tipoLista *l) {
  l->primeiro = NULL;
  l->ultimo = NULL;
  l->tam = 0;
}

void swapNodes(apontador a, apontador b) {
    tipoDado temp = a->dado;
    a->dado = b->dado;
    b->dado = temp;
}

void bubbleSort(tipoLista *lista) {
    int swapped;
    apontador ptr1;
    apontador lptr = NULL;

    if (lista->primeiro == NULL || lista->primeiro->proximo == NULL){
        return;
    }

    do {
        swapped = 0;
        ptr1 = lista->primeiro;

        while (ptr1->proximo != lptr) {
            if (strcmp(ptr1->dado.nome, ptr1->proximo->dado.nome) > 0) {
                swapNodes(ptr1, ptr1->proximo);
                swapped = 1;
            }
            ptr1 = ptr1->proximo;
        }
        lptr = ptr1;
    } while (swapped);
}

void addNovo(tipoLista *l, tipoDado valor) {
  apontador novoNo = (apontador)malloc(sizeof(TipoNo));
  novoNo->dado = valor;
  novoNo->proximo = NULL;

  if (l->primeiro == NULL) {
    l->primeiro = novoNo;
  } else {
    l->ultimo->proximo = novoNo;
  }

  l->ultimo = novoNo;
  l->tam++;
}

void listarContatos(tipoLista l) {
  apontador aux;
  aux = l.primeiro;
  system("cls");
      printf("******************************************************************** \n");
      printf("*            FUNCAO DE    L I S T A R    ESCOLHIDA                 * \n");
      printf("******************************************************************** \n");
  printf("******************************************************************** \n");
  while (aux != NULL) {

    printf("[CODIGO DE REFERENCIA: %d ]-------------->  NOME : %s\n",  aux->dado.numContato,aux->dado.nome);
    aux = aux->proximo;
  }
  printf("******************************************************************** \n");
}

int pesquisarContato(tipoLista *l, char *nome) {
  int resultadoDeComparacao = 0;
  apontador aux;
  aux = l->primeiro;
  while (aux != NULL) {
    if (strlen(nome) > strlen(aux->dado.nome)) {
      aux = aux->proximo;
      continue;
    }
    for (int k = 0; k < strlen(aux->dado.nome); k++) {
      int i = 0;
      while (nome[i] && (nome[i] == aux->dado.nome[i + k])) {
        i++;
      }
      if (i == strlen(nome)) {
        if (resultadoDeComparacao == 0) {
          printf("******************************************************************** \n");
          printf("* CONTATOS ENCONTRADOS A PARTIR DA PESQUISA REALIZADA              * \n");
          printf("******************************************************************** \n");
        }
        resultadoDeComparacao = 1;
        printf("[CODIGO DE REFERENCIA: %d ]-------------->  NOME : %s\n",  aux->dado.numContato,aux->dado.nome);
        break;
      } else {
        continue;
      }
    }
    aux = aux->proximo;
  }
  return resultadoDeComparacao;
}

void listarDadosDoContato(tipoLista *l, int codDoContato)
{
    system("cls");
    apontador aux = l->primeiro;
    bool vereficar= false;
    printf("******************************************************************** \n");

    while (aux != NULL)
    {

        if (aux->dado.numContato==codDoContato)
        {
            vereficar=true;

            printf("*               O CONTATO << %d >>FOI ENCONTRADO                   * \n",aux->dado.numContato);
            printf("******************************************************************** \n");
            printf("NOME :%s                                                           \n",aux->dado.nome);
            printf("TELEFONE :%lld                                                     \n",aux->dado.tel);
            printf("EMAIL :%s                                                          \n",aux->dado.email);

            break;
        }
        aux = aux->proximo;
    }

    if(vereficar==false)
    {
            printf("*            C O N T A T O  N A O  E X I S T E N T E               * \n");
    }


}
void removerContato(tipoLista *l, int codigoContato) {
    apontador anterior = NULL;
    apontador atual = l->primeiro;

    if (l->primeiro == NULL) {
        printf("A lista de contatos esta vazia.\n");
        return;
    }

    if (atual->dado.numContato == codigoContato) {
        l->primeiro = atual->proximo;
        char nomeExcluido[50];
        strcpy(nomeExcluido, atual->dado.nome);
        free(atual);
        l->tam--;
        printf("******************************************************************** \n");
        printf("* O CONTATO COM CODIGO '%d' E NOME '%s 'FOI REMOVIDO DA LISTA      * \n", codigoContato, nomeExcluido);
        printf("******************************************************************** \n");
        return;
    }

    while (atual != NULL) {
        if (atual->dado.numContato == codigoContato) {
            anterior->proximo = atual->proximo;
            char nomeExcluido[50];
            strcpy(nomeExcluido, atual->dado.nome);
            free(atual);
            l->tam--;
            printf("******************************************************************** \n");
            printf("* O CONTATO COM CODIGO '%d' E NOME '%s 'FOI REMOVIDO DA LISTA      * \n", codigoContato, nomeExcluido);
            printf("******************************************************************** \n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("******************************************************************** \n");
    printf("*   NAO FOI ENCONTRADO NENHUM CONTATO COM O CODIGO '%d'              * \n", codigoContato);
    printf("******************************************************************** \n");
}


int main() {
  tipoLista lista;
  inicializar(&lista);

  tipoDado temp;
  int quantContatos = 0;

  int sair;
  char nomePesquisa[100];

  do {
    int opcao;
    sair = 0;
    printf("******************************************************************** \n");
    printf("*      A G E N D A    D E    C O N T A T O         -  I  F  B  A  -* \n");
    printf("******************************************************************** \n");
    printf("*             <<<<<A SEGUIR, AS OPCOES DISPONIVEIS >>>>>           * \n");
    printf("******************************************************************** \n");
    printf("* 1 -> Inserir contato                                             * \n");
    printf("* 2 -> Pesquisar contato                                           * \n");
    printf("* 3 -> Listar todos os contatos por ordem alfabetica               * \n");
    printf("* 4 -> Listar dados do contato                                     * \n");
    printf("* 5 -> Deletar contato                                             * \n");
    printf("* 777 -> Sair                                                      * \n");
    printf("******************************************************************** \n");
    printf("* A SEGUIR DIGITE UMA OPCAO, APERTE ENTER PARA CONFIRMAR A ESCOLHA * \n");
    printf("******************************************************************** \n");
    printf("DIGITE A OPCAO :");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
    case 1:
      system("cls");
      printf("******************************************************************** \n");
      printf("*            FUNCAO DE   I N S E R I R   ESCOLHIDA                 * \n");
      printf("******************************************************************** \n");
      temp.numContato = ++quantContatos;
      printf("Nome: ");
      fgets(temp.nome, 50, stdin);
      printf("Telefone: ");
      scanf(" %lld", &temp.tel);
      getchar();
      printf("Email: ");
      fgets(temp.email, 80, stdin);
      addNovo(&lista, temp);
      printf("******************************************************************** \n");
      printf("*      O CONTATO << %d >>   FOI          A D I C I O N A D O       * \n", temp.numContato);
      printf("******************************************************************** \n");
      printf("\nPressione enter para continuar...");
      getchar();
      system("cls");
      break;
    case 2:
      system("cls");
      printf("******************************************************************** \n");
      printf("*            FUNCAO DE   P E S Q U I S A R    ESCOLHIDA            * \n");
      printf("******************************************************************** \n");
      printf("DIGITE O NOME QUE DESEJA PESQUISAR : ");
      scanf("%s", nomePesquisa);
      if (!pesquisarContato(&lista, nomePesquisa)) {
      printf("******************************************************************** \n");
      printf("*       NAO FOI ENCONTRADO NENHUM CONTATO COM ESTE NOME            * \n");
      }
      printf("******************************************************************** \n");
      system("pause");
      system("cls");
      break;
    case 3:
      bubbleSort(&lista);
      listarContatos(lista); // falta ordenar os contatos
      sair = 0;
      printf("\nPressione enter para continuar...");
      getchar();
      system("cls");
      break;
    case 4:
        system("cls");
      printf("******************************************************************** \n");
      printf("*         FUNCAO DE   L I S T A R  D A D O S  ESCOLHIDA            * \n");
      printf("******************************************************************** \n");
      printf("DIGITE O CODIGO DE REFERENCIA QUE DESEJA VIZUALIZAR OS DADOS : ");
        int numeroContato;
        scanf("%d", &numeroContato);
        getchar();
        listarDadosDoContato(&lista, numeroContato);

        printf("******************************************************************** \n");
        printf("\nPressione enter para continuar...");
        getchar();

        system("cls");
      break;
    case 5:
     system("cls");
        printf("******************************************************************** \n");
        printf("*            FUNCAO DE   R E M O V E R   ESCOLHIDA                 * \n");
        printf("******************************************************************** \n");
        printf("DIGITE O CODIGO DE REFERENCIA DO CONTATO QUE DESEJA REMOVER: ");
        int codigoRemover;
        scanf("%d", &codigoRemover);
        getchar();
        removerContato(&lista, codigoRemover);
        printf("\nPressione enter para continuar...");
        getchar();
        system("cls");
        break;

      break;
    case 777:
      sair = 1;
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n");
      break;
    }
  } while (sair == 0);
}
