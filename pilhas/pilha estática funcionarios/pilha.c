#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

#define max 30

struct funcionarios
{
    long int matricula;
    char nome[max];
    char setor;
    float salario;
};
typedef struct funcionarios Funcionarios;

struct pilha
{
    Funcionarios no[max];
    int topo;
};
typedef struct pilha * Pilha;

Pilha cria_pilha ()
{
    Pilha p;
    p = (Pilha)malloc(sizeof(struct pilha));

    if (p != NULL)
        p->topo = -1;
    return p;
}

int pilha_vazia (Pilha p)
{
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia (Pilha p) {
    if (p->topo == max-1)
        return 1;
    else
        return 0;
}

int push (Pilha p, long int matricula, char *nome, char setor, float salario)
{
    if (p == NULL || pilha_cheia(p) == 1)
        return 0;// Insere o elemento no topo

    p->topo++;
    p->no[p->topo].matricula = matricula;
    p->no[p->topo].setor = setor;
    p->no[p->topo].salario = salario;
    strcpy(p->no[p->topo].nome, nome);

    return 1;
}

int pop (Pilha p, long int *matricula, char *nome, char *setor, float *salario)
{
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;

    *matricula = p->no[p->topo].matricula; // Retorna o elemento
    *salario = p->no[p->topo].salario; // Retorna o elemento
    strcpy(nome, p->no[p->topo].nome);// Retorna o elemento
    *setor = p->no[p->topo].setor;// Retorna o elemento
    p->topo--; // Remove o elemento do topo

    return 1;
}

//devolve último elemento da pilha - topo
int get_topo(Pilha p, long int *matricula, char *nome, char *setor, float *salario)
{
    if(p==NULL || pilha_vazia(p)==1)
    {
        return 0;
    }

    *matricula = p->no[p->topo].matricula;
    strcpy(nome, p->no[p->topo].nome);
    *setor = p->no[p->topo].setor;
    *salario = p->no[p->topo].salario;

    return 1;
}

void esvazia_pilha(Pilha *p)
{
    (*p)->topo = -1;
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

int libera_pilha(Pilha *p)
{
     free(*p);
     *p = NULL;

     return 1;
}
