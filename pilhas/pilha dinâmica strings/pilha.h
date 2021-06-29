#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct no *Pilha;
Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha *p, char *nome);
int pop (Pilha *p, char *nome);
int get_topo(Pilha *p, char *nome);
int tam_pilha(Pilha p, int *tam);
int limpa_pilha(Pilha *p);
int libera_pilha(Pilha p);

#endif // PILHA_H_INCLUDED

