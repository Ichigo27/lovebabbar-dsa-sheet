// 243 Count Strongly Connected Components (Kosaraju Algo)

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

#include <bits/stdc++.h>
using namespace std;

// Kosaraju's Algorithm
// https://www.youtube.com/watch?v=ndfjV_yHpgQ
// time complexity: O(V+E)
// space complexity: O(V+E) + O(V) + O(V) + O(V) + O(V) = O(V+E)

void dfs(int src, vector<int> adj[], stack<int> &st, vector<bool> &visited)
{
    visited[src] = true;
    for (int i : adj[src])
    {
        if (!visited[i])
        {
            dfs(i, adj, st, visited);
        }
    }
    st.push(src);
}

void revdfs(int src, vector<int> adj[], vector<bool> &visited)
{
    visited[src] = true;
    for (int i : adj[src])
    {
        if (!visited[i])
        {
            revdfs(i, adj, visited);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    vector<int> adjList[V];
    for (int i = 0; i < V; i++)
    {
        for (int j : adj[i])
        {
            adjList[i].push_back(j);
        }
    }
    stack<int> st;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adjList, st, visited);
        }
    }
    vector<int> revList[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        for (int j : adj[i])
        {
            revList[j].push_back(i);
        }
    }
    int count = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            count++;
            revdfs(node, revList, visited);
            V--;
        }
    }
    return count;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << kosaraju(v, adj);
}