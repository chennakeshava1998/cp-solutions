#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
void dfs(int s)
{
    visited[s] = 1;

    for (auto u : adj[s])
    {
        if (visited[u] == 0)
            dfs(u);
    }
}

int main()
{
    int x, n, i, a, b, m;
    cin >> n >> m;
    adj.resize(n + 1);

    for (i = 0; i < m; ++i) // m edges in the graph
    {
        cin >> a >> b;
        // undirected edges?
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> x;
    visited.resize(n + 1, 0);

    // start dfs from the special node x, not from 1!!
    dfs(x); // numbering from 1 to N, INITIALIZE properly!
    visited[x] = 1;

    int cnt = 0;
    // start counting from index-1, index-0 is not considered
    for (i = 1; i < visited.size(); ++i)
    {
        // cout << u << " ";
        if (visited[i] == 0)
            ++cnt;
    }

    cout << cnt << endl;

    return 0;
}