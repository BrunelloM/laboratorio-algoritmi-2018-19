#ifndef LIST_H
#define LIST_H

typedef struct _Node Node;
typedef struct _List List;

void dispose_list(List*);
List *create_list(int (*compare_data)(void*, void*));
void add_node(List*, Node*);
Node *new_node(void*);
void print_list(List *, void (print_node)(Node*));


#endif
