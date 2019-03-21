#include "list.h"
#include <stdio.h>

struct my_datatype {
        int id1;
        char id2;
};

void print_integer(node *to_print) {
        printf("%d", *((int*)to_print->data));
}

void print_struct(node *to_print) {
        printf("\nid1: %d, id2: %c", (((struct my_datatype*)to_print->data)->id1), (((struct my_datatype*)to_print->data)->id2));
}

int main(){
        int n = 5;
        list *new_list = create_list();

        for(int i = 0; i < 22; i++) {
                struct my_datatype to_add;
                to_add.id1 = i;
                to_add.id2 = i + 97;

                add_node(new_list, new_node(&to_add, sizeof(to_add)));
        }

        print_list(new_list, print_struct);

        dispose_list(new_list);
}
