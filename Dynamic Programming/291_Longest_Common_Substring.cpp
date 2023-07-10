// 291 Longest Common Substring

// Given two strings.The task is to find the length of the longest common substring.

#include <bits/stdc++.h>
using namespace std;

// LCS Variation
// https://www.youtube.com/watch?v=_wP9mWNPL5w

// Tabulation like LCS
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    int dp[n + 1][m + 1];
    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (S1[i - 1] != S2[j - 1])
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}

// Space optimized
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                curr[j] = 0;
            else if (S1[i - 1] != S2[j - 1])
                curr[j] = 0;
            else
            {
                curr[j] = 1 + prev[j - 1];
                res = max(res, curr[j]);
            }
        }
        prev = curr;
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string S1, S2;
    cin >> S1 >> S2;
    cout << longestCommonSubstr(S1, S2, n, m) << endl;
}