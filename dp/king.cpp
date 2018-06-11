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

// helper function to display the contents of dp 2d array
void disp(vector<vector<int>> dp);

int main()
{
    int m, n, x, i, j, temp;

    cin >> m >> n;
    // m = no. of rows in the grid.
    // n = no. of columns in the grid.

    // v array contains the input grid
    int v[m + 1][n + 1];

    // If the king is dropped at (i, j), what is the minimum health required for him to reach (m, n) ?? This value is held by dp[i][j]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (i = 1; i <= m; ++i)
    {
        for (j = 1; j <= n; ++j)
            cin >> v[i][j];
    }

    // If the v(m, n) < 0, then if the king is dropped at (m, n), then he must have atleast one greater point than v(m, n) to survive.
    // Assuming the health of king >= 1 always
    if (v[m][n] < 0)
        dp[m][n] = 1 - v[m][n];
    else if (v[m][n] == 0)
        dp[m][n] = 1;
    else
        dp[m][n] = 0;

    // To fill dp[i][j], we need dp values from the right and bottom cells. This mandates a diagonal bottom-left to upward-right movement like: (m, n), (m, n-1), (m-1, n), (m-2, n-2), (m-1, n-1), etc

    // I couldn't think of an elegant way for this traversal. So I thought of filling up the last row and column first. Then filling up row-wise/col-wise from the pen-ultimate row/column respectively.

    // finding dp for the last row; King only moves rightwards.
    i = m;
    for (j = n - 1; j >= 1; --j)
    {
        temp = 1e9;
        if (i <= m - 1)
            temp = dp[i + 1][j];
        if (j <= n - 1)
            temp = min(temp, dp[i][j + 1]);

        dp[i][j] = temp - v[i][j];

        if (v[i][j] < 0 && dp[i][j] < 1 - v[i][j])
            dp[i][j] = 1 - v[i][j];

        if (dp[i][j] < 0 && v[i][j] > 0)
            dp[i][j] = 0;
        else if (dp[i][j] < 0)
            dp[i][j] = 1;
    }

    // Traversing the last column: King only moves downwards
    j = n;
    for (i = m - 1; i >= 1; --i)
    {
        temp = 1e9;
        if (i <= m - 1)
            temp = dp[i + 1][j];
        if (j <= n - 1)
            temp = min(temp, dp[i][j + 1]);

        dp[i][j] = temp - v[i][j];

        if (v[i][j] < 0 && dp[i][j] < 1 - v[i][j])
            dp[i][j] = 1 - v[i][j];

        if (dp[i][j] < 0 && v[i][j] > 0)
            dp[i][j] = 0;
        else if (dp[i][j] < 0)
            dp[i][j] = 1;
    }

    // Now traverse from m-1, n-1: covering complete rows in one iteration

    for (i = m - 1; i >= 1; --i)
    {
        for (j = n - 1; j >= 1; --j)
        {
            temp = 1e9;
            if (i <= m - 1)
                temp = dp[i + 1][j];
            if (j <= n - 1)
                temp = min(temp, dp[i][j + 1]);

            dp[i][j] = temp - v[i][j];

            if (v[i][j] < 0 && dp[i][j] < 1 - v[i][j])
                dp[i][j] = 1 - v[i][j];

            if (dp[i][j] < 0 && v[i][j] > 0)
                dp[i][j] = 0;
            else if (dp[i][j] < 0)
                dp[i][j] = 1;
        }
    }

    disp(dp);

    cout << "Final Answer: " << dp[1][1] << endl;

    return 0;
}

void disp(vector<vector<int>> dp)
{
    cout << "\n\nContents of dp array:\n";
    for (int i = 1; i < dp.size(); ++i)
    {
        for (int j = 1; j < dp[0].size(); ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << "\n\n";
}