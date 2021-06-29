#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

struct no
{
    int info;
    struct no *prox;
};
typedef struct no *No;

struct fila
{
    struct no *ini; //guarda endere�o de estrutura n� (primeiro)
    struct no *fim; //guarda endere�o de estrutura n� (�ltimo)
};
typedef struct fila *Fila; //endere�o de estrutura fila

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

    No aux = f->ini;

    while(aux->prox != NULL)
    {
        aux = aux->prox;
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

