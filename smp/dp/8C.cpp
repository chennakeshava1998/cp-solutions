// TODO: Memory Constraint, this answer will not pass. 
// Include memoization
// Find a way to update the answer array.

#include <bits/stdc++.h>
using namespace std;

// int dp[1 << 25][25], n;

int sq_dist(pair<int, int> x, pair<int, int> y)
{
    return pow(x.first - y.first, 2) + pow(x.second - y.second, 2);
}

int n;
vector<vector<int>> dp;
pair<int, int> start;
vector<pair<int, int>> address;
vector<int> ans; // contains the final ordering of vertices.

int func(int mask, int obj, pair<int, int> p)
{
    if (obj == 2) // can only take atmost 2 objects
        return sq_dist(p, start);

    // already taken n objects. This case doesn't arise.
    if (__builtin_popcount(mask) == n)
        return 0;

    int ans = 1e9;

    for (auto i = 0; i < n; ++i)
    {
        if (mask && (1 << i) == 0) // item-i has not already been selected
            ans = min(ans, func(mask | (1 << i), obj + 1, address[i]) + sq_dist(p, address[i]));
    }

    // go back to the hand bag
    ans = min(ans, func(mask, 0, start) + sq_dist(p, start));
}

int main()
{
    // input
    int x, y;
    cin >> x >> y;
    start.first = x;
    start.second = y;

    cin >> n;
    // resizing the appropriate vectors
    dp.resize(1 << n, vector<int>(n, -1));
    while (n--)
    {
        cin >> x >> y;
        address.push_back({x, y});
    }

    ans.push_back(0);

    int distance = func(0, 0, start);

    // before printing the final order, push 0'th node into the ans array
    ans.push_back(0);

    for (auto u : ans)
        cout << u << " ";
    cout << endl;

    return 0;
}
