// 266 Edit Distance

// Given two strings s and t. Return the minimum number of operations required to convert s to t.
// The possible operations are permitted:

//     Insert a character at any position of the string.
//     Remove any character from the string.
//     Replace any character from the string with any other character.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=fJaKO8FbDdo

// Recursive Solution
// time complexity: O(3^n)
// space complexity: O(1)
// int solve(int i, int j, string &s, string &t)
// {
//     if (i == s.size())
//         return t.size() - j;
//     if (j == t.size())
//         return s.size() - i;

//     if (s[i] == t[j])
//         return solve(i + 1, j + 1, s, t);

//     int insert = solve(i, j + 1, s, t);
//     int remove = solve(i + 1, j, s, t);
//     int replace = solve(i + 1, j + 1, s, t);

//     return 1 + min(insert, min(remove, replace));
// }

// int editDistance(string s, string t)
// {
//     return solve(0, 0, s, t);
// }

// Memoization
// time complexity: O(m*n)
// space complexity: O(m*n) for dp + O(m*n) for recursion stack
// int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
// {
//     if (i == s.size())
//         return t.size() - j;
//     if (j == t.size())
//         return s.size() - i;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (s[i] == t[j])
//         return dp[i][j] = solve(i + 1, j + 1, s, t, dp);

//     int insert = solve(i, j + 1, s, t, dp);
//     int remove = solve(i + 1, j, s, t, dp);
//     int replace = solve(i + 1, j + 1, s, t, dp);

//     return dp[i][j] = 1 + min(insert, min(remove, replace));
// }

// int editDistance(string s, string t)
// {
//     vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
//     return solve(0, 0, s, t, dp);
// }

// Tabulation
// time complexity: O(m*n)
// space complexity: O(m*n)
// int editDistance(string s, string t)
// {
//     int m = s.size(), n = t.size();
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//     for (int j = 0; j <= n; j++)
//         dp[m][j] = n - j;
//     for (int i = 0; i <= m; i++)
//         dp[i][n] = m - i;

//     for (int i = m - 1; i >= 0; i--)
//     {
//         for (int j = n - 1; j >= 0; j--)
//         {
//             if (s[i] == t[j])
//                 dp[i][j] = dp[i + 1][j + 1];
//             else
//                 dp[i][j] = 1 + min(dp[i][j + 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
//         }
//     }

//     return dp[0][0];
// }

// Tabulation (Space Optimized)
// time complexity: O(m*n)
// space complexity: O(n)
int editDistance(string s, string t)
{
    int m = s.size(), n = t.size();
    vector<int> prev(max(m, n) + 1, 0), curr(max(m, n) + 1, 0);

    for (int j = 0; j <= n; j++)
        prev[j] = n - j;

    for (int i = m - 1; i >= 0; i--)
    {
        curr[n] = m - i;
        for (int j = n - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
                curr[j] = prev[j + 1];
            else
                curr[j] = 1 + min(curr[j + 1], min(prev[j], prev[j + 1]));
        }
        prev = curr;
    }

    return curr[0];
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << editDistance(s, t) << endl;
}
