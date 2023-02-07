// 69 Count of number of given string in 2D character array

// Find the number of occurrences of a given search word in a 2d-Array of characters where the word can go up, down, left, right, and around 90-degree bends.
// Note : While making a word you can use one cell only once.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m)^2, where n is the row size and m is the column size.
// Auxiliary Space: O(n*m)
int solve(vector<vector<char>> &mat, string &target, int i, int j, int curr)
{
    int ans = 0;
    if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] == '#' || mat[i][j] != target[curr])
        return 0;
    if (curr == target.size() - 1 && target[curr] == target[target.size() - 1])
        return 1;
    mat[i][j] = '#';
    ans += solve(mat, target, i - 1, j, curr + 1);
    ans += solve(mat, target, i + 1, j, curr + 1);
    ans += solve(mat, target, i, j - 1, curr + 1);
    ans += solve(mat, target, i, j + 1, curr + 1);
    mat[i][j] = target[curr];
    return ans;
}

int findOccurrence(vector<vector<char>> &mat, string target)
{
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += solve(mat, target, i, j, 0);
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
    cout << findOccurrence(mat, s);
}