// 278 Count all subsequences having product less than K

// Given an array of positive numbers, the task is to find the number of possible subsequences having product less than a given number k.

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(1)
// int solve(int i, long long prod, const vector<int> &a, int n, long long k)
// {
//     if (i == n)
//         return 0;
//     int ans = 0;
//     if (prod * 1LL * a[i] < k)
//         ans = 1 + solve(i + 1, prod * 1LL * a[i], a, n, k);
//     ans += solve(i + 1, prod, a, n, k);
//     return ans;
// }

// int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
// {
//     return solve(0, 1, a, n, k);
// }

// Memoization Solution
// Time Complexity: O(n*k)
// Space Complexity: O(n*k)
// int solve(int i, long long prod, const vector<int> &a, int n, long long k, vector<vector<int>> &dp)
// {
//     if (i == n)
//         return 0;
//     if (dp[i][prod] != -1)
//         return dp[i][prod];
//     int ans = 0;
//     if (prod * 1LL * a[i] < k)
//         ans = 1 + solve(i + 1, prod * 1LL * a[i], a, n, k, dp);
//     ans += solve(i + 1, prod, a, n, k, dp);
//     return dp[i][prod] = ans;
// }

// int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
// {
//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
//     return solve(0, 1, a, n, k, dp);
// }

// Tabulation Solution
// Time Complexity: O(n*k)
// Space Complexity: O(n*k)
int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{
    // 
}

int main()
{
    int n;
    cin >> n;
    long long k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << countSubArrayProductLessThanK(a, n, k) << endl;
}