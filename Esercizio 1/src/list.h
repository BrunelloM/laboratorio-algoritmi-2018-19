#ifndef LIST_H
#define LIST_H

/*
** Nodo
*/
typedef struct _Node Node;

/*
** lista
*/
typedef struct _List List;

/*
** iteratore
*/
typedef struct _Iterator Iterator;

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
void List_add_tail(List *, Node*);

/*
** Inserimento in una specifica posizione
*/
void List_add_i(List *, Node*, int);

/*
** Verifica se la lista e' vuota
*/
int List_is_empty(List *);

/*
** Ritorna il numero degli elementi presenti nella lista
*/
int List_size(List *);

/*
** Cancella l'elemento in coda alla lista
*/
void List_remove_tail(List *);

/*
** Cancella l'elemento alla posizione i
*/
void List_remove_i(List *, int);

/*
** Ritorna l-elemento alla posizione i
*/
Node *List_get_node(List *, int);

/*
** ritorna un nuovo iteratore per la lista
*/
Iterator *List_get_iterator(List *);

/*
** sposta l-iteratore alla prossima posizione
*/
void Iterator_get_next(Iterator *);

/*
** ritorna 0 se invalido, >0 altrimenti
*/
int Iterator_is_valid(Iterator *);

/*
** ritorna l'elemento puntato dall'iterator
*/
Node *Iterator_get_element(Iterator *);

/*
** Stampa la lista
*/
void List_print(List *, void (print_node)(void*));

/*
** crea un nuovo nodo
*/
Node *List_new_node(void *);

#endif
