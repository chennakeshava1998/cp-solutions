/*
    Problem 2 (Optional, but recommended):
    Given an unsorted integer array, find the first missing positive integer.
    Example:
    Given [1,2,0] return 3,
    [3,4,-1,1] return 2,
    [-8, -7, -6] returns 1.
    Deadline for submission: 17th June, 2018. 11:59 pm
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, x, i, j;

    cin >> m >> n;
    int v[m + 1][n + 1];
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (i = 1; i <= m; ++i)
    {
        for (j = 1; j <= n; ++j)
            cin >> v[i][j];
    }

    if (v[m][n] < 0)
        dp[m][n] = 1 - v[m][n];
    else if (v[m][n] == 0)
        dp[m][n] = 1;
    else
        dp[m][n] = 0;

    // finding dp for the last row; King only moves rightwards.

    i = m;
    for (j = n - 1; j >= 1; --j)
    {
        if (i < n - 1)
            temp = dp[i + 1][j];
        if (j < m - 1)
            temp = min(temp, dp[i][j + 1]);

        dp[i][j] = temp - v[i][j];

        if (v[i][j] < 0 && dp[i][j] < 1 - v[i][j])
            dp[i][j] = 1 - v[i][j];
    }

    return 0;
}