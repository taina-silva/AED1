#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lista.h"

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Criar lista (tecle 1):\n");
    printf("[2]. Inserir elemento na lista (tecle 2):\n");
    printf("[3]. Apagar elemento da lista (tecle 3):\n");
    printf("[4]. Imprimir lista (tecle 4):\n");
    printf("[5]. Limpar lista (tecle 5):\n");
    printf("[6]. Sair (tecle 6):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

void imprimir_lista(Lista lista)
{
    int f;
    get_fim(lista, &f);

    if(lista_vazia(lista) == 1 || f == 0)
    {
        printf("Lista vazia!\n\n");
    }else
    {
        int tipo, inteiro;
        char letra;

        printf("\nElementos da lista:\n\n");

        for(int i=1; i <= f; i++)
        {
            get_values(lista, i, &inteiro, &letra, &tipo);

            if(tipo == 0)
            {
                printf("\tNumero %d: %d\n", i, inteiro);

            }else if(tipo == 1)
            {
                setbuf(stdin, NULL);
                printf("\tLetra %d: %c\n", i, letra);
                setbuf(stdin, NULL);
            }
        }
    }
}

int main()
{
    Lista lista;
    int verifica = 0;

    int escolha = 0;

    int tipo, inteiro;
    char letra;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar lista\n\n");

                if(verifica == 0)
                {
                    lista = cria_lista();

                    if(lista != NULL)
                    {
                        printf("Falha na criacao da lista!\n\n");
                    }else
                    {
                        printf("Lista criada com sucesso!\n\n");
                    }
                }else
                {
                    printf("Lista ja criada\n\n!");
                }

                break;

            case 2:
                printf("\nOpcao 2 escolhida -  Inserir elemento na lista\n\n");

                printf("Digite o tipo de dado (0 - int ou 1 - char): ");
                scanf("%d", &tipo);

                if(tipo == 0)
                {
                    printf("\n\tNumero: ");
                    scanf("%d", &inteiro);
                    insere_elem(&lista, inteiro, letra, tipo);
                }else if(tipo == 1)
                {
                    setbuf(stdin, NULL);
                    printf("\n\tLetra: ");
                    scanf("%c", &letra);
                    insere_elem(&lista, inteiro, letra, tipo);
                    setbuf(stdin, NULL);
                }else
                {
                    printf("\n\tTipo invalido!\n");
                }

                break;

            case 3:
                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                printf("\nOpcao 3 escolhida - Apagar elemento da lista\n\n");

                printf("Digite o tipo de dado (0 - int ou 1 - char): ");
                scanf("%d", &tipo);

                if(tipo == 0)
                {
                    printf("\nNumero a ser removido: ");
                    scanf("%d", &inteiro);
                    if(remove_elem(&lista, inteiro, letra, tipo) == 0)
                    {
                        printf("Numero nao existe ou lista indisponivel!\n");
                    }else
                    {
                        printf("Primeira ocorrencia do numero removida com sucesso!\n");
                    }
                }else if(tipo == 1)
                {
                    setbuf(stdin, NULL);
                    printf("\nLetra a ser removida: ");
                    scanf("%c", &letra);
                    if(remove_elem(&lista, inteiro, letra, tipo) == 0)
                    {
                        printf("Letra nao existe ou lista indisponivel!\n");
                    }else
                    {
                        printf("Primeira ocorrencia da letra removida com sucesso!\n");
                    }
                }

                break;

            case 4:
                printf("\nOpcao 4 escolhida - Imprimir lista\n\n");
                imprimir_lista(lista);

                break;

            case 5:
                printf("\nOpcao 5 escolhida - Limpar lista\n\n");
                if(limpa_lista(&lista) == 0)
                {
                    printf("Falha!\n");
                }else
                {
                    printf("\nNao ha mais elementos na lista!!!\n");
                }

                break;

            case 6:
                printf("\nOpcao 6 escolhida - SAIR\n\n");
                liberar_lista(&lista);

                break;

            default:
                printf("\nOpcao Inexistente!!!\n");
                break;
        }

    }while(escolha!=6);

    return 0;
}
