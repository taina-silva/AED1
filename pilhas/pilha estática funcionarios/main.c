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
    printf("\nEscolha uma das op��es a seguir:\n\n");
    printf("[1]. Criar pilha de funcion�rios (tecle 1):\n");
    printf("[2]. Empilhar funcion�rios (tecle 2):\n");
    printf("[3]. Desempilhar funcion�rios (tecle 3):\n");
    printf("[4]. Imprimir pilha de funcionrios (tecle 4):\n");
    printf("[5]. Funcion�rio no topo da pilha (tecle 5):\n");
    printf("[6]. Quantidade de funcion�rios na pilha (tecle 6):\n");
    printf("[7]. Limpar pilha de funcion�rios (tecle 7):\n");
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

    printf("\nFuncion�rios da pilha:\n\n");

    for(int i=0; i < tam; i++)
    {
        pop(p, &mat, name, &set, &sal);
        push(aux, mat, name, set, sal);
    }

    for(int i=0; i < tam; i++)
    {
        pop(aux, &mat, name, &set, &sal);
        printf("Funcion�rio %d\n", i+1);
        printf("\tMatr�cula: %ld\n", mat);
        printf("\tNome: %s\n", name);
        printf("\tSetor: %c\n", set);
        printf("\tSal�rio: %.2f\n", sal);
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
                printf("\nOp��o 1 escolhida -  Criar pilha de funcion�rios\n\n");

                pilha = cria_pilha();

                if(pilha == NULL)
                {
                    printf("Falha na aloca��o!\n\n");
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

                printf("\nOp��o 2 escolhida -  Empilhar funcion�rios\n\n");

                int qtdd;

                printf("Quantidade inicial de funcion�rios a serem inseridos na pilha (m�ximo = 20): ");
                scanf("%d", &qtdd);

                while(qtdd<0 || qtdd>20)
                {
                    printf("\nQuantidade inv�lida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira os funcion�rios na pilha:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    if(pilha_cheia(pilha)==1)
                    {
                        printf("\nPilha cheia!\n\n");
                        break;
                    }

                    printf("\tFuncion�rio %d:\n", i+1);
                    printf("\tMatr�cula: ");
                    scanf("%ld", &matricula);
                    printf("\tNome: ");
                    scanf("%s", nome);
                    setbuf(stdin, NULL); //limpar buffer de string\char
                    printf("\tSetor: ");
                    scanf("%c", &setor);
                    printf("\tSal�rio: ");
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
                printf("\nOp��o 3 escolhida - Desempilhar funcion�rios\n\n");

                if (pop(pilha, &matricula, nome, &setor, &salario) == 0)
                {
                    printf("\nPilha vazia ou funcion�rio inexistente!!\n\n");
                }else
                {
                    printf("Funcion�rio removido: \n");
                    printf("\tMatr�cula: %ld\n", matricula);
                    printf("\tNome: %s\n", nome);
                    printf("\tSetor: %c\n", setor);
                    printf("\tSal�rio: %.2f\n", salario);
                }
                break;

            case 4:
                printf("\nOp��o 4 escolhida - Imprimir pilha de funcion�rios\n\n");

                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }

                imprimir_pilha(pilha);
                break;

            case 5:
                printf("\nOp��o 5 escolhida - Funcion�rio no topo da pilha \n\n");

                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }

                get_topo(pilha, &matricula, nome, &setor, &salario);

                printf("Funcion�rio no topo da pilha: \n");
                printf("\tMatr�cula: %ld\n", matricula);
                printf("\tNome: %s\n", nome);
                printf("\tSetor: %c\n", setor);
                printf("\tSal�rio: %.2f\n", salario);

                break;

            case 6:
                printf("\nOp��o 6 escolhida - Quantidade de funcion�rios na pilha\n\n");

                if(pilha_vazia(pilha)==1)
                {
                    printf("Pilha vazia!\n\n");
                    break;
                }

                int tamanho;
                tam_pilha(pilha, &tamanho);
                printf("H� %d funcion�rios na pilha!\n", tamanho);

                break;

            case 7:
                printf("\nOp��o 7 escolhida - Limpar pilha de funcion�rios\n\n");

                esvazia_pilha(&pilha);

                printf("\nN�o h� mais funcion�rios na pilha!\n");

                break;

            case 8:
                printf("\nOp��o 8 escolhida - SAIR\n\n");
                libera_pilha(&pilha);
                break;

            default:
                printf("\nOp��o Inexistente!!!\n");
                break;
        }

    }while(escolha!=8);

    return 0;
}
