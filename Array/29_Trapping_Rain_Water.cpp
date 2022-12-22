// 29 Trapping Rain water problem

// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

#include <bits/stdc++.h>
using namespace std;

// brute force
// https://youtu.be/m18Hntz4go8?t=162
// Time Complexity: O(N^2)
// Auxiliary Space: O(1)

// prefix array for left and right
// https://youtu.be/m18Hntz4go8?t=343
// Time Complexity: O(N)
// Auxiliary Space: O(2*N)
// long long trappingWater(int arr[], int n)
// {
//     long long water = 0;
//     vector<pair<int, int>> valleys;
//     int left[n], right[n];
//     left[0] = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         left[i] = max(left[i - 1], arr[i]);
//     }
//     right[n - 1] = arr[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//     {
//         right[i] = max(right[i + 1], arr[i]);
//     }
//     for (int i = 1; i < n - 1; i++)
//     {
//         water += min(left[i], right[i]) - arr[i];
//     }
//     return water;
// }

// two pointer
// https://youtu.be/m18Hntz4go8?t=528
// Time Complexity: O(N)
// Auxiliary Space: O(1)
long long trappingWater(int arr[], int n)
{
    long long water = 0;
    int l = 0, r = n - 1;
    int leftMax = 0, rightMax = 0;
    while(l <= r)
    {
        if(arr[l] <= arr[r])
        {
            if(arr[l] >= leftMax)
                leftMax = arr[l];
            else
                water += leftMax - arr[l];
            l++;
        }
        else
        {
            if (arr[r] >= rightMax)
                rightMax = arr[r];
            else
                water += rightMax - arr[r];
            r--;
        }
    }
    return water;
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
    cout << trappingWater(arr, n);
}