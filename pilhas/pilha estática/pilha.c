#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

#define MAX 20

struct pilha
{
    int vetor[MAX];
    int topo;
};
typedef struct pilha *Pilha;

Pilha cria_pilha()
{
    Pilha p;

    p = (Pilha)malloc(sizeof(struct pilha));

    if(p==NULL)
        return 0;

    p->topo = -1; //indica última posição ocupada da lista

    return p;
}

int pilha_vazia(Pilha p)
{
    if(p->topo == -1)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int pilha_cheia(Pilha p)
{
    if(p->topo == MAX-1)
    {
        return 1;
    }else
    {
        return 0;
    }
}

//empilha
int push(Pilha p, int elem)
{
    if(p==NULL || pilha_cheia(p)==1)
    {
        return 0;
    }

    p->topo++; //pega posição livre
    p->vetor[p->topo] = elem; //insere elem na posição livre

    return 1;
}

//desempilha
int pop (Pilha p, int *elem)
{
    if(p==NULL || pilha_vazia(p)==1)
    {
        return 0;
    }

    *elem = p->vetor[p->topo];

    p->topo--; //remove último elemento

    return 1;
}

//devolve último elemento da pilha - topo
int le_topo(Pilha p, int *elem)
{
    if(p==NULL || pilha_vazia(p)==1)
    {
        return 0;
    }

    *elem = p->vetor[p->topo];

    return 1;
}

int tam_pilha(Pilha p, int *tam)
{
    if(pilha_vazia(p) == 1)
    {
        *tam = 0;
        return 0;
    }

    *tam = p->topo + 1;

    return 1;
}

int limpa_pilha(Pilha p)
{
    if(p == NULL || pilha_vazia(p)==1)
    {
        return 0;
    }

    int tam = p->topo + 1;

    while(tam--)
    {
        p->topo--;
    }

    return 1;
}
