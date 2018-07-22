// reverseFindLen() is not the same as applying findLen with the vector in reverse order. Always cross-check, if such reusability holds true for all cases.
vector<int> findLen(vector<int> v)
{
    vector<int> ans(v.size(), 1);
    for (int i = 0; i < v.size(); ++i)
    {
        int j = i - 1, cnt = 0;

        while (j >= 0)
        {
            if (v[j] < v[i])
                cnt = max(cnt, ans[j]);
            --j;
        }

        ans[i] = cnt + 1;
    }

    return ans;
}

vector<int> reverseFindLen(vector<int> v)
{
    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; --i)
    {
        int cnt = 0, j = i + 1;
        while (j < v.size())
        {
            if (v[j] < v[i])
                cnt = max(cnt, ans[j]);
            ++j;
        }

        ans[i] = cnt + 1;
    }

    return ans;
}

int solve(vector<int> v)
{
    vector<int> ans1 = findLen(v);
    // disp(v);
    // disp(ans1);
    vector<int> ans2 = reverseFindLen(v);

    // disp(ans2);

    int ans = 0;
    for (int i = 0; i < ans1.size(); ++i)
        ans = max(ans, ans1[i] + ans2[i]);

    --ans;

    return ans;
}

int Solution::longestSubsequenceLength(const vector<int> &A)
{
    if (A.empty())
        return 0;
    return solve(A);
}
