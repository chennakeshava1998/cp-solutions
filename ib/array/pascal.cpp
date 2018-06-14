int nchoosek(int n, int r);
int nchoosek(int n, int r)
{
    if (n == 0 || r > n)
        return 0;
    if (r == 0 || n == r)
        return 1;

    if (r > n / 2)
        r = n - r;

    int ans = n;
    for (int i = 2; i <= r; ++i)
    {
        ans *= (n - r + 1);
        ans /= i;
    }

    return ans;
}

vector<int> Solution::getRow(int k)
{
    vector<int> ans;
    for (int i = 0; i <= k; ++i)
        ans.push_back(nchoosek(k, i));

    return ans;
}
