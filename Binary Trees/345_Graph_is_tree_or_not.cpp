// 345 Check if given graph is tree or not.  [ IMP ]

// Write a function that returns true if a given undirected graph is a tree and false otherwise. For example, the following graph is a tree.

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Check if the graph is connected and there is no cycle.
// Time Complexity: O(V+E)
// Space Complexity: O(V)

// bool dfs(int node, int prev, vector<int> adj[], vector<bool> &visited)
// {
//     visited[node] = true;
//     for (auto it : adj[node])
//     {
//         if (!visited[it])
//         {
//             if (dfs(it, node, adj, visited))
//                 return true;
//         }
//         else if (it != prev)
//             return true;
//     }
//     return false;
// }


// bool isConnectedAndNoCycles(int V, vector<int> adj[])
// {
//     vector<bool> visited(V, false);
//     if(dfs(0, -1, adj, visited))
//         return false;
//     for (int i = 0; i < V; i++)
//         if (!visited[i])
//             return false;
//     return true;
// }

// bool isTree(int V, vector<int> adj[])
// {
//     return isConnectedAndNoCycles(V, adj);
// }


// Approach 2: Check if the graph is connected and there is V-1 edges.
// Time Complexity: O(V+E)
// Space Complexity: O(V)

void dfs(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
    for (auto it : adj[node])
        if (!visited[it])
            dfs(it, adj, visited);
}

bool isConnected(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    dfs(0, adj, visited);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            return false;
    return true;
}

bool isTree(int V, vector<int> adj[])
{
    if (!isConnected(V, adj))
        return false;
    int edges = 0;
    for (int i = 0; i < V; i++)
        edges += adj[i].size();
    return edges / 2 == V - 1;
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
        adj[v].push_back(u); // Comment this line for directed graph
    }
    cout << isTree(v, adj);
}