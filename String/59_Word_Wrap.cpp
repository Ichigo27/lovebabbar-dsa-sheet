// 59 Word Wrap Problem [VERY IMP].

// Given an numsay nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
//  Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one.
//  You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming
// Time Complexity: O(n2)
// Space Complexity: O(n)
int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();
    int dp[n];
    dp[n - 1] = 0;
    int cost = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int curr = -1;
        dp[i] = INT_MAX;
        for (int j = i; j < n; j++)
        {
            curr += nums[j] + 1;
            if (curr > k)
                break;
            if (j == n - 1)
                cost = 0;
            else
                cost = (k - curr) * (k - curr) + dp[j + 1];
            if(cost < dp[i])
                dp[i] = cost;
        }
    }
    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    cout << solveWordWrap(nums, k);
}