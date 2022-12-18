// 15 Next Permutation

// Given an array of integers nums, find the next permutation of nums.

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
// In this approach, we find out every possible permutation of list formed by the elements of the given array and find out the permutation which is just larger than the given one. But this one will be a very naive approach, since it requires us to find out every possible permutation which will take really long time and the implementation is complex. Thus, this approach is not acceptable at all. Hence, we move on directly to the correct approach.

// Complexity Analysis
//     Time complexity : O(n!). Total possible permutations is n!.
//     Space complexity : O(n). Since an array will be used to store the permutations.

// Approach 2: Single Pass Approach
// https://www.youtube.com/watch?v=LuLCLgMElus

// Complexity Analysis
//     Time complexity : O(n). In worst case, only two scans of the whole array are needed.
//     Space complexity : O(1). No extra space is used. In place replacements are done.

void nextPermutation(vector<int> &nums)
{
    if (nums.size() < 2)
        return;
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }
    if (i >= 0)
    {
        int j = nums.size() - 1;
        while (j > i && nums[j] <= nums[i])
        {
            j--;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
    else
        reverse(nums.begin(), nums.end());
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    nextPermutation(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}