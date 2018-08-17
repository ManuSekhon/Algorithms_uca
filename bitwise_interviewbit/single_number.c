/**
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 */

int singleNumber(const int *A, int size)
{
    int num = 0;
    for (int i = 0; i < size; i++)
        num = num ^ A[i];

    return num;
}