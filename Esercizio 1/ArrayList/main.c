#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void print_integer(void *element) {
        printf("%d,", *((int*)element));
}

int main() {
        List *list = List_create();

        int *ptr;

        for(int i = 0; i < 12; i++) {
                ptr = (int*) malloc(sizeof(int));
                *ptr = i;
                List_add_tail(list, ptr);
        }
        ptr = (int*) malloc(sizeof(int));
        *ptr = 8743;
        List_add_i(list, ptr, 10);
        List_remove_i(list, 10);
        List_print(list, print_integer);

        //List_add_tail(list, NULL);
}
