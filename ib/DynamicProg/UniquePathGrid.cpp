// https://www.interviewbit.com/problems/unique-paths-in-a-grid/
#include <bits/stdc++.h>
using namespace std;

void disp(vector<vector<int>> &A)
{
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < A[0].size(); ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

int numPaths(vector<vector<int>> &A)
{

    if (A.empty())
        return 0;

    vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));
    // dp[0][0] = 1; ==? This stmt will be false if there is an obstacle at (0, 0) itself :P ---> Trivial case correctness

    dp[0][0] = (A[0][0] == 1 ? 0 : 1);
    int i = 1, j = 1;

    for (; i < A.size(); ++i)
    {
        if (A[i][0] == 1)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i - 1][0];
    }

    for (; j < A[0].size(); ++j)
    {
        if (A[0][j] == 1)
            dp[0][j] = 0;
        else
            dp[0][j] = dp[0][j - 1];
    }

    i = 1;
    j = 1;

    /*
    NOTE:
    for (; i < A.size(); ++i)
    {
        for (; j < A[0].size(); ++j)
        {
            if (A[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    These types of loops are dangerous. They do not have explicit initialization statements. So, after the first iteration of the outermost loop, the inner loop will cease to execute. Because, j would have reached the limit in the previous iteration. And there is no initialization to revert that state back. Very Imp!!




    */

    for (i = 1; i < A.size(); ++i)
    {
        for (j = 1; j < A[0].size(); ++j)
        {
            if (A[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    disp(dp);

    return dp[A.size() - 1][A[0].size() - 1];
}

int main()
{

    return 0;
}