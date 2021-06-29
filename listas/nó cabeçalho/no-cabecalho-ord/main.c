#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "no.h"

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
    Lista lista;

    int escolha = 0;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar lista\n\n");
                lista = cria_lista();
                if(lista != NULL)
                {
                    printf("\nLista criada com sucesso!\n");
                }
                break;

            case 2:
                printf("\nOpcao 2 escolhida -  Inserir elementos na lista\n\n");
                int qtdd;
                int num;

                printf("Quantidade de elementos a serem inseridos na lista: ");
                scanf("%d", &qtdd);

                while(qtdd<0)
                {
                    printf("\nQuantidade invalida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira os elementos na lista:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    printf("    Elemento %d: ", i+1);
                    scanf("%d", &num);
                    insere_ord(&lista, num);
                }
                break;

            case 3:
                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                printf("\nOpcao 3 escolhida - Apagar elemento da lista\n\n");
                int num2;

                printf("Elemento a ser removido: ");
                scanf("%d", &num2);

                if (remove_ord (&lista, num2) == 0)
                {
                    printf("\nLista vazia ou elemento inexistente!!\n\n");
                }else
                {
                    printf("\nPrimeira ocorrencia do elemento removida com sucesso!\n");
                }
                break;

            case 4:
                printf("\nOpcao 4 escolhida - Imprimir lista\n\n");

                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                int f;
                int numero;

                get_fim(&lista, &f);

                printf("\nElementos da lista: ");

                for(int i=1; i <= f; i++)
                {
                    get_values(lista, &numero, i);
                    printf("%d ", numero);
                }

                printf("\n");
                break;

            case 5:
                printf("\nOpcao 5 escolhida - Limpar lista\n\n");
                if(limpa_lista(&lista) == 1)
                {
                    printf("\nNao ha mais elementos na lista!\n");
                }else
                {
                    printf("\nFalha ao limpar lista!\n");
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

    return 0;
}
