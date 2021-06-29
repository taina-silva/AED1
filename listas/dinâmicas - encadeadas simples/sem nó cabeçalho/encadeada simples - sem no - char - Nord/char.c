#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "char.h"

struct no
{
    char info;
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
        return 1;
    else
        return 0;
}

int insere_elem(Lista *l, char letter)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = letter;

    (*N).prox = *l;
    *l = N;

    return 1;
}

int insere_ord(Lista *l, char letter)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = letter;

    if(lista_vazia(*l) == 1 || letter <= (*l)->info)
    {
        (*N).prox = *l;
        *l = N;
        return 1;
    }

    Lista aux = *l;

    while(aux->prox != NULL && aux->prox->info < letter)
    {
        aux = aux->prox;
    }

    N->prox = aux->prox;
    aux->prox = N;

    return 1;
}

int remove_elem(Lista *l, char *letter)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = *l; //ponteiro aux para primeiro n�

    //trata letra = primeiro n� da lista
    if(*letter == (*l)->info)
    {
        *l = (*aux).prox; //lista aponta para segundo n�
        free(aux); //libera mem�ria de aux

        return 1;
    }

    //percorre at� fim da lista ou achar letra
    while((*aux).prox != NULL && aux->prox->info != *letter)
    {
        aux = (*aux).prox; //aux pega endere�o de pr�xima regi�o
    }

    if((*aux).prox == NULL) //fim da lista
        return 0;

    //remove letra diferente da do primeiro n�
    Lista aux2 = (*aux).prox; //aponta n� a ser removido
    (*aux).prox = (*aux2).prox; //retira n� da lista, aponta para n� seguinte
    free(aux2); //libera mem�ria aux

    return 1;
}

int remove_ord(Lista *l, char *letter)
{
    if(lista_vazia(*l) == 1 || *letter < (*l)->info)
    {
        return 0;
    }

    Lista aux = *l; //ponteiro aux para primeiro n�

    //trata letra = primeiro n� da lista
    if(*letter == (*l)->info)
    {
        *l = (*aux).prox; //lista aponta para segundo n�
        free(aux); //libera mem�ria de aux

        return 1;
    }

    //percorre at� fim da lista ou achar letra
    while((*aux).prox != NULL && aux->prox->info < *letter)
    {
        aux = (*aux).prox; //aux pega endere�o de pr�xima regi�o
    }

    if((*aux).prox == NULL || aux->prox->info > *letter) //fim da lista
        return 0;

    //remove letra diferente da do primeiro n�
    Lista aux2 = (*aux).prox; //aponta n� a ser removido
    (*aux).prox = (*aux2).prox; //retira n� da lista, aponta para n� seguinte
    free(aux2); //libera mem�ria aux

    return 1;
}

int get_posicao(Lista *l, char letter, int *i)
{
    if(lista_vazia(*l) == 1)
        return 0;

    int pos=1;

    Lista aux = *l;

    //percorre at� fim da lista ou at� achar elemento
    while((*aux).prox != NULL && aux->prox->info != letter)
    {
        aux = (*aux).prox;
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

    int pos=0;

    Lista aux = *l;

    while((*aux).prox != NULL)
    {
        aux = (*aux).prox;
        pos++;
    }

    *i = pos+1;
    return 1;
}


int get_values(Lista *l, int p, char *elem)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = *l;

    int pos=1;

    while((*aux).prox != NULL && pos < p)
    {
        aux = (*aux).prox ;
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
    char carac;
    get_fim(&aux, &end);

    for(int i=1; i <= end; i++)
    {
        carac = get_values(&aux, i, &carac);
        remove_ord(&aux, &carac);
    }
    (*l) = NULL;

    return 1;
}

void liberar_lista(Lista *l)
{
    free(*l);
    (*l) = NULL;
}
