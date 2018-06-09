// O(n^2) solution

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long

ll calcMinJumps();

int main()
{
    ll t;
    cin >> t;

    while(t--)
        cout << calcMinJumps() << "\n";

    return 0;
}

ll calcMinJumps()
{
    ll n, x, i;
    cin >> n;
    vector<ll>v;

    while(n--)
    {
        cin >> x;
        v.pb(x);
    }

    ll l = v.size();

    vector<ll>dp(l);
    dp[l-1] = 0;

    for(ll i=l-2;i >= 0; --i)
    {
        /*
        1
        10
        2 3 1 1 2 4 2 0 1 1

        Just because there is a 0, we cannot return -1. We could very well jump over the 0th position
        */
        if(v[i] == 0)
            dp[i] = 1000;
        else
            dp[i] = 1 + *min_element(dp.begin() + i + 1, dp.begin() + i + v[i] + 1);
    }
    return (dp[0] > 1000 ? -1 : dp[0]); // Do not test for equality! Test cases will fail
}



