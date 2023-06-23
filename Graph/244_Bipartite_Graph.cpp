// 244 Check whether a graph is Bipartite or Not

// Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

#include <bits/stdc++.h>
using namespace std;

// using dfs
// time complexity: O(V+E)
// space complexity: O(V)
bool dfs(int node, vector<int> adj[], vector<int> &color)
{
    if (color[node] == -1)
        color[node] = 1;
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!dfs(it, adj, color))
                return false;
        }
        else if (color[it] == color[node])
            return false;
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, adj, color))
                return false;
        }
    }
}

// using bfs
// time complexity: O(V+E)
// space complexity: O(V)
bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    queue<int> q;
    q.push(0);
    color[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << isBipartite(v, adj);
}