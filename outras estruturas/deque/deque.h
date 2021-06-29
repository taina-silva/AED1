#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

typedef struct deque *Deque;
Deque cria_deque();
int deque_vazio(Deque f);
int deque_cheio(Deque f);
int insere_fim(Deque f, int elem);
int insere_inicio(Deque f, int elem);
int remove_ini(Deque f, int *elem);
int remove_fim(Deque f, int *elem);
int tam__deque(Deque f, int *tam);
int limpa_deque(Deque f);
void liberar(Deque *f);

#endif // DEQUE_H_INCLUDED
