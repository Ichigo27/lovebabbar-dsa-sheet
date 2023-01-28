// 55 Find Longest Recurring Subsequence in String

// Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

// The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n2)
// Space Complexity: O(n2)
int LongestCommonSubsequence(int x, int y, string s1, string s2)
{
    int dp[x + 1][y + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1] && i != j)
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x][y];
}

int LongestRepeatingSubsequence(string str)
{
    int n = str.size();
    return LongestCommonSubsequence(n, n, str, str);
}

int main()
{
    string s;
    cin >> s;
    cout << LongestRepeatingSubsequence(s);
}