#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct no *No;
typedef struct fila *Fila;
Fila cria_fila();
int fila_vazia(Fila f);
int insere_fim(Fila f, int elem);
int remove_ini(Fila f, int *elem);
void tam_fila(Fila f, int *tam);
int esvazia_fila(Fila f);
void apaga_fila(Fila *f);

#endif // FILA_H_INCLUDED
