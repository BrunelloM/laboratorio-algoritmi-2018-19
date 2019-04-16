#include "edit_distance.h"
#include <string.h>
#include <stdio.h>

int edit_distance_rec(char *, char *, int, int);
int min(int, int, int);
int edit_distance_dyn_rec(char *, char *, int l1, int l2, int[l1][l2]);

int edit_distance_dyn(char *str1, char *str2) {
        int l1 = (int) strlen(str1);
        int l2 = (int) strlen(str2);

        int values[l1][l2];

        memset(values, -1 , sizeof(values));



        return edit_distance_dyn_rec(str1, str2, l1 , l2, values);
}


int edit_distance_dyn_rec(char* str1, char* str2, int l1, int l2, int values[l1][l2]) {
        if (l1 == 0)
                return l2;

        if (l2 == 0)
                return l1;

        if (values[l1 - 1][l2 - 1] != -1)
                return values[l1 - 1][l2 - 1];

        if (str1[l1 - 1] == str2[l2 - 1])
                return values[l1 - 1][l2 - 1] = edit_distance_dyn_rec(str1, str2, l1 - 1, l2 - 1, values);

        return values[l1 - 1][l2 - 1] = 1 + min(edit_distance_dyn_rec(str1, str2, l1, l2 - 1, values), // Insert
                                                edit_distance_dyn_rec(str1, str2, l1 - 1, l2, values), // Remove
                                                edit_distance_dyn_rec(str1, str2, l1 - 1, l2 - 1, values));
}

int edit_distance(char *str1, char *str2) {
        int l1 = (int) strlen(str1);
        int l2 = (int) strlen(str2);

        return edit_distance_rec(str1, str2, l1, l2);
}

int edit_distance_rec(char *str1, char *str2, int l1, int l2) {
        if(l1 == 0)
                return l2;

        if(l2 == 0)
                return l1;

        if(str1[l1 - 1] == str2[l2 - 1])
                return edit_distance_rec(str1, str2, l1 - 1, l2 - 1);
        else
                return min(edit_distance_rec(str1, str2, l1, l2 - 1) + 1,
                           edit_distance_rec(str1, str2, l1 - 1, l2) + 1,
                           edit_distance_rec(str1, str2, l1 - 1, l2 - 1) + 1);
}

int min(int a, int b, int c) {
        int min_ab = (a <= b) ? a : b;
        return (c <= min_ab) ? c : min_ab;
}
