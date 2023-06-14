// 218 Implement BFS algorithm

// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> res, visited(V, 0);
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        if (visited[vertex] == 0)
        {
            visited[vertex] = 1;
            res.push_back(vertex);
        }
        for (auto &neigh : adj[vertex])
        {
            if (visited[neigh] == 0)
                q.push(neigh);
        }
    }
    return res;
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
        // g[y].push_back(x);
    }
    vector<int> nodes = bfsOfGraph(v, g);
    for (auto &node : nodes)
        cout << node << ' ';
}