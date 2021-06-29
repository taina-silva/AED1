#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "char.h"

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Inserir elementos na lista (tecle 1):\n");
    printf("[2]. Apagar elemento da lista (tecle 2):\n");
    printf("[3]. Imprimir lista (tecle 3):\n");
    printf("[4]. Limpar lista (tecle 4):\n");
    printf("[5]. Sair (tecle 5):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

/*void imprimir_lista(Lista l){

    int f;
    int numero;

    get_fim(&l, &f);

    printf("\nElementos da lista: ");

    for(int i=1; i < f; i++)
    {
        get_values(&l, &numero, i);
        printf("%d ", numero);
    }

    printf("\n");
}*/

int main()
{
    Lista lista;
    lista = cria_lista();

    //imprimir_lista(lista);
    printf("Ainda nao ha elementos na lista!!!\n\n");

    int escolha = 0;
    char letra, letra2;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Inserir elementos na lista\n\n");
                int qtdd;

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
                    setbuf(stdin, NULL);
                    scanf("%c", &letra);
                    insere_elem(&lista, letra);
                }
                break;

            case 2:
                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                printf("\nOpcao 2 escolhida - Apagar elemento da lista\n\n");

                printf("Elemento a ser removido: ");
                scanf("%c", &letra);

                if (remove_elem(&lista, &letra) == 0)
                {
                    printf("\nLista vazia ou elemento inexistente!!\n\n");
                }else
                {
                    printf("\nPrimeira ocorrencia do elemento removida com sucesso!\n");
                }
                break;

            case 3:
                printf("\nOpcao 3 escolhida - Imprimir lista\n\n");

                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                int f;

                get_fim(&lista, &f);

                printf("\nElementos da lista: ");

                for(int i=1; i <= f; i++)
                {
                    get_values(&lista, i, &letra2);
                    printf("%c ", letra2);
                }

                printf("\n");
                break;

            case 4:
                printf("\nOpcao 4 escolhida - Limpar lista\n\n");
                limpa_lista(&lista);

                printf("\nNao ha mais elementos na lista!!!\n");
                break;

            case 5:
                printf("\nOpcao 5 escolhida - SAIR\n\n");
                liberar_lista(&lista);
                break;

            default:
                printf("\nOpcao Inexistente!!!\n");
                break;
        }

    }while(escolha!=5);

    return 0;
}

