// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

#include <bits/stdc++.h>
using namespace std;

int maxSquareSubMatrix(vector<vector<int>> &A);
int findMaxElement(vector<vector<int>> &A);
vector<vector<int>> inputMatrix(int m, int n);

vector<vector<int>> inputMatrix(int m, int n)
{
    vector<vector<int>> matrix;
    vector<int> temp_buffer;
    int x = 0;
    while (m--)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            temp_buffer.push_back(x);
        }

        matrix.push_back(temp_buffer);
        temp_buffer.clear();
    }

    return matrix;
}

int findMaxElement(vector<vector<int>> &A)
{
    int maximum_element = INT_MIN;

    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[0].size(); ++j)
            maximum_element = max(maximum_element, A[i][j]);

    return maximum_element;
}

int maxSquareSubMatrix(vector<vector<int>> &A)
{
    int m = A.size(), n = A[0].size(), i = 0, j = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // copying the first column as it is.
    for (; i < m; ++i)
        dp[i][0] = A[i][0];

    // copying the first row into dp
    for (; j < n; ++j)
        dp[0][j] = A[0][j];

    for (i = 1; i < m; ++i)
    {
        for (j = 1; j < n; ++j)
        {
            if (A[i][j] == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }

    return findMaxElement(dp);
}

int main()
{
    int t;

    return 0;
}