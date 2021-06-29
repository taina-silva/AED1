#include <stdio.h>
#include <stdlib.h>

#include "deque.h"

#define MAX 20

struct deque
{
    int vetor[MAX];
    int ini, cont; //não é preciso campo para indicar fim da Deque, pois fim é determinado pelo incremento circular entre ini e cont (fim=(ini+1)%cont)
};

Deque cria_deque()
{
    Deque f;

    f = (Deque)malloc(sizeof(struct deque));

    if(f == NULL)
        return 0;

    f->ini = 0;
    f->cont = 0;

    return f;
}

int deque_vazio(Deque f)
{
    if(f->cont == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int deque_cheio(Deque f)
{
    if(f->cont == MAX)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int insere_fim(Deque f, int elem)
{
    if(deque_cheio(f) == 1)
    {
        return 0;
    }

    int fim = (f->ini + f->cont)%MAX;
    f->vetor[fim] = elem;
    f->cont++;

    return 1;
}

int insere_inicio(Deque f, int elem)
{
    if(deque_cheio(f) == 1)
    {
        return 0;
    }

    f->ini = (f->ini - 1)%MAX;
    f->vetor[f->ini] = elem;
    f->cont++;

    return 1;
}

int remove_ini(Deque f, int *elem)
{
    if(deque_vazio(f)==1)
    {
        return 0;
    }

    *elem = f->vetor[f->ini];
    f->ini = (f->ini+1)%MAX; //incremento circular
    f->cont--; //decremento não circular

    return 1;
}

int remove_fim(Deque f, int *elem)
{
    if(deque_vazio(f)==1)
    {
        return 0;
    }

    int fim = (f->ini + f->cont)%MAX
    *elem = f->vetor[fim];
    f->cont--;

    return 1;
}

int tam_deque(Deque f, int *tam)
{
    if(deque_vazio(f) == 1 || f == NULL)
    {
        *tam = 0;
        return 0;
    }

    *tam = f->cont;

    return 1;
}

int limpa_deque(Deque f)
{
    if(f == NULL || deque_vazio(f)==1)
    {
        return 0;
    }

    f->ini = 0;
    f->cont = 0;

    return 1;
}

void liberar(Deque *f)
{
    free(*f);
    *f = NULL;
}
