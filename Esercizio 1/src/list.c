#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void throw_error(char*);

struct _Node {
	Node *next;
        Node *prec;
	void *data;
};

struct _List {
	Node *head;
	Node *tail;
        int current_size;
};

List *List_create() {
        List *ret_list = (List*) malloc(sizeof(List));
	if(ret_list == NULL)
		throw_error("malloc returned an invalid pointer");
        ret_list->head = NULL;
        ret_list->tail = NULL;
	ret_list->current_size = 0;
        return ret_list;
}

void List_dispose(List *current_list) {
        Node *iterator = current_list->head;
        Node *to_dealloc = NULL;

        while(iterator) {
                to_dealloc = iterator;
                iterator = iterator->next;
                free(to_dealloc);
        }
        free(current_list);
}

void List_add_node(List *current_list, Node *node) {
        if(current_list == NULL)
                throw_error("current_list parameter cannot be NULL");

        if(node == NULL)
                throw_error("node parameter cannot be NULL");

        if(current_list->head == NULL && current_list->tail == NULL) {
                current_list->head = node;
                current_list->tail = node;
        } else {
                node->prec = current_list->tail;
                current_list->tail->next = node;
                current_list->tail = node;
        }
        current_list->current_size += 1;
}

/**
node *new_node(void *data, int data_type_size) {
        node *ret_node = (node*) malloc(sizeof(node));
        ret_node->data = malloc(data_type_size);
        memcpy(ret_node->data, data, data_type_size);
        ret_node->next = NULL;
        return ret_node;

**/

Node *List_new_node(void *data) {
	if(data == NULL)
		throw_error("invalid parameter execption: data parameter cannot be null");
	Node *ret_node = (Node*) malloc(sizeof(Node));
	if(ret_node == NULL)
		throw_error("malloc error: returned value is null");
	ret_node->data = data;
        ret_node->prec = NULL;
	ret_node->next = NULL;
	return ret_node;
}

int List_is_empty(List *current_list) {
        if(current_list == NULL)
                throw_error("current_list parameter cannot be null");

        return current_list->current_size == 0;
}

void List_print(List *current_list, void (*print_node)(Node*)) {
        Node *iterator = current_list->head;
        while(iterator != NULL) {
                print_node(iterator);
                iterator = (Node*) iterator->next;
        }
}

int List_size(List *current_list) {
        return current_list->current_size;
}

void throw_error(char *string) {
	fprintf(stderr, "%s", string);
	exit(EXIT_FAILURE);
}
