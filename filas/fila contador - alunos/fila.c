#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

#define MAX 20

struct Alunos
{
    int matricula;
    char nome[50];
    int faltas;
    float media;
};
typedef struct Alunos aluno;

struct fila
{
    aluno vetor[MAX];
    int ini, cont; //não é preciso campo para indicar fim da fila, pois fim é determinado pelo incremento circular entre ini e cont (fim=(ini+1)%cont)
};
typedef struct fila *Fila;

Fila cria_fila()
{
    Fila f;

    f = (Fila)malloc(sizeof(struct fila));

    if(f == NULL)
        return 0;

    f->ini = 0;
    f->cont = 0;

    return f;
}

int fila_vazia(Fila f)
{
    if(f->cont == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int fila_cheia(Fila f)
{
    if(f->cont == MAX)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int insere_fim(Fila f, aluno pessoa)
{
    if(fila_cheia(f) == 1)
    {
        return 0;
    }

    //fim = (f->ini + f->cont)%MAX

    f->vetor[(f->ini + f->cont)%MAX] = pessoa;
    f->cont++;

    return 1;
}

int remove_ini(Fila f, aluno *pessoa)
{
    if(fila_vazia(f)==1)
    {
        return 0;
    }

    *pessoa = f->vetor[f->ini];
    f->ini = (f->ini+1)%MAX; //incremento circular
    f->cont--; //decremento não circular

    return 1;
}

void tam_fila(Fila f, int *tam)
{
    if(fila_vazia(f) == 1 || f == NULL)
    {
        *tam = 0;
    }

    *tam = f->cont;
}

int limpa_fila(Fila f)
{
    if(f == NULL || fila_vazia(f)==1)
    {
        return 0;
    }

    f->ini = 0;
    f->cont = 0;

    return 1;
}

void libera_fila(Fila *f)
{
    free(*f);
    *f=NULL;
}
