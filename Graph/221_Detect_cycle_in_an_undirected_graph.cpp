// 221 Detect Cycle in UnDirected Graph using BFS/DFS Algo

// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

// methods to detect cycle in an undirected graph
// 1. DFS
// 2. BFS

#include <bits/stdc++.h>
using namespace std;

// DFS
// Time Complexity: O(V + E), the Time Complexity of this method is the same as the time complexity of DFS traversal which is O(V+E).
// Auxiliary Space: O(V). To store the visited and recursion stack O(V) space is needed.
bool solve(int vertex, int parent, vector<int> &visited, vector<int> adj[])
{
    visited[vertex] = 1;
    for (auto &neigh : adj[vertex])
    {
        if (visited[neigh] == 0)
        {
            if (solve(neigh, vertex, visited, adj) == true)
                return true;
        }
        else if (neigh != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            if (solve(i, -1,visited, adj) == true)
                return true;
        }
    }
    return false;
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
    cout << isCycle(v, g);
}