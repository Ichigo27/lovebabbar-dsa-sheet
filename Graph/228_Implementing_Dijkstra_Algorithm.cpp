// 228 Dijkstra algo

// Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
// Note: The Graph doesn't contain any negative weight cycle.

#include <bits/stdc++.h>
using namespace std;

// time complexity O(V^2)
// space complexity O(V)

// using set
// vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
// {
//     vector<int> dist(V, INT_MAX);
//     dist[S] = 0;
//     set<pair<int, int>> s;
//     s.insert({0, S});
//     while (!s.empty())
//     {
//         auto it = s.begin();
//         int u = it->second;
//         s.erase(it);
//         for (auto i : adj[u])
//         {
//             int v = i[0];
//             int w = i[1];
//             if (dist[v] > dist[u] + w)
//             {
//                 if (dist[v] != INT_MAX)
//                     s.erase(s.find({dist[v], v}));
//                 dist[v] = dist[u] + w;
//                 s.insert({dist[v], v});
//             }
//         }
//     }
//     return dist;
// }

// using priority queue
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int u = it.second;
        for (auto i : adj[u])
        {
            int v = i[0];
            int w = i[1];
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj[v];
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    int s;
    cin >> s;
    vector<int> ans = dijkstra(v, adj, s);
    for (int i = 0; i < v; i++)
        cout << ans[i] << " ";
}
