int Solution::findMedian(vector<vector<int>> &A)
{
    vector<int> temp;
    int n = A.size(), m = A[0].size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            temp.push_back(A[i][j]);
    }

    A.clear();

    nth_element(temp.begin(), temp.begin() + m * n / 2 + 1, temp.end());

    return temp[m * n / 2 + 1];
}

