#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#define RESIZE_FACTOR 2
#define INITIAL_SIZE 100

struct _List {
        void **array_list;
        int element_count;
        int tail_index;
        int array_size;
};

struct _Iterator {
        int index;
};

void List_right_shift(List *, int);
void List_left_shift(List *, int);
void List_resize(List *);

void throw_error(char *string) {
	fprintf(stderr, "%s", string);
	exit(EXIT_FAILURE);
}

List *List_create() {
        List *new_list = (List *) malloc(sizeof(List));
        if(new_list == NULL)
                throw_error("malloc error: not enough space for a List object");
        new_list->array_list = (void **) malloc(sizeof(void *) * INITIAL_SIZE);
        if(new_list->array_list == NULL)
                throw_error("malloc error: not enough space for an array of void pointers");
        new_list->tail_index = -1;
        new_list->element_count = 0;
        new_list->array_size = INITIAL_SIZE;
        return new_list;
}

void List_dispose(List *to_dispose) {
        if(to_dispose == NULL)
                throw_error("invalid parameter: to_dispose parameter canno be NULL value");
        free(to_dispose->array_list);
        free(to_dispose);
}

void List_add_tail(List *list, void *element) {
        if(list == NULL)
                throw_error("invalid parameter: list parameter cannot be NULL");

        if(element == NULL)
                throw_error("invalid parameter: element parameter cannot be NULL");

        if(list->element_count + 1 >= list->array_size) {
                // reallocate memory
                List_resize(list);
        }
        list->array_list[++list->tail_index] = element;
        list->element_count++;
}

void List_add_i(List *list, void *element, int index) {
        if(list == NULL)
                throw_error("invalid parameter: list parameter cannot be NULL");
        if(element == NULL)
                throw_error("invalid parameter: element parameter cannot be NULL");
        if(index < 0 || index >= list->element_count)
                throw_error("invalid parameter: invalid index value");

        if(list->element_count + 1 >= list->array_size) {
                // reallocate memory
                List_resize(list);
        }
        List_right_shift(list, index);
        list->array_list[index] = element;
        list->element_count++;
}

void List_right_shift(List *list, int to) {
        for(int i = list->tail_index; i >= to; i--) {
                list->array_list[i + 1] = list->array_list[i];
        }
        list->tail_index += 1;
}

void List_left_shift(List *list, int from) {
        for(int i = from; i < list->tail_index; i++) {
                list->array_list[i] = list->array_list[i + 1];
        }
        list->tail_index -= 1;
}

void List_resize(List *list) {
        list->array_size = list->array_size * RESIZE_FACTOR;
        list->array_list = (void**) realloc(list->array_list, sizeof(void*) * list->array_size);
        if(list->array_list == NULL)
                throw_error("realloc error: not enough memory to reallocate array_list");
}

void List_print(List *list, void (print_node)(void*)) {
        for(int i = 0; i < list->element_count; i++) {
                print_node(list->array_list[i]);
        }
}

int List_is_empty(List *list) {
        if(list == NULL)
                throw_error("invalid parameter: list parameter cannot be NULL");
        return list->element_count == 0;
}

int List_size(List *list) {
        if(list == NULL)
                throw_error("invalid parameter: list parameter cannot be NULL");
        return list->element_count;
}

void List_remove_tail(List *list) {
        if(list == NULL)
                throw_error("invalid parameter: list parameter cannot be NULL");
}

void List_remove_i(List *list, int index) {
        if(list == NULL)
                throw_error("invalid parameter: list parameter cannot be NULL");
        if(index < 0 || index >= list->element_count)
                throw_error("invalid parameter: invalid index value");

        List_left_shift(list, index);
        list->element_count -= 1;
}

void *List_get_i(List *list, int index) {
        if(list == NULL)
                throw_error("invalid parameter: list parameter cannot be NULL");
        if(index < 0 || index >= list->element_count)
                throw_error("invalid parameter: invalid index value");

        return list->array_list[index];
}

Iterator *List_get_iterator(List *list) {
        if(list == NULL)
                throw_error("invalid parameter: list parameter cannot be NULL");
        Iterator *iterator = (Iterator*) malloc(sizeof(Iterator));
        iterator->index = 0;
        return iterator;
}

void Iterator_get_next(Iterator *iterator) {

}

int Iterator_is_valid(Iterator *iterator) {

}

void *Iterator_get_element(Iterator *iterator) {
        if(iterator == NULL)
                throw_error("invalid parameter: iterator parameter cannot be NULL");
        if(Iterator_is_valid(iterator))
                throw_error("the current iterator is invalid");

}
