// 232 Find the no. of Isalnds

// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m)
// Space Complexity: O(1)
void dfs(int i, int j, vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
        return;
    grid[i][j] = '0';
    dfs(i + 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i - 1, j, grid);
    dfs(i, j - 1, grid);
    dfs(i + 1, j + 1, grid);
    dfs(i - 1, j + 1, grid);
    dfs(i + 1, j - 1, grid);
    dfs(i - 1, j - 1, grid);
}

int numIslands(vector<vector<char>> &grid)
{
    int num = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(i, j, grid);
                num++;
            }
        }
    }
    return num;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << numIslands(grid);
}
