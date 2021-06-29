#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "deque.h"

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Criar deque (tecle 1):\n");
    printf("[2]. Inserir elementos no deque (tecle 2):\n");
    printf("[3]. Remover elemento do deque (tecle 3):\n");
    printf("[4]. Imprimir deque  (tecle 4):\n");
    printf("[5]. Limpar deque (tecle 5):\n");
    printf("[6]. Sair (tecle 6):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

void imprimir_deque(Deque deque)
{
    Deque aux = cria_deque();

    int i=1;

    printf("Elementos do deque:\n\n");
    while(deque_vazio(deque) == 0)
    {
        int elem;
        remove_ini(deque, &elem);
        printf("\tElemento %d: %d\n", i, elem);
        insere_fim(aux, elem);
        deque_vazio(deque);
        i++;
    }

    while(deque_vazio(aux) == 0)
    {
        int elem;
        remove_ini(aux, &elem);
        insere_fim(deque,elem);
        deque_vazio(aux);
    }

    printf("\n");
}

int main()
{
    Deque deque;

    int escolha = 0;
    int choice = 0;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar deque\n\n");

                deque = cria_deque();

                if(deque == NULL)
                {
                    printf("Falha na alocacao!\n\n");
                    break;
                }else
                {
                    printf("Deque criado com sucesso!\n\n");
                }

                break;

            case 2:
                if(deque_cheio(deque)==1)
                {
                    printf("\nDeque cheia!\n\n");
                    break;
                }

                printf("\nOpcao 2 escolhida -  Inserir elementos no deque\n\n");

                int qtdd, elemento;
                printf("Inserir no inicio (tecle 1) ou no final (tecle 2): ");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("Quantidade de elementos a serem inseridos no deque (maximo = 20): ");
                    scanf("%d", &qtdd);

                    while(qtdd<0 || qtdd>20)
                    {
                        printf("\nQuantidade invalida!\n");
                        printf("\nDigite novamente: ");
                        scanf("%d", &qtdd);
                    }

                    printf("\nInsira os elementos no deque:\n\n");

                    for(int i=0; i<qtdd; i++)
                    {
                        if(deque_cheio(deque)==1)
                        {
                            printf("\nDeque cheio!\n\n");
                            break;
                        }

                        printf("    Elemento %d: ", i+1);
                        scanf("%d", &elemento);
                        insere_inicio(deque, elemento);
                    }

                }else if(choice == 2)
                {
                    printf("Quantidade de elementos a serem inseridos no deque (maximo = 20): ");
                    scanf("%d", &qtdd);

                    while(qtdd<0 || qtdd>20)
                    {
                        printf("\nQuantidade invalida!\n");
                        printf("\nDigite novamente: ");
                        scanf("%d", &qtdd);
                    }

                    printf("\nInsira os elementos no deque:\n\n");

                    for(int i=0; i<qtdd; i++)
                    {
                        if(deque_cheio(deque)==1)
                        {
                            printf("\nDeque cheio!\n\n");
                            break;
                        }

                        printf("    Elemento %d: ", i+1);
                        scanf("%d", &elemento);
                        insere_fim(deque, elemento);
                    }
                }else
                {
                    printf("Numero invalido!\n");
                }

                break;

            case 3:
                if(deque_vazio(deque)==1)
                {
                    printf("Deque vazio!\n\n");
                    break;
                }
                printf("\nOpcao 3 escolhida - Remover elemento do deque\n\n");

                printf("Remove no inicio (tecle 1) ou no final (tecle 2): ");
                scanf("%d", &choice);

                int remover;
                if(choice == 1)
                {
                    if (remove_ini(deque, &remover) == 0)
                    {
                        printf("\nDeque vazio ou elemento inexistente!!\n\n");
                    }else
                    {
                        printf("Elemento removido: %d\n", remover);
                    }
                }else if(choice == 2)
                {
                    if (remove_fim(deque, &remover) == 0)
                    {
                        printf("\nDeque vazio ou elemento inexistente!!\n\n");
                    }else
                    {
                        printf("Elemento removido: %d\n", remover);
                    }
                }else
                {
                    printf("Numero invalido!\n");
                }

                break;

            case 4:
                printf("\nOpcao 4 escolhida - Imprimir deque\n\n");

                if(deque_vazio(deque)==1)
                {
                    printf("Deque vazio!\n\n");
                    break;
                }

                imprimir_deque(deque);
                break;

            case 5:
                printf("\nOpcao 5 escolhida - Limpar deque\n\n");

                if(limpa_deque(deque) == 0)
                {
                    printf("\nDeque ja vazia ou inexistente!\n");
                    break;
                }else
                {
                    printf("\nNao ha mais elementos no deque !\n");
                }

                break;

            case 6:
                printf("\nOpcao 6 escolhida - SAIR\n\n");
                liberar(&deque);

                break;

            default:
                printf("\nOpcao Inexistente!!!\n");
                break;
        }

    }while(escolha!=6);

    return 0;
}
