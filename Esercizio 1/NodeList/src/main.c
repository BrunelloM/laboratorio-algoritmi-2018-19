#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void print_integer(void *to_print) {
        printf("%d, ", *((int*)to_print));
}

int main(){
        List *new_list = List_create();
        int *ptr_i;

        for(int i = 0; i < 22; i++) {
                ptr_i = (int*) malloc(sizeof(int));
                *ptr_i = i;
                List_add_tail(new_list, List_new_node(ptr_i));
        }

        ptr_i = (int*) malloc(sizeof(int));

        List_print(new_list, print_integer);
        *ptr_i = 130;
        List_add_i(new_list, List_new_node(ptr_i), 21);
        List_print(new_list, print_integer);

        List_dispose(new_list);
}
