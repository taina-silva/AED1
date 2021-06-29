#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lista.h"

struct no
{
    int tipo;
    union
    {
        int i_int;
        char i_char;
    } info;

    struct no *prox;
};

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista l)
{
    if(l == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista *l, int elem, char elem2, int tipo)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->tipo = tipo;

    if(tipo == 0)
    {
        N->info.i_int = elem;
    }else if(tipo == 1)
    {
        N->info.i_char = elem2;
    }else
    {
        return 0;
    }

    N->prox = *l;
    *l = N;

    return 1;
}

int remove_elem(Lista *l, int elem, char elem2, int tipo)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = *l; //ponteiro aux para primeiro nó

    if(tipo == 0)
    {
        //trata primeiro nó da lista
        if(elem == (*l)->info.i_int)
        {
            *l = aux->prox; //lista aponta para segundo nó
            free(aux); //libera memória de aux

            return 1;
        }

        //percorre até fim da lista ou achar elem
        while(aux->prox != NULL && aux->prox->info.i_int != elem)
        {
            aux = aux->prox; //aux pega endereço de próxima região
        }

        if(aux->prox == NULL) //fim da lista
            return 0;

    }else if(tipo == 1)
    {
        if(elem2 == (*l)->info.i_char)
        {
            *l = aux->prox;
            free(aux);

            return 1;
        }

        while(aux->prox != NULL && aux->prox->info.i_char != elem2)
        {
            aux = aux->prox;
        }

        if(aux->prox == NULL) //fim da lista
            return 0;
    }else
    {
        return 0;
    }

    Lista aux2 = aux->prox; //aponta nó a ser removido
    aux->prox = aux2->prox; //retira nó da lista, aponta para nó seguinte
    free(aux2); //libera memória aux

    return 1;
}

int get_values(Lista l, int p, int *elem, char *elem2, int *tipo)
{
    if(lista_vazia(l) == 1)
        return 0;

    Lista aux = l;
    int pos=1;

    while(aux->prox != NULL && pos < p)
    {
        aux = aux->prox ;
        pos++;
    }

    *tipo = aux->tipo;
    *elem = aux->info.i_int;
    *elem2 = aux->info.i_char;

    return 1;
}

void get_fim(Lista l, int *i)
{
    if(lista_vazia(l) == 1)
    {
        *i = 0;
    }else
    {
        Lista aux = l;
        int pos=0;

        while(aux->prox != NULL)
        {
            aux = aux->prox;
            pos++;
        }

        *i = pos+1;
        }
}

int limpa_lista(Lista *l)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux;

    while(*l != NULL)
    {
        aux = *l;
        *l = aux->prox;
        free(aux);
    }

    return 1;
}

void liberar_lista(Lista *l)
{
    free(*l);
    (*l) = NULL;
}
