#include <bits/stdc++.h>
using namespace std;
#define MOD ((int)pow(10, 9) + 7)

vector<vector<int>> dp(pow(10, 3) + 1, vector<int>(pow(10, 3) + 1, -1));

long long int nchoosek(long long int n, long long int k)
{
    if (n < k)
        return 0;

    if (k == 0 || (n == k))
        return 1;

    if (k > (n - k))
        k = n - k;

    if (dp[n][k] != -1)
        return dp[n][k];

    long long int ans = (nchoosek(n - 1, k) % MOD + nchoosek(n - 1, k - 1) % MOD) % MOD;

    dp[n][k] = ans % MOD;
    dp[n][n - k] = ans % MOD;

    return dp[n][k];
}

int main()
{
    int t, n, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> r;
        cout << nchoosek(n, r) << "\n";
    }

    return 0;
}