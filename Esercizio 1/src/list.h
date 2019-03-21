#ifndef LIST_H
#define LIST_H

typedef struct {
	struct node *next;
	void *data;
}node;

typedef struct {
	node *head;
	node *tail;
}list;

void dispose_list(list*);
list *create_list();
void add_node(list*, node*);
node *new_node(void*, int);
void print_list(list *, void print_node(node*));


#endif
