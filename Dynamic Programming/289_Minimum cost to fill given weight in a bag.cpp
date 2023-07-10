// 289 Minimum cost to fill given weight in a bag

// Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of i kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

// Note:
// 1. cost[i] = -1 means that i kg packet of orange is unavailable
// 2. It may be assumed that there is infinite supply of all available packet types.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=skf0qDzSJsQ
// https://www.youtube.com/watch?v=ZrBhhX0xMl8

// Recursive Solution
// Time Complexity: O(2^N)
// Space Complexity: O(1)
int solve(int i, int W, int cost[], int N)
{
    if (W == 0 && i == N)
        return 0;
    if (W < 0 || i == N)
        return 1e9;
    if (cost[i] == -1 || (i + 1) > W)
        return solve(i + 1, W, cost, N);
    return min(cost[i] + solve(i, W - (i + 1), cost, N), solve(i + 1, W, cost, N));
}

int minimumCost(int cost[], int N, int W)
{
    int ans = solve(0, W, cost, N);
    return ans >= 1e9 ? -1 : ans;
}

// Memoization Solution
// Time Complexity: O(N*W)
// Space Complexity: O(N*W) + O(N)
int solve(int i, int W, int cost[], int N, vector<vector<int>> &dp)
{
    if (W == 0 && i == N)
        return 0;
    if (W < 0 || i == N)
        return 1e9;
    if (dp[i][W] != -1)
        return dp[i][W];
    if (cost[i] == -1 || (i + 1) > W)
        return dp[i][W] = solve(i + 1, W, cost, N, dp);
    return dp[i][W] = min(cost[i] + solve(i, W - (i + 1), cost, N, dp), solve(i + 1, W, cost, N, dp));
}

int minimumCost(int cost[], int N, int W)
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    int ans = solve(0, W, cost, N, dp);
    return ans >= 1e9 ? -1 : ans;
}

// Tabulation Solution
// Time Complexity: O(N*W)
// Space Complexity: O(N*W)
int minimumCost(int cost[], int N, int W)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 1e9));
    int ans = 1e9;
    for (int i = 0; i <= N; ++i)
        dp[i][0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            if (cost[i - 1] == -1 || i > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(cost[i - 1] + dp[i][j - i], dp[i - 1][j]);
        }
        ans = min(ans, dp[i][W]);
    }
    return ans >= 1e9 ? -1 : ans;
}

int main()
{
    int n, w;
    cin >> n >> w;
    int cost[n];
    for (int i = 0; i < n; ++i)
        cin >> cost[i];
    cout << minimumCost(cost, n, w) << endl;
}