// 242 Find bridge in a graph

// Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.

#include<bits/stdc++.h>
using namespace std;

// time complexity: O(V+E)
// space complexity: O(V)

void dfs(int u, vector<int> adj[], vector<int> &discovery, vector<int> &low, vector<int> &visited, int parent, int &timer, vector<vector<int>> &ans)
{
    visited[u] = 1;
    discovery[u] = low[u] = ++timer;
    for (auto v : adj[u])
    {
        if (v == parent)
            continue;
        if (visited[v] == 0)
        {
            dfs(v, adj, discovery, low, visited, u, timer, ans);
            low[u] = min(low[u], low[v]);
            if (low[v] > discovery[u])
            {
                ans.push_back({u, v});
            }
        }
        else
        {
            low[u] = min(low[u], discovery[v]);
        }
    }
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
    vector<int> discovery(V,-1), low(V,-1), visited(V,0);
    int parent = -1;
    int timer = 0;
    vector<vector<int>> ans;
    for (int i = 0; i<V; i++)
    {
        if (visited[i] == 0)
            dfs(i, adj, discovery, low, visited, parent, timer, ans);
    }
    for(auto x: ans)
    {
        if((x[0] == c && x[1] == d) || (x[0] == d && x[1] == c))
            return 1;
    }
    return 0;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int c, d;
    cin >> c >> d;
    cout << isBridge(v, adj, c, d);
}