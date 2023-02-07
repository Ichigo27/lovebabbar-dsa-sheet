// 68 Count All Palindromic Subsequence in a given String.

// Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) present in the string str.
// Note: You have to return the answer module 10^9+7;

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(3^(n*n)), it is exponential increasing which can see using recursion tree, it is not a tight bound.
// Auxiliary Space: O(n), as max number of stack frames in recursion tree of it will have n frames.

// Expected Approach
// Time Complexity: O(n*n), as there are at n*n states and for calculating each state we need at max of 3 operations.
// Auxiliary Space: O(n*n), as we are using 2D vector cps of size n*n.
long long int solve(string &s, int i, int j, vector<vector<long long int>> &dp)
{
    int m = 1e9 + 7;
    if (i > j)
        return 0;
    if (i == j)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == s[j])
        return dp[i][j] = (1 + solve(s, i, j - 1, dp) + solve(s, i + 1, j, dp)) % m;
    else
        return dp[i][j] = ((solve(s, i, j - 1, dp) + solve(s, i + 1, j, dp) - solve(s, i + 1, j - 1, dp)) % m + m) % m;
}

long long int countPS(string str)
{
    int n = str.length();
    vector<vector<long long int>> dp(n, vector<long long int>(n, -1));
    return solve(str, 0, n - 1, dp);
}

int main()
{
    string s;
    cin >> s;
    cout << countPS(s);
}