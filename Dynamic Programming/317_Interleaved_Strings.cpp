// 317 Find if a string is interleaved of two other strings

// Given strings A, B, and C, find whether C is formed by an interleaving of A and B.
// An interleaving of two strings S and T is a configuration such that it creates a new string Y from the concatenation substrings of A and B and |Y| = |A + B| = |C|
// For example:
// A = "XYZ"
// B = "ABC"
// so we can make multiple interleaving string Y like, XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more so here your task is to check whether you can create a string Y which can be equal to C.
// Specifically, you just need to create substrings of string A and create substrings B and concatenate them and check whether it is equal to C or not.
// Note: a + b is the concatenation of strings a and b.
// Return true if C is formed by an interleaving of A and B, else return false.

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// Time Complexity: O(2^(m+n))
// Space Complexity: O(1) + O(m+n) recursive stack space
// bool solve(int i, int j, int k, string &a, string &b, string &c)
// {
//     if (k == c.size())
//         return true;
//     if (i == a.size() && j == b.size())
//         return false;
//     if (i < a.size() && a[i] == c[k] && solve(i + 1, j, k + 1, a, b, c))
//         return true;
//     if (j < b.size() && b[j] == c[k] && solve(i, j + 1, k + 1, a, b, c))
//         return true;
//     return false;
// }

// bool isInterleave(string A, string B, string C)
// {
//     return solve(0, 0, 0, A, B, C);
// }

// Memoization Solution
// Time Complexity: O(m*n)
// Space Complexity: O(m*n*o) + O(m+n) recursive stack space
// bool solve(int i, int j, int k, string &a, string &b, string &c, vector<vector<vector<int>>> &dp)
// {
//     if (k == c.size())
//         return true;
//     if (i == a.size() && j == b.size())
//         return false;
//     if (dp[i][j][k] != -1)
//         return dp[i][j][k];
//     if (i < a.size() && a[i] == c[k] && solve(i + 1, j, k + 1, a, b, c, dp))
//         return dp[i][j][k] = 1;
//     if (j < b.size() && b[j] == c[k] && solve(i, j + 1, k + 1, a, b, c, dp))
//         return dp[i][j][k] = 1;
//     return dp[i][j][k] = 0;
// }

// bool isInterleave(string A, string B, string C)
// {
//     vector<vector<vector<int>>> dp(A.size() + 1, vector<vector<int>>(B.size() + 1, vector<int>(C.size() + 1, -1)));
//     return solve(0, 0, 0, A, B, C, dp);
// }

// Tabulation Solution
// Time Complexity: O(m*n)
// Space Complexity: O(m*n*o)
// bool isInterleave(string A, string B, string C)
// {
//     int m = A.size(), n = B.size(), o = C.size();
//     vector<vector<vector<bool>>> dp(m + 1, vector<vector<bool>>(n + 1, vector<bool>(o + 1, false)));
//     for (int i = m; i >= 0; i--)
//     {
//         for (int j = n; j >= 0; j--)
//         {
//             for (int k = o; k >= 0; k--)
//             {
//                 if (k == o)
//                     dp[i][j][k] = true;
//                 else if (i == m && j == n)
//                     dp[i][j][k] = false;
//                 else if(i < m && A[i] == C[k] && dp[i + 1][j][k + 1])
//                     dp[i][j][k] = true;
//                 else if(j < n && B[j] == C[k] && dp[i][j + 1][k + 1])
//                     dp[i][j][k] = true;
//                 else
//                     dp[i][j][k] = false;
//             }
//         }
//     }
//     return dp[0][0][0];
// }


// Tabulation Solution (Space Optimized)
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
// bool isInterleave(string A, string B, string C)
// {
//     int m = A.size(), n = B.size(), o = C.size();
//     vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
//     for (int i = m; i >= 0; i--)
//     {
//         for (int j = n; j >= 0; j--)
//         {
//             if (i == m && j == n)
//                 dp[i][j] = true;
//             else if (i < m && A[i] == C[i + j] && dp[i + 1][j])
//                 dp[i][j] = true;
//             else if (j < n && B[j] == C[i + j] && dp[i][j + 1])
//                 dp[i][j] = true;
//             else
//                 dp[i][j] = false;
//         }
//     }
//     return dp[0][0];
// }


// Tabulation Solution (Space Optimized)
// Time Complexity: O(m*n)
// Space Complexity: O(n)
bool isInterleave(string A, string B, string C)
{
    int m = A.size(), n = B.size(), o = C.size();
    vector<bool> dp(n + 1, false);
    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (i == m && j == n)
                dp[j] = true;
            else if (i < m && A[i] == C[i + j] && dp[j])
                dp[j] = true;
            else if (j < n && B[j] == C[i + j] && dp[j + 1])
                dp[j] = true;
            else
                dp[j] = false;
        }
    }
    return dp[0];
}

int main()
{
    string A, B, C;
    cin >> A >> B >> C;
    cout << isInterleave(A, B, C) << endl;
}