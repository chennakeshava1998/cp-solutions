int Solution::reverse(int A)
{
    int temp = A, ans = 0, prev = ans, rem;

    if (A < 0)
        temp = -temp;

    while (temp)
    {
        rem = temp % 10;
        if (ans * 10 > INT_MAX)
            return 0;

        ans = ans * 10;
        if (ans < prev)
            return 0;

        if (ans + rem > INT_MAX)
            return 0;

        ans += rem;

        if (ans < prev)
            return 0;
        
        temp /= 10;
    }

    return (A < 0) ? (-1 * ans) : ans;
}
