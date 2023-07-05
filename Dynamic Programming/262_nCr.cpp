// 262 Binomial Coefficient Problem

// Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Dynamic Programming
// https://www.youtube.com/watch?v=jIb1W3ObIho
// Time Complexity: O(n*r)
// Auxiliary Space: O(r)
int nCr(int n, int r)
{
    int dp[r + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = min(i, r); j > 0; j--)
            dp[j] = (dp[j] + dp[j - 1]) % 1000000007;
    return dp[r];
}

// Approach 2: Modular Multiplicative Inverse
// Time Complexity: O(r)
// Auxiliary Space: O(1)
// int nCr(int n, int r)
// {
//     if (r > n - r)
//         r = n - r;
//     int res = 1;
//     for (int i = 0; i < r; i++)
//     {
//         res *= (n - i);
//         res /= (i + 1);
//     }
//     return res;
// }

int main()
{
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r) << endl;
}
