//PILHAS

//- estática sequencial:

tad.c

#define MAX 20

struct pilha {
	int vetor[MAX];
	int topo;
}

tad.h typedef struct pilha *Pilha;

Pilha cria_pilha()
{
	Pilha p;
	p = (Pilha)malloc(sizeof(struct pilha));
	if(p != NULL)
    {
        p->topo = -1;
    }

    return p;
}

int pilha_vazia(Pilha p)
{
    if(p->topo = -1)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int pilha_cheia(Pilha p)
{
    if(p->topo = MAX-1)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int push(Pilha p, int elem)
{
    if(p == NULL || pilha_cheia(p)==1)
    {
        return 0;
    }

    p->topo++;
    p->no[p->topo] = elem;

    return 1;
}

int pop(Pilha p, int *elem)
{
    if(p == NULL || pilha_vazia(p)==1)
    {
        return 0;
    }

    *elem = p->no[p->topo];
    p->topo--;

    return 1;
}

int le_topo(Pilha p, int *elem)
{
    if(p == NULL || pilha_vazia(p)==1)
    {
        return 0;
    }

    *elem = p->no[p->topo];

    return 1;
}








//- dinâmica encadeada simples:

tad.c

struct no
{
    int info;
    struct no *prox;
};

tad.h = typedef struct no *Pilha;


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

int push(Pilha *p, int elem)
{
    Pilha N = (Pilha)malloc(sizeof(struct no));

    if(N == NULL)
        return 0;

    N->info = elem;
    N->prox = *p;
    *p = N;

    return 1;
}

int pop(Pilha *p, int *elem)
{
    if(pilha_vazia(*p)==1)
    {
        return 0;
    }

    Pilha aux = *p;

    *elem = aux->info;

    *p = aux->prox;
    free(aux);

    return 1;
}

int le_topo(Pilha *p, int *elem)
{
    if(pilha_vazia(*p)==1)
    {
        return 0;
    }

    *elem = (*p)->info;

    return 1;
}

//- dinâmica encadeada circular:
