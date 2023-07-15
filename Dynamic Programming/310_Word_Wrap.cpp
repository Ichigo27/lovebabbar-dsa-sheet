// 310 Word Wrap Problem

// Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
// Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one.
// You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)^2.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=aPdpJ_RjaXs
// https://www.codeburps.com/dsa/word-wrap-problem

// Recursive
// Time Complexity: O(2^n)
// Space Complexity: O(1) + O(n) for recursion stack
// int solve(int i, int j, vector<int> &nums, int k)
// {
//     if (i == nums.size())
//         return 0;
//     int spaceNeeded = j < k ? nums[i] + 1 : nums[i];
//     if (j < spaceNeeded)
//         return j * j + solve(i + 1, k - nums[i], nums, k);
//     else
//     {
//         int incl = solve(i + 1, j - spaceNeeded, nums, k);
//         int excl = j * j + solve(i + 1, k - nums[i], nums, k);
//         return min(incl, excl);
//     }
// }

// int solveWordWrap(vector<int> nums, int k)
// {
//     return solve(0, k, nums, k);
// }


// Memoization
// Time Complexity: O(n*k)
// Space Complexity: O(n*k) + O(n) for recursion stack
// int solve(int i, int j, vector<int> &nums, int k, vector<vector<int>> &dp)
// {
//     if (i == nums.size())
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     int spaceNeeded = j < k ? nums[i] + 1 : nums[i];
//     if (j < spaceNeeded)
//         return dp[i][j] = j * j + solve(i + 1, k - nums[i], nums, k, dp);
//     else
//     {
//         int incl = solve(i + 1, j - spaceNeeded, nums, k, dp);
//         int excl = j * j + solve(i + 1, k - nums[i], nums, k, dp);
//         return dp[i][j] = min(incl, excl);
//     }
// }

// int solveWordWrap(vector<int> nums, int k)
// {
//     vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));
//     return solve(0, k, nums, k, dp);
// }


// Tabulation
// Time Complexity: O(n*k)
// Space Complexity: O(n*k)
// int solveWordWrap(vector<int> nums, int k)
// {
//     int n = nums.size();
//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
//     for (int j = 0; j < k + 1; j++)
//         dp[n][j] = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < k + 1; j++)
//         {
//             int spaceNeeded = j < k ? nums[i] + 1 : nums[i];
//             if (j < spaceNeeded)
//                 dp[i][j] = j * j + dp[i + 1][k - nums[i]];
//             else
//             {
//                 int incl = dp[i + 1][j - spaceNeeded];
//                 int excl = j * j + dp[i + 1][k - nums[i]];
//                 dp[i][j] = min(incl, excl);
//             }
//         }
//     }
//     return dp[0][k];
// }


// Tabulation (Space Optimized)
// Time Complexity: O(n*k)
// Space Complexity: O(k)
int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> curr(k + 1, 0), next(k + 1, 0);
    for (int j = 0; j < k + 1; j++)
        next[j] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < k + 1; j++)
        {
            int spaceNeeded = j < k ? nums[i] + 1 : nums[i];
            if (j < spaceNeeded)
                curr[j] = j * j + next[k - nums[i]];
            else
            {
                int incl = next[j - spaceNeeded];
                int excl = j * j + next[k - nums[i]];
                curr[j] = min(incl, excl);
            }
        }
        next = curr;
    }
    return next[k];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    int k;
    cin >> k;
    cout << solveWordWrap(nums, k) << endl;
}