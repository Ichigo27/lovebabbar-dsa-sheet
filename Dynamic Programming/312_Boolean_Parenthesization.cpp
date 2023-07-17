// 312 Boolean Parenthesization Problem

// Given a boolean expression S of length N with following symbols.
// Symbols
//     'T' ---> true
//     'F' ---> false
// and following operators filled between symbols
// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

#include <bits/stdc++.h>
using namespace std;

const int mod = 1003;

// https://www.youtube.com/watch?v=MM7fXopgyjw

// Recursive Approach
// Time Complexity: O(4^N)
// Space Complexity: O(1) + O(N) for recursive stack
// int solve(int i, int j, string S, bool isTrue)
// {
//     if (i > j)
//         return 0;
//     if (i == j)
//     {
//         if (isTrue)
//             return S[i] == 'T';
//         else
//             return S[i] == 'F';
//     }
//     int ways = 0;
//     for (int k = i + 1; k <= j - 1; k += 2)
//     {
//         int lt = solve(i, k - 1, S, true) % mod;
//         int lf = solve(i, k - 1, S, false) % mod;
//         int rt = solve(k + 1, j, S, true) % mod;
//         int rf = solve(k + 1, j, S, false) % mod;
//         if (S[k] == '&')
//         {
//             if (isTrue)
//                 ways = (ways + lt * rt) % mod;
//             else
//                 ways = (ways + lt * rf + lf * rt + lf * rf) % mod;
//         }
//         else if (S[k] == '|')
//         {
//             if (isTrue)
//                 ways = (ways + lt * rt + lt * rf + lf * rt) % mod;
//             else
//                 ways = (ways + lf * rf) % mod;
//         }
//         else if (S[k] == '^')
//         {
//             if (isTrue)
//                 ways = (ways + lt * rf + lf * rt) % mod;
//             else
//                 ways = (ways + lt * rt + lf * rf) % mod;
//         }
//     }
//     return ways % mod;
// }

// int countWays(int N, string S)
// {
//     return solve(0, N - 1, S, true);
// }


// Memoization Approach
// Time Complexity: O(N*N*N)
// Space Complexity: O(N*N*N) + O(N) for recursive stack
// int solve(int i, int j, string S, bool isTrue, vector<vector<vector<int>>> &dp)
// {
//     if (i > j)
//         return 0;
//     if (i == j)
//     {
//         if (isTrue)
//             return S[i] == 'T';
//         else
//             return S[i] == 'F';
//     }
//     if (dp[i][j][isTrue] != -1)
//         return dp[i][j][isTrue];
//     int ways = 0;
//     for (int k = i + 1; k <= j - 1; k += 2)
//     {
//         int lt = solve(i, k - 1, S, true, dp) % mod;
//         int lf = solve(i, k - 1, S, false, dp) % mod;
//         int rt = solve(k + 1, j, S, true, dp) % mod;
//         int rf = solve(k + 1, j, S, false, dp) % mod;
//         if (S[k] == '&')
//         {
//             if (isTrue)
//                 ways = (ways + lt * rt) % mod;
//             else
//                 ways = (ways + lt * rf + lf * rt + lf * rf) % mod;
//         }
//         else if (S[k] == '|')
//         {
//             if (isTrue)
//                 ways = (ways + lt * rt + lt * rf + lf * rt) % mod;
//             else
//                 ways = (ways + lf * rf) % mod;
//         }
//         else if (S[k] == '^')
//         {
//             if (isTrue)
//                 ways = (ways + lt * rf + lf * rt) % mod;
//             else
//                 ways = (ways + lt * rt + lf * rf) % mod;
//         }
//     }
//     return dp[i][j][isTrue] = ways % mod;
// }

// int countWays(int N, string S)
// {
//     vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
//     return solve(0, N - 1, S, true, dp);
// }


// Tabulation Approach
// Time Complexity: O(N*N*N)
// Space Complexity: O(N*N*N)
int countWays(int N, string S)
{
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(2, 0)));
    for (int i = 0; i < N; i += 2)
    {
        if (S[i] == 'T')
            dp[i][i][1] = 1;
        else
            dp[i][i][0] = 1;
    }
    for (int i = N - 3; i >= 0; i -= 2)
    {
        for (int j = i + 2; j < N; j += 2)
        {
            for (int isTrue = 0; isTrue < 2; isTrue++)
            {
                int ways = 0;
                for (int k = i + 1; k <= j - 1; k += 2)
                {
                    int lt = dp[i][k - 1][1] % mod;
                    int lf = dp[i][k - 1][0] % mod;
                    int rt = dp[k + 1][j][1] % mod;
                    int rf = dp[k + 1][j][0] % mod;
                    if (S[k] == '&')
                    {
                        if (isTrue)
                            ways = (ways + lt * rt) % mod;
                        else
                            ways = (ways + lt * rf + lf * rt + lf * rf) % mod;
                    }
                    else if (S[k] == '|')
                    {
                        if (isTrue)
                            ways = (ways + lt * rt + lt * rf + lf * rt) % mod;
                        else
                            ways = (ways + lf * rf) % mod;
                    }
                    else if (S[k] == '^')
                    {
                        if (isTrue)
                            ways = (ways + lt * rf + lf * rt) % mod;
                        else
                            ways = (ways + lt * rt + lf * rf) % mod;
                    }
                }
                dp[i][j][isTrue] = ways % mod;
            }
        }
    }
    return dp[0][N - 1][1];
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << countWays(n, s) << endl;
}