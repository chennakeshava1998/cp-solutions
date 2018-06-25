int Solution::trailingZeroes(int A)
{
    int ans = 0, p = 5;

    while (A / p)
    {
        ans += A / p;
        p *= 5;
    }

    return ans;
}
