// https://www.interviewbit.com/problems/single-number-ii/
int Solution::singleNumber(const vector<int> &A)
{
    int ans = 0;
    for (int j = 31; j >= 0; --j)
    {
        int bit = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i] & (1 << j))
                ++bit;
        }

        if (bit % 3)
            ans |= (1 << j);
    }

    return ans;
}
