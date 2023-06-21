// 235 Implement Prim’s Algorithm

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(ElogV)
// Space Complexity: O(E+V)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> edges)
{
    vector<pair<pair<int, int>, int>> mst;
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        adj[it.first.first].push_back({it.first.second, it.second});
        adj[it.first.second].push_back({it.first.first, it.second});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    vector<int> key(n + 1, INT_MAX), parent(n + 1, -1), visited(n + 1, 0);
    key[1] = 0;
    parent[1] = -1;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = 1;
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (visited[v] == 0 && key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        mst.push_back({{parent[i], i}, key[i]});
    }
    return mst;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }
    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);
    for (auto it : mst)
    {
        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    }
}