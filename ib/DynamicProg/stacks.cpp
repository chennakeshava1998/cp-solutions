// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

int stacks(const vector<int> v)
{
    /*
    vector<int> prefix(v.size());
    int n = v.size();
    prefix[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; --i)
        prefix[i] = max(v[i], prefix[i + 1]);

    int ans = INT_MIN;

    for (int i = 0; i < n; ++i)
        ans = max(ans, prefix[i] - v[i]);

    return ans;
    */

    // Instead of using a prefix array, which requires O(N) memory, process from the last and use constant memory!

    int curr_max = INT_MIN, ans = INT_MIN;
    for (int i = n - 1; i >= 0; --i)
    {
        curr_max = max(curr_max, v[i]);
        ans = max(ans, curr_max - v[i]);
    }

    return ans;
}

int Solution::maxProfit(const vector<int> &A)
{
    if (A.size() == 0)
        return 0;
    return stacks(A);
} 