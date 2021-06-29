#include <stdio.h>
#include <locale.h>
#include <string.h>
#define MAX 20
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

void imprimir_deque(Deque f)
{
    if(deque_vazio(f) == 1 || f == NULL){
        printf("\nDeque vazio!\n");
        return;
    }

    Deque aux = cria_deque();

    int i=1;

    printf("Elementos do deque:\n\n");
    while(deque_vazio(f) == 0)
    {
        int elem;
        remove_ini(f, &elem);
        printf("\tElemento %d: %d\n", i, elem);
        insere_fim(aux, elem);
        i++;
    }

    while(deque_vazio(aux) == 0)
    {
        int elem;
        remove_ini(aux, &elem);
        insere_fim(f,elem);
    }

    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Deque deque;
    int verifica = 0;

    int escolha = 0;

    do{
        escolha = Opcoes();
        switch(escolha)
        {
            case 1:
            {
                printf("\nOpcao 1 escolhida -  Criar deque\n\n");

                if(verifica == 0)
                {
                    deque = cria_deque();

                    if(deque == NULL)
                    {
                        printf("Falha ao criar deque!\n\n");
                    }else
                    {
                        printf("Deque criado com sucesso!\n\n");
                        verifica = 1;
                    }
                }else
                {
                    printf("Deque ja criado!\n\n");
                }

                break;
            };

            case 2:
            {
                int opcao = 0;

                do{
                    printf("Inserir no inicio [1] ou no final [2]: ");
                    scanf("%d", &opcao);
                }while(opcao < 1 || opcao > 2);

                if(opcao == 1)
                {
                    int qtdd;
                    printf("\nQuantidade de elemento a serem inseridos: ");
                    scanf("%d", &qtdd);

                    for(int i=0; i<qtdd; i++)
                    {
                        int num;
                        printf("\nInsira número: ");
                        scanf(" %d", &num);

                        if (insere_inicio(deque, num)==0)
                            printf("\nDeque cheio!\n");
                    }

                    printf("\n");
                }
                if(opcao == 2)
                {
                    int qtdd;
                    printf("\nQuantidade de elemento a serem inseridos: ");
                    scanf("%d", &qtdd);

                    for(int i=0; i<qtdd; i++)
                    {
                        int num;
                        printf("\nInsira número: ");
                        scanf(" %d", &num);

                        if (insere_fim(deque, num)==0)
                            printf("\nDeque cheio!\n");
                    }

                    printf("\n");
                }

                break;
            }

            case 3:{
                int opcao = 0;
                do{
                    printf("Remover no inicio [1] ou no fim [2]: ");
                    scanf("%d", &opcao);
                }while(opcao < 1 && opcao > 2);

                if(opcao == 1)
                {
                    int num;
                    if(remove_ini(deque, &num)==0){
                        printf("\nDeque vazio!\n");
                    }
                    else{
                        printf("\nNúmero %d removido com sucesso!\n", num);
                    }
                    printf("\n");
                }
                if(opcao == 2)
                {
                    int num;
                   if(remove_fim(deque, &num)==0){
                        printf("\nDeque vazio!\n");
                    }
                    else{
                        printf("\nNúmero %d removido com sucesso!\n", num);
                    }
                    printf("\n");
                }

                break;
            }

            case 4:
            {
                imprimir_deque(deque);
                break;
            }
            case 5:
            {

                 if(limpa_deque(deque) == 0)
                {
                    printf("\nDeque ja vazia ou inexistente!\n");
                    break;
                }else
                {
                    printf("\nNao ha mais elementos no deque !\n");
                }

                break;
            }
            case 6:
            {
                printf("\nOpcao 6 escolhida - SAIR\n\n");
                libera_deque(&deque);
                break;
            }
            default:
                printf("\nOpcao Inexistente!!!\n");
                break;
        }
    }while (escolha != 6);

    return 0;
}
