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

void test_single_number(void)
{
    int a[] = {1, 2, 2, 3, 1};
    int b[] = {5, 5, 2, 2, 1, 1, 7};
    int c[] = {
        723, 256, 668, 723, 140, 360, 597, 233, 128, 845, 737, 804, 986, 701,
        906, 512, 845, 510, 510, 227, 430, 701, 366, 946, 464, 619, 946, 627,
        209, 771, 424, 555, 959, 711, 530, 937, 716, 261, 505, 658, 706, 140,
        511, 277, 396, 233, 819, 196, 475, 906, 583, 261, 147, 658, 517, 197,
        196, 702, 944, 711, 128, 555, 149, 483, 530, 291, 716, 258, 430, 464,
        601, 749, 149, 415, 802, 573, 627, 771, 660, 601, 360, 986, 291, 51,
        415, 51, 227, 258, 937, 366, 923, 669, 33, 517, 417, 702, 475, 706,
        110, 417, 275, 804, 500, 473, 746, 973, 669, 275, 973, 147, 817, 657,
        277, 923, 144, 660, 197, 511, 793, 893, 944, 505, 322, 817, 586, 512,
        322, 668, 33, 424, 962, 597, 144, 746, 345, 753, 345, 269, 819, 483,
        368, 802, 573, 962, 583, 615, 208, 209, 269, 749, 256, 657, 619, 893,
        959, 473, 753, 299, 396, 299, 500, 368, 586, 110, 793, 737, 615};
    assert(singleNumber(a, 5) == 3);
    assert(singleNumber(b, 7) == 7);
    assert(singleNumber(c, 167) == 208);
    printf("Passed: singleNumber\n");
}

void test_cntBits(void)
{
    int a[] = {2, 7};
    int b[] = {1, 3, 5};
    assert(cntBits(a, 2) == 4);
    assert(cntBits(b, 3) == 8);
    printf("Passed: diff_bits_sum_pairwise\n");
}

void test_single_number_two(void)
{
    int a[] = {1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
    assert(single_number_two(a, 10) == 4);
    printf("Passed: single_number_two\n");
}

int main(void)
{
    test_min_xor();
    test_num_one_bits();
    test_reverse_bits();
    test_integer_divide();
    test_single_number();
    test_cntBits();
    test_single_number_two();
}