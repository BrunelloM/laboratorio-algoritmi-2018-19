#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Utility function to find minimum of three numbers
int min(int a, int b, int c) {
        int min_ab = (a <= b) ? a : b;
        return (c <= min_ab) ? c : min_ab;
}

int edit_dist_dyn_rec(char* str1, char* str2, int l1, int l2, int values[l1][l2]) {

    if (l1 == 0)
        return l2;

    if (l2 == 0)
        return l1;

    if (values[l1 - 1][l2 - 1] != -1)
        return values[l1 - 1][l2 - 1];

    if (str1[l1 - 1] == str2[l2 - 1])
        return values[l1 - 1][l2 - 1] = edit_dist_dyn_rec(str1, str2, l1 - 1, l2 - 1, values);

    return values[l1 - 1][l2 - 1] = 1 + min(edit_dist_dyn_rec(str1, str2, l1, l2 - 1, values), // Insert
                                      edit_dist_dyn_rec(str1, str2, l1 - 1, l2, values), // Remove
                                      edit_dist_dyn_rec(str1, str2, l1 - 1, l2 - 1, values));
}

// Driver Code
int main()
{

    char *str1 = "patupalipitpa";
    char *str2 = "sfiatonfia";
    int l1 = strlen(str1);
    int l2 = strlen(str2);

    // Declare a values array which stores
    // the answer to recursive calls
    int values[l1][l2];

    // initially all index with -1
    memset(values, -1, sizeof values);

    // Function call
    // memoization nad top-down approach
    printf("%d", edit_dist_dyn_rec(str1, str2, l1, l2, values));

    return 0;
}
