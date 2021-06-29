#include <stdio.h>
#include <stdlib.h>

#include "recursiva.h"

struct no
{
    double info;
    struct no * prox;
};
typedef struct no * Lista;

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int insere_final (Lista *lst, double elem)
{
    Lista N;

    if(lista_vazia(*lst) == 1)
    {
        N = (Lista)malloc(sizeof(struct no));

        if (N == NULL)
        {
            return 0;
        }

        N->info = elem;

        N->prox = *lst;
        *lst = N;

        return 1;
    }else
    {
        int R;

        R = insere_final(&(*lst)->prox, elem);

        return R;
    }
}

int insere_ord (Lista *lst, double elem)
{
    if (lista_vazia(*lst) == 1 || elem <= (*lst)->info)
    {
        Lista N = (Lista) malloc(sizeof(struct no));
        if (N == NULL)
        {
            return 0;
        }

        N->info = elem;

        (*N).prox = *lst;
        *lst = N;
        return 1;
    } else{
        int R = insere_ord(&(*lst)->prox, elem);
        return R;
    }

}

int remove_inicio(Lista *lst, double *elem)
{
    if(lista_vazia(*lst) == 1)
    {
        return 0;
    }else
    {
        Lista aux = *lst;
        *elem = aux->info;
        *lst = aux->prox;
        free(aux);

        return 1;
    }
}

int remove_elem(Lista *lst, double elem)
{
    if(lista_vazia(*lst) == 1)
    {
        return 0;
    }else{

        if(elem == (*lst)->info)
        {
            Lista aux = *lst;
            *lst = (*aux).prox;
            free(aux);
            return 1;

        }else{
            int R = remove_elem(&(*lst)->prox, elem);
            return R;
        }

    }
}

int remove_ord(Lista *lst, double elem)
{
    if(lista_vazia(*lst) == 1 || elem < (*lst)->info)
    {
        return 0;
    }
    else
    {
        if(elem == (*lst)->info)
        {
            Lista aux = *lst;
            *lst = (*aux).prox;
            free(aux);
            return 1;
        }
        else
        {
            int R = remove_ord(&(*lst)->prox, elem);
            return R;
        }

    }
}

int remove_posicao(Lista *lst, int position)
{
    if (lista_vazia((*lst)) == 1)
    {
        return 0; // Falha
    }
    Lista aux = (*lst);

    if (position == 1)
    {
        *lst = (*aux).prox;
        free(aux);
        return 1;
    }
    int pos = 2;

    while(aux->prox != NULL && pos < position)
    {
        aux = (*aux).prox;
        pos++;
    }
    if(aux->prox == NULL)
        return 0;

    Lista aux2 = (*aux).prox;
    (*aux).prox = (*aux2).prox;
    free(aux2);

    return 1;
}

int get_posicao(Lista lst, double elem)
{
    if (lista_vazia(lst) == 1)
    {
        return 0;
    }
    Lista aux = lst;

    if (elem == lst->info)
    {
        return 1;
    }
    int pos = 1;

    while(aux->prox != NULL && aux->prox->info < elem)
    {
        aux = (*aux).prox;
        pos++;
    }

    return pos+1;
}

double obtem_elem(Lista lst, int position)
{

    Lista aux = lst;
    int pos = 0;

    while (aux->prox != NULL && pos < position)
    {
        aux = aux->prox;
        pos++;
    }

    return aux->info;
}

int get_end(Lista lst)
{
    if (lst == NULL || lista_vazia(lst) == 1)
    {
        return 0;
    }

    Lista aux = lst;
    int pos = 0;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
        pos++;
    }

    return pos;
}

void limpa_lista(Lista *lst)
{
    while(*lst != NULL)
    {
        Lista aux = *lst;
        *lst = aux->prox;
        free(aux);
    }
}
