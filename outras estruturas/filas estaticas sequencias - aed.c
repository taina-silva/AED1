//desperdício de posição
//armazena MAX-1 elementos

#define MAX 20

struct fila
{
    int vetor[MAX];
    int ini, fim;
};

tad.h: typedef struct fila *Fila;

Fila cria_fila()
{
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));

    if(f!=NULL)
    {
        f->ini = 0;
        f->fim = 0;
    }

    return f;
}

int fila_vazia(Fila f)
{
    if(f->ini == f->fim)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int fila_cheia(Fila f)
{
    if(f->ini == (f->fim+1)%MAX)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int insere_fim(Fila f, int elem)
{
    if(fila_cheia(f)==1)
    {
        return 0;
    }

    f->no[f->fim] = elem;
    f->fim = (f->fim + 1)%MAX;

    return 1;
}

int remove_ini(Fila f, int *elem)
{
    if(fila_vazia(f)==1)
    {
        return 0;
    }

    *elem = f->no[f->ini];
    f->ini = (f->ini + 1)%MAX;

    return 1;
}



//desperdício de posição
//armazena MAX elementos

#define MAX 20

struct fila
{
    int vetor[MAX];
    int ini, cont;
};

tad.h: typedef struct fila *Fila;

Fila cria_fila()
{
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));

    if(f!=NULL)
    {
        f->ini = 0;
        f->cont = 0;
    }

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

int insere_fim(Fila f, int elem)
{
    if(fila_cheia(f)==1)
    {
        return 0;
    }

    int fim = (f->ini + f->cont)%MAX;
    f->no[fim] = elem;
    f->cont++;

    return 1;
}

int remove_ini(Fila f, int *elem)
{
    if(fila_vazia(f)==1)
    {
        return 0;
    }

    *elem = f->no[f->ini];
    f->ini = (f->ini + 1)%MAX;
    f->cont--;

    return 1;
}
