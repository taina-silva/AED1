//FILAS

//fila encadeada simples:

tad.c

struct no {
    int info;
    struct no *prox;
};

tad.h typedef struct no *No;

struct fila {
    No ini;
    No fim;
};

tad.h typedef struct fila *Fila;

Fila cria_fila()
{
    Fila f;

    f = (Fila)malloc(sizeof(struct fila));

    if(f != NULL)
    {
        f->ini = NULL;
        f->fim = NULL;
    }

    return f;
}

int fila_vazia(Fila f)
{
    if(f->ini == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int insere_fim(Fila f, int elem)
{
    No N;

    N = (No)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = elem;
    N->prox = NULL;

    if(fila_vazia(f)==1)
    {
        f->ini = N;
    }else
    {
        f->fim->prox = N;
    }

    f->fim = N;

    return 1;
}

int remove_ini(Fila f, int *elem)
{
    if(fila_vazia(f)==1)
    {
        return 0;
    }

    No aux = f->ini;

    *elem = aux->info;

    if(f->ini == f->fim)
    {
        f->fim = NULL;
    }

    f->ini = aux->prox;
    free(aux);

    return 1;
}

//fila encadeada circular:

tad.c

struct no
{
    int info;
    struc no *prox;
};

tad.h = typedef struct no *Fila;

Fila cria_fila()
{
    return NULL;
}

int fila_vazia(Fila f)
{
    if(f == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int insere_fim(Fila *f, int elem)
{
    Lista N = (Fila)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = elem;

    if(fila_vazia(*f)==1)
    {
        N->prox = N;
        *f = N;
    }else
    {
        N->prox = (*f)->prox;
        (*f)->prox = N;
        *f = N;
    }

    return 1;
}

int insere_inicio(Fila *f, int elem)
{
    Lista N = (Fila)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = elem;

    if(fila_vazia(*f)==1)
    {
        N->prox = N;
        *f = N;
    }else
    {
	N->prox = (*f)->prox;
        (*f)->prox = N;
    }

    return 1;
}

int remove_ini(Fila *f, int *elem)
{
    if(fila_vazia(*f)==1)
    {
        return 0;
    }

    Fila aux = (*f)->prox;

    *elem = aux->info;

    if(*f == (*f)->prox)
    {
        *f = NULL;
    }else
    {
        (*f)->prox = aux->prox;
    }

    free(aux);

    return 1;
}

int remove_final(Fila *f)
{
    if(lista_vazia(*f) == 1)
    {
        return 0;
    }

    Fila aux = *f;
    Fila aux2 = aux->prox; //guarda endereço primeiro no

    while(aux->prox != *f)
    {
        aux = aux->prox;
    }

    *f = aux;
    free(aux->prox);
    aux->prox = aux2;

    return 1;
}

int esvazia_deque(Deque *f)
{
    if(deque_vazio(*f)==1 || *f==NULL)
        return 0;

    Deque aux = *f;
    Deque aux2;

    while(aux->prox != *f)
    {
        aux2 = aux->prox;
        aux->prox = aux2->prox;
        free(aux2);
    }

    if(*f == (*f)->prox)
    {
        *f = NULL;
        free(aux);
    }

    return 1;
}

void esvazia_fila(Fila f)
{
    struct no * aux;
    while(f->ini != NULL)
    {
        if(f->ini == f->fim)
        {
            f->fim = NULL;
        }

        aux = f->ini;
        f->ini = f->ini->prox;
        free(aux);
    }
}

void apaga_fila(Fila *f)
{
    free(*f);
    *f = NULL;
}

