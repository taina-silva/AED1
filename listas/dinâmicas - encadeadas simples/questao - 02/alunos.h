#ifndef ALUNOS_H_INCLUDED
#define ALUNOS_H_INCLUDED

typedef struct Alunos alunos;
typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista l);
int insere_elem(Lista *l, unsigned int matri, char *name, float med, int falta);
int remove_elem(Lista *l, int matri);
int get_posicao(Lista *l, int matri);
int size_lista(Lista *l);
int get_matricula(Lista *l, int p, unsigned int *matri);
int get_nome(Lista *l, int p, char *name);
int get_media(Lista *l, int p, float *med);
int get_faltas(Lista *l, int p, int *falta);
int limpa_lista(Lista *l);

#endif // ALUNOS_H_INCLUDED
