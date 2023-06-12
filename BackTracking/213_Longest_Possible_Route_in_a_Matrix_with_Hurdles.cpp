// 213 Longest Possible Route in a Matrix with Hurdles

// Given an N x M matrix, with a few hurdles(denoted by 0) arbitrarily placed, calculate the length of the longest possible route possible from source(xs,ys) to a destination(xd,yd) within the matrix. We are allowed to move to only adjacent cells which are not hurdles. The route cannot contain any diagonal moves and a location once visited in a particular path cannot be visited again.If it is impossible to reach the destination from the source return -1.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(4^N), where N is the number of cells in the matrix. This is because, at each cell, there are four possible directions to explore (right, down, left, up), and the maximum depth of the recursion is N.
// Auxiliary Space: O(1)

vector<int> xMoves = {1, 0, -1, 0};
vector<int> yMoves = {0, 1, 0, -1};

bool isValid(vector<vector<int>> matrix, int i, int j)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] != 1)
        return false;
    return true;
}

void print(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void solve(vector<vector<int>> matrix, int xc, int yc, int xd, int yd, int curr, int &res)
{
    if (xc == xd && yc == yd)
    {
        if (curr > res)
        {
            res = curr;
        }
        return;
    }
    matrix[xc][yc] = 2;

    for (int i = 0; i < 4; i++)
    {
        int nx = xc + xMoves[i];
        int ny = yc + yMoves[i];
        if (isValid(matrix, nx, ny))
            solve(matrix, nx, ny, xd, yd, curr + 1, res);
    }
    matrix[xc][yc] = 1;
}

int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int res = 0;
    if (matrix[xs][ys] == 0)
        return -1;
    solve(matrix, xs, ys, xd, yd, 0, res);
    return res == 0 ? -1 : res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int xs, ys, xd, yd;
    cin >> xs >> ys >> xd >> yd;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << longestPath(matrix, xs, ys, xd, yd);
}