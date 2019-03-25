#ifndef LIST_H
#define LIST_H

typedef struct _Node Node;
typedef struct _List List;

/*
** Crea nuova lista
*/
List *List_create();

/*
** Dealloca la lista
*/
void List_dispose(List *);

/*
** Inserimento in coda
*/
void List_add_node(List *, Node*);

/*
** Verifica se la lista e' vuota
*/
int List_is_empty(List *);

/*
** Verifica se la lista e' vuota
*/
int List_size(List *);

void List_print(List *, void (print_node)(Node*));
Node *List_new_node(void *);

#endif
