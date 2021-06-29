#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "no.h"

struct no
{
    int elem;
    struct no *prox;
};
typedef struct no *Lista;

Lista cria_lista()
{
    Lista cab;

    cab = (Lista)malloc(sizeof(struct no));

    if(cab != NULL)
    {
        cab->prox = NULL;
        cab->elem = 0;
    }

    return cab;
}

int lista_vazia(Lista l)
{
    if(l->prox == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista l, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->elem = elem;
    N->prox = l->prox;
    l->prox = N;
    l->elem++;

    return 1;
}

int remove_elem(Lista *l, int elem)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = *l;

    while(aux->prox != NULL && aux->prox->elem != elem)
    {
        aux = aux->prox;
    }

    if(aux->prox == NULL) //fim da lista
        return 0;

    Lista aux2 = aux->prox; //aponta nó a ser removido
    aux->prox = aux2->prox; //retira nó da lista, aponta para nó seguinte
    free(aux2); //libera memória aux
    (*l)->elem--;

    return 1;
}

int remove_ord(Lista *l, int *elem)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = *l;
    Lista anterior;

    int maior = (*l)->prox->elem;

    while(aux->prox != NULL)
    {
        if(aux->prox->elem > maior)
        {
            anterior = aux;
            maior = aux->prox->elem;
        }

        aux = aux->prox;
    }

    *elem = maior;

    if(aux->prox == NULL) //fim da lista
    {
        anterior = *l;
    }

    Lista aux2 = anterior->prox;
    anterior->prox = aux2->prox;
    free(aux2);

    (*l)->elem--;

    return 1;
}

int get_posicao(Lista *l, int elem, int *i)
{
    if(lista_vazia(*l) == 1)
        return 0;

    int pos=1;

    Lista aux = *l;

    while((*aux).prox != NULL && (*(*aux).prox).elem == elem)
    {
        aux = aux->prox;
        pos++;
    }

    if((*aux).prox == NULL) //fim da lista
        return 0;

    *i = pos;
    return 1;
}

int get_fim(Lista *l, int *i)
{
    if(lista_vazia(*l) == 1)
        return 0;

    //int pos=0;

    Lista aux = *l;

    //while(aux->prox != NULL)
    //{
    //    aux = aux->prox;
    //    pos++;
    //}

    *i = aux->elem;
    return 1;
}


int get_values(Lista l, int *elem, int p)
{
    if(lista_vazia(l) == 1)
        return 0;

    Lista aux = l->prox;

    int pos=1;

    while(aux->prox != NULL && pos < p)
    {
        aux = aux->prox ;
        pos++;
    }

    *elem = aux->elem;

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

    for(int i=1; i <= end; i++)
    {
        get_values(aux, &numero, i);
        remove_elem(&aux, numero);
    }
    (*l)->prox = NULL;

    return 1;
}

void liberar_lista(Lista *l)
{
    free(*l);
    (*l) = NULL;
}
