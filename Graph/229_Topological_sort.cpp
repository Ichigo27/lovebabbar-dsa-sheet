// 229 Implement Topological Sort

// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

#include <bits/stdc++.h>
using namespace std;

// Using DFS
// https://www.youtube.com/watch?v=T_boOrr0rvk
// Time Complexity: O(V+E)
// Space Complexity: O(V)
// void dfs(int curr, vector<int> &visited, stack<int> &order, vector<int> adj[])
// {
//     visited[curr] = 1;
//     for (auto it : adj[curr])
//     {
//         if (!visited[it])
//             dfs(it, visited, order, adj);
//     }
//     order.push(curr);
// }

// vector<int> topoSort(int V, vector<int> adj[])
// {
//     vector<int> visited(V, 0);
//     stack<int> order;
//     for (int i = 0; i < V; i++)
//     {
//         if (!visited[i])
//             dfs(i, visited, order, adj);
//     }
//     vector<int> ans;
//     while (!order.empty())
//     {
//         ans.push_back(order.top());
//         order.pop();
//     }
//     return ans;
// }

// Using Kahn's Algorithm
// https://www.youtube.com/watch?v=6XmzL04mlgQ
// Time Complexity: O(V+E)
// Space Complexity: O(V)
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for(auto it: adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> res;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for(auto it: adj[curr])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return res;
}

int main()
{
    int v, e;
    cin >> e >> v;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> ans = topoSort(v, adj);
    for (int i = 0; i < v; i++)
        cout << ans[i] << " ";
}