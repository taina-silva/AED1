#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct fila *Fila;
Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int insere_fim(Fila f, int elem);
int remove_ini(Fila f, int *elem);
int tam_fila(Fila f, int *tam);
int get_values(Fila f, int i, int *valor);
int limpa_fila(Fila f);
void libera_fila(Fila *f);

#endif // FILA_H_INCLUDED
