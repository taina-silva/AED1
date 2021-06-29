//fila prioridade não-ordenada

//inserção no final
//remoção ordenada

//fila prioridade ordenada

//inserção ordenada
//remoção no início


//fila prioridade encadeada simples

struct no
{
    int info;
    struct no *prox;
};

tad.h: typedef struct no *No;

struct fila
{
    struct no * ini;
    struct no * fim;
};

tad.h: typedef struct fila *Fila;

Fila cria_fila()
{
    Fila f;
    f = (Fila) malloc(sizeof(struct fila));
    if (f != NULL)
    {
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_vazia(Fila f)
{
    if (f->ini == NULL)
        return 1;
    else
        return 0;
}

int insere_fim(Fila f, int elem)
{
    No N;
    N = (No) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N->info = elem; // Preenche campo aluno
    N->prox = NULL; // Preenche campo prox

    if (fila_vazia(f) == 1)
        f->ini = N; // Se fila vazia
    else
        (f->fim)->prox = N; // Se fila com elementos (NÃO vazia)

    f->fim = N; // Campo fim aponta para N
    return 1;
}

int insere_ord(Fila f, int elem)
{
    No N;
    N = (struct no *) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N->aluno = elem;

    if(fila_vazia(f)==1)
    {
        N->prox = NULL;
        f->ini = N;
        f->fim = N;
        return 1;
    }

    if(elem <= f->ini->info)
    {
        N->prox = f->ini;
        f->ini = N;
        return 1;
    }

    No aux = f->ini;

    while(aux->prox != NULL && aux->prox->info < elem)
    {
        aux = aux->prox;
    }

    N->prox = aux->prox;
    aux->prox = N;

    return 1;
}

int remove_ini(Fila f, int *elem)
{
    if (fila_vazia(f) == 1)
        return 0;

    No aux = f->ini;// Aux aponta para o 1o nó
    *elem = aux->info; // Retorna valor do elemento
    // Verifica se a fila tem um único nó
    if (f->ini == f->fim)
        f->fim = NULL;
    f->ini = aux->prox; // Retira 1o nó da fila
    free(aux); // Libera a memória alocada
    return 1;
}

int remove_ord(Fila *f, int *elem)
{
    if(fila_vazia(*f) == 1)
    {
        return 0;
    }

    No aux = (*f)->ini;// Aux aponta para o 1o nó
    No aux2 = (*f)->ini;// Aux aponta para o 1o nó
    *elem = aux->info; // Retorna valor do elemento

    //percorre até fim da fila
    while(aux->prox != NULL)
    {
        if(aux->prox->info <= *elem){
            aux2 = aux;
            (*elem) = aux->prox->aluno;
        }

        aux = (*aux).prox; //aux pega endereço de próxima região
    }
    if((*f)->ini->info == *ele){//menor elemento primeiro nó
        aux = (*f)->ini;
        (*f)->ini = aux->prox;
        free(aux); //libera memória aux
        return 1;
    }

    aux = aux2;
    aux2 = (*aux).prox; //aponta nó a ser removido
    (*aux).prox = (*aux2).prox; //retira nó da fila, aponta para nó seguinte
    free(aux2); //libera memória aux

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








//fila prioridade estática sequencial - contador

#define MAX 20


struct fila
{
    int vetor[MAX];
    int ini, cont; //não é preciso campo para indicar fim da fila, pois fim é determinado pelo incremento circular entre ini e cont (fim=(ini+1)%cont)
};

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

int insere_fim(Fila f, int elem)
{
    if(fila_cheia(f) == 1)
    {
        return 0;
    }

    int fim = (f->ini + f->cont)%MAX

    f->vetor[fim] = elem;
    f->cont++;

    return 1;
}

int insere_cres_ord(Fila f, int elem)
{
    if (f == NULL || fila_cheia(f) == 1)
    {
        return 0; // Falha
    }

    // Trata fila vazia ou elemento ≥ último da fila
    if (fila_vazia(f) == 1 || elem >= f->vetor[(f->ini + f->cont-1)%MAX])
    {
        f->vetor[(f->ini + f->cont)%MAX] = elem; // Insere no final
    }
    else
    {
        int i, j = 0, aux = f->ini;
        while (elem >= f->vetor[aux])   // Percorrimento
        {
            aux = (aux + 1)%MAX;
        }

        for (i = (f->ini + f->cont)%MAX; i > (aux)%MAX; i = (i - 1)%MAX) // Deslocamento
        {
            f->vetor[i] = f->vetor[i-1];
            j++;
        }
        f->vetor[aux] = elem; // Inclui o elemento na fila
    }
    f->cont++; // Avança o Fim
    return 1;  // Sucesso
}

int insere_decres_ord(Fila f, int elem)
{
    if (f == NULL || fila_cheia(f) == 1)
    {
        return 0; // Falha
    }

    // Trata fila vazia ou elemento <= último da fila
    if (fila_vazia(f) == 1 || elem <= f->vetor[(f->ini + f->cont-1)%MAX])
    {
        f->vetor[f->ini] = elem; // Insere no final
    }
    else if (elem <= f->vetor[(f->ini + f->cont-1)%MAX]){
        f->vetor[(f->ini + f->cont)%MAX] = elem;// Insere no final
    }else
    {
        int i, j = 0, aux = f->ini;
        while (elem <= f->vetor[aux])   // Percorrimento
        {
            aux = (aux + 1)%MAX;
        }

        for (i = (f->ini + f->cont)%MAX; i > (aux)%MAX; i = (i - 1)%MAX) // Deslocamento
        {
            f->vetor[i] = f->vetor[i-1];
            j++;
        }
        f->vetor[aux] = elem; // Inclui o elemento na fila
    }

    f->cont++; // Avança o Fim
    return 1;  // Sucesso
}

int remove_ini(Fila f, int *elem)
{
    if(fila_vazia(f)==1)
    {
        return 0;
    }

    *elem = f->vetor[f->ini];
    f->ini = (f->ini+1)%MAX; //incremento circular
    f->cont--; //decremento não circular

    return 1;
}

int remove_ord(Fila f, int *elem)
{
    if(fila_vazia(f)==1)
    {
        return 0;
    }

    int menor = f->ini;

    int fim = (f->ini + f->cont)%MAX;
    int percorre = f->ini;

    while(percorre != fim)
    {
        if(f->vetor[percorre] < f->vetor[menor])
        {
            menor = percorre;
        }

        percorre = (percorre+1)%MAX;
    }

    while(menor != fim)
    {
        f->vetor[menor] = f->vetor[(menor+1)%MAX];
        menor = (menor+1)%MAX;
    }

    return 1;
}

void tam_fila(Fila f, int *tam)
{
    if(fila_vazia(f) == 1 || f == NULL)
    {
        *tam = 0;
    }

    aux = f->ini;
    *tam = f->cont;


}
