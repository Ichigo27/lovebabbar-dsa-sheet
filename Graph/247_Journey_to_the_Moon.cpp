// 247 Journey to the Moon

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int src, vector<bool> &visited, int &count)
{
    visited[src] = true;
    count++;
    for (auto x : adj[src])
    {
        if (!visited[x])
        {
            dfs(adj, x, visited, count);
        }
    }
}

long long journeyToMoon(long long n, vector<vector<int>> astronaut)
{
    vector<int> adj[n];
    for (int i = 0; i < astronaut.size(); i++)
    {
        adj[astronaut[i][0]].push_back(astronaut[i][1]);
        adj[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    vector<bool> visited(n, false);
    vector<int> country;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int count = 0;
            dfs(adj, i, visited, count);
            country.push_back(count);
        }
    }
    long long total = n * (n - 1) / 2;
    for (int i = 0; i < country.size(); i++)
    {
        total -= country[i] * (country[i] - 1) / 2;
    }
    return total;
}

int main()
{
    int n, p;
    cin >> n >> p;
    vector<vector<int>> edges;
    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    cout << journeyToMoon(n, edges);
}