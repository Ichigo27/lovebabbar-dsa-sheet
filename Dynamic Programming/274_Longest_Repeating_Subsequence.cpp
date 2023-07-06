// 274 Longest Repeated Subsequence

// Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

// The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

#include <bits/stdc++.h>
using namespace std;

// Recursive
// Time complexity: O(2^n)
// Space complexity: O(1)
int solve(int i, int j, int n, string &s)
{
    if (i == n || j == n)
        return 0;
    if (s[i] == s[j] && i != j)
        return 1 + solve(i + 1, j + 1, n, s);
    else
        return max(solve(i + 1, j, n, s), solve(i, j + 1, n, s));
}

int LongestRepeatingSubsequence(string str)
{
    int n = str.size();
    return solve(0, 0, n, str);
}

// Memoization
// Time complexity: O(x*y)
// Space complexity: O(x*y) + O(x*y) = O(x*y)
int solve(int i, int j, int n, string &s, vector<vector<int>> &dp)
{
    if (i == n || j == n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == s[j])
        return dp[i][j] = 1 + solve(i + 1, j + 1, n, s, dp);
    else
        return dp[i][j] = max(solve(i + 1, j, n, s, dp), solve(i, j + 1, n, s, dp));
}

int LongestRepeatingSubsequence(string str)
{
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(0, 0, n, str, dp);
}

// Tabulation
// Time complexity: O(x*y)
// Space complexity: O(x*y)
int LongestRepeatingSubsequence(string str)
{
    int n = str.size();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str[i - 1] == str[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

// Space optimized tabulation
// Time complexity: O(x*y)
// Space complexity: O(y)
int LongestRepeatingSubsequence(string str)
{
    int n = str.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                curr[j] = 0;
            else if (str[i - 1] == str[j - 1] && i != j)
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return curr[n];
}

int main()
{
    string str;
    cin >> str;
    cout << LongestRepeatingSubsequence(str) << endl;
}