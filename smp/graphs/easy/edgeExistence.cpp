#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a, b, q;
    cin >> n >> m;

    // vector<vector<bool>> adjMat(n + 1, vector<bool>(n + 1, (bool)0));
    vector<int> adjMat(n + 1, 0);

    while (m--)
    {
        cin >> a >> b;
        adjMat[a] |= (1 << b);
        adjMat[b] |= (1 << a);
    }

    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        if (adjMat[a] & (1 << b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}