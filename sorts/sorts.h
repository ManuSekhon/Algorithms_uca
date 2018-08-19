/**
 * THIS HEADER FILE CONTAINS DECLARATIONS OF DIFFERENT SORTING 
 * ALGORITHMS SUCH AS MERGE SORT, QUICK SORT AND INSERTION SORT.
 * RUNS ON ALL DATA TYPES.
 */

#ifndef SORTS_H
#define SORTS_H

/**
 * COMPARE FUNCTION:
 * Every sorting function here takes pointer to compare function that must return integer less
 * 0, 0 or greater than 0 if a is less than, equal to or greater than b respectively. 
 */

// Sorts an array using merge sort
void msort(void *base, void *aux, int start, int end, int size,
           int (*compar)(const void *a, const void *b));

// Sorts an array using randomized quick sort
void my_qsort(void *base, int start, int end, int size,
              int (*compar)(const void *a, const void *b));

// Sorts an array using insertion sort
void isort(void *base, int start, int end, int size, int (*compar)(const void *a, const void *b));

#endif // SORTS_H