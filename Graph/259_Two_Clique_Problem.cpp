// 259 Two Clique Problem

// A Clique is a subgraph of graph such that all vertices in subgraph are completely connected with each other. Given a Graph, find if it can be divided into two Cliques.

#include <bits/stdc++.h>
using namespace std;

// time complexity O(V^2)
// space complexity O(V^2)

bool dfs(int node, vector<vector<int>> &graph, vector<int> &color)
{
    if (color[node] == -1)
        color[node] = 1;
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[node][i] == 1)
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[node];
                if (!dfs(i, graph, color))
                    return false;
            }
            else if (color[i] == color[node])
                return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> color(graph.size(), -1);
    for (int v = 0; v < graph.size(); v++)
    {
        if (color[v] == -1)
        {
            if (!dfs(v, graph, color))
                return false;
        }
    }
    return true;
}

bool canBeDividedinTwoCliques(vector<vector<int>> &graph)
{
    vector<vector<int>> complement;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            if (i != j)
                complement[i][j] = !graph[i][j];
            else
                complement[i][j] = 0;
        }
    }
    return isBipartite(complement);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    cout << canBeDividedinTwoCliques(graph);
}