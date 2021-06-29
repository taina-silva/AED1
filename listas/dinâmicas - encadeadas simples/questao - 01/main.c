#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <locale.h>
#define MAXN 20
#define MAX 11


int main()
{
    setlocale(LC_ALL, "portuguese");

    Lista lst;
    int i = 0, j = 0, k =0, l = 0, m = 1, option = 0;

    lst = cria_lista();

    while(m == 1)
    {

        printf("\n[1] Inserir registro");
        printf("\n[2] Apagar um registro");
        printf("\n[3] Imprimir Lista");
        printf("\n[4] Limpar lista:  ");
        printf("\n[5] Obter posição:  ");
        printf("\n[6] Apagar um registro de uma posição");
        printf("\n[7] Sair:  ");

        scanf("%d", &option);

        if(option == 1)
        {

            printf("\nInsira um número na lista: ");
            scanf("%d", &i);
            insere_ord(&lst, i);
        }
        else if(option == 2)
        {
            printf("\nDigite o valor que você deseja excluir: ");
            scanf("%d", &i);
            k = remove_ord(&lst, i);
            if (k == 0)
            {
                printf("\n\nELEMENTO NÃO EXISTE!!\n\n");
            }
        }
        else if(option == 3)
        {
            k = get_end(lst);
            if (lst == NULL || lista_vazia(lst) == 1 || k < 0)
            {
                printf("\n\nLISTA VAZIA!!\n\n");
            }
            else
            {
                l = 0;
                while (l<=k)
                {
                    i = get_element(lst, l);
                    printf("\nNum [%d]: %d",l+1, i);
                    l++;
                }
            }

        }
        else if(option == 4)
        {

            if (lst == NULL || lista_vazia(lst) == 1)
            {
                printf("\n\nLISTA JÁ ESTÁ VAZIA!!\n\n");
            }
            else
            {
                limpa_lista(&lst);
            }

        }
        else if(option == 5)
        {

            if (lista_vazia(lst) == 1)
            {
                printf("\n\nLISTA JÁ ESTÁ VAZIA!!\n\n");
            }
            else
            {
                printf("\nDigite o valor que você deseja obter a posição: ");
                scanf("%d", &j);
                k = get_posicao(lst, j);
                printf("\n\nPosição %d", k);

            }

        }else if(option == 6)
        {
            printf("\nDigite a posição do elemento que deseja excluir: ");
            scanf("%d", &i);
            k = remove_posicao(&lst, i);
            if (k == 0)
            {
                printf("\n\nELEMENTO NÃO EXISTE!!\n\n");
            }
        }
        else if(option == 7)
        {
            return 0;
        }
        else
        {
            printf("OPÇÃO INVÁLIDA!!");
            return 0;
        }

        printf("\n\n");
    }

    return 0;
}
