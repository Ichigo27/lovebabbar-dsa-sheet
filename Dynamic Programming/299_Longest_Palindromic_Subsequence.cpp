// 299 Longest Palindromic Subsequence

// Given a String, find the longest palindromic subsequence.

#include <bits/stdc++.h>
using namespace std;


// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(1) + O(n) for recursive stack
// int solve(int i, int j, string a, string b, int n)
// {
//     if (i == n || j == n)
//         return 0;
//     if (a[i] == b[j])
//         return 1 + solve(i + 1, j + 1, a, b, n);
//     return max(solve(i + 1, j, a, b, n), solve(i, j + 1, a, b, n));
// }

// int longestPalinSubseq(string A)
// {
//     int N = A.size();
//     string B = A;
//     reverse(B.begin(), B.end());
//     return solve(0, 0, A, B, N);
// }


// Memoization Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) + O(n) for recursive stack
// int solve(int i, int j, string a, string b, int n, vector<vector<int>> &dp)
// {
//     if (i == n || j == n)
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     if (a[i] == b[j])
//         return dp[i][j] = 1 + solve(i + 1, j + 1, a, b, n, dp);
//     return dp[i][j] = max(solve(i + 1, j, a, b, n, dp), solve(i, j + 1, a, b, n, dp));
// }

// int longestPalinSubseq(string A)
// {
//     int N = A.size();
//     string B = A;
//     reverse(B.begin(), B.end());
//     vector<vector<int>> dp(N, vector<int>(N, -1));
//     return solve(0, 0, A, B, N, dp);
// }


// Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// int longestPalinSubseq(string A)
// {
//     int N = A.size();
//     string B = A;
//     reverse(B.begin(), B.end());
//     vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
//     for (int i = 0; i <= N; i++)
//     {
//         for (int j = 0; j <= N; j++)
//         {
//             if (i == 0 || j == 0)
//                 dp[i][j] = 0;
//             else if (A[i - 1] == B[j - 1])
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             else
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
//     return dp[N][N];
// }


// Tabulation Solution (Space Optimized)
// Time Complexity: O(n^2)
// Space Complexity: O(n)
int longestPalinSubseq(string A)
{
    int N = A.size();
    string B = A;
    reverse(B.begin(), B.end());
    vector<int> prev(N + 1, 0), curr(N + 1, 0);
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0 || j == 0)
                curr[j] = 0;
            else if (A[i - 1] == B[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return curr[N];
}

int main()
{
    string A;
    cin >> A;
    cout << longestPalinSubseq(A);
}