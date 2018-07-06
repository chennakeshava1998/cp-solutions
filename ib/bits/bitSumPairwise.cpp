// https://www.interviewbit.com/problems/different-bits-sum-pairwise/
#define MOD (int)(pow(10, 9) + 7)

int sumOnes(int i, int j)
{
    return __builtin_popcount(i ^ j) % MOD;
}

int Solution::cntBits(vector<int> &A)
{
    // It is incorrect to push the elements into a set. Even if there are duplicate elements, it's necessary to take XOR with other elements.
    int sum = 0;

    vector<int>::iterator i = A.begin(), j = i;

    // If array contains only one integer
    if (A.size() <= 1)
        return sum;

    for (i = A.begin(); i != A.end(); ++i)
    {
        for (j = i + 1; j != A.end(); ++j)
            sum = (sum + (sumOnes(*i, *j)) % MOD) % MOD;
    }

    sum = (sum + sum) % MOD;
    return sum % MOD;
}
