// 212 Find if there is a path of more than k length from a source

// Given a graph, a source vertex in the graph, and a number k, find if there is a simple path, of path length greater than or equal to k, (without any cycle)starting from a given source and ending at any other vertex.Source vertex should always be 0.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=oZYMOJHWI9w
// Time Complexity: O(N!)
// Auxiliary Space: O(N)

bool solve(int curr, int k, vector<vector<pair<int, int>>> &g, vector<bool> &vis)
{
    vis[curr] = true;
    if(k <= 0)
        return true;
    for(auto &v: g[curr])
    {
        int u = v.first;
        int w = v.second;
        if(vis[u] == true)
            continue;
        if(w >= k)
            return true;
        if(solve(u, k - w, g, vis) == true)
            return true;
    }
    vis[curr] = false;
    return false;
}

bool pathMoreThanK(int V, int E, int k, int *a)
{
    vector<vector<pair<int, int>>> graph(V);
    for (int i = 0; i < 3 * E; i += 3)
    {
        graph[a[i]].push_back({a[i + 1], a[i + 2]});
        graph[a[i + 1]].push_back({a[i], a[i + 2]});
    }
    vector<bool> visited(V, false);
    return solve(0, k, graph, visited);
}

int main()
{
    int v, e, k;
    cin >> v >> e >> k;
    int arr[3 * e];
    for (int i = 0; i < 3 * e; i += 3)
    {
        cin >> arr[i] >> arr[i + 1] >> arr[i + 2];
    }
    cout << pathMoreThanK(v, e, k, arr);
}