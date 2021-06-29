#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct Alunos aluno;
typedef struct fila *Fila;
Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int insere_fim(Fila f, aluno pessoa);
int remove_ini(Fila f, aluno *pessoa);
void tam_fila(Fila f, int *tam);
int get_values(Fila f, int i, int *valor);
int limpa_fila(Fila f);
void libera_fila(Fila *f);


#endif // FILA_H_INCLUDED
