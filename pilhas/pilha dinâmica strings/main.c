#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "pilha.h"

#define MAX 20

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
    printf("[6]. Tamanho da pilha (tecle 5):\n");
    printf("[7]. Limpar pilha (tecle 6):\n");
    printf("[8]. Sair (tecle 7):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

void imprimir_pilha(Pilha p)
{
    int tam;
    char name[MAX];

    tam_pilha(p, &tam);

    Pilha aux = cria_pilha();

    printf("\nStrings da pilha: ");

    for(int i=0; i < tam; i++)
    {
        pop(&p, name);
        push(&aux, name);
    }

    for(int i=0; i < tam; i++)
    {
        pop(&aux, name);
        printf("%s ", name);
        push(&p, name);
    }

    printf("\n");
}

int main()
{
    Pilha pilha;
    char nome[MAX];

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
                    printf("Pilha criada com sucesso!\n\n");
                    break;
                }
                printf("Falha na alocacao!\n\n");

                break;

            case 2:

                printf("\nOpcao 2 escolhida -  Empilhar\n\n");

                int qtdd;

                printf("Quantidade inicial de strings a serem inseridas na pilha: ");
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
                    printf("    String %d: ", i+1);
                    scanf("%s", nome);
                    push(&pilha, nome);
                }
                break;

            case 3:
                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }
                printf("\nOpcao 3 escolhida - Desempilhar\n\n");

                if (pop(&pilha, nome) == 0)
                {
                    printf("\nPilha vazia ou string inexistente!!\n\n");
                }else
                {
                    printf("String removida: %s\n", nome);
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

                get_topo(&pilha, nome);

                printf("String no topo da pilha: %s\n", nome);

                break;

            case 6:
                printf("\nOpcao 6 escolhida - Tamanho da pilha\n\n");

                int tam;
                tam_pilha(pilha, &tam);
                printf("Tamanho da pilha = %d\n", tam);

                break;

            case 7:
                printf("\nOpcao 7 escolhida - Limpar pilha\n\n");

                if(limpa_pilha(&pilha) == 0)
                {
                    printf("\nPilha ja vazia ou inexistente!\n");
                    break;
                }else
                {
                    printf("\nNao ha mais elementos na pilha!\n");
                }

                break;

            case 8:
                printf("\nOpcao 8 escolhida - SAIR\n\n");
                libera_pilha(pilha);
                break;

            default:
                printf("\nOpcao Inexistente!!!\n");
                break;
        }

    }while(escolha!=8);

    return 0;
}
