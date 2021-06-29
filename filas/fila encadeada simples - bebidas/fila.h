#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct bebidas Bebida;
typedef struct no *No;
typedef struct fila *Fila;
Fila cria_fila();
int fila_vazia(Fila f);
int insere_fim(Fila f, Bebida bebida);
int remove_ini(Fila f, Bebida *bebida);
void tam_fila(Fila f, int *tam);
int esvazia_fila(Fila f);
void apaga_fila(Fila *f);

#endif // FILA_H_INCLUDED
