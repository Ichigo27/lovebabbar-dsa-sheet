// 253 Minimum edges to reverse to make path from source to destination

// Given a directed graph with N nodes and M edges. A source node and a destination node are also given, we need to find how many edges we need to reverse in order to make at least 1 path from the source node to the destination node.
// Note : In case there is no way then return -1.

#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm
// Time Complexity: O(ElogV)
// Space Complexity: O(V)
int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
{
    vector<pair<int, int>> adj[n];
    for (auto i : edges)
    {
        adj[i[0] - 1].push_back({i[1] - 1, 0});
        adj[i[1] - 1].push_back({i[0] - 1, 1});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    pq.push({0, src - 1});
    dist[src - 1] = 0;
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int node = p.second;
        int wt = p.first;
        for (auto i : adj[node])
        {
            int v = i.first;
            int w = i.second;
            if (dist[v] > dist[node] + w)
            {
                dist[v] = dist[node] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[dst - 1] == INT_MAX ? -1 : dist[dst - 1];
}

// 0-1 BFS
int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
{
    vector<pair<int, int>> adj[n];
    for (auto i : edges)
    {
        adj[i[0] - 1].push_back({i[1] - 1, 0});
        adj[i[1] - 1].push_back({i[0] - 1, 1});
    }
    deque<pair<int, int>> dq;
    vector<int> dist(n, INT_MAX);
    dq.push_front({0, src - 1});
    dist[src - 1] = 0;
    while (!dq.empty())
    {
        pair<int, int> p = dq.front();
        dq.pop_front();
        int node = p.second;
        int wt = p.first;
        for (auto i : adj[node])
        {
            int v = i.first;
            int w = i.second;
            if (dist[v] > dist[node] + w)
            {
                dist[v] = dist[node] + w;
                if (w == 0)
                    dq.push_front({dist[v], v});
                else
                    dq.push_back({dist[v], v});
            }
        }
    }
    return dist[dst - 1] == INT_MAX ? -1 : dist[dst - 1];
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    int src, dst;
    cin >> src >> dst;
    cout << minimumEdgeReversal(edges, v, src, dst);
}