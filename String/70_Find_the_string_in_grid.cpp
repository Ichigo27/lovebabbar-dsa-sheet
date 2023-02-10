// 70 Search a Word in a 2D Grid of characters.

// Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(R*C*8*len(str)).
    // All the cells will be visited and traversed in all 8 directions, where R and C is side of matrix so time complexity is O(R*C).
// Auxiliary Space: O(1).
    // As no extra space is needed.

vector<pair<int, int>> directions = {
    {-1, 0}, {+1, 0}, {0, -1}, {0, +1}, {-1, -1}, {-1, +1}, {+1, -1}, {+1, +1}};

bool solve(vector<vector<char>> &mat, string &target, int i, int j)
{
    if (mat[i][j] != target[0])
        return false;
    for (int idx = 0; idx < 8; idx++)
    {
        int x, y, k;
        x = i + directions[idx].first;
        y = j + directions[idx].second;
        for (k = 1; k < target.length(); k++)
        {
            if (x < 0 || y < 0 || x >= mat.size() || y >= mat[0].size() || mat[x][y] != target[k])
                break;
            x += directions[idx].first;
            y += directions[idx].second;
        }
        if (k == target.length())
            return true;
    }
    return false;
}

vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (solve(grid, word, i, j))
                ans.push_back({i, j});
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    string s;
    cin >> s;
    vector<vector<int>> ans = searchWord(mat, s);
    for (auto &ele : ans)
    {
        cout << ele[0] << ' ' << ele[1] << endl;
    }
}