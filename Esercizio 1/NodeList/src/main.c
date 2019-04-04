#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void print_integer(void *element) {
        printf(" %d", *((int*) element));
}


int main() {
        List *list = list_create();
        int values[] = {10, 24, 3, 2, 4, 6};
        int *ptr_int;

        ptr_int = (int *) malloc(sizeof(int));
        *ptr_int = values[0];
        list_add_i(list, ptr_int, 0);

        ptr_int = (int *) malloc(sizeof(int));
        *ptr_int = values[1];
        list_add_i(list, ptr_int, 1);

        // for(int i = 0; i < 6; i++) {
        //
        // }
        list_print(list, print_integer);
}
