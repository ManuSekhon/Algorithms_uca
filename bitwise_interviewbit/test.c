#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include "bitwise_interviewbit.h"

void test_min_xor(void)
{
    int a[] = {0, 2, 5, 7};
    int b[] = {0, 4, 7, 9};
    assert(findMinXor(a, 4) == 2);
    assert(findMinXor(b, 4) == 3);
    printf("Passed: findMinXor\n");
}

void test_num_one_bits(void)
{
    assert(numSetBits(11) == 3);
    assert(numSetBits(64) == 1);
    assert(numSetBits(INT_MAX) == 31);
    printf("Passed: num_one_bits\n");
}

void test_reverse_bits(void)
{
    assert(reverse(0) == 0);
    assert(reverse(45) == 3019898880);
    assert(reverse(3) == 3221225472);
    printf("Passed: reverse_bits\n");
}

void test_integer_divide(void)
{
    assert(divide(5, 2) == 2);
    assert(divide(INT_MIN, -1) == INT_MAX);
    assert(divide(-1, 1) == -1);
    printf("Passed: integer_divide\n");
}

int main (void)
{
    test_min_xor();
    test_num_one_bits();
    test_reverse_bits();
    test_integer_divide();
}