#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void print_integer(void *element) {
        printf(" %d", *((int*) element));
}

void free_memory(List *to_free) {
        Iterator *iterator = list_get_iterator(to_free);
        void *data_to_free;
        while(iterator_is_valid(iterator)) {
                data_to_free = iterator_get_element(iterator);
                iterator_next(iterator);
                free(data_to_free);
        }
}

int main() {
        List *list = list_create();
        int values[] = {10, 24, 3, 2, 4, 6};
        int *ptr_int;

        for(int i = 0; i < 6; i++) {
                ptr_int = (int *) malloc(sizeof(int));
                *ptr_int = values[i];
                list_add_i(list, ptr_int, i);
        }

        //for(int i = 0; i < 6; i++) {
                //list_remove_i(list, 1);
                list_print(list, print_integer);
        //}




}
