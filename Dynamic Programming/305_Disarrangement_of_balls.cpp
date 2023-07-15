// 305 Count Derangements (Permutation such that no element appears in its original position) [ IMPORTANT ]

// You are given N balls numbered from 1 to N and there are N baskets numbered from 1 to N in front of you, the ith basket is meant for the ith ball. Calculate the number of ways in which no ball goes into its respective basket.

#include <bits/stdc++.h>
using namespace std;

long long int M = 1e9 + 7;

// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(1) + O(n) for function call stack
// long long int solve(int N)
// {
//     if (N == 0 || N == 1)
//         return 0;
//     if (N == 2)
//         return 1;
//     return (((N - 1) % M) * ((solve(N - 1) + solve(N - 2)) % M)) % M;
// }

// long long int disarrange(int N)
// {
//     return solve(N);
// }

// Memoization Solution
// Time Complexity: O(n)
// Space Complexity: O(n) for dp array + O(n) for function call stack
// long int solve(int N, vector<int> &dp)
// {
//     if (N == 0 || N == 1)
//         return 0;
//     if (N == 2)
//         return 1;
//     if (dp[N] != -1)
//         return dp[N];
//     return dp[N] = (((N - 1) % M) * ((solve(N - 1, dp) + solve(N - 2, dp)) % M)) % M;
// }

// long int disarrange(int N)
// {
//     vector<int> dp(N + 1, -1);
//     return solve(N, dp);
// }

// Tabulation Solution
// Time Complexity: O(n)
// Space Complexity: O(n)
// long int disarrange(int N)
// {
//     vector<int> dp(N + 1, 0);
//     dp[2] = 1;
//     for (int i = 3; i <= N; i++)
//     {
//         dp[i] = (((i - 1) % M) * ((dp[i - 1] + dp[i - 2]) % M)) % M;
//     }
//     return dp[N];
// }

// Tabulation Solution (Space Optimized)
// Time Complexity: O(n)
// Space Complexity: O(1)
long int disarrange(int N)
{
    long int prev1 = 0, prev2 = 1, curr;
    if (N == 0 || N == 1)
        return 0;
    for (int i = 3; i <= N; i++)
    {
        curr = (((i - 1) % M) * ((prev2 + prev1) % M)) % M;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

int main()
{
    int n;
    cin >> n;
    cout << disarrange(n) << endl;
}