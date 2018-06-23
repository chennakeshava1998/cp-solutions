int Solution::titleToNumber(string A)
{
    int ans = 0;
    for (auto i = 0; i < A.size(); ++i)
    {
        char c = A[i];
        ans += ((pow(26, A.size() - 1 - i)) * (c - 'A' + 1));
    }

    return ans;
}
