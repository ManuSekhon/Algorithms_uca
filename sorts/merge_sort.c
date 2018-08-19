#include <string.h>

#include "sorts.h"

// Merge function for msort
static void merge(void *base, void *aux, int start, int middle, int end, int size,
                  int (*compar)(const void *a, const void *b))
{
    int start_2 = middle + 1;
    int length = end - start + 1;
    int index = start;

    // 1 byte alignment
    char *array = (char *)base;
    char *temp = (char *)aux;

    // both subarrays are filled
    while (start <= middle && start_2 <= end)
    {
        if (compar(array + start * size, array + start_2 * size) <= 0)
        {
            memcpy(temp + index * size, array + start * size, size);
            start++;
        }
        else
        {
            memcpy(temp + index * size, array + start_2 * size, size);
            start_2++;
        }
        index++;
    }

    // first subarray remains
    while (start <= middle)
    {
        memcpy(temp + index * size, array + start * size, size);
        index++;
        start++;
    }

    // second subarray remains
    while (start_2 <= end)
    {
        memcpy(temp + index * size, array + start_2 * size, size);
        index++;
        start_2++;
    }

    // copy temp to original
    for (int i = 0, j = end; i < length; i++, j--)
        memcpy(array + j * size, temp + j * size, size);
}

/**
 * Sorts an array using merge sort
 */
void msort(void *base, void *aux, int start, int end, int size,
           int (*compar)(const void *a, const void *b))
{
    if (start < end)
    {
        int middle = (start + end) >> 1;
        msort(base, aux, start, middle, size, compar);
        msort(base, aux, middle + 1, end, size, compar);
        merge(base, aux, start, middle, end, size, compar);
    }
}