#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fila.h"

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Criar fila (tecle 1):\n");
    printf("[2]. Inserir elementos na fila (tecle 2):\n");
    printf("[3]. Remover elemento da fila (tecle 3):\n");
    printf("[4]. Imprimir fila  (tecle 4):\n");
    printf("[5]. Limpar fila (tecle 5):\n");
    printf("[6]. Sair (tecle 6):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

/*void imprimir_fila(Fila f)
{
    int tam;
    int elemento;
    tam_fila(f, &tam);

    printf("\nElementos da fila: ");
    for(int i=0; i < tam; i++)
    {
        get_values(f, i, &elemento);
        printf("%d ", elemento);
    }

    printf("\n");
}*/

void imprimir_fila(Fila fila)
{
    int i=1;
    Fila aux = cria_fila();

    printf("Elementos da fila:\n\n");
    while(fila_vazia(fila) == 0)
    {
        int elem;
        remove_ini(fila, &elem);
        printf("\tElemento %d: %d\n", i, elem);
        insere_fim(aux, elem);
        fila_vazia(fila);
        i++;
    }

    while(fila_vazia(aux) == 0)
    {
        int elem;
        remove_ini(aux, &elem);
        insere_fim(fila,elem);
        fila_vazia(aux);
        i++;
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
                printf("\nOpcao 2 escolhida -  Inserir elementos na fila\n\n");

                int qtdd;
                int elemento;

                printf("Quantidade de elementos a serem inseridos na fila (maximo = 20): ");
                scanf("%d", &qtdd);

                while(qtdd<0 || qtdd>20)
                {
                    printf("\nQuantidade invalida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira os elementos na fila:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    setbuf(stdin, NULL);
                    printf("    Elemento %d: ", i+1);
                    scanf("%d", &elemento);
                    insere_fim(fila, elemento);
                }
                break;

            case 3:
                if(fila_vazia(fila)==1)
                {
                    printf("Fila  vazia!\n\n");
                    break;
                }
                printf("\nOpcao 3 escolhida - Remover elemento da fila\n\n");

                int remover;
                if (remove_ini(fila, &remover) == 0)
                {
                    printf("\nFila  vazia ou elemento inexistente!!\n\n");
                }else
                {
                    printf("Elemento removido: %d\n", remover);
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
                    printf("\nNao ha mais elementos na fila !\n");
                }

                break;

            case 6:
                printf("\nOpcao 6 escolhida - SAIR\n\n");
                apaga_fila(&fila);
                break;

            default:
                printf("\nOpcao Inexistente!!!\n");
                break;
        }

    }while(escolha!=6);

    return 0;
}
