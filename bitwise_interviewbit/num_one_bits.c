/** 
 * Write a function that takes an unsigned integer
 * and returns the number of 1 bits it has.
 */

#include "bitwise_interviewbit.h"

int numSetBits (unsigned int A)
{
    int count = 0;
    int x = A;

    // keep turning rightmost one bit off while keeping count
    while (x != 0)
    {
        count++;
        x = x & (x - 1);
    }

    return count;

    // Alternatively, use GCC extension
    // return __builtin_popcount(A);
}