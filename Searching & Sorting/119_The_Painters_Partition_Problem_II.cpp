// 119 Painters Partition Problem:

// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

// The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

#include <bits/stdc++.h>
using namespace std;

// Same as 114 Book Allocation Problem
// Time Complexity: O(logN), using binary search
// Auxiliary Space: O(1)
bool is_possible(int arr[], int n, int k, long long mid)
{
    long long total = 0, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        if (total + arr[i] > mid)
        {
            cnt++;
            total = arr[i];
        }
        else
        {
            total += arr[i];
        }
    }
    if (cnt <= k)
        return true;
    return false;
}

long long minTime(int arr[], int n, int k)
{
    long long low, high, mid, res = -1;
    low = 0;
    high = INT64_MAX;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (is_possible(arr, n, k, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int k, n;
    cin >> k >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minTime(arr, n, k);
}