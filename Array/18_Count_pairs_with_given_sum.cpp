// 18 find all pairs on integer array whose sum is equal to given number

// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
//  we need to iterate for every i,j and find pairs
// Time complexity: O(n^2).
// Space complexity: O(1).

// Approach 2: Binary Search
//  If the array is sorted then for each array element arr[i], find the number of pairs by finding all the values (sum – arr[i]) which are situated after ith index.
// Time complexity: O(nlogn).
// Space complexity: O(1).

int getPairsCount(int arr[], int n, int k)
{
    int ans = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        int ele = k - arr[i];
        int a = lower_bound(arr + i + 1, arr + n, ele) - arr;
        int b = upper_bound(arr + i + 1, arr + n, ele) - arr;
        ans += b - a;
    }
    return ans;
}

// Approach 3: Using Map
// https://www.youtube.com/watch?v=5L9Jrehvoew
// Time complexity: O(n).
// Space complexity: O(n).

// int getPairsCount(int arr[], int n, int k)
// {
//     int ans = 0;
//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++)
//     {
//         if(mp[k-arr[i]] > 0)
//         {
//             ans += mp[k - arr[i]];
//         }
//         mp[arr[i]]++;
//     }
//     return ans;
// }

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }
    cout << getPairsCount(arr, n, k);
}