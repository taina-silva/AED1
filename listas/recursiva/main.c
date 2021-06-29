#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "recursiva.h"

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Criar lista (tecle 1):\n");
    printf("[2]. Inserir elementos na lista (tecle 2):\n");
    printf("[3]. Apagar elemento da lista (tecle 3):\n");
    printf("[4]. Imprimir lista (tecle 4):\n");
    printf("[5]. Limpar lista (tecle 5):\n");
    printf("[6]. Sair (tecle 6):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista lista;

    int escolha = 0;
    double numero;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOp��o 1 escolhida -  Inserir elementos na lista\n\n");
                lista = cria_lista(&lista);
                if(lista == NULL)
                {
                    printf("Lista criada com sucesso!\n");
                    break;
                }else
                {
                    printf("Falha ao criar a lista!\n");
                    break;
                }

            case 2:
                printf("\nOp��o 2 escolhida -  Inserir elementos na lista\n\n");
                int qtdd;

                printf("Quantidade de elementos a serem inseridos na lista: ");
                scanf("%d", &qtdd);

                while(qtdd<0)
                {
                    printf("\nQuantidade inv�lida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira os elementos na lista:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    printf("    Elemento %d: ", i+1);
                    scanf("%lf", &numero);
                    insere_ord(&lista, numero);
                }
                break;

            case 3:
                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                printf("\nOp��o 3 escolhida - Apagar elemento da lista\n\n");
                printf("    1. Remo��o no in�cio da lista (tecle 1):\n");
                printf("    2. Remo��o por elemento espec�fico (tecle 2):\n");

                int choice;
                scanf("%d", &choice);

                if(choice==2)
                {
                    printf("Elemento a ser removido: ");
                    double remove;
                    scanf("%lf", &remove);

                    if (remove_ord(&lista, remove) == 0)
                    {
                        printf("\nLista vazia ou elemento inexistente!!\n\n");
                    }else
                    {
                        printf("\nPrimeira ocorr�ncia do elemento removida com sucesso!\n");
                    }
                    break;

                }else if(choice==1)
                {
                    if (remove_inicio (&lista, &numero) == 0)
                    {
                        printf("\nLista vazia ou elemento inexistente!!\n\n");
                    }else
                    {
                        printf("\nElemento removido: %.2lf\n", numero);
                    }
                    break;
                }

            case 4:
                printf("\nOp��o 4 escolhida - Imprimir lista\n\n");

                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                int f;
                double num;

                f = get_end(lista);

                printf("\nElementos da lista: ");

                for(int i=0; i <= f; i++)
                {
                    num = obtem_elem(lista, i);
                    printf("%.2lf ", num);
                }

                printf("\n");
                break;

            case 5:
                printf("\nOp��o 5 escolhida - Limpar lista\n\n");
                limpa_lista(&lista);

                printf("\nN�o h� mais elementos na lista!!!\n");
                break;

            case 6:
                printf("\nOp��o 6 escolhida - SAIR\n\n");
                limpa_lista(&lista);
                break;

            default:
                printf("\nOp��o Inexistente!!!\n");
                break;
        }

    }while(escolha!=6);

    return 0;
}
