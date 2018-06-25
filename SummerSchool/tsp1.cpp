#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, m, k;
vector<pair<int, int>> to_swap;

int main()
{
    int i, x, y;
    cin >> n >> m >> k;

    vector<int> A(n + 1);
    for (i = 1; i <= n; ++i)
        A[i] = i;

    for (auto j = 0; j < m; ++j)
    {
        cin >> x >> y;
        to_swap.push_back({x, y});
        swap(A[x], A[y]);
    }

    auto p = find(A.begin(), A.end(), 1);
    int j = p - A.begin();

    // search for (k, j) in the to_swap vector
    for (i = 0; i < to_swap.size(); ++i)
    {
        if (to_swap[i].first == k && to_swap[i].second == j)
            break;
    }

    cout << i + 1 << endl;

    return 0;
}