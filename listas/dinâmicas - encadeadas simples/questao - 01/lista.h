#ifndef COMPLEXO_H_INCLUDED
#define COMPLEXO_H_INCLUDED
#define MAXN 20
#define MAX 11

#endif // COMPLEXO_H_INCLUDED

typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord (Lista *lst, int elem);
int remove_ord (Lista *lst, int elem);
int get_posicao(Lista lst, int elem);
int get_element(Lista lst, int position);
int get_end(Lista lst);
int limpa_lista(Lista *lst);
