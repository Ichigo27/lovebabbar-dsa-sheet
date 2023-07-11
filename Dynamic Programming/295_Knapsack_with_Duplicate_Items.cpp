// 295

// Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times.

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(1) + O(n) for function call stack
// int solve(int i, int n, int w, int val[], int wt[])
// {
//     if (i == n)
//         return 0;
//     int ans = solve(i + 1, n, w, val, wt);
//     if (w - wt[i] >= 0)
//         ans = max(ans, val[i] + solve(i, n, w - wt[i], val, wt));
//     return ans;
// }

// int knapSack(int N, int W, int val[], int wt[])
// {
//     return solve(0, N, W, val, wt);
// }


// Memoization
// Time Complexity: O(n*W)
// Space Complexity: O(n*W) + O(n) for function call stack
// int solve(int i, int n, int w, int val[], int wt[], vector<vector<int>> &dp)
// {
//     if (i == n)
//         return 0;
//     if(dp[i][w] != -1)
//         return dp[i][w];
//     int ans = solve(i + 1, n, w, val, wt, dp);
//     if (w - wt[i] >= 0)
//         ans = max(ans, val[i] + solve(i, n, w - wt[i], val, wt, dp));
//     return dp[i][w] = ans;
// }

// int knapSack(int N, int W, int val[], int wt[])
// {
//     vector<vector<int>> dp(N, vector<int>(W + 1, -1));
//     return solve(0, N, W, val, wt, dp);
// }

// Tabulation
// Time Complexity: O(n*W)
// Space Complexity: O(n*W)
// int knapSack(int N, int W, int val[], int wt[])
// {
//     vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
//     for (int i = 1; i <= N; i++)
//     {
//         for (int j = 0; j <= W; j++)
//         {
//             dp[i][j] = dp[i - 1][j];
//             if (j - wt[i - 1] >= 0)
//                 dp[i][j] = max(dp[i][j], val[i - 1] + dp[i][j - wt[i - 1]]);
//         }
//     }
//     return dp[N][W];
// }

// Space Optimized Tabulation
// Time Complexity: O(n*W)
// Space Complexity: O(W)
int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> curr(W + 1, 0), prev(W + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            curr[j] = prev[j];
            if (j - wt[i - 1] >= 0)
                curr[j] = max(curr[j], val[i - 1] + curr[j - wt[i - 1]]);
        }
        prev = curr;
    }
    return prev[W];
}

int main()
{
    int N, W;
    cin >> N >> W;
    int val[N], wt[N];
    for (int i = 0; i < N; i++)
        cin >> val[i];
    for (int i = 0; i < N; i++)
        cin >> wt[i];
    cout << knapSack(N, W, val, wt) << endl;
}