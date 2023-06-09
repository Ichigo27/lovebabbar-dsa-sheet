// 208 Find shortest safe route in a path with landmines

// Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as 0), calculate length of the shortest safe route possible from any cell in the first column to any cell in the last column of the matrix. We have to avoid landmines and their four adjacent cells (left, right, above and below) as they are also unsafe. We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any diagonal moves.

#include <bits/stdc++.h>
using namespace std;

vector<int> rowIdx = {1, 0, -1, 0};
vector<int> colIdx = {0, 1, 0, -1};

bool isSafe(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &vis)
{
    if (mat[i][j] == 0 || vis[i][j] == 1)
        return false;
    return true;
}

bool isValid(int i, int j, vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}

void markUnsafe(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (isValid(i + rowIdx[k], j + colIdx[k], mat) && mat[i + rowIdx[k]][j + colIdx[k]] != 0)
                        mat[i + rowIdx[k]][j + colIdx[k]] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
            {
                mat[i][j] = 0;
            }
        }
    }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << mat[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}

void solve(int i, int j, int curr_cost, int &min_cost, vector<vector<int>> &mat, vector<vector<int>> &vis)
{
    int n = mat.size();
    int m = mat[0].size();
    if (j == m - 1)
    {
        min_cost = min(min_cost, curr_cost);
        return;
    }
    if(curr_cost > min_cost)
        return;
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        if (isValid(i + rowIdx[k], j + colIdx[k], mat) && isSafe(i + rowIdx[k], j + colIdx[k], mat, vis))
            solve(i + rowIdx[k], j + colIdx[k], curr_cost + 1, min_cost, mat, vis);
    }
    vis[i][j] = 0;
}

int findShortestPath(vector<vector<int>> &mat)
{
    int min_dist = INT_MAX;
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    markUnsafe(mat);
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 1)
            solve(i, 0, 1, min_dist, mat, vis);
        if (min_dist == m - 1)
            break;
    }
    return min_dist == INT_MAX ? -1 : min_dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << findShortestPath(mat);
}