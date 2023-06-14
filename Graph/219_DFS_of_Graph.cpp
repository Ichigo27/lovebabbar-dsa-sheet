// 219 Implement DFS Algo

// You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note : Use a recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex, vector<int> &vis, vector<int> adj[], vector<int> &res)
{
    res.push_back(vertex);
    vis[vertex] = 1;
    for (auto &neigh : adj[vertex])
    {
        if (vis[neigh] == 0)
            dfs(neigh, vis, adj, res);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> res, visited(V, 0);
    dfs(0, visited, adj, res);
    return res;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> g[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> nodes = dfsOfGraph(v, g);
    for (auto &node : nodes)
        cout << node << ' ';
}