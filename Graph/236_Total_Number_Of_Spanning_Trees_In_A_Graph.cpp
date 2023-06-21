// 236 Total no. of Spanning tree in a graph

#include <bits/stdc++.h>
using namespace std;

// 1. Brute Force
// Generate all permutations of vertices and check if they form a spanning tree
// Time Complexity: O(V!)
// Space Complexity: O(V)

int countSpanningTree(vector<vector<int>> &adj, int v)
{
    int count = 0;
    vector<int> p(v);
    for (int i = 0; i < v; i++)
        p[i] = i;
    do
    {
        bool flag = true;
        for (int i = 0; i < v; i++)
        {
            for (int u : adj[i])
            {
                if (p[i] == p[u])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            count++;
    } while (next_permutation(p.begin(), p.end()));
    return count;
}

// 2. Kirchoff's Theorem
// The number of spanning trees of a graph is equal to any cofactor of its Laplacian matrix
// Time Complexity: O(V^3)
// Space Complexity: O(V^2)

int determinant(vector<vector<int>> &lap, int n)
{
    int det = 1;
    for (int i = 0; i < n; i++)
    {
        if (lap[i][i] == 0)
        {
            bool flag = false;
            for (int j = i + 1; j < n; j++)
            {
                if (lap[j][i] != 0)
                {
                    flag = true;
                    for (int k = i; k < n; k++)
                        swap(lap[i][k], lap[j][k]);
                    det *= -1;
                    break;
                }
            }
            if (!flag)
                return 0;
        }
        for (int j = i + 1; j < n; j++)
        {
            int temp = lap[j][i] / lap[i][i];
            for (int k = i; k < n; k++)
                lap[j][k] -= temp * lap[i][k];
        }
    }
    for (int i = 0; i < n; i++)
        det *= lap[i][i];
    return det;
}

int countSpanningTree(vector<vector<int>> &adj, int v)
{
    vector<vector<int>> lap(v, vector<int>(v, 0));
    for (int i = 0; i < v; i++)
    {
        lap[i][i] = adj[i].size();
        for (int u : adj[i])
            lap[i][u] = -1;
    }
    vector<vector<int>> temp(v - 1, vector<int>(v - 1, 0));
    for (int i = 1; i < v; i++)
    {
        for (int j = 1; j < v; j++)
            temp[i - 1][j - 1] = lap[i][j];
    }
    return determinant(temp, v - 1);
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

}