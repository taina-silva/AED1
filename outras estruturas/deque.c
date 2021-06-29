//deque estático com desperdício de posição

#define N 15

struct deque
{
    int vetor[N];
    int ini, fim;
};

Deque cria_deque()
{
    Deque p = (Deque) malloc(sizeof(struct deque));
    if(p != NULL){
        p->ini = 0; //
        p->fim = 0; //inicializacao
    }
    return p;
}

int insere_fim(Deque p, int A) // insercao no fim
{
    if (deque_cheio(p) == 1)
        return 0;
    else{
        p->vetor[p->fim] = A;
        p->fim = (p->fim+1)%N;
        return 1;
    }
}

int insere_ini(Deque p, int A) // insercao no inicio
{
    if(deque_cheio(p) == 1)
        return 0;
    else{
        p->ini = (p->ini-1+N)%N;
        p->vetor[p->ini] = A;
        return 1;
    }
}

int remove_ini(Deque p, int *f) // remocao no inicio
{
    if (deque_vazio(p) == 1)
    {
        return 0;
    }
    *f = p->vetor[p->ini];
    p->ini = (p->ini+1)%N;
    return 1;
}

int remove_fim(Deque p, int *f) // remocao no fim
{
     if (deque_vazio(p) == 1)
    {
        return 0;
    }
    p->fim = (p->fim-1+N)%N;
    *f = p->vetor[p->fim];
    return 1;
}

int deque_vazio (Deque p)  // verifica se esta vazio
{
    if(p->ini == p->fim)
        return 1;
    else
        return 0;
}

int deque_cheio(Deque p) // verifica se esta cheio
{
    if (p->ini == (p->fim+1)%N)
        return 1;
    else
        return 0;
}

int esvazia_deque(Deque p){
    if(p == NULL)
        return 0;
    p->ini = 0;
    p->fim = 0;
    return 1;
}

void apaga_deque(Deque* p)
{
    free(*p);
    p = NULL;
}










//deque encadeado circular

#include <stdlib.h>
#include "Untitled1.h"

struct deque
{
    struct no *ini;
    struct no *fim;
};

struct no
{
    char info;
    struct no *prox;
};

Deque cria_deque()
{
    Deque p = (Deque) malloc(sizeof(struct deque));
    if(p != NULL)
    {
        p->ini = NULL; //
        p->fim = NULL; //inicializacao
    }
    return p;
}

int insere_fim(Deque p, char A) // insercao no fim
{
    No N = (No) malloc(sizeof(No));
    if(p->ini==NULL)
    {
        p->ini=N;
    }

    N->prox=p->ini;
    N->info=A;

    if(p->fim != NULL)
    {
        p->fim->prox=N;
    }
    p->fim=N;
    return 1;
}

int insere_ini(Deque p, char A) // insercao no inicio
{
    No N = (No) malloc(sizeof(No));
    N->prox=p->ini;
    N->info=A;
    p->ini=N;

    if(p->fim == NULL)
    {
        p->fim=N;
    }
    p->fim->prox=p->ini;
    return 1;
}

int remove_ini(Deque p, char *f) // remocao no inicio
{
    No aux;
    if (deque_vazio(p) == 1 || p->ini==NULL)
    {
        return 0; // falso
    }

    *f=p->ini->info;

    if(p->fim == p->ini)
    {
        free(p->ini);
        p->ini=NULL;
        p->fim=NULL;
    }
    else
    {
        aux=p->ini;
        p->ini=p->ini->prox;
        p->fim->prox=p->ini;
        free(aux);
    }
    return 1;
}

int remove_fim(Deque p, char *f) // remocao no fim
{
    No aux;
    No percorre;
    if (deque_vazio(p) == 1 || p->fim==NULL)
    {
        return 0;
    }

    *f=p->fim->info;

    if(p->fim == p->ini)
    {
        free(p->ini);
        p->ini=NULL;
        p->fim=NULL;
    }
    else
    {
        aux=p->fim;
        percorre=p->ini;
        while(percorre->prox != aux)
        {
            percorre=percorre->prox;
        }
        p->fim=percorre;
        p->fim->prox=p->ini;
        free(aux);
    }

    return 1;
}

int deque_vazio (Deque p)  // verifica se esta vazio
{
    if(p->ini==NULL || p->fim==NULL)
        return 1;

    else
        return 0;
}

int esvazia_deque(Deque p)
{
    if(p == NULL)
        return 0;

    while(deque_vazio(p)!=1)
    {
        char f = 'A';
        remove_ini(p,&f);
    }
    p->ini = NULL;
    p->fim = NULL;
    return 1;
}

void apaga_deque(Deque* p)
{
    esvazia_deque(*p);
    free(*p);
}



