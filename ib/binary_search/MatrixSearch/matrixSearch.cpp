// https://www.interviewbit.com/problems/matrix-search/
// O(m*log(n)); m = # of rows, n = # of columns

int Solution::searchMatrix(vector<vector<int>> &A, int B)
{
    int m = A.size(), n = A[0].size();
    for (auto i = 0; i < m; ++i)
    {
        if (A[i][0] > B)
            return 0;

        if (A[i][n - 1] < B)
            continue;

        if (binary_search(A[i].begin(), A[i].end(), B))
            return 1;
    }

    return 0;
}
