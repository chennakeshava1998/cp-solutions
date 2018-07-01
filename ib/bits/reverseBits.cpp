unsigned int Solution::reverse(unsigned int A)
{
    // Solution-1: Traverse through all 32 bits. Keep a separate copy
    /*
    int ans = 0, int j = 31;
    for (int i = 0; i < 32, j >= 0; ++i, --j)
    {
        if ((1 << i) & A)
            ans |= (1 << j);
    }

    return ans;

    */

    // Solution-2: Inplace swapping using XOR: Doesn't work correctly
    // More generic approach. Some datatypes may have more than 32 bits, it could be implementation specific
    int n = sizeof(A) * 8;
    for (int i = 0; i < n / 2; ++i)
    {
        if ((A & (1 << i)) != (A & (1 << (n - 1 - i))))
        {
            A ^= (1 << i);
            A ^= (1 << (31 - i));
        }
    }

    return A;
}
