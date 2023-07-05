// 265 Matrix Chain Multiplication 

// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
// The dimensions of the matrices are given in an array arr[] of size N(such that N = number of matrices + 1) where the ith matrix has the dimensions(arr[i - 1] x arr[i]).

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=vRVfmbCFW7Y

// Recursive Solution
// time complexity: O(2^n)
// space complexity: O(1)
// int solve(int arr[], int i, int j)
// {
//     if (i >= j)
//         return 0;
//     int ans = INT_MAX;
//     for (int k = i; k < j; k++)
//     {
//         int temp = solve(arr, i, k) + arr[i - 1] * arr[k] * arr[j] + solve(arr, k + 1, j);
//         ans = min(ans, temp);
//     }
//     return ans;
// }

// int matrixMultiplication(int N, int arr[])
// {
//     return solve(arr, 1, N - 1);
// }

// Memoization Solution
// time complexity: O(n^3)
// space complexity: O(n^2) + O(n) for recursion stack
// int solve(int arr[], int i, int j, vector<vector<int>> &dp)
// {
//     if (i >= j)
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     int ans = INT_MAX;
//     for (int k = i; k < j; k++)
//     {
//         int temp = solve(arr, i, k, dp) + arr[i - 1] * arr[k] * arr[j] + solve(arr, k + 1, j, dp);
//         ans = min(ans, temp);
//     }
//     return dp[i][j] = ans;
// }

// int matrixMultiplication(int N, int arr[])
// {
//     vector<vector<int>> dp(N, vector<int>(N, -1));
//     return solve(arr, 1, N - 1, dp);
// }

// Tabulation Solution
// time complexity: O(n^3)
// space complexity: O(n^2)
int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 1; i < N; i++)
        dp[i][i] = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int temp = dp[i][k] + arr[i - 1] * arr[k] * arr[j] + dp[k + 1][j];
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }
    return dp[1][N - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << matrixMultiplication(n, arr) << endl;
}