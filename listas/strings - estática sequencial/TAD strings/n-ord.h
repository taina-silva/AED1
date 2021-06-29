#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX1 20
#define MAX2 11

typedef struct lista *Lista;
Lista cria_lista();
int lista_vazia(Lista l);
int lista_cheia(Lista l);
int insere_elem (Lista l, char *elem);
int remove_elem (Lista l, char *elem);
int limpa_lista (Lista l);
int *get_posicao (Lista l, char *elem, int *p);
int *get_fim(Lista l, int *p);
char *get_values(Lista l, int i, char *elem);
void liberar_lista(Lista *l);

#endif // LISTA_H_INCLUDED
