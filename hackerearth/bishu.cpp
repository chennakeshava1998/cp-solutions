// https://www.hackerearth.com/zh/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

// perform bfs, find the nearest neighbor to node-1.

#include <bits/stdc++.h>
using namespace std;

int findGF(vector<vector<int>> adj, vector<int> girlLoc);

int findGF(vector<vector<int>> adj, vector<int> girlLoc)
{
    // bfs
    vector<bool> visited(adj.size(), 0);
    vector<int> dist(adj.size(), 1e9);

    dist[1] = 0;
    visited[1] = 1;

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        // there is no top() for a queue. It is only relevant for a stack
        auto a = q.front();
        q.pop();

        for (auto b : adj[a])
        {
            if (visited[b] == false)
            {
                q.push(b);
                dist[b] = dist[a] + 1;
                visited[b] = true;
            }
        }
    }

    // finding minimum
    int ans = 1e9, id = 1e9;

    sort(girlLoc.begin(), girlLoc.end());
    for (auto i = 0; i < girlLoc.size(); ++i)
    {
        if (dist[girlLoc[i]] < ans)
        {
            ans = dist[girlLoc[i]];
            id = girlLoc[i];
        }
    }

    return id;
}

int main()
{
    long long int n, q, x, u, v;
    cin >> n;

    // 1-based indexing, hence the size is (n+1)
    vector<vector<int>> adj(n + 1);
    vector<int> girlLoc;

    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> q;
    while (q--)
    {
        cin >> x;
        girlLoc.push_back(x);
    }

    cout << findGF(adj, girlLoc) << endl;
    return 0;
}