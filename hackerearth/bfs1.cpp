// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

// perform bfs, find the nearest neighbor to node-1.

#include <bits/stdc++.h>
using namespace std;

int minDist(vector<vector<int>> adj)
{
    int n = adj.size();
    vector<int> dist(n);
    vector<bool> visited(n, 0);

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    visited[1] = 1;

    while (!q.empty())
    {
        auto a = q.front();
        q.pop();

        for (auto b : adj[a])
        {
            if (visited[b] == false)
            {
                visited[b] = true;
                dist[b] = dist[a] + 1;
                q.push(b);
            }
        }
    }

    return dist[n - 1];
}

int main()
{
    int t, n, x, y, m;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);

        while (m--)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cout << minDist(adj) << endl;
    }

    return 0;
} 