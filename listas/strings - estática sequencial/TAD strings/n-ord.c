#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "n-ord.h"

#define MAX1 20
#define MAX2 11

struct lista
{
    char palavra[MAX1][MAX2];
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
    if((*l).FIM == MAX1)
        return 1;
    else
        return 0;
}

int insere_elem (Lista l, char *elem)
{
    if(l == NULL || lista_cheia(l) == 1)
        return 0;

    strcpy((*l).palavra[(*l).FIM], elem);
    (*l).FIM++;

    return 1;
}

int remove_elem (Lista l, char *elem)
{
    if(l == NULL || lista_vazia(l) == 1)
        return 0;

    int aux = 0;

    while(aux < (*l).FIM && strcmp((*l).palavra[aux], elem) != 0)
    {
        aux++;
    }

    if(aux == (*l).FIM)
        return 0; //fim da lista, elemento não existe

    //desloca à esquerda do sucessor do elemento até fim da lista
    for(int i = aux+1; i < (*l).FIM; i++)
        strcpy((*l).palavra[i-1], (*l).palavra[i]);

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
    char elem[MAX2];
    get_fim(l, &fim);

    for(int i=fim; i >= 0; i--)
    {
        get_values(l, i, elem);
        remove_elem(l, elem);
    }
    return 1;
}


int *get_posicao (Lista l, char *elem, int *p)
{
    if(l == NULL || lista_vazia(l) == 1)
        return 0;

    for(int i=0; i<(*l).FIM; i++)
    {
        if((*l).palavra[i][MAX2] == (*elem))
        {
            *p = i;
            break;
        }else
        {
            printf("Elemento inexistente na lista!\n\n");
            return 0;
        }
    }

    return p;
}

int *get_fim(Lista l, int *p)
{
    if(l == NULL || lista_vazia(l) == 1)
        return NULL;

    *p = (*l).FIM;

    return p;
}

char *get_values(Lista l, int i, char *elem)
{
    if(l == NULL)
        return 0;


    strcpy(elem, (*l).palavra[i]);

    return elem;
}

void liberar_lista(Lista *l)
{
    free(*l);
    *l = NULL;
}
