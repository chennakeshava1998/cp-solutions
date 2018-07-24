/*
int profit(vector<int> v)
{
    vector<int> dp(v.size(), 0);
    int max_dp = 0, pos = v.size() - 1;
    int i, j, n = v.size();
    dp[n - 1] = 0;

    for (i = n - 2; i >= 0; --i)
    {
        dp[i] = max(dp[i + 1], max_dp - v[i] + v[pos]);

        if (dp[i] > max_dp)
            pos = i;
        max_dp = max(max_dp, dp[i]);
    }
    return dp[0];
}
*/

int profit(vector<int> v)
{
    int ans = 0;

    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i + 1] > v[i])
            ans += (v[i + 1] - v[i]);
    }

    return ans;
}

int Solution::maxProfit(const vector<int> &A)
{
    if (A.empty())
        return 0;
    return profit(A);
}
