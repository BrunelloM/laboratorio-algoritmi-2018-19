#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list *create_list() {
        list *ret_list = malloc(sizeof(list));
        ret_list->head = NULL;
        ret_list->tail = NULL;
        return ret_list;
}

void dispose_list(list *current_list) {
        node *iterator = (node*) current_list->head;
        node *to_dealloc = NULL;

        while(iterator) {
                to_dealloc = iterator;
                iterator = (node*) iterator->next;
                free(to_dealloc->data);
                free(to_dealloc);
        }
        free(current_list);
}

void add_node(list *current_list, node *node) {
        if(current_list->head == NULL && current_list->tail == NULL) {
                current_list->head = node;
                current_list->tail = node;
        } else {
                current_list->tail->next = node;
                current_list->tail = node;
        }
}

node *new_node(void *data, int data_type_size) {
        node *ret_node = (node*) malloc(sizeof(node));
        ret_node->data = malloc(data_type_size);
        memcpy(ret_node->data, data, data_type_size);
        ret_node->next = NULL;
        return ret_node;
}

void print_list(list *current_list, void print_node(node*)) {
        node *iterator = current_list->head;
        while(iterator != NULL) {
                print_node(iterator);
                iterator = (node*) iterator->next;
        }
}
