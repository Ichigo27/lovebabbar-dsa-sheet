// 252 M Colouring Problem

// Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] && color[i] == m)
            return false;
    }
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, int color[], int n, int node)
{
    if (node == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, n, i))
        {
            color[node] = i;
            if (graphColoringUtil(graph, m, color, n, node + 1))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V];
    memset(color, 0, sizeof(color));
    if (graphColoringUtil(graph, m, color, V, 0))
        return true;
    return false;
}

int main()
{
    int n, m, e;
    cin >> n >> m >> e;
    bool graph[101][101];
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    cout << graphColoring(graph, m, n) << endl;
}