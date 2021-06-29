#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fila.h"

#define MAX 50

struct bebidas
{
    char nome[MAX];
    float volume;
    float preco;
};
typedef struct bebidas Bebida;

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Criar fila (tecle 1):\n");
    printf("[2]. Inserir bebidas na fila (tecle 2):\n");
    printf("[3]. Remover bebida da fila (tecle 3):\n");
    printf("[4]. Imprimir fila (tecle 4):\n");
    printf("[5]. Limpar fila (tecle 5):\n");
    printf("[6]. Sair (tecle 6):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

void imprimir_fila(Fila fila)
{
    int i=1;
    Fila aux = cria_fila();

    printf("Bebida:\n\n");
    while(fila_vazia(fila) == 0)
    {
        Bebida b;
        remove_ini(fila, &b);
        printf("Bebida %d:\n", i);
        printf("Nome: %s\n", b.nome);
        printf("Volume: %.2fl\n", b.volume);
        printf("Preco: R$%.2f\n", b.preco);
        printf("\n");
        insere_fim(aux, b);
        fila_vazia(fila);
        i++;
    }

    while(fila_vazia(aux) == 0)
    {
        Bebida b;
        remove_ini(aux, &b);
        insere_fim(fila,b);
        fila_vazia(aux);
    }

    printf("\n");
}

int main()
{
    Fila fila;

    int escolha = 0;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar fila\n\n");

                fila = cria_fila();

                if(fila == NULL)
                {
                    printf("Falha na alocacao!\n\n");
                    break;
                }else
                {
                    printf("Fila criada com sucesso!\n\n");
                }

                break;

            case 2:
                printf("\nOpcao 2 escolhida -  Inserir bebidas na fila\n\n");

                int qtdd;
                Bebida inserir;

                printf("Quantidade de bebidas a serem inseridas na fila (maximo = 20): ");
                scanf("%d", &qtdd);

                while(qtdd<0 || qtdd>20)
                {
                    printf("\nQuantidade invalida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira as bebidas na fila:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    setbuf(stdin, NULL);
                    printf("\tBebida %d:\n", i+1);
                    printf("\tNome: ");
                    scanf("%s", inserir.nome);
                    printf("\tVolume: ");
                    scanf("%f", &inserir.volume);
                    printf("\tPreco: ");
                    scanf("%f", &inserir.preco);
                    insere_fim(fila, inserir);
                    printf("\n");
                }
                break;

            case 3:
                if(fila_vazia(fila)==1)
                {
                    printf("Fila  vazia!\n\n");
                    break;
                }
                printf("\nOpcao 3 escolhida - Remover bebida da fila\n\n");

                Bebida remover;
                if (remove_ini(fila, &remover) == 0)
                {
                    printf("\nFila  vazia ou elemento inexistente!!\n\n");
                }else
                {
                    printf("Bebida removida:\n");
                    printf("Nome: %s\n", remover.nome);
                    printf("Volume: %.2fl\n", remover.volume);
                    printf("Preco: R$%.2f\n", remover.preco);
                }
                break;

            case 4:
                printf("\nOpcao 4 escolhida - Imprimir fila\n\n");

                if(fila_vazia(fila)==1)
                {
                    printf("Fila vazia!\n\n");
                    break;
                }

                imprimir_fila(fila);

                break;

            case 5:
                printf("\nOpcao 5 escolhida - Limpar fila\n\n");

                if(esvazia_fila(fila) == 0)
                {
                    printf("\nFila ja vazia ou inexistente!\n");
                    break;
                }else
                {
                    printf("\nNao ha mais bebidas na fila !\n");
                }

                break;

            case 6:
                printf("\nOpcao 6 escolhida - SAIR\n\n");
                break;

            default:
                printf("\nOpcao Inexistente!!!\n");
                break;
        }

    }while(escolha!=6);

    apaga_fila(&fila);

    return 0;
}
