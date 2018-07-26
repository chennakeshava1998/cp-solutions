
int minSumPath(vector<vector<int>>);

void disp(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[0].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int minSumPath(vector<vector<int>> A)
{
    vector<vector<int>> dp(A.size(), vector<int>(A[0].size()));
    int i = 1, j = 1;
    dp[0][0] = A[0][0];

    // first row
    for (; i < A[0].size(); ++i)
        dp[0][i] = dp[0][i - 1] + A[0][i];

    // first column
    for (; j < A.size(); ++j)
        dp[j][0] = dp[j - 1][0] + A[j][0];

    for (i = 1; i < A.size(); ++i)
        for (j = 1; j < A[0].size(); ++j)
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + A[i][j];

    return dp[A.size() - 1][A[0].size() - 1];
}

int Solution::minPathSum(vector<vector<int>> &A)
{
    if (A.empty())
        return 0;
    return minSumPath(A);
}
