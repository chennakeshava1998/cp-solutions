// https://www.interviewbit.com/problems/different-bits-sum-pairwise/
#define MOD (int)(pow(10, 9) + 7)

int Solution::cntBits(vector<int> &A)
{
    // It is incorrect to push the elements into a set. Even if there are duplicate elements, it's necessary to take XOR with other elements.
    int sum = 0;

    // If array contains only one integer
    if (A.size() <= 1)
        return sum;

    // Counts the number of 1's at i'th bit position
    int l = sizeof(int) * 8;
    vector<int> cntOnes(l, 0);

    int i, j;
    for (i = 0; i < l; ++i)
    {
        for (j = 0; j < A.size(); ++j)
        {
            if (A[j] & (1 << i))
                ++cntOnes[i];
        }
        // cout << "i = " << i << "\t" << cntOnes[i] << endl;
    }

    int n = A.size();

    for (i = 0; i < l; ++i)
        sum += (cntOnes[i] * (n - cntOnes[i])) % MOD;

    sum = (sum + sum) % MOD;
    return sum % MOD;
}
