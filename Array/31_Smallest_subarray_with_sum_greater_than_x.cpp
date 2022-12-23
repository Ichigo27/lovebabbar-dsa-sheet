// 31 Smallest Subarray with sum greater than a given value

// Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

#include <bits/stdc++.h>
using namespace std;

//  Brute Force
// The outer loop picks a starting element, the inner loop considers all elements (on right side of current start) as ending element. Whenever sum of elements between current start and end becomes more than the given number, update the result if current length is smaller than the smallest length so far. 
// Time Complexity: O(N^2)
// Auxiliary Space: O(1)

// Efficient Solution
// Time Complexity: O(N)
// Auxiliary Space: O(1)
int smallestSubWithSum(int arr[], int n, int x)
{
    int ans = n + 1;
    int curr_sum = 0;
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        if (curr_sum <= x)
            curr_sum += arr[end];
        while (curr_sum > x && start < n)
        {
            ans = min(ans, end - start + 1);
            curr_sum -= arr[start++];
        }
    }
    return (ans == n + 1) ? 0 : ans;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << smallestSubWithSum(arr, n, x);
}