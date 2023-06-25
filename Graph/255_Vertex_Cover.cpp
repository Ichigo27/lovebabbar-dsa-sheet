// 255 Vertex Cover Problem

// Given an undirected graph G return, the minimum number of vertexes that are needed so that every vertex is adjacent to the selected one.In short return the size of the vertex cover of the graph.

#include <bits/stdc++.h>
using namespace std;

// Approximation Algorithm
// Never finds a vertex cover whose size is more than twice the size of the minimum possible vertex cover
int vertexCover(int n, vector<pair<int, int>> &edges)
{
    vector<int> adj[n + 1];
    for (auto e : edges)
    {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            for (auto j : adj[i])
            {
                if (!visited[j])
                {
                    visited[i] = true;
                    visited[j] = true;
                    break;
                }
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> edges(e);
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }
    cout << vertexCover(v, edges) << endl;
}