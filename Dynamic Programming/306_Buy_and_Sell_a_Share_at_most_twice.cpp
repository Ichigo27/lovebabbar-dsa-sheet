// 306 Maximum profit by buying and selling a share at most twice [ IMP ]

// In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, the second transaction can only start after the first one is complete (Buy->sell->Buy->sell). The stock prices throughout the day are represented in the form of an array of prices.
// Given an array price of size N, find out the maximum profit that a share trader could have made.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=NW7XRzg3smo

// Recursive
// Time Complexity: O(2^n)
// Space Complexity: O(1) + O(n) for recursion stack
// int solve(int i, int canBuy, int limit, vector<int> &prices)
// {
//     if (i == prices.size() || limit == 0)
//         return 0;
//     int profit = 0;
//     if (canBuy)
//     {
//         int buying = -prices[i] + solve(i + 1, canBuy - 1, limit, prices);
//         int notBuying = solve(i + 1, canBuy, limit, prices);
//         profit = max(buying, notBuying);
//     }
//     else
//     {
//         int selling = prices[i] + solve(i + 1, canBuy + 1, limit - 1, prices);
//         int notSelling = solve(i + 1, canBuy, limit, prices);
//         profit = max(selling, notSelling);
//     }
//     return profit;
// }

// int maxProfit(vector<int> &prices)
// {
//     return solve(0, 1, 2, prices);
// }


// Memoization
// Time Complexity: O(n*2*3)
// Space Complexity: O(n*2*3) + O(n) for recursion stack
// int solve(int i, int canBuy, int limit, vector<int> &prices, vector<vector<vector<int>>> &dp)
// {
//     if (i == prices.size() || limit == 0)
//         return 0;
//     if (dp[i][canBuy][limit] != -1)
//         return dp[i][canBuy][limit];
//     int profit = 0;
//     if (canBuy)
//     {
//         int buying = -prices[i] + solve(i + 1, canBuy - 1, limit, prices, dp);
//         int notBuying = solve(i + 1, canBuy, limit, prices, dp);
//         profit = max(buying, notBuying);
//     }
//     else
//     {
//         int selling = prices[i] + solve(i + 1, canBuy + 1, limit - 1, prices, dp);
//         int notSelling = solve(i + 1, canBuy, limit, prices, dp);
//         profit = max(selling, notSelling);
//     }
//     return dp[i][canBuy][limit] = profit;
// }

// int maxProfit(vector<int> &prices)
// {
//     vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
//     return solve(0, 1, 2, prices, dp);
// }


// Tabulation
// Time Complexity: O(n*2*3)
// Space Complexity: O(n*2*3)
// int maxProfit(vector<int> &prices)
// {
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j <= 1; j++)
//         {
//             for (int k = 1; k <= 2; k++)
//             {
//                 int profit = 0;
//                 if (j)
//                 {
//                     int buying = -prices[i] + dp[i + 1][j - 1][k];
//                     int notBuying = dp[i + 1][j][k];
//                     profit = max(buying, notBuying);
//                 }
//                 else
//                 {
//                     int selling = prices[i] + dp[i + 1][j + 1][k - 1];
//                     int notSelling = dp[i + 1][j][k];
//                     profit = max(selling, notSelling);
//                 }
//                 dp[i][j][k] = profit;
//             }
//         }
//     }
//     return dp[0][1][2];
// }


// Tabulation (Space Optimized)
// Time Complexity: O(n*2*3)
// Space Complexity: O(2*3)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(3, 0)), next(2, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 1; k <= 2; k++)
            {
                int profit = 0;
                if (j)
                {
                    int buying = -prices[i] + next[0][k];
                    int notBuying = next[1][k];
                    profit = max(buying, notBuying);
                }
                else
                {
                    int selling = prices[i] + next[1][k - 1];
                    int notSelling = next[0][k];
                    profit = max(selling, notSelling);
                }
                curr[j][k] = profit;
            }
        }
        next = curr;
    }
    return next[1][2];
}

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    cout << maxProfit(price) << endl;
}