// 238 Implement Floyd warshall Algorithm

// The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
// Do it in-place.

#include <bits/stdc++.h>
using namespace std;

// time complexity O(n^3)
// space complexity O(n^2)
void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++) // i is the source
        {
            for (int j = 0; j < n; j++) // j is the destination
            {
                if (matrix[i][k] == -1 || matrix[k][j] == -1)
                    continue;
                else if (matrix[i][j] == -1)
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                else
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        matrix[i][i] = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    shortest_distance(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}