// 261 Knapsack Problem

// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=GqOmJHQZivw

// recursive solution
// time complexity: O(2^n)
// space complexity: O(1)
// int solve(int i, int W, int wt[], int val[], int n)
// {
//     if (i == n)
//         return 0;
//     if (wt[i] > W)
//         return solve(i + 1, W, wt, val, n);
//     return max(solve(i + 1, W, wt, val, n), val[i] + solve(i + 1, W - wt[i], wt, val, n));
// }

// int knapSack(int W, int wt[], int val[], int n)
// {
//     return solve(0, W, wt, val, n);
// }

// memoization
// time complexity: O(n*W)
// space complexity: O(n*W)
// int solve(int i, int W, int wt[], int val[], int n, vector<vector<int>> &dp)
// {
//     if (i == n)
//         return 0;
//     if (dp[i][W] != -1)
//         return dp[i][W];
//     if (wt[i] > W)
//         return dp[i][W] = solve(i + 1, W, wt, val, n, dp);
//     return dp[i][W] = max(solve(i + 1, W, wt, val, n, dp), val[i] + solve(i + 1, W - wt[i], wt, val, n, dp));
// }

// int knapSack(int W, int wt[], int val[], int n)
// {
//     vector<vector<int>> dp(n, vector<int>(W + 1, -1));
//     return solve(0, W, wt, val, n, dp);
// }

// tabulation
// time complexity: O(n*W)
// space complexity: O(n*W)
// int knapSack(int W, int wt[], int val[], int n)
// {
//     vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j <= W; j++)
//         {
//             if (wt[i] > j)
//                 dp[i][j] = dp[i + 1][j];
//             else
//                 dp[i][j] = max(dp[i + 1][j], val[i] + dp[i + 1][j - wt[i]]);
//         }
//     }
//     return dp[0][W];
// }

// space optimized tabulation
// time complexity: O(n*W)
// space complexity: O(W)
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> dp(W + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = W; j >= 0; j--)
        {
            if (wt[i] <= j)
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }
    return dp[W];
}


int main()
{
    int n, W;
    cin >> n >> W;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << knapSack(W, wt, val, n) << endl;
}