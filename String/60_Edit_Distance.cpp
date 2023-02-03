// 60 EDIT Distance [Very Imp]

// Given two strings s and t. Return the minimum number of operations required to convert s to t.
// The possible operations are permitted:
//     Insert a character at any position of the string.
//     Remove any character from the string.
//     Replace any character from the string with any other character.

#include <bits/stdc++.h>
using namespace std;

// Brute Way: Recursion
// The time complexity of above solution is exponential. In worst case, we may end up doing O(3^m) operations. The worst case happens when none of characters of two strings match.

// Optimal Way: Dynamic Programming
// https://youtu.be/fJaKO8FbDdox`
// Time Complexity: O(m x n)
// Auxiliary Space: O(m x n)
int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.length())
        return b.length() - j;
    if (j == b.length())
        return a.length() - i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
        return dp[i][j] = solve(a, b, i + 1, j + 1, dp);
    else
    {
        int addLetter = solve(a, b, i, j + 1, dp);
        int deleteLetter = solve(a, b, i + 1, j, dp);
        int replaceLetter = solve(a, b, i + 1, j + 1, dp);
        return dp[i][j] = 1 + min(addLetter, min(deleteLetter, replaceLetter));
    }
}

int editDistance(string s, string t)
{
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return solve(s, t, 0, 0, dp);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << editDistance(s, t);
}