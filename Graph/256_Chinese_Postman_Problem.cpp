// 256 Chinese Postman or Route Inspection

// Chinese Postman Problem is a variation of Eulerian circuit problem for undirected graphs. An Euler Circuit is a closed walk that covers every edge once starting and ending position is same. Chinese Postman problem is defined for connected and undirected graph. The problem is to find shortest path or circuity that visits every edge of the graph at least once.

#include <bits/stdc++.h>
using namespace std;

int minCost(int n, vector<vector<int>> &edges)
{
    // create a graph
    vector<vector<pair<int, int>>> g(n);
    for (auto x : edges)
        g[x[0]].push_back({x[1], x[2]}), g[x[1]].push_back({x[0], x[2]});

    // find the odd degree vertices
    vector<int> odd;
    for (int i = 0; i < n; i++)
        if (g[i].size() & 1)
            odd.push_back(i);

    // find the shortest path between all odd degree vertices
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < odd.size(); i++)
    {
        int s = odd[i];
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto x : g[u])
            {
                int v = x.first, w = x.second;
                if (!vis[v])
                {
                    vis[v] = 1;
                    dist[s][v] = w;
                    q.push(v);
                }
            }
        }
    }

    // find the minimum cost of traversing all edges
    vector<vector<int>> dp(1 << odd.size(), vector<int>(odd.size(), INT_MAX));
    for (int i = 0; i < odd.size(); i++)
        dp[1 << i][i] = 0;
    for (int mask = 0; mask < (1 << odd.size()); mask++)
    {
        for (int i = 0; i < odd.size(); i++)
        {
            if (mask & (1 << i))
            {
                for (int j = 0; j < odd.size(); j++)
                {
                    if (!(mask & (1 << j)))
                    {
                        dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dist[odd[i]][odd[j]]);
                    }
                }
            }
        }
    }

    // find the minimum cost of traversing all edges
    return dp[(1 << odd.size()) - 1][0];
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(e);
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
    }