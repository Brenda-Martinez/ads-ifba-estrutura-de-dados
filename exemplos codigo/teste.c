#include <stdio.h>

#define MaxTam 100
#define InicioVetor 0

typedef int TipoChave;
typedef int Apontador;

typedef struct {
    TipoChave Chave;
    /* outros componentes */
} TipoItem;

typedef struct {
    TipoItem itens[MaxTam];
    Apontador Primeiro, Ultimo;
} TipoLista;

void Inicia_Lista(TipoLista *Lista)
{
    Lista->Primeiro = InicioVetor;
    Lista->Ultimo = Lista->Primeiro;
}

int Lista_Vazia(TipoLista Lista)
{
    if(Lista.Primeiro == Lista.Ultimo){
        return 0;
    }else{
        return 1;
    }
}

int Insere_Lista(TipoItem x, TipoLista *Lista) {
    if (Lista->Ultimo > MaxTam - 1) {
        return (0);
    } else {
        Lista->itens[Lista->Ultimo] = x;
        Lista->Ultimo++;
        return (1);
    }
}

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;
    if (Lista_Vazia(*Lista) || p-1 >= Lista->Ultimo)
    {
        return (0);
    }

    *Item = Lista->itens[p - 1];
    for (Aux = p; Aux < Lista->Ultimo; Aux++){
        Lista->itens[Aux - 1] = Lista->itens[Aux];
    }
    Lista->Ultimo--;
}

void ImprimeLista(TipoLista Lista)
{
    int Aux;
    for (Aux = Lista.Primeiro; Aux<=(Lista.Ultimo - 1); Aux++){
        printf("%d\n", Lista.itens[Aux].Chave);
    }
}

int main(){

}
