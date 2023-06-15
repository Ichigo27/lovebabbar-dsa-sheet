// 226 Making wired Connections

// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<int> &visited, vector<vector<int>> &adjList)
{
    visited[curr] = 1;
    for (auto &neighbor : adjList[curr])
    {
        if (visited[neighbor] == 0)
            dfs(neighbor, visited, adjList);
    }
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    if (n - 1 > connections.size())
        return -1;
    vector<vector<int>> adjList(n);
    for (int i = 0; i < connections.size(); i++)
    {
        adjList[connections[i][0]].push_back(connections[i][1]);
        adjList[connections[i][1]].push_back(connections[i][0]);
    }
    vector<int> visited(n, 0);
    int cc = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, visited, adjList);
            cc++;
        }
    }
    return cc - 1;
}

int main()
{
    int v, e;
    cin >> v, e;
    vector<vector<int>> connections(v);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        connections.push_back({a, b});
    }
    cout << makeConnected(v, connections);
}
