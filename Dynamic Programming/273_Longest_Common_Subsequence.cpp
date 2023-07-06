// 273 Longest Common Subsequence

// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=NPZn9jBrX8U

// Recursive
// Time complexity: O(2^n)
// Space complexity: O(1)
// int solve(int i, int j, int x, int y, string s1, string s2)
// {
//     if (i == x || j == y)
//         return 0;
//     if (s1[i] == s2[j])
//         return 1 + solve(i + 1, j + 1, x, y, s1, s2);
//     else
//         return max(solve(i + 1, j, x, y, s1, s2), solve(i, j + 1, x, y, s1, s2));
// }

// int lcs(int x, int y, string s1, string s2)
// {
//     return solve(0, 0, x, y, s1, s2);
// }

// Memoization
// Time complexity: O(x*y)
// Space complexity: O(x*y) + O(x*y) = O(x*y)
// int solve(int i, int j, int x, int y, string s1, string s2, vector<vector<int>> &dp)
// {
//     if (i == x || j == y)
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     if (s1[i] == s2[j])
//         return dp[i][j] = 1 + solve(i + 1, j + 1, x, y, s1, s2, dp);
//     else
//         return dp[i][j] = max(solve(i + 1, j, x, y, s1, s2, dp), solve(i, j + 1, x, y, s1, s2, dp));
// }

// int lcs(int x, int y, string s1, string s2)
// {
//     vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
//     return solve(0, 0, x, y, s1, s2, dp);
// }

// Tabulation
// Time complexity: O(x*y)
// Space complexity: O(x*y)
// int lcs(int x, int y, string s1, string s2)
// {
//     int dp[x + 1][y + 1];
//     for (int i = 0; i <= x; i++)
//     {
//         for (int j = 0; j <= y; j++)
//         {
//             if (i == 0 || j == 0)
//                 dp[i][j] = 0;
//             else if (s1[i - 1] == s2[j - 1])
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             else
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
//     return dp[x][y];
// }

// Space optimized tabulation
// Time complexity: O(x*y)
// Space complexity: O(y)
int lcs(int x, int y, string s1, string s2)
{
    vector<int> prev(y + 1, 0), curr(y + 1, 0);
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
                curr[j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return curr[y];
}

int main()
{
    int x, y;
    cin >> x >> y;
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(x, y, s1, s2) << endl;
}