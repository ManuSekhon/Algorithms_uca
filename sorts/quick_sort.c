#include <stdlib.h>
#include <string.h>

#include "sorts.h"

// Byte wise swap of two elements of size SIZE
static inline void byte_swap(void *a, void *b, int size)
{
    void *temp = malloc(sizeof(size));
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

/** 
 * Sorts an array using randomized quick sort
 */
void my_qsort(void *base, int start, int end, int size,
              int (*compar)(const void *a, const void *b))
{
    if (start < end)
    {
        // 1 byte alignment
        char *pbase = (char *)base;

        // get random pivot
        int index = start + rand() % (end - start);
        byte_swap(pbase + start * size, pbase + index * size, size);

        // start of the wall
        char *pivot = pbase + start * size;
        int wall = start;

        for (int i = start + 1; i <= end; i++)
        {
            if (compar(pbase + i * size, pivot) < 0)
            {
                wall++;
                byte_swap(pbase + i * size, pbase + wall * size, size);
            }
        }
        // bring pivot to right position
        byte_swap(pivot, pbase + wall * size, size);

        my_qsort(base, start, wall - 1, size, compar);
        my_qsort(base, wall + 1, end, size, compar);
    }
}