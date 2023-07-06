// 276 LCS (Longest Common Subsequence) of three strings

// Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

#include <bits/stdc++.h>
using namespace std;

// Recursive
// Time complexity: O(2^n)
// Space complexity: O(1)
int solve(int i, int j, int k, int x, int y, int z, string s1, string s2, string s3)
{
    if (i == x || j == y || k == z)
        return 0;
    if (s1[i] == s2[j] && s2[j] == s3[k])
        return 1 + solve(i + 1, j + 1, k + 1, x, y, z, s1, s2, s3);
    else
    {
        int a = solve(i + 1, j, k, x, y, z, s1, s2, s3);
        int b = solve(i, j + 1, k, x, y, z, s1, s2, s3);
        int c = solve(i, j, k + 1, x, y, z, s1, s2, s3);
        return max(a, max(b, c));
    }
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    return solve(0, 0, 0, n1, n2, n3, A, B, C);
}

// Memoization
// Time complexity: O(x*y*z)
// Space complexity: O(x*y*z) + O(x*y*z) = O(x*y*z)
int solve(int i, int j, int k, int x, int y, int z, string s1, string s2, string s3, vector<vector<vector<int>>> &dp)
{
    if (i == x || j == y || k == z)
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    if (s1[i] == s2[j] && s2[j] == s3[k])
        return dp[i][j][k] = 1 + solve(i + 1, j + 1, k + 1, x, y, z, s1, s2, s3);
    else
    {
        int a = solve(i + 1, j, k, x, y, z, s1, s2, s3);
        int b = solve(i, j + 1, k, x, y, z, s1, s2, s3);
        int c = solve(i, j, k + 1, x, y, z, s1, s2, s3);
        return dp[i][j][k] = max(a, max(b, c));
    }
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));
    return solve(0, 0, 0, n1, n2, n3, A, B, C, dp);
}

// Tabulation
// Time complexity: O(x*y*z)
// Space complexity: O(x*y*z)
int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1 + 1][n2 + 1][n3 + 1];
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            for (int k = 0; k <= n3; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                {
                    int a = dp[i - 1][j][k];
                    int b = dp[i][j - 1][k];
                    int c = dp[i][j][k - 1];
                    dp[i][j][k] = max(a, max(b, c));
                }
            }
        }
    }
    return dp[n1][n2][n3];
}

// Tabulation (Space optimized)
// Time complexity: O(x*y*z)
// Space complexity: O(y*z)
int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<int>> prev(n2 + 1, vector<int>(n3 + 1, 0)), curr(n2 + 1, vector<int>(n3 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            for (int k = 0; k <= n3; k++)
            {
                if (j == 0 || k == 0)
                    curr[j][k] = 0;
                else if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                    curr[j][k] = 1 + prev[j - 1][k - 1];
                else
                {
                    int a = prev[j][k];
                    int b = curr[j - 1][k];
                    int c = curr[j][k - 1];
                    curr[j][k] = max(a, max(b, c));
                }
            }
        }
        prev = curr;
    }
    return curr[n2][n3];
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    string A, B, C;
    cin >> A >> B >> C;
    cout << LCSof3(A, B, C, n1, n2, n3) << endl;
}