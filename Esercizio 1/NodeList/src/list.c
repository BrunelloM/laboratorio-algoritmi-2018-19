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

struct _Iterator {
        Node *current_position;
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

void List_add_tail(List *current_list, Node *node) {
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

void List_add_i(List *current_list, Node *node, int index) {
        if(node == NULL)
                throw_error("node parameter cannot be NULL");
        if(current_list == NULL)
                throw_error("current_list parameter cannot be NULL");
        if(index >= current_list->current_size || index < 0)
                throw_error("invalid index: index argument is invalid");

        Node *iterator = current_list->head;

        if(index == 0) {                                 // the new node becomes the new head
                current_list->head->prec = node;
                node->next = current_list->head;
                current_list->head = node;
        } else if(index == current_list->current_size - 1) { // the new node becomes the new tail of the list
                List_add_tail(current_list, node);
        } else {                                         // search the position in which the node will be placed
                for(int i = 0; i < index - 1; i++)
                        iterator = iterator->next;

                node->next = iterator->next;
                node->prec = iterator;
                iterator->next->prec = node;
                iterator->next = node;
        }
}

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

void List_print(List *current_list, void (*print_node)(void*)) {
        Node *iterator = current_list->head;
        while(iterator != NULL) {
                print_node(iterator->data);
                iterator = (Node*) iterator->next;
        }
}

void List_remove_tail(List *current_list) {
        if(current_list == NULL)
                throw_error("current_list parameter cannot be NULL");
        current_list->tail->prec->next = NULL;
        free(current_list->tail);
}

void List_remove_i(List *current_list, int index) {
        if(current_list == NULL)
                throw_error("current_list parameter cannot be NULL");
        if(index >= current_list->current_size || index < 0)
                throw_error("invalid index: index argument is invalid");

        Node *iterator = current_list->head;

        if(index == 0) {
                iterator = iterator->next;
                iterator->prec = NULL;
                free(current_list->head);
                current_list->head = iterator;
        } else if(index == current_list->current_size - 1) {
                List_remove_tail(current_list);
        } else {
                for(int i = 0; i < index - 1; i++)
                        iterator = iterator->next;

                iterator->next->prec = iterator->prec;
                iterator->prec->next = iterator->next;
                free(iterator);
        }
}

Node *List_get_node(List* current_list, int index) {
        if(current_list == NULL)
                throw_error("current_list parameter cannot be NULL");
        if(index >= current_list->current_size || index < 0)
                throw_error("invalid index: index argument is invalid");

        Node *iterator = current_list->head;
        for(int i = 0; i < index - 1; i++)
                iterator = iterator->next;

        return iterator;
}

int List_size(List *current_list) {
        if(current_list == NULL)
                throw_error("current_list parameter cannot be NULL");
        return current_list->current_size;
}

Iterator *List_get_iterator(List *current_list) {
        if(current_list == NULL)
                throw_error("current_list parameter cannot be NULL");
        Iterator *new_iterator = (Iterator*) malloc(sizeof(Iterator));
        new_iterator->current_position = current_list->head;
        return new_iterator;
}

void Iterator_get_next(Iterator *iterator) {
        if(iterator == NULL)
                throw_error("iterator parameter cannot be NULL");
        iterator->current_position = iterator->current_position->next;
}

int Iterator_is_valid(Iterator *iterator) {
        if(iterator == NULL)
                throw_error("iterator parameter cannot be NULL");

        return iterator->current_position != NULL;
}

Node *Iterator_get_element(Iterator *iterator) {
        if(iterator == NULL)
                throw_error("iterator parameter cannot be NULL");
        if(!Iterator_is_valid(iterator))
                throw_error("current iterator is invalid");

        return iterator->current_position;
}

void throw_error(char *string) {
	fprintf(stderr, "%s", string);
	exit(EXIT_FAILURE);
}
