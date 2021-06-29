#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

#define MAX 20

struct no
{
    char nome[MAX];
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
int push(Pilha *p, char *nome)
{
    Pilha N = (Pilha)malloc(sizeof(struct no));

    if(N==NULL)
    {
        return 0;
    }

    strcpy(N->nome, nome);
    N->prox = *p; //inserção no início;
    *p = N;

    return 1;
}

//desempilha
int pop (Pilha *p, char *nome)
{
    if(pilha_vazia(*p)==1)
    {
        return 0;
    }

    Pilha aux = *p;

    strcpy(nome, aux->nome);

    *p = aux->prox;
    free(aux);

    return 1;
}

//devolve último elemento da pilha - topo
int get_topo(Pilha *p, char *nome)
{
    if(pilha_vazia(*p)==1)
    {
        return 0;
    }

    strcpy(nome, (*p)->nome);

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

int limpa_pilha(Pilha *p)
{
    if(pilha_vazia(*p)==1)
        return 0;

    Pilha aux = *p;

    while(aux != NULL)
    {
        *p = aux->prox;
        aux = aux->prox;
        free(aux);
    }

    return 1;
}
int libera_pilha(Pilha p)
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
    p = NULL;

    return 1;
}
