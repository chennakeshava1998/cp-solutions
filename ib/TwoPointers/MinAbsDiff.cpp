int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int i = 0, j = 0, k = 0, minDiff = 1e9;

    while (1)
    {
        int maxi = (max(A[i], max(B[j], C[k])));
        int mini = (min(A[i], min(B[j], C[k])));

        minDiff = min(minDiff, maxi - mini);

        if ((maxi - mini) == 0)
            break;

        if (A[i] == mini && (i < (A.size() - 1)))
            ++i;
        else if (A[i] == mini && (i == (A.size() - 1)))
            break;
        else if (B[j] == mini && (j < (B.size() - 1)))
            ++j;
        else if (B[j] == mini && (j == (B.size() - 1)))
            break;
        else if (k < (C.size() - 1))
            ++k;
        else if (k == (C.size() - 1))
            break;
    }

    return minDiff;
}