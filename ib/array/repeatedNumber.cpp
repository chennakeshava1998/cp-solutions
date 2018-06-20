// https://www.interviewbit.com/problems/find-duplicate-in-array/
int Solution::repeatedNumber(const vector<int> &A)
{
    /*
    This approach is not possible because the given array is read-only
    sort(A.begin(), A.end());

    for (auto i = 0; i < A.size() - 1; ++i)
    {
        if (A[i] == A[i + 1])
            return A[i];
    }
    */

    vector<bool> v(A.size(), 0);
    for (auto i = 0; i < A.size(); ++i)
    {
        if (v[A[i]] == 1)
            return A[i];
        v[A[i]] = 1;
    }
}
