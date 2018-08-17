/**
 * Reverse bits of an 32 bit unsigned integer
 */
#include "bitwise_interviewbit.h"

unsigned int reverse (unsigned int A)
{
    // swap 1 bit, 2 bits, 4 bits, 6 bits and 16 bits
    A = (A & 0xAAAAAAAA) >> 1  | (A & 0x55555555) << 1;
    A = (A & 0xCCCCCCCC) >> 2  | (A & 0x33333333) << 2;
    A = (A & 0xF0F0F0F0) >> 4  | (A & 0x0F0F0F0F) << 4;
    A = (A & 0xFF00FF00) >> 8  | (A & 0x00FF00FF) << 8;
    A = (A & 0xFFFF0000) >> 16 | (A & 0x0000FFFF) << 16;
    return A;
}