#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "lista.h"

#define MAX 20

struct lista
{
    float no[MAX];
    int FIM;
};
typedef struct lista *Lista;

Lista cria_lista()
{
    Lista lst;
    lst = (Lista)malloc(sizeof(struct lista));

    if(lst == NULL)
    {
        return NULL;
    }

    (*lst).FIM = 0;

    return lst;
}

int lista_vazia(Lista l)
{
    if((*l).FIM == 0)
        return 1;
    else
        return 0;
}

int lista_cheia(Lista l)
{
    if((*l).FIM == MAX)
        return 1;
    else
        return 0;
}

int insere_elem (Lista l, float elem)
{
    if(l == NULL || lista_cheia(l) == 1)
        return 0;

    (*l).no[(*l).FIM] = elem;
    (*l).FIM++;

    return 1;
}

int remove_elem (Lista l, float elem)
{
    if(l == NULL || lista_vazia(l) == 1)
        return 0;

    int aux = 0;

    while(aux < (*l).FIM && (*l).no[aux] != elem)
        aux++;

    if(aux == (*l).FIM)
        return 0; //fim da lista, elemento não existe

    //desloca à esquerda do sucessor do elemento até fim da lista
    for(int i = aux+1; i < (*l).FIM; i++)
        (*l).no[i-1] = (*l).no[i];

    (*l).FIM--;

    return 1;
}

int limpa_lista (Lista l)
{
    if(l == NULL || lista_vazia(l))
    {
        return 0;
    }

    int fim;
    float valor;
    get_fim(l, &fim);

    for(int i=fim; i >= 0; i--)
    {
        get_values(l, i, &valor);
        remove_elem(l, valor);
    }
    return 1;
}


int *get_posicao (Lista l, float elem, int *p)
{
    if(l == NULL || lista_vazia(l) == 1)
        return 0;

    for(int i=0; i<(*l).FIM; i++)
    {
        if((*l).no[i] == elem)
        {
            *p = i;
            break;
        }else
        {
            printf("Elemento inexistente na lista!\n\n");
            return 0;
        }
    }

    return p;;
}

int *get_fim(Lista l, int *p)
{
    if(l == NULL)
        return 0;

    *p = (*l).FIM;

    return p;
}

float *get_values(Lista l, int i, float *v)
{
    if(l == NULL)
        return 0;

    *v = (*l).no[i];

    return v;
}
