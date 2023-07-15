// 307 Optimal Strategy for a Game

// You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.
// In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
// You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally.

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(1) + O(n) for recursive stack
// long long solve(int i, int j, int arr[])
// {
//     if (i > j)
//         return 0;
//     return max(arr[i] + min(solve(i + 2, j, arr), solve(i + 1, j - 1, arr)), arr[j] + min(solve(i, j - 2, arr), solve(i + 1, j - 1, arr)));
// }

// long long maximumAmount(int arr[], int n)
// {
//     return solve(0, n - 1, arr);
// }

// Memoization Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) + O(n) for recursive stack
// long long solve(int i, int j, int arr[], vector<vector<int>> &dp)
// {
//     if (i > j)
//         return 0;
//     if (i == j)
//         return arr[i];
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     long long a = arr[i] + min(solve(i + 2, j, arr, dp), solve(i + 1, j - 1, arr, dp));
//     long long b = arr[j] + min(solve(i, j - 2, arr, dp), solve(i + 1, j - 1, arr, dp));
//     return dp[i][j] = max(a, b);
// }

// long long maximumAmount(int arr[], int n)
// {
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     return solve(0, n - 1, arr, dp);
// }

// Tabulation Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
long long maximumAmount(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i)
        dp[i][i] = arr[i];
    for (int i = 0; i < n - 1; ++i)
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    for (int i = n - 3; i >= 0; --i)
        for (int j = i + 2; j < n; ++j)
            dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << maximumAmount(arr, n) << endl;
}