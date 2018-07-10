void Solution::sortColors(vector<int> &A)
{
    int one = 0, two = 0, zero = 0, i;
    for (i = 0; i < A.size(); ++i)
    {
        if (A[i] == 0)
            ++zero;
        else if (A[i] == 1)
            ++one;
        else
            ++two;
    }

    i=0;
    while (zero)
    {
        A[i] = 0;
        --zero;
        ++i;
    }

    while (one)
    {
        A[i] = 1;
        --one;
        ++i;
    }

    while (two)
    {
        A[i] = 2;
        --two;
        ++i;
    }
}
