#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void print_integer(void *element) {
        printf(" %d", *((int*) element));
}

int compare_integer(void *a, void *b) {
        return *((int *)a) <= *((int *)b);
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
        List *list1 = list_create();
        List *list2 = list_create();

        int val1[] = {1, 5, 7, 9, 12, 17, 20, 22};
        int val2[] = {2, 3, 10, 17, 21, 50};
        int *ptr_int;

        for(int i = 0; i < 6; i++) {
                ptr_int = (int *) malloc(sizeof(int));
                *ptr_int = val1[i];
                list_add_tail(list1, ptr_int);
                ptr_int = (int *) malloc(sizeof(int));
                *ptr_int = val2[i];
                list_add_tail(list2, ptr_int);
        }

        list_print(list1, print_integer);
        list_print(list2, print_integer);
        printf("\n\n%d\n\n", *((int *)list_get_i(list2, 5)));

        List *merged_list = list_merge(list1, list2, compare_integer);
        list_print(merged_list, print_integer);
}
