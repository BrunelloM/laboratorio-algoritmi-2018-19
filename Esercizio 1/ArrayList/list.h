#ifndef LIST_H
#define LIST_H

/*
** Lista
*/
typedef struct _List List;

/*
** iteratore
*/
typedef struct _Iterator Iterator;

/*
** Crea nuova Lista
*/
List *list_create();

/*
** Dealloca la Lista
*/
void list_dispose(List *);

/*
** Inserimento in coda
*/
void list_add_tail(List *, void *);

/*
** Inserimento in una specifica posizione
*/
void list_add_i(List *, void *, int);

/*
** Verifica se la Lista e' vuota
*/
int list_is_empty(List *);

/*
** Ritorna il numero degli elementi presenti nella Lista
*/
int list_size(List *);

/*
** Cancella l'elemento in coda alla Lista
*/
void list_remove_tail(List *);

/*
** Cancella l'elemento alla posizione i
*/
void list_remove_i(List *, int);

/*
** Ritorna l'elemento alla posizione i
*/
void *list_get_i(List *, int);

/*
** ritorna un nuovo iteratore per la Lista
*/
Iterator *list_get_iterator(List *);

/*
** sposta l-iteratore alla prossima posizione
*/
void iterator_next(Iterator *);

/*
** ritorna 0 se invalido, >0 altrimenti
*/
int iterator_is_valid(Iterator *);

/*
** ritorna l'elemento puntato dall'iterator
*/
void *iterator_get_element(Iterator *);

/*
** cancella l'iteratore passato come parametro
*/
void iterator_dispose(Iterator *);

/*
** Stampa la Lista
*/
void list_print(List *, void (print_node)(void*));



/*
** mergesort di due Liste
** criterio e' il criterio di ordinamento
*/
//List *List_merge(List*, List*, int (criterio)(void*, void*));


#endif
