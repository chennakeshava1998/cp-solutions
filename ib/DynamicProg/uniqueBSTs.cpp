// quadratic solution
int uniqueBSTs(int A)
{
    // important to initialize with 0, because I am using dp[i] as accumulator variables 

    vector<int> dp(A + 1, 0);
    int i, j;

    dp[0] = 1;
    dp[1] = 1;

    for (i = 2; i <= A; ++i)
    {
        for (j = 1; j <= i; ++j)
            dp[i] = dp[i] + dp[j - 1] * dp[i - j];
    }

    return dp[A];
}