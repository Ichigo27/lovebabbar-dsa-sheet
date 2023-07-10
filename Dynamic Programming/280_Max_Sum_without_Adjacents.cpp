// 280 Longest subsequence such that difference between adjacent is one

// Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

#include <bits/stdc++.h>
using namespace std;

// Recursive
// Time Complexity: O(2^n)
// Space Complexity: O(1)
// int solve(int i, int *arr, int n)
// {
//     if (i >= n)
//         return 0;
//     return max(solve(i + 1, arr, n), arr[i] + solve(i + 2, arr, n));
// }

// int findMaxSum(int *arr, int n)
// {
//     return solve(0, arr, n);
// }

// Memoisation
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) = O(n)
// int solve(int i, int *arr, int n, vector<int> &dp)
// {
//     if (i >= n)
//         return 0;
//     if (dp[i] != -1)
//         return dp[i];
//     return dp[i] = max(solve(i + 1, arr, n), arr[i] + solve(i + 2, arr, n));
// }

// int findMaxSum(int *arr, int n)
// {
//     vector<int> dp(n + 1, -1);
//     return solve(0, arr, n, dp);
// }

// Tabulation
// Time Complexity: O(n)
// Space Complexity: O(n)
// int findMaxSum(int *arr, int n)
// {
//     vector<int> dp(n + 1, 0);
//     dp[1] = arr[0];
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
//     }
//     return dp[n];
// }

// Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1)
int findMaxSum(int *arr, int n)
{
    int prev2 = 0, prev1 = arr[0], curr = 0;
    if(n == 1)
        return arr[0];
    for (int i = 2; i <= n; i++)
    {
        curr = max(prev1, prev2 + arr[i - 1]);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << findMaxSum(arr, n) << endl;
}