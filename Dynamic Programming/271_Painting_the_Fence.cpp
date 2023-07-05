// 271 Painting the Fence problem

// Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colors. Since the answer can be large return it modulo 10^9 + 7.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=5eFh5CC-8KY

long long add(long long a, long long b)
{
    return (a % 1000000007 + b % 1000000007) % 1000000007;
}

long long mul(long long a, long long b)
{
    return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}

// Recursive solution
// time complexity: O(n)
// space complexity: O(n)
// long long solve(int n, int k)
// {
//     if (n == 1)
//         return k;
//     if (n == 2)
//         return add(k, mul(k, k - 1));
//     return add(mul(solve(n - 1, k), k - 1), mul(solve(n - 2, k), k - 1));
// }

// long long countWays(int n, int k)
// {
//     return solve(n, k);
// }

// Memoization solution
// time complexity: O(n)
// space complexity: O(n) + O(n) = O(n)
// long long solve(int n, int k, vector<vector<long long>> &dp)
// {
//     if (n == 1)
//         return k;
//     if (n == 2)
//         return add(k, mul(k, k - 1));
//     if (dp[n][k] != -1)
//         return dp[n][k];
//     return dp[n][k] = add(mul(solve(n - 1, k, dp), k - 1), mul(solve(n - 2, k, dp), k - 1));
// }

// long long countWays(int n, int k)
// {
//     vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
//     return solve(n, k, dp);
// }

// Tabulation solution
// time complexity: O(n)
// space complexity: O(n)
// long long countWays(int n, int k)
// {
//     vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
//     for (int i = 1; i <= k; i++)
//         dp[1][i] = i;
//     for (int i = 1; i <= k; i++)
//         dp[2][i] = add(i, mul(i, i - 1));
//     for (int i = 3; i <= n; i++)
//         for (int j = 1; j <= k; j++)
//             dp[i][j] = add(mul(dp[i - 1][j], j - 1), mul(dp[i - 2][j], j - 1));
//     return dp[n][k];
// }

// Space optimized tabulation solution
// time complexity: O(n)
// space complexity: O(1)
long long countWays(int n, int k)
{
    if (n == 1)
        return k;
    long long prev1 = k;
    long long prev2 = add(k, mul(k, k - 1));
    long long curr = 0;
    for (int i = 3; i <= n; i++)
    {
        curr = add(mul(prev1, k - 1), mul(prev2, k - 1));
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << countWays(n, k) << endl;
}