#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

struct no
{
    int info;
    struct no *prox;
};
typedef struct no *Pilha;

Pilha cria_pilha()
{
    return NULL;
}

int pilha_vazia(Pilha p)
{
    if(p == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

//empilha
int push(Pilha *p, int elem)
{
    Pilha N = (Pilha)malloc(sizeof(struct no));

    if(N==NULL)
    {
        return 0;
    }

    N->info = elem;
    N->prox = *p; //inserção no início;
    *p = N;

    return 1;
}

//desempilha
int pop (Pilha *p, int *elem)
{
    if(pilha_vazia(*p)==1)
    {
        return 0;
    }

    Pilha aux = *p;

    *elem = aux->info; //elemento do topo;

    *p = aux->prox;
    free(aux);

    return 1;
}

//devolve último elemento da pilha - topo
int le_topo(Pilha *p, int *elem)
{
    if(pilha_vazia(*p)==1)
    {
        return 0;
    }

    *elem = (*p)->info;

    return 1;
}

int tam_pilha(Pilha p, int *tam)
{
    if(pilha_vazia(p) == 1)
    {
        *tam = 0;
        return 0;
    }

    Pilha aux = p;
    int cont = 1;

    while(aux->prox != NULL)
    {
        cont++;
        aux = aux->prox;
    }

    *tam = cont;

    return 1;
}

int limpa_pilha(Pilha p)
{
    if(pilha_vazia(p)==1)
        return 0;


    Pilha aux;

    while(p != NULL)
    {
        aux = p;
        p = p->prox;
        free(aux);
    }

    return 1;
}
