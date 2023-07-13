// 302 Longest alternating subsequence

// A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations :
// x1 < x2 > x3 < x4 > x5..... or  x1 >x2 < x3 > x4 < x5.....
// Your task is to find the longest such sequence.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=UogHvfQ3e18
// https://www.youtube.com/watch?v=YrtczUOlRC8

// Time Complexity: O(n^2)
// Space Complexity: O(n)
// int AlternatingaMaxLength(vector<int> &nums)
// {
//     int ans = 1;
//     int n = nums.size();
//     vector<vector<int>> dp(n, vector<int>(2, 1));
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (nums[i] > nums[j] && dp[j][0] + 1 > dp[i][1])
//                 dp[i][1] = dp[j][0] + 1;
//             if (nums[i] < nums[j] && dp[j][1] + 1 > dp[i][0])
//                 dp[i][0] = dp[j][1] + 1;
//         }
//         ans = max(ans, max(dp[i][0], dp[i][1]));
//     }
//     return ans;
// }


// Time Complexity: O(n)
// Space Complexity: O(1)
int AlternatingaMaxLength(vector<int> &nums)
{
    int inc = 1, dec = 1;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
            inc = dec + 1;
        if (nums[i] < nums[i - 1])
            dec = inc + 1;
    }
    return max(inc, dec);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << AlternatingaMaxLength(nums);
}