// 248 Cheapest Flights Within K Stops

// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=9XybHVqTHcQ
// time complexity: O(E)
// space complexity: O(E+V)
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto x : flights)
    {
        adj[x[0]].push_back({x[1], x[2]});
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while (!q.empty())
    {
        int stop = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        if (stop > k)
            continue;
        for (auto x : adj[node])
        {
            int v = x.first;
            int w = x.second;
            if (dist[v] > cost + w && stop <= k)
            {
                dist[v] = cost + w;
                q.push({stop + 1, {v, dist[v]}});
            }
        }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}


int main()
{
    int v, e;
    cin >> v, e;
    vector<vector<int>> flights;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        flights.push_back({a, b, c});
    }
    int src, dst, k;
    cin >> src >> dst >> k;
    cout << findCheapestPrice(v, flights, src, dst, k);
}