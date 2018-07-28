int minSumPath(vector<vector<int>> A)
{
    vector<vector<int>> dp = A;
    int i, j;

    for (i = 1; i < dp.size(); ++i)
    {
        for (j = 0; j < dp[i].size(); ++j)
        {
            int temp_sum = 1e9;
            if (j < dp[i - 1].size())
                temp_sum = dp[i - 1][j];

            if (j >= 1)
                temp_sum = min(temp_sum, dp[i - 1][j - 1]);

            dp[i][j] = temp_sum + A[i][j];
        }
    }

    return *min_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
}