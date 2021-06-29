#ifndef CIRCULAR_H_INCLUDED
#define CIRCULAR_H_INCLUDED

typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista l);
int insere_final(Lista *l, int elem);
int remove_inicio(Lista *l, int *elem);
int remove_final(Lista *l);
int remove_elem(Lista *l, int elem);
int get_posicao(Lista l, int elem);
int get_fim(Lista *l, int *i);
int get_values(Lista *l, int *elem, int p);
int limpa_lista(Lista *l);

#endif // CIRCULAR_H_INCLUDED
