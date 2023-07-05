// 267 Subset Sum Problem

// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// time complexity: O(2^N)
// space complexity: O(1)
// int solve(int i, int total, int N, int arr[])
// {
//     if(total == 0)
//         return 1;
//     if(i >= N || total < 0)
//         return 0;
//     return solve(i + 1, total - arr[i], N, arr) || solve(i + 1, total, N, arr);
// }

// int equalPartition(int N, int arr[])
// {
//     int total = accumulate(arr, arr + N, 0);
//     if(total%2 == 1)
//         return 0;
//     return solve(0, total / 2, N,arr);
// }

// Memoization Solution
// time complexity: O(N*total)
// space complexity: O(N*total) + O(N) for recursion stack
// int solve(int i, int total, int N, int arr[], vector<vector<int>> &dp)
// {
//     if (total == 0)
//         return 1;
//     if (i >= N || total < 0)
//         return 0;
//     if (dp[i][total] != -1)
//         return dp[i][total];
//     return dp[i][total] = solve(i + 1, total - arr[i], N, arr, dp) || solve(i + 1, total, N, arr, dp);
// }

// int equalPartition(int N, int arr[])
// {
//     int total = accumulate(arr, arr + N, 0);
//     if (total % 2 == 1)
//         return 0;
//     vector<vector<int>> dp(N, vector<int>(total + 1, -1));
//     return solve(0, total / 2, N, arr, dp);
// }

// Tabulation Solution
// time complexity: O(N*total)
// space complexity: O(N*total)
// int equalPartition(int N, int arr[])
// {
//     int total = accumulate(arr, arr + N, 0);
//     if (total % 2 == 1)
//         return 0;
//     int M = total / 2;
//     int dp[N][M + 1];
//     for (int i = 0; i < N; i++)
//         dp[i][0] = 1;
//     for (int i = 1; i <= M; i++)
//         dp[0][i] = 0;
//     for (int i = 1; i < N; i++)
//         for (int j = 1; j <= M; j++)
//             if (j >= arr[i])
//                 dp[i][j] = dp[i - 1][j - arr[i]] || dp[i - 1][j];
//             else
//                 dp[i][j] = dp[i - 1][j];
//     return dp[N - 1][M];
// }

// Tabulation Solution (Space Optimized)
// time complexity: O(N*total)
// space complexity: O(total)
int equalPartition(int N, int arr[])
{
    int total = accumulate(arr, arr + N, 0);
    if (total % 2 == 1)
        return 0;
    int M = total / 2;
    int dp[M + 1];
    for (int i = 0; i <= M; i++)
        dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = M; j >= arr[i]; j--)
            dp[j] = dp[j - arr[i]] || dp[j];
    return dp[M];
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << equalPartition(N, arr) << endl;
}