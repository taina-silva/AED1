#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista l);
int insere_elem(Lista l, int elem);
int remove_elem(Lista *l, int elem);
int remove_ord(Lista *l, int *elem);
int get_posicao(Lista *l, int elem, int *i);
int get_fim(Lista *l, int *i);
int get_values(Lista l, int *elem, int p);
int limpa_lista(Lista *l);

#endif // NO_H_INCLUDED
