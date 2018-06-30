#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, n, i, a, b;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for (i = 1; i < n; ++i) // there are only (n - 1) edges in a tree
    {
        cin >> a >> b;
        // undirected edges?
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> x;

    // breadth first search
    vector<int> level(n + 1, -1);
    vector<bool> visited(n + 1, 0);

    queue<int> q;
    q.push(1);
    visited[1] = 1;
    level[1] = 1;

    while (!q.empty())
    {
        int a = q.front();
        q.pop();

        // traversing the neighbours of a
        for (auto u : adj[a])
        {
            if (!visited[u])
            {
                visited[u] = 1;
                q.push(u);
                level[u] = level[a] + 1;
            }
        }
    }

    int cnt = 0;
    for (auto u : level)
    {
        // cout << i << "\t" << u << endl;
        if (u == x)
            ++cnt;
    }

    cout << cnt << endl;

    return 0;
}