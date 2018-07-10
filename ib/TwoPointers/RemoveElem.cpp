// https://www.interviewbit.com/problems/remove-element-from-array/
int Solution::removeElement(vector<int> &A, int B)
{
    int cnt = 0, i;
    for (i = 0; i < A.size(); ++i)
    {
        if (A[i] == B)
            A[i] = 1e9;
    }

    sort(A.begin(), A.end());

    for (i = 0; A[i] != 1e9; ++i)
        cout << A[i] << " ";
    cout << endl;

    return i;
}
