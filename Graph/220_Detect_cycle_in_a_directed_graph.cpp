// 220 Detect Cycle in Directed Graph using BFS/DFS Algo

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// methods to detect cycle in a directed graph
// 1. DFS
// 2. BFS

#include <bits/stdc++.h>
using namespace std;

// DFS
// https://www.youtube.com/watch?v=1cSzxlhxOw8
// Time Complexity: O(V + E), the Time Complexity of this method is the same as the time complexity of DFS traversal which is O(V+E).
// Auxiliary Space: O(V). To store the visited and recursion stack O(V) space is needed.
bool solve(int vertex, vector<int> &visited, vector<int> &order, vector<int> adj[])
{
    visited[vertex] = 1;
    order[vertex] = 1; // order is used to check if the vertex is in the recursion stack or not
    for (auto &neigh : adj[vertex])
    {
        if (visited[neigh] == 0)
        {
            if (solve(neigh, visited, order, adj) == true)
                return true;
        }
        else if (order[neigh] == 1)
            return true;
    }
    order[vertex] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> order(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            if (solve(i, visited, order, adj) == true)
                return true;
        }
    }
    return false;
}

// Kahn's Algorithm
// https://www.youtube.com/watch?v=X2_tYUuthH8
// Time Complexity: O(V+E)
// Space Complexity: O(V)
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        count++;
        for (auto it : adj[curr])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return count != V;
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
    cout << isCyclic(v, g);
}
