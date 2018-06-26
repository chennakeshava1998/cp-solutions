int Solution::reverse(int A)
{
    int temp = A, ans = 0, rem;

    if (A < 0)
        temp = -temp;

    while (temp)
    {
        rem = temp % 10;
        if (ans * 10 > INT_MAX)
            return 0;

        ans = ans * 10;

        if (ans + rem > INT_MAX)
            return 0;

        ans += rem;
        temp /= 10;
    }

    return (A < 0) ? -ans : ans;
}
