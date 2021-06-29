#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#define MAXN 20
#define MAX 11

struct no
{
    int info;
    struct no * prox;
};
typedef struct no * Lista;

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
    {
        return 1; // Lista vazia
    }
    else
    {
        return 0; // Lista NÃO vazia
    }
}
int insere_ord (Lista *lst, int elem)
{
// Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0;    // Falha: nó não alocado
    }

    N->info = elem;


        if (lista_vazia(*lst) == 1 || elem <= (*lst)->info)
    {
        (*N).prox = *lst; // Aponta para o 1o nó atual da lista
        *lst = N; // Faz a lista apontar para o novo nó
        return 1;
    }
// Percorrimento da lista (elem > 1o nó da lista)
    Lista aux = *lst; // Faz aux apontar para 1o nó
    while (aux->prox != NULL && aux->prox->info < elem){
        aux = aux->prox; // Avança
    }
// Insere o novo elemento na lista
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remove_posicao(Lista *lst, int position)
{
    if (lista_vazia((*lst)) == 1)
    {
        return 0; // Falha
    }
    Lista aux = (*lst); // Ponteiro auxiliar para o 1o nó
    // Trata elemento = 1o nó da lista
    if (position == 1)
    {
        *lst = (*aux).prox; //lista aponta para segundo nó
        free(aux); //libera memória de aux
        return 1;
    }
    int pos = 2;

    // Percorrimento até achar o elem
    while(aux->prox != NULL && pos < position)
    {
        aux = (*aux).prox; //aux pega endereço de próxima região
        pos++;
    }
    if(aux->prox == NULL) //fim da lista
        return 0;

    Lista aux2 = (*aux).prox; //aponta nó a ser removido
    (*aux).prox = (*aux2).prox; //retira nó da lista, aponta para nó seguinte
    free(aux2); //libera memória aux

    return 1;//sucesso
}

int remove_ord(Lista *lst, int elem)
{
    if(lista_vazia(*lst) == 1 || elem < (*lst)->info)
    {
        return 0;
    }

    Lista aux = *lst; //ponteiro aux para primeiro nó

    //trata letra = primeiro nó da lista
    if(elem == (*lst)->info)
    {
        *lst = (*aux).prox; //lista aponta para segundo nó
        free(aux); //libera memória de aux

        return 1;
    }

    //percorre até fim da lista ou achar letra
    while((*aux).prox != NULL && aux->prox->info < elem)
    {
        aux = (*aux).prox; //aux pega endereço de próxima região
    }

    if((*aux).prox == NULL || aux->prox->info > elem) //fim da lista
        return 0;

    //remove letra diferente da do primeiro nó
    Lista aux2 = (*aux).prox; //aponta nó a ser removido
    (*aux).prox = (*aux2).prox; //retira nó da lista, aponta para nó seguinte
    free(aux2); //libera memória aux

    return 1;
}


int get_posicao(Lista lst, int elem)
{
    if (lista_vazia(lst) == 1)
    {
        return 0; // Falha
    }
    Lista aux = lst; // Ponteiro auxiliar para o 1o nó
// Trata elemento = 1o nó da lista
    if (elem == lst->info)
    {
        return 1;
    }
    int pos = 1;

    // Percorrimento até achar o elem
    while(aux->prox != NULL && aux->prox->info < elem)
    {
        aux = (*aux).prox; //aux pega endereço de próxima região
        pos++;
    }

    return pos+1;//sucesso
}

int get_element(Lista lst, int position)
{

    Lista aux = lst; // Ponteiro auxiliar para o 1o nó
    int pos = 0;

    while (aux->prox != NULL && pos < position)
    {
        aux = aux->prox;
        pos++;
    }

    return aux->info;
}

int get_end(Lista lst)
{
    if (lst == NULL || lista_vazia(lst) == 1)
    {
        return 0; // Falha
    }

    Lista aux = lst; // Ponteiro auxiliar para o 1o nó
    int pos = 0;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
        pos++;
    }

    return pos;
}

int limpa_lista(Lista *lst)
{
    int k = 0, i = 0;
    if (lista_vazia(*lst) == 1)
    {
        return 0; // Falha
    }
    else
    {
        k = get_end(*lst);
        while (i<=k)
        {
            remove_ord(&(*lst), get_element((*lst), i));
            i++;
        }
        (*lst) = NULL;
        return 1;
    }

}


