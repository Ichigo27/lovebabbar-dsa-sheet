// 246 Longest path in a Directed Acyclic Graph

// Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find the longest distances from s to all other vertices in the given graph.

#include <bits/stdc++.h>
using namespace std;

// time complexity O(V+E)
// space complexity O(V)
// topological sort + dfs
// first find the topological sort of the graph
// then traverse the graph in topological order and update the distance of the adjacent nodes
// if the distance of the adjacent node is less than the distance of the current node + weight of the edge then update the distance of the adjacent node
// if the distance of the adjacent node is not INT_MIN then it means that the node is reachable from the source node
// if the distance of the adjacent node is INT_MIN then it means that the node is not reachable from the source node

void dfs(int src, vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &st)
{
    visited[src] = 1;
    for (auto it : adj[src])
    {
        if (!visited[it.first])
            dfs(it.first, adj, visited, st);
    }
    st.push(src);
}

vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src)
{
    vector<pair<int, int>> adj[v];
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    vector<int> visited(v, 0);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }
    vector<int> dist(v, INT_MIN);
    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dist[node] != INT_MIN)
        {
            for (auto it : adj[node])
            {
                if (dist[node] + it.second > dist[it.first])
                    dist[it.first] = dist[node] + it.second;
            }
        }
    }
    return dist;
}

int main()
{
    int v, e, src;
    cin >> v >> e >> src;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> ans = maximumDistance(edges, v, e, src);
    for (int i = 0; i < v; i++)
    {
        if (ans[i] == INT_MIN)
            cout << "INF ";
        else
            cout << ans[i] << " ";
    }
}