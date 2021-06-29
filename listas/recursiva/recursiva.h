#ifndef RECURSIVA_H_INCLUDED
#define RECURSIVA_H_INCLUDED

typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_final (Lista *lst, double elem);
int insere_ord (Lista *lst, double elem);
int remove_inicio(Lista *lst, double *elem);
int remove_elem(Lista *lst, double elem);
int remove_ord(Lista *lst, double elem);
int remove_posicao(Lista *lst, int position);
int get_posicao(Lista lst, double elem);
double obtem_elem(Lista lst, int position);
int get_end(Lista lst);
void limpa_lista(Lista *lst);

#endif // RECURSIVA_H_INCLUDED
