#include <stdlib.h>
#include <string.h>

#include "sorts.h"

/**
 * Sorts an array using insertion sort
 */
void isort(void *base, int start, int end, int size, int (*compar)(const void *a, const void *b))
{
    // 1 byte alignment
    char *pbase = base;
    void *element = malloc(sizeof(size));

    for (int i = start + 1; i <= end; i++)
    {
        memcpy(element, pbase + i * size, size);
        int j = i - 1;

        // shift elements
        while (j >= 0 && compar(pbase + j * size, element) > 0)
        {
            memcpy(pbase + (j + 1) * size, pbase + j * size, size);
            j--;
        }
        memcpy(pbase + (j + 1) * size, element, size);
    }
    free(element);
}