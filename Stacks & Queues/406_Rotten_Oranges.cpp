// 406 Minimum time required to rot all oranges

// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=yf3oUhkvqA0

int orangesRotting(vector<vector<int>> &grid)
{
    int days = 0, fresh = 0;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }
    int converted = 0;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    while (!q.empty())
    {
        int currX = q.front().first.first;
        int currY = q.front().first.second;
        int currD = q.front().second;
        q.pop();
        days = max(days, currD);
        for (int i = 0; i < 4; i++)
        {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && grid[newX][newY] == 1)
            {
                q.push({{newX, newY}, currD + 1});
                visited[newX][newY] = true;
                converted++;
            }
        }
    }
    return fresh == converted ? days : -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << orangesRotting(grid) << endl;
}