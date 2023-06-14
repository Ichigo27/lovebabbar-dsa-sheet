// 222 Search in a Maze

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(4^(n^2)). As we are making 4 calls for every cell in the matrix.
// Auxiliary Space: O(1). As we are not using any extra space.

void solve(int i, int j, vector<vector<int>> &m, int n, string p, vector<string> &paths)
{
    if (i < 0 || j < 0 || i > n - 1 || j > n - 1 || m[i][j] == 0)
    {
        return;
    }
    if (i == n - 1 && j == n - 1)
    {
        paths.push_back(p);
        return;
    }
    m[i][j] = 0;
    solve(i - 1, j, m, n, p + "U", paths);
    solve(i + 1, j, m, n, p + "D", paths);
    solve(i, j - 1, m, n, p + "L", paths);
    solve(i, j + 1, m, n, p + "R", paths);
    m[i][j] = 1;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> paths;
    solve(0, 0, m, n, "", paths);
    return paths;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    vector<string> paths = findPath(m, n);
    for (auto path : paths)
    {
        cout << path << " ";
    }
}