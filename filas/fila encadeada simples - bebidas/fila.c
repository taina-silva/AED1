#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#define MAX 50

struct investimentos
{
    int codigo;
    double valor;
    float per;
};
typedef struct investimentos I;

struct no
{
    I info;
    struct no *prox;
};
typedef struct no *No;

struct fila
{
    struct no *ini; //guarda endereço de estrutura nó (primeiro)
    struct no *fim; //guarda endereço de estrutura nó (último)
};
typedef struct fila *Fila; //endereço de estrutura fila

Fila cria_fila()
{
    Fila f;
    f = (Fila)malloc(sizeof(struct fila)); //aloca estrutura tipo fila

    if(f == NULL)
    {
        return 0;
    }

    //campos ini e fim da fila apontam pra null
    f->ini = NULL;
    f->fim = NULL;

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

int insere_fim(Fila f, Bebida bebida)
{
    if(f == NULL) //fila inválida
    {
        return 0;
    }

    No N; //aloca ponteiro pra nó
    N = (No)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = bebida;
    N->prox = NULL;//último nó da fila

    if(fila_vazia(f)==1)
    {
        f->ini = N; //campo ini aponta para novo nó
    }else
    {
        f->fim->prox = N; //último nó da fila aponta para novo nó
    }

    f->fim = N; //N é o último nó (apontado pelo campo fim)

    return 1;
}

int remove_ini(Fila f, Bebida *bebida)
{
    if(fila_vazia(f)==1)
    {
        return 0;
    }

    No aux = f->ini; //ponteiro aux recebe endereço primeiro nó da fila
    *bebida = aux->info; //retorna valor elemento removido

    //verifica se fila tem único nó - ini e fim apontam para mesmo nó
    if(f->ini == f->fim)
    {
        f->fim = NULL;
    }

    f->ini = aux->prox; //retira primeiro nó da fila
    free(aux); //libera memória alocada

    return 1;
}

void tam_fila(Fila f, int *tam)
{
    if(fila_vazia(f) == 1)
    {
        *tam = 0;
    }

    No aux = f->ini;
    int cont = 1;

    while(aux->prox != NULL)
    {
        cont++;
        aux = aux->prox;
    }

    *tam = cont;
}

int esvazia_fila(Fila f)
{
    if(fila_vazia(f)==1)
        return 0;

    No aux = f->ini;

    while(aux->prox != NULL)
    {
        aux = aux->prox;
        f->ini = aux->prox;
        free(aux);
    }

    return 1;
}

void apaga_fila(Fila *f)
{
    free(*f);
    *f = NULL;
}



int elimina_elem(Fila f, float per)
{
	Fila aux = cria_fila();
}























int elimina_elem(Fila f, float per)
{
    Fila aux = cria_fila();

    if(aux == NULL)
    {
	printf("Falha!"); 
        return 0;
    }

    double soma = 0;

    while(fila_vazia(f) == 0)
    {
	I investe;
	if(remove_ini(fila, &investe)==0)
	{
		printf("Falha!"); 
		return 0;
	}

        if(investe.per < per)
	{
		soma = soma + investe.valor;
	}else 
	{
		if(insere_fim(aux, b)==0)
		{
			printf("Falha!"); 
			return 0;
		}
	}
    }

	printf("Valor resgatado: %.2f", soma); 
	
	while(fila_vazia(aux) == 0)
    	{
        	I investe;
        	if(remove_ini(aux, &investe)==1)
		{
			if(insere_fim(fila, investe)==0)
			{
				printf("Falha!"); 
				return 0;
			}
		}else
		{
			printf("Falha!"); 
			return 0;
		}
   	 }

    	return 1;
}
