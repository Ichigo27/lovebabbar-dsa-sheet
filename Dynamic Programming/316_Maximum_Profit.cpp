// 316 Maximum profit by buying and selling a share at most k times

// In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N days in an array A[ ] and a positive integer K, find out the maximum profit a person can make in at-most K transactions. A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.

#include <bits/stdc++.h>
using namespace std;

// Recursive
// Time Complexity: O(2^N)
// Space Complexity: O(1) + O(N) for recursive stack
// int solve(int i, int j, int k, int N, int A[])
// {
//     if (i == N || k == 0)
//         return 0;
//     int profit = 0;
//     if (j)
//     {
//         int buying = -A[i] + solve(i + 1, j - 1, k, N, A);
//         int notBuying = solve(i + 1, j, k, N, A);
//         profit = max(buying, notBuying);
//     }
//     else
//     {
//         int selling = A[i] + solve(i + 1, j + 1, k - 1, N, A);
//         int notSelling = solve(i + 1, j, k, N, A);
//         profit = max(selling, notSelling);
//     }
//     return profit;
// }

// int maxProfit(int K, int N, int A[])
// {
//     return solve(0, 1, K, N, A);
// }


// Memoization
// Time Complexity: O(N*K)
// Space Complexity: O(N*K) + O(N) for recursive stack
// int solve(int i, int j, int k, int N, int A[], vector<vector<vector<int>>> &dp)
// {
//     if (i == N || k == 0)
//         return 0;
//     if (dp[i][j][k] != -1)
//         return dp[i][j][k];
//     int profit = 0;
//     if (j)
//     {
//         int buying = -A[i] + solve(i + 1, j - 1, k, N, A, dp);
//         int notBuying = solve(i + 1, j, k, N, A, dp);
//         profit = max(buying, notBuying);
//     }
//     else
//     {
//         int selling = A[i] + solve(i + 1, j + 1, k - 1, N, A, dp);
//         int notSelling = solve(i + 1, j, k, N, A, dp);
//         profit = max(selling, notSelling);
//     }
//     return dp[i][j][k] = profit;
// }

// int maxProfit(int K, int N, int A[])
// {
//     vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(K + 1, -1)));
//     return solve(0, 1, K, N, A, dp);
// }


// Tabulation
// Time Complexity: O(N*K)
// Space Complexity: O(N*K)
// int maxProfit(int K, int N, int A[])
// {
//     vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(2, vector<int>(K + 1, 0)));
//     for (int i = N - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             for (int k = 1; k <= K; k++)
//             {
//                 int profit = 0;
//                 if (j)
//                 {
//                     int buying = -A[i] + dp[i + 1][j - 1][k];
//                     int notBuying = dp[i + 1][j][k];
//                     profit = max(buying, notBuying);
//                 }
//                 else
//                 {
//                     int selling = A[i] + dp[i + 1][j + 1][k - 1];
//                     int notSelling = dp[i + 1][j][k];
//                     profit = max(selling, notSelling);
//                 }
//                 dp[i][j][k] = profit;
//             }
//         }
//     }
//     return dp[0][1][K];
// }


// Tabulation (Space Optimized)
// Time Complexity: O(N*K)
// Space Complexity: O(K)
int maxProfit(int K, int N, int A[])
{
    vector<vector<int>> curr(2, vector<int>(K + 1, 0)), next(2, vector<int>(K + 1, 0));
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 1; k <= K; k++)
            {
                int profit = 0;
                if (j)
                {
                    int buying = -A[i] + next[0][k];
                    int notBuying = next[1][k];
                    profit = max(buying, notBuying);
                }
                else
                {
                    int selling = A[i] + next[1][k - 1];
                    int notSelling = next[0][k];
                    profit = max(selling, notSelling);
                }
                curr[j][k] = profit;
            }
        }
        next = curr;
    }
    return next[1][K];
}

int main()
{
    int k, n;
    cin >> k >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxProfit(k, n, a) << endl;
}