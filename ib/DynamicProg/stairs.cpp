// https://www.interviewbit.com/problems/stairs/

int stairs(int);
int Solution::climbStairs(int A)
{
    if (A <= 0)
        return 0;
    else if (A <= 2)
        return A;
    return stairs(A);
}

int stairs(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2; // (1, 1) and (2)

    for (int i = 3; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
} 