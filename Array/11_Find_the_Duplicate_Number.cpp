// 11 find duplicate in an array of N+1 Integers

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this repeated number.

#include <bits/stdc++.h>
using namespace std;

// method 1: Sorting
// In an unsorted array, duplicate elements may be scattered across the array. However, in a sorted array, duplicate numbers will be next to each other.
// Time Complexity: O(nlog⁡n)
// Space Complexity: O(logn)

// method 2: Use Map
// As we traverse the array, we need a way to "remember" values that we've seen. If we come across a number that we've seen before, we've found the duplicate. An efficient way to record the seen values is by adding each number to a set as we iterate over the numsnumsnums array.
// Time Complexity: O(n)
// Space Complexity: O(n)

// method 3: Floyd's Tortoise and Hare (Cycle Detection)
// https://www.youtube.com/watch?v=wjYnzkAhcNk
// https://www.youtube.com/watch?v=32Ll35mhWg0
// Time Complexity: O(n)
// Space Complexity: O(1)
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    int start = nums[0];
    while (start != slow)
    {
        slow = nums[slow];
        start = nums[start];
    }
    return start;
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
    cout << findDuplicate(nums);
}