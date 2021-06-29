#ifndef BEBIDAS-ORD_H_INCLUDED
#define BEBIDAS-ORD_H_INCLUDED

#define MAX1 20
#define MAX2 11

typedef struct lista *Lista;
Lista cria_lista();
int lista_vazia(Lista l);
int lista_cheia(Lista l);
int insere_ord (Lista l, char *elem, int vol, float p);
int remove_ord (Lista l, char *elem);
int limpa_lista (Lista l);
int *get_posicao (Lista l, char *elem, int *p);
int *get_fim(Lista l, int *p);
char *get_nome(Lista l, int i, char *elem);
int *get_volume(Lista l, int i, int *v);
float *get_preco(Lista l, int i, float *p);
void liberar_lista(Lista *l);

#endif // BEBIDAS-ORD_H_INCLUDED

