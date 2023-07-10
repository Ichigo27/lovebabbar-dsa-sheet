// 282 Egg Dropping Problem

// You are given N identical eggs and you have access to a K-floored building from 1 to K.

// There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below.

//     An egg that survives a fall can be used again.
//     A broken egg must be discarded.
//     The effect of a fall is the same for all eggs.
//     If the egg doesn't break at a certain floor, it will not break at any floor below.
//     If the eggs breaks at a certain floor, it will break at any floor above.

// Return the minimum number of moves that you need to determine with certainty what the value of f is.

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// Time Complexity: O(n*k^2)
// Space Complexity: O(1)
// int solve(int n, int k)
// {
//     if (k == 0 || k == 1 || n == 1)
//         return k;
//     int res = INT_MAX;
//     for (int i = 1; i <= k; i++)
//     {
//         int temp = 1 + max(solve(n - 1, i - 1), solve(n, k - i));
//         res = min(res, temp);
//     }
//     return res;
// }

// int eggDrop(int n, int k)
// {
//     return solve(n, k);
// }

// Memoization
// Time Complexity: O(n*k^2)
// Space Complexity: O(n*k) + O(n) + O(k) = O(n*k)
// int solve(int n, int k, vector<vector<int>> &dp)
// {
//     if (k == 0 || k == 1 || n == 1)
//         return k;
//     if (dp[n][k] != -1)
//         return dp[n][k];
//     int res = INT_MAX;
//     for (int i = 1; i <= k; i++)
//     {
//         int a, b;
//         if (dp[n - 1][i - 1] != -1)
//             a = dp[n - 1][i - 1];
//         else
//         {
//             a = solve(n - 1, i - 1, dp);
//             dp[n - 1][i - 1] = a;
//         }
//         if (dp[n][k - i] != -1)
//             b = dp[n][k - i];
//         else
//         {
//             b = solve(n, k - i, dp);
//             dp[n][k - i] = b;
//         }
//         int temp = 1 + max(a, b);
//         res = min(res, temp);
//     }
//     return dp[n][k] = res;
// }

// int eggDrop(int n, int k)
// {
//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
//     return solve(n, k, dp);
// }

// Tabulation
// Time Complexity: O(n*k^2)
// Space Complexity: O(n*k)
// int eggDrop(int n, int k)
// {
//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
//     for (int i = 1; i <= n; i++)
//     {
//         dp[i][0] = 0;
//         dp[i][1] = 1;
//     }
//     for (int i = 1; i <= k; i++)
//         dp[1][i] = i;
//     for (int i = 2; i <= n; i++)
//     {
//         for (int j = 2; j <= k; j++)
//         {
//             dp[i][j] = INT_MAX;
//             for (int x = 1; x <= j; x++)
//             {
//                 int temp = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
//                 dp[i][j] = min(dp[i][j], temp);
//             }
//         }
//     }
//     return dp[n][k];
// }

// Tabulation Optimized
// Time Complexity: O(n*k*log(k))
// Space Complexity: O(n*k)
int eggDrop(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int i = 1; i <= k; i++)
        dp[1][i] = i;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = INT_MAX;
            int low = 1, high = j;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                int a = dp[i - 1][mid - 1];
                int b = dp[i][j - mid];
                int temp = 1 + max(a, b);
                dp[i][j] = min(dp[i][j], temp);
                if (a < b)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    }
    return dp[n][k];
}


int main()
{
    int n = 2, k = 10;
    cout << eggDrop(n, k) << endl;
}