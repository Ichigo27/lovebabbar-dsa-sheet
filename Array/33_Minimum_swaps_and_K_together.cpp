// 33 Minimum swaps required bring elements less equal K together

// Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.

#include <bits/stdc++.h>
using namespace std;

// Naive Approach:
// Time Complexity: O(N^2)
// Auxiliary Space: O(1)

// Efficient Approach: sliding window
// Time Complexity: O(N)
// Auxiliary Space: O(1)

// Efficient Approach: two-pointer technique
// Time Complexity: O(N)
// Auxiliary Space: O(1)
int minSwap(int arr[], int n, int k)
{
    int ans;
    int good = 0;
    int bad = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            good++;

    for (int i = 0; i < good; i++)
    {
        if (arr[i] > k)
            bad++;
    }
    ans = bad;
    for (int start = 0, end = good; end < n; start++, end++)
    {
        if (arr[start] > k)
            bad--;
        if (arr[end] > k)
            bad++;
        ans = min(ans, bad);
    }
    return ans;
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
    int k;
    cin >> k;
    cout << minSwap(arr, n, k);
}