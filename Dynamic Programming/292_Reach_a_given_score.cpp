// 292 Count number of ways to reacha given score in a game

// Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=oizJTbpgAsc

// Recursive
// time complexity: O(3^n)
// space complexity: O(1) + recursion stack O(n)
// long long int solve(long long int i, long long int n, vector<int> &score)
// {
//     if(n < 0)
//         return 0;
//     if(n == 0)
//         return 1;
//     if(i == score.size())
//         return 0;
//     return solve(i, n - score[i], score) + solve(i + 1, n, score);
// }

// long long int count(long long int n)
// {
//     vector<int> score = {3, 5, 10};
//     return solve(0, n, score);
// }

// Memoization
// time complexity: O(3*n)
// space complexity: O(3*n) + O(3*n) = O(n)
// long long int solve(long long int i, long long int n, vector<int> &score, vector<vector<int>> &dp)
// {
//     if (n < 0)
//         return 0;
//     if (n == 0)
//         return 1;
//     if (i == score.size())
//         return 0;
//     if (dp[i][n] != -1)
//         return dp[i][n];
//     return dp[i][n] = solve(i, n - score[i], score, dp) + solve(i + 1, n, score, dp);
// }

// long long int count(long long int n)
// {
//     vector<int> score = {3, 5, 10};
//     vector<vector<int>> dp(score.size(), vector<int>(n + 1, -1));
//     return solve(0, n, score, dp);
// }

// Tabulation
// time complexity: O(3*n)
// space complexity: O(3*n)
// long long int count(long long int n)
// {
//     vector<int> score = {3, 5, 10};
//     vector<vector<int>> dp(score.size(), vector<int>(n + 1, 0));
//     for (int i = 0; i < score.size(); i++)
//         dp[i][0] = 1;
//     for (int i = 0; i < score.size(); i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (j - score[i] >= 0)
//                 dp[i][j] += dp[i][j - score[i]];
//             if (i > 0)
//                 dp[i][j] += dp[i - 1][j];
//         }
//     }
//     return dp[score.size() - 1][n];
// }

// Tabulation Space Optimized
// time complexity: O(n)
// space complexity: O(n)
long long int count(long long int n)
{
    long long int table[n + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;
    vector<int> score = {3, 5, 10};
    for (int i = 0; i < score.size(); i++)
    {
        for (int j = score[i]; j <= n; j++)
        {
            table[j] += table[j - score[i]];
        }
    }
    return table[n];
}

int main()
{
    long long int n;
    cin >> n;
    cout << count(n) << endl;
}