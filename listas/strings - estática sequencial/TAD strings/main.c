#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "n-ord.h"

#define MAX 11

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Inserir elementos na lista (tecle 1):\n");
    printf("[2]. Apagar elemento da lista (tecle 2):\n");
    printf("[3]. Imprimir lista (tecle 3):\n");
    printf("[4]. Apagar lista (tecle 4):\n");
    printf("[5]. Sair (tecle 5):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

void imprimir_lista(Lista l){
    int p;
    char pal[MAX];
    get_fim (l, &p);

    printf("\nElementos da lista: ");
    for(int i=0; i < p; i++)
    {
        get_values(l, i, pal);
        printf("%s ", pal);
    }

    printf("\n");
}

int main(){
    Lista lista;
    lista = cria_lista();

    if(lista == NULL)
    {
        printf("Falha na aloca��o!\n\n");
        return 0;
    }

    imprimir_lista(lista);
    printf("Ainda nao ha elementos na lista!!!\n\n");

    int escolha = 0;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                if(lista_cheia(lista)==1)
                {
                    printf("\nLista cheia!\n\n");
                    break;
                }

                printf("\nOpcao 1 escolhida -  Inserir elementos na lista\n\n");
                int qtdd;
                char word[MAX];

                printf("Quantidade inicial de elementos a serem inseridos na lista (maximo = 20): ");
                scanf("%d", &qtdd);

                while(qtdd<0 || qtdd>20)
                {
                    printf("\nQuantidade invalida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira os elementos na lista:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    if(lista_cheia(lista)==1)
                    {
                        printf("\nLista cheia!\n\n");
                        break;
                    }

                    printf("    Elemento %d: ", i+1);
                    scanf("%s", word);
                    insere_elem(lista, word);
                }
                break;

            case 2:
                if(lista_vazia(lista)==1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }
                printf("\nOpcao 2 escolhida - Apagar elemento da lista\n\n");
                char word2[MAX];
                printf("Elemento a ser removido: ");
                scanf("%s", word2);
                if (remove_elem (lista, word2) == 0)
                {
                    printf("\nLista vazia ou elemento inexistente!!\n\n");
                }else
                {
                    printf("\nPrimeira ocorrencia do elemento removida com sucesso!\n");
                }
                break;

            case 3:
                printf("\nOpcao 3 escolhida - Imprimir lista\n\n");
                imprimir_lista(lista);
                break;

            case 4:
                printf("\nOpcao 4 escolhida - Apagar lista\n\n");
                limpa_lista (lista);
                imprimir_lista(lista);
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
