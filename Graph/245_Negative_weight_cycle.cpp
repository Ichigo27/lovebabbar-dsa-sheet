// 245 Detect Negative cycle in a graph

// Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
// Note : edges[i] is defined as u, v and weight.

#include <bits/stdc++.h>
using namespace std;

// Using Floyd Warshall Algorithm
// time complexity: O(V^3)
// space complexity: O(V^2)
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        matrix[i][i] = 0;
    }
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        matrix[u][v] = w;
    }
    int m = matrix.size();
    for (int k = 0; k < m; k++)
    {
        for (int i = 0; i < m; i++) // i is the source
        {
            for (int j = 0; j < m; j++) // j is the destination
            {
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue;
                else if (matrix[i][j] == INT_MAX)
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                else
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][i] < 0)
            return 1;
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    cout << isNegativeWeightCycle(n, edges);
    return 0;
}