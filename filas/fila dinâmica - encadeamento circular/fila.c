#include <stdio.h>
#include <stdlib.h>

#include "circular.h"

struct no
{
    int info;
    struct no *prox;
};
typedef struct no *Fila;

Fila cria_fila()
{
    return NULL;
}

int fila_vazia(Fila f)
{
    if(f == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int insere_fim(Fila *f, int elem)
{
    //aloca novo nó e preenche campo info
    Lista N;
    N = (Lista)malloc(sizeof(struct no));

    if(N == NULL) //falha
    {
        return 0;
    }

    N->info = elem; //insere conteúdo no campo info

    //trata fila vazia
    if(fila_vazia(*f) == 1)
    {
        N->prox = N; //novo nó aponta para ele mesmo
        *f = N; //fila aponta para novo nó
    }else
    {
        N->prox = (*f)->prox; //novo nó aponta para primeiro
        (*f)->prox = N; //último nó aponta para novo nó
        *f = N; //fila aponta para novo nó (último)
    }

    return 1;

}

int remove_inicio(Fila *f, int *elem)
{
    if(fila_vazia(*f) == 1) //trata fila vazia
    {
        return 0;
    }

    Fila aux = (*f)->prox; //aux aponta para primeiro nó

    *elem = aux->info; //retorna valor do nó a ser removido

    if(*f == (*f)->prox) //trata fila com 1 nó - nó aponta para ele mesmo
    {
        *f = NULL;
    }else //trata fila com + de um elemento
    {
        (*f)->prox = aux->prox;
    }

    free(aux);
    return 1;
}

int remove_final(Fila *f)
{
    if(lista_vazia(*f) == 1)
    {
        return 0;
    }

    Fila aux = *f;
    Fila aux2 = aux->prox; //guarda endereço primeiro no

    while(aux->prox != *f)
    {
        aux = aux->prox;
    }

    *f = aux;
    free(aux->prox);
    aux->prox = aux2;

    return 1;
}

int get_posicao(Lista l, int elem)
{
    if (lista_vazia(l) == 1)
    {
        return 0;
    }
    Lista aux = l->prox;

    if (elem == l->prox->info)
    {
        return 1;
    }

    int pos = 1;

    while(aux != l && aux->prox->info != elem)
    {
        aux = (*aux).prox;
        pos++;
    }

    int fim;
    get_fim(&l, &fim);

    if (pos+1 > fim)
    {
        return 0;
    }

    return pos+1;
}

int tam_fila(Fila *f, int *i)
{
    if(fila_vazia(*f) == 1)
        return 0;

    int pos=1, cont = 0;

    Fila aux = (*f)->prox;

    while(cont == 0)
    {
        aux = aux->prox;
        pos++;
        if(aux->prox == *f)
        {
            pos++;
            cont=1;
        }
    }

    *i = pos;
    return 1;
}


int get_values(Lista *l, int *elem, int p)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = (*l)->prox;

    int pos=0;

    while(pos < p)
    {
        if(aux->prox == *l)
        {
            pos=p;
        }
        aux = aux->prox;
        pos++;
    }

    *elem = aux->info;

    return 1;
}

int limpa_fila(Fila *f)
{
    if(fila_vazia(*f) == 1)
        return 0;

    Fila aux = *f;

    int end;
    int numero;
    tam_fila(&aux, &end);

    while(end > 0)
    {
        remove_inicio(&aux, &numero);
        end--;
    }

    *f = NULL;

    return 1;
}
