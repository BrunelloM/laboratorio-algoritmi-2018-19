#include "list.h"
#include <stdio.h>

void print_integer(Node *to_print) {
        printf("%d", *((int*) to_print->data ));
}

int main(){
        List *new_list = List_create();

        for(int i = 0; i < 22; i++) {
                List_add_node(new_list, List_new_node(&i));
        }

        List_print(new_list, print_integer);

        List_dispose(new_list);
}
