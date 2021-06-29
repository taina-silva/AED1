#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha * Pilha;

Pilha cria_pilha ();
int pilha_vazia (Pilha p);
int pilha_cheia (Pilha p);
int push (Pilha p, long int matricula, char *nome, char setor, float salario);
int pop (Pilha p, long int *matricula, char *nome, char *setor, float *salario);
int get_topo(Pilha p, long int *matricula, char *nome, char *setor, float *salario);
void esvazia_pilha(Pilha *p);
int tam_pilha(Pilha p, int *tam);
int libera_pilha(Pilha *p);


#endif // PILHA_H_INCLUDED
