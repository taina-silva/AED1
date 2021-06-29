#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

#define MAX 21

struct fila
{
    int vetor[MAX];
    int ini, fim;
};
typedef struct fila *Fila;

Fila cria_fila()
{
    Fila f;

    f = (Fila)malloc(sizeof(struct fila));

    if(f == NULL)
        return 0;

    f->ini = 0;
    f->fim = 0;

    return f;
}

int fila_vazia(Fila f)
{
    if(f->ini == f->fim) //inicio tem que ser igual a fim, mas não necessariamente serão iguais a 0
    {
        return 1;
    }else
    {
        return 0;
    }
}

int fila_cheia(Fila f)
{
    if(f->ini == (f->fim+1)%MAX) //fim está em posição anterior ao início
    {
        return 1;
    }else
    {
        return 0;
    }
}

int insere_fim(Fila f, int elem)
{
    if(fila_cheia(f) == 1)
    {
        return 0;
    }

    f->vetor[f->fim] = elem;
    f->fim = (f->fim+1)%MAX; //incremento circular

    return 1;
}

int remove_ini(Fila f, int *elem)
{
    if(fila_vazia(f)==1)
    {
        return 0;
    }

    *elem = f->vetor[f->ini];
    f->ini = (f->ini+1)%MAX;

    return 1;
}

int tam_fila(Fila f, int *tam)
{
    if(fila_vazia(f) == 1 || f == NULL)
    {
        *tam = 0;
        return 0;
    }

    *tam = f->fim - f->ini;

    return 1;
}

int limpa_fila(Fila f)
{
    if(f == NULL || fila_vazia(f)==1)
    {
        return 0;
    }

    f->ini = 0;
    f->fim = 0;

    return 1;
}

void libera_fila(Fila *f)
{
    free(*f);
    *f=NULL;
}
