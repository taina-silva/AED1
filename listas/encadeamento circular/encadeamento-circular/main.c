#include <stdio.h>
#include <stdlib.h>

#include "circular.h"

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Criar lista (tecle 1):\n");
    printf("[2]. Inserir elementos na lista (tecle 2):\n");
    printf("[3]. Apagar elemento da lista (tecle 3):\n");
    printf("[4]. Posicao de elemento da lista (tecle 4):\n");
    printf("[5]. Imprimir lista (tecle 4):\n");
    printf("[6]. Limpar lista (tecle 5):\n");
    printf("[7]. Sair (tecle 6):\n\n");

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
                if(lista == NULL)
                {
                    printf("Lista criada com sucesso!\n");
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
                    insere_final(&lista, num);
                }
                break;

            case 3:
                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                printf("\nOpcao 3 escolhida - Apagar elemento da lista\n\n");
                printf("\nRemover elemento do inicio da lista (tecle 1) ou remover elemento especifico (tecle 2): ");
                int choice;
                scanf("%d", &choice);

                while(choice != 1 && choice != 2)
                {
                    printf("Numero invalido, digite novamente!\n");
                    scanf("%d", &choice);
                }

                if(choice == 1)
                {
                    int elemento;
                    remove_inicio(&lista, &elemento);
                    printf("\nElemento removido: %d\n\n", elemento);
                    break;

                }else if(choice == 2)
                {
                    int num2;
                    printf("Elemento a ser removido: ");
                    scanf("%d", &num2);

                    if (remove_elem(&lista, num2) == 0)
                    {
                        printf("\nLista vazia ou elemento inexistente!!\n\n");
                    }else
                    {
                        printf("\nPrimeira ocorrencia do elemento removida com sucesso!\n");
                    }
                    break;
                }

            case 4:
                printf("\nOpcao 4 escolhida - Posicao de elemento da lista\n\n");
                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                printf("Elemento para pegar sua posicao: ");
                int elem, pos;
                scanf("%d", &elem);
                pos = get_posicao(lista, elem);

                if(pos != 0)
                {
                    printf("\nPosicao do elemento %d: %d\n", elem, pos);
                    break;
                }else
                {
                    printf("\nElemento inxistente!\n");
                    break;
                }

            case 5:
                printf("\nOpcao 5 escolhida - Imprimir lista\n\n");

                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                int f;
                int numero;

                get_fim(&lista, &f);

                printf("\nElementos da lista: ");

                for(int i=0; i < f; i++)
                {
                    get_values(&lista, &numero, i);
                    printf("%d ", numero);
                }

                printf("\n");
                break;

            case 6:
                printf("\nOpcao 6 escolhida - Limpar lista\n\n");
                if(limpa_lista(&lista) == 1)
                {
                    printf("Nao ha mais elementos na lista!\n");
                }else
                {
                    printf("Falha ao limpar lista!\n");
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

