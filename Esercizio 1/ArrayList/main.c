#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void print_integer(void *element) {
        printf("%d,", *((int*)element));
}

int main() {
        List *list = list_create();

        int *ptr;

        for(int i = 0; i < 101; i++) {
                ptr = (int*) malloc(sizeof(int));
                *ptr = i;
                list_add_tail(list, ptr);
        }
        ptr = (int*) malloc(sizeof(int));
        *ptr = 8743;


        list_add_i(list, ptr, 10);
        for(int i = 0; i < 91; i++)
                list_remove_tail(list);
        list_print(list, print_integer);
        list_dispose(list);
        //List_add_tail(list, NULL);
}
