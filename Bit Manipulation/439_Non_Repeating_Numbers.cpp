// 439 Find the two non-repeating elements in an array of repeating elements

// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=pnx5JA9LNM4

// Time complexity: O(n)
// Space complexity: O(1)
vector<int> singleNumber(vector<int> nums)
{
    int c = 0;
    for(int i = 0; i < nums.size(); i++)
        c ^= nums[i];
    int rsbm = c & -c;
    int a = 0, b = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] & rsbm)
            a ^= nums[i];
        else
            b ^= nums[i];
    }
    return {min(a, b), max(a, b)};
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> ans = singleNumber(nums);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}