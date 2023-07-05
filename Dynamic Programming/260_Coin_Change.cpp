// 260 Coin Change Problem

// Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].
// Note : Assume that you have an infinite supply of each type of coin.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=I4UR2T6Ro3w
// https://www.youtube.com/watch?v=HgyouUi11zk

// Recursion
// time complexity: O(2^n)
// space complexity: recursion stack O(sum)
// int solve(int i, int rem, int coins[], int n)
// {
//     if (rem == 0)
//         return 1;
//     if (i >= n || rem < 0)
//         return 0;
//     return solve(i, rem - coins[i], coins, n) + solve(i + 1, rem, coins, n);
// }

// long long int count(int coins[], int N, int sum)
// {
//     sort(coins, coins + N);
//     return solve(0, sum, coins, N);
// }

// Memoization
// time complexity: O(n*sum)
// space complexity: O(n*sum) + recursion stack O(sum)
// int solve(int i, int rem, int coins[], int n, vector<vector<int>> &dp)
// {
//     if (rem == 0)
//         return 1;
//     if (i >= n || rem < 0)
//         return 0;
//     if (dp[i][rem] != -1)
//         return dp[i][rem];
//     return dp[i][rem] = solve(i, rem - coins[i], coins, n, dp) + solve(i + 1, rem, coins, n, dp);
// }

// long long int count(int coins[], int N, int sum)
// {
//     sort(coins, coins + N);
//     vector<vector<int>> dp(N, vector<int>(sum + 1, -1));
//     return solve(0, sum, coins, N, dp);
// }

// tabulation
// time complexity: O(n*sum)
// space complexity: O(n*sum)
// long long int count(int coins[], int num_coins, int target_sum) {
//     // Sort the coins in ascending order.
//     sort(coins, coins + num_coins);

//     // dp[i][j] stores the number of ways to make change for amount j using the first i coins.
//     vector<vector<int>> dp(num_coins, vector<int>(target_sum + 1, 0));

//     // There is one way to make change for amount 0 using any number of coins.
//     for (int i = 0; i < num_coins; i++) {
//         dp[i][0] = 1;
//     }

//     // For each coin.
//     for (int i = 0; i < num_coins; i++) {
//         // For each amount.
//         for (int j = 1; j <= target_sum; j++) {
//             if (i == 0) {
//                 // DP base case: one way to make change for any amount using just the first coin.
//                 dp[i][j] = (j % coins[i] == 0) ? 1 : 0;
//             } else {
//                 // Either count the number of ways to make change without using the current coin
//                 // or count the number of ways to make change using the current coin.
//                 dp[i][j] = dp[i - 1][j] + ((j - coins[i] >= 0) ? dp[i][j - coins[i]] : 0);
//             }
//         }
//     }

//     // Return the number of ways to make change for the given amount using the given coins.
//     return dp[num_coins - 1][target_sum];
// }

// space optimized tabulation
// time complexity: O(n*sum)
// space complexity: O(sum)
long long int count(int coins[], int num_coins, int target_sum)
{
    // Sort the coins in ascending order.
    sort(coins, coins + num_coins);

    // dp[i] stores the number of ways to make change for amount i using the first i coins.
    vector<int> dp(target_sum + 1, 0);

    // There is one way to make change for amount 0 using any number of coins.
    dp[0] = 1;

    // For each coin.
    for (int i = 0; i < num_coins; i++)
    {
        // For each amount.
        for (int j = 1; j <= target_sum; j++)
        {
            if (i == 0)
            {
                // DP base case: one way to make change for any amount using just the first coin.
                dp[j] = (j % coins[i] == 0) ? 1 : 0;
            }
            else
            {
                // Either count the number of ways to make change without using the current coin
                // or count the number of ways to make change using the current coin.
                dp[j] = dp[j] + ((j - coins[i] >= 0) ? dp[j - coins[i]] : 0);
            }
        }
    }

    // Return the number of ways to make change for the given amount using the given coins.
    return dp[target_sum];
}



int main()
{
    int n, sum;
    cin >> n >> sum;
    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    cout << count(coins, n, sum) << endl;
}