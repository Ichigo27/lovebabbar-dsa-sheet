// 21 Find if there is any subarray with sum equal to 0

// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

#include <bits/stdc++.h>
using namespace std;

// method 1: brute force
// consider all subarrays one by one and check the sum of every subarray. Run two loops: the outer loop picks a starting point i and the inner loop tries all subarrays starting from i
// Time Complexity: O(n^2).
// Auxiliary Space: O(1).

// method 2: prefix sum and hashing
// The idea is to iterate through the array and for every element arr[i], calculate the sum of elements from 0 to i (this can simply be done as sum += arr[i]). If the current sum has been seen before, then there is a zero-sum array. Hashing is used to store the sum values so that sum can be stored quickly and find out whether the current sum is seen before or not.
// Time Complexity: O(n).
// Auxiliary Space: O(n).
bool subArrayExists(int arr[], int n)
{
    unordered_map<int, int> mp;
    int ps[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + arr[i - 1];
        if (ps[i] == 0 || mp.find(ps[i]) != mp.end())
            return true;
        mp[ps[i]] = i;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << subArrayExists(arr, n);
}