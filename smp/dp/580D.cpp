// http://codeforces.com/problemset/problem/580/D
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

#define MAXN 20
vector<vector<int>> dp(1 << MAXN, vector<int>(MAXN, -1)), benefit(MAXN, vector<int>(MAXN, 0));

int solve(int mask, int prev);

int m; // total number of items that can be bought
vector<int> v;

int main()
{
    int n, k;
    cin >> n >> m >> k;

    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // updating the rules
    while (k--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        benefit[x][y] = c;
    }

    int mask = 0, prev = -1;
    cout << solve(mask, prev) << endl;

    return 0;
}

int solve(int mask, int prev)
{
    // already m items have been bought
    if (__builtin_popcount(mask) == m)
        return 0;

    // this subproblem has already been solved before
    if (dp[mask][prev] != -1)
        return dp[mask][prev];

    // max possible score from this state onwards.
    int ans = -1;
    for (auto i = 0; i < v.size(); ++i)
    {
        // if the i'th item has not already been bought
        if (mask & (1 << i) == 0)
        {
            int prev_reward = 0;
            if (i != -1)
                prev_reward = benefit[prev][i];

            ans = max(ans, solve(mask | (1 << i), i) + v[i] + prev_reward);
        }
    }
    dp[mask][prev] = ans;

    return ans;
}
