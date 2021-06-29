#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "bebidas-ord.h"

#define MAX1 20
#define MAX2 11

struct lista
{
    char palavra[MAX1][MAX2];
    int volume[MAX1];
    float preco[MAX1];
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

int insere_ord (Lista l, char *elem, int vol, float p)
{
    if(l == NULL || lista_cheia(l) == 1)
        return 0;

    int j=0;
    char elem2[MAX2];
    while(elem[j] != '\0')
    {
        elem2[j] = tolower(elem[j]);
        j++;
    }
    elem2[j] = '\0';


    if(lista_vazia(l)==1)
    {
        strcpy((*l).palavra[(*l).FIM], elem2);
        (*l).volume[(*l).FIM] = vol;
        (*l).preco[(*l).FIM] = p;
    }else
    {
        int i, aux=0;
        int v;
        float pr;
        while((aux < (*l).FIM) && (strcmp(elem2, (*l).palavra[aux]) >= 0))
        {
            if(strcmp(elem2, (*l).palavra[aux])==0)
            {
                if((*l).volume[aux] > vol)
                {
                    break;
                }
            }
            aux++;
        }

        for(i=(*l).FIM; i>aux; i--)
        {
            strcpy((*l).palavra[i], (*l).palavra[i-1]);
            get_nome(l, i-1, (*l).palavra[i-1]);
            get_volume(l, i-1, &v);
            get_preco(l, i-1, &pr);
            (*l).volume[i] = (*l).volume[i-1];
            (*l).preco[i] = (*l).preco[i-1];
        }

        strcpy((*l).palavra[aux], elem2);
        (*l).volume[aux] = vol;
        (*l).preco[aux] = p;
    }

    (*l).FIM++;

    return 1;
}

int remove_ord (Lista l, char *elem)
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
    {
        strcpy((*l).palavra[i-1], (*l).palavra[i]);
        (*l).volume[i-1] = (*l).volume[i];
        (*l).preco[i-1] = (*l).preco[i];
    }

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
        get_nome(l, i, elem);
        remove_ord(l, elem);
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
    if(l == NULL)
        return 0;

    *p = (*l).FIM;

    return p;
}

char *get_nome(Lista l, int i, char *elem)
{
    if(l == NULL || lista_vazia(l) == 1)
        return NULL;

    strcpy(elem, (*l).palavra[i]);
    return elem;
}

int *get_volume(Lista l, int i, int *v)
{
    if(l == NULL || lista_vazia(l) == 1)
        return 0;

    *v = (*l).volume[i];
    return v;
}

float *get_preco(Lista l, int i, float *p)
{
    if(l == NULL || lista_vazia(l) == 1)
        return 0;

    *p = (*l).preco[i];
    return p;
}

void liberar_lista(Lista *l)
{
    free(*l);
    *l = NULL;
}
