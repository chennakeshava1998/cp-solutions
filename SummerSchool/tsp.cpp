#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, m, k;
vector<pair<int, int>> to_swap;
vector<vector<int>> v;

void perform_swap(int remov);

void perform_swap(int remov)
{
    int i;
    vector<int> A(n + 1);
    for (i = 1; i <= n; ++i)
        A[i] = i;

    for (i = 0; i < m; ++i)
    {
        if (i == remov)
            continue;

        swap(A[to_swap[i].first], A[to_swap[i].second]);
    }

    v.push_back(A);
}

int func()
{
    int i, j;
    for (i = 0; i < m; ++i)
    {
        perform_swap(i);
    }

    for (i = 0; i < v.size(); ++i)
    {
        if (v[i][k] == 1)
            return i + 1;
    }

    cout << "could not find the answer!\n";
    return m;
}

int main()
{
    int i, x, y;
    cin >> n >> m >> k;

    for (auto j = 0; j < m; ++j)
    {
        cin >> x >> y;
        to_swap.push_back({x, y});
    }

    cout << func() << endl;

    return 0;
}