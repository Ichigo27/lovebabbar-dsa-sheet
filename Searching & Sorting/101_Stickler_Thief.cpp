// 101 maximum sum such that no 2 elements are adjacent

// Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/GrMBfJNk_NY
// Time Complexity: O(N)
// Auxiliary Space: O(N) + O(N)
int solve(int arr[], int n, int i, int dp[])
{
    if (i > n - 1)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int take = arr[i] + solve(arr, n, i + 2, dp);
    int leave = solve(arr, n, i + 1, dp);
    return dp[i] = max(take, leave);
}

int FindMaxSum(int arr[], int n)
{
    int dp[n];
    memset(dp, -1, sizeof(dp));
    return solve(arr, n, 0, dp);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << FindMaxSum(arr, n);
}