#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fila.h"

struct Alunos
{
    int matricula;
    char nome[50];
    int faltas;
    float media;
};
typedef struct Alunos Alunos;

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Criar fila (tecle 1):\n");
    printf("[2]. Inserir alunos na fila (tecle 2):\n");
    printf("[3]. Remover aluno da fila (tecle 3):\n");
    printf("[4]. Imprimir fila (tecle 4):\n");
    printf("[5]. Limpar fila (tecle 6):\n");
    printf("[6]. Sair (tecle 7):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

void imprimir_fila(Fila fila)
{
    Fila aux = cria_fila();

    int i=1;

    printf("Alunos da fila:\n\n");
    while(fila_vazia(fila) == 0)
    {
        Alunos pessoa;
        remove_ini(fila, &pessoa);
        printf("\tAluno %d:\n", i);
        printf("\tMatricula: %d\n", pessoa.matricula);
        printf("\tNome: %s\n", pessoa.nome);
        printf("\tFaltas: %d\n", pessoa.faltas);
        printf("\tMedia: %.2f\n", pessoa.media);
        insere_fim(aux, pessoa);
        fila_vazia(fila);
        i++;
        printf("\n");
    }

    while(fila_vazia(aux) == 0)
    {
        Alunos pessoa;
        remove_ini(aux, &pessoa);
        insere_fim(fila, pessoa);
        fila_vazia(aux);
    }

    printf("\n");
}

int main()
{
    Fila fila;

    int escolha = 0;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar fila\n\n");

                fila = cria_fila();

                if(fila == NULL)
                {
                    printf("Falha na alocacao!\n\n");
                    break;
                }else
                {
                    printf("Fila criada com sucesso!\n\n");
                }

                break;

            case 2:
                if(fila_cheia(fila)==1)
                {
                    printf("\nFila cheia!\n\n");
                    break;
                }

                printf("\nOpcao 2 escolhida -  Inserir alunos na fila\n\n");

                int qtdd;
                Alunos aluno;

                printf("Quantidade inicial de alunos a serem inseridos na fila (maximo = 20): ");
                scanf("%d", &qtdd);

                while(qtdd<0 || qtdd>20)
                {
                    printf("\nQuantidade invalida!\n");
                    printf("\nDigite novamente: ");
                    scanf("%d", &qtdd);
                }

                printf("\nInsira os alunos na fila:\n\n");

                for(int i=0; i<qtdd; i++)
                {
                    if(fila_cheia(fila)==1)
                    {
                        printf("\nFila cheia!\n\n");
                        break;
                    }

                    printf("\tAluno %d: \n", i+1);
                    printf("\tMatricula: ");
                    scanf("%d", &aluno.matricula);
                    setbuf(stdin, NULL);
                    printf("\tNome: ");
                    scanf("%s", aluno.nome);
                    printf("\tFaltas: ");
                    scanf("%d", &aluno.faltas);
                    printf("\tMedia: ");
                    scanf("%f", &aluno.media);
                    insere_fim(fila, aluno);
                    printf("\n");
                }
                break;

            case 3:
                if(fila_vazia(fila)==1)
                {
                    printf("Fila  vazia!\n\n");
                    break;
                }
                printf("\nOpcao 3 escolhida - Remover aluno da fila\n\n");

                Alunos remover;
                if (remove_ini(fila, &remover) == 0)
                {
                    printf("\nFila  vazia ou aluno inexistente!!\n\n");
                }else
                {
                    printf("Aluno removido:\n\n");
                    printf("Matricula: %d\n", remover.matricula);
                    printf("Nome: %s\n", remover.nome);
                    printf("Faltas: %d\n", remover.faltas);
                    printf("Media: %.2f\n", remover.media);
                }
                break;

            case 4:
                printf("\nOpcao 4 escolhida - Imprimir fila\n\n");

                if(fila_vazia(fila)==1)
                {
                    printf("Fila vazia!\n\n");
                    break;
                }

                imprimir_fila(fila);
                break;

            case 5:
                printf("\nOpcao 5 escolhida - Limpar fila\n\n");

                if(limpa_fila(fila) == 0)
                {
                    printf("\nFila ja vazia ou inexistente!\n");
                    break;
                }else
                {
                    printf("\nNao ha mais alunos na fila !\n");
                }

                break;

            case 6:
                printf("\nOpcao 6 escolhida - SAIR\n\n");
                libera_fila(&fila);
                break;

            default:
                printf("\nOpcao Inexistente!!!\n");
                break;
        }

    }while(escolha!=6);

    return 0;
}
