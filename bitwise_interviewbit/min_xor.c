/**
 * Given an array of N integers, find the pair of integers in the array 
 * which have minimum XOR value. Report the minimum XOR value.
 */

#include <limits.h>
#include <stdlib.h>

#include "bitwise_interviewbit.h"

// compare function for qsort
int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int findMinXor(int *A, int size)
{
    // sort the array
    qsort(A, size, sizeof(int), compare);

    // minimum xor of consecutive elements
    int min_xor = INT_MAX;
    for (int i = 0; i < size - 1; i++)
    {
        if ((A[i] ^ A[i + 1]) < min_xor)
            min_xor = A[i] ^ A[i + 1];
    }

    return min_xor;
}