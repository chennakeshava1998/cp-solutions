// https://www.interviewbit.com/problems/spiral-order-matrix-i/
/*
Does not work for the following input:
A : 
[
  [1]
  [2]
  [3]
]

Your function returned the following :
1 1 2 3 -1 

The expected returned value :
1 2 3 

*/

vector<int> Solution::spiralOrder(const vector<vector<int>> &A)
{
    int i, j, k, m = A.size(), n = A[0].size();
    int col_limit, row_limit;

    vector<int> ans;

    if (n & 1)
        col_limit = (n - 1) / 2 + 1;
    else
        col_limit = n - 1;

    if (m & 1)
        row_limit = (m - 1) / 2 + 1;
    else
        row_limit = m - 1;

    vector<vector<int>> v(m, vector<int>(n, 0));

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
            v[i][j] = A[i][j];
    }
    i = 0;
    j = 0;
    k = 0;

    while (1)
    {
        i = k;
        j = k;

        if (i >= row_limit || j >= col_limit)
            break;

        // cout << "upper: l to r\n";

        if(j == n - k - 1)
        {
            ans.push_back(v[i][j]);
            ++j;
        }

        while (j < n - k - 1)
        {
            // cout << v[i][j] << " ";
            ans.push_back(v[i][j]);
            v[i][j] = -1;
            ++j;
        }

        j = n - 1 - k;
        i = k;
        // cout << "rhs: top to bottom\n";
        while (i < m - 1 - k)
        {
            // cout << v[i][j] << " ";
            ans.push_back(v[i][j]);
            v[i][j] = -1;
            ++i;
        }

        i = m - 1 - k;
        // cout << "bottom row: r to l\n";

        while (j > k)
        {
            // cout << v[i][j] << " ";
            ans.push_back(v[i][j]);
            v[i][j] = -1;
            --j;
        }

        j = k;
        // cout << "left row: bottom to top\n";
        while (i > k)
        {
            ans.push_back(v[i][j]);
            // cout << v[i][j] << " ";
            v[i][j] = -1;
            --i;
        }

        ++k;
    }

    return ans;

    // cout << "done!\n";
}