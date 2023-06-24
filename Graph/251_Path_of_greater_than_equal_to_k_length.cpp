// 251 Find if there is a path of more thank length from a source

// Given a graph, a source vertex in the graph, and a number k, find if there is a simple path, of path length greater than or equal to k,(without any cycle) starting from a given source and ending at any other vertex.
// Source vertex should always be  0.

#include <bits/stdc++.h>
using namespace std;

// time complexity: O(V+E)
// space complexity: O(V)

bool dfs(int src, vector<pair<int, int>> adj[], vector<bool> &vis, int k)
{
    if (k <= 0)
        return true;
    vis[src] = true;
    for (auto x : adj[src])
    {
        if (!vis[x.first])
        {
            if (x.second >= k)
                return true;
            if (dfs(x.first, adj, vis, k - x.second))
                return true;
        }
    }
    vis[src] = false;
    return false;
}

bool pathMoreThanK(int V, int E, int k, int *a)
{
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < 3 * E; i += 3)
    {
        adj[a[i]].push_back({a[i + 1], a[i + 2]});
        adj[a[i + 1]].push_back({a[i], a[i + 2]});
    }
    vector<bool> vis(V, false);
    return dfs(0, adj, vis, k);
}

int main()
{
    int v, e, k;
    cin >> v >> e >> k;
    int arr[3 * e];
    for (int i = 0; i < 3 * e; i += 3)
    {
        cin >> arr[i] >> arr[i + 1] >> arr[i + 2];
    }
    cout << pathMoreThanK(v, e, k, arr);
}