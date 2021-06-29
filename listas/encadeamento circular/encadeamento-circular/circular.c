#include <stdio.h>
#include <stdlib.h>

#include "circular.h"

struct no
{
    int info;
    struct no *prox;
};
typedef struct no *Lista;

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista l)
{
    if(l == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int insere_final(Lista *l, int elem)
{
    Lista N;
    N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = elem;

    if(lista_vazia(*l) == 1)
    {
        N->prox = N;
        *l = N;
    }else
    {
        N->prox = (*l)->prox;
        (*l)->prox = N;
        *l = N;
    }

    return 1;

}

int remove_inicio(Lista *l, int *elem)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = (*l)->prox;

    *elem = aux->info; //retorna valor do nó a ser removido

    if(*l == (*l)->prox)
    {
        *l = NULL;
    }else
    {
        (*l)->prox = aux->prox;
    }

    free(aux);
    return 1;
}

int remove_final(Lista *l)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = *l;
    Lista aux2 = aux->prox; //guarda endereço primeiro no

    while(aux->prox != *l)
    {
        aux = aux->prox;
    }

    *l = aux;
    free(aux->prox);
    aux->prox = aux2;

    return 1;
}

int remove_elem(Lista *l, int elem)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = (*l)->prox;

    if(aux->info == elem)
    {
        remove_inicio(l, &elem);
        return 1;
    }else
    {
        while(aux->prox != *l && aux->prox->info != elem)
        {
            aux = aux->prox;

            if(aux->prox == *l && aux->prox->info == elem)
            {
                remove_final(l);
                return 1;
            }
        }

        if(aux->prox == *l && aux->prox->info != elem)
        {
            return 0;
        }
    }

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);

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

int get_fim(Lista *l, int *i)
{
    if(lista_vazia(*l) == 1)
        return 0;

    int pos=1, cont = 0;

    Lista aux = (*l)->prox;

    while(cont == 0)
    {
        aux = aux->prox;
        pos++;
        if(aux->prox == *l)
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

int limpa_lista(Lista *l)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = *l;

    int end;
    int numero;
    get_fim(&aux, &end);

    while(end > 0)
    {
        remove_inicio(&aux, &numero);
        end--;
    }

    *l = NULL;

    return 1;
}
