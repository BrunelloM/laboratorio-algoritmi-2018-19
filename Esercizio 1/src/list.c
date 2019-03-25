#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void throw_error(char*);

struct _Node {
	Node *next;
	void *data;
};

struct _List {
	Node *head;
	Node *tail;
	int (*compare_data)(void*, void*);
};

List *create_list(int (*compare_data)(void*, void*)) {
	if(compare_data == NULL)
		throw_error("compare_data parameter cannot be null");
        List *ret_list = (List*) malloc(sizeof(List));
	if(ret_list == NULL)
		throw_error("malloc returned an invalid pointer");
        ret_list->head = NULL;
        ret_list->tail = NULL;
	ret_list->compare_data = compare_data;
        return ret_list;
}

void dispose_list(List *current_list) {
        Node *iterator = (Node*) current_list->head;
        Node *to_dealloc = NULL;

        while(iterator) {
                to_dealloc = iterator;
                iterator = (Node*) iterator->next;
                free(to_dealloc->data);
                free(to_dealloc);
        }
        free(current_list);
}

void add_node(List *current_list, Node *node) {
        if(current_list->head == NULL && current_list->tail == NULL) {
                current_list->head = node;
                current_list->tail = node;
        } else {
                current_list->tail->next = node;
                current_list->tail = node;
        }
}

/**
node *new_node(void *data, int data_type_size) {
        node *ret_node = (node*) malloc(sizeof(node));
        ret_node->data = malloc(data_type_size);
        memcpy(ret_node->data, data, data_type_size);
        ret_node->next = NULL;
        return ret_node;

**/

Node *new_node(void *data) {
	if(data == NULL)
		throw_error("invalid parameter execption: data parameter cannot be null");
	Node *ret_node = (Node*) malloc(sizeof(Node));
	if(ret_node == NULL)
		throw_error("malloc error: returned value is null");
	ret_node->data = data;
	ret_node->next = NULL;
	return ret_node;
}

void print_list(List *current_list, void (*print_node)(Node*)) {
        Node *iterator = current_list->head;
        while(iterator != NULL) {
                print_node(iterator);
                iterator = (Node*) iterator->next;
        }
}

void throw_error(char *string) {
	fprintf(stderr, "%s", string);
	exit(EXIT_FAILURE);
}
