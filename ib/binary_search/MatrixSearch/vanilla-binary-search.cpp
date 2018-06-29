int Solution::searchMatrix(vector<vector<int>> &A, int B)
{
    // The entire 2d vector, if collapsed into a 1d vector, would still be sorted.

    int m = A.size(), n = A[0].size(), l = 0, r = m * n - 1, mid;

    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (A[mid / m][mid % n] == B)
            return 1;
        else if (A[mid / m][mid % n] > B)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return 0;
}