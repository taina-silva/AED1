#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct lista *Lista;
Lista cria_lista();
int lista_vazia(Lista l);
int lista_cheia(Lista l);
int insere_elem (Lista l, float elem);
int remove_elem (Lista l, float elem);
int limpa_lista (Lista l);
int *get_posicao (Lista l, float elem, int *p);
int *get_fim(Lista l, int *p);
float *get_values(Lista l, int i, float *v);

#endif // LISTA_H_INCLUDED
