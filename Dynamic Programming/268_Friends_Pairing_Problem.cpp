// 268 Friends Pairing Problem

// Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
// Note: Since answer can be very large, return your answer mod 10^9+7.

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

// https://www.youtube.com/watch?v=os_u6Q_Ag74

// Recursive Solution
// time complexity: O(2^n)
// space complexity: O(1)
int solve(int n)
{
    if (n <= 2)
        return n;
    return (solve(n - 1) % mod + (n - 1) * solve(n - 2) % mod) % mod;
}

int countFriendsPairings(int n)
{
    return solve(n);
}

// Top Down Approach
// time complexity: O(n)
// space complexity: O(n)
int solve(int n, vector<int> &dp)
{
    if (n <= 2)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (solve(n - 1, dp) % mod + (n - 1) * solve(n - 2, dp) % mod) % mod;
}

int countFriendsPairings(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

// Bottom Up Approach
// time complexity: O(n)
// space complexity: O(n)
int countFriendsPairings(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] % mod + (i - 1) * dp[i - 2] % mod) % mod;
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countFriendsPairings(n) << endl;
}