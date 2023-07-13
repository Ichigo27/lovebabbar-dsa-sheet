// 300 Count All Palindromic Subsequence in a given String

// Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) present in the string str.
// Note: You have to return the answer module 109+7;

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=vlbA8oUxSV0

const long long int M = 1000000007;

// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(1) + O(n) for recursive stack
// long long solve(int i, int j, string &str)
// {
//     // Base case: If the substring is empty, it's a palindrome
//     if (i > j)
//     {
//         return 0;
//     }

//     // Base case: If the substring has one character, it's a palindrome
//     if (i == j)
//     {
//         return 1;
//     }

//     // If the first and last characters of the substring are the same,
//     // then the number of palindromic substrings is the number of palindromic
//     // substrings of the substring without the first and last characters,
//     // plus 1 for the substring itself, plus the number of palindromic substrings
//     // of the substring without the first character, plus the number of palindromic
//     // substrings of the substring without the last character.
//     if (str[i] == str[j])
//     {
//         return ((1 + solve(i + 1, j, str) % M) % M + solve(i, j - 1, str) % M) % M;
//     }

//     // Otherwise, the number of palindromic substrings is the number of palindromic
//     // substrings of the substring without the first character, plus the number of
//     // palindromic substrings of the substring without the last character, minus
//     // the number of palindromic substrings of the substring without the first and
//     // last characters.
//     return ((solve(i + 1, j, str) % M + solve(i, j - 1, str) % M) % M - solve(i + 1, j - 1, str) % M + M) % M;
// }

// long long int countPS(string str)
// {
//     return solve(0, str.size() - 1, str);
// }

// Memoization Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) + O(n) for recursive stack
// long long solve(int i, int j, string &str, vector<vector<long long>> &dp)
// {
//     if (i > j)
//         return 0;
//     if (i == j)
//         return 1;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     if (str[i] == str[j])
//         return dp[i][j] = ((1 + solve(i + 1, j, str, dp) % M) % M + solve(i, j - 1, str, dp) % M) % M;
//     return dp[i][j] = ((solve(i + 1, j, str, dp) % M + solve(i, j - 1, str, dp) % M) % M - solve(i + 1, j - 1, str, dp) % M + M) % M;
// }

// long long int countPS(string str)
// {
//     vector<vector<long long>> dp(str.size(), vector<long long>(str.size(), -1));
//     return solve(0, str.size() - 1, str, dp);
// }

// Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// long long int countPS(string str)
// {
//     int n = str.size();
//     vector<vector<long long>> dp(n, vector<long long>(n, 0));
//     for (int i = 0; i < n; i++)
//         dp[i][i] = 1;
//     for (int l = 2; l <= n; l++)
//     {
//         for (int i = 0; i < n - l + 1; i++)
//         {
//             int j = i + l - 1;
//             if (str[i] == str[j])
//                 dp[i][j] = ((1 + dp[i + 1][j] % M) % M + dp[i][j - 1] % M) % M;
//             else
//                 dp[i][j] = ((dp[i + 1][j] % M + dp[i][j - 1] % M) % M - dp[i + 1][j - 1] % M + M) % M;
//         }
//     }
//     return dp[0][n - 1];
// }


// Another Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// long long int countPS(string str)
// {
//     int n = str.size();
//     vector<vector<long long>> dp(n, vector<long long>(n, 0));
//     for (int i = n - 1; i >= 0; i--)
//     {
//         dp[i][i] = 1;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (str[i] == str[j])
//                 dp[i][j] = ((1 + dp[i + 1][j] % M) % M + dp[i][j - 1] % M) % M;
//             else
//                 dp[i][j] = ((dp[i + 1][j] % M + dp[i][j - 1] % M) % M - dp[i + 1][j - 1] % M + M) % M;
//         }
//     }
//     return dp[0][n - 1];
// }

// Tabulation Solution (Space Optimized)
// Time Complexity: O(n^2)
// Space Complexity: O(n)
long long int countPS(string str)
{
    int n = str.size();
    vector<long long> curr(n, 0);
    vector<long long> prev(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        curr[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] == str[j])
                curr[j] = ((1 + curr[j - 1]) % M + prev[j] % M) % M;
            else
                curr[j] = ((curr[j - 1] % M + prev[j] % M) % M - prev[j - 1] % M + M) % M;
        }
        swap(curr, prev);
        fill(curr.begin(), curr.end(), 0);
    }
    return prev[n - 1];
}

int main()
{
    string str;
    cin >> str;
    cout << countPS(str);
}