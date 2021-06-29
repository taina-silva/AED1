#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "pilha.h"

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Criar pilha (tecle 1):\n");
    printf("[2]. Empilhar (tecle 2):\n");
    printf("[3]. Desempilhar (tecle 3):\n");
    printf("[4]. Imprimir pilha (tecle 4):\n");
    printf("[5]. Topo da pilha (tecle 5):\n");
    printf("[6]. Limpar pilha (tecle 6):\n");
    printf("[7]. Sair (tecle 7):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

void imprimir_pilha(Pilha p)
{
    int tam;
    int valor;

    tam_pilha(p, &tam);

    Pilha aux = cria_pilha();

    printf("\nElementos da pilha: ");

    for(int i=0; i < tam; i++)
    {
        pop(p, &valor);
        push(aux, valor);
    }

    for(int i=0; i < tam; i++)
    {
        pop(aux, &valor);
        printf("%d ", valor);
        push(p, valor);
    }

    printf("\n");
}

int main()
{
    Pilha pilha;

    int escolha = 0;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar pilha\n\n");

                pilha = cria_pilha();

                if(pilha == NULL)
                {
                    printf("Falha na alocacao!\n\n");
                    break;
                }else
                {
                    printf("Pilha criada com sucesso!\n\n");
                }

                break;

            case 2:
                if(pilha_cheia(pilha)==1)
                {
                    printf("\nPilha cheia!\n\n");
                    break;
                }

                printf("\nOpcao 2 escolhida -  Empilhar\n\n");

                int qtdd;
                int elemento;

                printf("Quantidade inicial de elementos a serem inseridos na pilha (maximo = 20): ");
                scanf("%d", &qtdd);

                while(qtdd<0 || qtdd>20)
                {
                    printf("\nQuantidade invalida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira os elementos na pilha:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    if(pilha_cheia(pilha)==1)
                    {
                        printf("\nPilha cheia!\n\n");
                        break;
                    }

                    printf("    Elemento %d: ", i+1);
                    scanf("%d", &elemento);
                    push(pilha, elemento);
                }
                break;

            case 3:
                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }
                printf("\nOpcao 3 escolhida - Desempilhar\n\n");

                int r;
                if (pop(pilha, &r) == 0)
                {
                    printf("\nPilha vazia ou elemento inexistente!!\n\n");
                }else
                {
                    printf("Elemento removido: %d\n", r);
                }
                break;

            case 4:
                printf("\nOpcao 4 escolhida - Imprimir pilha\n\n");

                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }

                imprimir_pilha(pilha);
                break;

            case 5:
                printf("\nOpcao 5 escolhida - Topo da pilha\n\n");

                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }

                int topo;
                le_topo(pilha, &topo);

                printf("Elemento no topo da pilha: %d\n", topo);

                break;

            case 6:
                printf("\nOpcao 6 escolhida - Limpar pilha\n\n");

                if(limpa_pilha(pilha) == 0)
                {
                    printf("\nPilha ja vazia ou inexistente!\n");
                    break;
                }else
                {
                    printf("\nNao ha mais elementos na pilha!\n");
                    imprimir_pilha(pilha);
                }

                break;

            case 7:
                printf("\nOpcao 7 escolhida - SAIR\n\n");
                break;

            default:
                printf("\nOpcao Inexistente!!!\n");
                break;
        }

    }while(escolha!=7);

    return 0;
}
