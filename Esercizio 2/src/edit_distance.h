#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

/*
** Recursive edit distance function that returns the Levenshtein distance of 2 strings passed as parameters.
** @param char *: Pointer of the first string
** @param char *: Pointer of the second string
** @return int: The edit distance between first string and second string passed as parameter
*/
int edit_distance(char *, char *);

/*
** Recursive edit distance function that uses dynamic programming that limits recursive calls.
** @param char *: Pointer of the first string
** @param char *: Pointer of the second string
** @return int: The edit distance between first string and second string passed as parameter
*/
int edit_distance_dyn(char *, char *);

/*
** Minimum function with 3 (integer) parameters which returns the minimum integer between them.
** @param int: Value of the first integer
** @param int: Value of the second integer
** @param int: Value of the third integer
** @return int: The minimum value between first, second and third integers.
*/
int min(int, int, int);

#endif
