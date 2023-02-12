// 77 Find the longest common subsequence between two strings.

// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercas

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(|str1|*|str2|)
// Auxiliary Space: O(|str1|*|str2|)
int lcs(int x, int y, string s1, string s2)
{
    int dp[x + 1][y + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x][y];
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(n, m, s1, s2);
}