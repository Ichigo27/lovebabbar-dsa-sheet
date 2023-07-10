// 284 Maximum size square sub-matrix with all 1s

// Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

#include <bits/stdc++.h>
using namespace std;

// Recursive solution
// Time complexity: O(3^(n+m))
// Space complexity: O(n+m)
// int solve(int i, int j, int n, int m, vector<vector<int>> &mat)
// {
//     if (i == n || j == m)
//         return 0;
//     if (mat[i][j] == 0)
//         return 0;
//     return 1 + min({solve(i + 1, j, n, m, mat), solve(i, j + 1, n, m, mat), solve(i + 1, j + 1, n, m, mat)});
//     ;
// }

// int maxSquare(int n, int m, vector<vector<int>> mat)
// {
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             ans = max(ans, solve(i, j, n, m, mat));
//     return ans;
// }

// Memoization
// Time complexity: O(n*m)
// Space complexity: O(n*m) + O(n+m) for recursion stack
// int solve(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
// {
//     if (i == n || j == m)
//         return 0;
//     if (mat[i][j] == 0)
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     return dp[i][j] = 1 + min({solve(i + 1, j, n, m, mat, dp), solve(i, j + 1, n, m, mat, dp), solve(i + 1, j + 1, n, m, mat, dp)});
// }

// int maxSquare(int n, int m, vector<vector<int>> mat)
// {
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             ans = max(ans, solve(i, j, n, m, mat, dp));
//     return ans;
// }

// Tabulation
// Time complexity: O(n*m)
// Space complexity: O(n*m)
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (mat[i][j] == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

// Tabulation (Space optimized)
// Time complexity: O(n*m)
// Space complexity: O(m)
// int maxSquare(int n, int m, vector<vector<int>> mat)
// {
//     vector<int> curr(m + 1, 0), next(m + 1, 0);
//     int ans = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = m - 1; j >= 0; j--)
//         {
//             if (mat[i][j] == 0)
//                 curr[j] = 0;
//             else
//                 curr[j] = 1 + min({next[j], curr[j + 1], next[j + 1]});
//             ans = max(ans, curr[j]);
//         }
//         next = curr;
//     }
//     return ans;
// }

// Tabulation (Space optimized)
// Time complexity: O(n*m)
// Space complexity: O(1)
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int down = i < n - 1 ? mat[i + 1][j] : 0;
            int right = j < m - 1 ? mat[i][j + 1] : 0;
            int diag = i < n - 1 and j < m - 1 ? mat[i + 1][j + 1] : 0;
            if (mat[i][j] == 1)
            {
                mat[i][j] = 1 + min(down, min(right, diag));
                ans = max(mat[i][j], ans);
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    cout << maxSquare(n, m, mat) << endl;
}