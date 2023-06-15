// 230 Minimum time taken by each job to be completed given by a Directed Acyclic Graph

// Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Auxiliary Space: O(V)
vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
{
    vector<int> ans(n, 0);
    vector<int> indegree(n, 0);
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
        indegree[edges[i][1] - 1]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            ans[i] = 1;
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                ans[it] = ans[node] + 1;
                q.push(it);
            }
        }
    }
    return ans;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    vector<int> ans = minimumTime(v, edges, e);
    for (int i = 0; i < v; i++)
        cout << ans[i] << " ";
}