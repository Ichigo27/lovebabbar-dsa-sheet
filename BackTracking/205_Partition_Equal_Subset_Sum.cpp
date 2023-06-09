// 205 Subset Sum Problem

// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int target, int n, int arr[], vector<vector<int>> &dp)
{
    if (target < 0 || i == n)
        return false;
    if (target == 0)
        return true;
    if (dp[i][target] != -1)
        return dp[i][target];
    return dp[i][target] = solve(i + 1, target - arr[i], n, arr, dp) || solve(i + 1, target, n, arr, dp);
}

int equalPartition(int N, int arr[])
{
    int total = accumulate(arr, arr + N, 0);
    if (total % 2 == 1)
        return 0;
    vector<vector<int>> dp(N, vector<int>(total / 2 + 1, -1));
    return solve(0, total / 2, N, arr, dp);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (equalPartition(n, arr) == 1)
        cout << "YES";
    else
        cout << "NO";
}