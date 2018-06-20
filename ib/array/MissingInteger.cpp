// https://www.interviewbit.com/problems/first-missing-integer/

int Solution::firstMissingPositive(vector<int> &A)
{
    sort(A.begin(), A.end());
    int k = 1;
    for (auto i = 0; i < A.size(); ++i)
    {
        if (A[i] <= 0)
            continue;

        if (A[i] == k)
        {
            while (A[i + 1] == k)
                ++i;
            ++k;
        }
        else
            return k;
    }

    return k;
}
