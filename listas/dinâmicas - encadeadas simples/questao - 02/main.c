#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"

int Opcoes()
{
    int opcao;
    printf("---------------------------------------\n");
    printf("\nEscolha uma das opcoes a seguir:\n\n");
    printf("[1]. Criar lista (tecle 1):\n");
    printf("[2]. Inserir registro de aluno (tecle 2):\n");
    printf("[3]. Apagar registro de aluno (tecle 3):\n");
    printf("[4]. Imprimir lista de alunos (tecle 4):\n");
    printf("[5]. Tamanho da lista de alunos (tecle 5):\n");
    printf("[6]. Limpar lista (tecle 6):\n");
    printf("[7]. Sair (tecle 7):\n\n");

    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    Lista lista;

    int escolha = 0;
    unsigned int matricula;
    char nome[20];
    float media;
    int faltas;

    do
    {
        escolha = Opcoes();
        switch (escolha)
        {
            case 1:
                printf("\nOpcao 1 escolhida -  Criar lista\n\n");
                lista = cria_lista();
                printf("\nLista criada com sucesso!\n\n");
                break;

            case 2:
                printf("\nOpcao 2 escolhida -  Inserir registro de aluno\n\n");
                printf("\nInsira os dados do aluno:\n\n");

                printf("    Matricula: ");
                scanf("%u", &matricula);
                printf("    Nome: ");
                scanf("%s", nome);
                printf("    Media: ");
                scanf("%f", &media);
                printf("    Faltas: ");
                scanf("%d", &faltas);

                insere_elem(&lista, matricula, nome, media, faltas);

                break;

            case 3:
                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                printf("\nOpcao 3 escolhida - Apagar registro de aluno\n\n");

                printf("Numero de matricula do aluno cujo registro deseja remover: ");
                scanf("%u", matricula);

                if (remove_elem (&lista, matricula) == 0)
                {
                    printf("\nLista vazia ou registro de aluno inexistente!\n\n");
                }else
                {
                    printf("\nRegistro de aluno removido com sucesso!\n");
                }
                break;

            case 4:
                printf("\nOpcao 4 escolhida - Imprimir lista de alunos\n\n");

                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                int f;
                f = size_lista(&lista);

                printf("\nElementos da lista: ");

                for(int i=1; i <= f; i++)
                {
                    get_matricula(&lista, i, &matricula);
                    get_nome(&lista, i, nome);
                    get_media(&lista, i, &media);
                    get_faltas(&lista, i, &faltas);
                    printf("\n\n    Dados do aluno %d:\n", i);
                    printf("        Matricula: %u\n", matricula);
                    printf("        Nome: %s\n", nome);
                    printf("        Media: %.2f\n", media);
                    printf("        Faltas: %d\n", faltas);
                }

                printf("\n");
                break;

            case 5:
                printf("\nOpcao 5 escolhida - Tamanho da lista de alunos\n\n");

                if(lista_vazia(lista) == 1)
                {
                    printf("Lista vazia!\n\n");
                    break;
                }

                int end;
                end = size_lista(&lista);
                printf("\nQuantidade de alunos registrados: %d\n", end);
                break;

            case 6:
                printf("\nOpcao 6 escolhida - Limpar lista\n\n");
                if(lista_vazia(lista) == 1)
                {
                    printf("Lista ja vazia!\n\n");
                    break;
                }

                limpa_lista(&lista);
                printf("\nNao ha mais elementos na lista!!!\n");
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
