/**
 * You are given an array of N positive integers, A1, A2 ,…, AN. 
 * Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N.
 * Return the answer modulo 109+7.
 */

// Example: 2 and 7
// 2: 010
// 7: 111
// First and third bit differ. Hence answer is 2

int cntBits (int *A, int size)
{
    int pairs = 0;
    for (int i = 0; i < 31; i++)
    {
        int one_count = 0;
        for (int j = 0; j < size; j++)
        {
            if (A[j] & (1 << i))
                one_count++;
        }

        pairs += (2 * one_count * (size - one_count));
        pairs %= 1000000007;
    }
    return pairs;
}