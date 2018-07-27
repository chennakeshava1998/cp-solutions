// https://www.interviewbit.com/problems/min-jumps-array/

void disp(vector<int> v)
{
    for (auto u : v)
        cout << u << " ";
    cout << endl;
}

int minJumps(vector<int> &A)
{
    if (A.empty())
        return 0;

    int n = A.size();
    vector<int> dp(n, 1e9);
    dp[n - 1] = 0;

    int i = n - 1, j, k, ans;
    while (i--)
    {
        ans = 1e9;
        j = i + 1;
        k = A[i];

        while ((k--) && j < A.size())
        {
            ans = min(ans, dp[j]);
            ++j;
        }

        if (ans != 1e9)
            dp[i] = ans;
    }

    if (dp[0] == 1e9)
        return -1;

    return dp[0];
}

// approach-2

int minJumps(vector<int> &A)
{
    if (A.empty())
        return 0;

    int steps = 1, maxi = INT_MIN, n = A.size();

    for (int i = 0; i < n; ++i)
    {
        maxi = INT_MIN;
        int j = i + 1, k = A[i], pos = 0;
        while ((k--) && j < A.size())
        {
            if (maxi < A[j])
            {
                maxi = A[j];
                pos = j;
            }
            ++j;
        }

        ++steps;
        i = pos + A[pos] - 1;
    }

    return steps;
}