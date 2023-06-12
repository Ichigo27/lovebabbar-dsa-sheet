// 214 Print all possible paths from top left to bottom right of a mXn matrix

// The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

#include <bits/stdc++.h>
using namespace std;

// TC - O(2^n*m)
// SC - O(n)

vector<int> xMoves = {1, 0};
vector<int> yMoves = {0, 1};

void printAllPaths(vector<vector<int>> &paths)
{
    int n = paths.size();
    int m = paths[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << paths[i][j] << ' ';
        }
        cout << endl;
    }
}

void solve(vector<vector<int>> &matrix, int xc, int yc, int xd, int yd, vector<int> path, vector<vector<int>> &paths)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if(xc == xd && yc == yd)
    {
        path.push_back(matrix[xc][yc]);
        paths.push_back(path);
        return;
    }
    int temp = matrix[xc][yc];
    matrix[xc][yc] = 0;
    for (int i = 0; i < 2; i++)
    {
        int nx = xc + xMoves[i];
        int ny = yc + yMoves[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && temp != 0)
        {
            path.push_back(temp);
            solve(matrix, nx, ny, xd, yd, path, paths);
            path.pop_back();
        }
    }
    matrix[xc][yc] = temp;
}

void allPaths(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> paths;
    vector<int> path;
    solve(matrix, 0, 0, n - 1, m - 1, path, paths);
    printAllPaths(paths);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    allPaths(matrix);
}