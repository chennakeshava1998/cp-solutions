#include <bits/stdc++.h>
using namespace std;

int func(vector<int> v);

int main()
{
    int t, n, x;
    cin >> t;

    while (t--)
    {
        vector<int> v;
        cin >> n;
        while (n--)
        {
            cin >> x;
            v.push_back(x);
        }

        cout << func(v) << endl;
    }

    return 0;
}

int func(vector<int> v)
{
    int i, j, n = v.size();
    vector<int> dp(n);
    stack<int> st;

    for (i = 0; i < n; ++i)
    {
        while (!st.empty() && v[st.top()] <= v[i])
            st.pop();

        if (st.empty())
            dp[i] = -1;
        else
            dp[i] = st.top();

        st.push(i);
    }

    for (i = 0; i < n; ++i)
        dp[i] = i - dp[i];

    return *max_element(dp.begin(), dp.end());
}