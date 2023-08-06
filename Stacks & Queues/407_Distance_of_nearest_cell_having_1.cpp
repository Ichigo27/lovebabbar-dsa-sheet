// 407 Distance of nearest cell having 1 in a binary matrix

// Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=edXdVwkYHF8

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    while (!q.empty())
    {
        int currX = q.front().first.first;
        int currY = q.front().first.second;
        int currD = q.front().second;
        q.pop();
        dist[currX][currY] = currD;
        for (int i = 0; i < 4; i++)
        {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && grid[newX][newY] == 0)
            {
                q.push({{newX, newY}, currD + 1});
                visited[newX][newY] = true;
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; i < m; j++)
            cin >> grid[i][j];
    vector<vector<int>> ans = nearest(grid);
}