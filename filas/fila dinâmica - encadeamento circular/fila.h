#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct no *Fila;
Fila cria_fila();
int fila_vazia(Fila f);
int insere_fim(Fila *f, int elem);
int remove_inicio(Fila *f, int *elem)
int remove_final(Fila *f);
int get_posicao(Fila *f, int elem);
int tam_fila(Fila *f, int *i);
int get_values(Fila *f, int *elem, int p);
int limpa_lista(Fila *f);

#endif // FILA_H_INCLUDED
