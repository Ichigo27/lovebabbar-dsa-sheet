// 217 Create a Graph, print it

#include <bits/stdc++.h>
using namespace std;

// describe the difference between the adjacency matrix and the adjacency list

// Adjacency Matrix
// 1. Space Complexity: O(V^2)
// 2. Edge Weight: O(1)
// 3. Edge Existence: O(1)
// 4. Iterating over all edges: O(V^2)

// Adjacency List
// 1. Space Complexity: O(V+E)
// 2. Edge Weight: O(1)
// 3. Edge Existence: O(logV)
// 4. Iterating over all edges: O(V+E)

// Adjacency List is better than Adjacency Matrix in terms of space complexity and iterating over all edges
// Adjacency Matrix is better than Adjacency List in terms of edge existence

vector<vector<int>> createAdjList()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    return g;
}

void printAdjList(vector<vector<int>> &g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> createAdjMatrix()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }
}

void printAdjMatrix(vector<vector<int>> &g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> adjList = createAdjList();
    printAdjList(adjList);
    vector<vector<int>> adjMatrix = createAdjMatrix();
    printAdjMatrix(adjMatrix);
}