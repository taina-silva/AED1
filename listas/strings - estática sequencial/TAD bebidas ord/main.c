#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bebidas-ord.h"

#define MAX 11

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Inserir bebidas na lista (tecle 1):\n");
    printf("[2]. Apagar bebida da lista (tecle 2):\n");
    printf("[3]. Imprimir lista de bebidas (tecle 3):\n");
    printf("[4]. Apagar lista de bebidas (tecle 4):\n");
    printf("[5]. Sair (tecle 5):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

void imprimir_lista(Lista l){
    int p;
    char pal[MAX];
    int v;
    float pre;
    get_fim (l, &p);

    printf("\nBebidas da lista:\n");
    for(int i=0; i < p; i++)
    {
        get_nome(l, i, pal);
        get_volume(l, i, &v);
        get_preco(l, i, &pre);
        printf("\n    Bebida %d: %s\n", i+1, pal);
        printf("    Volume: %dml\n", v);
        printf("    Preco: R$%.2f\n", pre);
    }

    printf("\n");
}

int main(){
    Lista lista;
    lista = cria_lista();

    if(lista == NULL)
    {
        printf("Falha na alocação!\n\n");
        return 0;
    }

    imprimir_lista(lista);
    printf("Ainda nao ha bebidas na lista!!!\n\n");

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

                printf("\nOpcao 1 escolhida -  Inserir bebidas na lista\n\n");
                int qtdd;
                char word[MAX];
                int vol;
                float preco;

                printf("Quantidade inicial de bebidas a serem inseridas na lista (maximo = 20): ");
                scanf("%d", &qtdd);

                while(qtdd<0 || qtdd>20)
                {
                    printf("\nQuantidade invalida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira as bebidas na lista:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    if(lista_cheia(lista)==1)
                    {
                        printf("\nLista cheia!\n\n");
                        break;
                    }

                    printf("    Bebida %d: ", i+1);
                    printf("\n        Nome: ");
                    scanf("%s", word);
                    printf("        Volume: ");
                    scanf("%d", &vol);
                    while(vol < 0)
                    {
                        printf("\nVolume invalido, digite novamente: ");
                        scanf("%d", &vol);
                    }
                    printf("        Preco: ");
                    scanf("%f", &preco);
                    while(preco < 0)
                    {
                        printf("\nPreco invalido, digite novamente: ");
                        scanf("%f", &preco);
                    }
                    insere_ord(lista, word, vol, preco);
                }
                break;

            case 2:
                if(lista_vazia(lista)==1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }
                printf("\nOpcao 2 escolhida - Apagar bebida da lista\n\n");
                char word2[MAX];
                printf("Elemento a ser removido: ");
                scanf("%s", word2);
                if (remove_ord (lista, word2) == 0)
                {
                    printf("\nLista vazia ou bebida inexistente!!\n\n");
                }else
                {
                    printf("\nPrimeira ocorrencia da bebida removida com sucesso!\n");
                }
                break;

            case 3:
                printf("\nOpcao 3 escolhida - Imprimir lista\n\n");
                imprimir_lista(lista);
                break;

            case 4:
                printf("\nOpcao 4 escolhida - Apagar lista de bebidas\n\n");
                limpa_lista (lista);
                imprimir_lista(lista);
                printf("\nNao ha mais bebidas na lista!!!\n");
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
