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

int insere_ord (Lista l, float elem)
{
    if(l == NULL || lista_cheia(l) == 1)
        return 0;

    if(lista_vazia(l) == 1 || elem >= (*l).no[(*l).FIM - 1])
    {
        (*l).no[(*l).FIM] = elem;
    }else
    {
        int i, aux = 0;
        while(elem >= (*l).no[aux])
            aux++;

        for(i=(*l).FIM; i>aux; i--)
            (*l).no[i] = (*l).no[i-1];

        (*l).no[aux] = elem;
    }

    (*l).FIM++;

    return 1;
}

int remove_ord (Lista l, float elem)
{
    if(l == NULL || lista_vazia(l) == 1 || elem < (*l).no[0] || elem > (*l).no[(*l).FIM - 1])
        return 0;

    int aux = 0;

    while(aux < (*l).FIM && (*l).no[aux] < elem)
        aux++;

    if(aux == (*l).FIM || (*l).no[aux] > elem)
        return 0; //fim da lista, elemento não existe

    //desloca à esquerda do sucessor do elemento até fim da lista
    for(int i = aux+1; i < (*l).FIM; i++)
        (*l).no[i-1] = (*l).no[i];

    (*l).FIM--;

    return 1;
}
