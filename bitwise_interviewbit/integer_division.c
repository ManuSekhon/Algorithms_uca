/**
 * Divide two integers without using multiplication, division and mod operator.
 * Return the floor of the result of the division.
 */

#include <limits.h>
#include <stdlib.h>

#include "bitwise_interviewbit.h"

int divide(int A, int B)
{
    // integer flow if INT_MIN / -1
    if (labs(A) > INT_MAX && B == -1)
        return INT_MAX;

    // absolute value
    long int dividend = labs(A);
    long int divisor = labs(B);

    int quotient = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((divisor << i) <= dividend)
        {
            quotient = quotient | (1 << i);
            dividend = dividend - (divisor << i);
        }
    }

    return (A > 0 && B < 0) || (A < 0 && B > 0) ? -quotient : quotient;
}
