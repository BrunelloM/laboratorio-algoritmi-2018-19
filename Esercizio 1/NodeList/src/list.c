#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node Node;

struct _Node {
        void *data;
        Node *next;
};

struct _List {
        Node *tail;
        Node *head;
        int element_count;
};

struct _Iterator {
        Node *current_node;
};

Node *Node_new(void *, Node *);

void throw_error(char *string) {
	fprintf(stderr, "%s", string);
	exit(EXIT_FAILURE);
}

List *list_create() {
        List *new_list = (List *) malloc(sizeof(List));
        if(new_list == NULL)
                throw_error("malloc error: not enough space for a List object");

        new_list->tail = NULL;
        new_list->head = NULL;
        new_list->element_count = 0;
        return new_list;
}

void list_dispose(List *to_dispose) {
        if(to_dispose == NULL)
                throw_error("invalid parameter: to_dispose parameter cannot be NULL value");

        Node *disposable = to_dispose->head;
        Node *tmp;
        while(disposable != NULL) {
                tmp = disposable;
                disposable = disposable->next;
                free(tmp);
        }
        free(to_dispose);
}

void list_add_tail(List *list, void *element) {
        if(list == NULL)
                throw_error("invalid parameter: list parameter cannot be NULL");

        if(element == NULL)
                throw_error("invalid parameter: element parameter cannot be NULL");

        Node *new_element = Node_new(element, NULL);
        if(list->tail == NULL) {
                list->tail = list->head = new_element;
        } else {
                list->tail->next = new_element;
                list->tail = new_element;
        }

        list->element_count += 1;
}

void list_add_i(List *list, void *element, int index) {
        if(list == NULL)
                throw_error("invalid parameter: list parameter cannot be NULL");
        if(element == NULL)
                throw_error("invalid parameter: element parameter cannot be NULL");
        if(index < 0 || index >= list->element_count)
                throw_error("invalid parameter: invalid index value");

        if(index == 0) {
                list->head = Node_new(element, NULL);
                list->tail = list->head;
        } else {
                Node *iterator = list->head;
                while(index) {
                        iterator = iterator->next;
                        index--;
                }
                iterator->next = Node_new(element, iterator->next);
        }
        list->element_count += 1;
}

void list_print(List *list, void (print_element)(void*)) {
        Node *iterator = list->head;
        while(iterator) {
                print_element(iterator->data);
                iterator = iterator->next;
        }
}

int list_is_empty(List *list) {
        return (list->element_count == 0);
}

int list_size(List *list) {
        return list->element_count;
}

void list_remove_tail(List *list) {
        // (?)
}

void list_remove_i(List *list, int index) {
        // (?)
}

void *list_get_i(List *list, int index) {
        Node *iterator = list->head;
        while(index) {
                iterator = iterator->next;
                index--;
        }
        return iterator->data;
}

Iterator *list_get_iterator(List *list) {
        if(list == NULL)
                throw_error("invalid parameter:  list parameter cannot be NULL");
        Iterator *new_iterator = (Iterator *) malloc(sizeof(Iterator));
        if(new_iterator == NULL)
                throw_error("malloc error: not enough space for an Iterator object");
        new_iterator->current_node = list->head;
        return new_iterator;
}

void iterator_next(Iterator *iterator) {
        if(iterator == NULL)
                throw_error("invalid parameter: iterator parameter cannot be NULL");

        if(!iterator_is_valid(iterator))
                throw_error("invalid parameter: iterator parameter cannot be NULL");

        iterator->current_node = iterator->current_node->next;
}

int iterator_is_valid(Iterator *iterator) {
        if(iterator == NULL)
                throw_error("invalid parameter: iterator parameter cannot be NULL");

        return (iterator->current_node != NULL);
}

void *iterator_get_element(Iterator *iterator) {
        if(iterator == NULL)
                throw_error("invalid parameter: iterator parameter cannot be NULL");
        if(!iterator_is_valid(iterator))
                return NULL;

        return iterator->current_node->data;
}

void iterator_dispose(Iterator *iterator) {
        if(iterator == NULL)
                throw_error("invalid parameter: iterator parameter cannot be NULL");

        free(iterator);
}

Node *Node_new(void* data, Node* next) {
        Node *new_node = (Node *) malloc(sizeof(Node));

        if(new_node == NULL)
                throw_error("malloc error: not enough space for a Node object");

        new_node->data = data;
        new_node->next = next;
        return new_node;
}
