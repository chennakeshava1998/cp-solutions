/*
Stock Prices input: 3 7 9
    I am assuming that, we can sell 7 on the second day, and then buy it again. Because atmost 2 transactions are permitted, and we are not purchasing multiple stocks.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, i;
    cin >> n;
    vector<int> prices;
    while (n--)
    {
        cin >> x;
        prices.push_back(x);
    }

    n = prices.size();

    vector<int> left(n), right(n);
    // left[i] holds the profit possible from 0...i (both inclusive)
    // right[i] holds the profit possible from (i+1)....(n-1)

    left[0] = 0;
    int curr_min = prices[0];
    for (i = 1; i < left.size(); ++i)
    {
        curr_min = min(curr_min, prices[i]);
        left[i] = max(left[i - 1], prices[i] - curr_min);
    }

    int curr_max = prices[n - 1];
    right[n - 1] = 0;

    for (i = n - 2; i >= 0; --i)
    {
        curr_max = max(curr_max, prices[i]);
        right[i] = max(right[i + 1], curr_max - prices[i]);
    }

    int ans = INT_MIN;
    for (i = 0; i < n; ++i)
        ans = max(ans, left[i] + right[i]);

    cout << ans << endl;

    return 0;
}