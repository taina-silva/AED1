#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

struct no
{
    int info;
    struct no *prox;
};

struct fila
{
    struct no *ini; //guarda endere�o de estrutura n� (primeiro)
    struct no *fim; //guarda endere�o de estrutura n� (�ltimo)
};

Fila cria_fila()
{
    Fila f;
    f = (Fila)malloc(sizeof(struct fila)); //aloca estrutura tipo fila

    if(f == NULL)
    {
        return 0;
    }

    //campos ini e fim da fila apontam pra null
    f->ini = NULL;
    f->ini = NULL;

    return f;
}

int fila_vazia(Fila f)
{
    if(f->ini == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

//fila prioridade n�o ordenada
int insere_fim(Fila f, int elem)
{
    if(f == NULL) //fila inv�lida
    {
        return 0;
    }

    No N; //aloca ponteiro pra n�
    N = (No)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = elem;
    N->prox = NULL;//�ltimo n� da fila

    if(fila_vazia(f)==1)
    {
        f->ini = N; //campo ini aponta para novo n�
    }else
    {
        f->fim->prox = N; //�ltimo n� da fila aponta para novo n�
    }

    f->fim = N; //N � o �ltimo n� (apontado pelo campo fim)

    return 1;
}

/*busca posi��o adequada para elemento de acordo com sua
prioridade (ascendente ou descendente)
-- remo��o no in�cio*/

//FPA
int insere_fpa_ord(Fila f, int elem)
{
    if(f == NULL) //fila inv�lida
    {
        return 0;
    }

    No N; //aloca ponteiro pra n�
    N = (No)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = elem;

    //caso para fila vazia ou elem > que o �ltimo (insere fim)
    if(fila_vazia(f) == 1 || elem > N->info)
    {
        if(fila_vazia(f) == 1)
        {
            f->ini = N;
        }else
        {
            f->fim->prox = N;
        }

        N->prox = NULL;
        f->fim = N;
        return 1;
    }

    if(elem < f->ini->info)
    {
        N->prox = f->ini;
        f->ini = N;

        return 1;
    }

    No aux = f->ini;

    while(aux->prox != NULL && aux->prox->info < elem)
    {
        aux = aux->prox;
    }

    N->prox = aux->prox;
    aux->prox = N;

    return 1;
}

//fila prioridade ordenada
int remove_ini(Fila f, int *elem)
{
    if(fila_vazia(f)==1)
    {
        return 0;
    }

    No aux = f->ini; //ponteiro aux recebe endere�o primeiro n� da fila
    *elem = aux->info; //retorna valor elemento removido

    //verifica se fila tem �nico n� - ini e fim apontam para mesmo n�
    if(f->ini == f->fim)
    {
        f->fim = NULL;
    }

    f->ini = aux->prox; //retira primeiro n� da fila
    free(aux); //libera mem�ria alocada

    return 1;
}

/*busca elemento de menor (fila de prioridade ascendente)
ou menor (fila de prioridade descendente) prioridade e o remove da
estrutura
-- inser��o no fim*/

//FPA
int remove_fpa_ord(Fila f, int *elem)
{
    if(fila_vazia(f)==1 || f==NULL)
    {
        return 0;
    }

    No aux = f->ini;
    int menor = aux->info;

    while(aux->prox != NULL)
    {
        if(aux->prox->info < menor)
        {
            menor = aux->prox->info;
        }
        aux = aux->prox;
    }

    *elem = aux->prox->info;

    if(aux->prox == NULL)
    {
        return 0; //fim da fila
    }

    if(menor == f->ini->info) //verifica se elemento a ser removido � o primeiro
    {
        if(f->ini == f->fim) //verifica se h� somente um n�
        {
            f->fim = NULL;
        }

        f->ini = aux->prox;
        free(aux);
    }else
    {
        No aux2 = aux->prox;
        aux->prox = aux2->prox;
        free(aux2);
    }

    return 1;

}

void tam_fila(Fila f, int *tam)
{
    if(fila_vazia(f) == 1)
    {
        *tam = 0;
    }

    No aux = f->ini;
    int cont = 1;

    while(aux->prox != NULL)
    {
        cont++;
        aux = aux->prox;
    }

    *tam = cont;
}

int esvazia_fila(Fila f)
{
    if(fila_vazia(f)==1)
        return 0;

    No aux;

    while(f->ini != NULL)
    {
        aux = f->ini;
        f->ini = aux->prox;
        free(aux);
    }

    return 1;
}

void apaga_fila(Fila *f)
{
    free(*f);
    *f = NULL;
}
