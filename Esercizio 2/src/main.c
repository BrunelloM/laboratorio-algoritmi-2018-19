#include "edit_distance.h"
#include <stdio.h>


int main() {
        char *str1 = "patupalipitpa";
        char *str2 = "sfiatonfia";

        int edit_dist = edit_distance(str1, str2);
        printf("With Dynamic Prog: %d", edit_distance_dyn(str1, str2));
        printf("\nWith Recursive Fn: %d", edit_dist);
}
