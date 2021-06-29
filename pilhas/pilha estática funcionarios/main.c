#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

#include "pilha.h"

#define MAX 20
#define MAX2 30

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opções a seguir:\n\n");
    printf("[1]. Criar pilha de funcionários (tecle 1):\n");
    printf("[2]. Empilhar funcionários (tecle 2):\n");
    printf("[3]. Desempilhar funcionários (tecle 3):\n");
    printf("[4]. Imprimir pilha de funcionrios (tecle 4):\n");
    printf("[5]. Funcionário no topo da pilha (tecle 5):\n");
    printf("[6]. Quantidade de funcionários na pilha (tecle 6):\n");
    printf("[7]. Limpar pilha de funcionários (tecle 7):\n");
    printf("[8]. Sair (tecle 8):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

void imprimir_pilha(Pilha p)
{
    int tam;
    tam_pilha(p, &tam);

    long int mat;
    char name[MAX2];
    char set;
    float sal;

    Pilha aux = cria_pilha();

    printf("\nFuncionários da pilha:\n\n");

    for(int i=0; i < tam; i++)
    {
        pop(p, &mat, name, &set, &sal);
        push(aux, mat, name, set, sal);
    }

    for(int i=0; i < tam; i++)
    {
        pop(aux, &mat, name, &set, &sal);
        printf("Funcionário %d\n", i+1);
        printf("\tMatrícula: %ld\n", mat);
        printf("\tNome: %s\n", name);
        printf("\tSetor: %c\n", set);
        printf("\tSalário: %.2f\n", sal);
        push(p, mat, name, set, sal);
        printf("\n");
    }

    printf("\n");
}

int main()
{
    setlocale (LC_ALL, "Portuguese");

    Pilha pilha;
    long int matricula;
    char nome[MAX2];
    char setor;
    float salario;

    int escolha = 0;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOpção 1 escolhida -  Criar pilha de funcionários\n\n");

                pilha = cria_pilha();

                if(pilha == NULL)
                {
                    printf("Falha na alocação!\n\n");
                    break;
                }else
                {
                    printf("Pilha criada com sucesso!\n\n");
                }

                break;

            case 2:
                if(pilha_cheia(pilha)==1)
                {
                    printf("\nPilha cheia!\n\n");
                    break;
                }

                printf("\nOpção 2 escolhida -  Empilhar funcionários\n\n");

                int qtdd;

                printf("Quantidade inicial de funcionários a serem inseridos na pilha (máximo = 20): ");
                scanf("%d", &qtdd);

                while(qtdd<0 || qtdd>20)
                {
                    printf("\nQuantidade inválida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira os funcionários na pilha:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    if(pilha_cheia(pilha)==1)
                    {
                        printf("\nPilha cheia!\n\n");
                        break;
                    }

                    printf("\tFuncionário %d:\n", i+1);
                    printf("\tMatrícula: ");
                    scanf("%ld", &matricula);
                    printf("\tNome: ");
                    scanf("%s", nome);
                    setbuf(stdin, NULL); //limpar buffer de string\char
                    printf("\tSetor: ");
                    scanf("%c", &setor);
                    printf("\tSalário: ");
                    scanf("%f", &salario);
                    push(pilha, matricula, nome, setor, salario);
                    printf("\n");
                }
                break;

            case 3:
                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }
                printf("\nOpção 3 escolhida - Desempilhar funcionários\n\n");

                if (pop(pilha, &matricula, nome, &setor, &salario) == 0)
                {
                    printf("\nPilha vazia ou funcionário inexistente!!\n\n");
                }else
                {
                    printf("Funcionário removido: \n");
                    printf("\tMatrícula: %ld\n", matricula);
                    printf("\tNome: %s\n", nome);
                    printf("\tSetor: %c\n", setor);
                    printf("\tSalário: %.2f\n", salario);
                }
                break;

            case 4:
                printf("\nOpção 4 escolhida - Imprimir pilha de funcionários\n\n");

                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }

                imprimir_pilha(pilha);
                break;

            case 5:
                printf("\nOpção 5 escolhida - Funcionário no topo da pilha \n\n");

                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }

                get_topo(pilha, &matricula, nome, &setor, &salario);

                printf("Funcionário no topo da pilha: \n");
                printf("\tMatrícula: %ld\n", matricula);
                printf("\tNome: %s\n", nome);
                printf("\tSetor: %c\n", setor);
                printf("\tSalário: %.2f\n", salario);

                break;

            case 6:
                printf("\nOpção 6 escolhida - Quantidade de funcionários na pilha\n\n");

                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }

                int tamanho;
                tam_pilha(pilha, &tamanho);
                printf("Há %d funcionários na pilha!\n", tamanho);

                break;

            case 7:
                printf("\nOpção 7 escolhida - Limpar pilha de funcionários\n\n");

                esvazia_pilha(&pilha);

                printf("\nNão há mais funcionários na pilha!\n");

                break;

            case 8:
                printf("\nOpção 8 escolhida - SAIR\n\n");
                libera_pilha(&pilha);
                break;

            default:
                printf("\nOpção Inexistente!!!\n");
                break;
        }

    }while(escolha!=8);

    return 0;
}
