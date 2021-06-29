#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"

struct Alunos
{
    unsigned int matricula;
    char nome[20];
    float media;
    int faltas;
};
typedef struct Alunos alunos;

struct no
{
    alunos *aluno;
    struct no *prox;
};
typedef struct no *Lista;

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista l)
{
    if(l == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista *l, unsigned int matri, char *name, float med, int falta)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->aluno->matricula = matri;
    strcpy(N->aluno->nome, name);
    N->aluno->media = med;
    N->aluno->faltas = falta;

    (*N).prox = *l;
    *l = N;

    return 1;
}

int remove_elem(Lista *l, int matri)
{
    if(lista_vazia(*l) == 1)
    {
        return 0;
    }

    Lista aux = *l;

    if(matri == (*l)->aluno->matricula)
    {
        *l = (*aux).prox;
        free(aux);
        return 1;
    }

    while(aux->prox != NULL && aux->prox->aluno->matricula != matri)
    {
        aux = aux->prox;
    }

    if((*aux).prox == NULL)
        return 0;

    Lista aux2 = (*aux).prox;
    (*aux).prox = (*aux2).prox;
    free(aux2);

    return 1;
}

int get_posicao(Lista *l, int matri)
{
    if(lista_vazia(*l) == 1)
        return 0;

    int pos=1;

    Lista aux = *l;

    if(matri == (*l)->aluno->matricula)
    {
        return pos;
    }

    while((*aux).prox != NULL && aux->prox->aluno->matricula != matri)
    {
        aux = (*aux).prox;
        pos++;
    }

    if((*aux).prox == NULL)
        return 0;

    return pos+1;
}

int size_lista(Lista *l)
{
    if(lista_vazia(*l) == 1)
        return 0;

    int pos=1;

    Lista aux = *l;

    while((*aux).prox != NULL)
    {
        aux = (*aux).prox;
        pos++;
    }

    return pos;
}


int get_matricula(Lista *l, int p, unsigned int *matri)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = *l;

    int pos=1;

    while((*aux).prox != NULL && pos < p)
    {
        aux = (*aux).prox ;
        pos++;
    }

    *matri = aux->aluno->matricula;

    return 1;
}

int get_nome(Lista *l, int p, char *name)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = *l;

    int pos=1;

    while((*aux).prox != NULL && pos < p)
    {
        aux = (*aux).prox ;
        pos++;
    }

    strcpy(name, aux->aluno->nome);

    return 1;
}

int get_media(Lista *l, int p, float *med)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = *l;

    int pos=1;

    while((*aux).prox != NULL && pos < p)
    {
        aux = (*aux).prox ;
        pos++;
    }

    *med = aux->aluno->media;

    return 1;
}

int get_faltas(Lista *l, int p, int *falta)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = *l;

    int pos=1;

    while((*aux).prox != NULL && pos < p)
    {
        aux = (*aux).prox ;
        pos++;
    }

    *falta = aux->aluno->faltas;

    return 1;
}

int limpa_lista(Lista *l)
{
    if(lista_vazia(*l) == 1)
        return 0;

    Lista aux = *l;

    int end;
    end = size_lista(&aux);

    unsigned int remover;

    for(int i=1; i <= end; i++)
    {
        get_matricula(&aux, i, &remover);
        remove_elem(&aux, remover);
    }
    (*l) = NULL;

    return 1;
}
