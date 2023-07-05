// 263 Permutation Coefficient Problem

// Given two integers n and k, The task is to calculate Permutation Coefficient P(n,k)
// Note: P(n, k) is used to represent the number of ways to obtain an ordered subset having k elements from a set of n elements.Since this value may be large only find it modulo 10^9 + 7.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=Ebj83h76VUU

// time complexity: O(n*k)
// space complexity: O(k)
int permutationCoeff(int n, int k)
{
    int dp[k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = min(i, k); j > 0; j--)
            dp[j] = (dp[j] + (j * dp[j - 1]) % 1000000007) % 1000000007;
    return dp[k];
}

// time complexity: O(n*k)
// space complexity: O(1)
int permutationCoeff2(int n, int k)
{
    int P = 1;
    for (int i = 0; i < k; i++)
        P = (P * (n - i)) % 1000000007;
    return P;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << permutationCoeff(n, k) << endl;
}