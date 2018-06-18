// https://www.hackerearth.com/problem/algorithm/vaishu-and-tower-arrangements/description/

#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int minReplace(vector<int>);
int main()
{
    int t, n, x;

    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v;
        while (n--)
        {
            cin >> x;
            v.push_back(x);
        }

        cout << minReplace(v) << endl;
    }

    return 0;
}

int minReplace(vector<int> v)
{
    int cnt = 0, i, n = v.size(), val = 1e9;
    if (v[0] != -1)
        ++cnt;

    if (v[n - 1] != 1)
        ++cnt;

    vector<int> dp1(n), dp2(n);

    // dp1[i] has the cumulative count of -1's to the RHS of index i, not including index-i

    v[0] = -1;
    v[n - 1] = 1;

    // for (auto u : v)
    //     cout << u << " ";
    // cout << endl;

    dp1[n - 1] = 0;
    for (i = n - 2; i >= 0; --i)
    {
        if (v[i + 1] == -1)
            dp1[i] = dp1[i + 1] + 1;
        else
            dp1[i] = dp1[i + 1];
    }

    // dp2[i] has the cumulative count of 1's to the LHS of index i, not including index-i

    dp2[0] = 0;
    for (i = 1; i < n; ++i)
    {
        if (v[i - 1] == 1)
            dp2[i] = dp2[i - 1] + 1;
        else
            dp2[i] = dp2[i - 1];
    }

    // dp1[i] + dp2[i] tells the number of changes need to be done, if i is the margin of separation.

    for (i = 0; i < n; ++i)
    {
        if (dp1[i] + dp2[i] < val)
            val = dp1[i] + dp2[i];
    }

    

    // for (auto u : dp1)
    //     cout << u << " ";
    // cout << endl;

    // for (auto u : dp2)
    //     cout << u << " ";
    // cout << endl;

    return (cnt + val);
}
