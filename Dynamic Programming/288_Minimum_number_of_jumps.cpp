// 288 Minimum number of jumps to reach end

// Given an array of N integers arr[] where each element represents the maximum length of the jump that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

// Note: Return -1 if you can't reach the end of the array.

#include <bits/stdc++.h>
using namespace std;

// Greedy Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
int minJumps(int arr[], int n)
{
    int reachable, steps, jumps;
    reachable = arr[0];
    steps = arr[0];
    jumps = 1;
    if (n == 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    for (int i = 1; i < n - 1; i++)
    {
        reachable = max(reachable, i + arr[i]);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i >= reachable)
                return -1;
            steps = reachable - i;
        }
    }
    return jumps;
}

// Recursive Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)
int solve(int i, int arr[], int n)
{
    if (i >= n - 1)
        return 0;
    if (arr[i] == 0)
        return INT_MAX;
    int mn = INT_MAX;
    for (int j = i + 1; j <= i + arr[i] && j < n; ++j)
    {
        mn = min(mn, 1 + solve(j, arr, n));
    }
    return mn;
}

int minJumps(int arr[], int n)
{
    return solve(0, arr, n);
}

// Memoization
// Time Complexity: O(n^2)
// Space Complexity: O(n) + O(n) = O(n)
int solve(int i, int arr[], int n, vector<int> &dp)
{
    if (i >= n - 1)
        return 0;
    if (arr[i] == 0)
        return INT_MAX;
    if (dp[i] != -1)
        return dp[i];
    int mn = INT_MAX;
    for (int j = i + 1; j <= i + arr[i] && j < n; ++j)
    {
        mn = min(mn, 1 + solve(j, arr, n, dp));
    }
    return dp[i] = mn;
}

int minJumps(int arr[], int n)
{
    vector<int> dp(n, -1);
    return solve(0, arr, n);
}

// Tabulation
// Time Complexity: O(n^2)
// Space Complexity: O(n)
int minJumps(int arr[], int n)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dp[i] != INT_MAX)
        {
            for (int j = i + 1; j <= i + arr[i] && j < n; ++j)
            {
                dp[j] = min(dp[j], 1 + dp[i]);
            }
        }
    }
    return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << minJumps(arr, n) << endl;
}