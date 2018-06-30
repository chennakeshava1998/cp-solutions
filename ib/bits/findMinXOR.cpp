// https://www.interviewbit.com/problems/min-xor-value/?ref=similar_problems
int Solution::findMinXor(vector<int> &A)
{
    sort(A.begin(), A.end());
    int ans = A[0] ^ A[1];
    for (int i = 1; i < A.size() - 1; ++i)
        ans = min(ans, A[i] ^ A[i + 1]);

    return ans;
}
