// 203 m Coloring Problem

// Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

#include <bits/stdc++.h>
using namespace std;

bool isValid(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int i = 0; i<n; i++)
    {
        if(i != node && graph[node][i] == 1 && color[i] == col)
            return false;
    }
    return true;
}

bool solve(int node, int color[], bool graph[101][101], int m, int n)
{
    if(node == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isValid(node, color, graph, n, i))
        {
            color[node] = i;
            if (solve(node + 1, color, graph, m, n))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    int color[n] = {0};
    return solve(0, color, graph, m, n);
}

int main()
{
    int m, n, e;
    cin >> m >> n >> e;
    bool graph[101][101];
    for (int i = 0; i < n; i++)
    {
        memset(graph[i], 0, sizeof(graph[i]));
    }
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    cout << graphColoring(graph, m, n);
}