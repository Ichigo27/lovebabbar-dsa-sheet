// 269 Gold Mine Problem

// Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

//     to the cell diagonally up towards the right
//     to the right
//     to the cell diagonally down towards the right

// Find out maximum amount of gold which he can collect.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=tQU4rkmPyV0

// Recursive Solution
// Time Complexity: O(n*m)
// Space Complexity: O(1)
// int solve(int i, int j, int n, int m, vector<vector<int>> &M)
// {
//     if (i < 0 || j < 0 || i >= n || j >= m)
//         return 0;
//     return M[i][j] + max(solve(i + 1, j + 1, n, m, M), max(solve(i, j + 1, n, m, M), solve(i - 1, j + 1, n, m, M)));
// }

// int maxGold(int n, int m, vector<vector<int>> M)
// {
//     int res = 0;
//     for (int i = 0; i <= n; i++)
//         res = max(res, solve(i, 0, n, m, M));
//     return res;
// }

// Memoization Solution
// Time Complexity: O(n*m)
// Space Complexity: O(n*m) + O(n*m) = O(n*m)
// int solve(int i, int j, int n, int m, vector<vector<int>> &M, vector<vector<int>> &dp)
// {
//     if (i < 0 || j < 0 || i >= n || j >= m)
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     return dp[i][j] = M[i][j] + max(solve(i + 1, j + 1, n, m, M, dp), max(solve(i, j + 1, n, m, M, dp), solve(i - 1, j + 1, n, m, M, dp)));
// }

// int maxGold(int n, int m, vector<vector<int>> M)
// {
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     int res = 0;
//     for (int i = 0; i <= n; i++)
//         res = max(res, solve(i, 0, n, m, M, dp));
//     return res;
// }

// Tabulation Solution
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
int maxGold(int n, int m, vector<vector<int>> M)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            int right = (j == m - 1) ? 0 : dp[i][j + 1];
            int right_up = (i == 0 || j == m - 1) ? 0 : dp[i - 1][j + 1];
            int right_down = (i == n - 1 || j == m - 1) ? 0 : dp[i + 1][j + 1];
            dp[i][j] = M[i][j] + max(right, max(right_up, right_down));
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dp[i][0]);
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
    cout << maxGold(n, m, M) << endl;
}