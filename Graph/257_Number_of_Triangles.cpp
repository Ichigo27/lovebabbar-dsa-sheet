// 257 Number of Triangles in a Directed and Undirected Graph

#include <bits/stdc++.h>
using namespace std;

// time complexity O(V^3)
// space complexity O(1)
int countTriangle(int V, vector<vector<int>> &graph, bool isDirected)
{
    int count_Triangle = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                if (graph[i][j] && graph[j][k] && graph[k][i])
                    count_Triangle++;
            }
        }
    }
    isDirected ? count_Triangle /= 3 : count_Triangle /= 6;
    return count_Triangle;
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
    int isDirected;
    cin >> isDirected;
    cout << countTriangle(n, graph, isDirected) << endl;
}