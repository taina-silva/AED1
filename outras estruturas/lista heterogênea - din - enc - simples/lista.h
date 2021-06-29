#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista l);
int insere_elem(Lista *l, int elem, char elem2, int tipo);
int remove_elem(Lista *l, int elem, char elem2, int tipo);
int get_values(Lista l, int p, int *elem, char *elem2, int *tipo);
void get_fim(Lista l, int *i);
int limpa_lista(Lista *l);
void liberar_lista(Lista *l);

#endif // LISTA_H_INCLUDED
