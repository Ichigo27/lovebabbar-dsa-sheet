// Implement Bellman Ford Algorithm

// Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
// Note: edges[i] is defined as u, v and weight.

#include <bits/stdc++.h>
using namespace std;

// time complexity: O(V*E)
// space complexity: O(V)
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    for (int i = 0; i < n; i++)
    {
        edges.push_back({n, i, 0});
    }
    vector<int> dist(n + 1, INT_MAX);
    dist[n] = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    cout << isNegativeWeightCycle(n, edges);
    return 0;
}