#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void print_integer(void *element) {
        printf(" %d", *((int*) element));
}


int main() {
        List *list = list_create();
        int values[] = {1, 2, 3, 2, 4, 6};
        int *ptr_int;
        for(int i = 0; i < 6; i++) {
                ptr_int = (int *) malloc(sizeof(int));
                *ptr_int = values[i];
                list_add_tail(list, ptr_int);
        }
        list_print(list, print_integer);
}
