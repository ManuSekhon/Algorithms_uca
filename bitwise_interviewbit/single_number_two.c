/**
 * Given an array of integers, every element appears thrice except for one
 * which occurs once. Return that number.
 */

int single_number_two(int *A, int size)
{
    int num = 0;
    for (int i = 0; i < 31; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (A[j] & (1 << i))
                count++;
        }
        if (count % 3 != 0)
        {
            num = num | (1 << i);
        }
    }
    return num;
}

