#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED

typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista l);
void lista_cheia(Lista l);
int insere_elem(Lista *l, char letter);
int remove_elem(Lista *l, char *letter);
int get_posicao(Lista *l, char letter, int *i);
int get_fim(Lista *l, int *i);
int get_values(Lista *l, int p, char *elem);
int limpa_lista(Lista *l);
void liberar_lista(Lista *l);

#endif // CHAR_H_INCLUDED
